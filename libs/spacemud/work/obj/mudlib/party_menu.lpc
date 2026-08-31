/* Do not remove the headers from this file! see /USAGE for more info. */

// party_menu.c - Menu object accessible through the 'party' command
//                for all players. Includes all party-related
//                functions.
// March 1, 1997: Iizuka@Lima Bean created.
// August 15, 1999: Iizuka@Lima Bean ripped creation process out of the
//                  party player command and moved it here.

#define MAX_ATTEMPTS 3

#include <mudlib.h>

inherit MENUS;
inherit CLASS_PARTY;

private
varargs void enter_password(string owner, string party_name, int failures, string response);
void start_menu();

class menu toplevel;
class menu maint;
class menu empty;

class menu_item quit_item;
class menu_item main_seperator;
class menu_item help_item;

class section party_data;
class section party_maint;
class section party_menu;

private
string party_name;
private
object user;
private
object *invites = ({});
int is_lead = 0;

void who_current()
{
   int online;
   class party party = PARTY_D->query_party(party_name);
   string c = "";
   mapping members = party.members;
   mapping kills = party.kills;
   frame_init_user();
   set_frame_title("Party: " + party_name);
   set_frame_header(sprintf("%-15.15s %-10.10s %-10.10s %-10.10s", "Player", "Level", "Role", "Kills"));

   foreach (string name in keys(members))
   {
      object body = find_body(lower_case(name));
      if (body)
      {
         c += sprintf(" %-15.15s %-10.10s %-10.10s %-10.10s\n", body->query_name(), "" + body->query_level(),
                      members[name] == 1 ? "Lead" : "Member", "" + kills[name]);
         online++;
      }
      else
         c += sprintf(warning(" %-15.15s %-10.10s %-10.10s %-10.10s") + "\n", name, "Offline",
                      members[name] == 1 ? "Lead" : "Member", "" + kills[name]);
   }
   set_frame_footer(sprintf("%d member%s, %d online right now. Total kills for the party: %d", sizeof(members),
                            sizeof(members) == 1 ? "" : "s", online, party.total_kills));
   set_frame_content(c);
   write(frame_render());
}

void party_maint()
{
   return;
}

void party_help()
{
   write(accent("Calling 'help parties':"));
   new (HELPSYS)->begin_help("parties");
   return;
}

void remove()
{
   destruct();
}

string query_user()
{
   return user ? user->query_name() : "none";
}

void last_ten_kills()
{
   string *list = PARTY_D->query_kill_list(party_name);
   int count = sizeof(list);
   if (!list)
   {
      write("No kills yet, go slay.");
      return;
   }
   printf("Last 10 kills in the party");
   printf("--------------------------");
   foreach (string kill in list)
   {
      printf("%-3.3s %s", "" + count, kill);
      count--;
   }
   printf("--------------------------\n\n");

   return;
}

void list_active()
{
   string c = "";
   mapping active = PARTY_D->list_all_parties();
   frame_init_user();
   set_frame_title("Party: " + party_name);
   set_frame_header(sprintf("%-25.25s %-12.12s %-12.12s", "Party Name", "Kill count", "Members"));

   foreach (string name, int *data in active)
   {
      c += sprintf(" %-25.25s %-12.12s %-12.12s", name, "" + data[0], "" + data[1]);
   }
   set_frame_content(c);
   write(frame_render());
}

void quit_party()
{
   printf("Removing you from %s.. %%^RED%%^done.%%^RESET%%^\n\n", party_name);
   if (sizeof(PARTY_D->query_party_members(party_name)) == 1)
      PARTY_D->remove_party(party_name);
   else
      PARTY_D->remove_member(user->query_name(), party_name);
   quit_menu_application();
}

void confirm_create(string owner, string party_name, string response)
{
   switch (response)
   {
   case "n":
   case "no":
      destruct();
   case "y":
   case "yes":
      modal_simple(( : enter_password, owner, party_name, 0 :), "   Enter password: ", 1);
      return;
   default:
      modal_simple(( : confirm_create, owner, party_name:), "Enter 'yes' or 'no' please: ", 0);
      return;
   }
}

private
void confirm_password(string owner, string party_name, string password, int failures, string response)
{
   if (response != password)
   {
      write("\nPasswords do not match!\n");
      if (++failures == MAX_ATTEMPTS)
      {
         write("Sorry..\n");
         destruct();
      }
      modal_simple(( : enter_password, owner, party_name, failures:), "   Enter password: ", 1);
      return;
   }

   PARTY_D->register_party(party_name, owner, password);
   write("\n");
   start_menu();
}

void confirm_change_password(string password, string confirmed_password)
{
   if (strlen(password) < 3)
   {
      write(warning("** Password must be at least 3 characters."));
      return;
   }

   if (!confirmed_password)
   {
      modal_simple(( : confirm_change_password, password:), "   Once more: ", 1);
      return;
   }
   if (password != confirmed_password)
   {
      write(warning("\nYour passwords are a poor match, try couples therapy?\n"));
      return;
   }
   PARTY_D->set_password(party_name, confirmed_password);
   write("New password set for " + party_name + ".");
}

private
void change_password()
{
   modal_simple(( : confirm_change_password:), "   Enter password: ", 1);
}

private
void kill_menu_for(string s)
{
   object *menus = filter_array(objects(), (
                                               : base_name($1) == "/obj/mudlib/party_menu" &&
                                                     ($1->query_user() == $(s) || $1->query_user() == "none")
                                               :));
   menus->remove();
}

private
void invite_member(string member)
{
   object target = find_body(member);
   class party party = PARTY_D->query_party(party_name);
   mapping members = party.members;

   if (lower_case(member) == "q" || member == "")
   {
      write("Ok, no invite.");
      return;
   }

   if (!member || member == "" || member == "i")
   {
      modal_simple(( : invite_member:), "Invite whom? (q to quit): ", 1);
      return;
   }

   if (PARTY_D->locate_user(member))
   {
      write("Sorry, but " + capitalize(member) + " is already a member of a party.");
      return;
   }

   if (!target || !target->is_visible())
   {
      write("You can only invite someone who is online.");
      return;
   }

   if (target)
   {
      tell(target, "%^CHANNEL%^Invite received:%^RESET%^ " + this_body()->query_name() + " has invited you to the '" +
                       party_name + "' party. Type 'party accept' to accept.");
      invites += ({target});
      write(capitalize(member) + " has been invited to " + party_name +
            ". The invite only lasts as long as you stay in this menu.");
   }
}

private
void kick_member(string member)
{
   class party party = PARTY_D->query_party(party_name);
   string c = "";
   int count = 0;
   mapping members = party.members;

   // Check if member is a number > 0
   if (to_int(member))
   {
      int k = to_int(member);
      if (k > 0 && k <= sizeof(sort_array(keys(members), 1)))
      {
         string kickee = sort_array(keys(members), 1)[k - 1];
         if (user->query_name() == kickee)
         {
            write(warning("Cannot kick party lead, leave if you must."));
            return;
         }
         write("Removed " + kickee + " from " + party_name + ".");
         if (find_body(lower_case(kickee)))
            tell(find_body(lower_case(kickee)), "You have been kicked from the party.");
         PARTY_D->remove_member(kickee, party_name);
         kill_menu_for(kickee);
         return;
      }
      write(warning("Invalid entry."));
   }

   if (lower_case(member) == "q" || member == "")
   {
      write("Ok, no kicks.");
      return;
   }

   foreach (string m in sort_array(keys(members), 1))
   {
      count++;
      write("[" + count + "] " + m);
   }
   modal_simple(( : kick_member:), "[1" + (count > 1 ? "-" + count : "") + ",q]: ", 1);
}

private
varargs void enter_password(string owner, string party_name, int failures, string response)
{
   if (!response || response == "")
   {
      write("You must enter a password. And don't forget it!\n");
      if (++failures == MAX_ATTEMPTS)
      {
         write("Sorry.\n");
         destruct();
      }
      modal_simple(( : enter_password, owner, party_name, failures:), "   Enter password: ", 1);
      return;
   }

   if (PARTY_D->party_exists(party_name))
   {
      if (!PARTY_D->add_member(owner, party_name, response))
      {
         write("Incorrect password.\n");
         if (++failures == MAX_ATTEMPTS)
         {
            write("Sorry.\n");
            destruct();
         }
         modal_simple(( : enter_password, owner, party_name, failures:), "   Enter password: ", 1);
         return;
      }
      failures = 0;
      printf("Joined %s.\n", party_name);
   }
   else
   {
      modal_simple(( : confirm_password, owner, party_name, response, failures:), "\n   Confirm password: ", 1);
      return;
   }

   start_menu();
}

private
varargs void enter_party_password(string owner, string party_name, int failures, string response)
{
   write("\n"); // Since we were in secure entry
   if (failures == MAX_ATTEMPTS)
   {
      write("Sorry, you just didn't make the cut.\n");
      destruct();
   }

   if (!PARTY_D->add_member(owner, party_name, response))
   {
      write("Password is incorrect.\n");
      modal_simple(( : enter_party_password, owner, party_name, ++failures:), "Try again. Enter password: ");
   }
   else
   {
      write("Congratulations! You've been added to the party!\n");
   }
}

private
void enter_party_name(string owner, string response)
{
   response = trim(response);
   if (!response || response == "" || !regexp(response, "^[a-zA-Z 0-9]+$"))
   {
      write("Invalid name, only letters, numbers and spaces.\n");
      modal_simple(( : enter_party_name, owner:), "   Enter party name: ");
      return;
   }

   if (PARTY_D->party_exists(response))
   {
      printf("%s exists.\n", response);
      modal_simple(( : enter_party_password, owner, response, 0 :), "   Enter password: ", 1);
   }
   else
   {
      printf("Party '%s' does not exist. ", response);
      modal_simple(( : confirm_create, owner, response:), "Create it? ");
   }
}

private
void confirm_join_party(string owner, string response)
{
   response = lower_case(response);

   if (response == "n" || response == "no")
      destruct(this_object());

   if (response == "y" || response == "yes")
   {
      modal_simple(( : enter_party_name, owner:), "  Enter party name: ");
   }
}

int is_invited(object player)
{
   return member_array(player, invites) != -1 ? party_name : 0;
}

int is_party_menu()
{
   return clonep(this_object());
}

void simple_join(string party)
{
   object *party_invites = filter_array(objects(), ( : $1->is_party_menu() && $1->is_invited(this_body()) :));
   class party jparty = PARTY_D->query_party(party);
   string passwd = jparty.password;
   if (!PARTY_D->add_member(this_body()->query_name(), party, passwd))
      write("Failed to join somehow, sorry.");
   else
   {
      write("Invite accepted, you joined the " + party + " party.");
      party_invites->remove_invite(this_body());
   }
}

void remove_invite(object body)
{
   if (member_array(body, invites) != -1)
   {
      invites -= ({body});
      if (PARTY_D->locate_user(body->query_name()) == party_name)
         tell(user, body->query_name() + " decided to join your party.");
      else
         tell(user, body->query_name() + " decided to join another party.");
   }
}

void accept_invite(string party)
{
   object *party_invites = filter_array(objects(), ( : $1->is_party_menu() && $1->is_invited(this_body()) :));
   int count;

   if (stringp(party) && lower_case(party) == "q" || party == "")
   {
      write("Ok, not accepting anything right now.");
      return;
   }

   if (to_int(party))
   {
      int k = to_int(party);
      if (k >= 1 && k <= sizeof(party_invites))
         simple_join(sort_array(map(party_invites, ( : $1->is_invited(this_body()) :)), 1)[k - 1]);
      else
         write("** Invalid entry, aborting.");
      return;
   }

   switch (sizeof(party_invites))
   {
   case 2..1000:
      write("You have <bld>multiple invites<res>. Which party do you want to join?");
      foreach (string m in sort_array(map(party_invites, ( : $1->is_invited(this_body()) :)), 1))
      {
         count++;
         write("[" + count + "] " + m);
      }
      modal_simple(( : accept_invite:), "[1" + (count > 1 ? "-" + count : "") + ",q]: ", 1);

      break;
   case 1:
      simple_join(party_invites[0]->is_invited(this_body()));
      break;
   default:
      write("You're not invited to any parties currently. Create your own perhaps? Use 'party' to do so.");
      break;
   }
}

void join_party(string arg)
{
   string owner = this_body()->query_name();

   if (arg == "accept")
   {
      accept_invite(0);
      return;
   }

   if (!PARTY_D->locate_user(owner))
   {
      write("You are not a member of any party.\n");
      modal_simple(( : confirm_join_party, owner:), "Would you like to join one? ");
   }
   else
   {
      start_menu();
   }
}

void give_lead(string member)
{
   class party party = PARTY_D->query_party(party_name);
   string c = "";
   int count = 0;
   mapping members = party.members;

   // Check if member is a number > 0
   if (to_int(member))
   {
      int k = to_int(member);
      if (k > 0 && k <= sizeof(sort_array(keys(members), 1)))
      {
         string lead = sort_array(keys(members), 1)[k - 1];
         if (user->query_name() == lead)
         {
            write(warning("You are already lead?"));
            return;
         }
         write("Changed lead in " + party_name + " to " + capitalize(lead) + ".");
         PARTY_D->swap_access(lead, user->query_name(), party_name);
         remove_section_item(toplevel, party_maint);
         is_lead = 0;
         if (find_body(lower_case(lead)))
            tell(find_body(lower_case(lead)), "You have been made party lead for " + party_name + ".");
         return;
      }
      write(warning("Invalid entry."));
   }

   if (lower_case(member) == "q" || member == "")
   {
      write("Ok, no management changes.");
      return;
   }

   write(accent("Who do you want to lead instead of you?"));
   foreach (string m in sort_array(keys(members), 1))
   {
      count++;
      write("[" + count + "] " + m);
   }
   modal_simple(( : give_lead:), "[1" + (count > 1 ? "-" + count : "") + ",q]: ", 1);
}

private
void frame_init_user()
{
   class party party = PARTY_D->query_party(party_name);
   ::frame_init_user();
   TBUG(party.theme);
   if (party.theme)
      set_theme(party.theme);
}

private
void set_party_theme(string t)
{
   string *themes = keys(query_themes());
   class party party = PARTY_D->query_party(party_name);
   string c = "";
   int count = 0;

   // Check if member is a number > 0
   if (to_int(t))
   {
      int k = to_int(t);
      if (k > 0 && k <= sizeof(sort_array(themes, 1)))
      {
         string theme = sort_array(themes, 1)[k - 1];
         write("Changed theme for " + party_name + " to " + capitalize(theme) + ".");
         PARTY_D->set_theme(theme, party_name);
         return;
      }
      write(warning("Invalid entry."));
   }

   if (lower_case(t) == "q" || t == "")
   {
      write("Ok, no theme changes.");
      return;
   }

   write(accent("The current party theme is: " + PARTY_D->query_theme(party_name)));
   write(accent("Which theme would you like for the party?"));
   write("[" + count + "] " + "(No theme - users own theme)");
   foreach (string m in sort_array(themes, 1))
   {
      count++;
      write("[" + count + "] " + capitalize(m));
   }
   modal_simple(( : set_party_theme:), "[0" + (count > 1 ? "-" + count : "") + ",q]: ", 1);
}

private
void add_lead_menu()
{
   add_menu_item(party_maint, new_menu_item("Kick member", ( : kick_member:), "k"));
   add_menu_item(party_maint, new_menu_item("Invite member", ( : invite_member:), "i"));
   add_menu_item(party_maint, new_menu_item("Change password", ( : change_password:), "p"));
   add_menu_item(party_maint, new_menu_item("Give lead", ( : give_lead:), "L"));
   add_menu_item(party_maint, new_menu_item("Set party theme", ( : set_party_theme:), "t"));

   // Ensure the right order of menus.
   remove_section_item(toplevel, party_data);
   add_section_item(toplevel, party_maint);
   add_section_item(toplevel, party_data);
   is_lead = 1;
}

void display_current_menu()
{
   if (PARTY_D->query_owner(party_name) == user->query_name() && !is_lead)
   {
      add_lead_menu();
   }
   ::display_current_menu();
}

void start_menu()
{
   user = this_body();
   party_name = PARTY_D->locate_user(user->query_name());
   frame_init_user();
   toplevel = new_menu(party_name + " Party Menu");
   party_data = new_section("Party Data", "title", 1);
   party_maint = new_section("Party Admin", "warning", 2);
   party_menu = new_section("Other", "<081>", 3);
   empty = new_menu("Empty Menu");
   maint = new_menu(party_name + " Maintenance Menu");

   quit_item = new_menu_item("Quit", ( : quit_menu_application:), "q");
   add_section_item(toplevel, party_data);

   add_menu_item(party_data, new_menu_item("Members list", ( : who_current:), "m"));
   add_menu_item(party_data, new_menu_item("Active parties", ( : list_active:), "a"));
   add_menu_item(party_data, new_menu_item("Last ten kills", ( : last_ten_kills:), "l"));

   if (PARTY_D->query_owner(party_name) == user->query_name() && !is_lead)
   {
      add_lead_menu();
   }

   add_section_item(toplevel, party_menu);
   add_menu_item(party_menu, new_menu_item("QUIT party", ( : quit_party:), "x"));
   add_menu_item(party_menu, new_menu_item("Help!", ( : party_help:), "h"));
   add_menu_item(party_menu, quit_item);

   init_menu_application(toplevel);
}