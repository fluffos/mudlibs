/* std/armour/combat.c
 *
 * combat related things of armour.
 */

#include <properties.h>
#include <combat.h>
#include <config.h>
#include <search.h>
#include <equipment.h>

inherit "/std/equipment";

int id(string str);
void AddId(string id);
void RemoveId(string id);
string QueryShort();

#define TO   this_object()
#define TP   this_player()

private int     pAPperQP;
nosave object owner, wear_ob, def_ob, remove_ob;
nosave int worn, weaponhands;
nosave mixed armourtype;
nosave int *defences;

public int QueryAPperQP ()             { return pAPperQP; }
public int SetAPperQP (int i)          { return pAPperQP = i; }

object SetWorn(object o) { worn = !!o; return owner = ::SetWorn(o); }

int SetWeaponHands(int h) { return weaponhands = SetNumberHands(h); }
int QueryWeaponHands() { return QueryNumberHands(); }

object SetWearObj (object ob) { return wear_ob = ob; }
object SetRemoveObj (object ob) { return remove_ob = ob; }
object SetDefendObj (object ob) { return def_ob = ob; }
object QueryWearObj () { return wear_ob; }
object QueryRemoveObj () { return remove_ob; }
object QueryDefendObj () { return def_ob; }

int wear(object own) { return !Wear(objectp(own) ? own : TP,1); }
int unwear () { return !Unwear(); }

public varargs mixed Wear (object living, int is_armour) {
  object obj;
  if (objectp(obj = QueryWearObj()) && !({int})obj->CheckWear(living))
    return EQ_FORBID;
  return ::Wear(living, is_armour);
}

public varargs int Unwield (int flags) {
  object obj, liv;
  liv = QueryWorn();
  if (   objectp(liv)
      && objectp(obj = QueryRemoveObj())
      && !({int})obj->CheckRemove(liv)
     )
    return EQ_FORBID;
  return ::Unwield(flags);
}

void create() {
  SetUsage(EQM_WEAR);
  defences = ({ 0 });
  seteuid(getuid(TO)); // to be able to load the formula object.
}

void init() {
  add_action( "fwear", "wear" );
  add_action( "funwear", "unwear");
  add_action( "funwear", "remove");
}

int SetAC (int i) { return (defences = ({ i }))[DT_INTR]; }
varargs int QueryAC () { return defences[DT_INTR]; }

mixed QueryArmourType() { return armourtype; }
mixed SetArmourType(mixed a) {
  if (VALID_ARMOUR_TYPE(a)) {
    if (armourtype && intp(armourtype))
      RemoveId( ([ AT_MAIL:     "mail"
                 , AT_HELMET:   "helmet"
                 , AT_AMULET:   "amulet"
                 , AT_RING:     "ring"
                 , AT_GLOVES:   "gloves"
                 , AT_CLOAK:    "cloak"
                 , AT_BOOTS:    "boots"
                 , AT_SHIELD:   "shield"
                 , AT_TROUSERS: "trousers"
                 , AT_BELT:     "belt"
                ])[armourtype]
              );
    else if (armourtype && stringp(armourtype))
      RemoveId(armourtype);
    armourtype=a;
    if (intp(armourtype))
      AddId( ([ AT_MAIL:     "mail"
              , AT_HELMET:   "helmet"
              , AT_AMULET:   "amulet"
              , AT_RING:     "ring"
              , AT_GLOVES:   "gloves"
              , AT_CLOAK:    "cloak"
              , AT_BOOTS:    "boots"
              , AT_SHIELD:   "shield"
              , AT_TROUSERS: "trousers"
              , AT_BELT:     "belt"
             ])[armourtype]
           );
    else {
      log_file("COMPAT", sprintf("%O: %O->SetArmourType(string %O,)\n"
            , TO, previous_object(), armourtype));
      AddId(armourtype);
    }
    return armourtype;
  }
  return 0;
}

int *SetDefences (mixed v) {
  if (intp(v)) v = ({ v });
  else if (!sizeof(v)) v = ({ 0 });
  return defences = v;
}
int *QueryDefences () { return defences; }

//---------------------------------------------------------------------------
public void DegradeArmour ( mapping soaked, mapping damage, object weapon
                          , int success, int target)

// Degrade the armours quality

{
  int s, apq;

  s = soaked["TOTAL"];
  apq = QueryAPperQP();
  if (apq && ((s >= apq) || !random(200)))
    SetQuality(QueryQuality() - ((s/apq) || 1));
}

/* CalcDefend (enemy, damage, damage_type)
 * Defend (enemy, damage, damage_type)
 *
 * Compute the defence against a specific damage and return it.
 * It will be subtracted from the damage by the living itself.
 * Calc_Defend just calculates the value w/o caring for def_ob.
 * Defend() is the fun to call for defense.
 */

int CalcDefend (object enemy, int damage, int dtype) {
  int ac,*def;

  def = QueryDefences();
  ac = QueryAC();
  if (dtype && dtype < sizeof(def)) ac += def[dtype];
    /* Magic formula, copied from weapon::CalcDamage(). */
  return ac;
}

int Defend (object enemy, int damage, int dtype) {
  object d_ob;
  int rc;
  d_ob = QueryDefendObj();
  if (d_ob)
    rc = ({int})d_ob->DefendHit(enemy, damage, dtype);
  else
    rc = CalcDefend (enemy, damage, dtype);
  return (rc*(QueryQuality()+5))/105;
}
