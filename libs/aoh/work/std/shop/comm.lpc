/*
** /std/shop/comm.c
**
** The communication between the customers and the shopkeeper.
*/

#include <config.h>
#include <properties.h>
#include <living.h>
#include <rooms.h>
#include <secure/wizlevels.h>
#include <combat.h>
#include <magic.h>

#define ME               this_object()
#define TP               this_player()
#define STR              "/lib/string"
#define SHOPKEEPER_ID    "I'm the shopkeeper"
#define DUSTBIN_ID       "I'm the trashcan"
#define LSF(x)           symbol_function(x,ME)
#define ESF(x)           symbol_function(x)

public object QueryShopkeeper()
{
  return present(SHOPKEEPER_ID,ME);
}

public void RemoveShopkeeper()
{
  object ob;
  string fname;

  if (ob = QueryShopkeeper())
    {
      fname = blueprint(ob);
      ob->remove();
      if (ob) destruct(ob);
      ME->RemoveItem(fname);
    }
}

public varargs void SetShopkeeper(string file,mapping properties)
{
  RemoveShopkeeper();
  if (!file)
    ME->AddItem("/std/npc",REFRESH_HOME,
      ({
        ([
          P_NAME:"Shopkeeper",
          P_IDS:({"shopkeeper","keeper","assistant"}),
          P_SHORT:"the shopkeeper",
          P_LONG:"This is the shopkeeper.\n",
          P_GENDER:(random(2)?MALE:FEMALE),
          P_RACE:"human",
          P_ALIGN:500+random(300),
          P_LEVEL:17,
          P_DEX:16,
          P_CON:19,
          P_INT:15
        ]),
        properties
      })-({0}),
      LSF("shopkeeper_refresh"));
  else
    ME->AddItem(file,REFRESH_HOME,properties,LSF("shopkeeper_refresh"));
}

public object QueryDustbin()
{
  return present(DUSTBIN_ID,ME);
}

public void RemoveDustbin()
{
  object ob;
  string fname;

  if (ob = QueryDustbin())
    {
      fname = blueprint(ob);
      ob->remove();
      if (ob) destruct(ob);
      ME->RemoveItem(fname);
    }
}

public varargs void SetDustbin(string file,mapping properties)
{
  RemoveDustbin();
  if (!file)
    ME->AddItem("/std/container",REFRESH_HOME,
      ({
        ([
          P_IDS:({"dustbin","dust-bin","bin"}),
          P_ADS:({"large","dust"}),
          P_WEIGHT:0,
          P_MAX_WEIGHT:(1<<30),
          P_MAX_INV:(1<<30),
          P_SHORT:"a dustbin",
          P_LONG:"A large dustbin.\n"
                 "You can 'toss' useless items into it.\n",
          P_NOGET:"The dustbin is too heavy for you to take.\n"
        ]),
        properties
      })-({0}),
      LSF("dustbin_refresh"));
  else
    ME->AddItem(file,REFRESH_HOME,properties,LSF("dustbin_refresh"));
}

public varargs string CustomerName(int cap)
// Returns name, shortdescription or whatever of the customer. If
// the customer is an invis wizard, 0 is returned, i. e. there should
// be no message given to its environment.
{
  string message;
  if (!TP) return 0;
  message = ({string})TP->QueryName()||({string})TP->QueryShort()||"someone";
  return message?(cap?capitalize(message):message):0;
}

protected varargs status sk_in_shop(int silent)
{
  if (({int})ME->QueryNoShopkeeper()
      ||QueryShopkeeper())
    return 1;
  if (!silent)
    notify_fail(
      lambda(0,
        ({ESF(","),
          ({LSF("Write"),
            "Sorry, there's nobody here who can do that for you!\n"
          }),
          ({LSF("Say"),
            CustomerName(1)+" looks confused, because there's noone here.\n",
            quote(({TP}))
          })
        })),
      NOTIFY_NOT_VALID);
  return 0;
}

public varargs void Say(mixed str,object *exclude,status ignlight)
{
  if (stringp(str))
    str = ({str,0});
  if (TP&&({int})TP->QueryInvis()&&IS_IMMORTAL(TP))
   {
     if (member(exclude||({}),TP)==-1)
       tell_object(TP,str[0]);
     return;
   }
  if (!ignlight)
    show_room(ME,
      ({
        ({string})STR->wrap(str[0],75,0),
        ({string})STR->wrap(str[1]?str[1]:"Something happens.\n",75,0)
      }),exclude);
  else
    tell_room(ME,({string})STR->wrap(str[0],75,0),exclude);
}

public varargs void Write(mixed str,status ignlight)
{
  if (stringp(str))
    str = ({str,0});
  if (!ignlight)
    show_object(TP,
      ({
        ({string})STR->wrap(str[0],75,0),
        ({string})STR->wrap(str[1]?str[1]:"It's too "+(({int})TP->CantSee()<0?"dark":"bright")+".\n",
             75,0)
      }));
  else
    tell_object(TP,({string})STR->wrap(str[0],75,0));
}

public varargs string SkShort(int cap)
// Returns the shortdescription of the shopkeeper. If argument is
// given, the name will be returned capitalized.
{
  object ob;
  if (cap)
    if (({int})ME->QueryNoShopkeeper())
      return "The shopkeeper";
    else
      return (ob=QueryShopkeeper())
             ?capitalize(({string})ob->QueryShort()||"Someone"):0;
  if (({int})ME->QueryNoShopkeeper()) return "the shopkeeper";
  return (ob=QueryShopkeeper())?({string})ob->QueryShort()||"someone":0;
}

public varargs int SkSay(string str)
// Let the shopkeeper say 'str' and return 1. Return 0 for failure.
{
  if (sk_in_shop(1))
    {
      if (TP&&({int})TP->QueryInvis()&&IS_IMMORTAL(TP))
        tell_object(TP,({string})STR->wrap(SkShort(1)+" tells you: "+str,75,2));
      else
        tell_room(ME,({string})STR->wrap(SkShort(1)+" says: "+str,75,2));
      return 1;
    }
  return 0;
}

public int SkWrite(string str)
// Let the shopkeeper say 'str' only to the customer and return 1.
// Return 0 for failure.
{
  if (sk_in_shop(1))
    return write (({string})STR->wrap(SkShort(1)+" says to you: "+str,75,2)), 1;
  return 0;
}

public int SkEmote(mixed str)
{
  if (sk_in_shop(1))
    {
      if (stringp(str))
        tell_object(TP,({string})STR->wrap(SkShort(1)+" "+str,75,0));
      else
	if (pointerp(str)&&sizeof(str)==2)
	  {
	    tell_object(TP,({string})STR->wrap(SkShort(1)+" "+str[0],75,0));
	    tell_room(ME,({string})STR->wrap(SkShort(1)+" "+str[1],75,0),({TP}));
	  }
      return 1;
    }
  return 0;
}

public void shopkeeper_refresh(object ob)
{
  ob->AddId(SHOPKEEPER_ID);
  ob->AddDefence(DT_PSYCHO,100); // Noone can shock them ;-)
  ob->AddResistance(ST_PSYCHO,100);
}

public void dustbin_refresh(object ob)
{
  object *inv;
  int a;

  ob->SetMaxWeight(1<<29);
  ob->AddId(DUSTBIN_ID);
  if (time()-({int})ob->QueryCreationTime()<10)
    show_room(ME,
      ({
        SkShort(1)+" turns around and places a " + ({string})ob->QueryShort() +
          " into the corner of the shop.\n",
        "Something happens.\n"
      }) );
  inv = all_inventory(ob);
  a = sizeof(inv);
  inv = inv - filter(inv, #'query_once_interactive /*'*/);
  if (a)
  {
    tell_room(ME, "Crunching noises emmanate from the "
      + ({string})ob->QueryShort() + ".\n");
    map_objects(inv, "remove");
    inv = inv - ({ 0 });
    if (sizeof(inv))
    {
      map(inv, #'destruct /*'*/);
      inv = inv - ({ 0 });
    }
  }
}
