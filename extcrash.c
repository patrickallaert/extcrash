#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"

void (*old_zend_execute)(zend_execute_data *data);

static void custom_zend_execute(zend_execute_data *execute_data)
{
	old_zend_execute(execute_data);
}

PHP_MINIT_FUNCTION(extcrash)
{
	old_zend_execute = zend_execute_ex;
	zend_execute_ex = custom_zend_execute;
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(extcrash)
{
	zend_execute_ex = old_zend_execute;
	return SUCCESS;
}

zend_module_entry extcrash_module_entry = {
	STANDARD_MODULE_HEADER,
	"extcrash",
	NULL,
	PHP_MINIT(extcrash),
	PHP_MSHUTDOWN(extcrash),
	NULL,
	NULL,
	NULL,
	"0.1.0",
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_EXTCRASH
ZEND_GET_MODULE(extcrash)
#endif
