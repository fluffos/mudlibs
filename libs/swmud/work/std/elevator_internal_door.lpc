// Do not remove the headers from this file! see /USAGE for more info.
inherit OBJ;

void setup();
mixed direct_open_obj();
mixed open();
mixed direct_close_obj();
mixed close();

string long()
{
   if (environment()->query_state("door"))
      return "The door is open.\n";
   else
      return "The door is closed.\n";
}

void setup()
{
   function f;
   set_id("door");
   set_adj("elevator");
   set_attached(1);
}

mixed direct_open_obj()
{
   if (call_other(environment(this_object()), "query_door_open"))
      return "It is already open!\n";
   if (call_other(environment(this_object()), "query_in_motion"))
      return "The door is stuck.\n";
   return 1;
}

mixed open()
{
   this_body()->simple_action("$N $vopen the door.\n", this_object());
   call_other(environment(this_object()), "open_the_door");
}

mixed direct_close_obj()
{
   if (!call_other(environment(this_object()), "query_door_open"))
      return "It is already closed!\n";
   return 1;
}

mixed close()
{
   this_body()->simple_action("$N $vclose the door.\n", this_object());
   call_other(environment(this_object()), "close_the_door");
}
