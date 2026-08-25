/*
 * composite.h
 *
 * Routines to describe livings and dead objects, composite sentences and some
 * text formatting.
 */

#ifndef COMPOSITE_DEF
#define COMPOSITE_DEF

#define COMPOSITE_FILE "/sys/global/composite"

/* COMPOSITE_LIVE(x) - describe all objects in array x as livings.
 * COMPOSITE_DEAD(x) - describe all objects in array x as dead objects.
 */
#define COMPOSITE_LIVE(x) ((string)COMPOSITE_FILE->desc_live(x))
#define COMPOSITE_DEAD(x) ((string)COMPOSITE_FILE->desc_dead(x))

/* FO_COMPOSITE_LIVE(x, ob) - describe all objects in array x as livings as
 *                            seen by living ob.
 * FO_COMPOSITE_DEAD(x, ob) - describe all objects in array x as dead objects
 *                            as seen by living ob.
 */
#define FO_COMPOSITE_LIVE(x, ob) ((string)COMPOSITE_FILE->fo_desc_live(x, ob))
#define FO_COMPOSITE_DEAD(x, ob) ((string)COMPOSITE_FILE->fo_desc_dead(x, ob))

/* COMPOSITE_ALL_LIVE(x) - describe all objects in array x as livings,
                           including those that are marked as no-show-composite.
 * COMPOSITE_ALL_DEAD(x) - describe all objects in array x as dead objects,
                           including those that are marked as no-show-composite.
 */
#define COMPOSITE_ALL_LIVE(x) ((string)COMPOSITE_FILE->desc_live(x, 0, 0, 1))
#define COMPOSITE_ALL_DEAD(x) ((string)COMPOSITE_FILE->desc_dead(x, 0, 0, 1))

/* FO_COMPOSITE_ALL_LIVE(x, ob) - describe all objects in array x as livings,
     as seen by living ob including those that are marked as no-show-composite.
 * FO_COMPOSITE_ALL_DEAD(x, ob) - describe all objects in array x as dead objects,
     as seen by living ob including those that are marked as no-show-composite.
 */
#define FO_COMPOSITE_ALL_LIVE(x, ob) \
    ((string)COMPOSITE_FILE->fo_desc_live(x, ob, 0, 1))
#define FO_COMPOSITE_ALL_DEAD(x, ob) \
    ((string)COMPOSITE_FILE->fo_desc_dead(x, ob, 0, 1))

/* SILENT_COMPOSITE_LIVE(x) - describe all objects in array x as livings, if
 *   there are none (visible), return an empty string and not "someone".
 * SILENT_COMPOSITE_DEAD(x) - describe all objects in array x as dead objects,
 *   if there are none (visible), return an empty string and not "something".
 */
#define SILENT_COMPOSITE_LIVE(x) ((string)COMPOSITE_FILE->desc_live(x, 1))
#define SILENT_COMPOSITE_DEAD(x) ((string)COMPOSITE_FILE->desc_dead(x, 1))

/*
 * Function:    composite/fo_composite
 * Description: Creates a composite description of objects
 * Arguments:   x:          Array of the objects to describe
 *              sf:         Name of function to call in objects to get its 
 *                          <name> objects with the same <names> are described
 *                          together.
 *              df:         Function to call to get the actual description of
 *                          a group of 'same objects' i.e objects whose
 *                          'sf' returned the same value.
 *		for_ob:     Who want this description?
 * 
 * Returns:     A description string on the format:
 *              <desc>, <desc> and <desc> 
 *              Where <desc> is what ob->df() returns
 *
*/
#define COMPOSITE(x, sf, df) \
    ((string)COMPOSITE_FILE->composite(x, sf, df))

#define FO_COMPOSITE(x, sf, df, for_ob) \
    ((string)COMPOSITE_FILE->fo_composite(x, sf, df, for_ob))

/*
 * Function:    composite_sort
 * Description: Sorts an array as composite sorts its output
 * Arguments:   arr:        Array of the objects to sort
 *              sepfnc:     Function to call in objects to get its <name>
 *                          Objects with the same <names> are sorted
 *                          together.
 * 
 * Returns:     0 or the array sorted
 *
*/
#define COMPOSITE_SORT(arr, sepfnc) \
    ((object *)COMPOSITE_FILE->sort_similar(arr, sepfnc))

/*
 * A VBFC to FO_COMPOSITE_LIVE and _DEAD would be nice :)
 */
#define QCOMPLIVE "@@fo_desc_last_live:" + COMPOSITE_FILE + "@@"
#define QCOMPDEAD "@@fo_desc_last_dead:" + COMPOSITE_FILE + "@@"

/*
 * COMPOSITE_WORDS
 * COMPOSITE_WORDS_WITH
 *
 * Simple combination of a wordlist with "," and "and"
 * Simple combination of a wordlist with "," and another word.
 */
#define COMPOSITE_WORDS(wl)		((string)COMPOSITE_FILE->composite_words((wl), "and"))
#define COMPOSITE_WORDS_WITH(wl, wrd)	((string)COMPOSITE_FILE->composite_words((wl), (wrd)))

/*
 * HANGING_INDENT
 *
 * Returns <text> with a hanging indent, i.e. the first line is printed at the
 * first column and subsequent lines are indented with <indent> spaces. The
 * maximal indent is 20 characters. If <width> is 0, use the screen width of
 * the player, for 1 use the default (80 character screen) and for any other
 * value, use that value.
 */
#define HANGING_INDENT(text, indent, width) \
    ((string)COMPOSITE_FILE->hanging_indent((text), (indent), (width)))

/*
 * EXPAND_LINE
 *
 * Returns a string of <length> long, padded with repetitions of <text>. The
 * <text> must be at least 1 character long. The last <text> may be trunctated
 * if it does not fit. Example: EXPAND_LINE("-+", 5) -> "-+-+-"
 * Note: To include "'" in the <text>, you must use "\\'" (as the backslash
 *       has to be escaped past the interpreter). Similarly, to include "\"
 *       requires "\\\\".
 */
#define EXPAND_LINE(text, length) sprintf("%'" + (text) + "'*s", (length), "")

/* No definitions beyond this point. */
#endif COMPOSITE_DEF
