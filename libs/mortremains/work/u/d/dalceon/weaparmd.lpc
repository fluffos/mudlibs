// Weparmd.c
//
// The daemon that handles the set_weapon_type() and 
// set_armor_type() functions, and anything related.

inherit DAEMON;

/**[ ARMOR FUNCTIONS ]**********************************************/

// This func was written by Cyanide@Nightfall's Keep
// on 11 June 1997 with Nightmask@Nightfall's Keep.  ;)

void set_armor_type (object ob, string type) {
    string material = "metal/steel" ;
    int tmp, *qual;

    type = lower_case(type);

    switch (type) {
    case "amulet" : qual = ({ 500,1,0,7 });
	material = "metal/gold"; break;
    case "clothing" : qual = ({ 0,0,0,12 }); break;
    case "banded" : qual = ({ 200,15,6,0 }); break;
    case "brigandine" : qual = ({ 120,25,4,0 }); break;
    case "chain" : qual = ({ 75,30,5,0 }); break;
    case "field plate" : qual = ({ 2000,35,8,0 }); break;
    case "full plate" : qual = ({ 6000,40,9,0 }); break;
    case "helmet" : qual = ({ 30,5,0,1 }); break;
    case "hide" : qual = ({ 15,10,4,0 });
	material = "leather"; break;
    case "leather" : qual = ({ 5,7,2,0 });
	material = "leather"; break;
    case "padded" : qual = ({ 4,7,2,0 });
	material = "cloth"; break;
    case "plate" : case "plate mail" :
    case "platemail" : qual = ({ 600,35,7,0 }); break;
    case "ring mail" : qual = ({ 100,32,3,0 }); break;
    case "scale" : qual = ({ 120,33,4,0 }); break;
    case "shield" : qual = ({ 7,5,1,2 });
	material = "wood"; break;
    case "splint" : qual = ({ 80,32,6,0 }); break;
    case "studded" : 
    case "studded leather" : qual = ({ 20,21,3,0 });
	material = "leather"; break;
    case "boot" : 
    case "boots" : qual = ({ 1,1,0,4 }); 
	material = "leather"; break;
    case "gloves" : qual = ({ 1,0,0,3 });
	material = "leather"; break;
    case "gauntlets" : qual = ({ 7,2,0,3 }); break;
    case "ring" : qual = ({ 25,0,0,6 });
	material = "metal/gold"; break;
    case "robes" : qual = ({ 5,3,0,9 }); 
	material = "cloth"; break;
    case "bracers" : qual = ({ 3,0,0,5 }); 
	material = "leather"; break;
    case "cloak" : qual = ({ 5,1,0,8 }); 
	material = "cloth"; break;
    case "girdle" : qual = ({ 45,60,0,10 });
	material = "leather"; break;
    case "belt" : qual = ({ 20,25,0,11 });
	material = "leather"; break;
    }

    switch (qual[3]) {
    case 0 : ob->set ("type", "suit"); break;
    case 1 : ob->set ("type", "helmet"); break;
    case 2 : ob->set ("type", "shield"); break;
    case 3 : ob->set ("type", "gloves"); break;
    case 4 : ob->set ("type", "boots"); break;
    case 5 : ob->set ("type", "bracers"); break;
    case 6 : ob->set ("type", "ring"); break;
    case 7 : ob->set ("type", "amulet"); break;
    case 8 : ob->set ("type", "cloak"); break;
    case 9 : ob->set ("type", "robes"); break;
    case 10 : ob->set ("type", "girdle"); break;
    case 11 : ob->set ("type", "belt"); break;
    default : ob->set ("type", "clothing"); break;
    }

    ob->set ("armor_object", 1);
    ob->set("armor", qual[2]);
    ob->set ("bonus", 0);
    ob->set ("value", qual[0]);
    ob->set ("mass", qual[1]);
    ob->set ("armor", qual[2]);
    if (!ob->query("material_type")) 
	ob->set("material_type", material);

} //end set_armor_type()


// Cyanide@Nightfall's Keep wrote this, 2 Nov 97

varargs int arm_set_bonus(object ob, int bonus, int magic) {
    if (undefinedp(magic))
	magic = bonus;

    if (bonus || magic) {
	ob->set("enchantment", magic);
	ob->set("schools", ({ "enchantment" }) );
    } else {
	ob->set("bonus", 0);
    }

    ob->set("bonus", bonus);
    return 1;
}


/**[ WEAPON FUNCTIONS ]*********************************************/


varargs void weap_set_bonus (object ob, int magic, int to_hit, int dam) {
    if ((!magic)||(magic==0)) magic = 0;

    if ((!to_hit) || (to_hit==0)) to_hit = magic;
    if ((!dam) || (dam==0)) dam = magic;

    ob->set("enchantment", magic);
    ob->set("to_hit_adj", to_hit);
    ob->set("dam_adj", dam);
    if (magic) 
	ob->set("schools", ({ "enchantment" }) );
}

void set_weapon_type (object ob, string weap) {
    // array qual = ({ value, weight, size, type, damage1, damage2, group })
    // types: bludgeioning=0, piercing=1, slashing=2

    string item = "x", material = "metal/steel";
    int *qual;

    ob->set("weapon_type_set", weap);

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
    case "dirk" : qual = ({ 2,1,1,1,1,3,6 }); break;
    case "flail" : qual = ({ 15,15,4,0,2,7,1 }); break;
    case "hammer" : qual = ({ 8,5,3,0,1,6,1 }); break;
    case "halberd" : qual = ({ 10,15,5,2,2,11,5 }); break;
    case "glaive" : qual = ({ 10,15,5,2,2,11,5 }); break;
    case "gun" : 
	switch (item) {
	case "pistol" :
	case "light handgun" : qual = ({ 100,1,1,1,1,12,7 });
	    ob->set("ammo_type", ".22"); break;
	case "medium handgun" : qual = ({ 300,2,1,1,2,15,7 });
	    ob->set("ammo_type", "9mm"); break;
	case "heavy handgun" : qual = ({ 600,3,1,1,3,18,7 });
	    ob->set("ammo_type", ".357"); break;
	case "very heavy handgun" : qual = ({ 900,4,1,1,4,22,7 });
	    ob->set("ammo_type", ".44"); break;
	case "shotgun" : qual = ({ 200,8,4,1,5,16,8 });
	    ob->set("nosecond", 1);
	    ob->set("ammo_type", "shotshell"); break;
	case "machinegun" : 
	case "machine" : qual = ({ 1500,10,3,1,3,20,9 });
	    ob->set("ammo_type", "11mm"); ob->set("ammo_used", 4);
	    ob->set("natt_bonus", 2);
	    ob->set_bonus(0,-3,0);
	    ob->set("nosecond", 1);
	    break;
	case "heavy" : qual = ({ 9000,30,5,4,10,30,10 });
	    ob->set("nosecond", 1);
	    ob->set("ammo_used", "UNDEFINED"); break;
	}
	break;
    case "pick" : qual = ({ 7,4,4,1,1,4,5 }); break;
    case "knife" : qual = ({ 1,0,1,1,1,2,6 }); break;
    case "mace" : qual = ({ 8,10,3,0,2,5,1 }); break;
    case "maul" : qual = ({ 200,30,12,0,7,35,1 }); break;
    case "morning star" : qual = ({ 10,12,4,0,2,7,1 }); break;
    case "quarterstaff" : qual = ({ 1,4,6,0,1,6,2 }); 
	material = "wood"; break;
    case "sickle" : qual = ({ 2,3,2,2,1,4,5 }); break;
    case "spear" : qual = ({ 2,5,5,1,1,7,5 }); break;
    case "sword" :
	switch (item) {
	case "long" : qual = ({ 15,4,4,2,1,10,3 }); break;
	case "short" : qual = ({ 10,3,2,1,1,6,6 }); break;
	case "two_handed" :
	case "two-handed" : qual = ({ 50,15,6,2,2,14,3 }); break;
	}
	break;
    case "trident" : qual = ({ 15,5,5,1,2,9,5 }); break;
    case "whip" : qual = ({ 1,2,5,2,1,1,4 }); 
	material = "leather"; break;
    }

    ob->set ("material_type", material);
    ob->set ("value", qual[0]);
    ob->set ("mass", qual[1]);
    ob->set ("size", qual[2]);

    switch (qual[3]) {
    case 0 : ob->set("damage_type", "bludgeoning"); 
	ob->set_verbs( ({ "swing at" }) ); break;
    case 1 : ob->set("damage_type", "piercing"); 
	ob->set_verbs( ({ "stab at" }) ); break;
    case 2 : ob->set("damage_type", "slashing"); 
	ob->set_verbs( ({ "slash at" }) ); break;
    default : // Assumedly, "other"
    }

    ob->set ("damage", ({ qual[4], qual[5] }) );
    switch (qual[6]) {
    case 0 : ob->set("weapon_type", "Axes"); break;
    case 1 : ob->set("weapon_type", "Clubbing Weapons"); break;
    case 2 : ob->set("weapon_type", "Staves"); break;
    case 3 : ob->set("weapon_type", "Long Blades"); break;
    case 4 : ob->set("weapon_type", "Whips"); break;
    case 5 : ob->set("weapon_type", "Polearms"); break;
    case 6 : ob->set("weapon_type", "Short Blades"); break;
    case 7 : ob->set("weapon_type", "Small Arms"); break;
    case 8 : ob->set("weapon_type", "Long Arms"); break;
    case 9 : ob->set("weapon_type", "Machine Weapons"); break;
    case 10 : ob->set("weapon_type", "Heavy Weapons"); break;
    }

    ob->set("weapon", 1);

} // end set_weapon_type()


void set_material_type (object ob, string stuff) {
    string stuff2 = "X";
    int tmp, *qual;

    // If the material_type was already set, set the weapon back to the
    // standard values for that weapon.

    if (ob->query("material_type_set")) {
	stuff2 = (string)ob->query("weapon_type_set");
	if (!stuff2) stuff2 = "sword/long";
	ob->set_weapon_type(stuff2);
    }

    if (ob->query("material_type") &&
      (lower_case(stuff) == (string)ob->query("material_type")))
	return;

    ob->set("material_type", stuff);
    ob->set("material_type_set", stuff);

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

    tmp = (int)ob->query("mass");
    if (!tmp) tmp = 0;
    tmp = (qual[0] * tmp)/100;
    ob->set ("mass", tmp);

    tmp = (int)ob->query("value");
    if (!tmp) tmp = 0;
    tmp = (qual[1] * tmp)/100;
    ob->set ("value", tmp);

    ob->set ("material_th_dam", ({ qual[2], qual[3] }) );

} //end set_material_type()     (weapon version)

/* EOF */
