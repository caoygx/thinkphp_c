/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "main/SAPI.h"

#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "ext/standard/php_var.h"
#include "ext/standard/php_array.h"
#include "Zend/zend_globals_macros.h"
#include "php_thinkphp_c.h"

/* If you declare any globals in php_thinkphp_c.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(thinkphp_c)
*/

/* True global resources - no need for thread safety here */
static int le_thinkphp_c;
static zval *config =NULL;

/* {{{ thinkphp_c_functions[]
 *
 * Every user visible function must have an entry in thinkphp_c_functions[].
 */
const zend_function_entry thinkphp_c_functions[] = {
    PHP_FE(confirm_thinkphp_c_compiled, NULL)       /* For testing, remove later. */
    PHP_FE_END  /* Must be the last line in thinkphp_c_functions[] */
};
/* }}} */

/* {{{ thinkphp_c_module_entry
 */
zend_module_entry thinkphp_c_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    "thinkphp_c",
    thinkphp_c_functions,
    PHP_MINIT(thinkphp_c),
    PHP_MSHUTDOWN(thinkphp_c),
    PHP_RINIT(thinkphp_c),      /* Replace with NULL if there's nothing to do at request start */
    PHP_RSHUTDOWN(thinkphp_c),  /* Replace with NULL if there's nothing to do at request end */
    PHP_MINFO(thinkphp_c),
#if ZEND_MODULE_API_NO >= 20010901
    PHP_THINKPHP_C_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_THINKPHP_C
ZEND_GET_MODULE(thinkphp_c)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("thinkphp_c.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_thinkphp_c_globals, thinkphp_c_globals)
    STD_PHP_INI_ENTRY("thinkphp_c.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_thinkphp_c_globals, thinkphp_c_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_thinkphp_c_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_thinkphp_c_init_globals(zend_thinkphp_c_globals *thinkphp_c_globals)
{
    thinkphp_c_globals->global_value = 0;
    thinkphp_c_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(thinkphp_c)
{
    /* If you have INI entries, uncomment these lines 
    REGISTER_INI_ENTRIES();
    */
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(thinkphp_c)
{
    /* uncomment this line if you have INI entries
    UNREGISTER_INI_ENTRIES();
    */
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(thinkphp_c)
{
        MAKE_STD_ZVAL(config);
        array_init(config);
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(thinkphp_c)
{
    zval_ptr_dtor(&config);
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(thinkphp_c)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "thinkphp_c support", "enabled");
    php_info_print_table_end();

    /* Remove comments if you have entries in php.ini
    DISPLAY_INI_ENTRIES();
    */
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_thinkphp_c_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(C)
{
    zval *key=NULL;
    zval *value=NULL;
    zval *default_value=NULL;


    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &key, &value, &default_value) == FAILURE) {
        php_printf("param error");
        RETURN_NULL();  
    }
    
    

    if(key== NULL || Z_TYPE_P(key) == IS_NULL){
//      php_printf("key is null,return all \n");    

//      ZVAL_COPY_VALUE(return_value,config);
        RETURN_ZVAL(config,1,0);
//      return;
    }

    if(Z_TYPE_P(key) == IS_STRING ){

        char *name;
        //strcpy(name,Z_STRVAL_P(key));
        name = Z_STRVAL_P(key);
//      name = (char *)emalloc(Z_STRLEN_P(key)+1);
//      ZVAL_COPY_VALUE(key_copy,key);
        //strcpy(name,Z_STRVAL_P(key_copy));
        //memcpy(name,Z_STRVAL_P(key),Z_STRLEN_P(key)+1);
//
//      zval *key_copy;
//      MAKE_STD_ZVAL(key_copy);
//      ZVAL_COPY_VALUE(key_copy,key);
//      php_var_dump(&config,1);    
//                  zval_ptr_dtor(&key);    
//              php_var_dump(&config,1);
//      name = php_strtoupper(Z_STRVAL_P(key),Z_STRLEN_P(key));
//              php_var_dump(&config,1);
//php_var_dump(&key_copy,1);return;
        //name = php_strtoupper(name,strlen(name));
//php_printf("len:%d\n",sizeof(name));
//php_printf("len_zval:%d\n",Z_STRLEN_P(key));
//              php_var_dump(&config,1);    
        if (!strstr(name, ".")) {
//          php_printf("key:%s",name); 
//          php_printf("\n"); 

            if(value == NULL || Z_TYPE_P(value) == IS_NULL){//getc
 //               php_printf("get start:");
//                php_var_dump(&config,1);

                zval **ppdata;
                if(zend_hash_find(Z_ARRVAL_P(config),name,strlen(name)+1,(void **)&ppdata) != FAILURE)
                {
                
//                    ZVAL_COPY_VALUE
                    RETURN_ZVAL(*ppdata,1,0);
            //      php_var_dump(ppdata,1);         
                    //ZVAL_COPY_VALUE(return_value,*ppdata);
                    //efree(*ppdata);
//                  php_printf("find"); 
//                  zval_ptr_dtor(ppdata);  
                    //zval_dtor(*ppdata);
        //          efree(name);
                //  return;
                }
                if(default_value != NULL && Z_TYPE_P(default_value) != IS_NULL  ){
//                  php_printf(Z_STRVAL_P(key)); 
//                  php_printf(":"); 
//                  php_printf("no find\n"); 
                    ZVAL_COPY_VALUE(return_value,default_value);
                    //                 php_var_dump(&default_value,1);
        //          zval_dtor(default_value);
                    return;
                }
                return ;
            }else{ //set

//              zval *tmp2;
//              MAKE_STD_ZVAL(tmp2);
                //ALLOC_ZVAL(tmp2);
                //INIT_PZVAL_COPY(tmp2,value);
  //              tmp2 = value;
                //Z_ADDREF_P(value);
    //            zval_copy_ctor(tmp2);
    Z_ADDREF_P(value);
 //   php_printf(Z_STRVAL_P(value));
                zend_hash_update(Z_ARRVAL_P(config), name, strlen(name)+1, &value, sizeof(zval *), NULL);
       //         Z_DELREF_P(value);       
        // Z_ADDREF_P(value);
        //      efree(name);
//              zval_ptr_dtor(&tmp2);
  //              php_printf("set end:");
//                php_var_dump(&config,1);
    RETURN_TRUE;
            }
            return;
        }
        //二维数据设置和获取
        char *firstKeyPointer= NULL;
        char *firstKey = NULL;

        char *secondKeyPointer= NULL;
        char *secondKey= NULL;
        //char *nameCopy = NULL;
        char *nameCopy = (char *)malloc(strlen(name)+1);
        strcpy(nameCopy,name);
        php_printf("copy=%s\n",nameCopy);
        firstKey= strtok(nameCopy,".");
        secondKey= strtok(NULL,".");

        if(value == NULL || Z_TYPE_P(value) == IS_NULL){
            zval **ppzval;
            if(zend_hash_find(Z_ARRVAL_P(config),firstKey,strlen(firstKey)+1,(void **)&ppzval) != FAILURE){
                //                    php_var_dump(ppzval,1);
                //php_var_dump(ppzval,1);
                zval **secondValue=NULL;
                if(zend_hash_find(Z_ARRVAL_P(*ppzval),secondKey,strlen(secondKey)+1,(void **)&secondValue) != FAILURE){

                    RETURN_ZVAL(*secondValue,1,0);
                }
        //      zval_ptr_dtor(ppzval);  
            }
            if(default_value != NULL && Z_TYPE_P(default_value) != IS_NULL  ){
                //php_printf(Z_STRVAL_P(key)); 
//              php_printf("."); 
//              php_printf("no find\n"); 
                ZVAL_COPY_VALUE(return_value,default_value);
                //                 php_var_dump(&default_value,1);
                return;
            }else{
                RETURN_NULL();
            }

        }else{

            zval *tmp;
            MAKE_STD_ZVAL(tmp);
            zval **ppzval;

            if(zend_hash_find(Z_ARRVAL_P(config),firstKey,strlen(firstKey)+1,(void **)&ppzval) != FAILURE){
                ZVAL_COPY_VALUE(tmp,value);
                zend_hash_update(Z_ARRVAL_PP(ppzval),secondKey,strlen(secondKey)+1,(void **)&tmp,sizeof(zval *),NULL);
//              php_printf("%s\n","find"); 
        //      zval_ptr_dtor(ppzval);  
            }
            else{
                zval *firstArray;
                MAKE_STD_ZVAL(firstArray);
                array_init(firstArray);
                //add_assoc_string(firstArray,secondKey,"api",1);
                ZVAL_COPY_VALUE(tmp,value);
                add_assoc_zval(firstArray,secondKey,tmp);
                add_assoc_zval(config,firstKey,firstArray);
            }
        }
    }
    if(Z_TYPE_P(key) == IS_ARRAY){

        zend_fcall_info fci;
        zend_fcall_info_cache fcc;
        zval *retval;
        zval *handle = NULL;
        zval function_name;
        zval **argv[2];

        ZVAL_STRING(&function_name, "array_change_key_case", 1);
        MAKE_STD_ZVAL(handle);

        zval *type; 
        MAKE_STD_ZVAL(type);
        ZVAL_LONG(type,1);
        argv[0] = &key;
        argv[1] = &type;
        fci.size = sizeof(fci);
        fci.function_table = EG(function_table);
        fci.function_name = &function_name;
        fci.symbol_table = NULL;
        fci.object_ptr = NULL;
        fci.retval_ptr_ptr = &retval;
        fci.param_count = 2;
        fci.params = argv;
        fci.no_separation = 0;


//php_var_dump(&key,1);
        if (zend_call_function(&fci, NULL TSRMLS_CC) == FAILURE) {
            php_printf("err");        
        }
        else {
//php_var_dump(&retval,1);
            php_array_merge(Z_ARRVAL_P(config),Z_ARRVAL_PP(&retval), 0 TSRMLS_CC);
            //zval_ptr_dtor(&key);
        }
//      zval_ptr_dtor(&retval);
        zval_ptr_dtor(&handle);
        zval_ptr_dtor(&type);
        zval_dtor(&function_name);
        zval_ptr_dtor(*argv);
        RETURN_TRUE;
    }



        RETURN_NULL();  







    //len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "C", arg);
    //RETURN_STRINGL(strg,  0);
    }

/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

