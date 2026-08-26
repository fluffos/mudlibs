inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUABLE;

string name = "";
string component_type = "";
mapping damage_bonuses = ([ ]);
mapping attribute_bonuses = ([ ]);
mapping skill_bonuses = ([ ]);
int to_hit_bonus = 0;
int stun_bonus = 0;
int slow_bonus = 0;
int deflection_bonus = 0;
int parry_bonus = 0;
int heal_bonus = 0;
int armor_bonus = 0;
int critical_chance_bonus = 0;
int critical_multiplier_bonus = 0;
int alignment_restriction = 0;
string name_restriction = "";

void mudlib_setup()
{
   m_valuable::mudlib_setup();

   set_id("lightsaber_component");

   add_save(({ "name", "component_type", "damage_bonuses", "attribute_bonuses", "skill_bonuses", "to_hit_bonus", "stun_bonus", "slow_bonus", "deflection_bonus", "parry_bonus", "heal_bonus", "armor_bonus", "critical_chance_bonus", "critical_multiplier_bonus", "alignment_restriction", "name_restriction" }));
}

int is_lightsaber_component() { return 1; }

void set_component_name(string component_name)
{
   name = component_name;
}

string query_component_name() { return name; }

void set_component_type(string type)
{
   component_type = type;
}

string query_component_type() { return "lightsaber " + component_type; }

void set_damage_bonuses(mapping values)
{
   damage_bonuses = values;
}

mapping query_damage_bonuses()
{
   return damage_bonuses;
}

void set_attribute_bonuses(mapping values)
{
   attribute_bonuses = values;
}

mapping query_attribute_bonuses()
{
   return attribute_bonuses;
}

void set_skill_bonuses(mapping values)
{
   skill_bonuses = values;
}

mapping query_skill_bonuses()
{
   return skill_bonuses;
}

void set_to_hit_bonus(int value)
{
   to_hit_bonus = value;
}

int query_to_hit_bonus()
{
   return to_hit_bonus;
}

void set_stun_bonus(int value)
{
   stun_bonus = value;
}

int query_stun_bonus()
{
   return stun_bonus;
}

void set_slow_bonus(int value)
{
   slow_bonus = value;
}

int query_slow_bonus()
{
   return slow_bonus;
}

void set_deflection_bonus(int value)
{
   deflection_bonus = value;
}

int query_deflection_bonus()
{
   return deflection_bonus;
}

void set_parry_bonus(int value)
{
   parry_bonus = value;
}

int query_parry_bonus()
{
   return parry_bonus;
}

void set_heal_bonus(int value)
{
   heal_bonus = value;
}

int query_heal_bonus()
{
   return heal_bonus;
}

void set_armor_bonus(int value)
{
   armor_bonus = value;
}

int query_armor_bonus()
{
   return armor_bonus;
}

void set_critical_chance_bonus(int value)
{
   critical_chance_bonus = value;
}

int query_critical_chance_bonus()
{
   return critical_chance_bonus;
}

void set_critical_multiplier_bonus(int value)
{
   critical_multiplier_bonus = value;
}

int query_critical_multiplier_bonus()
{
   return critical_multiplier_bonus;
}

void set_alignment_restriction(int value)
{
   alignment_restriction = value;
}

int query_alignment_restriction()
{
   return alignment_restriction;
}

void set_name_restriction(string value)
{
   name_restriction = value;
}

string query_name_restriction()
{
   return name_restriction;
}