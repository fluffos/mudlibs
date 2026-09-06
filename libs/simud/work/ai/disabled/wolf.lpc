#include <emote.h>

// defect notes:
//

inherit "/ai/module";
inherit "/inherit/ai";

string *emotes = ({"froth","grr","growl","listen"});

void create() {
   ::create();
   if (!mappingp(desire)) {
      desire = ([ ]);
   }
   cact = "waiting";
   call_out("on_tick", 0);
}

/// \return 1 if the wolf is hungry (below 75% food).
int is_hungry() {
   return (this_object()->query_food()
      < this_object()->query_food_capacity() * 3 / 4);
}

/// Perform the actual AI tick (overrides method in /inherit/ai.c)
void on_tick() {
   debug("on_tick, cact = "+cact,"ai");
   // make sure we don't have more than one tick running
   remove_call_out("on_tick");

   if (!anger)
     anger = ([ ]);

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

   // combat ai goes here
   if (this_object()->query_combat()) {
      command("growl");
      call_out( "on_tick", 5+random(5) );
   } else {
      boredom++;
      desire["mate"]++;

      debug("Boredom: " + boredom, "ai" );
      debug("Libido: " + desire["mate"], "ai" );

      // if hunting & no target remains
      if (cact == "hunt" && victim && victim->query_dead()) {
         command("howl");
         // todo:  Use monster specific "devour" command.
         command("chew " + victim->query_dead());
      }

      // select a new action
      if (is_hungry())
         start_act("hunt");
      else if (this_object()->query_food() > 350)
         start_act("mate");
      else if (this_object()->query_party_object() &&
               this_object()->query_party_object()->query_leader() == this_object() ) {
         if (random(100) < 60)
            start_act("wander");
         else
            start_act("emote");
      } else
         start_act("emote");

      call_out( "on_tick", 20 + random(10) + boredom * 2 );
   }
}

/** Causes the wolf to seek a mate and reproduce
 *  Motivation: Comfort
 */
void act_mate() {
   object pack = this_object()->query_party_object();

   // If the wolf has mated recently, or if there are a bazillion wolves, don't bother...
   if ( desire["mate"] < 10 + sizeof(clones(object_name(this_object()))) ) {
      debug("not enough desire to mate ("+desire["mate"]+"/10)","ai");
      end_act();
      return;
   }

   // If a wolf is in a pack, then they will mate with one of the members
   if (pack) {
      object wolf;
      debug("wolf is in a pack","ai");
      foreach ( wolf : pack->query_members() ) {
         debug("considering "+(string)wolf+" as a mate","ai");
         if (wolf->query_gender() != this_object()->query_gender()) {
            object baby = clone_object(object_name(this_object()));
            debug("looks good, commencing mating ritual and stuff","ai");
            command("snuggle wolf");
            baby->move(environment(this_object()));
            this_object()->msg_local("~CLABA new wolf is born.~CDEF");
            desire["mate"] = 0;
            // todo:  have baby grow up and remain part of the pack
            // then leave the pack to disperse when it reaches adulthood
         }
      }
   } else {   // otherwise, they will seek to form a pack
      object wolf;
      debug("wolf not in pack, seeking mate","ai");
      foreach ( wolf : all_inventory(environment()) ) {
         if ( object_name(wolf) == object_name(this_object()) && !wolf->query_party_object() &&
              wolf->query_gender() != this_object()->query_gender() ) {
            debug("looks good, initiate flirtation","ai");
            command("flirt");
            command("party");
            command("rally "+(string)wolf);
            debug("new party formed","ai");
         }
      }
   }
   end_act();
}

/** Causes wolf to leave the room
 *  Motivation: Boredom
 */
void act_wander() {
   string *exits = environment(this_object())->query_exit_dirs();
   object pack = this_object()->query_party_object();
   if (!pack || pack->query_leader() == this_object()) {
      command("go "+exits[random(sizeof(exits))]);
      boredom--;
   }
   end_act();
}

/** Causes the wolf to do something to pass the time.
 *  Motivation: Boredom
 */
void act_emote() {
   if (random(100) < 70)
      command(emotes[random(sizeof(emotes))]);
   else
      switch (random(5)) {
         case 0: command("emote paces back and forth impatiently."); break;
         case 1: command("emote pants lazily."); break;
         case 2: command("emote howls."); break;
         default: command("emote snaps to attention."); break;
      }
   boredom--;
   end_act();
}

/** Causes the wolf to hunt for food.
 *  Motivation: Hunger
 */
void act_hunt() {
   object food, room;

   // easiest case, food is in inventory
   foreach (food : all_inventory())
      if (food->query_edible()) {
         command("eat "+food->query_name());
         end_act();
         return;
      }

   room = environment(this_object());

   // next case, food is in room
   foreach(food: all_inventory(room)) {
      if (food->query_dead()) {
         command("chew "+food->query_name());
         return;
      }
      if (food->query_edible()) {
         command("walk to "+(string)food);
         if (this_object()->query_adjacent(food)) {
            command("get "+food->query_name());
            command("eat "+food->query_name());
            end_act();
            return;
         }
         break;
      }
   }

   // worst case, food must be hunted
   foreach (food: all_inventory(room)) {
      // will only attack other dogs if starving
      if (food->query_race() == "canine" && this_object()->query_food() >= 0)
         continue;
      // will only attack living targets who are not in good standing
      if (food->query_is_living() && anger[(string)food] >= 0) {
         int me, him;
         victim = food;
         me = this_object()->query_strength() + this_object()->query_constitution() + this_object()->query_speed() + random(3);
         him = victim->query_strength() + victim->query_constitution() + victim->query_speed();
         if (me > him) {
            command("kill "+victim->query_name());
            anger[(string)victim] = 10;
            return;
         } else {
            command("glower "+victim->query_name());
         }
      }
   }
   command("emote howls mournfully.");
   start_act("wander");
}
