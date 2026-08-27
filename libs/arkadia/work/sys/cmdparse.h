/*
 * cmdparse.h
 *
 * This holds some very handy macros for command parsing.
 */

#ifndef CMDPARSE_DEF
#define CMDPARSE_DEF

#include "/sys/files.h"

/*
 * CMDPARSE_STD
 *
 * This defines the object holding much of the cmdparse.h code.
 */
#define CMDPARSE_STD "/sys/global/cmdparse"

/*
 * CMDPARSE_ONE_ITEM
 *
 * Parse and execute a trivial command of the type <verb> <item>
 *
 * Arguments:
 *            c     Command string after verb. ( == <item> )
 *                  <item> can be for example:
 *                      "the red apple", "all green objects" etc.
 *
 *            dofun Function called to do what ever is to be done
 *                  to each object included in <item>
 *
 *            afun  [optional] Function called for each object in <item>
 *                  to confirm inclusion in <item>. If afun == 0 then
 *                  those of the objects that are in the players inventory
 *                  or the players environment are included.
 *
 * Both dofun and afun are needed because afun most be called first for all
 * objects to get <item> descs like "the second apple" to work right.
 *
 * Returns: 
 *            An array holding all objects for which 'dofun' returned 1.
 */
#define CMDPARSE_ONE_ITEM(c, dofun, afun) \
    ((object *)CMDPARSE_STD->do_verb_1obj(c, dofun, afun, this_object()))

/*
 * CMDPARSE_IN_ITEM
 *
 * Parse and execute a command of the type <verb> <item1> "in_prep" <item2>
 *
 * It finds those of <item1> is located inside <item2>
 *
 * Arguments:
 *            c     Command string after verb. 
 *                  <itemX> can be for example:
 *                      "the red two apples", "all blue ones" etc.
 *
 *            pfun  Function called to confirm "in_prep" as correct.
 *
 *            dofun Function called to do what ever is to be done
 *                  to each object included in <item1>
 *
 *            afun  [optional] Function called for each object in <item2>
 *                  to confirm inclusion in <item2>. If afun == 0 then
 *                  those of the objects that are in the players inventory
 *                  or the players environment are included.
 *
 * Both dofun and afun are needed because afun most be called first for all
 * objects to get <item> descs like "the second apple" to work right.
 *
 * Returns: 
 *            An array holding all objects for which 'dofun' returned 1.
 */
#define CMDPARSE_IN_ITEM(c, pfun, dofun, afun) \
    ((object *)CMDPARSE_STD->do_verb_inside(c, pfun, dofun, afun, this_object()))

/*
 * CMDPARSE_WITH_ITEM
 *
 * Parse and execute a command of the type <verb> <item1> "prep" <item2>
 *
 * Arguments:
 *            c     Command string after verb. 
 *                  <itemX> can be for example:
 *                      "the red two apples", "all blue ones" etc.
 *
 *            chfun Function called to confirm "prep" as correct.
 *
 *            dofun Function called to do what ever is to be done
 *                  to each object included in <item1>
 *
 *            afun1 [optional] Function called for each object in <item1>
 *                  to confirm inclusion in <item1>. If afun1 == 0 then
 *                  those of the objects that are in the players inventory
 *                  or the players environment are included.
 *
 *            afun2 [optional] Function called for each object in <item2>
 *                  to confirm inclusion in <item2>. If afun2 == 0 then
 *                  those of the objects that are in the players inventory
 *                  or the players environment are included.
 *
 * Returns: 
 *            An array holding all objects for which 'dofun' returned 1.
 */
#define CMDPARSE_WITH_ITEM(c, chfun, dofun, afun1, afun2) \
    ((object *)CMDPARSE_STD->do_verb_with(c, chfun, dofun, afun1, afun2, this_object()))

/*
 * NORMAL_ACCESS
 *
 * test for access to object
 *
 * Arguments:
 *            arr     array from parse_command to test (arr[0] gives numeric or
 *		      order info).
 *
 *            acsfunc function to use in filter to filter objects in arr
 *
 *            acsobj  object use to call acsfunc
 *
 * Returns: 
 *            An array holding all objects satisfying arr[0] and acsfunc. 
 */
#define NORMAL_ACCESS(arr, acsfunc, acsobj) \
    ((object *)CMDPARSE_STD->normal_access(arr, acsfunc, acsobj))

/*
 * VISIBLE_ACCESS
 *
 * test for access to object visible to a player, only include this_player()
 * if it is the only object.
 *
 * Arguments:
 *            arr     array from parse_command to test (arr[0] gives numeric or
 *		      order info).
 *
 *            acsfunc function to use in filter to filter objects in arr
 *
 *            acsobj  object use to call acsfunc
 *
 * Returns: 
 *            An array holding all objects satisfying arr[0] and acsfunc. 
 */
#define VISIBLE_ACCESS(arr, acsfunc, acsobj) \
    ((object *)CMDPARSE_STD->visible_access(arr, acsfunc, acsobj, 0))

/*
 * FIND_STR_IN_OBJECT
 *
 * Find the corresponding object array in a player or room.
 * Locates both 'second sword' as well as 'sword 2' or 'two swords'
 *
 * Always returns an array with objects, or sometimes an empty array.
 */
#define FIND_STR_IN_OBJECT(str, obj, przyp) \
    ((object *)CMDPARSE_STD->find_str_in_object(str, obj, przyp))

/*
 * FIND_STR_IN_ARR
 *
 * Find the corresponding object array from a given array.
 * Locates both 'second sword' as well as 'sword 2' or 'two swords'
 *
 * Always returns an array with objects, or sometimes an empty array.
 */
#define FIND_STR_IN_ARR(str, arr, przyp) \
    ((object *)CMDPARSE_STD->find_str_in_arr(str, arr, przyp))

/*
 * CMDPARSE_ITEMLIST
 *
 * Parses a string on the form:
 *
 *    <prep> <item> <prep> <item> <prep> <item> ....
 *
 * item can be a subitem, sublocation or a normal object.
 *
 * Returns an array with four elements:
 *
 *
 * ret[0]		 The prepositions 
 * ret[1]		 The items, a normal parse_command %i return value 
 * ret[2]		 True if last was not a normal object 
 * ret[3]		 True if no normal objects 
 *
 */
#define CMDPARSE_ITEMLIST(str) CMDPARSE_STD->parse_itemlist(str)

/* 
 * PARSE_THIS
 *
 * This define gives access to the function parse_this in the basic soul
 * COMMAND_DRIVER so that you do not have to copy it everywhere.
 *
 * s - the string to parse
 * p - the pattern to parse with
 *
 * for more information do see "man parse_this" in the chapter "soul"
 */
#define PARSE_THIS(s, p) (object *)COMMAND_DRIVER->parse_this(s, p)

#endif CMDPARSE_DEF
