/*
**	Guild artefact menu by Tsath 2020
**
*/

#include <combat_config.h>
#include <commands.h>
#include <config/guild.h>
#include <mudlib.h>
#include <playerflags.h>
// ### for now
#include <security.h>

inherit MENUS;
// ### for now
inherit M_ACCESS;

class menu toplevel;
// submenus of the toplevel (main) menu
class menu soulmenu;
class menu ccmenu;
class menu reportmenu;
class menu remotemenu;
class menu personalmenu;
// submenus of personalmenu
class menu biffmenu;
class menu snoopablemenu;

class menu_item quit_item;
class menu_item goto_main_menu_item;

class section main;
class section other;
class section guild;

void toggle_cc(int flag, string state);

// right now, we're just going to call the help command.
// private class menu helpmenu;

private
mapping dispatch = (["o":"Options", "?":"help", ]);

void start_player_menu()
{
   new (PLAYER_MENU)->start_menu();
}

class menu build_guild_menu(string guild)
{
   class menu m;
   m = new_menu(sprintf("%-30s", capitalize(guild) + " Sub Module") + "");
   return m;
}

void start_mission(int tier, string name, string guild, mapping mats, string reply)
{
   if (lower_case(trim(reply)) == "y")
   {
      write("Starting mission.\n");
      foreach (string mat, int cnt in mats)
      {
         GUILD_D->remove_material(guild, mat, cnt);
      }
      GUILD_D->run_mission(tier, name, guild);
   }
   else
   {
      write("Aborted.\n");
   }
}

void start_favour(int tier, string name, int cost, string guild, string reply)
{
   if (lower_case(trim(reply)) == "y")
   {
      if (GUILD_D->query_favour_score(guild) >= cost)
      {
         write("Purchasing favour.\n");

         if (GUILD_D->spend_favour(guild, cost))
            GUILD_D->start_favour(tier, name, guild);
         else
            write("Aborted, suddenly not enough favour.\n");
      }
      else
         write("Aborted, suddenly not enough favour.\n");
   }
   else
   {
      write("Aborted.\n");
   }
}

mixed pretty_materials(string guild, string mats)
{
   string out = "";
   mapping guild_mats = GUILD_D->query_materials(guild);
   mapping used_mats = ([]);
   string *pairs = explode(mats, ",");
   int gotall = 1;
   foreach (string mat in pairs)
   {
      string *req = explode(mat, ":");
      string material = req[0];
      int count = to_int(req[1]);
      used_mats[material] = count;

      if (CRAFTING_D->valid_material(material))
      {
         if (guild_mats[material] >= count)
            out += " %^GREEN%^+%^RESET%^ " + count + "/" + guild_mats[material] + " " + material + " available.\n";
         else
         {
            out += " %^RED%^-%^RESET%^ " + count + "/" + guild_mats[material] + " " + material + " not available.\n";
            gotall = 0;
         }
      }
   }
   return ({gotall, out, used_mats});
}

void guild_mission(string guild, int tier, string name)
{
   mapping mish_info = GUILD_D->query_mission(tier, name);
   mixed materials = pretty_materials(guild, mish_info["materials"]);
   string *mgmt = GOVERNANCE_D->query_managers(guild) + ({GOVERNANCE_D->query_leader(guild)});

   write("[MISSION INFO]\n" + replace_string(mish_info["description"], "<guild>", capitalize(guild)) + "\n\n");
   write("[MISSION COST]\n" + materials[1] + "\n\n");

   if (materials[0] && member_array(lower_case(this_body()->query_name()), mgmt) != -1)
   {
      modal_simple(( : start_mission, tier, name, guild, materials[2] :), "Start the mission? (y/N) ", 1);
   }
}

void guild_favour(string guild, int tier, string name)
{
   mapping favour_info = GUILD_D->query_favour(tier, name);
   string *mgmt = GOVERNANCE_D->query_managers(guild) + ({GOVERNANCE_D->query_leader(guild)});
   int favour = to_int(favour_info["favour"]);
   write("[FAVOUR INFO]   " + replace_string(favour_info["description"], "<guild>", capitalize(guild)) + "\n");
   write("[FAVOUR COST]   " + favour + "\n");
   write("[FAVOUR LENGTH] " + time_to_string(to_int(favour_info["length"]) * 60) + "\n\n");

   if (member_array(lower_case(this_body()->query_name()), mgmt) != -1)
   {
      if (GUILD_D->query_favour_score(guild) >= favour)
         modal_simple((
                          : start_favour, tier, name, favour, guild:),
                      "Buy this favour for " + favour + " favour? (y/N) ", 1);
      else
      {
         write("\n" + capitalize(guild) + " does not have enough favour to purchase this yet.\n\n");
      }
   }
}

class menu build_guild_mission_menu(string guild, class menu_item gmi)
{
   class menu m;
   class section s = new_section("Missions", "accent");
   class section o = new_section("Other", "warning");
   int count = 1;
   int guild_tier = GUILD_D->query_guild_tier(guild) || 1;
   mapping missions = GUILD_D->query_missions(guild_tier);
   m = new_menu(sprintf("%-30s", capitalize(guild) + " Missions"));
   add_section_item(m, s);
   add_section_item(m, o);
   foreach (string name, mapping data in missions)
   {
      class menu_item mi = new_menu_item(sprintf("%-30s", name) + " Favour gain: " + data["favour"],
                                         (
                                             : guild_mission, guild, guild_tier, name:),
                                         count + "");
      add_menu_item(s, mi);
      count++;
   }
   add_menu_item(o, gmi);
   return m;
}

class menu build_guild_favour_menu(string guild, class menu_item gmi)
{
   class menu m;
   int count = 1;
   class section s = new_section("Favour", "accent");
   class section o = new_section("Other", "warning");
   int guild_tier = GUILD_D->query_guild_tier(guild) || 1;
   mapping favours = GUILD_D->query_favours(guild_tier);
   m = new_menu(capitalize(guild) + " Favour");
   add_section_item(m, s);
   add_section_item(m, o);

   foreach (string name, mapping data in favours)
   {
      class menu_item mi = new_menu_item(name + " Favour Cost: " + data["favour"],
                                         (
                                             : guild_favour, guild, guild_tier, name:),
                                         count + "");
      add_menu_item(s, mi);
      count++;
   }
   add_menu_item(o, gmi);
   add_menu_item(o, quit_item);
   return m;
}

void init_guild_modules(object *modules)
{
   guild = new_section("Guild", "accent");
   if (!sizeof(modules))
      return;
   foreach (object module in modules)
   {
      string guild = module->query_module_name();
      class menu gm = build_guild_menu(guild);
      class section gms = new_section("Guild Menu", "accent");
      class menu_item guild_menu_item = new_menu_item("Return to guild menu", gm, "m");
      class menu g_mish = build_guild_mission_menu(guild, guild_menu_item);
      class menu g_favour = build_guild_favour_menu(guild, guild_menu_item);
      class menu_item mi =
          new_menu_item(capitalize(guild) + " " + GUILD_ARTEFACT_PLUGIN + " ", gm, module->query_letter());
      class menu_item mish_item = new_menu_item("Missions", g_mish, "s");
      class menu_item favour_item = new_menu_item("Favour", g_favour, "f");
      class menu_item goto_guild_menu_item = new_menu_item("Return to " + guild + " menu", gm, "m");

      add_menu_item(main, mi);
      add_section_item(gm, gms);
      add_menu_item(gms, mish_item);
      add_menu_item(gms, favour_item);
      add_menu_item(gms, goto_main_menu_item);
      add_menu_item(gms, quit_item);
   }
}

void create(int level)
{
   set_privilege(1);

   toplevel = new_menu(GUILD_ARTEFACT + "-- Version L" + level);
   main = new_section("Main", "accent");
   other = new_section("Other", "warning");
   add_section_item(toplevel, main);
   add_section_item(toplevel, other);

   // Since we'll use these things more than once, we can just
   // call new_menu_item once, and insert them wherever we want
   // to use them.
   quit_item = new_menu_item("Quit", ( : quit_menu_application:), "q");
   goto_main_menu_item = new_menu_item("Return to main menu", toplevel, "m");

   // Add items to the toplevel (main) menu.
   add_menu_item(other, new_menu_item("MUD Options", ( : start_player_menu:), "o"));
   add_menu_item(other, quit_item);
}

void start_menu()
{
   frame_init_user();
   init_menu_application(toplevel);
}
