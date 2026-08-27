inherit "/std/storeroom";
#include "/d/abarrach/path.h"
#define ARMAS "/baseobs/weapons/"
#define ARMAD "/baseobs/armours/"
 
setup()
{
        set_short("El almassen");
        set_long("Aqui e donde se guardan los objetos.\n");
        add_exit("sur", CIUDAD+"zapateria", "door");
        set_light(80);
}
 
void reset()
{
        call_out("af_reset", 0);
}
 
void af_reset()
{
   int i, j;
   object ob, torch;
        
   i = sizeof(find_match("botas de montar", this_object()));
   for (;i<4;i++)
   {
   torch = clone_object("/d/anduar/objetos/calzado/botas_montar");
   torch->move(this_object());
   }
   i = sizeof(find_match("zapatillas", this_object()));
   for (;i<2;i++)
   {
   ob = clone_object("/d/anduar/objetos/calzado/zapatillas");
   ob->move(this_object());
   }
   i=sizeof(find_match("sandalias", this_object()));
   for (;i<3;i++)
   {
   ob = clone_object("/d/anduar/objetos/calzado/sandalias");
   ob->move(this_object());
   }
}
