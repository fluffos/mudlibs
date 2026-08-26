#include "../defs.h"

inherit ROOM;   
object grenda;
object needle;
int searched;
void init(){ add_action("search", "search"); }
void create() {
  seteuid(getuid());   

  set("author", "Waxer");  
  set("light", 1);
  set("short", "Inside a dark wagon.");
  
set("long", @ENDLONG
This is a dark wagon.  You see stacks of cloth of all different patterns
and colors.  A lamp is the only light source emanating from here.
There is a box fastened shut in the northwest corner.
ENDLONG
);

  set("item_desc", ([
    "stacks" : "These are bolts of cloth of bizarre colors and patterns.\n",
    "cloth" : "These are bolts of cloth of bizarre colors and patterns.\n",
     "lamp" : "An ancient metal lamp is the only light source in this room.\n",
     "box" : "This looks like a box of sewing supplies.\n"
 ]) );
   
  set("smell", ([
    "default" : "You smell decaying cotton and other fibers.\n", 
    "lamp" : "It smells like it is leaking more oil than it's using.\n",
    "stool" : "You pick up the faint odor of a beer fart.\n",
]) );

  set("exits", ([
    "out" : ROOMS(grounds),  
]) );
  ::create();  
}
void reset(){
  if(!grenda){
    grenda=clone_object(MON(grenda));
    grenda->move(TO);
  }
::reset();
}
int search(string str){
    if(grenda){
           write("Grenda doesn't let you near her box of knitting supplies.\n");
            return 1;
       }
    if(searched){
       write("The box contains nothing of interest");
       return 1;
          }
   if(!str){ 
    write("That cannot be searched here"); 
    return 1; 
        } 
   if(!grenda){
          
      if(str !="box")
        {
        write("You find a pair of golden knitting needles in the box!\n");
        needle=clone_object(OBJ(needle));
        needle->move(TP);
        searched = 1;
        return 1;
          }
    }
}
