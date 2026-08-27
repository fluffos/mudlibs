inherit "/std/vaults/vault_room";
#include "path.h"
#include "config.h"

void setup ()
{
	::setup();
  set_guild_owner( ({GUILD2}) );
	set_saqueable(1);	// saq. con opts por defecto
  set_short (BAULTITLE+"\n");
  set_long (BAULTITLE+"\n"+
     "Te encuentras en una habitacion muy asegurada con una puerta de un "+
"material que parece acero. Afortunadamente estaba abierta para ti. Ves un gran "+
"baul en la habitacion que tiene aspecto de ser usado con mucha frecuencia. "+
"Tambien puedes ver un cartel.\n\n");
  add_item("baul","Es un gran cofre de madera tallada ricamente y con refuerzos de metal.");
  set_light (60);

  add_exit ("norte", ROOMS+"hall", "corridor");
}

/*int clean_up()
{
 return 1;
}*/
