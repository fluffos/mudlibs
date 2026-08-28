/****
****    File                    /inherit/armour.c
***     Description             Weapon object
**      Coder                   Dazzt
*/

inherit "/inherit/equipment";

/* --- -- - variables - -- --- */

string *slots;                          /* slots this armour uses           */
string armourtype, armourmake;
int *protection;

/* --- function prototypes --- */

varargs int set_armour_type(string, string);
string *set_slots(mixed);

string *query_slots();
int is_armour();

/* --- -- - functions - -- --- */

create_equipment()
{
	protection = PROTECTION_D->init_protection();
	THOB->create_armour();
}


/* varargs int set_armour_type(string, void | string);
 * 
 * defines various defaults for different armours
 * 
 * coder: dazzt
 * * */


varargs int set_armour_type(string type, string make)
{
	mapping valid_make = 
		([
    		"scale"  : ({ ({ "pierce", 5 }) }),
			"banded" : ({ ({ "slash", 10 }), ({ "bludgeon", 5 }) }),
			"chain"  : ({ ({ "slash", 10 }), ({ "bludgeon", -10 }) }),
			"plate"  : ({ ({ "slash", 15 })	}),
			"ring"   : ({ ({ "slash",  5 }), ({ "pierce", 5 }) }),
			"splint" : ({ ({ "pierce", 5 }), ({ "bludgeon", 10 }) })
]);
	
	int i;
	
	switch (type)
	{
		case "earring"     : set_slots(({ "ear" })); set_dimensions(4, 4, 2);
		break;
		case "earrings"    : set_slots(({ "ear", "ear" })); set_dimensions(4, 4, 4); 
		break;
		case "helm"        :
		case "helmet"      : set_slots(({ "head" })); set_dimensions(20, 20, 25);
		break;
		case "amulet"      : set_slots(({ "neck" })); set_dimensions(15, 10, 5);
		break;
		case "necklace"    : set_slots(({ "neck" })); set_dimensions(5, 5, 5);
		break;
		case "bracer"      :
		case "bracelet"    : set_slots(({ "bracer" })); set_dimensions(20, 7, 7); 
		break;
		case "bracers"     :
		case "bracelets"   : set_slots(({ "bracers" })); set_dimensions(20, 7, 14); 
		break;
		case "gauntlet"    :
		case "glove"       : set_slots(({ "hand" })); set_dimensions(30, 10, 10); 
		break;
		case "gauntlets"   :
		case "gloves"      : set_slots(({ "hands" })); set_dimensions(30, 10, 20); 
		break;
		case "breastplate" : set_slots(({ "torso" })); set_dimensions(60, 70, 30); 
		break;
		case "belt"        : 
		case "girdle"      : set_slots(({ "waist" })); set_dimensions(20, 10, 10);
		break;
		case "boots"       : set_slots(({ "feet" })); set_dimensions(40, 50, 30); 
		break;
		case "boot"        : set_slots(({ "foot" })); set_dimensions(40, 50, 15); 
		break;
		default:
		set_slots("wrong slot");
	}
	armourtype = type;
	
	if (make)
	{
		if (valid_make[make] != 0)
			for (i = 0; i < sizeof(valid_make[make]); i++)
				PROTECTION_D->add_protection(protection, valid_make[make][i][0], valid_make[make][i][1]);
		armourmake = make;
	}
	return 1;
}

string *set_slots(mixed s) 
{ 
	if (arrayp(s))
		return slots = s;
	if (stringp(s))
		return slots = ({ s });
	return 0;
}


string *query_slots()   { return slots; }
int *query_protection() { return protection; }
int is_armour()         { return 1; }

string stat_me()
{
	string s;
	int *p = protection;
	int i;
	
	s = ::stat_me();
	
	s += "ARMOUR OBJECT\n" +
	    "  type         : " + (armourtype ? armourtype : "none") + "\n" +
		"  construction : " + (armourmake ? armourmake : "none") + "\n" + 
		"  slots        : ";
	for (i = 0; i < sizeof(slots); i++)
		s += slots[i] + ", ";
	s = s[0..<3] + "\n";
	s += "  protection   : BLD  PRC  SLS  FIR  CLD  ELC  ACD  POI  MAG  PSI  ASP\n";
    s += sprintf("               : %-4d %-4d %-4d %-4d %-4d %-4d %-4d %-4d %-4d %-4d %-4d  (%%)\n",
				 p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9], p[10]);
	
	return s;
}
	
	
		
