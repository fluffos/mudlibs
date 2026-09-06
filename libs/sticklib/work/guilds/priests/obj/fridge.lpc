#include <treasure.h>
#include "../priest.h"

#define POTS ({"greater restore mana", "lesser restore mana", "heal major wounds", "heal minor wounds", "invisibility", "invulnerability", "neutralize poison"})

mapping potions;

string my_long();

void
create_treasure()
{
    set_name("potion fridge");
    set_id("fridge");
    set_long(#'my_long);
    potions = ([]);
}

void
init_treasure()
{
    add_action("put_potion", "store");
    add_action("get_potion", "fetch");
}


string
my_long()
{
    string str, *pot_names;
    int *amounts,i;

    str = "A magical potion fridge.\n";
    amounts = m_values(potions);
    pot_names = m_indices(potions);
    i = sizeof(potions);
    if(!i)
	str += "It is empty.";
    else
	while(--i>=0) {
	    if(amounts[i]>0)
		str += sprintf("   (%d) %s: %d pcs\n", member(POTS,pot_names[i])+1,
		  pot_names[i], amounts[i]); 
	}
    return str;
}

status get() { return 0; }



status
put_potion(string str)
{
    string pot_name;
    object pot;

    if(sscanf(str,"%s into fridge",pot_name)!=1)
	return notify_fail("Store what into what?\n"),0; 

    pot = present(pot_name, this_player());
    if(!pot)
	return notify_fail("But you don't have that.\n"),0;
    if(!pot->is_priest_potion())
	return notify_fail("That's not suitable to be stored in the fridge.\n"),0;

    potions[pot->query_pot_name()]++;
    pot->drop();
    destruct(pot);
    this_player()->tell_me("You put a potion into the fridge");
    return 1;
}

status
get_potion(string str)
{
    string pot_name;
    object pot;
    int n;

    if(sscanf(str,"%d from fridge", n)==1) {
	if(n<1||n>sizeof(POTS))
	    return notify_fail(sprintf("There's only %s different potions!\n",
		sizeof(POTS))),0;
	pot_name = POTS[n-1];
    }
    else
    if(sscanf(str,"%s from fridge", pot_name)!=1)
	return notify_fail("Fetch what from where?"),0;
    if(!member(potions,pot_name) || !potions[pot_name])
	return notify_fail(sprintf("There seems to be no \"%s\" in the fridge\n",
	    pot_name)),0;

    pot = ALCHEMY_D->clone_potion(pot_name,10+random(60));
    if(!pot)
	return notify_fail("*BUG* Inform a guild coder\n"),0;

    if(!this_player()->add_weight(pot->query_weight())) {
	destruct(pot);
	return notify_fail("You don't seem to be able to carry anything more"),0;
    }
    potions[pot_name]--;
    move_object(pot, this_player());
    this_player()->tell_me("You get a potion from the fridge");
    return 1;
}
