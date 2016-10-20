dnl $Id$
dnl config.m4 for extension thinkphp_c

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(thinkphp_c, for thinkphp_c support,
dnl Make sure that the comment is aligned:
dnl [  --with-thinkphp_c             Include thinkphp_c support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(thinkphp_c, whether to enable thinkphp_c support,
Make sure that the comment is aligned:
[  --with-thinkphp_c           Include thinkphp_c support])
dnl [  --enable-thinkphp_c           Enable thinkphp_c support])

if test "$PHP_THINKPHP_C" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-thinkphp_c -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/thinkphp_c.h"  # you most likely want to change this
  dnl if test -r $PHP_THINKPHP_C/$SEARCH_FOR; then # path given as parameter
  dnl   THINKPHP_C_DIR=$PHP_THINKPHP_C
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for thinkphp_c files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       THINKPHP_C_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$THINKPHP_C_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the thinkphp_c distribution])
  dnl fi

  dnl # --with-thinkphp_c -> add include path
  dnl PHP_ADD_INCLUDE($THINKPHP_C_DIR/include)

  dnl # --with-thinkphp_c -> check for lib and symbol presence
  dnl LIBNAME=thinkphp_c # you may want to change this
  dnl LIBSYMBOL=thinkphp_c # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $THINKPHP_C_DIR/lib, THINKPHP_C_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_THINKPHP_CLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong thinkphp_c lib version or lib not found])
  dnl ],[
  dnl   -L$THINKPHP_C_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(THINKPHP_C_SHARED_LIBADD)

  PHP_NEW_EXTENSION(thinkphp_c, thinkphp_c.c, $ext_shared)
fi
