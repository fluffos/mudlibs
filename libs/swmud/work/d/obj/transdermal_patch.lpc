inherit OBJ;
inherit M_GETTABLE;
inherit M_WEARABLE;

int query_value();

private string type = "bacta";
private int total_healed = 0;
private int heal_capacity = 1;
private int heal_rate = 1;

void mudlib_setup()
{
   m_wearable::mudlib_setup();
   this_object()->add_save(({ "type", "total_healed", "heal_capacity", "heal_rate" }));
}

void setup(string set_type, int set_heal_capacity, int set_heal_rate)
{
   if (strlen(set_type))
   {
      type = set_type;
   }

   if (set_heal_capacity)
   {
      heal_capacity = set_heal_capacity;
   }

   if (set_heal_rate)
   {
      heal_rate = set_heal_rate;
   }

   set_id(type + " patch", "patch");
   set_long("A transdermal " + type + " patch, made by a physician from synthesized components.  It will automatically release medication when it's needed, until its reservoir is depleted.");
   set_mass(300);

   if (type == "bacta")
   {
      set_slot("healing patch");
   }
   else
   {
      set_slot(type + " patch");
   }

   set_wear_relation("on");
   set_body_size(0);
}

void heart_beat()
{
   object env = environment();

   if (!env->is_living()) { return; }

   if ((heal_capacity > total_healed) && (env->query_health() < env->query_max_health()))
   {
      int amount_healed;

      if ((heal_capacity - total_healed) < heal_rate)
      {
         heal_rate = heal_capacity - total_healed;
      }

      if (type == "bacta")
      {
         amount_healed = env->heal_us(heal_rate, "none");

//         tell(env, "Healed " + amount_healed + ".\n");
      }
      else if (type == "antidote")
      {
         object toxin = env->has_effect("poison");

         if (toxin)
         {
            int poison_strength = toxin->query_poison_strength();
            amount_healed = heal_rate;

            if (amount_healed > poison_strength)
            {
               amount_healed = poison_strength;
            }

            tell(env, "You feel better as some of the toxins are removed from your body.\n");
            toxin->add_poison_strength(amount_healed * -1);
         }
      }

      if (amount_healed > 0)
      {
         total_healed += amount_healed;
      }
   }

   if (total_healed >= heal_capacity)
   {
      set_heart_beat(0);

      tell(env, "%^BOLD%^%^RED%^" + capitalize(this_object()->the_short()) + " has been used up.%^RESET%^\n");

      set_proper_name("used " + type + " patch");
      set_id("used " + type + " patch", "used patch");
      set_long("A transdermal " + type + " patch that has been used up.");
      this_object()->do_remove();
      set_slots(({}));
   }
}

int deny_alter_value() { return 1; }

void on_wear()
{
   set_heart_beat(8);
}

void on_remove()
{
   set_heart_beat(0);
}

int query_value_pure()
{
   return query_value();
}

int query_value()
{
   if (heal_capacity > total_healed)
   {
      return (heal_capacity - total_healed) * 6;
   }

   return 0;
}