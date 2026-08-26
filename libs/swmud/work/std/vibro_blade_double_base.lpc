inherit VIBRO_BLADE_BASE;

void mudlib_setup()
{
   vibro_blade_base::mudlib_setup();
   set("two_hands", 1);
   set_weapon_speed(2);
   set_to_hit_base(-25);
}

class event_info process_vibro_blade_double_evt(class event_info evt)
{
   return evt;
}

class event_info source_modify_event(class event_info evt)
{
   evt = vibro_blade_base::source_modify_event(evt);

   if (stringp(evt->data) || (event_damage(evt) < 1)) { return evt; }

   evt = process_vibro_blade_double_evt(evt);

   return evt;
}