/*
 * /sys/language.h
 *
 * Some language functions
 *
 * Revision history:
 * /Mercade, 8 January 1994. typecasted
 */

#ifndef LANG_DEF
#define LANG_DEF

#include "/sys/pl.h"
#define LANG_FILE "/sys/global/language"

/*
 * LANG_PWORD    -- Get the plural form of a noun
 *
 * LANG_SWORD    -- Get the singular form of a noun
 *
 * LANG_PSENT    -- Get the plural form of a noun phrase
 *
 * LANG_ART      -- Get the article of a noun
 *
 * LANG_ADDART   -- Get the article of a noun + the noun
 *
 * LANG_WNUM     -- Get the textform of a number
 *
 * LANG_NUMW     -- Get the number of a textform
 *
 * LANG_POSS     -- Get the possessive form of a name
 *
 * LANG_ASHORT   -- Get it right with article and heaps
 *
 * LANG_THESHORT -- Get it right with 'the' in front of heaps
 *
 * LANG_ORDW     -- Get the number of an ordinal textform, "first" -> 1
 *
 * LANG_WORD     -- Get the text in ordinal from from a number, 2 -> "second"
 */

#define LANG_PWORD(x)    ((string)LANG_FILE->plural_word(x))
#define LANG_SWORD(x)    ((string)LANG_FILE->singular_form(x))
#define LANG_PSENT(x)    ((string)LANG_FILE->plural_sentence(x))
#define LANG_ART(x)      ((string)LANG_FILE->article(x))
#define LANG_ADDART(x)   ((string)LANG_FILE->add_article(x))
#define LANG_WNUM(x)     ((string)LANG_FILE->word_number(x))
#define LANG_NUMW(x)        ((int)LANG_FILE->number_word(x))
#define LANG_POSS(x)     ((string)LANG_FILE->name_possessive(x))
#define LANG_ASHORT(x)   ((string)LANG_FILE->lang_a_short(x))
#define LANG_THESHORT(x) ((string)LANG_FILE->lang_the_short(x))
#define LANG_ORDW(x)        ((int)LANG_FILE->number_ord_word(x))
#define LANG_WORD(x)     ((string)LANG_FILE->word_ord_number(x))

#define LANG_NUMS(x)        ((int)LANG_FILE->num_slowo(x))
#define LANG_SNUM(a,b,c) ((string)LANG_FILE->slowo_num(a,b,c))
#define LANG_SORD(a,b,c) ((string)LANG_FILE->slowo_ord_num(a,b,c))
#define LANG_ORDS(x)        ((int)LANG_FILE->num_ord_slowo(x)
#define LANG_PRZYP(a,b,c)   ((int)LANG_FILE->query_przyp_rzeczow(a,b,c))

/* no definitions beyond this line. */
#endif LANG_DEF
