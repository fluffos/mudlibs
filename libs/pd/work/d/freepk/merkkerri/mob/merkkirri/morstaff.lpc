#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"staff", "morbid staff", "morbid"}));
set_name("morbid staff");
set_short("%^BLUE%^Mor%^YELLOW%^b%^BLUE%^id %^RESET%^BLUE%^Sta%^YELLOW%^f%^BLUE%^f%^RESET%^");
set_long("This staff is carved of ivory.  It is inlaid with strange figurings of elves twisting and writhing in agony.  The staff is noticeably heavy.");
set_weight(25);
set_curr_value("platinum",1);
set_wc(9);
set_ac(1);
set_type("blunt");
set_hands(2);
set_wield("%^RESET%^MAGENTA%^The ivory changes color to %^BOLD%^RED%^blood red%^RESET%^MAGENTA%^.%^RESET%^");
set_unwield("The ivory changes back to its original %^WHITE%^white%^RESET%^ shade.");
set_hit((:weapon_hit:));
}

int wieldMe(string oi) {
   object ob;
   if (!oi) return 0;
   ob = present(oi, this_player());
   if (ob != this_object()) return 0;
   if (this_player()->query_class() != "mage") {
      message("info", "Only a magician could handle the power in this staff.", this_player());
      return 1;
   }
   return 0;
}

void init() {
 ::init();
   add_action("wieldMe", "wield");
}

int weapon_hit(object atk)
{
int result;
if(random(100) > 91) {
write("%^BLUE%^The figurines upon the staff writhe in agony!\nAfter a flash of %^BOLD%^blue%^RESET%^BLUE%^ light, you feel more revitalized!%^RESET%^");
say("%^BLUE%^The figurines upon "+(string)this_player()->query_cap_name()+"'s staff writhe in agony!\nAfter a flash of %^BOLD%^blue%^RESET%^BLUE%^ light, "+this_player()->query_cap_name()+" looks revitalized. %^RESET%^");
result=(this_player()->query_skill("magic attack")/4+(random(this_player()->query_stats("intelligence"))));
this_player()->add_mp(result);
return result;
}
}
