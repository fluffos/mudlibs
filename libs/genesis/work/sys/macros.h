/*
 * /sys/macros.h
 *
 * This file contains various useful macros.
 */

#ifndef MACROS_DEF
#define MACROS_DEF

#ifndef CONFIG_DEFINED
#include "/sys/config.h"
#endif  CONFIG_DEFINED

#ifndef CONST_DEF
#include "/sys/const.h"
#endif  CONST_DEF

#ifndef LANG_DEF
#include "/sys/language.h"
#endif  LANG_DEF

#ifndef PROP_DEF
#include "/sys/stdproperties.h"
#endif  PROP_DEF

/*
 * MAX(a, b) and MIN(a, b) respectively return the highest or the lowest of
 * the two arguments. ABS(a) returns 'a' with a positive sign. SNG(a) returns
 * the sign of 'a', either -1, 0 or 1.
 */
#define MAX(a, b) max(({ (a), (b) }))
#define MIN(a, b) min(({ (a), (b) }))
#define ABS(a)    ((a) >  0  ? (a) : -(a))
#define SGN(a)    ((a) >= 1  ? 1 : (((a) < 0) ? -1 : 0))

/*
 * MAXINT is the largest integer number the gamedriver can handle. If you
 * exceed MAXINT, it will loop and continue to count at (-MAXINT - 1). I
 * take it you are familiar with the alphabet ;-)
 */
#define MAXINT    (2147483647)
#define ALPHABET  ("abcdefghijklmnopqrstuvwxyz")
#define ALPHABET_LEN (26)

/*
 * MASTER_OB(ob) - returns the filename of 'ob' without object number.
 * MASTER        - returns the filename of this_object() without object num.
 * IS_CLONE      - true if this_object() is not the master object.
 * CLONE_COPY    - returns the objectpointer to a clone of this_object().
 * CALL_BY_CLONE - true if previous_object() is a clone of this_object().
 * CALL_BY(file) - true if previous_object() has filename 'file'.
 * CALL_BY_SELF  - true if we externally called ourselves.
 * OB_NUM(ob)    - returns the object number of 'ob'.
 * OB_NAME(ob)   - returns a unique add_name() for 'ob' based on OB_NUM.
 */
#define MASTER_OB(ob) (explode(file_name(ob) + "#", "#")[0])
#define MASTER        (MASTER_OB(this_object()))
#define IS_CLONE      (file_name(this_object()) != MASTER)
#define CLONE_COPY    clone_object(MASTER)
#define CALL_BY_CLONE (MASTER == MASTER_OB(previous_object()))
#define CALL_BY(file) (MASTER_OB(previous_object()) == (file))
#define CALL_BY_SELF  (previous_object() == this_object())
#define OB_NUM(ob)    (explode(file_name(ob) + "#0", "#")[1])
#define OB_NAME(ob)   ("ob_" + OB_NUM(ob))

/*
 * IN_ARRAY(item, arr) is true when the item is a member of array.
 */
#define IN_ARRAY(item, arr) (member_array((item), (arr)) != -1)

/*
 * LOAD_ERR(file) tries to load the module 'file' and if it fails, returns
 * the error message. If it is succesful, it returns 0.
 */
#define LOAD_ERR(file) catch(call_other((file), "??"))

/*
 * FCHAR(str) return the first character of 'str'.
 */
#define FCHAR(str) ((str))[0..0]

/*
 * LCALLfun makes a call_other to the function 'fun' in this_object(). By
 * doing so, the function is called in the shadow first rather than called
 * only internally.
 */
#define LCALL this_object()->

/*
 * FORMAT_NAME(name) returns the name 'name' (cpaitalize) in a left aligned
 * format of 11 characters. This is especially useful for displaying player
 * names in a table.
 * The macro FORMAT_PLNAME(pl) does the same, but bases itself on the player
 * object pointer instead.
 */
#define FORMAT_NAME(name) (sprintf("%-11s", (capitalize(name))))
#define FORMAT_PLNAME(pl) ((pl) ? FORMAT_NAME((pl)->query_real_name()) : ("Unknown"))

/*
 * VBFC(fun)    - return the VBFC string for an internal call to the
 *                function 'fun'.
 * VBFC_ME(fun) - return the VBFC string for a call_other to the function
 *                'fun' in this_object().
 */
#define VBFC(fun)    ("@@" + (fun) + "@@")
#define VBFC_ME(fun) ("@@" + (fun) + ":" + file_name(this_object()) + "@@")

/*
 * UNSEEN_NAME     - the (capitalized) name of someone who is invisible.
 * MYNAME          - the real (lower case) name of this_interactive().
 * METNAME         - the 'met' (capitalized) name of this_player().
 * NONMETNAME      - the 'nonmet' (capitalized) name of this_player().
 * ART_NONMETNAME  - NONMETNAME preceided by a capitalized article A or An.
 * TART_NONMETNAME - NONMETNAME preceided by the capitalized article The.
 */
#define UNSEEN_NAME     ("Someone")
#define MYNAME          ((string)this_interactive()->query_real_name())
#define METNAME         ((string)this_player()->query_name())
#define NONMETNAME      (capitalize(this_player()->query_nonmet_name()))
#define ART_NONMETNAME  (capitalize(LANG_ADDART(this_player()->query_nonmet_name())))
#define TART_NONMETNAME ("The " + (string)this_player()->query_nonmet_name())

/*
 * Here are some useful macros for using when figuring out player names.
 * Even if MET_ACTIVE is not defined, QMET should be VBFC for the functions
 * are dependant of previous_object for visibility.
 */
#define QMET(func, ob) (ob ? "@@" + (func) + ":" + file_name(ob) + "@@" : "0")

#define QSHORT(ob) QMET("vbfc_short", (ob))

/*
 * QNAME uses VBFC to return either the name of the player or the race
 *     preceded by a or an. ob is the object who we want check if we know.
 * QCNAME is the same as QNAME except that it returns a capital A or An.
 * QPNAME is the same as QNAME except that it returns the possessive form.
 * QCPNAME is the same as QCNAME except that it returns the possessive form.
 * QTNAME is the same as QNAME except that it returns 'the'.
 * QCTNAME is the same as QTNAME except that it returns a capital 'The'.
 * QTPNAME is the same as QTNAME except that it returns the possessive form.
 * QCTPNAME is the same as QCTNAME except that it returns the possessive form.
 */
#define QNAME(ob)    QMET("query_art_name", (ob))
#define QCNAME(ob)   QMET("query_Art_name", (ob))
#define QPNAME(ob)   QMET("query_art_possessive_name", (ob))
#define QCPNAME(ob)  QMET("query_Art_possessive_name", (ob))
#define QTNAME(ob)   QMET("query_the_name", (ob))
#define QCTNAME(ob)  QMET("query_The_name", (ob))
#define QTPNAME(ob)  QMET("query_the_possessive_name", (ob))
#define QCTPNAME(ob) QMET("query_The_possessive_name", (ob))

/*
 * Can ob1 see ob2?
 */
#define CAN_SEE(ob1, ob2)	((int)ob2->check_seen(ob1))
/*
 * Can ob1 see anything in a specific room or is it too dark?
 * Can ob1 see anything in his/hers environment or is it too dark?
 */
/*
#define CAN_SEE_IN_A_ROOM(ob, room)	((room) && \
    ((room)->query_prop(OBJ_I_LIGHT) > -((ob)->query_prop(LIVE_I_SEE_DARK))))
*/
#define CAN_SEE_IN_A_ROOM(ob, room)	((room) && !(ob)->query_prop(LIVE_I_BLIND) \
    && !((room)->query_prop(OBJ_I_LIGHT) <= ALWAYS_DARK_LIMIT) && \
    (max(({ (room)->query_prop(OBJ_I_LIGHT), ((ob)->query_prop(LIVE_I_SEE_DARK)) })) > 0))

#define CAN_SEE_IN_ROOM(ob)	CAN_SEE_IN_A_ROOM((ob), environment(ob))

/*
 * STRING_HASH_LEN(str, len) - gives a hash of arbitrary length. Ensure not
 *                    to ask for more text than crypt() returns.
 * STRING_HASH(str) - gives an 6 character hash of any string, giving it 64G
 *                    combinations with low risk of clashes. It uses capital
 *                    letters, lower case letters, numbers, period "." and
 *                    forward slash "/" as returned from crypt.
 * OBJECT_HASH(obj) - gives an 6 character hash of the current object clone.
 * MASTER_HASH(obj) - gives an 6 character hash of the object master of an
 *                    object.
 */
#define STRING_HASH_LEN(str, len) (crypt((str), "$1$0$")[-(len)..])
#define STRING_HASH(str) STRING_HASH_LEN((str), 6)
#define OBJECT_HASH(obj) STRING_HASH(file_name(obj))
#define MASTER_HASH(obj) STRING_HASH(MASTER_OB(obj))

/* No definitions beyond this line. */
#endif MACROS_DEF
