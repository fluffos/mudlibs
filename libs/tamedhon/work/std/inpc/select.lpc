// MorgenGrauen MUDlib
//
// inpc/select.c -- Beste Ausruestung suchen
//
// $Id: select.c,v 3.6 1997/02/05 14:02:03 Rochus Exp $

#define NEED_PROTOTYPES

#include <thing.h>
#include <living.h>
#include <inpc.h>
#include <properties.h>
#include <combat.h>
#include <language.h>

#pragma strong_types

#define ME this_object()

mapping scan_objects(mixed src) {
  // Ermittelt zu jedem Typ (Waffe, Ruestungstyp...) alle Objekte diesen Typs
  // Gesucht wird: - Im Inventory, falls Objekt angegeben
  //               - Im Array, falls Array angegeben
  object *obs,ob;
  mapping res;
  mixed x;
  int i;

  if (mappingp(src))
    return src;
  res=([]);
  if (objectp(src))
    src=all_inventory(src);
  if (!pointerp(src))
    src=({src});
  for (i=sizeof(src)-1;i>=0;i--) {
    if (!objectp(ob=src[i]))
      continue;
    if (x=ob->QueryProp(P_ARMOUR_TYPE))
      ;
    else if (ob->QueryProp(P_WEAPON_TYPE))
      x=OT_WEAPON;
    else if (ob->QueryProp(P_COMBATCMDS))
      x=OT_COMBAT_OBJECT;
    else
      x=OT_MISC;
    if (!pointerp(obs=res[x]))
      obs=({});
    obs+=({ob});
    res[x]=obs;
  }
  return res;
}

mixed *find_object_by_type(mixed from, mixed typ) {
  // Findet all Objekte eines Typs, z.B. alle Waffen im Monster
  // <from> kann auch ein Mapping sein, das schon die mit scan_objects
  // erstellt Klassifikation enthaelt, damit diese nicht mehrfach
  // erstellt werden muss.
  mixed res;

  if (!mappingp(from))
    from=scan_objects(from);
  if (!mappingp(from) ||
      !pointerp(res=from[typ]))
    return ({});
  return res;
}

int eval_weapon(object ob) {
  return ob->QueryProp(P_WC);
}

object find_best_weapon(mixed from) {
  // Findet die beste Waffe
  int i,wc,bwc;
  object *res,ob,bob;
  
  if (!pointerp(res=find_object_by_type(from, OT_WEAPON)))
    return 0;
  bwc=-1;bob=0;
  for (i=sizeof(res)-1;i>=0;i--) {
    if (!objectp(ob=res[i])) continue;
    wc=eval_weapon(ob);
    if (wc>bwc) {
      bob=ob;
      bwc=wc;
    }
  }
  return bob;
}

varargs int wield_best_weapon(mixed from) {
  // Zueckt die beste Waffe.
  // Sollte mit command("zuecke_beste_waffe") aufgerufen werden,
  // damit this_player() richtig gesetzt wird.
  object ob,old;

  if (!from)
    from=ME;
  if (!objectp(ob=find_best_weapon(from)))
    return 0;
  if (objectp(old=QueryProp(P_WEAPON)) && old!=ob) {
    old->RemoveId(INPC_BEST_WEAPON_ID);
    old->DoUnwield();
  }
  if (!ob->id(INPC_BEST_WEAPON_ID))
    ob->AddId(INPC_BEST_WEAPON_ID);
  return ob->wield_me();
}

int eval_armour(object ob) {
  return ob->QueryProp(P_AC);
}

object find_best_armour(mixed from, mixed typ) {
  // Findet die beste Ruestung eines Typs
  int i,ac,bac;
  object *res,ob,bob;
  
  if (!pointerp(res=find_object_by_type(from, typ)))
    return 0;
  bac=-1;bob=0;
  for (i=sizeof(res)-1;i>=0;i--) {
    if (!objectp(ob=res[i])) continue;
    ac=eval_armour(ob);
    if (ac>bac) {
      bob=ob;
      bac=ac;
    }
  }
  return bob;
}

object *find_best_armours(mixed from) {
  // Findet die besten Ruestungen, die gleichzeitig getragen werden koennen
  mapping ol;
  object *res,ob;
  mixed *types,typ;
  int i;
  
  if (!mappingp(ol=scan_objects(from)))
    return ({});
  if (!pointerp(res=ol[AT_MISC]))
    res=({});
  types=m_indices(ol);
  for (i=sizeof(types)-1;i>=0;i--) {
    typ=types[i];
    if (VALID_ARMOUR_CLASS[typ]) { // anderer Armour-Typ ausser AT_MISC?
      ob=find_best_armour(from,typ);
      if (objectp(ob))
	res+=({ob});
    }
  }
  return res;
}

varargs int wear_best_armours(mixed from) {
  // Die besten Ruestungen werden angezogen
  // Sollte mit command("trage_beste_ruestungen") aufgerufen werden,
  // damit this_player() richtig gesetzt wird.
  object *na,*oa,*diff;
  int i;
  
  if (!from)
    from=ME;
  if (!pointerp(na=find_best_armours(from)))
    return 0;
  if (!pointerp(oa=QueryProp(P_ARMOURS)))
    oa=({});
  diff=oa-na;
  for (i=sizeof(diff)-1;i>=0;i--) {
    diff[i]->RemoveId(INPC_BEST_SHIELD_ID);
    diff[i]->DoUnwear();
  }
  diff=na-oa;
  for (i=sizeof(diff)-1;i>=0;i--) {
    if (diff[i]->QueryProp(P_ARMOUR_TYPE)==AT_SHIELD
	&& !diff[i]->id(INPC_BEST_SHIELD_ID))
      diff[i]->AddId(INPC_BEST_SHIELD_ID);
    diff[i]->do_wear("alles");
  }
  return 1;
}

int eval_combat_object(object ob, mapping vals, object enemy) {
  return 0;
}

varargs string
find_best_combat_command(mixed from, object enemy, mapping pref) {
  // Sucht den guenstigsten Befehl zur Benutzung einer Sonderwaffe heraus
  object *obs;
  mixed *ind,x,y,vul;
  string best;
  int i,j,max,val,mhp;
  
  if (!from)
    from=ME;
  if (!enemy)
    enemy=QueryEnemy();
  if (!mappingp(pref)) // bevorzugte Eigenschaften
    pref=([C_MIN:5,
	   C_AVG:10,
	   C_MAX:2,
	   C_HEAL:10
	   ]);
  best=0;max=-1;
  if (!pointerp(obs=find_object_by_type(from,OT_COMBAT_OBJECT)))
    return best;
  mhp=QueryProp(P_MAX_HP)-QueryProp(P_HP);
  if (objectp(enemy))
    vul=enemy->QueryProp(P_RESISTANCE_STRENGTHS);
  if (mhp<0) mhp=0;
  for (i=sizeof(obs)-1;i>=0;i--) {
    if (!objectp(obs[i])) continue;
    if (!mappingp(x=obs[i]->QueryProp(P_COMBATCMDS))) continue;
    ind=m_indices(x);
    for (j=sizeof(ind)-1;i>=0;i--) {
      if (!stringp(ind[j])) continue;
      y=x[ind[j]];
      if (mappingp(y)) {
	if (val=y[C_HEAL]) {
	  if (val>mhp) val=mhp; // Nur MOEGLICHE Heilung beruecksichtigen
	  val*=pref[C_HEAL];
	} else {
	  val=y[C_MIN]*pref[C_MIN]
	    + y[C_AVG]*pref[C_AVG]
	    + y[C_MAX]*pref[C_MAX];
	  if (y[C_DTYPES] && vul) // Vulnerability des Gegners bedenken...
	    val=(int)(((float)val)*(1.0+ME->eval_resistance(y[C_DTYPES],vul)));
	}
      } else {
	val=1;
      }
      val+=eval_combat_object(obs[i],y,enemy);
      if (val<max) continue;
      max=val;
      if (mappingp(y) && y[C_HEAL]>0)
	best=sprintf(ind[j],name(RAW)); // Heilung auf sich selbst
      else if (objectp(enemy))
	best=sprintf(ind[j],enemy->name(RAW)); // Schaden auf Gegner
    }
  }
  return best;
}

varargs int use_best_combat_command(mixed enemy, mixed from, mapping pref) {
  // Fuehrt moeglichst guten Kampfeinsatz mit einer Sonderwaffe aus
  string str;
  
  if (stringp(enemy) && environment())
    enemy=present(enemy,environment());
  if (str=find_best_combat_command(from,enemy,pref))
    return command(str);
  return 0;
}

void add_select_commands() {
  add_action("wield_best_weapon","zuecke_beste_waffe");
  add_action("wear_best_armours","trage_beste_ruestungen");
  add_action("use_best_combat_command","benutze_beste_sonderwaffe");
  add_action("wield_best_weapon","zücke_beste_waffe");
  add_action("wear_best_armours","trage_beste_rüstungen");
}
