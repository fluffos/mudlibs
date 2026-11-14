// SilberLand MUDlib
//
// CONTAINER/INVENTORY.C -- Umgang mit besonderen Objekten im Inventory
//
// $Date: 1997/03/13 00:56:54 $
/* $Revision: 3.2 $
 * $Log: inventory.c,v $
 * Revision 3.2  1997/03/13 00:56:54  Woody
 * prepared for revision control
 *
 * Revision 3.1  1995/12/11 19:26:15  Rochus
 * Automatisches updaten der Stats beim Hinzufuegen/Entfernen
 * von Objekten mit Attribut-Modifiern.
 *
 * Revision 3.0  1995/11/22 14:31:48  Jof
 * Updated to revision 3.0
 *
 * Revision 1.2  1995/11/13 20:34:38  Rochus
 * bugfix
 *
 * Revision 1.1  1995/11/13 19:43:35  Rochus
 * Initial revision
 *
 */

inherit "/std/container/inventory";

#pragma strong_types
#define NEED_PROTOTYPES

#include <properties.h>
#include <sensitive.h>
#include <attributes.h>

#define ME this_object()

void RemoveSensitiveObject(object ob) {
  ::RemoveSensitiveObject(ob);
  RemoveSensitiveObjectFromList(ob,SENSITIVE_ATTACK);
  if (objectp(ob) && ob->QueryProp(P_X_ATTR_MOD))
    UpdateAttributes();
}

void InsertSensitiveObject(object ob, mixed arg) {
  ::InsertSensitiveObject(ob,arg);
  if (objectp(ob) && ob->QueryProp(P_X_ATTR_MOD))
    UpdateAttributes();
}

void CheckSensitiveAttack(int dam, mixed dam_type, mixed spell, object enemy) {
  mixed a,x;
  int i;
  
  if (!pointerp(a=QueryProp(P_SENSITIVE_ATTACK)))
    return;
  if (!pointerp(dam_type))
    dam_type=({dam_type});
  for (i=sizeof(a)-1;i>=0;i--)
    if (pointerp(x=a[i]) &&
	dam>x[SENS_THRESHOLD] &&
	member(dam_type,x[SENS_KEY])>=0 &&
	objectp(x[SENS_OBJECT]) &&
	environment(x[SENS_OBJECT])==ME &&
	closurep(x[SENS_CLOSURE]))
      funcall(x[SENS_CLOSURE],
	      enemy,x[SENS_KEY],dam,
	      spell,x[SENS_OPT]);
}
