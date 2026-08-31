/* Do not remove the headers from this file! see /USAGE for more info. */

//
// REMOVE.C    970408  Fritti
//
// Remove a post from a bulletin board.
//

//: COMMAND
// Remove a post from a bulletin board, remove equipment, remove other things.
//
//  |  ``remove helmet``
//  |  ``remove all``
//
// .. TAGS: RST

inherit VERB_OB;

#include <driver/type.h>

mixed can_remove_wrd(string wrd)
{
   object brd = 0;
   mixed res;

   foreach (object ob in deep_inventory(environment(this_body())))
   {
      if ((int)ob->is_bulletin_board())
      {
         if (!brd)
            brd = ob;
         else
            return "Please specify on which board you want to "
                   "remove a note.\n";
      }
   }
   if (!brd)
      return "There's nothing here to remove notes from.\n";

   if ((res = brd->direct_remove_wrd_from_obj(wrd, brd)) != 1)
      return res;

   return default_checks();
}

mixed can_remove_wrd_from_obj(string wrd, object ob)
{
   return default_checks();
}

void do_remove_obj(object ob)
{
   ob->do_remove();
#ifdef USE_INTRODUCTIONS
   this_body()->clear_description();
#endif
}

void do_remove_obs(object *obs)
{
   foreach (object ob in obs)
   {
      //        TBUG("Remove: "+ob);
      if (typeof(ob) == T_STRING)
         continue;
      // Do not attempt to remove things not in inventory.
      if (environment(ob) != this_body())
         continue;
      ob->do_remove();
   }
#ifdef USE_INTRODUCTIONS
   this_body()->clear_description();
#endif
}

void do_remove_wrd(string wrd)
{
   object brd = 0;
   int id;

   foreach (object ob in deep_inventory(environment(this_body())))
   {
      if ((int)ob->is_bulletin_board())
         brd = ob;
   }

   sscanf(wrd, "%d", id);
   brd->do_remove(id);
}

void do_remove_wrd_from_obj(string wrd, object ob)
{
   int id;

   sscanf(wrd, "%d", id);
   ob->do_remove(id);
}

void create()
{
   add_rules(({"WRD", "WRD from OBJ", "OBJ", "OBS"}), ({"take off"}));
}
