/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE
//
//  |  ``climb <something>``
//  |  ``climb <preposition> <something>``
//  |  ``i.e. climb over hedge``
//
// Climb things, or over, under, on, etc.
//
// .. TAGS: RST

inherit VERB_OB;

void do_climb_wrd_obj(string prep, object ob)
{
   ob->do_verb_rule("climb", "WRD OBJ", prep, ob);
}

void do_climb_obj(object ob)
{
   ob->do_verb_rule("climb", "OBJ", ob);
}

void create()
{
   add_rules(({"OBJ", "WRD OBJ"}), ({}));
}
