/*
 
 MAP_Door.c
 
 - Mapmaster compatible.
 - Uses /obj/door.c modified by Tron.
  
*/
 
#include <areas.h>

#define	MMASTER	AREA_DUEL_ARENA "map/mapmaster"
#define	DOOR	AREA_DUEL_ARENA "obj/door"
 
inherit DOOR;
 
void
make_doors(string mask) {
 
string oroom;
string odir, tdir;
string end;
object ob;
int x,y;
   
   if(!mask) return;
 
   if (sscanf(mask, "%s %s %s %s",oroom, tdir, odir, end)!=4)
      return;
 
   ob = clone_object(DOOR);
  sscanf(oroom,"%d/%d",x,y);
    move_object(ob, (object)MMASTER->create_room(x,y));
   set_door(ob);
   set_all(tdir+" "+end);          
   ob->set_door(this_object());
   ob->set_all(odir+" "+end);
 
return;
}
 
 
