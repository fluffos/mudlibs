#include <mudlib.h>
#include "../defs.h"

inherit OBJECT;
int done;
string query_condition(){
   if(done) return "This grave has been desecrated.\n";
   if(!done) return "The ground before this grave is softy and muddy.\n";
}
void create() {
  seteuid(getuid());
  set("id", ({
    "grave",
    "gravestone",
    "headstone",
    "marker",  
  }));
  set("short", "A moldy granite gravestone.");
  set("long", @EndLong
This grave is made of decaying granite, and is scribed
with dwarven markings.  It marks the resting place of
the dead.  All types and colors of mold cover nearly the
entire structure.
EndLong
);
  set("prevent_get", 1);
  
}
void init(){
 switch(random(6)){
   case 0: set("short", "A moldy granite gravestone"); break;
   case 1: set("short", "A black marble headstone with white markings"); break;
   case 2: set("short", "A broken rock headstone"); break;
   case 3: set("short", "A common grave marker"); break;
   case 4: set("short", "An ornate cross-shaped gravestone"); break;
   case 5: set("short", "A mold ridden ridden grave marker"); break;
   default: set("short", "A moldy granite gravestone"); break;
}
  environment(TO)-> add("item_desc/markings", "The markings are so decayed they are unreadable.\n");

  add_action("dig_func", "dig");

}

int dig_func(string str){
 object ucorpse;
  if(!str || str !="up grave") return 0;

  if(!present("*SHOVEL*", TP) && !wizardp(TP)){ write("What are you to dig with?\n"); return 1; }

if(done){ write("That grave has already been desecrated.\n"); return 1; }
ucorpse = clone_object(MON(u_corpse.c));

write("You dig up the grave...\n\n");
say(TPN+" desecrates the sanctity of the grave...\n\n");
say(ucorpse->query("cap_name")+" seems quite offended by this, and attacks "+TPN+"!\n");
write(ucorpse->query("cap_name")+" Attacks you for defiling "+possessive(ucorpse->query("gender"))+" grave!\n");
ucorpse->move(environment(TO));
ucorpse->kill_ob(TP); 
done = 1;
set("long", (string)TO->query("long")+query_condition());
return 1;
}                                                 