inherit RACE;

string race_name = "tatooinian";
string human_race_sacrifice = "str";
string human_race_bonus = "con";
int body_size = 3;
int human_race_modifier = 0;
int human_race_str_min = 40;
int human_race_str_max = 90;
int human_race_con_min = 40;
int human_race_con_max = 90;
int human_race_agi_min = 35;
int human_race_agi_max = 90;
int human_race_dex_min = 40;
int human_race_dex_max = 90;
int human_race_per_min = 35;
int human_race_per_max = 90;
int human_race_int_min = 35;
int human_race_int_max = 90;
int human_race_cha_min = 5;
int human_race_cha_max = 80;
int human_race_luc_min = 35;
int human_race_luc_max = 90;
int human_race_for_min = 35;
int human_race_for_max = 90;

// This is the name of the race, used in the initial selection screen, finger info, etc.
string query_race()
{
   return race_name;
}

// This is the body size of the race, from 1 to 5
int query_body_size()
{
   return body_size;
}

void set_body_size(int value)
{
   if (value) { body_size = value; }
}

// This is the help description
string short_description()
{
   return "The bleak and rough lifestyle of Tatooine creates hardened and tough individuals.  Humans from Tatooine receive bonuses to their strength, dexterity, and constitution, but they are not the most charming people to meet.\n";
}

string query_human_race_sacrifice_attribute() { return human_race_sacrifice; }
string query_human_race_bonus_attribute() { return human_race_bonus; }

void set_human_race_sacrifice_attribute(string atr) { human_race_sacrifice = atr; }
void set_human_race_bonus_attribute(string atr) { human_race_bonus = atr; }

int query_human_race_modifier() { return human_race_modifier; }

void set_human_race_modifier(int modifier) { human_race_modifier = modifier; }

int is_human() { return 1; }

int query_race_str_min()
{
   return human_race_str_min
      + (human_race_sacrifice == "str" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "str" ? human_race_modifier * 5 : 0);
}

int query_race_str_max()
{
   return human_race_str_max
      + (human_race_sacrifice == "str" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "str" ? human_race_modifier * 5 : 0);
}

int query_race_con_min()
{
   return human_race_con_min
      + (human_race_sacrifice == "con" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "con" ? human_race_modifier * 5 : 0);
}

int query_race_con_max()
{
   return human_race_con_max
      + (human_race_sacrifice == "con" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "con" ? human_race_modifier * 5 : 0);
}

int query_race_agi_min()
{
   return human_race_agi_min
      + (human_race_sacrifice == "agi" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "agi" ? human_race_modifier * 5 : 0);
}

int query_race_agi_max()
{
   return human_race_agi_max
      + (human_race_sacrifice == "agi" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "agi" ? human_race_modifier * 5 : 0);
}

int query_race_dex_min()
{
   return human_race_dex_min
      + (human_race_sacrifice == "dex" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "dex" ? human_race_modifier * 5 : 0);
}

int query_race_dex_max()
{
   return human_race_dex_max
      + (human_race_sacrifice == "dex" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "dex" ? human_race_modifier * 5 : 0);
}

int query_race_per_min()
{
   return human_race_per_min
      + (human_race_sacrifice == "per" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "per" ? human_race_modifier * 5 : 0);
}

int query_race_per_max()
{
   return human_race_per_max
      + (human_race_sacrifice == "per" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "per" ? human_race_modifier * 5 : 0);
}

int query_race_int_min()
{
   return human_race_int_min
      + (human_race_sacrifice == "int" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "int" ? human_race_modifier * 5 : 0);
}

int query_race_int_max()
{
   return human_race_int_max
      + (human_race_sacrifice == "int" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "int" ? human_race_modifier * 5 : 0);
}

int query_race_cha_min()
{
   return human_race_cha_min
      + (human_race_sacrifice == "cha" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "cha" ? human_race_modifier * 5 : 0);
}

int query_race_cha_max()
{
   return human_race_cha_max
      + (human_race_sacrifice == "cha" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "cha" ? human_race_modifier * 5 : 0);
}

int query_race_luc_min()
{
   return human_race_luc_min
      + (human_race_sacrifice == "luc" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "luc" ? human_race_modifier * 5 : 0);
}

int query_race_luc_max()
{
   return human_race_luc_max
      + (human_race_sacrifice == "luc" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "luc" ? human_race_modifier * 5 : 0);
}

int query_race_for_min()
{
   return human_race_for_min
      + (human_race_sacrifice == "for" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "for" ? human_race_modifier * 5 : 0);
}

int query_race_for_max()
{
   return human_race_for_max
      + (human_race_sacrifice == "for" ? human_race_modifier * -5 : 0)
      + (human_race_bonus == "for" ? human_race_modifier * 5 : 0);
}

int query_original_str_min() { return human_race_str_min; }
int query_original_str_max() { return human_race_str_max; }
int query_original_con_min() { return human_race_con_min; }
int query_original_con_max() { return human_race_con_max; }
int query_original_agi_min() { return human_race_agi_min; }
int query_original_agi_max() { return human_race_agi_max; }
int query_original_dex_min() { return human_race_dex_min; }
int query_original_dex_max() { return human_race_dex_max; }
int query_original_per_min() { return human_race_per_min; }
int query_original_per_max() { return human_race_per_max; }
int query_original_int_min() { return human_race_int_min; }
int query_original_int_max() { return human_race_int_max; }
int query_original_cha_min() { return human_race_cha_min; }
int query_original_cha_max() { return human_race_cha_max; }
int query_original_luc_min() { return human_race_luc_min; }
int query_original_luc_max() { return human_race_luc_max; }
int query_original_for_min() { return human_race_for_min; }
int query_original_for_max() { return human_race_for_max; }