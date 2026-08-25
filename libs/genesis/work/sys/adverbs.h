/*
 * /sys/adverbs.h
 *
 * This file will allow you to handle adverbs that are known in the mudlib.
 * If you specify an adverb you only need to supply a part of that adverb.
 * The pattern should be at least three characters long and the first adverb
 * that matches the first sizeof(pattern) characters will be returned as
 * recognized adverb.
 *
 * The adverbs themselves I stripped from the soul /cmd/std/soul_cmd.c and
 * if you want to use adverbs in a soul, you should use the functions
 * parse_adverb() and parse_adverb_with_space() that are both in the object
 * /cmd/std/command_driver.c, which is mandatory for souls anyway.
 */

#ifndef SYS_ADVERBS_DEFINITIONS
#define SYS_ADVERBS_DEFINITIONS

/* Need this since it's also used in <living_desc.h> */
#ifndef ADVERBS_FILE
#define ADVERBS_FILE "/sys/global/adverbs.lpc"
#endif

/*
 * FULL_ADVERB(string pattern)
 *
 * Returns the full adverb if you only supply a part of an adverb. This allows
 * a player to type "smile cun" and this routine will convert that "cun" into
 * the complete adverb "cunningly". Note that the pattern should have at least
 * three characters to be allowed. If the adverb is not found, an empty
 * string "" will be returned.
 */
#define FULL_ADVERB(p)   ((string)ADVERBS_FILE->full_adverb(p))

/*
 * MEMBER_ADVERB(string pattern)
 *
 * Returns the index of the pattern in the array of known adverbs or -1 if
 * the adverb is not found.
 */
#define MEMBER_ADVERB(p) ((int)ADVERBS_FILE->member_adverb(p))

/*
 * ADVERB_AT_POS(int index)
 *
 * Returns the adverb in the array of adverbs with the index i. If the index
 * i is illegal, an empty string "" will be returned.
 */
#define ADVERB_AT_POS(i) ((string)ADVERBS_FILE->adverb_at_pos(i))

/*
 * DEFAULT_ADVERB_ARRAY
 *
 * This is the array with adverbs that are default.. They cannot be removed
 * for the adverb-searching algorithm always needs at least two adverbs to
 * function.
 */
#define DEFAULT_ADVERB_ARRAY ({ "happily", "sadly" })

/*
 * NO_ADVERB
 * NO_ADVERB_WITH_SPACE
 *
 * This is the result string if you ask for an adverb that does not exist or
 * cannot be matched. The definition NO_ADVERB is nicer to use than "". It
 * comes in two flavours, with and without space.
 */
#define NO_ADVERB ("")
#define NO_ADVERB_WITH_SPACE (" ")

/*
 * BLANK_ADVERB
 *
 * This adverb means that the player does not want to use an adverb.
 */
#define BLANK_ADVERB (".")

/*
 * NO_DEFAULT_ADVERB
 * NO_DEFAULT_ADVERB_WITH_SPACE
 *
 * This "adverb" is used to differ on default adverbs for use with a target
 * or as a general emote. It comes in two flavours, with and without space.
 */
#define NO_DEFAULT_ADVERB ("_no_default_adverb")
#define NO_DEFAULT_ADVERB_WITH_SPACE (" _no_default_adverb")

/*
 * SERVICE_ADVERBS_ARRAY
 *
 * An array containing the service-adverbs. These "adverbs" have a special
 * meaning in the manipulation of adverbs.
 */
#define SERVICE_ADVERBS_ARRAY ({ BLANK_ADVERB, NO_DEFAULT_ADVERB })

/*
 * ADD_SPACE_TO_ADVERB(string s)
 *
 * Returns either the adverb with a preceding space or an empty string if
 * the adverb was the special adverb that the player used to tell that he
 * does not want to use an adverb.
 */
#define ADD_SPACE_TO_ADVERB(s) (((s) == BLANK_ADVERB) ? "" : (" " + (s)))

/*
 * REMOVE_SPACE_FROM_ADVERB(string s)
 *
 * Returns the adverb without a preceding space if it had any.
 */
#define REMOVE_SPACE_FROM_ADVERB(s) \
    (strlen(s) ? (((s)[0] == " ") ? ((s)[1..] : (s)) : "")

/*
 * ADVERB_SAVE_FILE - This is the file with all adverbs known to the game.
 * The file contains a sorted list with every adverb on a new line.
 *
 * ADVERB_REPLACEMENT_FILE - contains a table with the exceptions to the
 * normal adverbs, i.e. make someone "smile in a friendly manner" rather
 * than "smile friendly". The file contains on each line the adverb and
 * the replacement, separated by a colon, i.e. "friendly:in a friendly manner"
 *
 * ATTRIBUTES_FILE - contains the attributes people can select for their
 * character. The file has categories in caps with two = in front of it
 * "==EYES" and then each attribute within that category on a single line.
 */
#define ADVERB_FILE             ("/sys/data/ADVERBS")
#define ADVERB_REPLACEMENT_FILE ("/sys/data/ADVERB_REPLACEMENTS")
#define ATTRIBUTES_FILE         ("/sys/data/ATTRIBUTES")

/* No definitions beyond this line. */
#endif SYS_ADVERBS_DEFINITIONS
