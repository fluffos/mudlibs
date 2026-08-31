inherit SPELL;
inherit COMBAT_SPELL;

void setup()
{
   set_spell_name("magic arrow");
   set_combat_messages("combat-torch");
   set_damage_type("force");
}

int calculate_damage()
{
   return random(8) + 1;
}

void cast_spell(object ob, object reagent)
{
   object *targets;

   if (!ob)
   {
      targets = filter(all_inventory(environment(this_body())), ( : $1 != this_body() && $1->is_living() :));
      this_body()->simple_action("$N $vcast a magic arrow!");
   }
   else
   {
      targets = ({ob});
      this_body()->targetted_action("$N $vcast a magic arrow at $t1.", ob);
   }

   foreach (object item in targets)
   {
      if (item && item == this_body())
         continue;

      do_spell_damage(item, ( : calculate_damage:));
   }
}