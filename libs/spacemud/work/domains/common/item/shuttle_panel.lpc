
inherit OBJ;
inherit M_OPENABLE;
inherit M_INPUT;

string code;
object body;

string panel_id()
{
   return environment()->ship_name();
}

void when_opened()
{
   write("A sleek touchscreen display beneath is revealed. The interface comes to life with a soft hum "
         "and a vibrant holographic display upon exposure.");
}

void mudlib_setup()
{
   ::mudlib_setup();
   set_id("communication panel", "panel", "casing");
   set_in_room_desc("A interactive panel is at the head of the isle.");
   set_long("A communication panel to interact with the shuttle systems.");
   set_attached(1);
   add_hook("open", ( : when_opened:));
}

mixed direct_use_obj()
{
   if (body && !present(body, environment()) || body == this_body())
      body = 0;

   return query_closed() ? "#The panel is closed." : (body ? body->query_name() + " is already using that panel." : 1);
}

mixed direct_close_obj()
{
   if (body && !present(body, environment()) || body == this_body())
      body = 0;

   return body ? body->query_name() + " is using that panel, so you cannot close it." : 1;
}

void stop_using()
{
   body = 0;
}

private
void panel_comms(mixed s)
{
   write("%^DIGITAL_DISPLAY%^[" + panel_id() + "] - " + upper_case("" + s) + "<res>\n");
}

varargs void panel_info(string s)
{
   if (s)
      panel_comms(s);
   panel_comms("Enter command");
}

void print_help()
{
   string *help = ({"Shuttle controls", " [R] - Ready to launch", " [C] - Cancel ongoing launch",
                    " [I] - Mission Information", " [?] - Help info", "", " [Q] - Logout / Quit"});

   foreach (string h in help)
      panel_comms(h);
}

void mission_info()
{
   string dest_time = time_to_string((environment()->destination_reached_at() - time()));
   panel_comms("<Awaiting carrier> DL_Datarequest " + environment()->payload()["id"] || "_____");
   panel_comms("...");
   panel_comms("<bld>Mission<res>: " + environment()->payload()["mission"]);
   panel_comms(environment()->payload()["problem"]);
   panel_comms("<bld>Time to destination<res>: " + (strlen(dest_time) ? dest_time : "(Unknown)"));
}

void main_input(string c)
{
   c = lower_case(c);
   switch (c)
   {
   case "?":
   case "h":
      panel_comms("Help requested");
      print_help();
      break;
   case "i":
      panel_comms("Mission info requested");
      mission_info();
      break;
   case "q":
      panel_comms("user logout");
      this_body()->do_game_command("close panel");
      stop_using();
      return;
   case "r":
      panel_comms("Flight requested");
      environment(this_object())->flight();
      break;
   default:
      panel_info();
      break;
   }

   modal_simple(( : main_input:));
}

void do_use()
{
   if (body)
   {
      if (!present(body, environment()))
         body = 0;
   }

   body = this_body();
   body->simple_action("The panel lights up as $n $vpress it.");
   panel_comms("Welcome aboard this Orion Shuttle.");
   panel_comms("Press (?) for HELP or (q) to QUIT at any time.");
   call_out("panel_info", 1);
   modal_simple(( : main_input:));
}

string long()
{
   string l = "The communication panel is a sleek, touch-sensitive interface with a holographic display. It features "
              "intuitive icons for various channels, a central microphone, and emergency override buttons. Colored "
              "status lights indicate connection strength, while a scrollable log records all transmissions. Durable "
              "and user-friendly, it's designed for quick, efficient communication.";

   return l + "\n\n" + m_openable::extra_long_stuff();
}