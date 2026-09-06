/* living/combat.c
**
** The combat routines for living objects are here.
**
** This file is (c) Nightfall 1992 and (c) One Step Beyond 1997.
** You may use of it whatever you like, but you should put a reference
** in your file if you do it.
**
** Version 4.0 first version of new living object
** Version 4.1 Pepel has fixed many things
** Version 4.2 Pepel converted to new QueryFoo() convention
**   07-Oct-92 [Mateese] spell casting implemented
**   02-Aug-94 [Deepthought] Activate heartbeat only if necessary.
**   17-Nov-97 [Softbyte] Old Stats/Skills removed
**
** CHANGES
**  05/28/98 Mica Fixed a typo/bug inside the auto-attack function
**                (ratattacks you!)
**-----------------------------------------------------------------
** 11/02/98 Magictcs Added support for legs in the same way like hands
**                   (but only for Set/Query - no other usage presently - maybe
**                   later!)
*/

#include <config.h>
#include <properties.h>
#include <living.h>
#include <combat.h>
#include <combattune.h>
#include <secure/wizlevels.h>
#include <driver/object_info.h>
#include <attributes.h>
#include <msgclass.h>

#define ME this_object()
#define PREV previous_object()
#define HERE environment(ME)
#define TP this_player()
#define TI this_interactive()
#define ENV environment
#define SF(x) #'x //' Emacs-Hack

/*#include "log.h"*/

public varargs object QueryRaceObj(int reload); // std/living/description
public int CanSeeLiving(object liv); // std/living/description
public void AddHeart(mixed hook); // std/living/heart
public void RemoveHeart(mixed hook); // std/living/heart
public int QueryCon(); // std/living/stats
public int QueryDex(); // std/living/stats
public int QueryStr(); // std/living/stats
public int QueryInt(); // std/living/stats
#ifdef NF
public int UseStat(string name, int diff); // std/living/stats
#endif
public varargs int DoDamage (int damage, int gentle); // std/living/body
public varargs int AddXP (int xp,int delay); // std/living/body
public object *QueryFollowers(); // std/thing/moving
int QueryIsNPC(); // std/living/description
int QueryIsPlayer(); // std/living/description
public string QueryName(); // std/living/description
public varargs mixed Query(string pn, int sc); // std/base
public int QueryLevel();         // std/living/description
public int QueryXP(); // std/living/body
public int QueryHP(); // std/living/body
public int QueryGhost(); // std/living/description
public int combat_heartbeat();

nosave mixed delaymsg;
nosave int   delaybeats;
nosave mixed *enemies, *hunters;
nosave mixed *defences;
nosave mixed *weapons;
nosave mixed *hands;
nosave mixed *legs;
nosave object *armours;
nosave object friendobj;
nosave mixed  equipobj;
nosave object last_wield_ob;
nosave object last_wear_ob;

nosave object magicobj;  /* Denotes the object for doing magic */

nosave int aggressive, a_ness;

// -----------------------------------------------------------------------------
// Add-, Get-, Remove-, Set- and Query-Functions
// -----------------------------------------------------------------------------

public mixed QueryCombatDelay()
{
  return delaybeats;
}

public mixed SetCombatDelay(int time, string s)
{
  if (time < 1)
    time = 0, delaymsg = 0;
  else
  {
    if (stringp(s))
      delaymsg = s;
    AddHeart(HEART_COMBAT);
  }
  return delaybeats = time;
}

public string QueryCombatDelayMsg() { return delaymsg; }
public string SetCombatDelayMsg(string s) { return delaymsg = s; }

public mixed QueryStunned() { return QueryCombatDelay(); }
public mixed SetStunned(int i)
{
  // Compat code
  int cdl;
  string cmsg;

  cdl = QueryCombatDelay();
  if (cdl < 1)
    cdl = 0;
  if (i > 0)
    cmsg = "You are stunned.\n";
  if (magicobj && delaymsg)
    cmsg = delaymsg;
  return SetCombatDelay(cdl+i, cmsg);

#if 0
  // Original code
  return SetCombatDelay(i, "You are stunned.\n");
#endif
}

public int SetAC(int i) { return (defences = ({ i }))[0]; }
public varargs int QueryAC() { return defences[0]; }

public void AddDefence(int type, int val)
{
  if (sizeof(defences) <= type)
    defences += allocate(type-sizeof(defences)+1);
  defences[type] = val;
}

public int GetDefence(int type)
{
  if (type == DT_INTR)
    return QueryAC();
  if (sizeof(defences) > type)
    return defences[type];
  return 0;
}

public int SetAggressive(int a) { return aggressive = a; }
public int QueryAggressive() { return aggressive; }
public int SetAttackChance(int a) { return a_ness = a; }
public int QueryAttackChance() { return a_ness; }
public object *QueryEnemies() { return enemies; }
private object *SetEnemies(object *e)
{
  AddHeart(HEART_COMBAT);
  return enemies = e;
}

public status AddEnemy(object e)
{
  object *f;
  if (!enemies || !pointerp(enemies))
    enemies = ({});
  if (   !e
      || (enemies && member(enemies,e)!=-1)
      || ({int})e->QueryGhost()
      || e == ME
     )
    return 0;
  enemies += ({e});
  f = QueryFollowers()||({});
  if (member(f,0)!=-1) f-=({0});
  map_objects(f,"NotifyAddEnemy",e);
  AddHeart(HEART_COMBAT);
  return 1;
}

public status RemoveEnemy(object e)
{
  object *f;
  if (enemies && member(enemies,e)!=-1)
    {
      enemies-=({e});
      f = QueryFollowers()||({});
      if (member(f,0)!=-1) f-=({0});
      map_objects(f,"NotifyRemoveEnemy",e);
      if (!sizeof(enemies) && !delaybeats)
        RemoveHeart(HEART_COMBAT);
      return 1;
    }
  return 0;
}

public object *QueryHunters() { return (hunters||({}))+({}); }
public object *SetHunters(object *h) { return hunters = h; }
private status AddHunter(object e)
{
  object *f;
  if (!hunters || !pointerp(hunters))
    hunters = ({});
  if (   !e
   || (hunters && member(hunters,e)!=-1)
     )
    return 0;
  hunters += ({e});
  f = QueryFollowers()||({});
  if (member(f,0)!=-1) f-=({0});
  map_objects(f,"NotifyAddHunter",e);
  return 1;
}

public status RemoveHunter(object e)
{
  object *f;
  if (hunters && member(hunters,e)!=-1)
    {
      hunters-=({e});
      f = QueryFollowers()||({});
      if (member(f,0)!=-1) f-=({0});
      map_objects(f,"NotifyRemoveHunter",e);
      return 1;
    }
  return 0;
}

public int *SetDefences(int *d) { return defences = d; }
public int *QueryDefences() { return (defences||({}))+({}); }
public object *SetArmours(object *d) { return armours = d; }
public object *QueryArmours() { return (armours||({}))+({}); }
public object *SetWeapons(object *w) { return weapons = w; }
 /* use with extreme care ! */
public object *QueryWeapons() { return (weapons||({}))+({}); }
public mixed SetHands(mixed h) { return hands = h; }       /* use with care */
public mixed SetLegs(mixed l) { return legs= l; }       /* use with care */
public mixed QueryHands() { return (hands||({}))+({}); }
public mixed QueryLegs() { return (legs||({}))+({}); }
public object SetCastObj(object m) { return magicobj = m; }
public object QueryCastObj() { return magicobj; }
public object SetFriendObj(object o) { return friendobj = o; }
public object QueryFriendObj() { return friendobj; }


// -----------------------------------------------------------------------------
// Misc. Functions
// -----------------------------------------------------------------------------

public void StartHunting(object e)
{
  if (RemoveEnemy(e) && e)
    {
      AddHunter(e);
      msg_object( e, CMSG_COMBAT_SELF, "You are hunted by "+(QueryName()||"someone")+".\n");
    }
}

public void StopHunting(object e)
{
  RemoveEnemy(e);
  RemoveHunter(e);
}

public void StopAllHunting()
{
  int i;
  object e;
  if (enemies)
    for (i=sizeof(enemies); i--; )
      if (e=enemies[i])
      {
        StopHunting(e);
        e->StopHunting(ME);
      }
  if (hunters)
    for (i=sizeof(hunters); i--; )
      if (e=hunters[i])
      {
        StopHunting(e);
        e->StopHunting(ME);
      }
}

void StopAllCombat() { return StopAllHunting(); }

public void StopAttack()
{
  map((enemies||({}))+(hunters||({}))-({0}),SF(StopHunting));
}

public int IsFriend(object victim)
  // By default: don't attack other NPCs if being a NPC
  // or don't attack players if being a player
{
  return    (QueryIsNPC() && ({int})victim->QueryIsNPC())
         || (QueryIsPlayer() && ({int})victim->QueryIsPlayer());
}


public status CheckAutoAttack (object victim)
{
  if (!victim || victim == ME)
    return 0;
  if (!({int})victim->QueryGhost()
      && ((    QueryAggressive()
           &&  a_ness > random(1000)
           && (friendobj ? !({int})friendobj->IsFriend(victim)
                         : !IsFriend(victim) )
          )
          || (member(hunters||({}),victim)!=-1)
         )
      && CanSeeLiving(victim)
      && (  !query_once_interactive(victim)
         || !IS_IMMORTAL(victim)
         || ({int})victim->Query(P_NOWIZ) )
     )
    return 1;
  return 0;
}

public void Kill(object ob)
  // Kill - start the combat
{
  if (   objectp(ob)
      && AddEnemy(ob)
     )
    {
      msg_object( ob, CMSG_COMBAT_SELF|MMSG_DIRECT,
    capitalize((Query(P_NAME)||Query(P_SHORT)||"Someone"))+
    " attacks you!\n" );
      AddHeart(HEART_COMBAT);
    }
}

public status CalcIsHit(object attacker)
{
  int oppdex, chance;
  if (!attacker)
    return 0;
  oppdex = ({int})attacker->QueryDex() - QueryDex();
  if (oppdex > 30)
    oppdex = 30;
  else if (oppdex < -30)
    oppdex = -30;
  if (oppdex < 0)
    chance = 65 + 2 * oppdex;
  else
    chance = 65 + oppdex;
  if (chance < random(100))
    return 0;
  return 1;
}

public object do_hit(mixed x)
  // Hit the opponent. Return the one we attacked.
{
  int damage, damage_type;
  string how, hows;
  object enemy;
  string xshort;

  if (!enemies || !sizeof(enemies)) return 0;
  enemy = enemies[random(sizeof(enemies))];
  if (!enemy || ({int})enemy->QueryHP() < 0 )
    {
      StopHunting(enemy);
      return 0;
    }
  if (!present(enemy) && enemy != environment())
    {
      StartHunting(enemy);
      return 0;
    }

  if (objectp(x))
    {
      xshort = ({string})x->QueryShort(); /* counter self-destructing weapons */
      damage = ({int})x->QueryDamage(enemy);
      damage_type = ({int})x->QueryDamageType();
      if (({int})x->QueryOldCombat())
  {
    switch (damage_type)
      {
      case DT_BLUDGEON: how = " charge on "; hows = " charges on "; break;
      case DT_PIERCE: how = " stab at "; hows = " stabs at "; break;
      case DT_SLASH: how = " slash at "; hows = " slashes at "; break;
      default: how = " attack "; hows = " attacks ";
      }
    msg_object( ME, CMSG_COMBAT_SELF,
        "You"+how+({string})enemy->QueryName() +" with "+xshort);
    msg_object( enemy, CMSG_COMBAT,
        "  "+capitalize(QueryName())+hows+"you with "+xshort);
    msg_say( CMSG_COMBAT_OTHERS,
     "  "+capitalize(QueryName())+hows+({string})enemy->QueryName()+" with "
     +xshort,({ME, enemy}));
  }
    }
  else
    {
      /* Magic formula for hand attacks */
      damage = random(3*hands[x][HAND_WC]/5+QueryDex()/5 + QueryStr()/5);
      damage_type = DT_BLUDGEON;
      msg_object( ME, CMSG_COMBAT_SELF, "You attack "+({string})enemy->QueryName()
    +" with "+hands[x][HAND_SHORT]);
      msg_object(enemy, CMSG_COMBAT,
   "  "+capitalize(QueryName())+" attacks you with "
   +hands[x][HAND_SHORT]);
      msg_say( CMSG_COMBAT_OTHERS,
         "  "+capitalize(QueryName())+" attacks "+({string})enemy->QueryName()+" with "
         +hands[x][HAND_SHORT],({ME, enemy}));
    }

  if (enemy)
    {
      damage = ({int})enemy->Defend(damage, damage_type, objectp(x)?x:0);
      AddXP(damage);
    }
  return enemy;
}

public void Attack()
{
  object w;
  int i,h;

  /* Perhaps do attack chatting */
  if (Query(P_ACHAT_CHANCE)) ME->DoAttackChat();

  /* Scan all weapons and free 'hands' */
  for (i = sizeof(weapons) + 1; --i;)
    if (w = weapons[<i]) do_hit(w);
  h=sizeof(hands);
  for (i = h + 1; --i;) if (!objectp(hands[<i][HAND_WEAPON])) do_hit(h - i);
}

public varargs int Defend(int dam, int dam_type, mixed weapon)
{
  object attacker;
  mixed *xtras, ac;
  string whats, how;
  mixed what;
  int i,oppdex,chance;

  AddHeart(HEART_COMBAT);
  attacker = this_player() || previous_object();
  if (   (   !weapon
          || !intp(weapon)
          || !(weapon&DEFEND_F_NOLIV)
         )
      && AddEnemy(attacker)
     )
  {
#ifdef LOG_KILLS
    if (   interactive(ME)
      && TP
      && interactive(TP)
      && TP != ME
      && (!IS_IMMORTAL(ME) || !IS_IMMORTAL(TP)))
    {
      object attacker_ob;
      string mylevel, klevel, kname, rname;

      if (i = query_user_level(ME)) mylevel = "w"+i;
      else mylevel = QueryLevel()+"/"+(({int})RACEMASTER->XPtoLevel(QueryXP()));
      attacker_ob = TP;
      if (attacker_ob)
      {
        if (   !(kname = ({string})attacker_ob->QueryRealName())
          && !(kname = ({string})attacker_ob->QueryName())
          && !(kname = ({string})attacker_ob->QueryShort()))
          kname = "<invis>";
        if (!({int})attacker_ob->QueryIsPlayer())
          kname += " ["+object_name(attacker_ob)+"]";
        else if ((rname = ({string})attacker_ob->QueryRealName()) && kname != rname)
          kname += " ["+rname+"]";
        if (   query_once_interactive(attacker_ob)
          && (i = query_user_level(attacker_ob)))
          klevel = "w"+i;
        else klevel = ({int})attacker_ob->QueryLevel()+"/"
          +(({int})RACEMASTER->XPtoLevel(({int})attacker_ob->QueryXP()));
      }
      else klevel = kname = "???";

      write_file("/log/KILLER", ctime(time())+" "+kname+
       "("+klevel+") attacked "+
       ({string})ME->QueryRealName()+"("+mylevel+")"
       +(query_verb() ? (" by '"+query_verb()+"'") : "")
       +((ENV() && ({int})ENV()->QueryKillZone()) ? " (LEGAL)" : "")
       +"\n");
    }
#endif
  }

  /* my own intrinsic defences */
  ac = QueryAC();
  if (dam_type) ac += GetDefence(dam_type);

  /* Check armour */
  xtras = ({});

  if (!weapon || !intp(weapon) || !(weapon&DEFEND_F_NOLIV))
    chance = CalcIsHit(attacker);
  else
    chance = 1;

  if ( !chance && dam_type <= DT_CONVENTIONALS)
  {
    dam = 0;
    ac = 0;
    chance = 0;
  }

  for (i = sizeof(armours); dam && i--;)
  {
    mixed xtra;
    object a;

    if (a = armours[i])
    {
      xtra = ({mixed})a->Defend(attacker, dam, dam_type);
      if (pointerp(xtra))
        oppdex = xtra[0];
      else
        oppdex = xtra;
      if (oppdex < 1)
        oppdex = 0;
      else
        oppdex = 1 + random(oppdex);
      a->DegradeArmour((["TOTAL":oppdex]), ([]), weapon, 100, 0);
    }
    else { armours -= ({a}); i--; continue; } /* clean it on the fly */
    if (pointerp(xtra))
    {
      ac += xtra[0];
      xtras += xtra;
    }
    else ac += xtra;
  }
  if (dam && (dam -= ac) < 1 && dam_type >= 0 && dam_type <= DT_CONV)
    dam = 1;

  if (objectp(weapon))
    weapon->DegradeWeapon((["TOTAL":random(ac)+1]), ([]), 100, 0);

  if (objectp(weapon) && !({int})weapon->QueryOldCombat())
  {
    what = ({mixed})weapon->NotifyHit(attacker, ME, (["TOTAL":dam])
         , 100, (dam*100)/(QueryHP()||1));
    if (pointerp(what))
    {
      tell_object(TP, what[0]);
      if (ME != TP) tell_object(ME, what[1]);
      show_room(ENV(TP), what[2], ({ TP, ME }) );
    }
  }
  else if (   (!weapon || !intp(weapon) || !(weapon&DEFEND_F_NOMSG))
     && dam_type <= DT_CONVENTIONALS)
  {
    switch (dam)
    {
      case 0: what = " miss "; whats = " misses "; how = "";
        break;
      case 1: what=" tickle ";whats=" tickles ";how=" in the stomach";
        break;
      case 2..3: what = " graze "; whats = " grazes "; how = "";
        break;
      case 4..5: what = " hit "; whats = " hits "; how = "";
        break;
      case 6..10: what = " hit "; whats = " hits "; how = " hard";
        break;
      case 11..20: what = " hit "; whats = " hits "; how = " very hard";
        break;
      case 21..30: what = " smash "; whats = " smashes ";
        how = " with a bone crushing sound";
        break;
      default: what=" massacre ";whats=" massacres ";how=" to small fragments";
    }
    if (dam) { what = " and"+what; whats = " and"+whats; }
    else { what = ", but"+what; whats = ", but"+whats; }
    msg_object( attacker, CMSG_COMBAT_SELF, what+QueryName()+how+".\n");
    msg_object( ME, CMSG_COMBAT, whats+"you"+how+".\n");
    msg_say( CMSG_COMBAT_OTHERS, whats+QueryName()+how+".\n", ({ME, attacker}));
  }
  else if (objectp(weapon)) /* conventional weapon with magical damage type */
    weapon->DidDamage(attacker, dam, dam_type);

  /* oh, why do I need all these tests ?? - because it's buggy ! */
  if (xtras && pointerp(xtras))
    for (i = sizeof(xtras) + 1; --i;)
      if (stringp(xtras[<i])) tell_room(HERE, xtras[<i]);

  ac = environment();
  i = DoDamage(dam);
  if (   environment() != ac /* We ran away, so don't hunt attacker */
      && (   (!weapon || !intp(weapon))
          && attacker != ME
         )
     )
     RemoveEnemy(attacker);
  return i;
}


/* called by the weapon when it wants to be wielded. return 1 on success */
public int wieldme(object ob)
{
  int i, h;

  if (ob == last_wield_ob)
    return 1;

  if (QueryGhost())
    {
      msg_write( CMSG_GENERIC, "You can't do that in your present state.\n");
      return 0;
    }

  last_wield_ob = ob;
  if (!({int})ob->wield(ME))
    return last_wield_ob = 0;
  last_wield_ob = 0;

  /* somehow, arrays are returned by reference, ... */
  h = ({int})ob->QueryWeaponHands();
  for (i = sizeof(hands); i-- && h;) if (!hands[i][HAND_WEAPON]) h--;

  if (h)
    {
      msg_write(CMSG_GENERIC, "You don't have enough free hands!\n");
      return 0;
    }
  return 1;
}

public void unwieldme(object ob)
{
  int i;
  for (i = sizeof(hands); i--;)
    if (hands[i][HAND_WEAPON] == ob) hands[i][HAND_WEAPON] = 0;
  weapons -= ({ob});
}


public int wearme(object ob)
{
  int i;
  mixed at;
  if (ob == last_wear_ob)
    return 1;
  last_wear_ob = ob;
  i = ({int})ob->wear(ME);
  last_wear_ob = 0;
  if (!i) return 0;
  at = ({mixed})ob->QueryArmourType();
  if (!VALID_ARMOUR_TYPE(at))
    {
      msg_write( CMSG_GENERIC,
        ({string})ob->QueryShort()+" does not have a valid armour type.\n");
      log_file("INVALID_ARMOUR",
         ctime(time())+" "+({string})ME->QueryRealName()+" "+object_name(ob)
         +" UID "+getuid(ob)+" EUID "+geteuid(ob)+"\n");
      return 0;
    }

  for (i = sizeof(armours); i--;)
    if (armours[i] && ({mixed})armours[i]->QueryArmourType() == at)
      {
  if (armours[i] == ob)
    return 1;
  msg_write( CMSG_GENERIC, "You are already wearing "+add_a(at)+".\n");
  return 0;
      }
  if (AT_SHIELD == at)
    {
      int h;
      if ((h = ({int})ob->QueryWeaponHands()) < 1) h = 1;
      for (i = sizeof(hands); i-- && h;) if (!hands[i][HAND_WEAPON]) h--;
      if (h) { msg_write( CMSG_GENERIC,
    "You don't have enough free hands!\n"); return 0; }
    }
  return 1;
}

public void removeme(object ob)
{
  int i;
  for (i = sizeof(hands); i--;) /* search for shields */
    if (hands[i][HAND_WEAPON] == ob) hands[i][HAND_WEAPON] = 0;
  armours -= ({ob});
}

// --- Upwards compatibility

public mixed SetEquipObj(mixed o)
{
  if (pointerp(o))
    return equipobj = o - ({ ME, QueryRaceObj() });
  return equipobj = o;
}

public mixed QueryEquipObj(int sc)
{
  mixed * rc;

  if (sc)
    return equipobj;
  rc = ({ ME, QueryRaceObj() });
  return (rc+((pointerp(equipobj) ? equipobj : ({ equipobj }))-rc)) - ({ 0 });
}

public object *AddEquipObj(object o)
{
  if (!equipobj)
    return equipobj = ({ o });
  if (objectp(equipobj))
    return equipobj = (({ equipobj })-({ o, 0 })) + ({ o });
  return equipobj = (equipobj-({ o, 0 })) + ({ o });
}

public mixed RemoveEquipObj(mixed o)
{
  if (!equipobj)
    return 0;
  if (objectp(equipobj))
    {
      if (equipobj == o)
  equipobj = 0;
      return equipobj;
    }
  return equipobj -= ({ o, 0 });
}

public status AddWeapon(object ob)
{
  if (!weapons)
    weapons = ({});
  if (!({int})ob->Query(P_NOWIELD) && member(weapons,ob) == -1)
  {
    weapons += ({ ob });
    ob->SetWielded(ME);
    return 1;
  }
  return 0;
}

public void RemoveWeapon(object ob, int flags)
{
  if (-1 != member(weapons, ob))
    {
      weapons -= ({ ob });
      if (PREV != ob)
  ob->Unwield(flags);
      ob->SetWielded(0);
    }
}

public status AddArmour(object ob)
{
  int i;
  mixed at;
  string sh;
  if (({int})ob->Query(P_NOWEAR))
    return 0;
  at = ({mixed})ob->QueryArmourType();
  if (!armours)
    armours = ({});
  for (i = sizeof(armours); i--;)
    if (   armours[i]
        && ({mixed})armours[i]->QueryArmourType() == at
        && (sh = ({string})armours[i]->Short()) && sh != ""
       )
      {
        msg_write( CMSG_GENERIC, "You are already wearing "+sh+".\n");
        return 0;
      }
  if (member(armours,ob)==-1)
    armours += ({ ob });
  ob->SetWorn(ME);
  return 1;
}

public void RemoveArmour(object ob, int flags)
{
  int i;
  for (i = sizeof(hands); i--;) /* search for shields */
    if (hands[i][HAND_WEAPON] == ob)
      hands[i][HAND_WEAPON] = 0;
  if (PREV != ob)
    ob->Unwear(flags);
  ob->SetWorn(0);
  armours -= ({ob});
}

public void Ungrip(object ob)
{
  int i;
  for (i = sizeof(hands); i--;)
    if (hands[i][HAND_WEAPON] == ob) hands[i][HAND_WEAPON] = 0;
}

public int Grip(object ob)
{
  int i, h, free;

  free = 0;
  for (i = sizeof(hands); i--;)
    if (!hands[i][HAND_WEAPON])
      free++;
    else if (ob == hands[i][HAND_WEAPON])
      return 1;

  if ((h = ({int})ob->QueryNumberHands()) < 1)
    h = 0;

  if (h > free)
    return 0;

  for (i = sizeof(hands) + 1; --i && h;)
    if (!hands[<i][HAND_WEAPON])
      {
  hands[<i][HAND_WEAPON] = ob;
  h--;
      }
  return 1;
}

public int combat_heartbeat()
  // Since combat and spell casting are mutual exclusive, we also
  // deal with the latter here.
  // We call the Attack() function if there is a reason to attack
  // someone. There are several reasons:
  // - I'm currently attacked by someone.
{
  int got_delay;
  got_delay = 0;
  if (delaybeats > 0)
  {
    got_delay = 1;
    delaybeats--;
    if (delaybeats & 1)
    {
      if (stringp(delaymsg))
        write(delaymsg);
      else if (!magicobj)
        msg_write( CMSG_COMBAT_SELF, "You are unconscious.\n");
      else
        msg_write( CMSG_COMBAT_SELF, "You continue to cast the spell.\n");
    }
    if (delaybeats < 1)
    {
      delaymsg = 0;
      delaybeats = 0;
      if (!magicobj)
        msg_write( CMSG_COMBAT_SELF,"You regain your full conscience.\n");
    }
  }

  /* Check enemies in the case the monster does nothing but special
   * attacks.
   */
  if (enemies)
  {
    object enemy;
    int i;
    if (member(enemies,0)) enemies -= ({0});
    for (i = sizeof(enemies); i--; )
    {
      enemy = enemies[i];
      if (!enemy || ({int})enemy->QueryHP() < 0)
        StopHunting(enemy);
      else if (   (!present(enemy))
        || (query_once_interactive(enemy) && !interactive(enemy)) )
        StartHunting(enemy);
    }
  }
  /* No reason to continue doing heart beats because of combat */
  if (magicobj && !({int})magicobj->CastOn())
    return 1;
  if ((!enemies || !sizeof(enemies)) && !delaybeats)
    return 0;
  if (!got_delay)
    Attack();
  return 1;
}

public void create()
{
  aggressive = 0;
  hands = weapons = enemies = hunters = armours = ({});
  defences = ({0});
  a_ness = 1000;
  friendobj = 0;
}

public void init()
{
  int delay;

  if (CheckAutoAttack(this_player()))
  {
      /* We decided to kill this player. Now how fast can we react? */
#ifdef NF
    UseStat(A_INT, 0);
    UseStat(A_DEX, 0);
#endif
    delay = 6 - (QueryInt()*STAT_SCALE+QueryDex()*STAT_SCALE)/50;

    if (delay < 1)
      Kill(this_player());
    else
      call_out(SF(Kill), delay, this_player());
  }
}

// -----------------------------------------------------------------------------
// Commands
// -----------------------------------------------------------------------------

public int stop_hunting_mode(string arg)
{
  StopAttack();
  write("OK.\n");
  return 1;
}
