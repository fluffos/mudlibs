/* source file -- AD&D, 2nd Edition Ability Scores */
#include "ability.h"

  /* member variables */
int *actual;                 /* permanent ability scores */
int *effect;                 /* temporary ability scores */

  /* protected function declarations */
protected int check_score(int ab, int sc);
protected string query_stat_string(int sc);

void create()
{
  int i;

  actual = ({ 0, 0, 0, 0, 0, 0 });
  effect = ({ 0, 0, 0, 0, 0, 0 });
  for (i = 0; i < NUM_AS; actual[i++] = random(16) + 3);
  reset_all_stats();
}

int query_real_stat(int ab)
{
  if (ab < STR || ab > CHA)
    return 0;
  return (actual[ab]);
}

int set_real_stat(int ab, int sc)
{
  if (ab < STR || ab > CHA)
    return 0;
  return (actual[ab] = check_score(ab, sc));
}

int adjust_real_stat(int ab, int adj)
{
  if (ab < STR || ab > CHA)
    return 0;
  if (!adj)
    return (actual[ab]);
  if (ab == STR && actual[ab] < 0)
    actual[ab] = adj > 0 ? 18 : 19;
  return (actual[ab] = check_score(ab, actual[ab] + adj));
}

int query_stat(int ab)
{
  if (ab < STR || ab > CHA)
    return 0;
  return (effect[ab]);
}

int set_stat(int ab, int sc)
{
  if (ab < STR || ab > CHA)
    return 0;
  return (effect[ab] = check_score(ab, sc));
}

int adjust_stat(int ab, int adj)
{
  if (ab < STR || ab > CHA)
    return 0;
  if (!adj)
    return (effect[ab]);
  if (ab == STR && effect[ab] < 0)
    effect[ab] = adj > 0 ? 18 : 19;
  return (effect[ab] = check_score(ab, effect[ab] + adj));
}

int reset_stat(int ab)
{
  if (ab < STR || ab > CHA)
    return 0;
  return (effect[ab] = actual[ab]);
}

void reset_all_stats()
{
  int i;

  for (i = 0; i < NUM_AS; i++)
    reset_stat(i);
}

protected int check_score(int ab, int sc)
{
  if (ab == STR && sc < 0)
    if (sc < -100)
      return -100;
    else
      return (sc);
  if (sc < 1)
    return 1;
  if (sc > 25)
    return 25;
  return (sc);
}

string query_ability_name(int ab)
{
  switch (ab)
  {
    case STR: return "Strength";
    case DEX: return "Dexterity";
    case CON: return "Constitution";
    case INT: return "Intelligence";
    case WIS: return "Wisdom";
    case CHA: return "Charisma";
    default:  return 0;
  }
}

string query_real_stat_string(int ab) {
  if (ab < STR || ab > CHA)
    return 0;
  return (query_stat_string(actual[ab]));
}

string query_stat_string(int ab) {
  if (ab < STR || ab > CHA)
    return 0;
  return (query_stat_string(effect[ab]));
}

protected string query_stat_string(int sc)
{
  if (sc > -100 && sc < 0)
    return ("18/" + sc + "");
  else if (sc == -100)
    return ("18/00");
  else if (sc > 0 && sc < 26)
    return (sc + "");
  else
    return (check_score(DEX, sc) + "");
}

