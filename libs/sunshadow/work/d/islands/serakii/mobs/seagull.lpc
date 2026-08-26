//Seagull - LoKi - 2021



#include <std.h>
#include "../serakii.h"
inherit MONSTER;

int head_home;

void create()
{
   ::create();
   set_name("ragged seagull");
   set_short("%^C244%^ra%^C251%^g%^C244%^"+
   "g%^C222%^e%^C244%^d s%^C094%^e%^C244%^"+
   "agu%^C221%^l%^C244%^l%^CRST%^");
   set_id(({"seagull","bird","ragged seagull"}));
   set_long("%^C246%^This bird is a truly %^C100%^"+
   "sad %^C246%^sight. Its wings are %^C095%^"+
   "ragged %^C246%^and %^C250%^missing feathers%^C246%^ "+
   "and its body is lean and %^C088%^malnourished%^C246%^. "+
   "A %^C228%^lean sharp yellow%^C246%^ beak looks like "+
   "it might hurt but the bird isn't aggressive and "+
   "instead pokes around the streets of the %^C251%^"+
   "town%^C248%^ %^C246%^looking for %^C094%^"+
   "food%^C246%^. %^CRST%^\n");
   set_gender("female");
   set_race("seagull");
   set_body_type("fowl");
   set_hd(1,5);
   set_exp(1);
   set_emotes(10,({
      "%^C111%^Wind %^C247%^whips %^C111%^through the %^C094%^empty %^C111%^streets.%^CRST%^\n",
      "%^C058%^The %^C254%^seagull%^C058%^ picks at something on the %^C094%^ground%^C058%^.%^CRST%^\n",
      "%^C162%^The %^C254%^seagull %^C162%^cries out and %^C247%^flaps %^C162%^around.%^CRST%^\n",
        }),0);
   command("message in flies in");
   command("message out flies ");
   set_speed(9);
   set_nogo(({ROAD"11"}));
   call_out("head_home",400+random(100));

}

int head_home()
{
   tell_room(ETO,"The seagull flies away");
   TO->move("/d/shadowgate/void");
   destruct(TO);
   return 1;
}
