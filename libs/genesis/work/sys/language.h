/*
 * /sys/language.h
 *
 * Some language functions.
 */

#ifndef LANG_DEF
#define LANG_DEF

#define LANG_FILE "/sys/global/language"

/*
 * LANG_PWORD    -- Get the plural form of a noun.
 * LANG_SWORD    -- Get the singular form of a noun.
 * LANG_PSENT    -- Get the plural form of a noun phrase.
 * LANG_ART      -- Get the article of a noun.
 * LANG_ADDART   -- Get the article of a noun + the noun.
 * LANG_STRIPART -- Strip the article from a description.
 * LANG_POSS     -- Get the possessive form of a name.
 * LANG_SHORT    -- Get the short without article. Works for heaps, too.
 * LANG_ASHORT   -- Get the short with article. Works for heaps, too.
 * LANG_THESHORT -- Get the short with 'the' in front. Works for heaps, too.
 *
 * LANG_NUM2WORD -- Get the textform of a number.
 * LANG_WNUM     -- Kept for backward compatibility.
 * LANG_WORD2NUM -- Get the number of a textform.
 * LANG_NUMW     -- Kept for backward compatibility.
 * LANG_WORD2ORD -- Get the number of an ordinal textform, "first" -> 1
 * LANG_ORDW     -- Kept for backward compatibility.
 * LANG_ORD2WORD -- Get the text in ordinal from from a number, 2 -> "second"
 * LANG_WORD     -- Kept for backward compatibility.
 * LANG_ORD2EXT  -- Get the text in ordrinal extension, 2 -> "2nd"
 */

#define LANG_PWORD(x)    ((string)LANG_FILE->plural_word(x))
#define LANG_SWORD(x)    ((string)LANG_FILE->singular_form(x))
#define LANG_PSENT(x)    ((string)LANG_FILE->plural_sentence(x))
#define LANG_ART(x)      ((string)LANG_FILE->article(x))
#define LANG_ADDART(x)   ((string)LANG_FILE->add_article(x))
#define LANG_STRIPART(x) ((string)LANG_FILE->strip_article(x))
#define LANG_POSS(x)     ((string)LANG_FILE->name_possessive(x))
#define LANG_SHORT(x)    ((string)LANG_FILE->lang_short(x))
#define LANG_ASHORT(x)   ((string)LANG_FILE->lang_a_short(x))
#define LANG_THESHORT(x) ((string)LANG_FILE->lang_the_short(x))

#define LANG_NUM2WORD(x) ((string)LANG_FILE->word_number(x))
#define LANG_WNUM(x)     LANG_NUM2WORD(x)
#define LANG_WORD2NUM(x) ((int)LANG_FILE->number_word(x))
#define LANG_NUMW(x)     LANG_WORD2NUM(x)
#define LANG_WORD2ORD(x) ((int)LANG_FILE->number_ord_word(x))
#define LANG_ORDW(x)     LANG_WORD2ORD(x)
#define LANG_ORD2WORD(x) ((string)LANG_FILE->word_ord_number(x))
#define LANG_WORD(x)     LANG_ORD2WORD(x)
#define LANG_ORD2EXT(x)  ((string)LANG_FILE->word_ord_ext(x))

/*
 * LANG_IS_PLURAL(x)
 *
 * Returns true if the word is likely to be a plural.
 */
#define LANG_IS_PLURAL(x)   ((string)LANG_FILE->is_plural(x))

/*
 * LANG_IS_OFFENSIVE(x) -- Returns true if the term contains offensive words
 *                         or sub-words.
 */
#define OFFENSIVE_WORDS ({ "*bitch*", "*clit*", "*cock*", "*cunt*", "*dick*", \
    "*fag*", "*fart*", "*fuck*", "*peck*", "*penis*", "*pussy*", "*rape*", \
    "*shit*", "*slut*", "*suck*", "*nigger*", "*titt*", "*twat*", "*poop*" })
/* FluffOS PORT NOTE: was (: wildmatch($1, (x)) :) -- see
 * wildmatch_bound() in secure/simul_efun.c for why. */
#define LANG_IS_OFFENSIVE(x) (!!sizeof(filter(OFFENSIVE_WORDS, (: wildmatch_bound, (x) :))))

/*
 * LANG_VOWELS - an array with all vowels.
 */
#define LANG_VOWELS ({ "a", "e", "i", "o", "u", "y" })

/*
 * GET_NUM_DESC - Match a value 'v' in range 0 to maximum 'mx' to a series of
 * main descriptions 'md' using uniform distribution of descriptions.
 * GET_NUM_DESC_SUB - Ditto, but also allow sub-descriptions 'sd'.
 * GET_PROC_DESC and GET_PROC_DESC_SUB do the same, but then with a percentage
 * that runs from 0-100% instead of an arbitrary maximum.
 */
#define GET_NUM_DESC(v, mx, md)              ((string)LANG_FILE->get_num_desc((v), (mx), (md)))
#define GET_NUM_DESC_CENTER(v, mx, ce, cew, md) (LANG_FILE->get_num_desc_centered((v), (mx), (ce), (cew), (md)))
#define GET_NUM_DESC_SUB(v, mx, md, sd, ti)  ((string)LANG_FILE->get_num_desc((v), (mx), (md), (sd), (ti)))
#define GET_PROC_DESC(v, md)                 ((string)LANG_FILE->get_num_desc((v), 100, (md)))
#define GET_PROC_DESC_SUB(v, md, sd, ti)     ((string)LANG_FILE->get_num_desc((v), 100, (md), (sd), (ti)))
#define GET_NUM_DESC_COMBOS(md, sd, ti)      ((string)LANG_FILE->get_num_desc_combos((md), (sd), (ti)))

/*
 * GET_NUM_LEVEL_DESC - Match a value 'v' to a series of descriptions 'md'. Each
 * description has an associated level 'lv' that you need to have or exceed to
 * get the description.
 * GET_NUM_LEVEL_INDEX - Same, but get the index of the level/description.
 */
#define GET_NUM_LEVEL_INDEX(v, lv)           ((int)LANG_FILE->get_num_level_index((v), (lv)))
#define GET_NUM_LEVEL_DESC(v, lv, md)        ((string)LANG_FILE->get_num_level_desc((v), (lv), (md)))

/* APPRAISE_VERB - Just a list of synonyms. */
#define APPRAISE_VERB one_of_list( ({ "appraise", "appraise", "assess", \
    "consider", "determine", "estimate", "guess", "judge", "reckon" }) )

/* LANG_PRETITLES - list of (mostly) chivalrous pretitles that we don't want
 * as part of names of new players.
 */
#define LANG_PRETITLES ({ "sir*", "*count*", "duke*", "*lord*", "*lady*", \
    "*prince*", "*king*", "*queen*", "*master*", "mr*", "miss*", "*dude*", \
    "*boy*", "*man", "ms*", "*guy" })

/* No definitions beyond this line. */
#endif LANG_DEF
