/* Do not remove the headers from this file! see /USAGE for more info. */

inherit COMBAT_SPELL;

string fireball_potency = "spark";

void setup()
{
   set_level(3);
   set_name("fireball");
   set_category("evocation");
   set_damage_type("fire");
   extra_reflex_cost(3);
   set_cast_time(5);
   set_description("This spell creates a ball of fire that flies at the target or everyone in the room.");
}

int calculate_damage()
{
   int dmg = random(70) + 50;

   switch (dmg)
   {
   case 0..10:
      fireball_potency = "tiny";
      break;
   case 11..20:
      fireball_potency = "";
      break;
   case 21..30:
      fireball_potency = "large";
      break;
   case 31..50:
      fireball_potency = "huge";
      break;
   default:
      fireball_potency = "extremely huge";
      break;
   }

   return dmg;
}

string short()
{
   return add_article(fireball_potency + " " + query_name());
}

void cast_spell(object ob, object reagent, int success)
{
   object *targets;

   if (!ob)
   {
      targets = filter(all_inventory(environment(this_body())), ( : $1 != this_body() && $1->is_living() :));
      this_body()->simple_action("$N $vcast a fireball spell!");
   }
   else
   {
      targets = ({ob});
      this_body()->targetted_action("$N $vcast a fireball spell at $t1!", ob);
   }

   foreach (object item in targets)
   {
      /* okay... we won't have the fireball hit the caster... :-) */
      if (item && item == this_body())
         continue;

      // reduce hit points here
      do_spell_damage(this_body(), item, ( : calculate_damage:));
   }
}

mixed valid_target(object ob)
{
   /* a fireball can always be cast... */
   return 1;
}

mixed valid_reagent(object ob)
{
   return !ob || "That wouldn't help the spell any.\n";
}
