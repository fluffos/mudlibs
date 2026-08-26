inherit M_LIGHTSABER_COMPONENT;

void setup(string name)
{
   if (!strlen(name))
   {
      name = "mysterious";
   }

   set_id(capitalize(name) + " crystal", lower_case(name) + " crystal", "crystal");
   set_long("This gray crystal is opaque.");
   set_component_name(lower_case(name));
   set_component_type("focusing");
   set_name_restriction(name);
   set_mass(50);
   set_value(0);
}

int is_name_crystal() { return 1; }

mapping query_damage_bonuses()
{
   int alignment = owner(this_object())->query_jedi_alignment();

   if (alignment > 0)
   {
      return ([ "vs dark side" : 1 + to_int(floor(alignment / 2.6)) ]);
   }
   else if (alignment < 0)
   {
      return ([ "energy" : 1 + to_int(floor(alignment / -5.5)) ]);
   }

   return ([ ]);
}

mapping query_attribute_bonuses()
{
   int alignment = owner(this_object())->query_jedi_alignment();

   if (alignment > 0)
   {
      return ([ "con" : 1 + to_int(floor(alignment / 5.5)), "agi" : 1 + to_int(floor(alignment / 5.5)), "int" : 1 + to_int(floor(alignment / 5.5)) ]);
   }
   else if (alignment < 0)
   {
      return ([ "str" : 1 + to_int(floor(alignment / -5.5)), "dex" : 1 + to_int(floor(alignment / -5.5)), "cha" : 1 + to_int(floor(alignment / -5.5)) ]);
   }

   return ([ ]);
}

int query_to_hit_bonus()
{
   int alignment = owner(this_object())->query_jedi_alignment();

   if (alignment > 0)
   {
      return alignment * 2;
   }

   return 0;
}

int query_stun_bonus()
{
   int alignment = owner(this_object())->query_jedi_alignment();

   if (alignment < 0)
   {
      return alignment * -2;
   }

   return 0;
}

int query_slow_bonus()
{
   int alignment = owner(this_object())->query_jedi_alignment();

   if (alignment > 0)
   {
      return alignment * 2;
   }

   return 0;
}

int query_deflection_bonus()
{
   return 0;
}

int query_parry_bonus()
{
   return 0;
}

int query_heal_bonus()
{
   return 0;
}

int query_armor_bonus()
{
   int alignment = owner(this_object())->query_jedi_alignment();

   if (alignment > 0)
   {
      return 1 + to_int(floor(alignment / 5.5));
   }

   return 0;
}

int query_critical_chance_bonus()
{
   int alignment = owner(this_object())->query_jedi_alignment();

   if (alignment < 0)
   {
      return 1 + to_int(floor(alignment / -5.5));
   }

   return 0;
}

int query_critical_multiplier_bonus()
{
   int alignment = owner(this_object())->query_jedi_alignment();

   if (alignment < 0)
   {
      return 1 + to_int(floor(alignment / -5.5));
   }

   return 0;
}

int query_alignment_restriction()
{
   int alignment = owner(this_object())->query_jedi_alignment();

   if (alignment > 0)
   {
      switch (alignment)
      {
         case 25..29: set_long("This white crystal is translucent."); return 1;
         case 30..33: set_long("This white crystal glows very faintly."); return 1;
         case 34..37: set_long("This white crystal glows dimly."); return 1;
         case 38..41: set_long("This white crystal glows moderately."); return 1;
         case 42..45: set_long("This white crystal glows brightly."); return 1;
         case 46..47: set_long("This white crystal glows brilliantly."); return 1;
         case 48..49: set_long("This white crystal glows intensely."); return 1;
         case 50: set_long("This white crystal radiates an immense ammount of light, almost blinding anyone who looks at it."); return 1;
         default: set_long("This white crystal is opaque."); return 1;
      }

      return 1;
   }
   else if (alignment < 0)
   {
      switch (alignment)
      {
         case -29..-25: set_long("This black crystal is translucent."); return -1;
         case -33..-30: set_long("This black crystal glows very faintly."); return -1;
         case -37..-34: set_long("This black crystal glows dimly."); return -1;
         case -41..-38: set_long("This black crystal glows moderately."); return -1;
         case -45..-42: set_long("This black crystal glows brightly."); return -1;
         case -47..-46: set_long("This black crystal glows brilliantly."); return -1;
         case -49..-48: set_long("This black crystal glows intensely."); return -1;
         case -50: set_long("This black crystal radiates an immense amount of light, almost blinding anyone who looks at it."); return -1;
         default: set_long("This black crystal is opaque."); return -1;
      }

      return -1;
   }

   set_long("This gray crystal is opaque.");

   return 0;
}