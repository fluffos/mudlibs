// Last edited by deforce on 10-05-2009
// Must be cloned with new() instead of it using the master object, for multiple hooks to work correctly
inherit "/std/buff";

void create(int duration)
{
   buff::create();

   set_buff_duration(duration);
}

void apply_buff(object target)
{
   tell(target, "You will now move around silently.\n");
}

void remove_buff(object target)
{
   tell(target, "%^BOLD%^Your movement is no longer silent.%^RESET%^\n");
}