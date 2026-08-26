#include "ocean.h"

inherit MONSTER;

string query_long();
string query_gender();
string query_short();
string chat();

int i, rnd;

void init()
{
  ::init();
  rnd = random(3) + 1;
  say(rnd+"\n");
  query_short();
}

void create() 
{

    ::create();
    i = random(3) + 1;
    set("author", "gasman");
    set("short", "@@query_short" );
    set("long", "@@query_long" );
    set("id", ({ "citizen", "dude", "person" }) );
    set("race", "human");
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set("damage", ({ 1, 4 }) );
    credit(random(3) + 9);
    set("gender", "@@query_gender");
    set_level(random(10)+1);

    set("chat_chance", 15);
    set("chat_output", ({
      chat(),
    }));
}


string query_short()
{
  string str;
  switch(i)
  {
    case 1 .. 3 : str = "A homeless man.\n"; break;
    set_name("A Homeless man");
    default : str = "Citizen of"+CITY_NAME+".\n"; break;
  } 
  return str;
}

string query_long()
{
  string str;
  switch(i)
  {
    case 1 .. 3 : str = "A filthy homeless man begging for change.\n"; break;
    default : str = "An ordinary man like doing his business.\n"; break;
  }
  return str;
}

string query_gender()
{
  string str;
  switch(i)
  {
    case 1 .. 3 : str = "male"; break;
    default : str = "male"; break; 
  }
  return str;
}

string chat()
{
  string str;
  
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
  }
  return str;
}
