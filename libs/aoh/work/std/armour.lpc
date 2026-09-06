/*
 * std/armour.c
 *
 * A luxury frontend to the generic armour.
 * The real work is done in std/armour/combat
 *
 * Version 4.1 native compatible
 * Version 4.2 Pepel fixed lots of things
 *             Mateese made it plushy
 * Version 4.3 Cadra updated SetStandard a bit (calculates the weight now
 *             09jan97
 * Version 4.4 Thragor changed SetStandard that it fits to AddItem, i. e.
 *             it now accepts an array as first argument, telling what
 *             armour-type the armour has, which ac and which size, 21jan97
 * Version 4.5 Cadra changed AT_ARMOUR to AT_MAIL
 */

#include <combat.h>
#include <moving.h>
#include <classes.h>
#include <properties.h>

inherit "std/thing";
inherit "/std/armour/combat";

#define TO this_object()

public int QueryOldCombat() { return 1;}

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

public mixed QueryHelpMsg() {
  mixed rc;
  mixed armour_type;

  rc = ::QueryHelpMsg();
  if (!rc)
  {
    armour_type = QueryArmourType();
    if (-1 == member(({ AT_GLOVES, AT_BOOTS, AT_TROUSERS }), armour_type))
      rc = "This "+strip_a(QueryShort())+" protects";
    else if (armour_type == AT_GLOVES)
      rc = "These gloves protect";
    else if (armour_type == AT_TROUSERS)
      rc = "These trousers protect";
    else
      rc = "These boots protect";
    rc += " against attacks while being worn.\n";
    if (QueryNumberHands() == 1)
      rc += "You need one hand to wear it.\n";
    else if (QueryNumberHands() > 1)
      rc += "You need "+itoa(QueryNumberHands())+" hands to wear it.\n";
  }
  return rc;
}

public varargs int QueryValue(mixed flag)
{
  if (flag) return (::QueryValue());
  return modifyValue(::QueryValue());
}

public varargs string Long(string what) { return modifyLong(::Long(what)); }
public varargs string InvShort (string what) {
  int q;
  string rc;
  q = QueryQuality();
  SetQuality(100);
  rc = ::InvShort(what);
  SetQuality(q);
  return modifyInvShort(rc);
}

public varargs string Short (string what) {
  return modifyShort(::Short(what));
}

void init() {
  thing::init();
  combat::init();
}

int AddDefence (int type, int value) {
  int size;
  if ((size=sizeof(defences)) <= type)
    defences += allocate(type-size+1);
  return defences[type] = value;
}

int GetDefence (int type) {
  if (sizeof(defences) > type)
    return defences[type];
  return 0;
}

int SetDefence (int type, int value) { return AddDefence(type,value); }

protected int helpcalc(int ac,int size) {
  int i;
  switch (size) {
    case PSIZE_LARGE: i=3; break;
    case PSIZE_SMALL: i=1; break;
    default:          i=1;
    }
  if (ac < 3) return i;
  if (ac < 5) return i+1;
  return i+2;
}

varargs int SetStandard (mixed armour_type, int ac, int size)
  // armour_type may also be an array of the form:
  // ({armour_type, ac, size})
{
  int at;

  // spread array to the values (if armour_type is an array)
  if (pointerp(armour_type))
    return apply(#'SetStandard /*'*/,armour_type);

  if (!VALID_ARMOUR_TYPE(armour_type)) return 0;
  at = member(({ AT_MAIL, AT_HELMET, AT_RING, AT_GLOVES, AT_CLOAK, AT_BOOTS, AT_SHIELD,
     AT_TROUSERS, AT_AMULET, AT_BELT })
		    , armour_type);
  if (at < 0)
  {
    log_file("COMPAT", sprintf("%O: %O->SetStandard(string %O,)\n"
	    , TO, previous_object(), armour_type));
    at = member(
    ({ "armour", "helmet", "ring", "gloves", "cloak", "boots", "shield" })
		    , armour_type );
  }
  SetShort ( ({ "an armour"
	      , "a helmet"
	      , "a ring"
	      , "some gloves"
	      , "a cloak"
	      , "some boots"
	      , "a shield"
	      , "a pair of trousers"
	      , "an amulet"
	      , "a belt"
	     })[at]
	   );
  if (-1 == member(({ AT_GLOVES, AT_BOOTS, AT_TROUSERS }), armour_type))
    SetLong("An ordinary "+strip_a(QueryShort())+".\n");
  else if (armour_type == AT_GLOVES)
    SetLong("A pair of ordinary gloves.\n");
  else if (armour_type == AT_TROUSERS)
    SetLong("A pair of ordinary trousers.\n");
  else
    SetLong("A pair of ordinary boots.\n");
  SetSize(size);
  SetResetQuality(99);
  if (armour_type == AT_SHIELD)
    SetNumberHands(ac>0?ac:1);
  SetWeight ( ({ 2500 * helpcalc(ac,size)
	       ,  500 * helpcalc(ac,size)
	       ,   10 * helpcalc(ac,size)
	       ,   80 * helpcalc(ac,size)
	       ,  900 * helpcalc(ac,size)
	       , 1000 * helpcalc(ac,size)
	       , 1500 * helpcalc(ac,size)
	       ,  700 * helpcalc(ac,size)
	       ,   10 * helpcalc(ac,size)
	       ,  100 * helpcalc(ac,size)
	      })[at]
	   );
  SetValue ( ({  50+ 500*ac //  50..3050
	      ,  20+ 400*ac //  20.. 820
	      , 100+1000*ac // 100..1100
	      ,  20+ 450*ac //  20.. 920
	      ,  50+ 500*ac //  50..1050
	      ,  30+ 300*ac //  30.. 630
	      , 100+ 600*ac // 100..1300
	      ,  20+ 450*ac //  20.. 920
	      ,  50+1000*ac //  50..1050
	      ,  20+ 450*ac //  20.. 920
	     })[at]
	   );
  // Values approved by VAW of Finance, Thragor, 16jan97
  SetArmourType(armour_type);
  SetAPperQP(ac+1);
  SetAC(ac);
  return 1;
}

void create () {
  thing::create();
  combat::create();
  AddClassId(C_ARMOUR);
  SetStandard(AT_HELMET, 1);
}
