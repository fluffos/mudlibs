/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** 25-Jul-96    Valentino.     Created.
** 17-Jan-23    Tsath		    Updated and framed.
** 09-Oct-24    Tsath          Rewritten to use frame columns.
*/

//: COMMAND
// syntax: ``people [flags]``
//
// Shows a list of players and associated info, with the flags determining
// which players and info are included
//
// Instead of calling the cmd with flags you can do:
//``set people_flags [flags]`` the flags that you appoint will be automatically
//  used as your default arguments when the command is called.
//
// ex:
//``set people_flags hpnI``
// or
//``people hpnI``
//
// The available flags are as follows.
//  | --------------------------------------------------------------------------
//  |  W -This flag will show wizards only. It will not print anything, it just
//  |    filters the users and removes anyone without wizard status.
//  |  P -This flag shows players only. Another filter, this command just removes
//  |    any wizards from the who list.
//  |  A -This flag shows admins (demigods or Gods) only.
//  |  D -This flag adds an informative line of info triggered by other flags, fex.
//  |    if your command supports the 'W' flag the info line would print:
//  |    'Wizards only'
//  |    -----------------------------------------~
//  |    <list of wizards>
//  |    -----------------------------------------~
//
//  |    above the list of all the wizards logged on.
//  |  h -Huge header. Lists mudname and time on a header 3 lines wide. Automatically
//  |    appended at the top of the list.
//  |  H -Small header. List mudname and time on a header 1 line wide. Automatically
//  |    appended to the top of the list.
//  |  l -level of player
//  |  n -Prints the users login name without titles.
//  |  t -Prints the users name and title.
//  |  p -Prints positions, God, Avatar, Demigod, player, ect.
//
//  |  -WIZARD ONLY FLAGS-
//  |  -------------------------------------------------------------------------
//  |  w -Prints brief description of the users enviroment.
//  |  f -Prints filename of the users environment.
//  |  a -Prints either player, wizard or admin titles only.
//  |  u -Prints username of body.
//  |  i -Prints idle times of people logged on.
//  |  I -Prints IP/hostnames of people logged on.
//  |  F -Prints an 'I' if a person is idle, and an 'E' if the person is editing.
//
// .. TAGS: RST

#include <config/user_menu.h>
#include <playerflags.h>

inherit CMD;
inherit M_FRAME;
// inherit M_WIDGETS;

#define WHO_FORMAT "%s:  (Local Time is: %s) %28s\n%s"
#define DEBUG(arg)                                                                                                     \
   if (debug && member_array(arg, msgs) == -1)                                                                         \
   msgs += ({arg})

string *msgs = ({});

string get_who_string(string arg)
{
   string content = " ";
   string header = "";
   int first_run = 1;
   int debug;
   int path_mod = 20;
   int env_mod = 25;
   object *b = bodies() - ({0});
   string bad_flags = "";
   string *args = ({});
   string tmp;

   frame_init_user();

   if (arg)
   {
      args = explode(arg, "");
   }
   else
   {
      tmp = get_user_variable("people_flags");
      if (tmp)
         args = explode(tmp, "");
      else
      {
         args = explode("anFwh", "");
      }
   }
   if (member_array("D", args) != -1)
   {
      debug = 1;
      args -= ({"D"});
   }

   if (member_array("W", args) != -1)
   {
      b = filter_array(b, ( : wizardp($1) :));
      args -= ({"W"});
      DEBUG("Wizards only");
   }
   else if (member_array("A", args) != -1)
   {
      b = filter_array(b, ( : adminp($1) :));
      args -= ({"A"});
      DEBUG("Admins only");
   }
   else if (member_array("P", args) != -1)
   {
      b = filter_array(b, ( : !wizardp($1) :));
      args -= ({"P"});
      DEBUG("Players only");
   }
   if (!wizardp(this_user()))
   {
      b = filter_array(b, ( : $1->query_body()->is_visible() :));
   }

   if (member_array("h", args) != -1)
   {
      string footer = "";
      args -= ({"h"});
      DEBUG("Header");
      if (sizeof(b) == 1)
         footer += "There is only 1 user connected ";
      else
         footer += "There are " + sizeof(b) + " users connected ";
      footer += "at " + ctime(time()) + "" + "\n";
      set_frame_footer(footer);
   }
   else if (member_array("H", args) != -1)
   {
      args -= ({"H"});
      DEBUG("Small Header");
      content += sprintf("%s:  (Local Time is: %s)\n", mud_name(), ctime(time()));
   }
   if (strlen(bad_flags))
      content += warning("Bad flags: " + bad_flags);

   foreach (string arg2 in args)
   {
      switch (arg2)
      {
      case "n":
         frame_add_column("Name", b->query_name());
         break;
      case "w":
         if (wizardp(this_user()))
            frame_add_column("Environment", map(b, (
                                                       : environment($1) ? environment($1)->get_brief() : "(Nowhere)"
                                                       :)));
         break;
      case "f":
         if (wizardp(this_user()))
            frame_add_column("Path", map(b, (
                                                : environment($1) ? filename_ellipsis((environment($1)), 40) : "(lost?)"
                                                :)));
         break;
      case "t":
         frame_add_column("Title", b->query_formatted_desc(78));
         break;
      case "p":
         frame_add_column("Position", map(b, ( : $1->query_wiz_position() ? $1->query_wiz_position() : "(None)" :)));
         break;
      case "u":
#ifdef USE_USER_MENU
         frame_add_column(
             "User",
             map(b, (
                        : $1->query_link()->query_userid() ? capitalize($1->query_link()->query_userid()) : "(None?)"
                        :)));
#endif
         break;
      case "a":
         if (!wizardp(this_user()))
            break;
         frame_add_column("Privilege", map(b, ( : wizardp($1) ? (adminp($1) ? "Admin" : "Wizard") : "Player" :)));
         break;
      case "i":
         if (!wizardp(this_user()))
            break;
         frame_add_column("Idle",
                          map(b, (
                                     : query_idle($1->query_link()) ? convert_time(query_idle($1->query_link()), 2) : ""
                                     :)));
         break;
      case "I":
         if (!wizardp(this_user()))
            break;
         frame_add_column("IP", map(b, ( : query_ip_name($1->query_link()) :)));
         break;
      case "l":
         if (!wizardp(this_user()))
            break;
         frame_add_column("Level", map(b, ( : "" + $1->query_level() :)));
         break;
      case "F":
         if (!wizardp(this_user()))
            break;
         frame_add_column(
             "Flags",
             map(b, (
                        : query_idle($1->query_link()) > 60 ? "I" : " " + ($1 && $1->test_flag(F_IN_EDIT) ? "E" : " ")
                        :)));
         break;
      default:
         if (arg2)
            bad_flags += arg2;
      }
   }
   set_frame_title(implode(explode(mud_name(), ""), " "));
   if (strlen(bad_flags))
      set_frame_footer("Bad flags for people: " + bad_flags);

   return frame_render_columns();
}

private
void main(string arg)
{
   string outtie;
   if (arg == "")
      arg = 0;
   msgs = 0;
   msgs = ({});
   outtie = get_who_string(arg);
   if (sizeof(msgs))
      outf(implode(msgs, ", ") + ".\n");
   out(outtie);
}

void player_menu_entry()
{
   bare_init();
   main(0);
   done_outputing();
}
