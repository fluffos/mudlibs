inherit HIDDEN_DOOR;

varargs void setup(string name, string dir, string room, string locked, string desc)
{
   set_id("door");
   add_adj(dir);
   set_unique(1);
   set_long((desc ? desc : "It is a standard door") + " with no lock on this side.");

   if (locked)
   {
      set_closed(1);
      set_locked(locked);
   }

   set_attached(1);

   setup_door(name, dir, room);
}

void do_on_open()
{
   ::do_on_open();
   environment(this_object())->set_room_state("open");
}

void do_on_close()
{
   ::do_on_close();
   environment(this_object())->clear_room_state("open");
}

void on_clone(mixed args...)
{
   ::on_clone(args...);
   if (is_open()) { do_on_open(); }
   else { do_on_close(); }
}

mixed direct_unlock_obj(object ob) { return 0; }
mixed direct_lock_obj(object ob) { return 0; }
mixed direct_pick_obj(object ob) { return 0; }
mixed direct_pick_obj_with_obj() { return 0; }