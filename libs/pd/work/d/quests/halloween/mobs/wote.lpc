#include <std.h>
#include <halloween.h>

inherit MONSTER;

int speech;
void create()
{
 ::create();
 set_name("witch of the east");
 set_short("%^CYAN%^%^BOLD%^Witch of the east%^RESET%^");
 set_long("The witch of the East is not an ugly witch, but rather "
          "beautiful.  Where she excells in her physical qualities, "
          "she lacks in intelligence and wisdom.  East is the weakest "
          "of the four witches, though to underestimate her could prove "
          "fatal.\n"
          "She is wearing:\n"
"%^BLACK%^%^BOLD%^Br%^RESET%^%^BOLD%^%^GREEN%^oo%^BLACK%^%^BOLD%^m"
           "st%^RESET%^%^BOLD%^%^GREEN%^i%^RESET%^%^BLACK%^%^BOLD%^ck "
           "%^RESET%^%^BOLD%^%^GREEN%^o%^BOLD%^%^BLACK%^f th%^RESET%^%^BOLD%^%^GREEN%^e"
           "%^RESET%^ %^BOLD%^%^BLACK%^e%^RESET%^%^BOLD%^%^GREEN%^as%^BOLD%^"
           "%^BLACK%^t%^RESET%^ (ridden)");

 set_id( ({ "witch", "witch of the east" }) );

 set_race("goblin");
 set_body_type("human");
 set_gender("female");
 set_level(10);
 set_stats("constitution", 99999999);
 set_hp(query_max_hp());
// set_moving(1);
// set_speed(20);
 new(OBJS "ebroom")->move(this_object());
 set_no_clean(1); 
} 

void catch_tell(string str)
{
 string a,b, pers;

 if (!str) return;
 str = lower_case(strip_colours(str));
 if (sscanf(str, "%s says: %s", pers, b)!=2) return;
  if(sscanf(b, "%shalloween%s", a, str)==2) {
    force_me("say MmmMmM candy.. *droools*");
    return;
  }
 if(sscanf(b, "%sbroomstick%s", a, str)==2) {
    force_me("say You want my broomstick? Be nice about it.");
    return;
  }
   if(sscanf(b, "%splease%s", a, str)==2) {
      force_me("say *blushes* Ok you can see it."); 
      force_me("give broomstick to "+pers);
      force_me("emote puffs in a cloud of smoke.");
      this_object()->remove();
      return;
    }
   if(sscanf(b, "%shave%s", a, str)==2) {
      force_me("say Have what?");
      return;
    }
   if(sscanf(b, "%sgive%s", a, str)==2) {
      force_me("say Give you what?");
      return;
    }

}
void heart_beat()
{ 
 ::heart_beat();
 
 if (speech++ > 10)
   {
    switch(random(3))
     {
      case 2: force_me("say D'uh i better not let you get all the broomsticks, then the arch would be mad."); break;
      case 1: force_me("emote starts counting her fingers."); break;
      case 0: force_me("say Isnt my broomstick pretty?"); break;
     }
    speech = 0;
   }
  
}
