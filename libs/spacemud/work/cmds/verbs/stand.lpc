/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** stand.c

   Added standing in and standing on objects
   Vette  April 11, 1997

   Basically rewritten in March 1999 by Tigran
*/

//: COMMAND
// USAGE
//
//  |  ``stand``
//  |  ``stand <preposition>``
//  |  ``stand <preposition> <something>``
//
//  Stand, stand up, stand down, stand on chair.
//
// .. TAGS: RST

inherit VERB_OB;

void do_stand()
{
   this_body()->simple_action("$N $vstand up.");
   this_body()->stand_up();
}

void do_stand_wrd(string prep)
{
   if (prep != "up")
   {
      write("Stand what?");
      return;
   }

   this_body()->simple_action("$N $vstand up.");
   this_body()->stand_up();
}

void do_stand_wrd_obj(string prep, object ob)
{
   ob->do_verb_rule("stand", "WRD OBJ", prep, ob);
}

void create()
{
   add_rules(({""}));
   add_rules(({"WRD"}));
   add_rules(({"WRD OBJ"}), ({}));
}
