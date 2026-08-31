// /bin/skills/_limbs.c
// From the Nightmare Mudlib
// A cleric, monk, kataan spell to determine the body damage of others.
// By Gregon@Nightmare

// Amarael update:
// Spell gets better with skills.
 
#include <std.h> 
inherit DAEMON;
int spell();
 
int cmd_limbage(string str){
    string name, *limbs;
    object ob, tp;
    int x, i, *dam, maxdam;
 
    if(!str)
      return notify_fail("Correct syntax: limbs [whom]\n");
   
    tp=this_player();
 
    if(tp->query_subclass()!="monk" && tp->query_subclass()!="cleric")
      return notify_fail("What?\n");

    if(tp->query_subclass()=="cleric")
      x=tp->query_skill("belief");
    else
      x=tp->query_skill("faith"); 
    if(x < 20)
      return notify_fail("You are not yet faithful enough to do that.\n");

    if(tp->query_mp()<20)
      return notify_fail("You do not have the magic strength to do that right now.\n");
 
    ob=present(str, environment(tp));

    if(!ob)
      return notify_fail(capitalize(str)+" is not here.\n");
   
    if(ob->query_ghost())
      notify_fail("That player has no limbs at all!\n");
 
    tp->add_mp(-20);

    message("info", tp->query_cap_name()+" utters a request for divine guidance.", environment(tp), tp);
 
    if(x-random(51)<0) {
     write("Your prayers for guidance are not heard.");
     return 1;
     }

   tp->add_skill_points("faith",10);

   name = ob->query_cap_name();
   dam = allocate(i=sizeof(limbs = ob->query_limbs()));

   if(x < 300 ) {
     while(i--) {
       dam[i] = to_int(percent(ob->query_dam(limbs[i]), ob->query_max_dam(limbs[i])));
       if(dam[i]>dam[maxdam])
         maxdam=i;
       }

     if(!dam[maxdam]){
       write(name+" has minimal body damage.");
       return 1;
       }
 
     if(x<40) {
       if(x-random(51)<0)
         maxdam=random(i);
       write("You get the sense that "+name+"'s "+limbs[maxdam]+" is damaged.");
       return 1;
       }
 
     if(x<65) {
       write("You get the sense that "+name+"'s "+limbs[maxdam]+" is damaged.");
       return 1;
       }
 
     if(x<80){
       if(dam[maxdam]<20){
         write("You get the sense that "+name+"'s "+limbs[maxdam]+" is slightly damaged.");
         return 1;
         }
       if(dam[maxdam]<40){
         write("You get the sense that "+name+"'s "+limbs[maxdam]+" is somewhat damaged.");
         return 1;
         }  
       if(dam[maxdam]<60){
         write("You get the sense that "+name+"'s "+limbs[maxdam]+" is heavily damaged.");
         return 1;
         }
       if(dam[maxdam]<80){
         write("You get the sense that "+name+"'s "+limbs[maxdam]+" is severely damaged.");
         return 1;
         }
       write("You get the sense that "+name+"'s "+limbs[maxdam]+" is about to fall off!");
       return 1;
       }
     write("You get the sense that "+name+"'s "+limbs[maxdam]+" is at "+dam[maxdam]+" percent of its potential.");
     return 1;
     }
   else {
     while(i--) {
       dam[i] = to_int(percent(ob->query_dam(limbs[i]), ob->query_max_dam(limbs[i])));
       message("info", ob->query_cap_name()+"'s "+limbs[i]+" is at "+dam[i]+"% of it's potential.", tp, );
       }
     return 1;
     }
   write("WTF? BUG!");
   return 1;
}



void help(){
    write("syntax: limbs [whom]\nThis allows the faithful to offer a prayer "
          "for guidance in determining the location of injuries on another.");
}
int spell() {
   object a;
   a = this_player();
   if (!a) return 0;
   if (a->query_subclass() != "cleric" && a->query_subclass() != "monk") return 0;
   if (a->query_level() < 2) return 0;
   return 1;
}
