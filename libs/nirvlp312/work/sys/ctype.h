/*
    sys/ctype.h - character class macros allowing side effects
*/

#ifndef _sys_ctype_h
#define _sys_ctype_h

#define NL      "\n"
#define QUOTE   "\""
#define BSLASH  "\\"
#define TRUE    1
#define FALSE   0

#define _U      'A'
#define _L      'B'
#define _N      'D'
#define _S      'H'
#define _P      'P'
#define _X      '`'

/* This gets shared anyway :-) */
#define _ctype_ "@@@@@@@@@H@@@@@@@@@@@@@@@@@@@@@@"\
                "HPPPPPPPPPPPPPPPDDDDDDDDDDPPPPPP"\
                "PaaaaaaAAAAAAAAAAAAAAAAAAAAPPPPP"\
                "PbbbbbbBBBBBBBBBBBBBBBBBBBBPPPPP"

#define isalpha(c)      ((_ctype_)[(c) & 0xff]&(_U|_L)&'?')
#define isupper(c)      ((_ctype_)[(c) & 0xff]&(_U)&'?')
#define islower(c)      ((_ctype_)[(c) & 0xff]&(_L)&'?')
#define isdigit(c)      ((_ctype_)[(c) & 0xff]&(_N)&'?')
#define isxdigit(c)     ((_ctype_)[(c) & 0xff]&(_X)&'?')
#define isspace(c)      ((_ctype_)[(c) & 0xff]&(_S)&'?')
#define ispunct(c)      ((_ctype_)[(c) & 0xff]&(_P)&'?')
#define isalnum(c)      ((_ctype_)[(c) & 0xff]&(_U|_L|_N)&'?')
#define isprint(c)      ((_ctype_)[(c) & 0xff]&(_U|_L|_N|_P)&'?')
#define isgraph(c)      isprint(c)

/* These two work for all isalpha(c) */
#define toupper(c)      ((c)&'_')
#define tolower(c)      ((c)|' ')

/* Make a string from integer ascii */
#define tostring(c)     ((string)"/basic/quote"->query_chart(c))

/*
 * ISO 8851-1 (latin 1):
 *
 *  ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿
 * ÀÂÄÆÈÊÌÎÐÒÔÖØÚÜÞ
 * àãæéìïòöúÿ
 */

// the character most alike:
#define _isotoascii0_ "?" "\x01\x02\x03\x04\x05\x06\x07" \
                      "\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f" \
                      "\x10\x11\x12\x13\x14\x15\x16\x17" \
                      "\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f" \
                      " !\"#$%&'()*+,-./0123456789:;<=>?"\
                      "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"\
                      "`abcdefghijklmnopqrstuvwxyz{|}~?" \
                      "?" "\x01\x02\x03\x04\x05\x06\x07" \
                      "\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f" \
                      "\x10\x11\x12\x13\x14\x15\x16\x17" \
                      "\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f" \
                      " !cLxY|S\"ca<_-R~o?23'mP.,10>????"\
                      "AAAAAAACEEEEIIIIDNOOOOOxOUUUUYPs" \
                      "aaaaaaaceeeeiiiidnooooo/ouuuuypy"

#define isotoascii0(c) ((_isotoascii0_)[(c) & 0xff])

// remove accents, use ? for non translatable without loss:
#define _isotoascii1_ "?" "\x01\x02\x03\x04\x05\x06\x07" \
                      "\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f" \
                      "\x10\x11\x12\x13\x14\x15\x16\x17" \
                      "\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f" \
                      " !\"#$%&'()*+,-./0123456789:;<=>?"\
                      "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"\
                      "`abcdefghijklmnopqrstuvwxyz{|}~?" \
                      "?" "\x01\x02\x03\x04\x05\x06\x07" \
                      "\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f" \
                      "\x10\x11\x12\x13\x14\x15\x16\x17" \
                      "\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f" \
                      " ???????????????????????????????" \
                      "AAAA???CEEEEIIII?NOOOO?x?UUU?Y??" \
                      "aaaa???ceeeeiiii?noooo???uuu?y?y"

#define isotoascii1(c) ((_isotoascii1_)[(c) & 0xff])

// default is the most alike looking character:
#define isotoascii(c) isotoascii0(c)

#endif /* _sys_ctype_h */

