#include <treasure.h>

void create_treasure()
{
    set_name("belladonna");
    set_id( ({ "powder", "belladonna powder" }) );
    set_short("Belladonna-root-powder");
    set_long("This is a very powerful drug when it's used right.");
    set_weight(1);
    set_value(250);
}

void init_treausre()
{
    add_action("cure", "cure");
}

status cure(string person)
{
    if(!person) return 0;
    if( !present(person,environment())  &&
      !(environment(environment())    &&
	present(person,environment(environment()))))
    {
	this_player()->tell_me("Can't find " + person + " here.");
	return 1;
    }
    if(lower_case(person)!= "bilbo")
    {
	this_player()->tell_me(" Ok, you give the powder to "+person+"\n"+
	  "It doesn't seem to have any effect.");
	environment(this_player())->tell_here(this_player()->query_name()+
	  " tries to cure "+ person +".");
	destruct(this_object());
	return 1;
    }
    else return 0;
    return 1;
}
