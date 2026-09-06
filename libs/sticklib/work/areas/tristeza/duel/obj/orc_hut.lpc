#include <areas.h>


/*
**
** Orcs' hut - Code by Tron.
**
*****************************/

#define ATRIBUTES  ({ "grey", "blue", "green", "old", "fragile",\
                      "red", "almost collapsed", "filthy", "small",\
                      "large", "lousy", "rain beaten" })

#define MYCLONE(x) move_object(clone_object(x), this_object())

string name;


status 
id(string str) {

  return (str=="hut" || str==name);
}


void
long () {

if(present(this_player(), this_object()))
   write("This is a typical hut built by orcs.\n"+
         "The smell has already become familiar but\n"+
         "this scene has not. There are some pieces of\n"+
         "rotten meat on the \"floor\" and some other\n"+
         "objects that do not catch your interest.\n"+
         "The hut has only this one room and nothing else.\n");
 else
   write("This is just a simple hut. Maybe you should\n"+
         "enter it to get more information.\n");
 }

string
short() { return name;}

void
reset(status arg) {

   if(arg) return;

   name = ATRIBUTES[random(sizeof(ATRIBUTES))]+" hut";

   //if(!random(2)) MYCLONE(AREA_DUEL_ARENA + "obj/chair");
   //if(!random(3)) MYCLONE(AREA_DUEL_ARENA + "obj/table");
   if(!random(5)) MYCLONE(AREA_DUEL_ARENA + "obj/knife");
   //if(!random(8)) MYCLONE(AREA_DUEL_ARENA + "mon/stunner_orc");
   //if(!random(10)) MYCLONE(AREA_DUEL_ARENA + "obj/okey");
   //if(!random(10)) MYCLONE(AREA_DUEL_ARENA + "obj/cursed_sword");

 }

void
init() {

 if(present(this_player(), this_object())) {
     add_action("out", "out");
     add_action("out", "exit");
   }
  else add_action("enter", "enter");
}
  

status 
out() {

 write("You leave the hut.\n");
 this_player()->move_player("out", environment());
 return 1;
}

status 
enter(string str) {

object ob;
string tmp;
int ord, i;

  if(!str) {
    write("Hmmm...enter what exactly???\n");
    return 1;
  }


 if(sscanf(str, "%s %d", tmp, ord)==2) str=tmp;
 else ord=1;

 if (str==name || str=="hut") {
     ob=first_inventory(environment());
     while(ob) 
       {
         if(ob->id("hut")) i++;
         if(ord==i) break;
         ob=next_inventory(ob);
       }

   }


  if(!ob) write("And what is that?\n");
  else this_player()->move_player("into "+name, ob);

return 1;
}
