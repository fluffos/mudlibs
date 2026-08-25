/* Do not remove the headers from this file! see /USAGE for more info. */

/*
**	Player menu by John Viega (rust@virginia.edu) 5-Jul-95
**	For the Lima mudlib.
**
**	Still want to have:
**	o channel menu
**     o more reporter commands
**	o what's new or something like that.
**	o take args at line, ie, b yes for biff or somesuch
**     o disable newbie options
*/

#include <combat_config.h>
#include <commands.h>
#include <menu.h>
#include <mudlib.h>
#include <playerflags.h>

// ### for now
#include <security.h>

inherit MENUS;
// ### for now
inherit M_ACCESS;

MENU toplevel;
// submenus of the toplevel (main) menu
MENU soulmenu;
MENU ccmenu;

MENU reportmenu;
MENU remotemenu;
MENU personalmenu;
MENU uxmenu;
// submenus of personalmenu
MENU biffmenu;
MENU snoopablemenu;

MENU_ITEM quit_item;
MENU_ITEM goto_main_menu_item;
MENU_ITEM main_seperator;

void toggle_cc(int flag, string state);

// right now, we're just going to call the help command.
// private MENU helpmenu;

private
mapping dispatch = (["n":"news", "w":"who", "b":"bug", "t":"typo", "i":"idea", "?":"help", "l":"mudlist", ]);

private
nomask void simple_cmd(string cmd)
{
   call_other(CMD_DIR_PLAYER "/" + dispatch[cmd], "player_menu_entry");
}

void start_mail()
{
   this_user()->query_mailer()->begin_mail();
}

void handle_finger(string person)
{
   ZBUG(person);
   CMD_OB_FINGER->player_menu_entry(person);
   prompt_then_return();
}

void test_soul(string s)
{
   CMD_OB_SEMOTE->player_menu_entry(s);
   prompt_then_return();
}

void find_soul(string s)
{
   if (!s || s == "")
   {
      write("Invalid.\n");
      return;
   }

   CMD_OB_EMOTEAPROPOS->player_menu_entry(s);
}

void show_souls(string s)
{
   CMD_OB_FEELINGS->player_menu_entry(s);
}

void show_adverbs(string s)
{
   write("Remember: You can get any of these adverbs by typing part of the adverb \n"
         "then *, if the part you type is unique.  Eg, kick rust ene* would give you:\n"
         "kick rust energetically, but kick rust en* won't because it also\n"
         "matches endearingly and enthusiastically.\n");

   CMD_OB_ADVERBS->player_menu_entry(s);
}

void change_email(string s)
{
   this_user()->set_email(s);
   write("Email info changed.\n");
}

void change_url(string s)
{
   this_user()->set_url(s);
   write("Home page address changed.\n");
}

void change_real_name(string s)
{
   this_user()->set_real_name(s);
   write("Real name changed.\n");
}

void change_title(string s)
{

   if (strsrch(s, "$N") == -1)
      s = "$N " + s;
   this_body()->set_title(s);

   write("Title changed.\n");
}

void query_personal_info()
{
   printf("Your title is: %s\n"
          "Your provided e-mail address is: %s\n"
          "Your provided WWW home page is: %s\n"
          "You %sget notified when new mail arrives.\n"
          "Wizards %s snoop you.\n",
          this_body()->query_title(), this_user()->query_email(), this_user()->query_url(),
          this_body()->test_flag(F_BIFF) ? "" : "DON'T ", this_body()->test_flag(F_SNOOPABLE) ? "CAN" : "can't");

   prompt_then_return();
}

void prompt_change_title()
{
   input_one_arg("Change title to what? ", ( : change_title:));
}

void prompt_change_email()
{
   input_one_arg("Change e-mail to what? ", ( : change_email:));
}

void prompt_change_real_name()
{
   input_one_arg("Change real name to what? ", ( : change_real_name:));
}

void prompt_change_url()
{
   input_one_arg("Change your WWW homepage address to what? ", ( : change_url:));
}

void set_mode(string s)
{
   CMD_OB_MODE->player_menu_entry(s);
}

void prompt_change_mode()
{
   input_one_arg("Set mode 'plain', 'vt100', 'ansi' or 'xterm': ", ( : set_mode:));
}

void set_simplify(string s)
{
   CMD_OB_SIMPLIFY->player_menu_entry(s);
}

void prompt_change_simplify()
{
   input_one_arg("Set simplify to reduce fancy UI for screenreaders.\n" + " 'on' or 'off': ", ( : set_simplify:));
}

void set_emoji(string s)
{
   CMD_OB_EMOJI->player_menu_entry(s);
}

void prompt_change_emoji()
{
   input_one_arg("Set emoji replacements. Requires unicode in your client.\n" + " 'on', 'off' or 'list': ",
                 (
                     : set_emoji:));
}

void set_frames(string s)
{
   CMD_OB_FRAMES->player_menu_entry(s);
}

void prompt_change_frames()
{
   input_one_arg("Set frame style, colour theme. Requires unicode for fancier ones.\n\t" +
                     "'styles' to see other style options.\n\t" + "'style <style>' to see other options.\n\t" +
                     "'themes' to list the colour themes.\n\t" + "'theme <theme>' to select a colour theme.\n",
                 (
                     : set_frames:));
}

void set_metric(string s)
{
   CMD_OB_METRIC->player_menu_entry(s);
}

void prompt_change_metric()
{
   input_one_arg("Use the metric system? (on/off)\n", ( : set_metric:));
}

void set_width(string s)
{
   CMD_OB_WIDTH->player_menu_entry(s);
}

void prompt_change_width()
{
   input_one_arg("Set to a number or 'auto' for automatic detection? \n", ( : set_width:));
}

void set_biff(string s)
{
   if (s == "y")
      s = "on";
   else
      s = "off";

   CMD_OB_BIFF->player_menu_entry(s);
   goto_previous_menu();
}

void set_snoopable(string s)
{
   if (s == "y")
      s = "on";
   else
      s = "off";

   CMD_OB_SNOOPABLE->player_menu_entry(s);
   goto_previous_menu();
}

void finish_who(string mudname)
{
   CMD_OB_FINGER->player_menu_entry("@" + mudname);
   printf("%s queried.  It's up to that mud to reply to you.\n", mudname);
   prompt_then_return();
}

void remote_who()
{
   write("Which mud do you want to query?\n");
   complete_choice(0, IMUD_D->query_mudnames(), ( : finish_who:));
}
void update_ccmenu()
{
   // Add items to the combat config menu
   this_body()->update_combat_config();
   set_menu_items(
       ccmenu,
       ({main_seperator,
         new_menu_item(
             "Hide missed swings in combat      [" +
                 (this_body()->combat_config(CC_HIDE_MISSES) ? "%^GREEN%^ON%^RESET%^" : "%^RED%^OFF%^RESET%^") + "]",
             (
                 : get_input_then_call,
                   (
                       : toggle_cc, CC_HIDE_MISSES:),
                   "Toggle on "
                   "(y/n): "
                 :),
             "s"),
         new_menu_item(
             "Hide attacks without damage       [" +
                 (this_body()->combat_config(CC_HIDE_NO_DAMAGE) ? "%^GREEN%^ON%^RESET%^" : "%^RED%^OFF%^RESET%^") + "]",
             (
                 : get_input_then_call,
                   (
                       : toggle_cc, CC_HIDE_NO_DAMAGE:),
                   "Toggle on "
                   "(y/n): "
                 :),
             "n"),
         new_menu_item(
             "Hide low damage attacks           [" +
                 (this_body()->combat_config(CC_HIDE_LOW_DAMAGE) ? "%^GREEN%^ON%^RESET%^" : "%^RED%^OFF%^RESET%^") +
                 "]",
             (
                 : get_input_then_call,
                   (
                       : toggle_cc, CC_HIDE_LOW_DAMAGE:),
                   "Toggle on "
                   "(y/n): "
                 :),
             "l"),
         new_menu_item(
             "Hide disabled limb messages       [" +
                 (this_body()->combat_config(CC_HIDE_DISABLE_LIMB) ? "%^GREEN%^ON%^RESET%^" : "%^RED%^OFF%^RESET%^") +
                 "]",
             (
                 : get_input_then_call,
                   (
                       : toggle_cc, CC_HIDE_DISABLE_LIMB:),
                   "Toggle on "
                   "(y/n): "
                 :),
             "d"),
         new_menu_item(
             "Hide non-vital stuns              [" +
                 (this_body()->combat_config(CC_HIDE_SIMPLE_STUNS) ? "%^GREEN%^ON%^RESET%^" : "%^RED%^OFF%^RESET%^") +
                 "]",
             (
                 : get_input_then_call,
                   (
                       : toggle_cc, CC_HIDE_SIMPLE_STUNS:),
                   "Toggle on "
                   "(y/n): "
                 :),
             "S"),
         new_menu_item(
             "Hide dodges                       [" +
                 (this_body()->combat_config(CC_HIDE_DODGES) ? "%^GREEN%^ON%^RESET%^" : "%^RED%^OFF%^RESET%^") + "]",
             (
                 : get_input_then_call,
                   (
                       : toggle_cc, CC_HIDE_DODGES:),
                   "Toggle on "
                   "(y/n): "
                 :),
             "D"),
         goto_main_menu_item, quit_item}));
}

void toggle_cc(int flag, string state)
{
   object shell = this_user()->query_shell_ob();
   string *cconfig;
   if (state != "y" && state != "n")
   {
      write("y or n only.\n");
      return;
   }

   TBUG("What: " + flag + " state: " + state);
   if (get_user_variable("cconfig") == 0)
      shell->set_variable("cconfig", CC_SIZE);

   cconfig = explode(get_user_variable("cconfig"), "");

   // If variable was extended, pad it with 'n's.
   if (sizeof(cconfig) < strlen(CC_SIZE))
      cconfig = explode(sprintf("%-" + sizeof(CC_SIZE) + "'n's", implode(cconfig, "")), "");

   if (flag < sizeof(CC_SIZE))
      cconfig[flag] = state;

   shell->set_variable("cconfig", implode(cconfig, ""));
   update_ccmenu();
}

void create()
{
   set_privilege(1);

   toplevel = new_menu(mud_name() + " Game Menu");
   ccmenu = new_menu("Combat Config");
   soulmenu = new_menu("Soul Menu");
   reportmenu = new_menu("Reporter Menu");
   personalmenu = new_menu("Personal Menu");
   uxmenu = new_menu("User Interface Menu");
   biffmenu = new_menu("Notify you when you receive new mail?");
   snoopablemenu = new_menu("Allow wizards to snoop you?");
   remotemenu = new_menu("Other muds");

   // Since we'll use these things more than once, we can just
   // call new_menu_item once, and insert them wherever we want
   // to use them.
   quit_item = new_menu_item("Quit", ( : quit_menu_application:), "q");
   goto_main_menu_item = new_menu_item("Return to main menu", toplevel, "m");

   main_seperator = new_seperator("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

   // Add items to the toplevel (main) menu.
   add_menu_item(toplevel, main_seperator);
   add_menu_item(toplevel, new_menu_item("Read news (news)", ( : simple_cmd:), "n"));
   add_menu_item(toplevel, new_menu_item("Combat configuration", ccmenu, "c"));
   add_menu_item(toplevel, new_menu_item("Send or read mail (mail)", ( : start_mail:), "m"));
   add_menu_item(toplevel, new_menu_item("See who's on (who)", ( : simple_cmd:), "w"));
   add_menu_item(toplevel, new_menu_item("Get info about a person (finger)",
                                         (
                                             : get_input_then_call,
                                               (
                                                   : handle_finger:),
                                               "Finger who? "
                                             :),
                                         "f"));
   add_menu_item(toplevel, new_menu_item("Soul/emote Menu", soulmenu, "s"));
   add_menu_item(toplevel, new_menu_item("Report a bug, typo or idea", reportmenu, "r"));
   add_menu_item(toplevel, new_menu_item("User Interface, colours, emojis, frames.", uxmenu, "i"));
   add_menu_item(toplevel, new_menu_item("Change or view your personal information. ", personalmenu, "p"));
   add_menu_item(toplevel, new_menu_item("Information on other muds", remotemenu, "o"));
   add_menu_item(toplevel, quit_item);
   add_menu_item(toplevel, new_menu_item("Help", ( : simple_cmd:), "?"));

   update_ccmenu();
   // Add items to the soul menu.
   add_menu_item(soulmenu, main_seperator);
   add_menu_item(soulmenu, new_menu_item("List souls",
                                         (
                                             : get_input_then_call,
                                               (
                                                   : show_souls:),
                                               "List all souls starting with "
                                               "(enter for ALL souls): "
                                             :),
                                         "s"));
   add_menu_item(soulmenu, new_menu_item("List adverbs",
                                         (
                                             : get_input_then_call,
                                               (
                                                   : show_adverbs:),
                                               "List all adverbs starting with "
                                               "(enter for ALL adverbs): "
                                             :),
                                         "a"));
   add_menu_item(soulmenu, new_menu_item("Find souls",
                                         (
                                             : get_input_then_call,
                                               (
                                                   : find_soul:),
                                               "Find souls whose output "
                                               "contains string: "
                                             :),
                                         "f"));

   add_menu_item(soulmenu, new_menu_item("Test a soul",
                                         (
                                             : get_input_then_call,
                                               (
                                                   : test_soul:),
                                               "Soul to test: "
                                             :),
                                         "t"));

   add_menu_item(soulmenu, quit_item);

   add_menu_item(soulmenu, goto_main_menu_item);

   add_menu_item(reportmenu, main_seperator);
   add_menu_item(reportmenu, new_menu_item("Report a bug", ( : simple_cmd:), "b"));
   add_menu_item(reportmenu, new_menu_item("Report a typo", ( : simple_cmd:), "t"));
   add_menu_item(reportmenu, new_menu_item("Report an idea", ( : simple_cmd:), "i"));
   add_menu_item(reportmenu, quit_item);
   add_menu_item(reportmenu, goto_main_menu_item);

   add_menu_item(personalmenu, main_seperator);
   add_menu_item(personalmenu, new_menu_item("View your personal information", ( : query_personal_info:), "v"));
   add_menu_item(personalmenu, new_menu_item("Change your title", ( : prompt_change_title:), "t"));
   add_menu_item(personalmenu, new_menu_item("Change your supplied "
                                             "e-mail address",
                                             (
                                                 : prompt_change_email:),
                                             "e"));
   add_menu_item(personalmenu, new_menu_item("Change your supplied WWW home "
                                             "page address",
                                             (
                                                 : prompt_change_url:),
                                             "w"));
   add_menu_item(personalmenu, new_menu_item("Set or unset mail notification", biffmenu, "n"));
   add_menu_item(personalmenu, new_menu_item("Set whether or not you can be "
                                             "snooped",
                                             snoopablemenu, "s"));
   add_menu_item(personalmenu, new_menu_item("Change your supplied real name", ( : prompt_change_real_name:), "r"));
   add_menu_item(uxmenu, new_menu_item("Set terminal mode", ( : prompt_change_mode:), "t"));
   add_menu_item(uxmenu, new_menu_item("Simpler UI for screen readers", ( : prompt_change_simplify:), "s"));
   add_menu_item(uxmenu, new_menu_item("Emoji replacements", ( : prompt_change_emoji:), "e"));
   add_menu_item(uxmenu, new_menu_item("Terminal width", ( : prompt_change_width:), "w"));
   add_menu_item(uxmenu, new_menu_item("Metric vs Imperial", ( : prompt_change_metric:), "i"));
   add_menu_item(uxmenu, new_menu_item("Frame themes", ( : prompt_change_frames:), "f"));
   add_menu_item(uxmenu, goto_main_menu_item);
   add_menu_item(personalmenu, quit_item);
   add_menu_item(personalmenu, goto_main_menu_item);

   add_menu_item(biffmenu, main_seperator);
   add_menu_item(biffmenu, new_menu_item("Yes", ( : set_biff:), "y"));
   add_menu_item(biffmenu, new_menu_item("No", ( : set_biff:), "n"));
   add_menu_item(biffmenu, quit_item);
   add_menu_item(biffmenu, goto_main_menu_item);

   add_menu_item(snoopablemenu, main_seperator);
   add_menu_item(snoopablemenu, new_menu_item("Yes", ( : set_snoopable:), "y"));
   add_menu_item(snoopablemenu, new_menu_item("No", ( : set_snoopable:), "n"));
   add_menu_item(snoopablemenu, quit_item);
   add_menu_item(snoopablemenu, goto_main_menu_item);

   add_menu_item(remotemenu, main_seperator);
   add_menu_item(remotemenu, new_menu_item("List muds " + mud_name() + " knows about", ( : simple_cmd:), "l"));
   add_menu_item(remotemenu, new_menu_item("See who's on another mud", ( : remote_who:), "w"));
   add_menu_item(remotemenu, quit_item);
   add_menu_item(remotemenu, goto_main_menu_item);
}

void start_menu()
{
   init_menu_application(toplevel);
}
