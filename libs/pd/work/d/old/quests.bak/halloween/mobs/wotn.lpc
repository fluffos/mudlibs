#include <std.h>
#include <halloween.h>

inherit MONSTER;

int speech;
void create()
{
 ::create();
 set_name("witch of the north");
 set_short("%^ORANGE%^Witch of the north%^RESET%^");
 set_long("The witch has bright %^YELLOW%^yellow%^RESET%^ stringy "
          "hair sticking out of her pointy witch hat. She has a "
          "a strange glowing aura around her. She has a huge pointy "
          "nose.\n"
          "She is wearing:\n"
          "%^BLACK%^%^BOLD%^Br%^RESET%^%^ORANGE%^oo%^BLACK%^%^BOLD%^m"
           "st%^RESET%^%^ORANGE%^i%^RESET%^%^BLACK%^%^BOLD%^ck "
           "%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^f th%^RESET%^%^ORANGE%^e"
           "%^RESET%^ %^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^or%^BOLD%^"
           "%^BLACK%^th%^RESET%^ (ridden)");


 set_id( ({ "witch", "witch of the north" }) );
 set_race("goblin");
 set_body_type("human");
 set_gender("female");
 set_level(10);
 set_stats("constitution", 99999999);
 set_max_hp(500000);
 set_hp(query_max_hp());
 set_moving(1);
 set_speed(20);
 new(OBJS "nbroom")->move(this_object());
 set_no_clean(1); 
} 

void heart_beat()
{ 
 ::heart_beat();
 
 if (speech++ > 10)
   {
    switch(random(3))
     {
      case 2: force_me("say The others better not screw up, or there will be hell to pay."); break;
      case 1: force_me("say Just wait and see what we can do."); break;
      case 0: force_me("say Its all going well, just wait."); break;
     }
    speech = 0;
   }
  
}
