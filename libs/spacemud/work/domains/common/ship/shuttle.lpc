inherit SPACESHIP;

string query_owner();
void test();

string shuttle_id = "shuttle-" + random(100000);
int refuse_undock = 5;
string starsystem;
string location;
mapping payload;
object npcship;
object entry_room;
string npcship_id;
string room_type;
int destination_reached_at;

int *entry;

void setup()
{
   // Feed the random ID to SHIP_D to get a "proper ship ID"
   shuttle_id = SHIP_D->ship_name(shuttle_id);
   set_id("shuttle", "ship");
   set_brief("Space shuttle " + shuttle_id + " passenger bay");
   set_long(
       "The passenger bay of the Orion X5 space shuttle is a compact with small round windows on each side, "
       "utilitarian space designed for functionality and efficiency. Rows of padded seats, arranged in pairs on "
       "either side of a narrow aisle, provide seating for up to ten passengers. Each seat is equipped with harnesses "
       "to ensure safety during turbulent phases of the flight. The walls are smooth and unadorned, covered in a "
       "durable, easy-to-clean material, with no access panels or buttons within reach of curious hands. The "
       "bulkhead at the front is sealed off to passengers.\n"
       "A panel for shuttle control sits at the front of the cabin, and an airlock is set in the wall leading "
       "outside. The floor has a $hatch hatch.");
   add_item(
       "window", "windows",
       "The shuttle's windows are small and reinforced, offering limited but intriguing glimpses of the outer space "
       "beyond. The flooring is made of non-slip material, ensuring safe movement even in zero gravity conditions.");
   add_item("bulkhead",
            "At the front of the bay, a reinforced bulkhead separates the passenger area from the cockpit, with an "
            "intercom system being the only means of communication with the crew. A simple, built-in display screen at "
            "the head of the aisle provides basic flight information and emergency instructions, ensuring passengers "
            "are well-informed without unnecessary distractions.");
   set_ship_cost(50000);
   set_ship_size(2);
   set_ship_type("orion space shuttle");
   set_objects((["^common/item/airlock":1, "^common/item/shuttle_panel":1]));
   test();
}

void comms(string s)
{
   tell_from_inside(this_object(), s + "\n");
}

void speaker(string s)
{
   comms("%^SAY%^The speaker says<res>, \"" + s + "\".");
}

void set_payload(mapping m)
{
   payload = m;
}

void test()
{
   payload = (["shuttle":"/domains/common/ship/shuttle",
                "expiry":1721938002,
               "problem":"<bld>Power Core Failure<res>: The ship's primary power source has malfunctioned, "
                         "leading to a complete systems shutdown.",
               "mission":"CORE", "ship type":"Void Frigate", "size":6, ]);
}

mapping payload()
{
   return payload;
}

void set_location(string ss, string l)
{
   starsystem = ss;
   location = l;
}

string query_location()
{
   return location;
}

string query_starsystem()
{
   return starsystem;
}

string ship_name()
{
   return shuttle_id;
}

void flight(int stage)
{
   object terminal, temp;
   switch (stage)
   {
   case 0:
      speaker("We are now leaving the dock. Strap in");
      break;
   case 1:
      if (this_object()->is_docked())
      {
         terminal = present("terminal", load_object(this_object()->is_docked()));
         terminal->undocking();
         comms("The shuttle jerks as it is released from the docking clamps.");
      }
      else
         comms("You can hear the shuttle checking its docking clamps.");
      break;
   case 2:
      comms("The shuttle thrusters slowly pushes the shuttle away from the station dock.");
      break;
   case 4:
      comms("The shuttle picks up speed and heads to open space.");
      break;
   case 5:
      destination_reached_at = time() + random(30) + random(30) + 10;
      speaker("We have now reached cruising speed, and we will be at your destination in " +
              time_to_string(destination_reached_at - time()) + ". Enjoy the flight");

      // Handover to docking.
      call_out("dock_with_npcship", destination_reached_at - time());
      return;
   }

   stage++;
   if (stage < 6)
      call_out("flight", random(5) + 3, stage);
}

int destination_reached_at()
{
   return destination_reached_at;
}

void dock_with_npcship(int stage)
{
   int tns = time_ns();
   // Initialize mission area
   if (!npcship)
   {
      npcship_id = "/domains/common/ship/npcship/" + tns + "/" + payload["size"] + "/";
      payload["id"] = tns;
      npcship = load_object(npcship_id + "0/0");
      entry = npcship->random_room();
      room_type = npcship->room_type_name(npcship->room_type(entry));
   }

   switch (stage)
   {
   case 0:
      comms("You see the shuttle approach a " + npcship->query_ship_type() + ".");
      break;
   case 1:
      comms("You fly by side of the " + npcship->size_name() + " vessel noticing the insignia <192>" +
            npcship->ship_name() + "<res> written on the side.");
      break;
   case 2:
      speaker("Please strap in for docking.");
      break;
   case 4:
      comms("The shuttle rumbles and turns sharply.");
      break;
   case 5:
      speaker("Found docking hatch with " + npcship->ship_name() + " leading to " + add_article(room_type) +
              ". Docking commencing");
      break;
   case 6:
      speaker("Please remain still until this Orion X5 has come to a complete halt.");
      break;
   case 8:
      comms("A metallic clank is heard from below the shuttle hatch in the floor.");
      break;
   case 10:
      speaker("We have successfully docked, and this unit will await your return.");
      add_exit("down", npcship_id + entry[0] + "/" + entry[1]);
      entry_room = load_object(npcship_id + entry[0] + "/" + entry[1]);
      entry_room->add_exit("up", file_name(this_object()));
      comms("The hatch in the floor opens.");
   }

   stage++;
   if (stage < 11)
      call_out("dock_with_npcship", random(5) + 3, stage);
}

int is_ship_empty()
{
   if (refuse_undock)
      refuse_undock--;

   return refuse_undock == 0;
}

// Override the persistance function, since this one is not persisted.
void object_arrived(object ob)
{
   TBUG(ob->short() + " arrived.");
}

// Must be in a spaceship to handle the virtualization
object virtual_create(string arg)
{
   return ::virtual_create(__FILE__, arg);
}