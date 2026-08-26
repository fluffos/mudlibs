// Last edited by deforce on 10-05-2008
inherit "/std/buff";

function my_hook;
int reduction;

void create(int amount, int duration)
{
   buff::create();

   reduction = amount;

   set_buff_duration(duration);
}

int query_reduction()
{
   return reduction;
}

void apply_buff(object target)
{
   my_hook = (: query_reduction :);
   target->add_hook("force_shield", my_hook);

   target->simple_action("$N $vsurround $r with a shield of the Force.\n");
}

void remove_buff(object target)
{
   target->remove_hook("force_shield", my_hook);

   target->other_action("The Force shield surrounding $N dissipates.\n");
   tell(target, "%^BOLD%^Your Force shield dissipates.%^RESET%^\n");
}