// Last edited by deforce on 08-08-2007
#include <hooks.h>

inherit HIDDEN_DOOR;

void setup(string name, string dir, string room, string locked, string desc)
{
   set_id("door");
   add_adj(dir);
   set_unique(1);
   set_long((desc ? desc : "It is a standard door") + " with a thumb-turn lock on this side, which requires no item to lock and unlock.");

   if (locked)
   {
      set_closed(1);
      set_locked(locked);
   }

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

varargs void do_lock(object ob)
{
   if (this_body()->query_limb_health("right hand") < 1)
   {
      if (this_body()->query_limb_health("left hand") < 1)
      {
         this_body()->my_action("$N $vtry to lock the $o, but both of $p hands are disabled.", this_object());
         this_body()->other_action("$N $vtry pathetically to lock the $o, flailing $p useless disabled hands around in a clockwise motion.", this_object());

         return;
      }
   }

   this_body()->simple_action("$N $vlock the $o, turning the knob on the lock clockwise with $p thumb.", this_object());
   set_locked(get_sibling()->query_key_type());
//   hook_state("prevent_open", my_open_hook, 1);
}

varargs void do_unlock(object ob)
{
   if (this_body()->query_limb_health("right hand") < 1)
   {
      if (this_body()->query_limb_health("left hand") < 1)
      {
         this_body()->my_action("$N $vtry to unlock the $o, but both of $p hands are disabled.", this_object());
         this_body()->other_action("$N $vtry pathetically to unlock the $o, flailing $p useless disabled hands around in a counter-clockwise motion.", this_object());

         return;
      }
   }

   this_body()->simple_action("$N $vunlock the $o, turning the knob on the lock counter-clockwise with $p thumb.", this_object());
   set_locked(0, get_sibling()->query_key_type());
//   hook_state("prevent_open", my_open_hook, 0);
}

mixed direct_lock_obj(object ob)
{
   mixed ex = call_hooks("prevent_lock", HOOK_YES_NO_ERROR);
   if (!ex) { ex = "It appears that something is preventing it from being locked.\n"; }

   if (stringp(ex))
   {
      return ex;
   }

   if (!this_object()->query_closed()) { return "You'll have to close it first."; }

   if (query_locked()) { return "It is already locked.\n"; }

   return 1;
}

mixed direct_unlock_obj(object ob)
{
   mixed ex = call_hooks("prevent_unlock", HOOK_YES_NO_ERROR);
   if (!ex) { ex = "It appears that something is preventing it from being unlocked.\n"; }

   if (stringp(ex))
   {
      return ex;
   }

   if (!this_object()->query_closed()) { return "It is already open."; }

   if (!query_locked()) { return "It is already unlocked.\n"; }

   return 1;
}

mixed direct_pick_obj(object ob) { return 0; }
mixed direct_pick_obj_with_obj() { return 0; }