#include "drinks.h"
/* ok handles hps, Spell/Power points and drinking/eating things...
 * Hmmmm, considering we dont want to have drinks/food I will not 
 * put that in at the moment.
 */
/* Logging Taniwha 1995 */
#define XP_LIMIT 15000
#define LOGFILE "BUSTED"
int max_hp,
max_gp,
total_xp,
wimpy;
int hp,
xp,
gp;
private int *drink_info;
nosave mapping damage_done;

void create() {
    damage_done = ([ ]);
} /* create() */

int query_hp() { return hp; }
int query_max_hp() { return max_hp; }
int query_gp() { return gp; }
int query_max_gp() { return max_gp; }
int query_xp() { return xp; }
int query_total_xp() { return total_xp; }
mapping query_damage_done() { return damage_done; }

int set_wimpy(int i) 
{
    int j;
    j = this_object()->query_property("fear");
    if(i < j) i = j;
    if (i <0 || i > 100)
	return -1;
    return (wimpy = i);
} /* set_wimpy() */

int query_wimpy() { return wimpy; }

int set_max_hp(int i) {
    if (max_hp)
	hp = hp*i/max_hp;
    else
	hp = max_hp;
    max_hp = i;
    if (max_hp==1)
	max_hp = 2;
    if (hp>max_hp)
	hp = max_hp;
    return max_hp;
}  /* set_max_hp() */

// Made varargs : Radix - March 3, 1997
varargs int set_hp(int i, object hp_remover)
{
    if (i>max_hp)
	i = max_hp;
    hp = i;
    if (hp<0)
	call_out("do_death", 0,  hp_remover);
    return hp;
} /* set_hp() */

int adjust_hp(int i, object hp_remover)
{
    int bah = 1;    // for color on hp monitor - Radix
    hp += i;
    if(hp_remover && !(int)hp_remover->query_dead() )
	damage_done[hp_remover] += i;
    if ( hp>max_hp )
	hp = max_hp;

    if ( hp<0 ) /* eeek we died! */
    {
	if(i > 0 && hp_remover == this_object() ) call_out("do_death",0,0); /* NOT this object, use attacker list */
	else
	    call_out("do_death", 0, hp_remover);
    }
    // Radix Jan 1996
    if (hp < max_hp/5)
	bah = 0;
    if(interactive(this_object()))
    {
	remove_call_out("display_monitor");
	call_out("display_monitor",0,bah);
    }
    return hp;
} /* adjust_hp() */

int set_max_gp(int i) 
{
    if (max_gp)
	gp = gp*i/max_gp;
    else
	gp = max_gp;
    max_gp = i;
    if (gp>max_gp)
	gp = max_gp;
    return max_gp;
} /* set_max_gp() */

int set_gp(int i) {
    gp = i;
    if (gp > max_gp)
	gp = max_gp;
    return gp;
} /* set_gp() */

int adjust_gp(int i) {
    if(gp + i < 0)
	return -1;
    gp += i;
    if (gp>max_gp)
	gp = max_gp;
    return gp;
} /* adjust_gp() */
void logit(string what,int amount)
{
    if(interactive(this_object()))
    {
	log_file(LOGFILE,(string)this_object()->query_cap_name()+" awarded "+amount+" "+what+
	  " by "+previous_object()->query_name()+" file "+file_name(previous_object())+
	  "\n");
    }
}

int adjust_xp(int i) 
{
    // Radix : Aug 1997
    master()->valid_adjust_xp(previous_object(), this_object(), i);
    if(i > XP_LIMIT) logit("XP",i);
    if (i>0) {
	i = (100-wimpy)*i/100;
	total_xp += i;
    }
    xp += i;
    return xp;
} /* adjust_xp() */

int set_xp(int i) {
    // Radix : Aug 1997
    master()->valid_adjust_xp(previous_object(), this_object(), i);
    if( (i-xp) > XP_LIMIT) logit("XP",(i-xp));
    if ( (xp-i) > XP_LIMIT) logit("XP", -(xp-i));
    if(i == -1 || !i) logit("XP", i);
    xp = i;
}

/* int set_xp(int i) { xp = i; return xp; } */

int adjust_volume(int type, int amt) {
    if (!pointerp(drink_info))
	drink_info = allocate(D_SIZEOF);
    if (type >= D_SIZEOF)
	return 0;
    return drink_info[type] += amt;
} /* adjust_volume() */

int query_volume(int type) {
    if (!pointerp(drink_info))
	drink_info = allocate(D_SIZEOF);
    if (type >= D_SIZEOF)
	return 0;
    return drink_info[type];
} /* query_volume() */

void update_volumes() {
    int i;

    if (!drink_info)
	return ;
    for (i=0;i<sizeof(drink_info);i++)
	if (drink_info[i] > 0)
	    drink_info[i]--;
	else
	    drink_info[i] = 0;
} /* update_volumes() */

string health_string() {
    if (hp < max_hp/10)
	return "is in very bad shape";
    if (hp < max_hp/5)
	return "is in bad shape";
    if (hp < max_hp/2)
	return "is not in a good shape";
    if (hp < max_hp - 200)
	return "is slightly hurt";
    return "is in good shape";
} /* health_string() */

string volume_string()
{
    int i = 0;

    if(drink_info[i]<= 0)
	return "Sober";
    if(drink_info[i] <= 50)
	return "Tipsy";
    if(drink_info[i] <= 100)
	return "Drunk";
    if(drink_info[i] <= 500)
	return "Very drunk";
    if(drink_info[i] <= 2000)
	return "Dead to the world";
    if(drink_info[i] <= 6000)
	return "Close to death";
    return "Pray for painless death";
}
