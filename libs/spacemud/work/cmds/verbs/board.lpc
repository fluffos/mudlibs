/* Do not remove the headers from this file! see /USAGE for more info. */

/***************************
 *
 *   board.c moved to
 *   /bin/verbs by zifnab
 ******************************/

//: COMMAND
// USAGE
//
//  |  ``board <something>``
//
// Board something can that be boarded.
//
// .. TAGS: RST

#include <mudlib.h>
inherit VERB_OB;

mixed can_board_obj(object ob)
{
   return 1;
}

mixed do_board_obj(object ob)
{
   environment(this_body())->do_go_obj(ob, 0);
}

void create()
{
   add_rules(({"OBJ"}), ({}));
}
