inherit OBJ;

void setup()
{
   set_id("Powertap", "powertap", "ptap");
   set_long("You can use this powertap to 'recharge' energy cells on weapons and other devices.");
}

mixed indirect_recharge_obj_with_obj() { return 1; }

int can_recharge(object thing)
{
   if (thing->is_blaster() && thing->requires_ammo())
   {
      return 1;
   }

   return 0;
}

void on_recharge(object thing)
{
   thing->set_ammo(thing->query_max_ammo());
   thing->set_last_recharge_time(time());
}