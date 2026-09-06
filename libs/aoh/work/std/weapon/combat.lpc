/* /std/weapon/combat
 *
 * The combat functionality of the generic weapon.
 *
 * Version 4.1 compat/native compatible by Marvin & Deepthought
 * Version 4.2 Pepel fixed many things
 */

#include <properties.h>
#include <combat.h>
#include <living.h>
#include <search.h>
#include <config.h>
#include <equipment.h>

#define TO   this_object()
#define TP   this_player()

inherit "/std/equipment";

string QueryShort();
void AddId(string id);
void RemoveId(string id);
int QueryWC();

private int pWPperQP;
nosave int wc, weaponhands, damtype;
nosave string weapontype;
nosave object owner, hit_ob, wield_ob, unwield_ob; // *sigh*
nosave int wielded;

void create() {
  SetUsage(EQM_WIELD);
  seteuid(getuid(TO)); // to be able to load the formula object.
}

public int QueryWPperQP ()             { return pWPperQP; }
public int SetWPperQP (int i)          { return pWPperQP = i; }

object SetWielded(object o) { wielded = !!o; return owner = ::SetWielded(o); }

object SetHitObj (object ob) {  return hit_ob = ob; }
object SetWieldObj (object ob) {  return wield_ob = ob; }
object SetUnwieldObj (object ob) {  return unwield_ob = ob; }
object QueryHitObj () {  return hit_ob; }
object QueryWieldObj () {  return wield_ob; }
object QueryUnwieldObj () {  return unwield_ob; }

public void DegradeWeapon ( mapping soaked, mapping damage, int success
			  , int target)
{
  int s, wpq;

  s = soaked["TOTAL"];
  wpq = QueryWPperQP();
  if (wpq && ((s >= wpq) || !random(200)))
    SetQuality(QueryQuality() - ((s/wpq) || 1));
}

int wield (object own) { return !Wield(objectp(own) ? own : TP, 1); }
int unwield()          { return !Unwield(); }

public varargs mixed Wield (object living, int is_weapon) {
  object obj;
  if (objectp(obj = QueryWieldObj()) && !({int})obj->CheckWield(living))
    return EQ_FORBID;
  return ::Wield(living, is_weapon);
}

public varargs int Unwield (int flags) {
  object obj, liv;
  liv = QueryWielded();
  if (   objectp(liv)
      && objectp(obj = QueryUnwieldObj())
      && !({int})obj->CheckUnwield(liv)
     )
    return EQ_FORBID;
  return ::Unwield(flags);
}


/*
 * QueryDamageType
 *
 * This is called from living/combat. If we have a hit object, ask that for
 * the damage type. If that is 0, use our own damtype.
 */

int QueryDamageType() {
  object h_ob;
  int t;
  h_ob=QueryHitObj();
  if (h_ob && (t = ({int})h_ob->WeaponHitType())) return t;
  return damtype;
}

/* CalcDamage(enemy)
 *
 * This function calculates the damage this weapon would normally do on
 * the enemy, w/o respect of any hit_ob.
 * Call QueryDamage() for the real one.
 */

int CalcDamage (object enemy) {
  /* A somewhat magic formula for determining the damage done */
  if (owner)
  {
    int rc, hands, stat;
    switch (QueryDamageType()) {
	    case DT_BLUDGEON : stat = ({int})owner->QueryStr()/2; break;
      case DT_SLASH    : stat = (3*({int})owner->QueryStr() + ({int})owner->QueryDex())/8; break;
      case DT_PIERCE   : stat = (({int})owner->QueryStr() + ({int})owner->QueryDex())/4; break;
      default          : stat = 0; break;
    }
    rc = ( random(2*QueryWC()) + random(stat) + 1 );
    hands = QueryNumberHands();
    if (hands > 1)
      rc = (rc * (50 + 50 * hands)) / 100;
    return rc;
  }
  return 0;
}

/*
 * QueryDamage(object enemy)
 *
 * This function returns damage the weapon does.
 * As argument, we get the enemy which is attacked. This allows for
 * special abilities of the weapon against certain types (races) of
 * monsters. QueryDamage() should return the actual damage the weapon
 * wants to do (already randomized and with all boni).
 * If you want to redefine this, write your own CalcDamage() and
 * call ::QueryCalc() to get a first idea of the damage done.
 */

int QueryDamage(object enemy) {
  object h_ob;
  int amount;
  h_ob=QueryHitObj();
  if (h_ob) amount = ({int})h_ob->WeaponHit(enemy);
  else amount = CalcDamage(enemy);
  return (amount*(QueryQuality()+5))/105;
}

/*
 * Properties
 */

varargs int QueryWC () { return wc; }
int SetWC (int w) { return wc = w; }

int QueryDamType () { return damtype; }
int SetDamType (int dtype) { return damtype = dtype; }

string QueryWeaponType() { return weapontype; }
string SetWeaponType(string w) {
  if (VALID_WEAPON_TYPE(w)) {
    if (weapontype)
      RemoveId(weapontype[2..]);
    weapontype = w;
    AddId(weapontype[2..]);
    SetDamType (([
	    WT_SWORD:    DT_SLASH
	  , WT_AXE:      DT_SLASH
	  , WT_WHIP:     DT_SLASH
	  , WT_KNIFE:    DT_PIERCE
	  , WT_RAPIER:   DT_PIERCE
	  , WT_SPEAR:    DT_PIERCE
	  , WT_INFANTRY: DT_PIERCE
	  , WT_CLUB:     DT_BLUDGEON
	  , WT_HAMMER:   DT_BLUDGEON
	  , WT_STAFF:    DT_BLUDGEON
	  , WT_CHAIN:    DT_BLUDGEON
	 ])[weapontype]
	);
  }
  return weapontype;
}

int SetWeaponHands(int h) { return weaponhands = SetNumberHands(h); }
int QueryWeaponHands() { return ::QueryNumberHands(); }

object QueryOwner() { return QueryWielded(); }
