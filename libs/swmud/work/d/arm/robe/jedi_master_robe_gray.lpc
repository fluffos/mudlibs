inherit ARMOR;
inherit ROBE_CUSTOM;
inherit HOOD;

void setup()
{
   set_id("gray Jedi Master robe", "Jedi Master robe", "master robe", "robe");
   set_long("A plain, medium-brown robe made of machine-spun wool.  It has a hood, which can be worn up or down by raising or lowering it.");

   set_slots("torso", "left arm", "right arm", "left leg", "right leg");

   set_armor_class(3);
   set_repair_skill("clothing repair");
   set_repair_guilds(({"jedi", "merchant"}));
   set_parts_type("clothing");

   set_mass(3000);
   set_value(5600);
}

int is_jedi_armor() { return 1; }

mapping query_attribute_modifiers()
{
   switch (environment()->query_guild_rank("jedi"))
   {
      case 2: return (["int" : 3, "cha" : 3]);
      case 3..1000: return (["int" : 5, "cha" : 5]);
   }

   if (environment()->query_guild_level("jedi") >= 20)
   {
      return (["int" : 1, "cha" : 1]);
   }

   return ([ ]);
}