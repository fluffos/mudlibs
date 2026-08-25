// Do not remove the headers from this file! see /USAGE for more info.

inherit ELEVATOR;

void setup()
{
   // Call setup() in ELEVATOR
   ::setup();
   // Description of the elevator make sure to mention the buttons you can press.
   // Cmds like 'look at cryo button' also works.
   set_long("You are in the elevator.  There are four buttons, labeled " +
            "'(1) Lima', '(2) Church', '(3) Attic', '(4) Wiz hall'.$elevator_door");
   // Set destinations with filenames of where we can go and shorthands.
   set_destinations(
       (["1/lima":"^std/Wizroom",
            "2/church":"^std//Church", "3/attic":"^std//Attic", "4/wizhall":"^std//wiz_hall", ]));

   // Set start position for elevator
   move_to("2/church");

   // Set the distance from and to each destination in seconds
   set_distance("2/church", "4/wizhall", 26);
   set_distance("3/attic", "4/wizhall", 32);
   set_distance("1/lima", "2/church", 16);
   set_distance("1/lima", "3/attic", 10);
   set_distance("1/lima", "4/wizhall", 42);

   // Set an elevator door direction and default location
   set_objects((["/std/elevator_door":({"east", "^std//Attic"})]));

   // Spawn the buttons on the wall automatically.
   // This *must* be done after the set_destinations() cal.
   setup_buttons();
}
