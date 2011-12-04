AC_INIT(rutc, 0.3.0)
AM_INIT_AUTOMAKE

AC_PROG_CC
AC_PROG_LEX
AC_PROG_YACC

AC_CHECK_LIB([m],[cos])
AC_CHECK_LIB([gslcblas],[cblas_dgemm])
AC_CHECK_LIB([gsl],[gsl_blas_dgemm])


AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile])
AC_OUTPUT