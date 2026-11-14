inherit "std/food";

#include <properties.h>
#include <food.h>

void create()
{
if (!clonep(this_object())) return;
::create();

SetProp(P_SHORT, "Ein Schokoriegel");
SetProp(P_LONG,
"Ein lecker aussehender Vollmilchschokoriegel.\n");
SetProp(P_NAME, "Schokoriegel");
AddId(({"riegel", "schokoriegel"}));
SetProp(P_WEIGHT, 100);
SetProp(P_VALUE, 50);
SetProp(P_FOOD_INFO, ([F_HEAL : ({5, 0}), F_SOAK : 5]));
}

void BeimEssen()
{
write("Du isst den leckeren Schokoriegel.\n");
say(this_player()->name()+" isst den leckeren Schokoriegel.\n");
}
