#include "path.h"
inherit "/obj/monster";

void setup()
{
    set_name("pirata");
    set_short("Pirata");
    set_gender(1);
    set_level(8+random(4));
    set_random_stats(8,4);
    set_long("Un huesudo pirata con pinta de estar algo deprimido, aunque "
    "su aspecto aun es caracteristico de los de su clase, varias cicatrices surcan "
    "su cara."
    "Te mira con desprecio. "
    "\n");
   set_al(250);
    load_chat(20, ({
        1,":erupta",
        1,"'No conoces una manera de salir de esta asquerosa isla?",
        1,"'Tienes algo que hecharme al gaznate?",
        1,"'Donde se mete el capitan cuando le necesito ?"
    })
    );
    load_a_chat(300, ({
        1,"'Tengo luchado con pescaditos mas peligrosos que tu!.",
        1,"Pirata te desprecia con la mirada.",
        1,"'He visto bigaros mejor armados que tu!",
        1,"Pirata te escupe."
    }));
    new("/baseobs/armours/leather")->move(this_object());
   new(OBJ+"boots")->move(this_object());
    new("/baseobs/weapons/dagger")->move(this_object());
   adjust_money(5+random(5),"silver");
   init_equip();
}





