#include "path.h"
inherit "/std/outside";
object *monsters;
string mon;

create()
{
   ::create();
    set_light(LIGHT);
    set_short("Isla de Havmand: Campamento Pirata.");
    set_night_long("\nIsla de Havmand: Campamento Pirata.\n"
    "   Todo lo que puedes ver son formas oscuras sobre un fondo aun mas oscuro. Parecen "
    "pequenyas viviendas construidas bajo los arboles, pero no puedes ver ningun detalle "
    "en la oscuridad. "
    "\n\n");
    add_property("no_undead",1);
    monsters = allocate(random(PIRATES));
   this_object()->setup();
   reset();

}
void reset()
{
    int i;
    if(monsters)
    {
        for(i = 0; i < sizeof(monsters); i++)
        {
            if(!monsters[i])
            {
                monsters[i] = new(CHARS+"pmice");
                monsters[i]->move(this_object());
            }
        }
    }
}
void dest_me()
{
    int i;
    if(monsters)
    {
   for(i = 0; i < sizeof(monsters); i++)
        if(monsters[i]) monsters[i]->dest_me();
    }
    ::dest_me();
}
