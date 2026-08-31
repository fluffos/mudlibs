/* Do not remove the headers from this file! see /USAGE for more info. */

#include <npcscript.h>

inherit LIVING;
inherit M_TRIGGERS;
inherit M_SMARTMOVE;
inherit M_NPCSCRIPT;

void setup()
{
   set_gender(1);
   set_name("Robert");
   add_id("bob");
   set_proper_name("Robert");
   set_in_room_desc("Robert (Example NPC Script - look at me)");
   set_long("An example of an NPC using NPC script. To start a demo script "
            "use:\n<011>@.here:bob->execute_script(\"demo\")<res>\nin your cmd shell." +
            "The demo script can be found and edited under ^std/monster/scripts/demo.npcs");
   create_script_from_file("demo", "scripts/demo.npcs");
   set_recovery_time(10);
}

void recover()
{
   object example_room = load_object("/domains/std/room/Example_Room1");
   if (environment(this_object()) == example_room)
      return;
   tell_from_outside(environment(this_object()), "Robert hurries back to the example room.");
   this_object()->move(example_room);
   tell_from_outside(environment(this_object()), "Robert hurries into the room.");
   do_game_command("say Sorry, I got lost.");
}