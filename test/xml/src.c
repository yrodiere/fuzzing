/* Parses a XML file on standard input and crashes if there is
 * a node corresponding to a particular XPathexpression.
 * Uses examples from http://xmlsoft.org/examples/index.html
 */
#include <stdlib.h>
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>

void crashIfMatching(xmlDocPtr doc, const char* xpathExpr)
{
	xmlXPathContextPtr xpathCtx;
	xmlXPathObjectPtr xpathObj;
	xmlNodeSetPtr nodes;

	/* Create xpath evaluation context */
	xpathCtx = xmlXPathNewContext(doc);
	if(xpathCtx == NULL) {
	    fprintf(stderr,"Error: unable to create new XPath context\n");
	    return;
	}

	/* Evaluate xpath expression */
	xpathObj = xmlXPathEvalExpression(xpathExpr, xpathCtx);
	if(xpathObj == NULL) {
	    fprintf(stderr,"Error: unable to evaluate xpath expression \"%s\"\n", xpathExpr);
	    xmlXPathFreeContext(xpathCtx);
	    return;
	}

	nodes = xpathObj->nodesetval;
	if(nodes == NULL) {
		xmlXPathFreeObject(xpathObj);
	    xmlXPathFreeContext(xpathCtx);
		return;
	}

	if(nodes->nodeTab && nodes->nodeTab[0]
			&& nodes->nodeTab[0]->type == XML_ELEMENT_NODE) {
		// Crash
		*(int*)NULL = 0;
	}

	/* Cleanup */
	xmlXPathFreeObject(xpathObj);
	xmlXPathFreeContext(xpathCtx);
}

void processXml ()
{
	xmlDocPtr doc; /* the resulting document tree */

	doc = xmlReadFd(0, NULL, NULL, 0);
	if (doc == NULL)
	{
		fprintf(stderr, "Failed to parse stdin\n");
		return;
	}

	crashIfMatching(doc, "/root/a/b/c");

	xmlFreeDoc(doc);
}

int main (int argc, char **argv)
{
	if (argc > 1)
	{
		printf("Usage: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/*
	 * this initialize the library and check potential ABI mismatches
	 * between the version it was compiled for and the actual shared
	 * library used.
	 */
	LIBXML_TEST_VERSION

	processXml();

	/*
	 * Cleanup function for the XML library.
	 */
	xmlCleanupParser();

	/*
	 * this is to debug memory for regression tests
	 */
	xmlMemoryDump();

	exit(EXIT_SUCCESS);
}

