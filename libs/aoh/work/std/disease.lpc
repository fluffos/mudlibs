// Standard illess
//
// (c) 7/97 Softbyte for OSB
//
// To write an disease:  - inherit this object      inherit DISEASE;
//                       - set properties in create P_DISEASE_SHORT,P_DISEASE_LONG
//                         at least the following   P_DISEASE_SUBTYPE,
//                         You find all proerties   P_DISEASE_TIME_ACTION
//                         in <properties.h>
//                       - Overwrite the Action()   void Action() {
//                         function to perform the    ...
//                         action of the disease    }
//                       - Call Infect(0-1000)      Infect(250);
//                         if you want to infect
//                         a rendomly choose living
//                         in the environment

// To start the disease: - clone the disease object  disease=clone_object("filename");
//                       - move it into the player   disease->move(player,M_SILENT);
//                       - call enable               disease->Enable();
//
//
// P_DISEASE_SHORT          name of the illness
// P_DISEASE_LONG           long desc. of the illness
// P_DISEASE_SEVERENESS     1/1000 severeness for heal
// P_DISEASE_OWNER          owner of the illness
// P_DISEASE_TYPE           Type fixed "_disease"
// P_DISEASE_SUBTYPE        Subtype e.g."_flue"
// P_DISEASE_TIME_HEAL      avg. time to self healing
// P_DISEASE_TIME_ACTION    avg time for Action call
// P_DISEASE_CURE_MSG       An healer shows this




#include <properties.h>
#include <moving.h>
inherit "/std/thing";

#define TO this_object()
#define TP this_player()


void Debug(string str)
{
  object ob;
  ob=find_player("softbyte");
  if (!ob || ({int})ob->Query("Silence")) return ;
  tell_object(ob,str);
}

varargs mixed Set(mixed prop,mixed arg)
{
  if (prop==P_DISEASE_TYPE || prop==P_DISEASE_SUBTYPE)
  {
    AddId(arg);
  }
  return ::Set(prop,arg);
}

void create()
{
  ::create();
  if (!is_clone(TO)) return;
  SetShort(0);
  Set(P_INVIS,1);
  Set(P_WEIGHT,0);
  Set(P_NOGIVE,1);
  Set(P_NODROP,1);
  Set(P_NOSELL,1);

  SetValue(100);                            // 100 coins to cure us

  Set(P_DISEASE_SHORT,"a mild form of the flu");  // The name off the illness
  Set(P_DISEASE_LONG,                       // A description
    "The flu will let you sneeze and cough.\n");
  Set(P_DISEASE_SUBTYPE,"_flu");
  Set(P_DISEASE_TIME_ACTION,30);            // avg time for ACtion or 0

  Set(P_DISEASE_TIME_HEAL,900);             // avg time till self heal or 0

  Set(P_DISEASE_SEVERENESS,250);            // in %%
  Set(P_DISEASE_OWNER,0);                   // Nobody is infected
  Set(P_DISEASE_CURE_MSG,
     "You are healed from the flu.\n");     // Default message
  Set(P_DISEASE_TYPE,"_disease");           // Add these as IDs as well


}

// This Function will start the illness
int Enable()
{
object pl;
int t;
  pl=environment(this_object());
  if (!pl || !living(pl)) return -2;
  if (Query(P_DISEASE_OWNER)) return -1;
  Set(P_DISEASE_OWNER,pl);
  t=Query(P_DISEASE_TIME_ACTION);
  if (t)  call_out("Action",t/2+random(t));
  t=Query(P_DISEASE_TIME_HEAL);
  call_out("remove",t/2+random(t)); // heal
  return 1;
}

// This function needs to stop the illness
varargs int remove()
{
  return ::remove();
}

// Can an object be infected ?
int CanInfect(object ob)
{
  // per default livings can be infected
  if (Query(P_DISEASE_OWNER)==ob) return 0;      // no self infect
  if (Query(P_DISEASE_SUBTYPE) &&
       present(P_DISEASE_SUBTYPE,ob)) return 0;  // no second infect
  if (({int})ob->QueryNetdead()) return 0;              // no netdead players
  if (living(ob)) return 1;
  return 0;
}

// Called to enfect other livings
varargs int Infect(int prob, object env)
{
  object pl,target,ill;
  object *obs;
  int l;
  pl=Query(P_DISEASE_OWNER);
  if (!pl && !env) return -1;
  if (!env) env=environment(pl);
  if (!env) return -2;

  if (prob<random(1000)) return -3;

  obs=all_inventory(env)||({});
  obs=filter(obs,#'CanInfect /*'*/);
  l=sizeof(obs);
  if (l<1) return -4;

  target=obs[random(l)];
  seteuid(getuid());
  ill=clone_object(blueprint(this_object()));
  if (ME_OK!=({int})ill->move(target,M_SILENT)  )
  {
    ill->remove();
    return -5;
  }
  ill->Enable();
  Debug(sprintf("Infected %O\n",target));
  seteuid(0);
  return 1;

}

// ------------------- Overridable User functions --------------------
void Action()
{
  // Put your code here
}
