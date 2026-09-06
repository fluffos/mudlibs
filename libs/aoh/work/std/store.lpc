/*
** /std/store
**
** The store of a shop, related to the basic shop file.
**
**   01-Oct-92 [m] adapted.
**   18-Apr-95 [t] adapted to new /std/shop
**   18-Aug-95 [t] Auto-Destruct of items in the store
**                 and performance of GroupInventory increased
** [m] Mateese
** [t] Thragor
*/

inherit "/std/container/restrictions";
inherit "/std/room";
inherit "/std/thing/moving";

#include <secure/wizlevels.h>
#include <properties.h>
#include <moving.h>
#include <search.h>
#include <money.h>

#define P_TIMESTAMP "TimeStamp" // Time when item entered the store
#define DESTRUCT_TIME 3*60      // Time when an item shall be destructed
#define MAX_ITEMS 6 // if there are more than 6 items of the same file-
                    // name (not clones of /std) in the store, new items
                    // get destructed
#define DESTROY_CHANCE 	90
#define ME this_object()
#define TP this_player()
#define SF(x) #'x //'
#define SYM(x) 'x //'

#define D(x,y) "/players/thragor/lib/debug"->debug("thragor",x,y)

private nosave mapping Pinventory;
// Contains the inventory in the form:
// (["<short without article>#<value>#<size>":({<fitting objects>})])
/*--------------------------------------------------------------------------*/

public int leave_store(string str)
{
  object env;
  if (str
      ||!TP
      ||environment(TP)!=ME) return 0;
  if (!env=environment(ME))
    return ({int})TP->move("/std/void",M_GO,"to nowhere");
  else
    return ({int})TP->move(env,M_GO,"to the shop");
}

public void create()
{
  "restrictions"::create();
  "room"::create();
  SetIntShort ("In a Store");
  SetIntLong("You are inside a store. An exit marked 'shop' leads out.\n");
  SetTransparency(0);
#if 0
  /* Creator is a string, not an object, and if it was a now-destructed
   * clone, the attempt to 'load' it implicitely will fail.
   * What shall it log anyway? I don't understand it... [Mateese]
   */
  log_file("STORES",this_object()->QueryCreator()+" creates a store.\n"
    "interactive: "+(this_object()->QueryCreator())->QueryCreator()+".\n"
    "Creator: "
    +((this_object()->QueryCreator())->QueryCreator())->QueryCreator()+".\n\n");
#endif
  SetNoGet(1); // uh oh, don't steal the store!
  AddExit("shop",SF(leave_store));
}

private int check_timestamp(object ob)
{
  int ts;
  return (ts = ({int})ob->Query(P_TIMESTAMP)) && (ts+DESTRUCT_TIME<time());
}

protected void check_idle_out()
{
  map_objects(filter(all_inventory(),SF(check_timestamp)),"remove");
}

public varargs void reset()
{
  if (sizeof(filter(all_inventory(ME),
    lambda(({SYM(ob)}),
      ({SF(&&),
        ({SF(query_once_interactive),
          SYM(ob)
        }),
        ({SF(<),
          ({SF(query_user_level),
            SYM(ob)
          }),
          LVL_WIZARD
        })
      })))))
    return;
  check_idle_out();
  // Check for items which are too long in the store
  return (::reset());
}

public varargs string Short()
{
  return "";
}

public varargs string Long()
{
  return "";
}

/*
** The store handles what will be displayed to a player.
** The list returned looks like this:
**   ([<objectp>:<calc_price>])
*/

public mixed SearchObjects(string pattern)
{
  mixed l;

  switch(lower_case(pattern||"all"))
  {
   case "small":
     l = filter(all_inventory(ME)
                     , lambda(({'o}), ({#'==, PSIZE_SMALL
                                    , ({#'call_other, 'o, "Query", P_SIZE})})
                     ));
     break;
   case "normal":
   case "medium":
     l = filter(all_inventory(ME)
                     , lambda(({'o}), ({#'==, PSIZE_NORMAL
                                    , ({#'call_other, 'o, "Query", P_SIZE})})
                     ));
     break;
   case "large":
     l = filter(all_inventory(ME)
                     , lambda(({'o}), ({#'==, PSIZE_LARGE
                                    , ({#'call_other, 'o, "Query", P_SIZE})})
                     ));
     break;
   case "generic":
     l = filter(all_inventory(ME)
                     , lambda(({'o}), ({#'==, PSIZE_GENERIC
                                    , ({#'call_other, 'o, "Query", P_SIZE})})
                     ));
     break;
   default:
     l = Locate(pattern,SM_MULTI|SM_IGNLIGHT);
     break;
  }
  if (mappingp(l))
    return m_values(l);
  return l;
}

public int CheckList(object ob)
{
  return sizeof(({string})ob->QueryShort()||"")
         && !({int})ob->Query(P_NOSELL)
         &&!({int})ob->QueryIsPlayer();
}

public int CheckId(object ob, string pattern)
// Called in filter to get all items which identify themself to the given
// id.
{
  if (!CheckList(ob)) return 0;
  switch(lower_case(pattern))
    {
     case "small":
      return ({int})ob->QuerySize()==PSIZE_SMALL;
     case "normal":
     case "medium":
      return ({int})ob->QuerySize()==PSIZE_NORMAL;
     case "large":
      return ({int})ob->QuerySize()==PSIZE_LARGE;
     case "generic":
      return ({int})ob->QuerySize()==PSIZE_GENERIC;
     default:
      return member(SearchObjects(pattern)||({}),ob)!=-1;
    }
  return member(SearchObjects(pattern)||({}),ob)!=-1;
}

protected string build_short(object ob)
{
  if (environment()&&({int})environment()->QueryMarket())
    return strip_article(({string})ob->Short()||"")+"#"+
           ({int})ob->Query("shopprice")+"#"+
           ({int})ob->QuerySize();
  return strip_article(({string})ob->Short()||"")+"#"+
         (({int})ob->QueryAmount()?(({int})ob->QueryValue()/({int})ob->QueryAmount()):
	  ({int})ob->QueryValue())+"#"+
         ({int})ob->QuerySize();
}

protected mapping AddInventory(object ob)
{
  string short;
  if (!catch(load_object(STATISTIC)))
    STATISTIC->AddItem(ob);
  if (!CheckList(ob))
    return Pinventory;
  if (!Pinventory)
    Pinventory = ([]);
  if (!member(Pinventory,short = build_short(ob)))
    Pinventory[short] = ({ob});
  else
    Pinventory[short]+= ({ob});
  return Pinventory;
}

protected mapping RemoveInventory(object ob)
{
  string short;
  if (!Pinventory) return 0;
  if (!member(Pinventory,short = build_short(ob))) return Pinventory;
  Pinventory[short]-=({ob});
  if (!sizeof(Pinventory[short]))
    m_delete(Pinventory,short);
  return Pinventory;
}

public mapping QueryInventory()
{
  return Pinventory;
}

public mapping GroupInventory(object *obs)
{
  int i;
  mapping res;
  string *shorts;

  i = sizeof(shorts = map(obs,SF(build_short)));
  res = ([]);
  while(i--)
    if (member(Pinventory||([]),shorts[i]))
      res[shorts[i]] = Pinventory[shorts[i]];
  return res;
}

public object *GetEqual(object ob)
// Returns all objects in the store, which have the same
// shortdescription and the same value as <ob> in an array.
{
  return (Pinventory||([]))[build_short(ob)]||({});
}

public void notify_enter(mixed from,int method,mixed extra)
{
  int i,des;
  object *inv,po;
  po = previous_object();
  if (query_once_interactive(po)
      && !IS_IMMORTAL(po))
    {
      for(inv = all_inventory(ME), i = 0; i < sizeof(inv); i++)
        if (!living(inv[i]) && random(100) < DESTROY_CHANCE)
          call_out(symbol_function("remove",inv[i]),1);
      write(
        "It looks like someone has quickly removed most items from the store\n"
        "as the shopkeeper was killed.\n");
    }
  if (({string})po->QueryCreator()!=object_name(ME)
      &&!query_once_interactive(po))
  // Don't destruct own articles or items
    {
      po->Set(P_TIMESTAMP,time());
      if (sizeof(GetEqual(po))>MAX_ITEMS)
	des = 1;
    }
  if ((!({string})po->Short() || "" == ({string})po->Short()) && !query_once_interactive(po))
    des = 1;
  if (des)
    call_out(symbol_function("remove",po),1);
  else
    AddInventory(po);
  return (::notify_enter(from,method,extra));
}

public void notify_leave(mixed to,int method,mixed extra)
{
  RemoveInventory(previous_object());
  return (::notify_leave(to,method,extra));
}

public status id_store()
{
  return 1;
}

public int id(string str)
{
  if (IS_IMMORTAL(TP))
    return (lower_case(str)=="store")||(::id(str));
  return (::id(str));
}
