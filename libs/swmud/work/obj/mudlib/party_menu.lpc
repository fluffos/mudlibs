/* Do not remove the headers from this file! see /USAGE for more info. */

// party_menu.c - Menu object accessible through the 'party' command
//                for all players. Includes all party-related
//                functions.
// March 1, 1997: Iizuka@Lima Bean created.
// August 15, 1999: Iizuka@Lima Bean ripped creation process out of the
//                  party player command and moved it here.

#define MAX_ATTEMPTS 3

#include <menu.h>
#include <mudlib.h>

inherit MENUS;

private
varargs void enter_password(string owner, string party_name, int failures, string response);

MENU toplevel;
MENU maint;

MENU_ITEM quit_item;
MENU_ITEM main_seperator;
MENU_ITEM help_item;
private
string party_name;

void who_current()
{
   string s;
   string *members = PARTY_D->query_party_members(party_name);

   s = sprintf("%%^BOLD%%^%%^WHITE%%^Members of %s%%^RESET%%^%%^MAGENTA%%^:%%^RESET%%^\n", party_name);

   printf("%s%%^BOLD%%^%%^BLUE%%^%s\n", s, repeat_string("-", sizeof(s)));
   foreach (string str in members)
   {
      printf("%s\n", str);
   }
   printf("%%^BOLD%%^%%^BLUE%%^%s\n\n", repeat_string("-", sizeof(s)));
}

void party_maint()
{
   return;
}

void party_help()
{
   return;
}

void last_ten_kills()
{
   return;
}

void who_offline()
{
   return;
}

void list_active()
{
   string *active = PARTY_D->list_all_parties();
   string line = sprintf("%%^BOLD%%^%%^BLUE%%^%s%%^RESET%%^", repeat_string("-", 20));

   printf("%%^BOLD%%^%%^WHITE%%^Parties on %s%%^RESET%%^\n", mud_name());
   printf("%s\n  %s\n%s\n\n", line, implode(active, "\n  "), line);
}

void quit_party()
{
   printf("Removing you from %s.. %%^RED%%^done.%%^RESET%%^\n\n", party_name);
   if (sizeof(PARTY_D->query_party_members(party_name)) == 1)
      PARTY_D->remove_party(party_name);
   else
      PARTY_D->remove_member(this_body()->query_name(), party_name);
   quit_menu_application();
}

void start_menu()
{
   party_name = PARTY_D->locate_user(this_body()->query_name());
   toplevel = new_menu(party_name + " party Menu");
   maint = new_menu(party_name + " Maintenance Menu");

   quit_item = new_menu_item("Quit", ( : quit_menu_application:), "q");
   main_seperator = new_seperator(repeat_string("-", 34));

   add_menu_item(toplevel, main_seperator);
   add_menu_item(toplevel, new_menu_item("Who is in " + party_name + "?", ( : who_current:), "w"));

   add_menu_item(toplevel, new_menu_item("List all active parties.", ( : list_active:), "a"));

   add_menu_item(toplevel, new_menu_item("List last ten kills. (Disabled)", ( : last_ten_kills:), "k"));

   add_menu_item(toplevel, new_menu_item("List offline party memebers.", ( : who_offline:), "o"));

   if (PARTY_D->query_owner(party_name) == this_body()->query_name())
      add_menu_item(toplevel, new_menu_item("Party maintenance", ( : party_maint:), "m"));

   add_menu_item(toplevel, new_menu_item("QUIT " + party_name + " permanently.", ( : quit_party:), "X"));

   add_menu_item(toplevel, main_seperator);

   add_menu_item(toplevel, new_menu_item("Help!", ( : party_help:), "h"));

   add_menu_item(toplevel, quit_item);

   init_menu_application(toplevel);
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
   if (!response || response == "" || !regexp(response, "^[a-zA-Z]+$"))
   {
      write("Invalid name.\n");
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

void join_party()
{
   string owner = this_body()->query_name();

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
