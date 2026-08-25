// Do not remove the headers from this file! see /USAGE for more info.
inherit OBJ;

string where;
string elevator;

mixed direct_press_obj();

void do_press()
{
   int state = 0;
   object ele = load_object(evaluate_path(elevator, 0, 1));
   if (!ele)
      error("Cannot load elevator called '" + elevator + "'");
   this_body()->simple_action("$N $vcall the elevator by pressing the $o.", this_object());
   state = ele->call_elevator(where);

   switch (state)
   {
   case 1: // We're coming ASAP, added to destination queue.
      tell_from_inside(environment(this_object()), "The lamp on the elevator button lights up.\n");
      environment(this_object())->set_room_state("lamp");
      break;
   case 2: // Elevator already here.
      tell_from_inside(environment(this_object()), "The lamp briefly blinks.\n");
      break;
   case 0: // Elevator already moving to this location. Have patience.
      tell_from_inside(environment(this_object()), "The lamp flashes red; it seems to heading here already.\n");
      break;
   }
}

void setup(string w, string e)
{
   set_attached(1);
   set_adj("elevator");
   set_id("button");
   where = w;
   elevator = e;
}

mixed direct_press_obj()
{
   return 1;
}
