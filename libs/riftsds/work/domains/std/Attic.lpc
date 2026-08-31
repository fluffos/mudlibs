#pragma no_warnings
inherit "/std/indoor_room";

void setup();
void arrived()
{
   if (query_state("lamp"))
      tell_from_inside(this_object(), "The lamp on the button beside the elevator goes out.\n");
   clear_room_state("lamp");
}
void setup()
{
   function f;
   set_brief("The Attic");
   set_long("This is the attic above the church.\nThere is an elevator door to"
            " the west, and a button beside the door.\n$lamp");
   set_state_description("lamp_on", "\nThe lamp on the button beside the elevator is lit.\n");
   set_light(1);
   set_objects((["/std/elevator_door":({"west", "/domains/std//elevator"}),
          "/std/elevator_call_button":({"3/attic", "/domains/std//elevator"}), ]));
}
