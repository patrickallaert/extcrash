PHP_ARG_ENABLE([extcrash],
  [whether to enable extcrash support],
  [AS_HELP_STRING([--enable-extcrash],
    [Enable extcrash support])],
  [no])

if test "$PHP_EXTCRASH" != "no"; then
  AC_DEFINE(HAVE_EXTCRASH, 1, [ Have extcrash support ])
  PHP_NEW_EXTENSION(extcrash, extcrash.c, $ext_shared)
fi
