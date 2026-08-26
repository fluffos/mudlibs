// Last edited by deforce on 07-12-2008
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

string get_stat_full_name(string stat);

function my_hook;
string stat_name;
int stat_bonus;

void create(string stat, int bonus, int duration)
{
   buff::create();

   stat_name = stat;
   stat_bonus = bonus;

   set_buff_duration(duration);
}

int query_stat_bonus()
{
   return stat_bonus;
}

void apply_buff(object target)
{
   my_hook = (: query_stat_bonus :);
   target->add_hook(stat_name + "_bonus", my_hook);
   target->refresh_stats();

   target->other_action("$N $vare surrounded by a steady, yellow glow.\n");
   tell(target, "You feel your " + get_stat_full_name(stat_name) + " become greater.\n");
}

void remove_buff(object target)
{
   target->remove_hook(stat_name + "_bonus", my_hook);
   target->refresh_stats();

   target->other_action("The yellow glow around $N fades away.\n");
   tell(target, "%^BOLD%^Your " + get_stat_full_name(stat_name) + " is no longer enhanced.%^RESET%^\n");
}

string get_stat_full_name(string stat)
{
   switch(lower_case(stat))
   {
      case "strength":
      case "str":
         return "strength";
      case "constitution":
      case "con":
         return "constitution";
      case "agility":
      case "agi":
         return "agility";
      case "dexterity":
      case "dex":
         return "dexterity";
      case "perception":
      case "per":
         return "perception";
      case "intelligence":
      case "int":
         return "intelligence";
      case "charisma":
      case "cha":
         return "charisma";
      case "luck":
      case "luc":
         return "luck";
      case "force":
      case "for":
         return "Force";
   }

   return "";
}