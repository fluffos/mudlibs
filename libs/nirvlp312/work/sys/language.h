/*
 * /sys/language.h
 * Some language functions
 */

#ifndef _sys_language_h
#define _sys_language_h

#define LANG_FILE "/lib/language"

#define LANG_PWORD(x) call_other(LANG_FILE,"plural_word",x)
#define LANG_PSENT(x) call_other(LANG_FILE,"plural_sentence",x)
#define LANG_ART(x) call_other(LANG_FILE,"article",x)
#define LANG_ADDART(x) call_other(LANG_FILE,"add_article",x)
#define LANG_WNUM(x) call_other(LANG_FILE,"word_number",x)
#define LANG_POSSESS(x) call_other(LANG_FILE,"possessive_s",x)

#endif
