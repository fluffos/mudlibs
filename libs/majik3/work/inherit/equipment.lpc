/*
 * /inherit/equipment.c                      Equipment inheritable
 * 
 *                Coder                      Dazzt 
 * */

#include <stats.h>

inherit ITEM;

/* --- -- - variables - -- --- */

int     worn;
int     wielded;

int     hpr_bonus;
int     spr_bonus;
int     epr_bonus;

int    *stat_bonuses;

/* --- function prototypes --- */

int set_worn(int);
int set_wielded(int);
int query_worn();
int query_wielded();
int is_eq();

void do_wear();                                /* called when eq is worn    */
void do_wield();                               /* called when eq is wielded */

int set_hpregen(int);                          /* various regeneration      */
int set_spregen(int);                          /* bonuses                   */
int set_epregen(int);

int set_statbonus(string, int);

do_wear();                                     /* called by eq system       */
do_wield();
do_unwear();

/* --- -- - functions - -- --- */

int set_worn(int i)    {   return worn = i;     }
int set_wielded(int i) {   return wielded = i;  }

int query_worn()       {   return worn;         }
int query_wielded()    {   return wielded;      }

int is_eq()            {   return 1;            }

int set_hpregen(int i) {   return hpr_bonus = i; }
int set_spregen(int i) {   return spr_bonus = i; }
int set_epregen(int i) {   return epr_bonus = i; }

int set_statbonus(string stat, int amnt)
{
	switch (stat)
	{
		case "str" : return stat_bonuses[S_STR] = amnt;
		case "dex" : return stat_bonuses[S_DEX] = amnt;
		case "con" : return stat_bonuses[S_CON] = amnt;
		case "int" : return stat_bonuses[S_INT] = amnt;
		case "wis" : return stat_bonuses[S_WIS] = amnt;
		case "pow" : return stat_bonuses[S_POW] = amnt;
		case "cha" : return stat_bonuses[S_CHA] = amnt;
		case "siz" : return stat_bonuses[S_SIZ] = amnt;
		case "stu" : return stat_bonuses[S_STU] = amnt;
	}
	return 0;
}
	
/* --- -- -- applies -- -- --- */

create_item()
{
	stat_bonuses = allocate(9);
	THOB->create_equipment();
}

do_wear()
{
	int i;
	int *orig_stats;
	
	orig_stats = ENV(THOB)->query_stats();
	
	for (i = 0; i < sizeof(stat_bonuses); i++)
	{
		orig_stats[i] += stat_bonuses[i];
		write(orig_stats[i] + "  ");
	}
	ENV(THOB)->set_stats(orig_stats);
	write("\n");
}

do_wield()
{
	do_wear();                                 /*  :)                       */
}

do_unwear()
{
	int i;
	int *orig_stats;
	
	orig_stats = ENV(THOB)->query_stats();
	
	for (i = 0; i < sizeof(stat_bonuses); i++)
	{
		orig_stats[i] -= stat_bonuses[i];
		write(orig_stats[i] + "  ");
	}
	ENV(THOB)->set_stats(orig_stats);
	write("\n");
}
	
string query_author()
{
	return "dazzt";
}
