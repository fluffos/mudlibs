/* source file -- AD&D, 2nd Edition Ability Scores -- Game Effects */
  
  /* strength effects */
protected int str_index() {
  int str;

  str = this_player()->query_str();
  if (str > -51 && str < 0)
    return 25;
  if (str > -76 && str < -50)
    return 26;
  if (str > -91 && str < -75)
    return 27;
  if (str > -100 && str < -90)
    return 28;
  if (str == -100)
    return 29;
  return (str - 1); /* str > 0 && str < 26 */
}

int to_hit_prob() {
  return ( ({ -5,-3,-3,-2,-2,-1,-1,0,0,0,0,0,0,0,0,0,1,1,3,3,4,4,5,6,
    7,1,2,2,2,3 }) [str_index()] );
}

int damage_adj() {
  return ( ({ -4,-2,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,1,1,2,7,8,9,10,11,12,
    14,3,3,4,5,6 }) [str_index()] );
}

int wgt_allow() {
  return ( ({ 1,1,5,10,10,20,20,35,35,40,40,45,45,55,55,70,85,110,485,
    535,635,785,935,1235,1535,135,160,185,235,335 })
    [str_index()] );
}

int max_press() {
  return ( ({ 3,5,10,25,25,55,55,90,90,115,115,140,140,170,170,195,
    220,255,640,700,810,970,1130,1440,1750,280,305,330,380,480 })
    [str_index()] );
}

int open_normal_doors() {
  return ( ({ 1,1,2,3,3,4,4,5,5,6,6,7,7,8,8,9,10,11,16,17,17,18,18,
    19,19,12,13,14,15,16 }) [str_index()] );
}

int open_special_doors() {
  return ( ({ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,10,12,14,16,17,18,
    0,0,0,3,6 }) [str_index()] );
}

int bnd_brs_lft_gts() {
  return ( ({ 0,0,0,0,0,0,0,1,1,2,2,4,4,7,7,10,13,16,50,60,70,80,90,
    95,99,20,25,30,35,40 }) [str_index()] );
}

  /* dexterity effects */
int surprise_adj() {
  return ( ({ -6,-4,-3,-2,-1,0,0,0,0,0,0,0,0,0,0,1,2,2,3,3,4,4,4,5,5 })
    [(int)this_player()->query_dex() - 1] );
}

int missle_att_adj() { return (surprise_adj()); }

int defensive_adj() {
  return ( ({ 5,5,4,3,2,1,0,0,0,0,0,0,0,0,-1,-2,-3,-4,-4,-4,-5,
    -5,-5,-6,-6 }) [(int)this_player()->query_dex() - 1] );
}

  /* constitution effects */
int hit_point_adj(int warrior) {
  int con;

  con = (int)this_player()->query_con();
  if (!warrior && con > 16)
    return 2;
  return ( ({ -3,-2,-2,-1,-1,-1,0,0,0,0,0,0,0,0,1,2,3,4,5,5,6,6,6,7,7 })
    [con - 1] );
}

int system_shock() {
  return ( ({ 25,30,35,40,45,50,55,60,65,70,75,80,85,88,90,95,97,
    99,99,99,99,99,99,99,100 }) [(int)this_player()->query_con() - 1] );
}

int resurrect_survival() {
  return ( ({ 30,35,40,45,50,55,60,65,70,75,80,85,90,92,94,96,98,
    100,100,100,100,100,100,100,100 }) [(int)this_player()->query_con() - 1] );
}

int poison_save()
{
  switch (this_player()->query_con())
  {
    case 1: return -2;
    case 2: return -1;
    case 19: case 20: return 1;
    case 21: case 22: return 2;
    case 23: case 24: return 3;
    case 25: return 4;
    default: return 0;
  }
}

int regeneration()
{
  int con;

  con = this_player()->query_con();
  if (con > 19 && con < 26)
    return (26 - con);
  return 0;
}

  /* intelligence effects */
int num_languages() {
  return ( ({ 0,1,1,1,1,1,1,1,2,2,2,3,3,4,4,5,6,7,8,9,10,11,12,15,20 })
    [(int)this_player()->query_int() - 1] );
}

int spell_level() {
  return ( ({ 0,0,0,0,0,0,0,0,4,5,5,6,6,7,7,8,8,9,9,9,9,9,9,9,9 })
    [(int)this_player()->query_int() - 1] );
}

int learn_spell() {
  return ( ({ 0,0,0,0,0,0,0,0,35,40,45,50,55,60,65,70,75,85,95,
    96,97,98,99,100,100 }) [(int)this_player()->query_int() - 1] );
}

int max_spells() { /* returns -1 for All Spells */
  return ( ({ 0,0,0,0,0,0,0,0,6,7,7,7,9,9,11,11,14,18,
    -1,-1,-1,-1,-1,-1,-1 }) [(int)this_player()->query_int() - 1] );
}

int illusion_immunity() {
  int intl;

  intl = this_player()->query_int();
  if (intl > 18)
    return (intl - 18);
  return 0;
}

  /* wisdom effects */
int magical_defense_adj() {
  return ( ({ -6,-4,-3,-2,-1,-1,-1,0,0,0,0,0,0,0,1,2,3,4,4,4,4,
    4,4,4,4 }) [(int)this_player()->query_wis() - 1] );
}

int spell_fail() {
  return ( ({ 80,60,50,45,40,35,30,25,20,15,10,5,0,0,0,0,0,0,0,0,
    0,0,0,0,0 }) [(int)this_player()->query_wis() - 1] );
}

void bonus_spells(int *spellTbl)
{ /* spellTbl is an array of 7 integers; spellTbl[0] is 1st level */
  switch (this_player()->query_wis())
  {
    case 25: spellTbl[6]++, spellTbl[5]++;
    case 24: spellTbl[5]++, spellTbl[5]++;
    case 23: spellTbl[4]++, spellTbl[4]++;
    case 22: spellTbl[3]++, spellTbl[4]++;
    case 21: spellTbl[2]++, spellTbl[4]++;
    case 20: spellTbl[1]++, spellTbl[3]++;
    case 19: spellTbl[0]++, spellTbl[3]++;
    case 18: spellTbl[3]++;
    case 17: spellTbl[2]++;
    case 16: spellTbl[1]++;
    case 15: spellTbl[1]++;
    case 14: spellTbl[0]++;
    case 13: spellTbl[0]++;
    default: break;
  }
}

string *spell_immunity()
{
  string *si;

  si = ({ });
  switch (this_player()->query_wis())
  {
    case 25:
      si += ({ "antipathy-sympathy", "death spell", "mass charm" });
    case 24:
      si += ({ "geas", "mass suggestion", "rod of rulership" });
    case 23:
      si += ({ "chaos", "febblemind", "hold monster", "magic jar",
        "quest" });
    case 22:
      si += ({ "charm monster", "confusion", "emotion", "fumble",
        "suggestion" });
    case 21:
      si += ({ "fear" });
    case 20:
      si += ({ "forget", "hold person", "ray of enfeeblement",
        "scare" });
    case 19:
      si += ({ "cause fear", "charm person", "command", "friends",
        "hypnotism" });
    default:
       break;
  }
  return (si);
}

  /* charaisma effects */
int num_henchmen() {
  return ( ({ 0,1,1,1,2,2,3,3,4,4,4,5,5,6,7,8,10,15,20,25,30,35,
    40,45,50 }) [(int)this_player()->query_cha() - 1] );
}

int loyalty_base() {
  return ( ({ -8,-7,-6,-5,-4,-3,-2,-1,0,0,0,0,0,1,3,4,6,8,10,12,
    14,16,18,20,20 }) [(int)this_player()->query_cha() - 1] );
}

int reaction_adj()
{
  return ( ({ -7,-6,-5,-4,-3,-2,-1,0,0,0,0,0,1,2,3,5,6,7,8,9,10,
    11,12,13,14 }) [(int)this_player()->query_cha() - 1] );
}

  /* check functions */
int query_open_doors(int special) {
  if (special)
    return (random(20) < open_special_doors());
  return (random(20) < open_normal_doors());
}
int query_bblg() { return (random(100) < bnd_brs_lft_gts()); }
int query_system_shock() { return (random(100)  < system_shock()); }
int query_resurrect_survival() {
  return (random(100) < resurrect_survival());
}
int query_learn_spell() { return (random(100) < learn_spell()); }
int query_illusion_immunity(int spell_level) {
  return (spell_level <= illusion_immunity());
}
int query_spell_fail() { return (random(100) < spell_fail()); }
int query_spell_immunity(string spell_name) {
  return (member_array(spell_name, spell_immunity()) != -1);
}
