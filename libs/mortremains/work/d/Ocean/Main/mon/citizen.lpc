#include "ocean.h"

inherit MONSTER;

string query_long();
string query_short();
string query_name();
string chat();

int i, rnd = 0;

void init()
{
    ::init();
}

void create() 
{

    ::create();
    i = random(6) + 1;
    set("author", "gasman");
    set("prevent_summon" , 1);
    set("short", "@@query_short" );
    set("long", "@@query_long" );
    set_name("@@query_name");
    set("id", ({ "citizen", "man", "person" }) );
    set("race", "human");
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set("damage", ({ 1, 4 }) );
    credit(random(3) + 9);
    set("gender", "male");

    set("moving", 1);
    set("wimpy", 45);

    set("chat_chance", 15);
    set("chat_output", ({
      chat(),
      chat(),
      chat(),
    }));

    set_level(random(10));
}


string query_short()
{
    string str;
    switch(i)
    {
    case 1 .. 3 : str = "A homeless man."; break;
    case 4 .. 6 : str = "A citizen of"+CITY_NAME+"."; break;
    default : str = "Citizen of"+CITY_NAME+"."; break;
    } 
    return str;
}

string query_name()
{
    string str;
    switch(i)
    {
    case 1 .. 3 : str = "The homeless man"; break;
    case 4 .. 6 : str = "Citizen"; break;
    default : str = "Man"; break;
    }
    return str;
}

string query_long()
{
    string str;
    switch(i)
    {
    case 1 .. 3 : str = "A filthy homeless man begging for change.\n"; break;
    case 4 .. 6 : str = "One of the many people of."+CITY_NAME"+. He looks very busy.\n"; break;
    default : str = "An ordinary man like doing his business.\n"; break;
    }
    return str;
}

string chat()
{
    string str;
    rnd = random(3) + 1;

    switch(i)
    {
    case 1 .. 3 :
	switch(rnd)
	{
	case 1 :
	    str = TO->query("cap_name")+" asks: spare any change?\n";
	    rnd = random(3) + 1;
	    break;
	case 2 :
	    str = TO->query("cap_name")+" pukes on his shoes.\n";
	    rnd = random(3) + 1;
	    break;
	case 3 :
	    str = TO->query("cap_name")+" stumbles.\n";
	    rnd = random(3) + 1;
	    break;
	}      
	break;
    case 4 .. 6 :
	switch(rnd)
	{
	case 1 :
	    str = "Someone brushes past you\n";
	    break;
	case 2 :
	    str = "The man says: get out of my way!\n";
	    break;
	case 3 :
	    str = "The man whistles.\n";
	    break;
	}
	break;
    }
    return str;
}
