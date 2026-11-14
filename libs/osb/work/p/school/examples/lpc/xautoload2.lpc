/*  XAutoload2 (Mateese, 27-Jul-92)
**
** A more example object for autoloading.
**
** Here we use the autoloading property for saving a value over logout.
** Also the property is realized as builtin-property.
**
** Note that both features DO NOT depend on each other!
** Instead of saving the value in a dedicated variable 'the_value' we
** could have put it directly into the property.
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

int the_value;

/*-------------------------------------------------------------------------
** Initialization.
*/

create () {
  thing::create();
  Set(P_SHORT, "a variable");
  Set(P_LONG, 
 "This is another autoloading object (/d/archwiz/common/lpc/exm/xautoload2.c ).\n"
"It allows you to save a value over logout, as long as it is not 0. "
"The value may set with 'xvarset <value>' and checked with 'xvarchk'.\n"
         );
  Set(P_VALUE, 0);
  Set(P_WEIGHT, 0);
  Set(P_READ_MSG, 
"A small sign reads:\n"+
"  Autoloader --- v"+VERSNR+"."+VERSION+"\n"+
"  Biontic Magics & Darkness\n"
            );
  Set(P_INFO, "Autoloader v"+VERSNR+"."+VERSION+": Mateese");
  AddId("variable");

    /* Per default, our value is just 0 */
  the_value = 0;

    /* The autoloading is done this time by builtin's, so no
    ** Set(P_AUTOOBJECT,...) here...
    */
}

/*-------------------------------------------------------------------------
** On demand, return the AUTOOBJECT-Property.
** In our case, it is just the content of the_value.
** If we'd like to save even a zero over logout, we could do it
** by returning ({ the_value }) instead of the_value alone.
*/

QueryAutoObject() {
  return the_value;
}

/*-------------------------------------------------------------------------
** Set the value of the AUTOOBJECT-Property.
** Since the value is normally stored and managed in the_value,
** a call to this lfun is either the player on startup, autoloading us,
** or some sinister figure changing the value from outside.
** Okok, if we wouldn't use a builtin-prop here, this distinction wouldn't
** be possible. But in most cases it isn't interesting either.
*/

SetAutoObject (mixed value) {
  object owner;

  the_value = value;

    /* Just for informational purpose :-) */
  if (owner = environment(ME) && living(owner))
    tell_object (owner, "The value of your variable has been set.\n");
}

/*-------------------------------------------------------------------------
** We have two own commands...
*/

init() {
  thing::init();
  add_action ("fvset", "xvarset");
  add_action ("fvchk", "xvarchk");
}

/*-------------------------------------------------------------------------
** Set the value of the variable
*/

fvset (string arg) {
  if (!arg) {
    notify_fail ("You forgot the value for the variable.\n");
    return 0;
  }
  the_value = arg;
  write ("You set the variable to ");
  write (the_value);
  write (".\n");
  if (the_value) write ("It is now autoloading.\n");
  else write ("It is no longer autoloading.\n");
  return 1;
}

/*-------------------------------------------------------------------------
** Print the value of the variable
*/

fvchk (string arg) {
  if (arg) {
    notify_fail ("'xvarchk "+arg+"'? How strange!\n");
    return 0;
  }
  write ("The variable is set to ");
  write (the_value);
  write (".\n");
  if (the_value) write ("It is autoloading.\n");
  else write ("It is not autoloading.\n");
  return 1;
}


/*************************************************************************/
