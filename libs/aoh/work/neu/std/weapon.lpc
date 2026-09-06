/*---------------------------------------------------------------------------
** std/weapon
**
** Compatibility object, quick and dirty.
**---------------------------------------------------------------------------
*/

#include <equipment.h>
#include "/neu/sys/combat.h"
#define THIS this_object()

inherit "neu/obj/weapon";

object owner, hit_ob, wield_ob, unwield_ob; // *sigh*
int wielded, weaponhands;

public int QueryOldCombat() { return 1;}

object SetWielded(object o) { wielded = !!o; return owner = ::SetWielded(o); }

object SetHitObj (object ob) {  return hit_ob = ob; }
object SetWieldObj (object ob) {  return wield_ob = ob; }
object SetUnwieldObj (object ob) {  return unwield_ob = ob; }
object QueryHitObj () {  return hit_ob; }
object QueryWieldObj () {  return wield_ob; }
object QueryUnwieldObj () {  return unwield_ob; }

int SetStandard (string type, int wc) { SetType(type, wc); return 1; }
int wield (object own) { return !Wield(own,1); }
int unwield()          { return !Unwield(); }

public varargs mixed Wield (object living, int is_weapon) {
  object obj;
  if (objectp(obj = QueryWieldObj()) && !obj->CheckWield(living))
    return EQ_FORBID;
  return ::Wield(living, is_weapon);
}

public int Unwield () {
  object obj, liv;
  liv = QueryWielded();
  if (   objectp(liv) 
      && objectp(obj = QueryUnwieldObj()) 
      && !obj->CheckUnwield(liv)
     )
    return EQ_FORBID;
  return ::Unwield();
}

int CalcDamage (object enemy) {
  mapping dam;
  dam = ::QueryDamage()||([]);
  if (!owner || sizeof(dam) < 1)
    return 0;
  return random(dam[m_indices(dam)[0]])+random(owner->QueryStr())+1;
}

/* mixed */ QueryDamage (object enemy) 
{
  object obj;

  if (!enemy)
    return ::QueryDamage();
  if (objectp(obj = QueryHitObj())) 
    return (int)obj->WeaponHit(enemy);
  return CalcDamage(enemy);
}

public mapping Damage (object victim, int success) {
  object obj;
  int t;
  mapping dam;

  dam = ::Damage(victim, success);
  if (!(   objectp(obj = QueryHitObj()) 
         && (t = (int)obj->WeaponHit(victim)))
     )
    t = CalcDamage(victim);
  dam[m_indices(dam)[0]] = t;
  return dam;
}

int QueryDamageType() {
  object obj;
  int t;
  mapping dam;

  if (   objectp(obj = QueryHitObj()) 
      && (t = (int)obj->WeaponHitType())
     )
    return t;
  dam = ::QueryDamage()||([]);
  if (sizeof(dam) < 1)
    return 0;
  return m_indices(dam)[0];
}

int QueryWC () { return QueryClass(); }
int SetWC (int w) { return SetClass(w); }

int QueryDamType () { 
  mapping dam;

  dam = ::QueryDamage()||([]);
  if (sizeof(dam) < 1)
    return 0;
  return m_indices(dam)[0];
}

int SetDamType (int dtype) {
  mapping dam;

  dam = ::QueryDamage()||([]);
  dam[dtype] = QueryClass();
  SetDamage(dam);
  return dtype;
}

int SetWeaponHands(int h) { return weaponhands = SetNumberHands(h); }
int QueryWeaponHands() { return QueryNumberHands(); }

object QueryOwner() { return QueryWielded(); }


