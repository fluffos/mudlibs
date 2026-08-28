/*
 * Name:                  /daemon/item.c
 * Description:           Daemon for creating generic items 
 * Coder:                 Dazzt
 * */


mapping generic_weapons = ([
  // name             dimensions    weight      damage types    off / def / spd
  "longsword" : ({ ({ 20, 3, 120 }), 5000, ([ "slash"  : "2d4" ]), 5,   5,   5   }),
  "dagger"    : ({ ({ 15, 3, 40  }), 1000, ([ "pierce" : "1d4" ]), 3,   3,   7   })
]);

mapping generic_armours = ([
  // name             dimensions    weight   protection types         slots        off / def / spd
  "leggings"  : ({ ({ 50, 30, 10 }), 4000, ([ "generic" : 2 ]), ({ "leg", "leg" }),   0,  3,  1 }),
  "boots"     : ({ ({ 30, 30, 10 }), 2000, ([ "generic" : 1 ]), ({ "foot", "foot" }), 0,  2,  0 })
]);

string *descriptions = ({
  "This is a quite typical %short%.\nIt looks very ordinary.\n",
  "You have a strange feeling that you have seen this %short% earlier.\n"
});

/*
 * Function     object create_generic_weapon(void | string type)
 * Description  Creates a generic weapon
 * 
 * Arguments    type - forces the weapon type to 'type'. If not
 *                     defined, weapon type will be random.
 *
 * Returns      Weapon Object
 * */

varargs object create_generic_weapon(string args)
{
    object ob;
    string desc, name, material;
    string *mats;

    if (!args)
	name = keys(generic_weapons)[ random(sizeof(keys(generic_weapons))) ];
    else
	name = args;

    if (!generic_weapons[name])
    {
	write("[" + file_name(previous_object()) + "]: error creating generic weapon (invalid type)\n");
	return 0;
    }

    mats = find_object(MATERIAL_D)->query_all_materials();
    material = mats[ random(sizeof(mats)) ];

    desc = descriptions[random(sizeof(descriptions))];
    desc = replace_string(desc, "%short%", material + " " + name);
    desc = replace_string(desc, "%name%", name);
    desc = replace_string(desc, "%material%", material);

    ob = clone_object("/obj/dummy_weapon");
    ob->set_name(name);

    if (name[sizeof(name)..sizeof(name)] == "s")
	ob->set_short(material + " " + name);
    else
    {
	if (member_array(material[0..0], ({ "a", "e", "i", "o", "u" })) == -1)
	    ob->set_short("a " + material + " " + name);
	else
	    ob->set_short("an " + material + " " + name);
    }

    ob->set_long(desc);
    ob->set_max_hp(100);
    ob->set_hp(random(100));
    ob->set_dimensions(generic_weapons[name][0]);
    ob->set_weight(generic_weapons[name][1]);
    ob->set_damage_names(generic_weapons[name][2]);
    ob->set_offense(generic_weapons[name][3]);
    ob->set_defense(generic_weapons[name][4]);
    ob->set_speed(generic_weapons[name][5]);

    return ob;
}

/*
 * Function     object create_generic_armour(void | string name)
 * Description  Creates a generic armour
 * 
 * Arguments    name - forces the armour name to 'name'. If not
 *                     defined, armour name will be random.
 *
 * Returns      Armour Object
 * */

varargs object create_generic_armour(string args)
{
    object ob;
    string name, desc;
    string *mats, material;

    if (!args)
	name = keys(generic_armours)[ random(sizeof(keys(generic_armours))) ];
    else
	name = args;

    if (!generic_armours[name])
    {
	write("[" + file_name(previous_object()) + "]: error creating generic armour (invalid name)\n");
	return 0;
    }

    mats = find_object(MATERIAL_D)->query_all_materials();
    material = mats[ random(sizeof(mats)) ];

    desc = descriptions[random(sizeof(descriptions))];
    desc = replace_string(desc, "%short%", material + " " + name);
    desc = replace_string(desc, "%name%", name);
    desc = replace_string(desc, "%material%", material);

    ob = clone_object("/obj/dummy_armour");
    ob->set_name(({ material + " " + name, name }));

    if (name[sizeof(name)..sizeof(name)] == "s")
	ob->set_short(material + " " + name);
    else
    {
	if (member_array(material[0..0], ({ "a", "e", "i", "o", "u" })) == -1)
	    ob->set_short("a " + material + " " + name);
	else
	    ob->set_short("an " + material + " " + name);
    }

    ob->set_long(desc);
    ob->set_max_hp(100);
    ob->set_hp(random(100));
    ob->set_dimensions(generic_armours[name][0]);
    ob->set_weight(generic_armours[name][1]);
    ob->set_protection_names(generic_armours[name][2]);
    ob->set_slots(generic_armours[name][3]);
    ob->set_offense(generic_armours[name][4]);
    ob->set_defense(generic_armours[name][5]);
    ob->set_speed(generic_armours[name][6]);

    return ob;
}
