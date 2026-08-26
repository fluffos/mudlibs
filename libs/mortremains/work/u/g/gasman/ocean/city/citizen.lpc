#include "ocean.h"

inherit MONSTER;

string query_long();
string query_short();
string query_name();
string chat(int rnd);

int i =0;

void init()
{
  ::init();
}

void create() 
{

    ::create();
    i = random(6) + 1;
    set("author", "gasman");
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
      chat(1),
      chat(2),
      chat(3),
    }));

    if(query_name() == "Lizard Man") set_level(15);
    else set_level(random(10));
    
}


string query_short()
{
  string str;
  switch(i)
  {
    case 1 .. 3 : str = "A homeless man."; break;
    case 4 .. 6 : str = "A citizen of"+CITY_NAME+"."; break;
    case 7 .. 10 : str = "A lizard man."; break;
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
    case 7 .. 10 : str = "Lizard Man"; break;
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
    case 7 .. 10 : str = wrap("You see a man with reptilian features. His skin is scaled and green. You aren't quite sure if it is safe to be around him or not."); break;
    default : str = "An ordinary man like doing his business.\n"; break;
  }
  return str;
}

string chat(int rnd)
{
  string str;
  

  switch(i)
  {
     case 1 .. 3 :
      switch(rnd)
      {
        case 1 :
	  str = TO->query("cap_name")+" asks: spare any change?\n";
	break;
	case 2 :
	  str = TO->query("cap_name")+" pukes on his shoes.\n";
	break;
	case 3 :
	  str = TO->query("cap_name")+" stumbles.\n";
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
     case 7 .. 10 :
       switch(rnd)
       {
         case 1 :
           str = "The Lizard Man hisses.\n";
         break;
           str = "The Lizard Man brushes against you.\n Your wallet feels a bit lighter.\n";
         case 2 :
         break;
         case 3 :
           str = "The Lizard Man peers at you.\n";
         break;
       }
     break;
  }
  return str;
}
