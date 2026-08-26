/*
** FILE:    catalog_d.c
** PURPOSE: Keeps track of all summonable monsters on the mud, and
**          organizes them by a modified level
*/

#include <uid.h>
#include <daemons.h>

inherit DAEMON;

#define SAVE_PATH_MAIN "/adm/etc/"
#define SAVE_PATH_ATTIC SAVE_PATH_MAIN+"attic/"
#define SAVE_NAME "catalog"           

varargs object get_random_mon( int, int );
int get_level ( object );
nomask int save_all();
int remove_base_name ( string );

// Globals
mapping reg_map = ([]);

/******************************************************************/

int catalog_monster ( mixed mon ) {
    object ob;
    string *base_names, name;
    int level;

    if (stringp(mon)) {
	ob = clone_object((string)mon);
    } else {
	if (objectp(mon)) ob = (object)mon;
	else return 0;
    }

    if (ob->query("prevent_summon")) return 0;

    base_names = keys(reg_map);
    name = base_name(ob);

    if (member_array(name, base_names) != -1)
	return 0;

    level = get_level(ob);

    reg_map += ([ name : level ]);

    REGISTRY_D->admin_call(
      name+" has been added to the summoning registry "+
      "as rank "+level+"."
    );

    save_all();

    return 1;
}

/******************************************************************/

varargs object get_random_mon( int lvl1, int lvl2 ) {
    string *base_names, *names = ({});
    int *lvls, i, num;
    object ob = 0;

    if (!lvl1) lvl1 = 0;
    if (!lvl2) lvl2 = lvl1;

    base_names = keys(reg_map);
    lvls = values(reg_map);

    names = ({});
    for (i = 0; i < sizeof(lvls); i++) {
	if (lvls[i] >= lvl1 && lvls[i] <= lvl2)
	{
	    names += ({ base_names[i] });
	} else {
	}
    }

    num = sizeof(names);
    if (num > 0) {
	num = random(num);
	ob = clone_object(names[num]);

	if (!ob || ob->query("prevent_summon")) {
	    remove_base_name(names[num]);

	    ob = get_random_mon(lvl1, lvl2);
	}
    }

    return ob;
}

/******************************************************************/

int get_level ( object ob ) { 
    int hd, counter;
    object wep;

    hd = ob->query_level();

    wep = ob->query("weapon1");
    if (wep && !living(wep)) {
	switch (ob->query_skill(wep->query("weapon_type"))) {
	case 3..4 : hd++; break;
	case 5 : hd+=2; break;
	}
    } else {
	wep = ob;
    }

    if (wep->query("damage"))
	counter = (wep->query("damage"))[1];
    if (!counter || counter < 0) counter = 0;

    switch ( counter ) {
    case 0..14 : break;
    case 15..25 : hd++; break;
    default: hd+=2; break;
    }

    if ((int)ob->query("armor_class")<0) hd++;
    if ((int)ob->query("natt")>3) hd++;

    if (ob->query("weap_resist"))
	hd+=(ob->query("weap_resist"));

    if (ob->query("magic_resist")) {
	if ((int)ob->query("magic_resist") > 120)
	    ob->set("magic_resist", 120);
	hd+=((ob->query("magic_resist"))/20);
    }

    if (ob->query("special")) 
	hd += ob->query("special");

    for (counter=0; 
      counter<sizeof(keys(ob->query("resist_type")));
      counter++) 
    {
	int val = (values(ob->query("resist_type")))[counter];

	if (val > 50) hd++;
    }

    return hd;

}  // end get_level()

/******************************************************************/

nomask int save_all() {
    save_object(SAVE_PATH_MAIN+SAVE_NAME);
    save_object(SAVE_PATH_ATTIC+SAVE_NAME);
}

/******************************************************************/

int remove_base_name ( string base ) {
    int i, sz, flag = 0;
    mapping tmp = ([]);
    string *base_names;

    //if (active!=ACTIVE) return DAEMON_NOT_ACTIVE;

    base_names = keys(reg_map);
    sz = sizeof(base_names);

    for (i=0; i<sz; i++) {
	if (base_names[i]!=base) {
	    tmp += ([ base_names[i] : reg_map[base_names[i]] ]);
    } else {
	flag = 1;
	REGISTRY_D->admin_notify(base+" has been removed from "+
	  "summon registry.");
    }
}

reg_map = tmp;
save_all();
return flag;
}

/******************************************************************/

nomask void load_saved_data() 
{
    if (!restore_object(SAVE_PATH_MAIN+SAVE_NAME)) 
    {
	REGISTRY_D->admin_call("ERROR: Failure in loading catalog "+
	  "registry! Attempting to load from backup copy.");
	if (!restore_object(SAVE_PATH_ATTIC+SAVE_NAME)) {    
	    REGISTRY_D->admin_call("ERROR: Fatal failure loading "+
	      "backup copy. Catalog is loading a null mapping.");
	    reg_map = ([]);
	}
    }

    return;
}

/******************************************************************/

mapping dump_catalog() { return reg_map; }

/******************************************************************/

void create() 
{
    seteuid( ROOT_UID );
    load_saved_data();
}

/* EOF */
