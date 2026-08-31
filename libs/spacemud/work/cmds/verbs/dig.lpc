/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** dig.c  by Rust.  Shows off the fact that we can be smart about finding
** out what people mean.
*/

//: COMMAND
// USAGE
//
//  |  ``dig <something> with <tool>``
//  |  ``dig in <something>``
//  |  ``dig in <something> with <tool>``
//  |  ``dig out <something>``
//  |  ``dig out <something with <tool>``
//  |  ``dig up <something>``
//  |  ``dig up <something> with <tool>``
//  |  ``dig with <tool>``
//  |  ``dig with <tool> in <something>``
//
// Dig a hole, dig in dirt with your space, dig up something. Just dig!
//
// .. TAGS: RST

#include <mudlib.h>

inherit VERB_OB;

mixed can_dig_str(string str)
{
   if (str == "hole" || str == "a hole")
      return "Try: dig in something with something.\n";
   return 0;
}

mixed can_dig()
{
   return "Try: dig in something with something.\n";
}

void do_dig_in_obj(object ob1)
{
   ob1->complete_dig();
}

void do_dig_obj(object ob1)
{
   ob1->complete_dig();
}

void do_dig_with_obj(object ob1)
{
   ob1->do_digging();
}

void do_dig_in_obj_with_obj(object ob1, object ob2)
{
   ob2->do_digging(ob1);
}

void do_dig_with_obj_in_obj(object ob1, object ob2)
{
   do_dig_in_obj_with_obj(ob2, ob1);
}

void do_dig_obj_with_obj(object ob1, object ob2)
{
   do_dig_in_obj_with_obj(ob1, ob2);
}

void do_dig_out_obj_with_obj(object ob1, object ob2)
{
   do_dig_in_obj_with_obj(ob1, ob2);
}

void do_dig_out_obj(object ob1)
{
   do_dig_in_obj(ob1);
}

void do_dig_up_obj_with_obj(object ob1, object ob2)
{
   do_dig_in_obj_with_obj(ob1, ob2);
}

void do_dig_up_obj(object ob1)
{
   do_dig_in_obj(ob1);
}

void create()
{
   add_rules(({"", "STR", "in OBJ", "in OBJ with OBJ", "with OBJ"}));
   add_rules(({"out OBJ", "OBJ with OBJ", "out OBJ with OBJ", "up OBJ", "up OBJ with OBJ", "with OBJ in OBJ"}));
   //    return ({ ({ "", "STR", "in OBJ", "in OBJ with OBJ", "with OBJ", "OBJ",
   //		   "out OBJ", "OBJ with OBJ", "out OBJ with OBJ",
   //		   "up OBJ", "up OBJ with OBJ", "with OBJ in OBJ", }) });
}
