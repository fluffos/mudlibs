// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

function my_hook;
int speed_bonus;

void create(int bonus, int duration)
{
   buff::create();

   speed_bonus = bonus;

   set_buff_duration(duration);
}

int query_speed_bonus()
{
   return speed_bonus;
}

void apply_buff(object target)
{
   my_hook = (: query_speed_bonus :);
   target->add_hook("force_speed", my_hook);
   target->add_armor_bonus(speed_bonus * 2);

   target->other_action("$N $vare surrounded by a steady, white glow.\n");
   tell(target, "You feel the Force flow through you, increasing your natural speed.\n");
}

void remove_buff(object target)
{
   target->remove_hook("force_speed", my_hook);
   target->add_armor_bonus(speed_bonus * -2);

   target->other_action("The white glow around $N fades away.\n");
   tell(target, "%^BOLD%^Your speed is no longer increased by the Force.%^RESET%^\n");
}