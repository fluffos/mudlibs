/* Do not remove the headers from this file! see /USAGE for more info. */

#include <config/guild.h>

inherit CONTAINER;
inherit M_GETTABLE;

int level = 1;
string *guild_modules = ({});

void module_received();
void artefact_moved();

void setup()
{
   set_id(GUILD_ARTEFACT, "guild_artefact_ob");
   add_adj("L" + level);
   set_long("A simple " + GUILD_ARTEFACT +
            ". It looks like it is working and usable. "
            "This simple L1 model comes with one module built in, and " +
            level + " slot for expansion modules.");
   add_relation("in");
   set_default_relation("in");
   set_max_capacity(10);
   set_mass(0.1);
   add_hook("object_arrived", ( : module_received:));
   add_hook("move", ( : artefact_moved:));
   set_value(120);
}

string *query_guilds()
{
   if (!sizeof(guild_modules) && sizeof(all_inventory()))
   {
      foreach (object m in all_inventory())
      {
         guild_modules += ({m->query_module_name()});
      }
      guild_modules -= ({0});
   }

   return guild_modules;
}

string get_extra_long()
{
   string el = "The following modules are installed:\n";
   object *modules = all_inventory();
   if (!sizeof(modules))
      return "";
   foreach (object m in modules)
   {
      el += "\t" + m->query_module_name() + "\n";
   }
   return el;
}

int inventory_visible()
{
   return 0;
}

void module_received()
{
   this_body()->simple_action("$N $vinsert a " + GUILD_ARTEFACT_PLUGIN + " into a small hatch on $p " + GUILD_ARTEFACT +
                              ". It disappears with a snap.");
}

void owner_killed(object ob)
{
   TBUG("Mob killed: " + ob);
}

void artefact_moved()
{
   TBUG("Environment: " + environment());
   if (environment() && environment()->is_body())
      environment()->add_hook("i_killed", ( : owner_killed:));
   else
      environment()->remove_hook("i_killed", ( : owner_killed:));
}

string add_article(string s)
{
   return "an " + s;
}

mixed direct_use_obj()
{
   return 1;
}

void do_use()
{
   object artefact_menu = new (ARTEFACT_MENU, level);
   object *modules = all_inventory();
   if (sizeof(modules))
      artefact_menu->init_guild_modules(modules);
   artefact_menu->start_menu();
}

mixed indirect_put_obj_wrd_obj(object ob1, string wrd, object ob2)
{
   if (ob1 && ob1->is_artefact_module())
   {
      object *modules = all_inventory();
      if (!ob1->query_module_name())
      {
         return "#The module is not programmed, so inserting it now would be a waste.";
      }
      if (sizeof(modules) < level)
         return 1;
   }
   return "#That doesn't seem to fit into the " + GUILD_ARTEFACT + ".";
}

// Can be put into things.
mixed indirect_get_obj_from_obj(object ob1, string wrd, object ob2)
{
   return "#Things inserted into the " + GUILD_ARTEFACT + " seems to be permanently installed.";
}