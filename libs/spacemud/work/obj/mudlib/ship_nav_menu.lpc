/*
**	Navigation computer for Space MUD 2025
**
*/

inherit MENUS;
inherit SPACE_CLASSES;

class ship_info *owned_ships;
object terminal;

class menu toplevel;
// submenus of the toplevel (main) menu
// class menu soulmenu;

class menu_item quit_item;
class menu_item goto_main_menu_item;
class menu_item dock_ship_item;
class menu_item statement_item;
class menu_item release_ship_item;
class menu_item space_scan_item;
class menu_item change_bank_item;

class section main;
class section other;
class section guild;

// right now, we're just going to call the help command.
// private MENU helpmenu;

string menu_text(string s)
{
   return sprintf("[-- <222>%-64s<res>-----]", s);
}

void error_text(string s)
{
   write(sprintf("**** <162>%-s<res>\n", s));
}

void accent_text(string s)
{
   write(sprintf("[" + accent("<162>%-s<res>]\n"), s));
}

void quit_menu_application(int booked)
{
   if (!booked)
   {
      terminal->stop_using();
   }

   ::quit_menu_application();
}

void do_enter_ship()
{
   class docking_info di = terminal->query_docking();
   if (di)
   {
      int result;
      result = this_body()->move(di->vfile);

      this_body()->force_look();
      terminal->stop_using();
      ::quit_menu_application();
      return;
   }
   error_text("You fail to enter the ship.");
}

void do_dock_ship(mapping structs, string bank, string number)
{
   int num = to_int(number);
   int total_docks;
   mapping docks;
   float fee, docking_fee;
   class structure st;
   int docking_completed;
   object dock_room;
   object terminal;
   class ship_info si;

   if (number == "q" || number == "")
   {
      error_text("Docking procedure aborted.");
      this_body()->simple_action("$N $vabort the procedure.");
      return;
   }
   if (num <= 0 || num > sizeof(structs))
   {
      error_text("Invalid ship number '" + num + "'. Docking aborted.");
      this_body()->simple_action("$N $vabort the procedure.");
      return;
   }

   st = structs[num];
   fee = SPACESTATION_D->query_config(st->name)->docking_fee;

   if (!ACCOUNT_D->coverage(bank, this_body(), fee, "credit"))
   {
      error_text("Lacking coverage in your account to commence docking.");
      return;
   }
   else
      accent_text("Account coverage verified for docking at " + st->name);

   docks = SPACESTATION_D->query_docks(st->name);
   total_docks = sizeof(docks);

   if (!total_docks || !sizeof(filter(values(docks), ( : !$1:))))
   {
      error_text("Currently, no docking slots available. Stand by.");
      return;
   }

   // filter out taken docks.
   si = environment(this_body())->query_ship_info();
   docks = filter_mapping(docks, ( : !$2:));
   docking_completed = SHIP_D->docking_time(si->type);

   dock_room = load_object(choice(keys(docks)));
   if (objectp(dock_room))
   {
      terminal = present("docking_terminal_id", dock_room);
      if (objectp(terminal))
      {
         environment(this_body())
             ->intercom("Docking assigned at " + dock_room->short() + " for " + capitalize(si->type) + " callsign " +
                        si->name);
         environment(this_body())->intercom("Docking estimated in " + time_to_string(docking_completed - time()));
         terminal->set_docking(si, docking_completed);
         terminal->start_story();
         SHIP_D->pay_dock_ship(this_body(), fee, si, bank);
         quit_menu_application(1);
      }
   }
}

mapping get_structures(string bank, class structure *sts)
{
   int count = 1;

   mapping structs = ([]);
   frame_init_user();
   write(menu_text("Docking Sites"));
   printf(accent("%-5.5s %-25.25s %-15.15s %-15.15s %-25.25s"), "[#]", "Site name", "Distance", "Docking fee", "Owner");
   foreach (class structure st in sts)
   {
      float docking_fee = SPACESTATION_D->query_config(st->name)->docking_fee;
      string fee_col = ACCOUNT_D->coverage(bank, this_body(), docking_fee, "credit") ? "<084>" : "<160>";
      structs[count] = st;
      printf("<bld>%-5.5s %-25.25s<res> %-15.15s " + fee_col + "%-15.15s<res> %-25.25s\n", "[" + count + "]",
             capitalize(st->name), st->distance + " km", pround(docking_fee, 2) + " ¤", st->owner || "Independent");
      count++;
   }
   write("\n\n");
   return structs;
}

void dock_ship()
{
   float max_cost;
   mapping ships = ([]);
   string docked_ship;
   string bank = SHIP_D->query_bank(this_body());
   string ssn = this_body()->query_starsystem();
   int planet = this_body()->query_planet();
   int docking_completed;
   class structure *st = SPACE_D->query_structures(ssn, planet);

   if (!sizeof(st))
   {
      error_text("There are no nearby structures to dock at.");
      return;
   }
   if (terminal->query_docking())
   {
      docked_ship = terminal->query_docking()->vfile;
      docking_completed = terminal->query_docking()->docking_time;
   }

   if (!bank)
   {
      error_text("You need to set a bank connection before docking.");
      return;
   }

   this_body()->simple_action("$N $vbegin a docking procedure.");
   ships = get_structures(bank, st);

   modal_simple(( : do_dock_ship, ships, bank:), "Ship # to dock (q to quit): ", 1);
}

void enter_ship()
{
   if (!present("guild_vdu_ob", this_body()) || !present("guild_vdu_ob", this_body())->ob_state())
   {
      error_text(
          "You need to wear a VDU to enter the ship. It needs to be scanned by the docking terminal upon entry.\n");
      return;
   }

   if (terminal->query_docking())
   {
      this_body()->simple_action(
          "$N $vswipe $p VDU on the docking terminal and the door opens briefly and $n $vslip into the ship.");
      do_enter_ship();
   }
   else
   {
      error_text("Wait, where did your rental just go?\n");
   }
}

void release_ship(string answer)
{
   string name = lower_case(this_body()->query_name());
   int outstanding = 0;
   answer = lower_case(answer);
   if (answer != "yes" && answer != "y")
   {
      error_text("Aborted.");
      return;
   }
   terminal->clear_docking();
   quit_menu_application(0);
}

void confirm_release()
{
   if (!terminal->query_docking())
   {
      error_text("No docking under way, and no ship currently docked.\n");
      return;
   }
   modal_simple(( : release_ship:), "Send the ship away? (y/n) ", 1);
}

void bank_statement()
{
   string bank = SHIP_D->query_bank(this_body());
   accent_text("Your automatic withdrawals are tied to: " + upper_case(bank + " bank"));
   write(replace_string(ACCOUNT_D->bank_statement(bank, "credit", this_body()), " crd", " ¤  ") + "\n\n");
}

void change_bank(string *banks, string pick)
{
   int ipick = to_int(pick);
   if (!ipick || ipick > sizeof(banks) || ipick <= 0)
   {
      error_text("Invalid bank id.\n");
      return;
   }
   ipick--;
   SHIP_D->set_bank_connection(banks[ipick], this_body());
   write("Bank connection changed " + capitalize(banks[ipick]) + ".\n**Only 'credit' accepted as currency.\n\n");
}

void pick_a_bank()
{
   string *banks = keys(ACCOUNT_D->query_accounts(this_body()));
   int count = 1;
   if (!sizeof(banks))
   {
      error_text("You have no money in banks.");
      return;
   }
   write("You have money in the following banks:\n");
   foreach (string b in banks)
   {
      write("\t [" + count + "] " + capitalize(b) +
            " Bank - (Account #: " + ACCOUNT_D->fake_account_id(b, this_body()) + ")\n");
      count++;
   }
   modal_simple(( : change_bank, banks:), "Enter a number to pick that bank connection: ", 1);
}

void show_prices()
{
   class spacestation_config sc = SPACESTATION_D->query_config(this_body()->query_location());
   write(menu_text("Prices at " + this_body()->query_location()) + "\n\n");
   printf("%-35.35s %-10.10s\n", "Long Term Storage slot / day", pround(sc->storage_fee, 2) + " ¤");
   printf("%-35.35s %-10.10s\n", "1-time Docking fee", pround(sc->docking_fee, 2) + " ¤");
   write("\n");
}

private show_frame(string *parts)
{
   frame_init_user();
   set_frame_title(parts[0]);
   set_frame_header(parts[1]);
   set_frame_content(parts[2]);
   if (sizeof(parts) == 4)
      set_frame_footer(parts[3]);
   write(frame_render());
}

void do_space_scan(int list, string range)
{
   string *frame_data;
   int r = to_int(range);
   if (r <= 0 || r > 10)
   {
      error_text("Invalid scan range.");
      return;
   }
   if (list)
      show_frame(SPACE_D->print_near(this_body()->query_starsystem(), r));
   else
      show_frame(SPACE_D->print_map(this_body()->query_starsystem(), r));
}

void space_scan(int list)
{
   modal_simple(( : do_space_scan, list:), "Scan range? [1-10] ", 1);
}

void create(object t)
{
   string docked_at = environment(this_body())->is_docked();
   if (!clonep())
      return;
   terminal = t;

   toplevel = new_menu(menu_text(implode(explode("SHIP NAV", ""), " ")));
   main = new_section("Main", "accent");
   other = new_section("Other", "warning");
   add_section_item(toplevel, main);
   add_section_item(toplevel, other);

   quit_item = new_menu_item("Quit", ( : quit_menu_application, 0 :), "q");
   goto_main_menu_item = new_menu_item("Return to main menu", toplevel, "m");

   if (!docked_at)
   {
      dock_ship_item = new_menu_item("Dock the ship", ( : dock_ship:), "d");
      add_menu_item(main, dock_ship_item);
   }
   else
   {
      release_ship_item = new_menu_item("Cancel your docking", ( : confirm_release:), "C");
      add_menu_item(main, release_ship_item);
   }
   space_scan_item = new_menu_item("Space Map", ( : space_scan, 0 :), "m");
   add_menu_item(main, space_scan_item);
   space_scan_item = new_menu_item("System Scan Details", ( : space_scan, 1 :), "s");
   add_menu_item(main, space_scan_item);

   statement_item = new_menu_item("Show Bank Statement", ( : bank_statement:), "b", 1);
   add_menu_item(main, statement_item);
   change_bank_item = new_menu_item("Change Banking Connection", ( : pick_a_bank:), "c");
   add_menu_item(main, change_bank_item);

   add_menu_item(other, quit_item);
}

void start_menu()
{
   frame_init_user();
   init_menu_application(toplevel);
}
