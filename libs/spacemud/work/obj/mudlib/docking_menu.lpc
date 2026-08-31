/*
**	Housing Terminal by Tsath 2020 for Nuke Mudlib
**
*/

inherit MENUS;
inherit SPACE_CLASSES;

class ship_info *owned_ships;
object terminal;

class menu toplevel;
// submenus of the toplevel (main) menu
// MENU soulmenu;

class menu_item quit_item;
class menu_item goto_main_menu_item;
class menu_item ship_info_item;
class menu_item dock_ship_item;
class menu_item statement_item;
class menu_item release_ship_item;
class menu_item purchase_ship_item;
class menu_item change_bank_item;
class menu_item terms_item;
class menu_item main_seperator;
class menu_item sub_seperator;

class section banking;
class section ships;
class section other;

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
      this_body()->simple_action("$N $vturn away from the terminal again.");
   }
   else
   {
      this_body()->simple_action("$N $vhave occupied this docking terminal.");
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

void do_dock_ship(mapping ships, float docking_fee, string bank, string number)
{
   int num = to_int(number);
   int docking_completed;
   float fee;

   if (terminal->query_docking())
   {
      docking_completed = terminal->query_docking()->docking_time;
   }

   if (number == "q" || number == "")
   {
      error_text("Docking procedure aborted.");
      this_body()->simple_action("$N $vabort the procedure.");
      return;
   }
   if (num <= 0 || num > sizeof(ships))
   {
      error_text("Invalid ship number '" + num + "'. Docking aborted.");
      this_body()->simple_action("$N $vabort the procedure.");
      return;
   }

   fee = SHIP_D->outstanding_fees(((class ship_info)ships[num])->name) + docking_fee;

   if (!ACCOUNT_D->coverage(bank, this_body(), fee, "credit"))
   {
      error_text("Lacking coverage in your account to commence docking.");
      return;
   }

   docking_completed = SHIP_D->docking_time(((class ship_info)ships[num])->type);
   terminal->set_docking(ships[num], docking_completed);
   write("Your " + ((class ship_info)ships[num])->type + " callsign " + ((class ship_info)ships[num])->name +
         " will be docked in " + time_to_string(docking_completed - time()) + ".");
   SHIP_D->pay_dock_ship(this_body(), fee, ships[num], bank);
   terminal->start_story();
   quit_menu_application(1);
}

mapping get_ship_list()
{
   float max_cost;
   int count = 1;
   mapping ships = ([]);
   frame_init_user();
   write(menu_text("Ship Inventory"));
   printf(accent("%-5.5s %-25.25s %-15.15s %-15.15s %-25.25s"), "[#]", "Ship Type", "Insignia", "Fees", "Parked at");
   foreach (class ship_info si in owned_ships)
   {
      object dock_room = si->docked_at ? load_object(si->docked_at) : 0;
      float fee = SHIP_D->outstanding_fees(si->name);
      ships[count] = si;
      printf("<bld>%-5.5s %-25.25s<res> %-15.15s %-15.15s %-25.25s\n", "[" + count + "]", capitalize(si->type),
             capitalize(si->name), pround(fee, 2) + " ¤",
             (si->long_term ? "Long term (" + time_to_string(time() - si->long_term, 1) + ")"
                            : (dock_room ? dock_room->short() : "Unknown")));
      if (fee > max_cost)
         max_cost = fee;
      count++;
   }
   ships["max"] = max_cost;
   write("\n\n");
   return ships;
}

void show_ship_info()
{
   if (!sizeof(owned_ships))
   {
      write("You have no ships docked here.\n");
      return;
   }

   get_ship_list();
}

void dock_ship()
{
   float max_cost;
   mapping ships = ([]);
   string docked_ship;
   string bank = SHIP_D->query_bank(this_body());
   int docking_completed;
   float docking_fee = SPACESTATION_D->query_config(this_body()->query_location())->docking_fee;

   if (terminal->query_docking())
   {
      docked_ship = terminal->query_docking()->vfile;
      docking_completed = terminal->query_docking()->docking_time;
   }

   if (!sizeof(owned_ships))
   {
      error_text("You have no ships docked here.");
      return;
   }

   if (!bank)
   {
      error_text("You need to set a bank connection before docking.");
      return;
   }

   this_body()->simple_action("$N $vbegin a docking procedure.");
   ships = get_ship_list();
   max_cost = ships["max"];
   accent_text(this_body()->query_location() + " charges a docking fee of " + pround(docking_fee, 2) +
               " ¤ will be charged for docking.");
   if (!ACCOUNT_D->coverage(bank, this_body(), docking_fee + max_cost, "credit"))
      error_text("Your account is low on funds and docking may not be available.");

   modal_simple(( : do_dock_ship, ships, docking_fee, bank:), "Ship # to dock (q to quit): ", 1);
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
   frame_init_user();
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

void create(object t)
{
   if (!clonep())
      return;
   terminal = t;

   owned_ships = SHIP_D->query_owned_ship(this_body(), this_body()->query_location());

   banking = new_section("Banking", "accent");
   ships = new_section("Ships", "accent");
   other = new_section("Other", "warning");

   toplevel = new_menu(implode(explode(upper_case(this_body()->query_location()) + " DOCKS", ""), " "));
   add_section_item(toplevel, banking);
   add_section_item(toplevel, ships);
   add_section_item(toplevel, other);
   quit_item = new_menu_item("Quit", ( : quit_menu_application, 0 :), "q");
   goto_main_menu_item = new_menu_item("Return to main menu", toplevel, "m");

   ship_info_item = new_menu_item("Show Ship Information", ( : show_ship_info:), "s", 1);

   if (sizeof(owned_ships))
   {
      if (!terminal->query_docking())
      {
         dock_ship_item = new_menu_item("Dock a ship", ( : dock_ship:), "d");
         add_menu_item(ships, dock_ship_item);
      }
      else
      {
         dock_ship_item = new_menu_item("Enter a docked ship", ( : enter_ship:), "e");
         add_menu_item(ships, dock_ship_item);
         release_ship_item = new_menu_item("Cancel your docking", ( : confirm_release:), "C");
         add_menu_item(ships, release_ship_item);
      }
      statement_item = new_menu_item("Show Bank Statement", ( : bank_statement:), "b", 1);
      add_menu_item(banking, statement_item);
      change_bank_item = new_menu_item("Change Banking Connection", ( : pick_a_bank:), "c");
      add_menu_item(banking, change_bank_item);
   }

   terms_item = new_menu_item(this_body()->query_location() + " Prices", ( : show_prices:), "p", 1);
   add_menu_item(other, terms_item);
   add_menu_item(other, quit_item);
   add_menu_item(other, ship_info_item);
}

void start_menu()
{
   frame_init_user();
   init_menu_application(toplevel);
}
