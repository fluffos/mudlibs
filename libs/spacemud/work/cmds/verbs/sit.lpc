/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** sit.c
*/

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``sit <preposition> <something>``
//  |  ``sit down``
//
//  Sit on a chair, sit down. Remain calm.
//
// .. TAGS: RST

void do_sit_wrd_obj(string prep, object ob)
{
   ob->do_verb_rule("sit", "WRD OBJ", prep, ob);
}

void do_sit()
{
   this_body()->sit_down();
   this_body()->simple_action("$N $vsit down.");
}

void do_sit_down()
{
   this_body()->sit_down();
   this_body()->simple_action("$N $vsit down.");
}

void create()
{
   add_rules(({"WRD OBJ", "", "down"}), ({}));
}
