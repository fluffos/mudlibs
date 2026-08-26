inherit HOLSTER;

void setup()
{
   set_id("lightsaber belt", "saber belt", "belt");
   set_long("A simple, brown leather belt with attachments for a standard lightsaber on both sides.");
   set_holster_relation("attached");
   set_mass(400);
   set_slot("waist");
   set_wear_relation("around");
}

int indirect_attach_obj_to_obj() { return 1; }
int indirect_detach_obj_from_obj() { return 1; }

int can_attach(object attachment)
{
   if (attachment->is_lightsaber() && !attachment->query("two_hands")
      && (sizeof(all_inventory(this_object())) < 2))
   {
      return 1;
   }

   return 0;
}

mixed receive_object(object target, string relation)
{
   if (target->is_lightsaber() && !target->query("two_hands")
      && (sizeof(all_inventory(this_object())) < 2))
   {
      return 1;
   }

   return target->short() + " cannot be attached to a lightsaber belt.\n";
}