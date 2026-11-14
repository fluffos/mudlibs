// Example illess
//
// (c) 7/97 Softbyte for OSB


#include <properties.h>
#include <moving.h>
inherit "/std/disease";

void create()
{
  ::create();
  Set(P_DISEASE_SUBTYPE,"_flu");
  Set(P_DISEASE_SHORT,
    "a mild form of the flu");  // The name off the illness
  Set(P_DISEASE_LONG,                       // A description
    "The flu will let you sneeze and cough.\n");                  
  Set(P_DISEASE_SEVERENESS,250);            // in %%
  Set(P_DISEASE_TIME_HEAL,1800);
  Set(P_DISEASE_TIME_ACTION,50);
}


// ------------------- User functions --------------------
void Action()
{
 object pl,env;
  pl=Query(P_DISEASE_OWNER);
  if (!pl) 
  {
    call_out("remove",1);
    return ;  
  }
  // Slower call_outs for netdead player
  if (pl->QueryNetdead())
  {
      call_out("Action",300);  
      return ;
  }

  env=environment(pl);
  if (env)
  {
    switch(random(2))
    { 
    case 0: 
      tell_room(env,capitalize(pl->QueryName())+" sneezes.\n",({pl}));
      tell_object(pl,"You sneeze.\n");
      Infect(50,env);  // infect with 5 % probablity
    break;
    case 1:
      tell_room(env,capitalize(pl->QueryName())+" coughes.\n",({pl}));
      tell_object(pl,"You cough.\n");
      Infect(250,env);  // infect with 25 % probablity
    break;
    }
  }
  call_out("Action",60+random(120));  
}
