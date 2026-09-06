// Old code... Should be fixed or removed:

#include <treasure.h>

#include <armour_defs.h>

void
create_treasure()
{
    set_name("rabbit paw");
    set_id(({ "paw", "rabbit paw" }));
    set_short("a rabbit paw");
    set_long(
      "You could probably make a good luck amulet of it.\
 You'd need some rope to do it, though.");
    set_weight(1);
    set_value(50);
}

void
init_treasure() 
{
    add_action("make","make");
}

int
make(string x)
{
    object ob;
    if (x!="amulet")
	return 0;
    if (!(ob = present("rope",this_player()))) {
	write("You don't have a rope to make an amulet of the rabbit's paw.\n");
	return 1;
    }
    write("You use the rope to make a good luck amulet from the rabbit's paw.\n");
    /* destruct calls automatically add_weight() on environment() */
    destruct(ob);
    ob = clone_object(ARMOUR_FILE);
    ob->set_name("furry amulet");
    ob->set_short("a furry amulet");
    ob->set_long("The good luck amulet is made of a rabbit's paw.\n");
    ob->set_type("amulet");
    ob->set_ac(1);
    ob->set_weight(1);
    ob->set_value(200);
    move_object(ob,environment());
    environment()->add_weight(1);
    /* destruct calls automatically add_weight() on environment() */
    destruct(this_object());
    return 1;
}
