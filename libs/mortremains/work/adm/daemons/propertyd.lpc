/*
** Propertyd.c
** This daemon calculates all sorts of stat and property related
**   stuff.
** Written by Cyanide@Nightfall's Keep, 7 May 1997 at like 1 am.
*/

#include <body.h>
#include <class_xp.h>

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

varargs int get_save (int, string);
int fix_masscap(object);
int filter_mass(object);


// This function calculates a monsters experience point value.
// Created by Cyanide 7 May 97.
// Cyanide updated 28 Aug 97.

int get_xp_rank( object ob ) {
    int xpv, hd, counter, *stat;
    object wep;

    hd = ob->query_level();

    // This is to help out lower level players.
    hd++;

    wep = ob->query("weapon1");
    if (wep && !living(wep)) {
	switch (ob->query_skill(wep->query("weapon_type"))) {
	case 3..4 : hd++; break;
	case 5 : hd+=2; break;
	}
    } else
	wep = ob;

    if (wep->query("damage") && pointerp(wep->query("damage")))
	counter = ((int *)wep->query("damage"))[1];
    if (!counter || counter < 0) counter = 0;

    switch ( counter ) {
    case 0..14 : break;
    case 15..25 : hd++; break;
    default: hd+=2; break;
    }

    stat = values( (mapping)ob->query("stat") );
    for (xpv=0; xpv < sizeof(stat); xpv++)
	if (stat[xpv] > 16) hd++;

    if ((int)ob->query("armor_class")<0) hd++;
    if ((int)ob->query("natt")>3) hd++;

    if (ob->query("weap_resist"))
	hd+=(ob->query("weap_resist"));

    if (ob->query("magic_resist")) {
	if ((int)ob->query("magic_resist") > 120)
	    ob->set("magic_resist", 120);
	hd+=((ob->query("magic_resist"))/20);
    }

    if (userp(ob)) {
	hd+=2;
    } else {
	if (ob->query("special")) 
	    hd += ob->query("special");
    }

    if (ob->query("resist_type"))
	for (counter=0; 
	  counter<sizeof(keys(ob->query("resist_type")));
	  counter++) 
	{
	    int val = (values(ob->query("resist_type")))[counter];

	    if (val < 50) hd++;
	}

    return hd;
} // end get_xp_rank()

varargs int calc_xpv (object ob, int no_set) {
    int xpv;
    int hd = get_xp_rank(ob);

    if (hd<13) {
	xpv = (hd*hd) * 14;
    } else {
	hd = hd - 13;
	xpv = (hd * 1100) + 3000;
    }

    if (!no_set)
	ob->set("xpv", xpv);

    return xpv;
}

int query_THAC0(object ob) {
    string klass, klass2;
    int level, level2, thac0;
    object link;

    if (ob->query_class()) {
	klass = (ob->query_class());
    } else {
	klass = "warrior";
    }

    //Monsters tend to hit a little harder...
    level = ob->query_level(klass);
    if (!userp(ob)) level+=5;
    /*
      if (level>20) level = 20;
	else if (level < 1) level = 1;
    */
    if (level < 1) level = 1; 

    switch (klass) {
    case "priest" : thac0 = (21-((2*level)/3)); break;
    case "rogue" : thac0 = 21 - (level/2); break;
    case "warrior" : thac0 = (21-level); break;
    case "wizard" : thac0 = (21-(level/3)); break;
    default: thac0 = (21-(level/2)); break;
    }

    link = ob->query_link();
    if (link){
	level2 = link->query("level_old");
	if (level2){
	    klass2 = (keys(link->query("Class_old")))[0];
	    switch (klass2) {
	    case "priest" : thac0 -= ((2*level2)/3); break;
	    case "rogue" : thac0 -= (level2/2); break;
	    case "warrior" : thac0 -= level2; break;
	    case "wizard" : thac0 -= ((level2/3)); break;
	    }
	}
    }
    if (thac0 > 20) thac0 = 20;

    return thac0;
}  //end query_THAC0()


// This function was originally written by Ilzarion (Who knows when?)
// Cyanide cleaned up and streamlined alot. Also moved it out of the way
//   28 Aug 97  :)

int query_natt (object fellow) {
    int natt, hand;
    string wep_type;
    object weap1, weap2;

    if (!userp(fellow) && fellow->query("natt"))
	return (fellow->query("natt"));

    hand = fellow->query("handedness");

    weap1 = fellow->query("weapon"+hand);
    if (hand==1)
	weap2 = fellow->query("weapon2");
    else
	weap2 = fellow->query("weapon1");

    natt = 1;

    if (!weap1 && !weap2) {
	if (fellow->query("unarmed_natt"))
	    return (int)fellow->query("unarmed_natt");
	wep_type = "Unarmed";
	weap1 = fellow;
    } else {
	if (weap1) {
	    wep_type = weap1->query("weapon_type"); 
	} else {
	    if (weap2) {
		wep_type = weap2->query("weapon_type");
	    }
	}
    }

    if (weap1) {
	switch (fellow->query_skill(wep_type)) {
	case 0 :  // Nonproficiency...
	    break;
	case 1 :  // Proficient
	    if ((fellow->query_level()) > 15) 
		if (fellow->query_level("warrior")) 
		    natt = natt+1;
	    break;
	case 2 : // Specialization, expertise...
	    if ((fellow->query_level())>15) natt++;
	    break;
	case 3 : // Mastery...
	    if ((fellow->query_level())>6) natt++;
	    if ((fellow->query_level())>15) natt++;
	    break;
	case 4 : // High Mastery...
	    if ((fellow->query_level())>6) natt++;
	    if ((fellow->query_level())>15) natt++;
	    break;
	case 5 :    //Grand mastery...
	    if ((fellow->query_level())>15) natt+=2;
	    if ((fellow->query_level())>20) natt++;
	    break;
	}
    }

    if (weap1==fellow) weap1 = 0;
    if ((!weap1) && (!weap2) && (fellow->query("unarmed_natt")) )
	natt = (fellow->query("unarmed_natt"));
    if (!natt) natt=1;
    if (weap1)
	if (weap1->query("natt_bonus")) natt++;


    return natt;
}

//This func figures out your AC bonus depending on you dexterity.
//  Cyanide 8 May, 1997
int query_dex_ac_bonus (object ob) {
    int dex, i;
    object weap;

    if ((ob->query("stunned")) || (ob->query("prone"))) return -4;
    if ((ob->query("casting")) ) return 0;

    dex = ob->query("stat/dexterity");

    if (dex<1) dex=1;
    else
    if (dex>25) dex=25;

    switch (dex) {
    case 1..2 : dex = -5; break;
    case 3 : dex = -4; break;
    case 4 : dex = -3; break;
    case 5 : dex = -2; break;
    case 6 : dex = -1; break;
    case 15 : dex = 1; break;
    case 16 : dex = 2; break;
    case 17 : dex = 3; break;
    case 18..20 : dex = 4; break;
    case 21..23 : dex = 5; break;
    case 24..25 : dex = 6; break;
    default : dex = 0; break;
    }

    //ilz is gonna put one- weapon style here

    if ((ob->query_skill("One Weapon Style") > 1)
      && ob->query("weapon"+ob->query("handedness"))){
	weap = ob->query("weapon"+ob->query("handedness"));
	if (ob->query("handedness") == 1)
	    i=2;
	else
	    i=1;

	if ( (!weap->query("nosecond")) && (!ob->query("weapon"+i)))
	    dex += 2;
    }

    return dex;
}  //end query_dex_ac_bonus()


int query_str_tohit (object ob) {
    int str;

    str = (int) ob->query("stat/strength");

    //if (ob->query("feeble")) str = 3; //One method... else set stat/strength to 3

    if (str<1) str=1;
    else
    if (str>25) str=25;

    switch (str) {
    case 1 : str = -5; break;
    case 2..3 : str = -3; break;
    case 4..5 : str = -2; break;
    case 6..7 : str = -1; break;
    case 17..18 : str = 1; break;
    case 19..20 : str = 2; break;
    case 21..22 : str = 3; break;
    case 23..24 : str = 4; break;
    case 25 : str = 5; break;
    default : str = 0; break;
    }

    return str;
}  //end query_str_tohit()


int query_str_dam (object ob) {
    int str;

    str = (int) ob->query("stat/strength");

    if (ob->query("feeble")) str = 3; //One method... else set stat/strength to 3

    if (str<1) str=1;
    else
    if (str>25) str=25;

    switch (str) {
    case 1 : str = -4; break;
    case 2 : str = -2; break;
    case 3..5 : str = -1; break;
    case 16..17 : str = 1; break;
    case 18 : str = 2; break;
    case 19..20 : str = 3; break;
    case 21 : str = 4; break;
    case 22 : str = 5; break;
    case 23 : str = 6; break;
    case 24 : str = 7; break;
    case 25 : str = 8; break;
    default : str = 0; break;
    }

    return str;
}  //end query_str_dam()


// Cyanide cut down the max on hp bonuses. It was just plain 
// EXCESSIVE.

int query_con_hp_bonus (object ob) {
    int con, fi;

    con = (int)ob->query("base_stat/constitution");
    if(!userp(ob)) con = (int)ob->query("stat/constitution");


    switch (con) {
    case 1 : con = -3; break;
    case 2..3 : con = -2; break;
    case 4..6 : con = -1; break;
    case 7..14 : con = 0; break;
    case 15 : con = 1; break;
    case 16 : con = 2; break;
    case 17 : con = 2; fi = 3; break;
    case 18 : con = 2; fi = 4; break;
    case 19 : con = 3; fi = 5; break;
    case 20 : con = 3; fi = 6; break;
    case 21 : con = 3; fi = 6; break;
    case 22..24 : con = 4; fi = 7; break;
    case 25 : con = 5; fi = 8; break;
    default : con = 0; break;
    }
    con*=2;
    fi*=2;

    if ((ob->query_class()) == "warrior") con = fi;

    if ( !userp(ob) )
	return fi;
    else
	return con;

}  // end query_con_hp_bonus()


// This function determines a creatures encumberance capacity in pounds
// based upon its strength and (to a lesser extent) size.
// Cyanide added it 22 July 97.

int query_max_cap (object ob) {
    int strength, size;

    strength = ob->query("stat/strength");
    size = ob->query("size");

    if (strength<1) strength = 1;
    if (strength>25) strength = 25;

    switch (strength) {
    case 1..2   : strength = 15; break;
    case 3      : strength = 20; break;
    case 4..5   : strength = 25; break;
    case 6..7   : strength = 35; break;
    case 8..9   : strength = 50; break;
    case 10..11 : strength = 55; break;
    case 12..13 : strength = 60; break;
    case 14..15 : strength = 70; break;
    case 16     : strength = 85; break;
    case 17     : strength = 100; break;
    case 18     : strength = 135; break;
    case 19     : strength = 150; break;
    case 20     : strength = 175; break;
    case 21     : strength = 200; break;
    case 22     : strength = 250; break;
    case 23     : strength = 300; break;
    case 24     : strength = 350; break;
    default     : strength = 425; break;
    }

    // Change to % based upon size.  Size 6 = 100%
    size = (size*10)+40;

    // Adjust calculated capacity by "size" percent...
    strength = (strength*size)/100;

    return strength;
}

// This func determines the best save out of all the object's
// classes.  

int query_save(object ob) {
    int *levels, i, sv=100, sv2;
    string *classes;
    mapping map;

    map = ob->query_levels2();
    if (map) {
	classes = keys(map);
	levels = values(map);

	for (i=0; i<sizeof(classes); i++) {
	    sv2 = get_save(levels[i], classes[i]);
	    if (sv2<sv) sv = sv2;
	}
    } else {
	sv = get_save(ob->query_level()); 
    }

    if (sv == 0) sv = 1;
    return sv;
}                           

// This calculates the saving throw of the given class at the given level.
// Cyanide, 10 Aug 97.

varargs int get_save (int level, string Class) {
    int save;

    if (!Class) Class = "warrior";
    if (!level) level = 0;

    switch(Class) {
    case "priest" : save = (level/-2)+15; break;
    case "rogue" : save = (level/-3)+14; break;
    case "wizard" : save = ((3*level)/-8)+13; break;
    default : save = ((2*level)/-3)+16; break;
    } 

    if (save>18) save = 18;
    // Currently, no minimum save...

    return save;
}

// This function figures out and repairs dilemmas of mass and capacity
// Completed - 11 Nov 97

int fix_masscap(object ob) {
    int mass, carried, max_cap, x;
    string item_name;
    object *stuff, thing;

    stuff = all_inventory(ob);
    max_cap = ob->query("max_cap");
    carried = max_cap;

    if (ob->query_room()) return 10000000;
    for (x=0;x<sizeof(stuff);x++) {
	mass = stuff[x]->query("mass");
	if (!mass) mass = 0;
	carried-=mass;
    }

    ob->set("capacity", carried);

    // If the object is living and carrying too much, it'll drop
    // some stuff.  Too damn bad.  -Cyanide

    if (living(ob)) {
	stuff = filter_array(stuff, "filter_mass", ob);
	if ( (carried<0)&&(sizeof(stuff)) ) {
	    thing = stuff[random(sizeof(stuff))];
	    item_name = thing->query("id")[0];

	    // This loop makes sure we drop the "item_name"
	    // we want (i.e., sword 2, rock 4, etc...)
	    mass=0;
	    max_cap = 0;  // Reusing this as a flag. Sorry.
	    for (x=0; x<sizeof(stuff) && (!max_cap); x++) { 
		if (stuff[x]->id(item_name)) mass++;
		if (stuff[x] == thing) max_cap = 1;
	    }
	    item_name = thing->query("short");
	    tell_object(ob, "You suddenly lose your grip on "
	      +item_name+"!\n");
	    ob->force_me("drop "+item_name+" "+mass);
	}
    }
    return carried;
}

int filter_mass(object ob) {
    if (!ob->query("mass")) return 0;
    if (!ob->query("short")) return 0;
    if (ob->query("prevent_drop")) return 0;
    if (ob->query_auto_load()) return 0;
    return 1;
}


// This determines the ressurection chance of a dead character
// based up his or her BASE constitution score.
// Cy finally added in Nov of 97.
// Cy made it based completely on level and the number of deaths
// a character has on his record.
// 1 March 2000

int query_res_percentage(object ob) {
    int con = 100;

    con -= ((int) ob->query("deaths") * 2);
    con += ob->query_level();

    /*
	con = ob->query("base_stat/constitution");
	if (con>25) con = 25;
	if (con<=1) return 0;

	switch (con) {
	case 0..13 : con = (con * 5) + 25; break;
	case 14..18 : con-=13;
	    con = (con * 2) + 90;
	    break;
	default : con = 100;
	}
    */

    return con;
}

int power(int x, int n){
    // do you believe that C doesnt have a power operator??!!! (it's true,, i checked)
    int i, p;
    p = 1;
    for (i = 1;i <= n; i++)
	p = p*x;
    return p;
}

int query_xp_needed(string Class, int lvl){
    object link;
    int golden, needed, needed2, i, lvlold;

    if (lvl==1) return 0;

    // written by ilz on 4/19/98
    //This returns the xp needed for the level sent to it
    i = member_array(Class, (keys(CLASS_XP)));
    if (i == -1) return 0;
    golden = (values(CLASS_XP))[i];
    switch (lvl){
    case 1..8 :  needed = (golden / (power(2, (9-lvl)) ));break;
    case 9 : needed = golden;break;
    case 10..101 : 
	needed = (golden * 2);
	for (i=10;i<=lvl;i++){
	    needed += (((PERCY_GAIN) * needed) / 100);
	}
	break;
    default : needed = golden;break;
    }

    /*
	link = this_player()->query_link();
	lvlold = link->query("level_old");
	if (lvlold && (lvlold > lvl)){
	    lvl -= 1;
	    switch (lvl){
	    case 0..8 :  needed2 = (golden / (power(2, (9-lvl)) ));break;
	    case 9 : needed2 = golden;break;
	    case 10..101 : 
		needed2 = (golden * 2);
		for (i=10;i<=lvl;i++){
		    needed2 += (((PERCY_GAIN) * needed2) / 100);
		}
		break;
	    default : needed2 = golden;break;
	    }
	    needed -= needed2;
	    needed = (needed *(this_player()->query_level(Class)));
	}
    */

    needed *= 10;
    return needed;
}

/* EOF */
