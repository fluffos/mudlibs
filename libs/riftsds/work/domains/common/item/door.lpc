/* Do not remove the headers from this file! see /USAGE for more info. */

inherit HIDDEN_DOOR;

void on_clone(mixed args...)
{
   ::on_clone(args...);
   if (is_open())
      do_on_open();
   else
      do_on_close();
}

void setup(string dir, string room)
{
   set_id("door");
   set_adj("metal", "simple");
   set_long("It's a normal looking metal simple metal door.");
   setup_door("simple metal door", dir, room);
}
