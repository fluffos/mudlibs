/*
** File: _equip.c
** Purpose:
** Credits:
**   04 Nov 97  Cyanide write the file.
**
** Notes: Cyanide based this version upon an equip module originally
**        written on 17 Sep 92 by Mobydick@TMI-2 and borrows some of
**        that code, but probably bears little resemblance to it 
**        other than its function.
*/

#define SYNTAX "Syntax: equip [all|type] (#).\n"
#define VALID_ARMOR_TYPES ({ "amulet", "boots", "bracers", "cloak", \
   "clothing", "earring", "gloves", "helmet", "ring", "robes", \
   "shield", "suit", "girdle", "belt", "full_suit" })

#include <mudlib.h>

int equip_func(object, int);
string *get_types_list(object);

int cmd_equip (string str, int silent) {    
    object armor, *stuff;
    int num = 1, x, counter;

    // Initialization of variables
    num = 1;
    counter = 0;
    stuff = all_inventory(this_player());

    if (!str) str="all";

    // Silent equipping for monsters equipping from the create()
    // function.    (04-06-98) Chronos..
    if (sscanf(str, "%s SILENT", str)==1 && TP->query("npc")) 
	silent = 1;

    // Support for format: equip all
    if (str=="all") {
	write("Equipping all valid armors.\n");
	stuff = filter_array(stuff, "filter_equippable");
	for (x=0; x<sizeof(stuff); x++) 
	    if (stuff[x]->query("armor_object"))
		counter += equip_func(stuff[x], silent);
	if (counter) 
	    write("You equip "+counter+" items.\n");
	else
	    write("You have nothing left to equip.\n");
	return 1;
    }

    // Support for format: equip armour 3
    // If no number argument is used, "num" defaults to 1.
    sscanf(str, "%s %d", str, num);

    while( (counter < num) && (x < sizeof(stuff)) ) {
	if (stuff[x]->id(str)) counter++;
	if (counter==num) equip_func(stuff[x], silent);
	x++;
    }

    if (!counter)
	write("You don't possess a "+str+".\n") ;

    return 1;
}


int equip_func (object obj, int silent) {
    object fwep, swep, class_ob; 
    string material, type, str, *types_list;
    string *no_material = ({}), *no_type = ({});
    int flag, x, y, no_weight, weight, *vals;;

    if (undefinedp(obj->query("armor_object"))) {
	write(capitalize(obj->query("short"))+" isn't armor.\n") ;
	return 0 ;
    }

    if (TP->query("summoned") && !obj->query("native_object")) {
	class_ob = TP->query("summoner");

	if (class_ob)
	    tell_object(class_ob, TPN+" refuses to equip "+ 
	      obj->query("short")+".\n");
	return 1;
    }

    type = obj->query("type") ;
    types_list = VALID_ARMOR_TYPES;

    if (member_array(type, types_list) == -1) {
	write("\""+capitalize(type)+"\" is not a valid armor type.\n"+
	  "To register "+type+" as an armor type, mail admin.\n");
	return 0;
    } 

    types_list = get_types_list(this_player());

    // If he's already equipping it, tell him so.
    if (obj->query("equipped")) {
	write ("You are already equipping "+obj->query("short")+"!\n") ;
	return 0 ;
    }

    // If this is a shield check his weapons and make sure he has a
    // free arm.
    if (type=="shield") {
	fwep = this_player()->query("weapon1") ;
	swep = this_player()->query("weapon2") ;
	if (swep) {
	    write ("You can't use the shield and two weapons at the same time.\n") ;
	    return 0 ;
	}
	if (fwep && (int)fwep->query("nosecond")==1) {
	    write ("You must have a free arm to use the shield.\n") ;
	    return 0 ;
	}
    }
    flag = 0;
    for (x=0;x<sizeof(types_list); x++) {
	if (type==types_list[x]) flag++;
    }
    if (type=="ring" || type=="earring") {
	if (flag>1) {
	    write("You are already wearing two "+type+"s.\n");
	    return 0;
	}
    } else {
	if ((flag > 0) && (type!="clothing")) {
	    write("You are already wearing armor of type "+type+".\n");
	    return 0;
	}
    }

    no_material = ({});
    no_type = ({});
    no_weight = 90000;

    for (x = 0; x < sizeof(all_inventory(TP)); x++) {
	string *tmp_array;

	class_ob = (all_inventory(TP))[x];
	if (class_ob->id("#CLASS_OBJECT#")) {
	    if (class_ob->query("banned_armor")) {
		tmp_array = class_ob->query("banned_armor");
		for (y=0; y<sizeof(tmp_array); y++)
		    no_type = no_type + ({ tmp_array[y] });
	    }
	    if (class_ob->query("banned_materials")) {
		tmp_array = class_ob->query("banned_materials");
		for (y=0; y<sizeof(tmp_array); y++)
		    no_material = no_material + ({ tmp_array[y] });
	    }

	    if (class_ob->query("banned_weight") &&
	      (int)class_ob->query("banned_weight") > no_weight)
		no_weight = class_ob->query("banned_weight");
	}
    }

    if (class_ob) {
	weight = obj->query("mass");

	material = obj->query("material");
	if (!material) material = "metal/steel";
	sscanf(material, "%s/%s", material, str);

	if (member_array(type, no_type) > -1) {
	    write("Your class prevents you from equipping type "+
	      type+".\n");
	    return 0;
	}
	if (member_array(material, no_material) > -1) {
	    write("Your class prevents you from equipping "+
	      material+".\n");
	    return 0;
	}
	if (weight > no_weight) {
	    write("Your class prevents you from equipping "+
	      "something that heavy.\n");
	    return 0;
	}
    }

    if (flag) {
	obj->set("type_std", type);
	type+=(string)flag;
	obj->set("type", type);
    }


    flag = (int)obj->query("size");
    if (!flag) {
	obj->set("size", 6);
	flag = 6;
    }

    if (flag == -1) {
	write(wrap(capitalize(obj->query("short")) + " seems to magically "+
	    "size itself to fit you!"));
    } else {
	if (flag < (int)this_player()->query("size")-1) {
	    write("That armor is much too small for you to use.\n");
	    return 0;
	}
	if (flag > (int)this_player()->query("size")+3){
	    write("That armor is much too large for you to use.\n");
	    return 0;
	}
    }

    if (obj->query("stat_mod") && mapp(obj->query("stat_mod"))) {
	int count;

	// Sorry for re-using this
	types_list = keys( obj->query("stat_mod") );
	vals = values( obj->query("stat_mod") );

	for (count = 0; count < sizeof(vals); count++)
	    TP->add("stat/"+types_list[count], vals[count]);
    }

    str = obj->query("equip_func");
    if(str)  flag = call_other(obj, str);

    if (!flag) {
	write(capitalize(obj->query("short"))+" was not equipped.\n");
	return 1;
    }

    if(!silent) {
	write ("You equip "+obj->query("short")+".\n") ;
	say (this_player()->query("cap_name")+" equips "+
	  obj->query("short")+".\n") ;
    }

    this_player()->set("armor/"+type,obj->query("armor")) ;
    this_player()->set("magic_armor/"+type,obj->query("bonus")) ;
    obj->set("equipped",1) ;
    this_player()->calc_armor_class() ;
    return 1 ;
}

string *get_types_list(object ob) {
    object *stuff;
    string type, *t_list;
    int i;

    stuff = all_inventory(ob);
    t_list = ({});
    for (i=0;i<sizeof(stuff);i++) {
	type = "";
	if (stuff[i]->query("armor_object") &&
	  stuff[i]->query("equipped") ) {
	    if (stuff[i]->query("type_std"))
		type = stuff[i]->query("type_std");
	    else
		type = stuff[i]->query("type");
	    if (sizeof(type)) t_list+=({ type });
	}
    }
    return t_list;
}




int filter_equippable (object ob) {
    if (!ob->query("armor_object")) return 0;
    if (ob->query("equipped")) return 0;
    return 1;
}

string help() {
    string help = SYNTAX;

    help += (@EndHelp
The equip command lets you wear armor. There are several types of armor
(suit, shield, helmet, etc) and you may equip one of each type (except for
rings and earrings: you may wear two of these). Equipping a shield will
prevent you from using two weapons, or a two-handed weapon.
See also: wield
EndHelp
    );

    return help;
}


/* EOF */
