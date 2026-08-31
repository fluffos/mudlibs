#include <std.h>
inherit WEAPON;
int weapon_hit(object target);
int staff_power(){int i; i=this_player()->query_skill("blunt")/3; return i;}

create(){
 ::create();
   set_name("Mage Staff");
   set_short("%^BOLD%^%^RED%^Mage Staff%^RESET%^");
   set_long("This the staff of a high mage");
   set_mass(15);
   set_id(({"staff", "mage staff"}));
   set_value(750);
   set_wc(25);
   set_ac(1);
   set_type("blunt");
   set_hit((: weapon_hit :));
}

void init(){ ::init(); add_action("wieldme", "wield"); }

int weapon_hit(object target){
 if(random(staff_power()-100) < staff_power()){
   message("info",
    this_player()->query_cap_name()+" kicks some ass with his staff",
     environment(this_player()), this_player());
   message("info", "You kick some ass with your mage staff", this_player());
   return staff_power();
  }
 return 1;
}

int wieldme(string str){
   object tp; tp=this_player();
   if(!str || present(str, this_player()) != this_object())return 0;
   if(tp->query_class() != "mage"){
     message("info", "Only a mage would be able to use such a staff.", tp);
     return 1;
   }
if (tp->query_skill("blunt") < 150){
     message("info", "You are not ready for this yet.", tp);
     return 1;
   }
   return 0;
}
