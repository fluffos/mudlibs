/*
    sys/ctype.h - character class macros allowing side effects
    Mar 1992 by marion@cs.tu-berlin.de
*/

#ifndef _sys_ctype_h
#define _sys_ctype_h

#define NL	"\n"
#define QUOTE	"\""
#define BSLASH	"\\"
#define TRUE	1
#define FALSE	0

#define _U	'A'
#define _L	'B'
#define _N	'D'
#define _S	'H'
#define _P	'P'
#define _X	'`'

/* This gets shared anyway :-) */
#define _ctype_	"@@@@@@@@@H@@@@@@@@@@@@@@@@@@@@@@HPPPPPPPPPPPPPPPDDDDDDDDDDPPPPPPPaaaaaaAAAAAAAAAAAAAAAAAAAAPPPPPPbbbbbbBBBBBBBBBBBBBBBBBBBBPPPPP"

#define isalpha(c)	((_ctype_)[c]&(_U|_L)&'?')
#define isupper(c)	((_ctype_)[c]&(_U)&'?')
#define islower(c)	((_ctype_)[c]&(_L)&'?')
#define isdigit(c)	((_ctype_)[c]&(_N)&'?')
#define isxdigit(c)	((_ctype_)[c]&(_X)&'?')
#define isspace(c)	((_ctype_)[c]&(_S)&'?')
#define ispunct(c)	((_ctype_)[c]&(_P)&'?')
#define isalnum(c)	((_ctype_)[c]&(_U|_L|_N)&'?')
#define isprint(c)	((_ctype_)[c]&(_U|_L|_N|_P)&'?')
#define isgraph(c)      isprint(c)

/* These two work for all isalpha(c) */
#define toupper(c)	((c)&'_')
#define tolower(c)	((c)|' ')

/* Make a string from integer ascii */
#define tostring(c)	((string)"/basic/quote"->query_chart(c))

#endif /* _sys_ctype_h */
