/*   A unit-thing  (Mateese, 10-Jul-1994)
**
** A simple thing of unit-style .. well, it's not completely simple :-)
*/

#include <properties.h>
#include <moving.h>

inherit "/std/unit";

/*----------------------------------------------------------------------------
** Initialize us 
*/

create() {
  string foo;
  int bar;

  ::create();

    /* The short description of 1 unit, the plural will have an 's'
    ** added at the end.
    ** The '@' will be replaced by some descriptive text.
    */
  Set(P_SHORT, "@tribble");

    /* The long description is also dynamic. */

   /* Each tribbles weighs 10 grams. */
 Set(P_WEIGHT_PER_UNIT, 10);

  
    /* Each tribble is 10 coins worth. */
  Set(P_VALUE_PER_UNIT, 10);

    /* By default this is only one tribble */
  Set(P_AMOUNT, 1);

    /* The ID */
  AddId("tribble");
  AddPluralId("tribbles");

    /* The mean part: when carried, the tribbles reproduce
    ** every 15 minutes.
    */
  if (sscanf(object_name(this_object()),"%s#%d", foo, bar) == 2)
    call_out ("_reproduce", 900);
}


/*----------------------------------------------------------------------------
** Return a random description string for the unit short description
** at every look.
*/

string Short(mixed what) {
  string rc, sh;
  int pos;

  sh = ::Short(what);
  pos = member(sh, '@');

  if (pos >= 0)
  {
    rc = "";
    switch(random(4)) {
    case 0: rc = "cosy ";     break;
    case 1: rc = "fluffy ";   break;
    case 2: rc = "hairy ";    break;
    case 3: rc = "chirping "; break;
    }
    sh = sh[0..pos-1]+rc+sh[pos+1..];
  }
  return sh;
}

/*----------------------------------------------------------------------------
** Give a longer description of the tribbles.
*/

QueryLong() {
  string rc;
  int val;

  rc = 
 "This is an example unit (/d/archwiz/common/lpc/exm/xunit.c).\n"
+"A tribble is a small cosy creature; touching it makes you feel happy.\n"
+"This bunch of tribbles weighs ";
  if ((val = Query(P_WEIGHT)) >= 100) 
    rc += ""+(val/1000)+"."+((val%1000)/10)+" kg";
  else rc += ""+val+" g";
  rc += " and is "+::QueryValue()+" worth.\n";
  return rc;
}

/*----------------------------------------------------------------------------
** When carried, reproduce.
*/

_reproduce() {
  object ob, env;
  int amount;

  /* Remove other pending call_outs */
  while(remove_call_out("_reproduce") >= 0);

    /* Are we carried ? */
  if ((env = environment()) && interactive(env)) {

      /* Clone the same amount of tribbles as we are */
    tell_object(env, "Your tribbles chirp.\n");
    ob = clone_object(blueprint(this_object()));
    amount = Query(P_AMOUNT);
    ob->Set(P_AMOUNT, Query(P_AMOUNT));

      /* move them all to us */
    ob->Set(P_LAST_AMOUNT, amount);

      /* If the move succeeds, this instance gets destructed.
      ** else the other one is superfluous.
      */
    if (ob->move(env) == ME_OK) 
      return;
    destruct(ob);
  }

  /* Either we aren't carried, or the reproduction failed:
  ** try again some time later
  */
  call_out ("_reproduce", 900);
}

/*--------------------------------------------------------------------------*/

