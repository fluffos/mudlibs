/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ADVERSARY;

object target;

void ob_arrived(object ob)
{
   if (ob->is_weapon())
      do_wield(ob);
   if (ob->is_armour())
      ob->do_wear();
}

void setup()
{
   set_id("dummy");
   set_gender(1);
   set_adj("test");
   set_in_room_desc("A test dummy is standing here.");
   set_level(10);
   add_hook("object_arrived", ( : ob_arrived:));
}

string query_name()
{
   return "test dummy";
}

void tell_target(string s)
{
   if (target)
   {
      tell(target, "%^GREEN%^[Dummy Level " + this_object()->query_level() + "]%^RESET%^ " + s + ".\n");
   }
}

int do_damage_event(class event_info evt)
{
   if (arrayp(evt->data))
   {
      tell_target("Incoming %^YELLOW%^" + format_list(evt->data[0]) + "%^RESET%^ dmg (" + evt->data[1] + " hp) on " +
                  evt->target_extra + " limb");
   }
   return ::do_damage_event(evt);
}

class event_info armours_modify_event(class event_info evt)
{
   object *armors = event_get_armours(evt);
   int dmg;
   string dtype;

   if (arrayp(evt->data))
   {
      dtype = evt->data[0], dmg = evt->data[1];
   }

   evt = ::armours_modify_event(evt);

   if (arrayp(evt->data))
   {
      if (evt->data[1] != dmg)
         tell_target("Armor reduced %^YELLOW%^" + format_list(evt->data[0]) + "%^RESET%^ dmg on " + evt->target_extra +
                     " to by " + (dmg - evt->data[1]));
   }

   return evt;
}

void disarm(object w)
{
   tell_target("%^YELLOW%^Disarmed%^RESET%^ weapon '" + w->short() + "'");
   w->move(this_object());
   this_object()->do_wield(w);
}

varargs int hurt_us(int x, string limb)
{
   // tell_target("" + x + " HP damage on " + limb);
}

// Add a small message to stand up action.
void stand_up()
{
   ::stand_up();
   simple_action("$N $vbounce back up.");
}

// A bit of built-in stun protection.
void stun(string limb, int period)
{
   ::stun(limb, 2);
   call_out("stand_up", 3);
}

void take_a_swing(object t)
{
   // Do nothing
   target = t;
   this_object()->heal_all();
}

mixed indirect_give_obj_to_liv()
{
   return 1;
}