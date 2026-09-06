/*---------------------------------------------------------------------------
** /obj/friendship
**
** A ring showing deep friendship, while also being an example how
** equipment objects are programmed.
** Originally programmed by Blackheart.
**---------------------------------------------------------------------------
*/


#include <config.h>
#include <properties.h>
#include <moving.h>
#include <equipment.h>

inherit "/std/thing";
inherit "/std/equipment";

#define THIS this_object()
#define TP   this_player()
#define ENV  environment()

//---------------------------------------------------------------------------

public int    isBound;            // Has the ring been used at all?
public string myName, otherName;  // Who are the friends?
public string timeBound;          // When did it happen?

private object sigother;

//---------------------------------------------------------------------------

public int QueryAreFriends()    { return isBound; }
public int SetAreFriends(int i) { return isBound = i; }

public string * QueryNames () { return ({ myName, otherName }); }
public string * SetNames(string * n) {
  myName = n[0];
  otherName = n[1];
  return QueryNames();
}

public string QueryFriendTime() { return timeBound; }
public string SetFriendTime(string t) { return timeBound = t; }

public mixed QueryAutoObject () {
  return ({ QueryAreFriends(), QueryNames(), QueryFriendTime() });
}

public void SetAutoObject (mixed * data) {
  SetAreFriends(data[0]);
  SetNames(data[1]);
  SetFriendTime(data[2]);
}

//---------------------------------------------------------------------------

public string QueryReadMsg () {
  string *n, msg;

  if (!QueryAreFriends())
    return "You can offer friendship to a person using this ring.\n";

  n = QueryNames();
  if (sizeof(n) > 2)
    msg = implode(n[0..<2], ", ");
  else
    msg = "";
  msg += " and "+n[<1]+" found together on "+QueryFriendTime();
  return sprintf("%-75=s", msg)+"\n";
}

public mixed QueryNoDrop() {
  return QueryAreFriends() ? "You won't drop your precious ring.\n" : 0;
}

public mixed QueryNoSell() {
  return QueryAreFriends() ? "You won't sell your precious ring.\n" : 0;
}

public mixed QueryNoGive() {
  return QueryAreFriends() ? "You won't give your precious ring away.\n" : 0;
}

public string QueryExtralook() {
  return (QueryAreFriends() && QueryWorn())
         ? (capitalize(TP->QueryPronoun())+" is a close friend of "
            +(QueryNames()[1])+".\n")
	   : 0;
}

//---------------------------------------------------------------------------

public void create() {
  ::create();
  SetUsage(EQM_WEAR);
  SetShort("a ring of friendship");
  SetLong(
"This is a beautiful ring of friendship. It looks quite expensive.\n"
"There is something engraved on the ring you can read.\n" 
         );
  AddId("ring");
  AddId("ring of friendship");
  AddAdjective("friendship");
  SetValue(1000);
  isBound = 0;
  myName = otherName = "nobody";
  timeBound = "not yet";
}

//---------------------------------------------------------------------------

public void init () {
  thing::init();
  equipment::init();
  add_action("fpropose", "offer");
  add_action("faccept", "accept");
  add_action("floose", "loose");
}

public varargs int move (mixed dest, int method, mixed extra) {
  int rc;
  rc = thing::move(dest, method, extra);
  if (rc == ME_OK)
    inform_move(dest, method, extra);
  return rc;
}

public varargs int remove() {
  inform_move(0, M_DESTRUCT);
  return thing::remove();
}

// Normally one would also do:
//   public int QueryValue()         { return modifyValue(::QueryValue()); }
//   public string Long(string what) { return modifyLong(::Long(what)); }
// but this ring can't degrade.

public varargs string InvShort (string what) { 
  return modifyInvShort(::InvShort(what)); 
}

//---------------------------------------------------------------------------

public varargs void NotifyWear (object by, object which, int is_armour)
{
  string *n;

  if (QueryAreFriends())
  {
    n = QueryNames();
    tell_object(by, "You get a warm feeling as you wear your ring.\n");
    show(capitalize(n[0])+" wears a friendship ring from "
         +capitalize(n[1])+".\n");
  }
}

public varargs void NotifyUnwear (object by, object which, int is_armour)
{
  string *n;

  if (QueryAreFriends())
  {
    n = QueryNames();
    tell_object(by, "You feel bleak as you remove the ring.\n");
    show(capitalize(n[0])+" removes a friendship ring from "
         +capitalize(n[1])+".\n");
  }
}

//---------------------------------------------------------------------------
public int fpropose (string arg)
{
  object player;

  if (!arg)
    return 0;

  if (!sscanf(arg, "friendship to %s", arg))
  {
    notify_fail("Offer friendship to whom?\n", NOTIFY_NOT_OBJ);
    return 0;
  }

  if (QueryAreFriends())
  {
    notify_fail("Two friendships with one ring? No.\n", NOTIFY_NOT_CMD);
    return 0;
  }

  if (!(player = find_player(arg)))
  {
    notify_fail("Can't find player '"+arg+"'.\n", NOTIFY_NOT_VALID);
    return 0; 
  }

  SetNames(({0, capitalize(TP->QueryRealName())}));
  sigother = TP;
  if (ME_OK != move(player))
    raise_error("Move of ring failed\n");

  write("You offer a friendship ring to "+capitalize(arg)+".\n");
  tell_object(player,
capitalize(TP->QueryRealName())+" offers a close friendship to you!\n"
+"You receive a nice ring and may now accept the friendship.\n");

  return 1;
}

//---------------------------------------------------------------------------
public int faccept (string arg)
{
  object ring2;
  string *n;

  if (!arg || !sigother || QueryAreFriends())
    return 0;
  
  arg = norm_id(arg);
  if (    arg != "ring" && arg != "the ring"
       && arg != "friendship" && arg != "the friendship"
     )
  {
    notify_fail("You could 'accept the friendship'.\n", NOTIFY_NOT_CMD);
    return 0;
  }
  n = QueryNames();
  n[0] = capitalize(TP->QueryRealName());
  SetNames(n);
  SetFriendTime(ctime(time()));
  ring2 = clone_object(blueprint(THIS));
  ring2->SetNames(({ n[1], n[0] }));
  ring2->SetFriendTime(QueryFriendTime());
  ring2->SetAreFriends(1);
  if (ME_OK != ring2->move(sigother))
    raise_error("Move of ring2 failed\n");
  SetAreFriends(1);
  TP->SetTitle("is a close friend of "+n[1]);
  sigother->SetTitle("is a close friend of "+n[0]);
  Wear(TP);
  ring2->Wear(sigother);
  show(n[0]+" wears a friendship ring from "+n[1]+".\n");
  sigother = 0;
  write("(you can loose the friendship anytime)\n");
  return 1;
}

//---------------------------------------------------------------------------
public int floose (string arg) 
{
  if (!arg || !QueryAreFriends())
    return 0;
  
  arg = norm_id(arg);
  if (arg != "friendship" && arg != "the friendship")
  {
    notify_fail("You could 'loose the friendship'.\n", NOTIFY_NOT_CMD);
    return 0;
  }
  Unwear();
  write(
"As you go to loosen your friendship with "+QueryNames()[1]+" an\n"+
"angel appears from the heavens and takes your ring...\n"
       );
  remove();  
  return 1;
}

/***************************************************************************/
