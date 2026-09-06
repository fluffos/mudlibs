/* /Obj/rope
**
** A generic rope.
**
**  Summer 94 [Suamor]
**  02-Nov-94 [Mateese] Nicened up a bit and documented.
*/

#include <config.h>
#include <rope.h>
#include <properties.h>
#include <moving.h>
#include <search.h>

inherit "std/thing";

#define TP this_player()
#define THIS this_object()

/*-------------------------------------------------------------------------*/

private nosave object tied_here;   // Objects the rope is tied to
private nosave object tied_there;
private nosave int pAllowTie2;     // Flag if two objects may bound together.
private nosave int sema;           // Prevents recursion in follow()
private nosave object storeenv;    // Room the rope is fixed in, if any.
private nosave mapping allowTOb;  // Allowed Details to tie the rope to
private nosave string whTOb;      // Detail rope is tied to

/*-------------------------------------------------------------------------*/

varargs void create() {
  ::create();
  AddId("rope");
  SetShort("a rope");
  SetLong("It's a sturdy rope made from hemp. You can see\n"+
          "nothing special about it.\n");
  SetValue(15);
  SetWeight(1000);
  tied_here = tied_there = pAllowTie2 = 0;
}

/*-------------------------------------------------------------------------*/

public int QueryAllowTie2 ()    { return pAllowTie2; }
public int SetAllowTie2 (int i) { return pAllowTie2 = i; }

/*-------------------------------------------------------------------------*/
public object * QueryTied()
{
   if (!QueryAllowTie2())
      return ({ tied_here, 0 });
   return ({ tied_here, tied_there });
}

public object *SetTied (mixed ob)
{
  if (!QueryAllowTie2()) {
    if (pointerp(ob))
      tied_here = ob[0];
    else
      tied_here = ob;
    return ({ tied_here, 0 });
  }
  if (pointerp(ob)) {
    tied_here = ob[0];
    tied_there = ob[1];
  }
  else if (tied_here)
    tied_there = ob;
  else
    tied_here = ob;
  return ({ tied_here, tied_there });
}

object * SetUntied(object ob)
{
  if (ob == tied_here) {
    tied_here = tied_there;
    tied_there = 0;
  }
  else
    tied_here = 0;
  return QueryTied();
}

/*-------------------------------------------------------------------------*/
public string MyShort()
{
   string ret;

   ret = "";
   if (tied_here && tied_here != THIS)
       ret = tied_here->QueryName() || tied_here->Short()
             || tied_here->Query("Fastening")[whTOb];

   if (tied_here && tied_there && tied_here != THIS && tied_there != THIS)
     ret += " and to "+(  tied_there->QueryName()
                        ||tied_there->Short()
                       || tied_there->Query("Fastening")[whTOb] );
   return ret;
}

public varargs string Short (string what)
{
  string rc;
  return ::Short(what)+((tied_here || tied_there) ? (" tied to "+MyShort()) : "");
}

public varargs string Long (string what)
{
  return  ::Long(what)
         +((tied_here || tied_there) ? ("It is tied to "+MyShort())+".\n" : "")
  ;
}

public string CheckNoMove() {
  if (   (tied_here || tied_there)
      && !(    (tied_here  && living(tied_here))
           || (tied_there && living(tied_there))
         )
     )
    return "The rope is still tied to "+MyShort()+".\n";
  return 0;
}

public mixed QueryNoGet()  { return ::QueryNoGet() || CheckNoMove(); }
public mixed QueryNoGive() { return ::QueryNoGive() || CheckNoMove(); }
public mixed QueryNoDrop() { return ::QueryNoDrop() || CheckNoMove(); }

public mapping AddFastening(mixed id, string descr)
{
  mapping objdet; // Details you can tie a rope to
  int i;

  if (!id) return objdet;
  if (stringp(id)) id = ({id});
  i = sizeof(id);
  if (!objdet=environment(TP)->Query("Fastening")) objdet = ([]);
  while (i--) {
    objdet[id[i]] = descr;
  }
  environment(TP)->Set("Fastening",objdet);
  return objdet;
}

/*-------------------------------------------------------------------------*/
public void follow (mixed dest, int method, mixed extra)

// Prevent a player leaving the room if he is tied to an object in the room.
// follow another player if he is tied to it.
{
  if (sema) return;
  sema = 1;

  if (tied_here && tied_there)
  {
    if (living(tied_here) && living(tied_there))
    {
       if (tied_here == TP)
          tied_there->move(dest,method,extra);
       else
          tied_here->move(dest,method,extra);
    }
    else if ((   (living(tied_here) && tied_there)
            || (living(tied_there) && tied_here))
           && dest != storeenv && dest != storeenv->Query("VisibleRoom")
          )
    {
      TP->move(storeenv,M_SILENT);
      write("You can't leave this room while beeing tied.\n");
      show(TP->QueryName()+" fails to leave the room still beeing tied.\n");
      sema=0;
      return;
    }
  }
  if (dest == storeenv->Query("VisibleRoom")) {
    /* Change the tied object from source to destination room */
    if (storeenv == tied_here) tied_here = find_object(storeenv->Query("VisibleRoom"));
    else if (storeenv == tied_there) tied_there = find_object(storeenv->Query("VisibleRoom"));
    storeenv=find_object(storeenv->Query("VisibleRoom"));
  }

  THIS->move(dest,M_SILENT,extra); /* move the rope :-) */
  sema = 0;
}

/*-------------------------------------------------------------------------*/

public void init()
{
  ::init();
  add_action("ftie"  , "tie");
  add_action("funtie", "untie");
}

/*-------------------------------------------------------------------------*/
public int TieTo (object ob)
{
  mixed rc;
  int allowTie2;
  string obd;

  allowTie2 = QueryAllowTie2();
  if (tied_here && (!allowTie2 || tied_there))
  {
    notify_fail("It is already tied to "+MyShort()+".\n", NOTIFY_NOT_VALID);
    return 1;
  }

  obd = ob->QueryName() || ob->Short()
        || ob->Query("Fastening")[whTOb];

  if ((rc = ob->Query(P_NO_TIE))) {
    notify_fail(stringp(rc) ? rc
                            : "You can't tie the "+::Short()+" to "+obd+".\n"
               , NOTIFY_NOT_VALID);
    return 2;
  }
  // Carried ropes get dropped
  if (environment() == TP)
    THIS->move(environment(TP),M_SILENT);

  storeenv = environment();
  ob->AddFollower(THIS);
  if (tied_here)
    tied_there = ob;
  else {
    tied_here = ob;
    SetNoGet(1);
  }
  return 0;
}

/*-------------------------------------------------------------------------*/
public int UntieFrom (object ob)

{
  string obd;
  mixed  rc;

  obd = ob->QueryName() || ob->Short()
        || ob->Query("Fastening")[whTOb];

  if (ob != tied_here && ob != tied_there) {
    notify_fail( "The "+::Short()+" is not tied to "+obd+".\n"
               , NOTIFY_NOT_VALID);
    return 1;
  }

  if ((rc = ob->Query(P_NO_UNTIE))) {
    notify_fail(stringp(rc) ? rc
                          : "You can't untie the "+::Short()+" from "+obd+".\n"
               , NOTIFY_NOT_VALID);
    return 2;
  }

  ob->RemoveFollower(THIS);
  if (tied_here == ob) {
    tied_here = tied_there;
    tied_there = 0;
    if (!tied_here) {
       SetNoGet(0);
       storeenv=0;
    }
  }
  else
    tied_there = 0;
  return 0;
}

/*-------------------------------------------------------------------------*/
public string dtie(string arg)
{
    allowTOb=environment(TP)->Query("Fastening");
    if  (allowTOb==([]) || !allowTOb || !member(allowTOb,arg)) return 0;
    return arg;
}

/*-------------------------------------------------------------------------*/
public int ftie (string arg)
{
  object ob;
  string t1, t2;

  if (   !arg
      || 2 != sscanf(arg, "%s to %s", t1, t2)
      || THIS != TP->WSearchEnvInv(t1)
     )
  {
    notify_fail("What do you want to tie?\n", NOTIFY_NOT_OBJ);
    return 0;
  }

  if (!(ob = TP->WSearchEnvInv(t2)) && !(whTOb=dtie(t2)))
  {
    notify_fail("What do you want to tie it to?\n", NOTIFY_NOT_VALID);
    return 0;
  }

  if (!ob && whTOb) ob=environment(TP);

  if (TieTo(ob))
    return 0;

  t1 = ob->QueryName() || ob->Short();
  if (t1=="nobody") t1=0;
  if (!t1 && sizeof(ob->Query("Fastening")))
    t1 = ob->Query("Fastening")[whTOb];
  else if (!t1 && !sizeof(ob->Query("Fastening")))
    t1 = "something";

  write("You tie "+::Short()+" to "+t1+".\n");
  show(TP->QueryName()+" ties "+::Short()+" to "+t1+".\n");

  return 1;
}

/*-------------------------------------------------------------------------*/
public int funtie (string arg)
{
  object ob;
  string t1, t2;

  if (   !arg
      || 2 != sscanf(arg, "%s from %s", t1, t2)
      || THIS != TP->WSearchEnvInv(t1)
     )
  {
    notify_fail("What do you want to untie?\n", NOTIFY_NOT_OBJ);
    return 0;
  }

  if (!(ob = TP->WSearchEnvInv(t2)) && !(whTOb=dtie(t2)))
  {
    notify_fail("From what do you want to untie?\n", NOTIFY_NOT_VALID);
    return 0;
  }

  if (!ob && whTOb) { write(whTOb+"\n"); ob=environment(TP); }

  if (UntieFrom(ob))
    return 0;

  write("You untie "+::Short()+" from "+(ob->Short()||ob->Query("Fastening")[whTOb])+".\n");
  show(TP->QueryName()+" unties "+::Short()+" from "+(ob->Short()||ob->Query("Fastening")[whTOb])+".\n");

  if (ob==environment()) whTOb=0;
  return 1;
}

/*************************************************************************/
