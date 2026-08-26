inherit "/std/effect";

int tear_strength = 1;

//:FUNCTION set_poison_strength
void set_tear_strength(int strength)
{
   tear_strength = strength;
}

int query_tear_strength()
{
   return tear_strength;
}

void add_tear_strength(int strength)
{
   tear_strength += strength;

   if (tear_strength < 0)
   {
      tear_strength = 0;
   }
}

varargs void setup(int strength)
{
   if (strength) { tear_strength = strength; }

   set_effect_duration(tear_strength);
   set_effect_delay(10);
   set_effect_type("tear damage");
   set_effect_name("tear");
}

void do_effect(object ob)
{
   if (tear_strength > 0)
   {
      int str;
      int con;
      int heal_rate;

      ob->refresh_stats();

      str = ob->query_str();
      con = ob->query_con();
      heal_rate = ob->query_heal_rate();

      ob->simple_action("$N $vbleed from $p deep wounds.");

      ob->weaken_us((tear_strength / 2) + random(tear_strength / 2) + 2 - heal_rate);

      if (tear_strength > ((str / 10.0) + (con / 10.0) + heal_rate))
      {
         tear_strength -= ceil((str + con) * (4.0 + (heal_rate * 0.2)) * tear_strength / 1000.0);
      }
      else
      {
         tear_strength = 0;
      }
   }

   if (tear_strength <= 0)
   {
      tell(ob, "You feel better as your deep wounds stop bleeding.\n");

      destruct(this_object());
   }
}

void transfer_to_existing_effect(object new_effect)
{
   add_tear_strength(new_effect->query_tear_strength());
   add_effect_duration(new_effect->query_tear_strength());
}