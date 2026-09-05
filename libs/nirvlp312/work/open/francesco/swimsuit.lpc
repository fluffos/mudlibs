#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";
int worn;
object ob;

reset(arg) {
set_name("swimsuit");
set_alias("suit");
set_short("A men's swimsuit");
set_long(
   "This thin swimsuit has deen designed to offer less-than-ever resistance\n"+
   "during swimming.  It is made by light nylon fabric which lets the water \n"+
   "flow without friction over it.  It is black, the only color available\n"+
   "for these special swimsuits.  It is 'trade'able to the Narrator.\n");
set_ac(2);
set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(350);
}

init() {
::init();
  add_action("trade","trade");
  add_action("wear","wear1");
  return 1;
}
trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="swimsuit"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 1900 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(1900));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}

wear(str) {
  if(!str) {notify_fail("Wear what?\n"); return 0;} 
   if(!id(str) || environment() != this_player() || worn) return 0;
   if(this_player()->query_gender()=="male"){
   ::wear(str);
   return 1; }
   else 
    {notify_fail("Eheh, wishing to walk around topless, uh?\n"); 
  return 0;}
return 0; }


query_save_flag() { return 1; }
