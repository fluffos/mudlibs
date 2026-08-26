#pragma no_warnings
inherit "/std/indoor_room";

void setup();
mixed can_go_north()
{
   if (!wizardp(this_body()))
      return "A magic force stops you.\n";
   return 1;
}

mixed do_go_north()
{
   write("You wriggle through the force field...\n");
   return 0;
}

void arrived()
{
   if (query_state("lamp"))
      tell_from_inside(this_object(), "The lamp on the button beside the elevator goes out.\n");
   clear_room_state("lamp");
}
void setup()
{
   function f;
   set_brief("Wizards Hall");
   set_long("You are in the hall of the wizards.\nThere is an elevator door to"
            " the west, with a button beside it,\nand a shimmering field to th"
            "e north.$lamp");
   set_state_description("lamp_on", "\nThere is a lit lamp beside the elevator.\n");
   set_light(1);
   set_objects((["/std/elevator_door":({"west", "/domains/std//elevator"}),
          "/std/elevator_call_button":({"4/wizhall", "/domains/std//elevator"}), ]));
   set_exits((["north":"quest_room.scr", ]));
}
