// Last edited by deforce on 05-07-2010
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

void create(int duration)
{
   buff::create();

   set_buff_duration(duration);
}

void apply_buff(object target)
{
   tell(target, "%^BOLD%^You have been stunned through the Force.%^RESET%^\n");
}

void remove_buff(object target)
{
   tell(target, "%^BOLD%^You are no longer stunned through the Force.%^RESET%^\n");
}