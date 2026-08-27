#include "path.h"
inherit "/std/outside";
string *monlist = ({"cat","mongrel","rat"});
create()
{
   int i;
   ::create();
    add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isla de Havmand: Senda.");
    set_night_long("\nIsla de Havmand : Senda\n\n"
    "   El alto y oscuro muro del castillo se eleva ante ti por un lado y las "
    "sombras de grandes arboles por el otro. Es imposible ver ningun detalle "
    "en la oscuridad. "
    "\n\n");
    add_item(({"muro","castillo","muro del castillo"}),"Un enorme castillo se eleva "
    "al oeste dominando el pequenyo poblado construido a su amparo. Esta construido "
    "en piedra y tiene unas altas torres."
    "\n");
    add_item(({"casa","vivienda"}),"Grotescas construcciones de pequenyo tamanyo donde "
    "vive parte de la poblacion local. Estan situadas junto al muro del castillo por "
    "proteccion y casi todas estan necesitadas de alguna reparacion.\n");
//    add_item(({"suciedad","polvo"}),"Brown, gritty dirt and dust gets scuffed up "
//    "from the track and works its way into your clothing. It is very itchy.\n");
    add_item("rodadas","Carros y vagonetas han ido dejando en el camino sus huellas erosionando "
    "poco a poco el suelo hasta dejar dos surcos. Ahora parece no haber signo de ninguno, "
    "como casi todo en esta isla, es posible que hayan caido en el desuso.\n");
//    add_feel("grit","Small coarse bits of dirt that get into your clothes "
//    "making you itch and long for a hot bath somewhere.\n");
    add_item("jungla","Una maranya de arboles se alzan ante ti. En muchos sitios la "
    "vegetacion es tan densa e impenetrable que debe de ser casi imposible abrirse "
    "paso a traves de ella.\n");
    add_property("no_undead",1);

   for(i = 0; i <= TRACK_ANIMAL_MAX; i++)
   {
   add_clone(CHARS+monlist[random(sizeof(monlist))],1);
   }

   this_object()->reset();
}
/* Taniwha 1997 and REALLY REALLY pissed off, leave the %^^%^^& 
   dummy function HERE
*/
int dummy() { return 1; }
