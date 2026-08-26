// Inheritable weapon object. For now.
// Mobydick@@TMI-2, 9-11-92
// 10 Jun 97  Cyanide added set_weapon_type().   It rocks.
// 18 Jun 97  Cyanide changed old set_weapon() to set_bonus() on the
//            grounds that it is easier to remember.

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

string *vb, *vb2 ;

void unwield(int silent);
varargs void set_weapon (int, int, int);
varargs void set_bonus (int, int, int);

#define set_value(x) set("value", x) 


int move (mixed dest) {

    object fellow ;

    fellow = environment(this_object()) ;
    if (fellow) {
	if (query("wielded")) {
	    unwield(0);
	}
    }
    return ::move(dest) ;
}

int remove() {

    object fellow ;

    fellow = environment(this_object()) ;
    if (fellow) {
	if ((object)fellow->query("weapon1")==this_object() ||
	  (object)fellow->query("weapon2")==this_object()) {
	    unwield(0);
	}
    }
    return ::remove() ;
}

void unwield(int silent) {

    object firstwep, secondwep, obj ;
    string str ;
    object fellow, wep ;
    string name ;
    int Class ;

    fellow = environment(this_object()) ;
    if (fellow) {
	firstwep = fellow->query("weapon1") ;
	secondwep = fellow->query("weapon2") ;
	obj = this_object() ;
	obj->set("wielded",0) ;
	if(!silent)
	    tell_object (fellow,"You stop wielding "+obj->query("short")+".\n") ;
	if(fellow && environment(fellow) && !silent)
	    tell_room (environment(fellow),fellow->query("cap_name")+" stops wielding "+obj->query("short")+".\n",fellow) ;
	if (obj==firstwep) {
	    if (secondwep) {
		//fellow->set("weapon1",secondwep) ;
		//fellow->set("weapon2",0) ;
		fellow->set("weapon1", 0);  //Cyanide Apr 27
		Class = secondwep->query("weapon") ;
		//fellow->set("attack_strength",Class) ;
	    } else {
		fellow->set("weapon1",0) ;
		//fellow->set("attack_strength",0) ;
	    }
	} else {
	    fellow->set("weapon2",0) ;
	    //		     Class = firstwep->query("weapon") ;    
	    //fellow->set("attack_strength",Class) ;
	}
    }
    str = obj->query("unwield_func") ;
    if (str) call_other(obj,str) ;

}

void set_verbs(string *verbs) {

    int i ;
    string w1, w2 ;

    vb = verbs ;
    vb2 = allocate(sizeof(vb)) ;
    for (i=0;i<sizeof(verbs);i++) {
	if (sscanf(verbs[i],"%s %s",w1,w2)==2) {
	    vb2[i]=w1+"s "+w2 ;
	} else {
	    vb2[i]=verbs[i]+"s" ;
	}
    }
}

void set_verbs2 (string *verbs) {
    vb2 = verbs ;
}
string *get_verb() {

    int i ;

    i = random(sizeof(vb)) ;
    return ({ vb[i], vb2[i] }) ;
}

// set_weapon is obsolete, but its here for compatibility.
// Please use set_bonus() instead.
varargs void set_weapon (int magic, int to_hit, int dam) {
    if (!magic) magic = 0;
    if (!to_hit) to_hit = 0;
    if (!dam) dam = 0;

    set_bonus(magic, to_hit, dam);
}

varargs void set_bonus (int magic, int to_hit, int dam) {
    if ((!magic)||(magic==0)) magic = 0;

    if ((!to_hit) || (to_hit==0)) to_hit = magic;
    if ((!dam) || (dam==0)) dam = magic;

    this_object()->set("enchantment", magic);
    this_object()->set("to_hit_adj", to_hit);
    this_object()->set("dam_adj", dam);
    if (magic) 
	this_object()->set("schools", ({ "enchantment" }) );
}


void set_weapon_type (string weap) {
    // array qual = ({ value, weight, size, type, damage1, damage2, group })
    // types: bludgeioning=0, piercing=1, slashing=2

    string item = "x", material = "metal/steel";
    int *qual;

    set("weapon_type_set", weap);

    sscanf(weap, "%s/%s", weap, item);
    weap = lower_case(weap);  item = lower_case(item);

    switch (weap) {
    case "axe" : switch (item) {
	case "battle" : qual = ({ 5,7,5,2,1,8,0 }); break;
	case "hand" :
	case "throwing" : qual = ({ 1,5,3,2,1,5,0 }); break;
	case "two-handed" : qual = ({ 10,15,5,2,2,13,0 }); break;
	}
	break;
    case "club" : qual = ({ 2,3,3,0,1,4,1 }); 
	material = "wood"; break;
    case "dagger" : qual = ({ 2,1,1,2,1,4,6 }); break;
    case "dirk" : qual = ({ 2,1,1,2,1,3,6 }); break;
    case "flail" : qual = ({ 15,15,4,0,2,7,2 }); break;
    case "mace" : qual = ({ 8,10,3,0,2,5,1 }); break;
    case "hammer" : qual = ({ 8,5,3,0,1,6,1 }); break;
    case "halberd" : qual = ({ 10,15,5,2,2,11,5 }); break;
    case "glaive" : qual = ({ 10,15,5,2,2,11,5 }); break;
    case "pick" : qual = ({ 7,4,4,1,1,4,5 }); break;
    case "knife" : qual = ({ 1,0,1,1,1,2,6 }); break;
    case "maul" : qual = ({ 200,30,12,0,7,35,1 }); break;
    case "morning star" : qual = ({ 10,12,4,0,2,7,1 }); break;
    case "quarterstaff" : qual = ({ 1,4,6,0,1,6,9 }); 
	material = "wood"; break;
    case "sickle" : qual = ({ 2,3,2,2,1,4,7 }); break;
    case "spear" : qual = ({ 2,5,5,1,1,7,8 }); break;
    case "sword" :
	switch (item) {
	case "long" : qual = ({ 15,4,4,2,1,10,3 }); break;
	case "short" : qual = ({ 10,3,2,1,1,6,6 }); break;
	case "two_handed" :
	case "two-handed" : qual = ({ 50,15,6,2,2,14,3 }); break;
	}
	break;
    case "trident" : qual = ({ 15,5,5,1,2,9,8 }); break;
    case "whip" : qual = ({ 1,2,5,2,1,1,10 }); 
	material = "leather"; break;
    }

    set ("material_type", material);
    set ("value", qual[0]);
    set ("mass", qual[1]);
    set ("size", qual[2]);
    switch (qual[3]) {
    case 0 : set("damage_type", "bludgeoning"); 
	set_verbs( ({ "swings at" }) ); break;
    case 1 : set("damage_type", "piercing"); 
	set_verbs( ({ "stab at" }) ); break;
    case 2 : set("damage_type", "slashing"); 
	set_verbs( ({ "slashes at" }) ); break;
    }
    set ("damage", ({ qual[4], qual[5] }) );
    switch (qual[6]) {
    case 0 : set("weapon_type", "Axes"); break;
    case 1 : set("weapon_type", "Clubbing Weapons"); break;
    case 2 : set("weapon_type", "Flails"); break;
    case 3 : set("weapon_type", "Long Blades"); break;
    case 4 : set("weapon_type", "Medium Blades"); break;
    case 5 : set("weapon_type", "Polearms"); break;
    case 6 : set("weapon_type", "Short Blades"); break;
    case 7  : set("weapon_type", "Polearms"); break;
    case 8  : set("weapon_type", "Polearms"); break;
    case 9 : set("weapon_type", "Staves"); break;
    case 10 : set("weapon_type", "Whips"); break;
    }
    set("weapon", 1);
} // end set_weapon_type()

void set_material_type (string stuff) {
    string stuff2 = "X";
    int tmp, *qual;

    // If the material_type was already set, set the weapon back to the
    // standard values for that weapon.

    if (query("material_type_set")) {
	stuff2 = (string)query("weapon_type_set");
	if (!stuff2) stuff2 = "sword/long";
	set_weapon_type(stuff2);
    }

    if (query("material_type") &&
      (lower_case(stuff) == (string)query("material_type")))
	return;

    set("material_type", stuff);
    set("material_type_set", stuff);

    sscanf(stuff, "%s/%s", stuff, stuff2);
    stuff = lower_case(stuff);
    stuff2 = lower_case(stuff2);

    // Format: %mass, %value, to hit adjustment, damage adjustment

    switch (stuff) {
    case "bone" : qual = ({ 50,30,-1,-1 }); break;
    case "ice" :
    case "crystal" : case "glass" : case "stone" : 
    case "obsidian" : qual = ({ 75, 50, -2, -1 }); break;
    case "leather" : qual = ({ 100, 100, 0, 0 }); break;
    case "metal" :
	switch (stuff2) {
	case "adamantite" :
	case "adamantium" : qual = ({ 75,50000,1,0 }); break;
	case "bronze" : qual = ({ 67,100,0,0}); break;
	case "elven steel" : qual = ({ 50,10000,0,0 }); break;
	case "fine steel" : qual = ({ 90,200,0,0 }); break;
	case "gold" : qual = ({ 200,300,-1,-2 }); break;
	case "mithril" : qual = ({ 50, 600, 1, 1});
	case "green steel" : qual = ({ 100,300,0,2 }); break;
	case "steel" : qual = ({ 100,100,0,0 }); break;
	case "iron" : qual = ({ 125,90,0,0 }); break;
	case "silver" : qual = ({ 100,200,-1,-1 }); break;
	}
	break;
    case "wood" : qual = ({ 50,10,-3,-2 }); break;
    }

    tmp = (int)query("mass");
    if (!tmp) tmp = 0;
    tmp = (qual[0] * tmp)/100;
    set ("mass", tmp);

    tmp = (int)query("value");
    if (!tmp) tmp = 0;
    tmp = (qual[1] * tmp)/100;
    set ("value", tmp);

    set ("material_th_dam", ({ qual[2], qual[3] }) );

} //end set_material_type()     (weapon version)


// All damage filters through the 'hit_func', function. This is
// only a placeholder, but weapons can be made to do some
// cool stuff with this.

int hit_func (object attacker, int damage) {
    return damage;
}
