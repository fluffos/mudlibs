/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** pick.c
**
*/

#include <move.h>
#include <setbit.h>
#include <verbs.h>

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``touch <something>``
//  |  ``throw <something> with <something>``
//
//  Touch the panel, touch canvas with paintbrush. You can touch things
//  as a ghost as well.
//
// .. TAGS: RST

void do_touch_obj(object ob)
{
   object who = this_body();
   if (ob == who)
      who->simple_action("$N $vensure $r that $n $vare still there.", who);
   else
      who->targetted_action("$N $vtouch $t.", ob);
   ob->do_touch();
}

void do_touch_obj_with_obj(object ob1, object ob2)
{
   object who = this_body();
   who->targetted_action("$N $vtouch $t with the $o.", ob1, ob2);
   ob1->touch_with(ob2);
}

void create()
{
   add_rules(({"OBJ", "OBJ with OBJ"}));
   clear_flag(NEED_TO_BE_ALIVE);
}
