/* /lib/item.c
 * from the Foundation II LPC Library
 * inheritable object for all tangible game objects
 * created by Descartes of Borg 950207
 */

#include <lib.h>
#include <daemons.h>
#include <config.h>
#include "item.h"

inherit LIB_OBJECT;
inherit LIB_MOVE;

private int Invis, Mass;
private mixed PreventDrop, PreventGet, PreventPut;

/***********          /lib/item.c modal functions          ***********/

int CanGet(object ob) {
    mixed val;

    if(!ob) return 0;
    if( !(val = GetPreventGet()) && !GetProperty("keep") ) return 1;
    else if( stringp(val) ) {
        message("my_action", val, ob);
        return 0;
    }
    else if( functionp(val) ) return (int)evaluate(val, ob);
    else if( stringp(GetProperty("keep")) ) {
        if( (string)ob->GetKeyName() == GetProperty("keep") ) return 1;
        return 0;
    }
    return 1;
}

int CanDrop(object ob) {
    mixed val;

    if( !(val = GetPreventDrop()) ) return 1;
    else if( stringp(val) ) {
        message("my_action", val, ob);
        return 0;
    }
    else if( functionp(val) ) return (int)evaluate(val, ob);
    else return 1;
}

int CanPut(object ob) {
    mixed val;

    if( !(val = GetPreventPut()) ) return 1;
    else if(stringp(val)) {
        message("my_action", val, ob);
        return 0;
    }
    else if( functionp(val) ) (int)evaluate(val, ob);
    else return 1;
}

/***********       /lib/item.c data manipulation functions      ***********/

int SetMass(int x) {
    if( x < 0 ) x = 0;
    return (Mass = x);
}

int AddMass(int x) { 
    if( Mass + x < 0 ) x = -Mass;
    if( environment() ) environment()->AddCarriedMass(x);
    return (Mass -= x);
}

int GetMass() { return Mass; }

mixed SetInvis(mixed val) {
    if( intp(val) ) return (Invis = val);
    else if( functionp(val) && !Invis ) return (Invis = val);
    else return Invis;
}

varargs int GetInvis(object ob) {
    if( !ob ) ob = (this_player() || previous_object());
    if( functionp(Invis) ) return (int)evaluate(Invis, ob);
    else return Invis;
}

mixed SetPreventGet(mixed val) {
    if(!stringp(val) && !functionp(val)) 
      error("Bad argument 1 to SetPreventGet().\n");
    return (PreventGet = val);
}

mixed GetPreventGet() { return PreventGet; }

mixed SetPreventDrop(mixed val) {
    if( !stringp(val) && !functionp(val) ) 
      error("Bad argument 1 to SetPreventDrop().\n");
    return (PreventDrop = val);
}

mixed GetPreventDrop() { return PreventDrop; }

mixed SetPreventPut(mixed val) {
    if(!stringp(val) && !functionp(val))
      error("Bad argument 1 to SetPreventPut().\n");
    return (PreventPut = val);
}

mixed GetPreventPut() { return PreventPut; }
