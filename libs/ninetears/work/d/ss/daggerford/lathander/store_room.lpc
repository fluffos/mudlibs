inherit "/std/storeroom";
#include "path.h";
object potion1;
object incense;
int i;
void reset()
{
if(!potion1){
   for(i=1;i<5;i++)
   {
      potion1=clone_object("/w/alansyn/items/orange_potion");
      potion1->move(this_object());
   }
}
if(!incense){
   for(i=1;i<5;i++){
      incense=clone_object("/w/alansyn/items/incense");
   incense->move(this_object());
   }
}
}
void setup()
{
set_short("This is a store room.  Do you need a short?");
set_long("This is a store room.  Do you need a description?");
set_light(55);
}
