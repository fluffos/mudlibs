
#include "path.h"
inherit "/std/outside";
object *monsters;
string *monlist = ({"hog","rat","bandicoot","hornet"});
string mon;
create()
{
   ::create();
   add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isla de Havmand: Jungla.");
    set_night_long("\nIsla de Havmand: Jungla.\n"
    "   Es muy dificil ver detalles en la oscuridad bajo el techo de la "
    "jungla.  Tienes la sensacion de que tu sentido del oido se incrementa, "
    "o y tambien te fijas mas en los olores del bosque. Debes andar con cuidado "
    "en la penumbra nada parece lo mismo. "
    "\n\n");
    add_item( ({"arbol","arboles"}),"Los arboles,grandes como torres, forman "
    "un techo sin fin bloqueando la entrada a la luz. Algunos de ellos tienen "
    "musgo y liquenes creciendo en sus troncos, y hacen dificultoso el camino "
    "ya que crecen muy juntos unos a otros. "
    "\n");
    add_item("leafmould","Fallen leaves have been collecting on the jungle "
    "floor for years. They deaden the sounds of footfalls, so you can "
    "hardly hear your own steps, let alone anything else walking along. "
    "\n");
    add_item("musgo","Brillante musgo verde cubre los troncos de los arboles "
    "y en el suelo cerca de sus raices. "
    "\n");
    add_item("liquen","Los liquenes, de un verde muy palido te recuerdan las barbas "
    "de un anciano. "
    "\n");
    add_item( ({"fungus","fungi"}),"Pale flesh colored fungi grow like "
    "plates from the trunks of the trees. "
    "\n");
   add_sound("jungla","Puedes oir el roce de las hojas y algin pajaron trinando."
      " Ocasionalmente tambien el sonido de agua goteando. \n\n");
    add_sound("agua","Escuchando con atencion oyes el sonido de agua goteando "
    "desde las hojas de arriba. "
    "\n");
    add_sound( ({"pajaro","pajaros"}),"Oyes trinos y el piar de pajaros y "
    "tambien algun crujido suave que esperas sea de pajaros al revolotear "
    "o buscar comida entre la hojarasca. "
    "\n");
    add_smell(({"aire","jungla"}),"El aire huele a vegetacion y a humedad "
    "Ocasionalmente notas un ligero tono salado que te recuerda al mar, "
    "no muy lejano. "
    "\n");
    add_feel("arbol","El tronco es rugoso y ligeramente resbaladizo debido "
    "a la constante humedad. "
    "\n");
    add_feel("musgo","Es suave y sedoso y muy, muy humedo. "
    "\n");
    add_feel("liquen","El  liquen es rugoso y aspero, al tocarlo se desintegra "
    "dejando un fino polvo verde en tus dedos. "
    "\n");
//    add_feel( ({"fungus","fungi"}),"This feels truely repellant, like the "
//    "week dead flesh of your grandmother. "
//    "\n");
   monsters = allocate(random(JUNGLE_ANIMAL_MAX));
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


