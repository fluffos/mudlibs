inherit OBJECT;

void create(){
set("prevent_get", 1);
set("short", "an Oasis");
set("id", ({ "oasis" }));
set("long" "This is a pool of cool, refreshing water.\n");
}
void init(){ add_action("drink", "drink"); }
 int drink(string str){
  int dl;
   if(!str || str !="from oasis") return 0;
if((int)TP->query("thirst") < 1){ write("You would gain nothing from drinking from the pool.\n"); return 1; }
        write("You drink some cool, refreshing water.\n");
        say(TPN+" drinks from the oasis.\n");
        TP->add("thirst", -1);
        dl++;
  if(dl > 5){ say("The oasis has been drained of all its precious water.\n"); remove(); }
return 1;
}