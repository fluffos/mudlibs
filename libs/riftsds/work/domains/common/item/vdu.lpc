inherit CONTAINER;
inherit M_GETTABLE;
inherit M_WEARABLE;

int level = 1;
string *guild_modules = ({});

void module_received();
void vdu_moved();

void setup()
{
   set_id("VDU", "vdu", "guild_vdu_ob");
   add_adj("L" + level);
   set_long("A write worn Visual Display Unit (VDU) that can be extended by slotting in a number of modules. This " +
            "model seems to have " + level +
            " slot for expansion modules. It can be worn on your wrist. Modules introduces seems to be permanently a " +
            "part of the VDU.");
   add_relation("in");
   set_wearmsg("$N $vstrap a $o to $p wrist.");
   set_slot("wrist");
   set_default_relation("in");
   set_max_capacity(10);
   set_mass(0.1);
   add_hook("object_arrived", ( : module_received:));
   add_hook("move", ( : vdu_moved:));
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
   this_body()->simple_action("$N $vinsert a module into a small hatch on $p VDU. It disappears with a snap.");
}

void owner_killed(object ob)
{
   TBUG("Mob killed: " + ob);
}

void vdu_moved()
{
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

int is_vdu()
{
   return 1;
}

void do_use()
{
   object vdu_menu = new (VDU_MENU, level);
   object *modules = all_inventory();
   if (sizeof(modules))
      vdu_menu->init_guild_modules(modules);
   vdu_menu->start_menu();
}

mixed indirect_put_obj_wrd_obj(object ob1, string wrd, object ob2)
{
   if (ob1 && ob1->is_vdu_module())
   {
      object *modules = all_inventory();
      if (!ob1->query_module_name())
      {
         return "#The module is not programmed, so inserting it now would be a waste.";
      }
      if (sizeof(modules) < level)
         return 1;
   }
   return "#That doesn't seem to fit into the VDU.";
}

// Can be put into things.
mixed indirect_get_obj_from_obj(object ob1, string wrd, object ob2)
{
   return "#Things inserted into the VDU seems to be permanently installed.";
}