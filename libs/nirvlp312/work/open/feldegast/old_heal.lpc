#include "/players/feldegast/defines.h"
#define STRENGTH 7
#define HEAL 25
#define COST 12
#define MAX_CHARGES 2

int charges;

init() {
  if(!environment()->is_player()) return;

  add_action("eat", "eat");
  add_action("eat","chew");
}
reset(arg) {
  if(arg) return;
  charges=MAX_CHARGES;
}

int id(string str)
{
  return str=="leaf" || str=="leaves";
}

short(){
  return HIG+"Sappy Leaves"+NORM+" *"+charges+"*";
}

long() {
  write("This is a bundle of small fresh leaves, covered in sap almost\n"+
       "as though someone had been trying to make them bleed.  The sap\n"+
       "and the leaf might be of some nutritional value.\n");
  write("There are "+charges+" portions left.\n");
}

get(){
  return 1;
}

eat(str) {

  if (!str || !id(str))
    return 0;

  if (!TP->eat_food(STRENGTH)) return 1;
  

  charges--;
  TP->heal_self(HEAL);
  write("You stuff a handful of leaves in your mouth and start chewing.\n"+
        "There are "+charges+" portions remaining.\n"
  );
  say(TPN+" chews on some leaves.\n");
  command("mon",TP);
  if (charges==0) {
    destruct(this_object());
    TP->add_weight(-1);
    write("You finish off the leaves.\n");
  }
  return 1;
}

query_value() {
  return COST*HEAL*charges;
}

query_weight() {
   return 1;
}
query_save_flag() { return 1; }
