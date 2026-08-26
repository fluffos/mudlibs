inherit "/std/effect";

int poison_strength = 1;

//:FUNCTION set_poison_strength
void set_poison_strength(int strength)
{
   poison_strength = strength;
}

int query_poison_strength()
{
   return poison_strength;
}

void add_poison_strength(int strength)
{
   poison_strength += strength;

   if (poison_strength <= 0)
   {
      destruct(this_object());
   }
}

void setup(object target, object source, object apparatus, int rank, int level)
{
   poison_strength = rank + ceil(level / 5.0) + 4;

   source->targetted_action("$N $vinject $t with $p $o.", target, apparatus);

   set_effect_duration(poison_strength);
   set_effect_delay(12);
   set_effect_type("poison damage");
   set_effect_name("poison");
}

void do_effect(object ob)
{
   if (poison_strength > 0)
   {
      int constitution;
      int damage = to_int(ceil(poison_strength / 2) + random((poison_strength / 2) + 1));

      ob->refresh_stats();

      constitution = ob->query_con();

      if (damage > constitution) { damage = constitution; }

      ob->simple_action("$N $vreel in pain from being poisoned.");
      ob->weaken_us(damage);

      if (poison_strength > (constitution / 10.0))
      {
         poison_strength -= ceil(constitution * 5.0 * poison_strength / 1000.0);
      }
      else
      {
         poison_strength = 0;
      }
   }

   if (poison_strength <= 0)
   {
      tell(ob, "You feel better as the last of the toxins are removed from your body.\n");

      destruct(this_object());
   }
}

void transfer_to_existing_effect(object new_effect)
{
   add_poison_strength(new_effect->query_poison_strength());
   add_effect_duration(new_effect->query_poison_strength());
}