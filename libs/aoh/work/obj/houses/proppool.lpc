/*
** The store where the certificates are stored
** Author: Sique@Nightfall
** Update: Thragor@Nightfall, 25aug95
*/

#define SF(x) #'x //'
#define P_CAMEFROM "CameFrom" // where a player comes from
#define PO previous_object()
#define TP this_player()

#include <moving.h>
#include <rooms.h>
#include <stdrooms.h>
#include <properties.h>
#include "/sys/houses.h"

inherit "/std/store";

public mixed *houses, *sold;

public int go_back(string str)
{
  string dest;

  if (str) return 0;
  if(str||!query_once_interactive(TP)) return 0;
  dest = ({string})TP->Query(P_CAMEFROM)||VOID;
  TP->move(dest,M_GO,"into a shop");
  TP->Set(P_CAMEFROM,0);
  return 1;
}

public void create()
{
  int    i;
  (::create());
  SetIntShort("Makler's Store");
  SetIntLong(
    "You are standing in the store of the agency.\n"
    "Here you can find certificates for all houses the estate agent\n"
    "wants to sell.\n");
  if(file_size(PROPERTYFILE+".o")>0)
    restore_object(PROPERTYFILE);
  else
    {
      houses = ({});
      sold = ({});
    }
  for(i = sizeof(houses); i--; )
    AddItem(houses[i][5]||CERT_DUMMY,REFRESH_NONE,
      ([
        "Homedir":houses[i][0],
        "Exitverb":houses[i][1],
        "Exitpath":houses[i][2],
        P_VALUE:houses[i][3],
        P_SHORT:"property certificate for a house "+
                (houses[i][4]?"in "+houses[i][4]:"somewhere")
      ]));
  AddExit("shop",SF(go_back));
}

public void notify_enter(object oldenv, mixed method, mixed extra)
{
  if (query_once_interactive(PO))
    PO->Set(P_CAMEFROM,object_name(oldenv));
  return (::notify_enter(oldenv, method, extra));
}

private int exist(mixed *house,string homedir,string exit,string path)
{
  return    house[0] == homedir
         && house[1] == exit
         && house[2] == path;
}

public varargs int AddProperty(string homedir, string exit, string path,
                               int price, string location, string cert_file)
{
  object cert;

  if (!houses)
    houses = ({({homedir,exit,path,price,location,cert_file})});
  else
    {
      if (sizeof(filter(houses,SF(exist),homedir,exit,path)))
        return 0;
      houses += ({({homedir,exit,path,price,location,cert_file})});
    }
  AddItem(cert_file||CERT_DUMMY,REFRESH_NONE,
    ([
      "Homedir":homedir,
      "Exitverb":exit,
      "Exitpath":path,
      P_VALUE:price,
      P_SHORT:"property certificate for a house "+
              (location?"in "+location:"somewhere")
    ]));
  save_object(PROPERTYFILE);
  return 1;
}

public int RemoveProperty(string homedir, string exit, string path)
{
  mixed *to_delete;

  if (  !houses
      ||!sizeof(houses))
    return 0;
  if(!sizeof(to_delete =
	     filter(houses,SF(exist),homedir,exit,path)))
    return 0;
  houses -= to_delete;
  save_object(PROPERTYFILE);
  remove();
  if (this_object()) destruct(this_object());
  return 1;
}

public void notify_leave(mixed dest, mixed method, mixed extra)
{
  if (query_verb()!="buy")
    return;
  if(!sold)
    sold = ({});
  sold += ({({({string})previous_object()->QueryHomedir(),
              ({string})previous_object()->QueryExitverb(),
              ({string})previous_object()->QueryExitpath(),
              capitalize(getuid(TP)),
              ctime()})});
  (::notify_leave(dest,method,extra));
  RemoveProperty(({string})previous_object()->QueryHomedir(),
		 ({string})previous_object()->QueryExitverb(),
		 ({string})previous_object()->QueryExitpath());
}

public mixed *QueryAllProperties() { return houses; }

public mixed *QuerySold() { return sold; }
