/*
** crystal_lock.c
**
** (C) Tron.
**
*/

#include <areas.h> 

#define NAME ((string) this_player()->query_name())
#define MMASTER AREA_TRISTEZA "duel/obj/mapmaster"
 
status
id(string str) { return (str=="hole"); }
 
string
short() { return "There is an almost square hole in the ground here"; }
 
void
long() {
 
   write("Hmmm...this could hold a cube...almost a regular one.\n");
}
 
void
init() {
 
 add_action("put_cube", "put");
 add_action("put_cube", "push");
}
 
status
put_cube(string str) {
 
string name;
object ob;
 
   if(!str) return 0;
 
   sscanf(str, "%s in hole", name);
   if(!(ob = present(name, this_player()))) {
      write("You don't have it.\n");
      return 1;
    }
   
   if(ob->id("cube_crystal")) {
       say(NAME+" puts something in the hole.\n");
       say(NAME +" vanishes without a sound.\n");
       destruct(ob);
       ob = (object)MMASTER->create_room(0, 8);
       move_object(this_player(), ob);
       write("You materialize somewhere else...\n");
      }
     else write ("That does not fit in the hole.\n");
 
return 1;
}
