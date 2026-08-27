#include "path.h"
inherit "/std/outside";
object *monsters;
string *monlist = ({"crab","snake","seal"});
string mon;

create()
{
   ::create();
    set_short("Isla de Havmand: Playa.");
    set_night_long("\nIsla de Havmand : Playa\n\n"
    "   Pequenyos rayos de luz se reflejan en la arena y el agua esta noche, aun "
    "cuando no hay ninguna fuente de luz.  Las olas baten contra la orilla y "
    "tus pisadas producen crujidos al caminar sobre la arena. "
    "\n\n");
    add_item("arena","Suave, fina arena blanca cubre la playa. Cuando intentas "
    "coger un punyado se te escurre por entre los dedos. \n");
    add_item(({"agua","olas","marea","mar"}),"Las olas rompen en la orilla, avanzando "
    "por la orilla y retirandose otra vez, y dejando un rastro de espuma blanca. \n");
    add_feel("arena","Sientes la arena caliente cuando corre entre tus "
    "dedos.\n");
    add_sound(({"olas","marea"}),"Oyes el ritmico sonido de las olas."
   "\n");
    add_sound("crujidos","Segun te mueves sobre la arena, tus pies hacen un sonido "
    "parecido a un crujido.\n");
    add_feel("agua","El agua esta calentita.\n");
    add_sound("pajaros","Puedes oir el sonido de aves marinas.\n");
    add_smell("aire","El olor a salitre es muy fuerte en el aire.\n");
      add_property("no_undead",1);


    if(random(BEACH_ANIMAL) == 0)
    {
        monsters = allocate(random(BEACH_ANIMAL_MAX)+1);
    }
    mon = CHARS+monlist[random(sizeof(monlist))];

   this_object()->setup();
   reset();
}
void reset()
{
    int i;
    for(i = 0; i < sizeof(monsters); i++)
    {
         if(!monsters[i])
         {
                monsters[i] = new(mon);
                monsters[i]->move(this_object());
        }
    }
}
void dest_me()
{
    int i;
    for(i = 0; i < sizeof(monsters); i++)
    {
        if(monsters[i]) monsters[i]->dest_me();
    }
    monsters = 0;
    ::dest_me();
}


