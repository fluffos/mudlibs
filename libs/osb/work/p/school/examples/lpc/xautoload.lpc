/*  XAutoload
**
** A simple example object for autoloading.
**
** An object is autoloading, if the property AUTOOBJECT returns a value
** different from zero. The property is checked on every save of the
** player, including the last save before quitting.
** The value returned by Query() is used as argument for Set()
** on reloading.
**
** Of course, the property might be realized as builtin-property, by
** defining two lfuns SetAutoobject() and QueryAutoobject().
**
** In this example the exact value of the property doesn't matter,
** so wie just set it once to non-zero (== 1) and then don't care any longer.
**
**   v.1 18-Jun-92 [m]
**       19-Jun-92 [m] Simplified it a bit (since I'm not so sleepy now :-)
**       27-Jul-92 [m] Adapted for new autoload mechanism
**
** [m] Mateese, Biontic Magics & Darkness
*/

#define PL this_player()
#define ME this_object()

#include <config.h>
#include <properties.h>

#define VERSION "920727"
#define VERSNR  1

inherit "/std/thing";

/*-------------------------------------------------------------------------
** Initialization.
*/

create () {
  thing::create();
  Set(P_SHORT, "an autoloader");
  Set(P_LONG, 
"This is an autoloading object (/d/archwiz/common/lpc/exm/xautoload.c ).\n"
     );
  Set(P_VALUE, 0);
  Set(P_WEIGHT, 0);
  Set(P_READ_MSG,
"A small sign reads:\n"+
"  Autoloader --- v"+VERSNR+"."+VERSION+"\n"+
"  Biontic Magics & Darkness\n"
         );
  Set(P_INFO, "Autoloader v"+VERSNR+"."+VERSION+": Mateese");
  AddId("autoloader");

    /* We just do autoloading, so the exact value of P_AUTOOBJECT
    ** doesn't matter, as long as it's not zero.
    */
  Set(P_AUTOOBJECT, 1);
}

/*************************************************************************/
