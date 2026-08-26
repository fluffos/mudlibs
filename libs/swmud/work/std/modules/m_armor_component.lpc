inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUABLE;

string name = "";
string component_type = "";
mapping attribute_bonuses = ([ ]);
mapping resistance_bonuses = ([ ]);
mapping weakness_bonuses = ([ ]);
mapping skill_bonuses = ([ ]);
int to_hit_bonus = 0;
int heal_bonus = 0;
int armor_bonus = 0;
int body_armor_bonus = 0;

void mudlib_setup()
{
   m_valuable::mudlib_setup();

   set_id("armor_component");

   add_save(({ "name", "component_type", "attribute_bonuses", "resistance_bonuses", "weakness_bonuses", "skill_bonuses", "to_hit_bonus", "heal_bonus", "armor_bonus", "body_armor_bonus" }));
}

int is_armor_component() { return 1; }

void set_component_name(string component_name)
{
   name = component_name;
}

string query_component_name() { return name; }

void set_component_type(string type)
{
   component_type = type;
}

string query_component_type() { return "armor " + component_type; }

void set_attribute_bonuses(mapping values)
{
   attribute_bonuses = values;
}

mapping query_attribute_bonuses()
{
   return attribute_bonuses;
}

void set_resistance_bonuses(mapping values)
{
   resistance_bonuses = values;
}

mapping query_resistance_bonuses()
{
   return resistance_bonuses;
}

void set_weakness_bonuses(mapping values)
{
   weakness_bonuses = values;
}

mapping query_weakness_bonuses()
{
   return weakness_bonuses;
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

void set_body_armor_bonus(int value)
{
   body_armor_bonus = value;
}

int query_body_armor_bonus()
{
   return body_armor_bonus;
}