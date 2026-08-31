/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** apply.c
** Tsath 2020-02-05
*/

//: COMMAND
// USAGE
//
//  |  ``apply <something> to <something>``
//  |  ``apply bandage to left arm``
//  |  ``apply for drivers license``
//
// For applying things to things or for things.
//
// .. TAGS: RST

#include <move.h>
#include <setbit.h>
#include <verbs.h>

inherit VERB_OB;

void do_apply_obj(object ob)
{
   object who = this_body();
   who->targetted_action("$N $vapply $t.", ob);
   ob->do_apply();
}

void do_apply_obj_to_str(object ob1, string str)
{
   object who = this_body();
   if (member_array(str, this_body()->query_limbs()) == -1)
   {
      printf("You cannot apply %s to that limb.\n", ob1->the_short());
      return;
   }
   who->targetted_action("$N $vapply $t to $p $o.", ob1, str);
   ob1->apply_to(str);
}

void create()
{
   add_rules(({"OBJ", "OBJ to STR"}));
}
