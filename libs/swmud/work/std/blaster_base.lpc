inherit AMMO_WEAPON;
inherit RANGED_BASE;

string chamber_name = "chamber_1";
string pcell_name = "pcell_1";
string scope_name = "scope_1";

void mudlib_setup()
{
   ammo_weapon::mudlib_setup();
   ranged_base::mudlib_setup();
   add_id("blaster");
   set_combat_messages("combat-blaster");
   set_skill_used("pistol combat");
   set_repair_skill("blaster repair");
   set_repair_learn_requirement("blaster repair");
   set_repair_guilds(({"engineer", "mercenary", "smuggler", "bounty hunter"}));
   set_parts_type("blaster");
   add_save(({ "chamber_name", "pcell_name", "scope_name" }));

   // Give time for saved inventory to be loaded first, or to add a specific color at creation
   call_out("check_if_blaster_has_components", 5);
}

void check_if_blaster_has_components()
{
   if (this_object())
   {
      if (strlen(chamber_name)
         && !sizeof(filter_array(all_inventory(this_object()), (: $1->id("blaster_chamber") :))))
      {
         new("/d/com/blaster/" + chamber_name)->move(this_object());
      }

      if (strlen(pcell_name)
         && !sizeof(filter_array(all_inventory(this_object()), (: $1->id("blaster_pcell") :))))
      {
         new("/d/com/blaster/" + pcell_name)->move(this_object());
      }

      if (strlen(scope_name)
         && !sizeof(filter_array(all_inventory(this_object()), (: $1->id("blaster_scope") :))))
      {
         new("/d/com/blaster/" + scope_name)->move(this_object());
      }

      this_object()->assemble();
   }
}

int is_blaster() { return 1; }

void set_blaster_chamber(string chamber)
{
   chamber_name = chamber;
}

string query_blaster_chamber()
{
   return chamber_name;
}

void set_blaster_pcell(string pcell)
{
   pcell_name = pcell;
}

string query_blaster_pcell()
{
   return pcell_name;
}

void set_blaster_scope(string scope)
{
   scope_name = scope;
}

string query_blaster_scope()
{
   return scope_name;
}

int valid_wield()
{
   if (this_object()->can_use_blaster_chamber() && !strlen(chamber_name))
   {
      tell(owner(this_object()), "You are unable to wield your " + this_object()->short() + " while it has no blaster chamber.\n");

      return 0;
   }
   else if (this_object()->can_use_blaster_power_cell() && !strlen(pcell_name))
   {
      tell(owner(this_object()), "You are unable to wield your " + this_object()->short() + " while it has no blaster power cell.\n");

      return 0;
   }

   return 1;
}

class event_info source_modify_event(class event_info evt)
{
   return evt;
}