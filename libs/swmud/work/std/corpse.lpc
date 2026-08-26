inherit CONTAINER;
inherit M_DECAY;
inherit M_MESSAGES;

string inspect_corpse(object inspector);
void set_inspected_by(string name, int value);
void set_inspection_failure();

string the_name;
string killed_by;
string killed_with;
object link;
int failed_inspection = 0;
mapping inspection_log = ([ ]);
int death_time = 0;

int is_living()
{
   return 0;
}

string in_room_desc()
{
   return query_in_room_desc();
}

mixed ob_state()
{
   return the_name;
}

object query_link()
{
   return link;
}

string query_killer()
{
   return killed_by;
}

string query_killer_weapon()
{
   return killed_with;
}

void mudlib_setup(string name, string long, object l, string killer, string killer_weapon)
{
   ::mudlib_setup();

   link = l;

   if (!name) { return; }

   the_name = name;
   killed_by = killer;
   killed_with = killer_weapon;
   death_time = time();
   set_long(long || "This is the dead body of " + capitalize(the_name) + ".");

   set_id("corpse", "body");

   if (the_name[<1] == 's')
   {
      set_adj("lifeless", the_name);
      set_proper_name(capitalize(the_name) + "' body");
   }
   else
   {
      set_adj("lifeless", the_name + "s");
      set_proper_name(capitalize(the_name) + "'s body");
   }

   set_in_room_desc("corpse of " + capitalize(the_name));
   set_plural_in_room_desc("corpses of " + capitalize(the_name) + ".");
   add_relation("on");
   set_default_relation("on");
   set_max_capacity(300);
   set_mass(59000);
   set_num_decays(1);
   set_last_decay_action("The corpse of " + the_name + " $vdecay into dust and ash.\n");
   set_decay_time(3600);
   set_decay_auto_remove(1);
}

string introduce_contents()
{
   if (sizeof(all_inventory()))
   {
      return "On " + the_short() + " you see:\n";
   }

   return "";
}

mixed indirect_get_obj_from_obj(object ob1, object ob2) { return 1; }
mixed indirect_put_obj_wrd_obj(object ob1, object ob2) { return 1; }

int is_corpse() { return 1; }
int has_inspection_failure() { return failed_inspection; }
int has_been_inspected_by(string name) { return inspection_log[name]; }
int query_death_time() { return death_time; }

int query_hide_contents()
{
   return 1;
}

string inspect_corpse(object inspector)
{
   object this_body = this_body();
   string text = "";

   if (killed_by == inspector->query_name())
   {
      text += "You killed them with ";

      if (killed_with == "bare hands")
      {
         text += "your bare hands";
      }
      else
      {
         text += add_article(killed_with);
      }

      text += " " + convert_time(time() - death_time) + " ago.\n";
   }
   else if (inspection_log[inspector->query_name()] || inspector->test_skill("inspect corpse", inspector->query_guild_level("bounty hunter") * 12))
   {
      set_inspected_by(inspector->query_name(), 1);

      text += "It looks like they were killed " + convert_time(time() - death_time) + " ago.\n";

      if ((inspection_log[inspector->query_name()] > 1) || inspector->test_skill("inspect corpse", inspector->query_guild_level("bounty hunter") * 8))
      {
         set_inspected_by(inspector->query_name(), 2);

         if (killed_with == "bare hands")
         {
            text += "It looks like the killer used their bare hands.\n";
         }
         else
         {
            text += "It looks like they were killed with " + add_article(killed_with) + ".\n";
         }

         if ((inspection_log[inspector->query_name()] > 2) || inspector->test_skill("inspect corpse", inspector->query_guild_level("bounty hunter") * 4))
         {
            set_inspected_by(inspector->query_name(), 3);

            text += "This murder looks like the work of " +  killed_by + ".\n";
         }
         else
         {
            text += "This murder doesn't seem to match anyone's modus operandi.\n";
         }
      }
   }
   else if (random(inspector->query_skill("inspect corpse")) < (110 - inspector->query_per()))
   {
      set_inspection_failure();

      text += "You gain nothing from inspection, and the evidence is ruined.\n";
   }
   else
   {
      text += "Upon inspection, you discover nothing related to the murder.\n";
   }

   return text;
}

void set_inspection_failure()
{
   failed_inspection = 1;
}

void set_inspected_by(string name, int value)
{
   inspection_log[name] = value;
}

void remove()
{
   foreach (object thing in all_inventory(this_object()))
   {
      thing->move(environment(this_object()));
   }

   destruct();
}