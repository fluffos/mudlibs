inherit "obj/armor";
#include "/players/pestilence/ansi.h";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("diamond ring");
   set_alias("a sparkling diamond ring");
   set_short("a sparkling "+HIW+"diamond"+NORM+" ring");
   set_long(
      "This is a sparkling"+HIW+" diamond"+NORM+" ring.  This ring has a lot\n"+
      "of meaning to it's original owner.  There seems to be an\n"+
      "inscription on this ring.\n"
   );
   set_ac(1);
   set_type("ring"); 
   set_weight(1);
   set_value(2000);

}
/*
query_save_flag(){
  return 1;
  }
*/

init () {
   ::init() ;
     add_action ("read_inscription","read");
     }

read_inscription(str) {
   if(str != "inscription") { notify_fail("Read what?\n");
 return 0; }
     write("With this ring I grant you the power of my life.\n");
      return 1;
}

do_special(owner)
{

int z;
object ob;
  z = random(50);
   if (z<5){
 environment()->add_hit_point(random(2));
tell_room(environment(owner), ""+environment()->query_name()+"'s "+HIW+"diamond ring"+NORM+" glows brightly as power flows from it.\n");
return 1;
}
      return 0; 
   }
