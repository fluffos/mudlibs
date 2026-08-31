#include <std.h>
#include <halloween.h>

inherit MONSTER;

int speech;
void create()
{
 ::create();
 set_name("witch of the west");
 set_short("%^RESET%^%^ORANGE%^Witch of the west%^RESET%^ %^RED%^%^BOLD%^(trapped under the mansion)%^RESET%^");
 set_long("This witch is pinned under the mansion. She is struggling "
          "to get out from under the mansion. This is the chubbiest "
          "of the witches. She has food stains all over her dress. "
          "It seems she is trying to reach of something thats out of "
          "her reach.\n"
          "She is wearing:\n"
"%^BLACK%^%^BOLD%^Br%^RESET%^%^BOLD%^%^CYAN%^oo%^BLACK%^%^BOLD%^m"
           "st%^RESET%^%^BOLD%^%^CYAN%^i%^RESET%^%^BLACK%^%^BOLD%^ck "
           "%^RESET%^%^BOLD%^%^CYAN%^o%^BOLD%^%^BLACK%^f th%^RESET%^%^BOLD%^%^CYAN%^e"
           "%^RESET%^ %^BOLD%^%^BLACK%^w%^RESET%^%^BOLD%^%^CYAN%^es%^BOLD%^"
           "%^BLACK%^t%^RESET%^ (ridden)");

 set_id( ({ "witch", "witch of the west", "wotw" }) );

 set_race("goblin");
 set_body_type("human");
 set_gender("female");
 set_level(10);
 set_stats("constitution", 99999999);
 set_hp(query_max_hp());
// set_moving(1);
// set_speed(20);
 new(OBJS "wbroom")->move(this_object());
 set_no_clean(1); 
} 

void heart_beat()
{ 
 ::heart_beat();

 if (present("slippers", this_object()))
   {
    force_me("emote wears the pair of ruby slippers");
    force_me("say Thanks.. i must leave!"); 
    force_me("emote blinks out of existance, leaving something behind.");
    present("slippers", this_object())->remove();
    this_object()->remove();
    return;
   }
 if (speech++ > 10)
   {
    switch(random(4))
     {
      case 3: force_me("fart");
      case 2: force_me("say eeek! i need my slippers!!!"); break;
      case 1: force_me("emote struggles to get out but fails."); break;
      case 0: force_me("say Please somebody must help me!"); break;
     }
    speech = 0;
   }
  
}
