//add by cach 2001.5
/*mixed query(string what);
mixed query_temp(string what);
void add(string what, mixed arg);
void set(string what, mixed arg);
void set_temp(string what, mixed arg);
void die();
int gain_experience(int what);
*/
//end of add
#include <mudlib.h>
#include "/include/daemons.h"
#include <martial.h>
#include <conditions.h>
inherit CONTAINER_OBJECT;

// This function updates the object's AC. It got moved out of the
// player object so monsters could have it too.
int calc_armor_class()
{
	mapping armor, extra_dbs, extra_acs;
	int i, equip_level, armor_ac, extra_ac, ac; 
	int armor_db, extra_db, db, max_db, max_extra_db;
	mixed *types, *extra_db_types, *extra_ac_types;

	ac = query("natural_armor_class");
	db = query("natural_defense_bonus");
	extra_dbs = query_temp("extra_db");
	extra_acs = query_temp("extra_ac");

	if( extra_dbs && mapp(extra_dbs) ) {
		extra_db_types = keys(extra_dbs);
		for( extra_db=0, i=sizeof(extra_db_types)-1; i>=0; i-- )
			extra_db += extra_dbs[extra_db_types[i]];
	}

	if( extra_acs && mapp(extra_acs) ) {
		extra_ac_types = keys(extra_acs);
		for( extra_ac=0, i=sizeof(extra_ac_types)-1; i>=0; i--)
	    	extra_ac += extra_acs[extra_ac_types[i]];
	}

	armor = query("armor");
	if( !userp(this_object()) && !ac && !db && !armor ) {
		ac = (int)this_object()->query_level() * 5;
		db = (int)this_object()->query_level() * 2;
	} else if( armor && mapp(armor) ) {
		types = keys(armor);
		for( i=0; i<sizeof(types); i++ ) {
			if( !armor[types[i]] ) continue;
			armor_ac = armor[types[i]]->query("armor_class");
			armor_ac -= armor[types[i]]->query("ac_damaged");
			armor_db = armor[types[i]]->query("defense_bonus");
			armor_db -= armor[types[i]]->query("db_damaged");
		   if ( this_object()->query("user") ) {
			equip_level = armor[types[i]]->query("equip_level");	
			switch( equip_level ) {
				case 0 : break;
				case 1 : armor_ac /= 2; armor_db /= 2; break;
				case 2 : armor_ac /= 4; armor_db /= 4; break;
				default : break;
			}
			switch ( (string)armor[types[i]]->query("material") ) {
				case "light_metal" :
					armor_ac = armor_ac * 85/100 ;
					break;
				case "element" :
					armor_ac = armor_ac * 78/100 ;
					break;
				case "stone" :
					armor_ac = armor_ac * 70/100 ;
					break;
				case "wood" :
					armor_ac = armor_ac *65/100 ;
					break;
				case "leather" :
					armor_ac = armor_ac * 60/100 ;
					break;
				case "cloth" :
					armor_ac = armor_ac / 2 ;
					break;
				default :
					break;
			}
		   }
			ac += armor_ac;
			db += armor_db;
		}
	}
	
	// max db and extra_db limit.
	if( userp(this_object()) ) {
		max_db = this_object()->query_stat("int") +
		         this_object()->query_stat("pie");
		max_extra_db = max_db / 2;
		if( db > max_db ) db = max_db;
		if( extra_db > max_extra_db ) extra_db = max_extra_db;
	}
	
	ac += extra_ac;
	db += extra_db;
        // lower bound check ac and db to prevent from bug.
        ac = (ac > 0 ? ac : 0 );
        db = (db > 0 ? db : 0 );
	set("armor_class", ac);
	set("defense_bonus", db);
	return ac;
}

// This function updates the object's bare-handed weapon_classes.
void calc_weapon_class()
{
	int my_str, wsk1, wsk2, twsk, blind;
	int wc1, wc2, min_dam1, min_dam2, max_dam1, max_dam2;
	object weap1, weap2;

	weap1 = query("weapon1");
	weap2 = query("weapon2");
	my_str = this_object()->query_stat("strength");

	if( !weap1 && !weap2 ) {
		wc1 = my_str / 4 + 3;
		min_dam1 = 1;
		max_dam1 = my_str / 6 + 3;
		wsk1 = this_object()->query_skill("unarmed");
	} else {
		if( weap1 ) {
			wc1 = (int)weap1->query("weapon_class");
			wc1 -= (int)weap1->query("wc_damaged");
			min_dam1 = (int)weap1->query("min_damage");
			max_dam1 = (int)weap1->query("max_damage");
			wsk1 = this_object()->query_skill(weap1->query("type"));
		}
		if( weap2 ) {
			wc2 = (int)weap2->query("weapon_class");
			wc2 -= (int)weap2->query("wc_damaged");
			min_dam2 = (int)weap2->query("min_damage");
			max_dam2 = (int)weap2->query("max_damage");
			wsk2 = this_object()->query_skill(weap2->query("type"));
		}
	}

	wc1 += wc1 * wsk1 / 200;
	wc2 += wc2 * wsk2 / 400;

	wc1 += (int)query("natural_weapon_class1");
	wc2 += (int)query("natural_weapon_class2");
        wc1 += (int)query_temp("extra_wc");
    wc1 -= this_object()->query("blind");
	wc2 -= this_object()->query("blind");
	if (wc1 < 1 ) wc1 = 1;
	if (wc2 < 1 ) wc2 = 1;
	min_dam1 += (int)query("natural_min_damage1");
	min_dam2 += (int)query("natural_min_damage2");
	max_dam1 += (int)query("natural_max_damage1");
	max_dam2 += (int)query("natural_max_damage2");

	// Make penalty if using two weapons.
	if( weap1 && weap2 ) {
		twsk = (int)this_object()->query_skill("two-weapon");
		wc1 = wc1 * (twsk+100) / 200;
		wc2 = wc2 * (twsk+100) / 200;
		min_dam1 = min_dam1 * (twsk+100) / 200;
		min_dam2 = min_dam2 * (twsk+100) / 200;
		max_dam1 = max_dam1 * (twsk+100) / 200;
		max_dam2 = max_dam2 * (twsk+100) / 200;
	}

	if( userp(this_object()) ) {
		if( wc1 > 75 ) wc1 = 75;
		if( wc2 > 75 ) wc2 = 75;
		if( min_dam1 > 30 ) min_dam1 = 30;
		if( min_dam2 > 30 ) min_dam2 = 30;
		if( max_dam1 > 60 ) max_dam1 = 60;
		if( max_dam2 > 60 ) max_dam2 = 60;
	}
	set( "weapon_class1", wc1 );
	set( "min_damage1", min_dam1 );
	set( "max_damage1", max_dam1 );
	if ( weap2 ) {
		set( "weapon_class2", wc2 );
		set( "min_damage2", min_dam2 );
		set( "max_damage2", max_dam2 );
	}
}
