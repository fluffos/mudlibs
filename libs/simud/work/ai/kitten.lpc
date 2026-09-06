/* This object was the ORIGINAL attempt at writing an AI. It was adorable.
 * It is, however, long broken. 10 wizpoints to whoever duplicates this
 * behavior (and accompanying mob) under the new system.
 */

#include <emote.h>

inherit "/inherit/ai";

void on_tick() {
   debug("kitten::on_tick","ai");
   // make sure we don't have more than one tick running
   remove_call_out("on_tick");
   if (!anger)
     anger = ([]);

   // if busy, wait a few seconds
   if (cact != "waiting") {
      call_out("on_tick",4);
      return;
   }

   // if dead, stop ticking
   if (this_object()->query_dead()) {
      remove_call_out("on_tick");
      return;
   }

   // if hunting & no target remains
   if (cact == "hunt" && victim->query_dead()) {
      command("emote meows in trumph.");
      command("emote eats the corpse (well it would if that were written yet...)");
      this_object()->add_food(victim->query_food());
      this_object()->add_drink(victim->query_water());
      call_out( "on_tick", 60 + random(60) );
      return;
   }

   // select a new action
   if (is_hungry())
      start_act("hunt");
   else if (!victim)
      start_act("investigate");
   else if (random(100) < 60)
      start_act("wander");
   else
      start_act("emote");

   call_out( "on_tick", 20 + random(20) + boredom * 2 );
}

/*
/// Called whenever a soul is fired off in the room
void on_soul(int attribute, string param, string verb) {
   debug("kitten::on_soul, param = "+param+", verb = "+verb,"ai");
   if (!this_object()->id(param))
      return;
   if (verb == "pet") {
      if (anger[(string)this_player()] > 0) {
         if (random(100) < 30)
            command("hiss "+this_player()->query_name());
         else
            command("scratch "+this_player()->query_name());
         anger[(string)this_player()]++;
      } else if (anger[(string)this_player()] < 0) {
         command("purr "+this_player()->query_name());
      } else if (random(100) < 75 + this_player()->query_charm()) {
         anger[(string)this_player()]--;
         command("purr "+this_player()->query_name());
      } else {
         command("hiss "+this_player()->query_name());
      }
   }
}
*/

/** Causes the cat to walk 1-3 squares in any of the cardinal directions.
 *  Motivation: Boredom
 */
void act_wander() {
   string dir;
   debug("kitten::act_wander","ai");

   if (random(100) < 80 && !is_hungry()) {
      victim = 0;

      switch (random(4)) {
         case 0: dir = "north"; break;
         case 1: dir = "south"; break;
         case 2: dir = "west"; break;
         case 3: dir = "east"; break;
      }
      command("walk "+(string)(1 + random(3))+" "+dir);
   } else {
      string *exits = environment(this_object())->query_exit_dirs();
      command("go "+exits[random(sizeof(exits))]);
   }
   end_act();
}

/** Causes the cat to run up to something in the room and investigate it.
 *  Motivation: Curiosity
 */
void act_investigate() {
   object *inv = all_inventory(environment(this_object()));
   debug("kitten::act_investigate","ai");
   victim = inv[random(sizeof(inv))];
   boredom = 0;
   command("walk to "+(string)victim);
   end_act();
}

/** Causes the cat to do something catlike.
 *  Motivation: Boredom
 */
void act_emote() {
   debug("kitten::act_emote, victim = '"+(string)victim+"'","ai");
   if (!victim) {
      start_act("investigate");
      return;
   } else if (boredom > 5) {
      victim = 0;
      command("lick kitten");
   } else if (anger[(string)victim] > 2) {
      switch (random(5)) {
         case 0: anger[(string)victim]--;
         case 1: command("scratch "+victim->query_name()); break;
         default: command("glare "+victim->query_name()); break;
      }
      boredom--;
   } else {
      switch (random(5)) {
         case 0: command("lick "+victim->query_name()); break;
         case 1: command("stare "+victim->query_name()); break;
         case 2: command("meow "+victim->query_name()); break;
         default: command("lick kitten"); break;
      }
      boredom++;
   }
   end_act();
}

/** Causes the cat to hunt for food.
 *  Motivation: Hunger
 */
void act_hunt() {
   object machine, food, room;

   debug("kitten::act_hunt","ai");
   victim = 0;

   // easiest case, food is in inventory
   foreach (food : all_inventory())
      if (food->query_edible()) {
         command("eat "+food->query_name());
         end_act();
         return;
      }

   debug("this_object() = "+(string)this_object(),"ai");
   room = environment(this_object());
   debug("room = "+(string)room,"ai");

   // next case, food is in room
   foreach(food: all_inventory(room))
      if (food->query_edible()) {
         command("walk to "+(string)food);
         if (this_object()->query_adjacent(food)) {
            command("get "+food->query_name());
            command("eat "+food->query_name());
         } else
            command("emote meows hungrily while staring at "+food->query_name());
         end_act();
         return;
      }

   // funniest case, vending machine is in room
   if (machine = present("vending machine",room)) {
      command("walk to "+(string)machine);
      if (this_object()->query_adjacent(machine)) {
         command("push button 1");
         command("drink nectar");
      } else
         command("emote meows hungrily while staring at "+machine->query_name());
      end_act();
   } else { // worst case, food must be hunted
      foreach (food: all_inventory(room)) {
         if (food->query_race() == "feline")
            continue;
         if (food->query_is_living() && food->query_weight() < this_object()->query_weight() &&
             anger[(string)food] >= 0) {
            command("kill "+food->query_name());
            anger[(string)victim] = 10;
            victim = food;
            return;
         }
      }
      start_act("wander");
   }
}
