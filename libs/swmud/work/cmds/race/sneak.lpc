// Last edited by deforce on 11-12-2009
// Twi'lek and Human racial skill
#include <flags.h>

inherit M_MESSAGES;
inherit VERB_OB;

void sneak(object room, string direction);

private mapping translations = ([ "n" : "north", "s" : "south", "e" : "east", "w" : "west", "ne" : "northeast", "nw" : "northwest", "se" : "southeast", "sw" : "southwest", "u" : "up", "d" : "down" ]);

void do_sneak_wrd(string direction)
{
   object room;

   if (translations[direction]) { direction = translations[direction]; }

   room = load_object(environment(this_body())->query_exit_destination(direction));

   if (room->is_room())
   {
      object this_body = this_body();

      this_body->add_skill_delay(8);

      if (this_body->test_skill("sneak", this_body->query_primary_level() * (this_body->query_race() == "twi'lek" ? 10 : 4)))
      {
         sneak(room, direction);
      }
      else
      {
         this_body->simple_action("$N $vfail to sneak " + direction + " into " + room->the_short() + ".\n");
      }
   }
   else
   {
      write(capitalize(room->the_short()) + " is not a room.\n");
   }
}

void do_sneak()
{
   write("Sneak in which direction?\n");
}

mixed can_sneak_wrd()
{
   object this_body = this_body();

   if ((this_body->query_race() == "twi'lek") || this_body->is_human())
   {
      if (this_body->has_skill_delay())
      {
         return "You are too busy to sneak into another room.\n";
      }
      else if (this_body->query_stunned())
      {
         return "You are too distracted to sneak into another room.\n";
      }
   }
   else
   {
      return "Only Twi'leks and Humans can sneak into another room.\n";
   }

   return 1;
}

void sneak(object room, string direction)
{
   object this_body = this_body();
   object last_room = environment(this_body);
   int rank = this_body->query_skill("sneak") / 100;

   if (this_body->move(room))
   {
      string text = this_body->query_msg("leave");
      if (this_body->is_body()) { text = "%^PLAYER_MOVEMENT%^" + text + "%^RESET%^"; }

      foreach (object thing in all_inventory(last_room))
      {
         if ((thing != this_body) && (random(thing->query_per() + (thing->query_luck() / 5)) > (rank * 10)))
         {
            tell(thing, action(({ this_body }), text, ({ direction }))[1]);
         }
      }

      write("You sneak " + direction + " into " + room->the_short() + ".\n");
      this_body->notify_move();

      text = this_body->query_msg("enter");
      if (this_body->is_body()) { text = "%^PLAYER_MOVEMENT%^" + text + "%^RESET%^"; }

      foreach (object thing in all_inventory(room))
      {
         if ((thing != this_body) && (random(thing->query_per() + (thing->query_luck() / 5)) > (rank * 10)))
         {
            tell(thing, action(({ this_body }), text, ({ direction }))[1]);
         }
      }
   }
}

void create()
{
   add_rules( ({ "", "WRD" }) );
}