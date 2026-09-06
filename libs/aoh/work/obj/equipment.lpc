/*---------------------------------------------------------------------------
** /obj/equipment
**
** A standard equipment thing.
** All necessary entanglement between /std/thing and /std/equipment is
** already done.
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

public void init () {
  thing::init();
  equipment::init();
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

public varargs int QueryValue(int sc)         { 
  return sc ? ::QueryValue() : modifyValue(::QueryValue()); 
}

public varargs string Long(string what) { return modifyLong(::Long(what)); }
public varargs string InvShort (string what) { 
  return modifyInvShort(::InvShort(what)); 
}

/***************************************************************************/
