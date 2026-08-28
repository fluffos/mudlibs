/*  
 *  /inherit/eq_system.c
 * 
 *          MAJIK equipment system inheritable
 * 
 *  [03.12.97]: Dazzt, initial version
 * */
	

/* --- -- - variables - -- --- */

mixed armour_slots;                            /* data for armour slots     */
mapping slot_aliases;                          /* aliases for slots         */

#define SLOT_NAME       0
#define SLOT_LOCATION   1
#define SLOT_LIMB       2
#define SLOT_OFF        3
#define SLOT_DFF        4
#define SLOT_EQ         5
#define SLOT_PROT       6

#define MAX_2H_WIELD    2.00
#define MAX_1H_WIELD    0.65

/* --- function prototypes --- */

void init_armour_slots(string);                /* initializes eq slots      */
string *resolve_slots(string *);               /* resolves slot aliases     */

mixed query_armour_slots();                    /* returns whole slot data   */
string *query_armour_slot_names();             /* equipment slot names      */
string *query_slots_in_limb(string);           /* returns slots in limb     */

int wear_eq(object, string *);                 /* wears equipment           */
int wield_eq(object);                          /* wields equipment          */
int remove_eq(mixed);                          /* removes equipment         */

object *query_attacks();                       /* returns attacking weapons */

/* --- -- - functions - -- --- */

/*
 * void init_armour_slots(string type)      initialize armour slots
 * 
 * NEVER call this function once armours have been worn!
 * 
 *                               coder      dazzt
 * */

void init_armour_slots(string type)
{
	int *empty_prot, i;

/* create empty protection array */	
	
	empty_prot = "/daemon/protection"->init_protection();

	/* initialize slot aliases */
	
	slot_aliases = ([
"ears"       : ({ "ear", "ear" }),
"leg"        : ({ "shin", "foot" }),
"feet"       : ({ "foot", "foot" }),
"arm"        : ({ "bracer", "hand" }),
"hands"      : ({ "hand", "hand" }),
"legs"       : ({ "leg", "leg" }),
"arms"       : ({ "arm", "arm" }),
"upper body" : ({ "head", "torso", "arms", "waist" }),
"full body"  : ({ "head", "torso", "arms", "legs", "waist" })
]);
	
	/* init slots according to type */
	
	if (!type)
		type = "humanoid";
	
	switch (type)
	{
		default: 
		case "humanoid" : armour_slots = ({ 
			//         SLOT LOCATION         LIMB OFF DFF WEAP/ARMOR  PROT
    			({   "head",      "",       "head", 0,  0,  0,  empty_prot }),
				({    "ear", "right",       "head", 0,  0,  0,  empty_prot }),
				({    "ear",  "left",       "head", 0,  0,  0,  empty_prot }),
				({   "neck",      "",       "head", 0,  0,  0,  empty_prot }),
				({  "cloak",      "",      "torso", 0,  0,  0,  empty_prot }),
				({  "torso",      "",      "torso", 0,  0,  0,  empty_prot }),
				({ "bracer", "right",  "right arm", 0,  0,  0,  empty_prot }),
				({ "bracer",  "left",   "left arm", 0,  0,  0,  empty_prot }),
				({   "hand", "right",  "right arm", 0,  0,  0,  empty_prot }),
				({   "hand",  "left",   "left arm", 0,  0,  0,  empty_prot }),
				({ "finger", "right",  "right arm", 0,  0,  0,  empty_prot }),
				({ "finger",  "left",   "left arm", 0,  0,  0,  empty_prot }),
				({  "waist",      "",      "torso", 0,  0,  0,  empty_prot }),
				({   "shin", "right",  "right leg", 0,  0,  0,  empty_prot }),
				({   "shin",  "left",   "left leg", 0,  0,  0,  empty_prot }),
				({   "foot", "right",  "right leg", 0,  0,  0,  empty_prot }),
				({   "foot",  "left",   "left leg", 0,  0,  0,  empty_prot }),
				({"held","left hand",   "left arm", 0,  0,  0,  empty_prot }),
				({"held","right hand", "right arm", 0,  0,  0,  empty_prot })
		}); 
		break;
	}
}

/*
 * string *resolve_slots(string)              resolves the slot aliases
 *                                            
 *                         coder              dazzt
 * */

string *resolve_slots(string *slots)
{
	int i, j, c;
	string *a;
	string s;
	
	a = keys(slot_aliases);
	
	for (i = 0; i < sizeof(a); i++)
	{
		s = a[i];
		j = member_array(s, slots);
		c = 0;
		
		while (j != -1)
		{
			c++;
			j = member_array(s, slots, j + 1);
		}
		
		for (j = 0; j < c; j++)
			slots += slot_aliases[s];
		slots -= ({ s });
		if (c != 0)
			i = -1;
	}
	return slots;
}

string *crunch_slots(string *slots)
{
	string *crunched, *aliases, *a;
	int done, i, j, k;
	
	crunched = slots;
	aliases = keys(slot_aliases);
	
	k = 0;
	while (!done && k < 3)
	{
		done = 0;
		for (i = 0; i < sizeof(aliases); i++)
		{
			a = slot_aliases[aliases[i]];
			for (j = 0; j < sizeof(a); j++)
				if (member_array(a[j], crunched) == -1)
					break;
			write("j:" + j + ", size: " + sizeof(a) + "\n");
			if (j == sizeof(a))
			{
				crunched += ({ aliases[i] });
				crunched -= slot_aliases[aliases[i]];
				done = -1;
			}
		}
		k++;
	}
	return crunched;
}
	
/*
 * int wear_eq(object, string)                wears equipment
 * 
 *                       coder                dazzt
 * */
		
varargs int wear_eq(object eq, string *slots)
{
	int i, idx;
	string *names;
	
	names = ({	});
	for (i = 0; i < sizeof(armour_slots); i++)
		names += ({ armour_slots[i][SLOT_NAME] });
   
	if (!slots)
		slots = eq->query_slots();
	
	if (!slots) 
		return 0;
	
	slots = resolve_slots(slots);
	
	for (i = 0; i < sizeof(slots); i++)
	{
		idx = member_array(slots[i], names);
		while (idx != -1 && armour_slots[idx][SLOT_EQ] != 0)
			idx = member_array(slots[i], names, idx + 1);
		if (idx == -1)
			return 0;
	}
	
	idx = 0;
	for (i = 0; i < sizeof(slots); i++)
	{
		idx = member_array(slots[i], names);
		while (idx != -1 && armour_slots[idx][SLOT_EQ] != 0)
			idx = member_array(slots[i], names, idx + 1);
		armour_slots[idx][SLOT_EQ] = eq;
	}
	
	THOB->do_wear();
	eq->set_worn(1);
	eq->wear();
	
	return 1;
}

/*
 * int wear_eq(object)                         wields equipment
 * 
 *               coder                         dazzt
 * */

int wield_eq(object eq)
{
	int i, len, cslots, idx, *idxs;
	string *names, *slots;

	names = ({	});
	for (i = 0; i < sizeof(armour_slots); i++)
		names += ({ armour_slots[i][SLOT_NAME] });

/* calculate how many limbs we need to wield this weapon */	
	
	len = eq->query_longest_dim();
	cslots = 3;                                /* kludge :> */
	
	if (len / (MAX_2H_WIELD * THIS->query_height()) <= 1)
		cslots = 2;
	if (len / (MAX_1H_WIELD * THIS->query_height()) <= 1)
		cslots = 1;

	slots = ({ });
	
	for (i = 0; i < cslots; i++)
		slots += ({ "held" });
	
	eq->set_slots(slots);
	
/* */	

	idxs = ({});
	for (i = 0; i < cslots; i++)
	{
		idx = -1; //member_array("held", names);
		do 
		{
			idx = member_array("held", names, idx + 1);
		} while (idx != -1 &&
				 (armour_slots[idx][SLOT_EQ] != 0 ||
				 member_array(idx, idxs) != -1));

		if (idx == -1)
			return 0;
		idxs += ({ idx });
	}

	for (i = 0; i < cslots; i++)
	{
		idx = member_array("held", names);
		while (idx != -1 && armour_slots[idx][SLOT_EQ] != 0)
			idx = member_array("held", names, idx + 1);
		if (idx == -1)
			return 0;
		armour_slots[idx][SLOT_EQ] = eq;
	}

/* */	
	
	THOB->do_wield();
	eq->set_wielded(1);
	eq->wield();
	return 1;
}

/*
 * int remove_eq(object | string eq)          removes equipment
 *    
 *                             coder          dazzt
 * */

int remove_eq(mixed eq)
{
	string *names, *slots;
	int i, idx;
	
	names = ({	});
	for (i = 0; i < sizeof(armour_slots); i++)
		names += ({ armour_slots[i][SLOT_NAME] });
	
	if (stringp(eq))
	{
		idx = member_array(eq, names);
		if (idx != -1)
			eq = armour_slots[idx][SLOT_EQ];
	}
	if (!objectp(eq))
		return 0;
	
	slots = eq->query_slots();
	
	for (i = 0; i < sizeof(slots); i++)
	{
		idx = member_array(slots[i], names);
		while (idx != -1 && armour_slots[idx][SLOT_EQ] != eq)
			idx = member_array(slots[i], names, idx + 1);
		if (idx != -1)
			armour_slots[idx][SLOT_EQ] = 0;
	}
	
	eq->set_worn(0);
	eq->set_wielded(0);
	eq->unwear();
	return 1;
}
	

/*
 * string *query_armour_slot_names()          returns the armour slot names
 * 
 *                             coder          dazzt
 * */

string *query_armour_slot_names()
{
	int i, sz;
	string *s;
	
	s = ({ });
	for (i = 0, sz = sizeof(armour_slots); i < sz; i++)
	{
		if (armour_slots[i][1] != "")
			s += ({ armour_slots[i][1] + " " + armour_slots[i][0] });
		else
			s += ({ armour_slots[i][0] });
	}
	return s;
}

string *query_slots_in_limb(string limb)
{
	string *s, *names;
	int i, sz;
	
	names = query_armour_slot_names();
	
	s = ({ });
	
	for (i = 0, sz = sizeof(armour_slots); i < sz; i++)
		if (armour_slots[i][SLOT_LIMB] == limb)
			s += ({ names[i] });

	return s;
}
	
mixed query_armour_slots()
{
	return armour_slots;
}

/*
 * object *query_attacks()                     returns attacking objects 
 *                                             that player has, in array.
 *                                             array contains '0' if no 
 *                                             weapon to attack with.
 * 
 *                   coder                     dazzt
 * */

object *query_attacks()
{
	object *weapons, ob;
	string *names;
	int idx, i;
	
	names = ({ });
	for (i = 0; i < sizeof(armour_slots); i++)
		names += ({ armour_slots[i][SLOT_NAME] });

	weapons = ({ });
	
	for (idx = -1;;)
	{
		idx = member_array("held", names, idx + 1);
		if (idx == -1)
			break;
		ob = armour_slots[idx][SLOT_EQ];
		if (ob && member_array(ob, weapons) == -1)
			weapons += ({ ob });
		else
			weapons += ({ 0 });
	} while (idx != -1);
	
	return weapons;
}

