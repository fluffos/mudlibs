#include <std.h>
inherit WEAPON;

int weapon_hit();

void create() {
::create();
    set_name("Blade of the Woods");

set_short("%^ORANGE%^B%^GREEN%^l%^ORANGE%^a%^GREEN%^d%^ORANGE%^e %^GREEN%^o%^ORANGE%^f %^GREEN%^t%^ORANGE%^h%^GREEN%^e %^BOLD%^%^WHITE%^W%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^o%^RESET%^%^GREEN%^d%^BOLD%^%^WHITE%^s%^RESET%^");
    set_long(
      "         / \\\n"
      "        {   }\n"
      "        p   !\n"
      "        ; : ;\n"
      "        | : |\n"
      "        | : |\n"
      "        l ; l\n"
      "        l ; l\n"
      "        I ; I\n"
      "        I ; I\n"
      "        I ; I\n"
      "        I ; I\n"
      "        d | b\n"   
      "        H | H\n"
      "        H | H\n"
      "        H I H\n"
      " ,;,    H I H      ,;,\n"
      ";H@H;   ;_H_;,    ;H@H;\n"
      "`\\Y/d_,;|4H@HK|;,_b\\Y/'\n"
      " '\\;WOODS$@@@$WOODS;/'\n"
      "  \"~~~\"*;!8@8!;*~~~\"\n"
      "        ;888;\n"
      "        ;888;\n"
      "        ;888;\n"
      "        ;888;\n"
      "        d8@8b\n"
      "        O8@8O\n"
      "        T808T\n"
      "         `~` \n"
      "The sword has \"%^GREEN%^I Belong To the beholder of the forest\" printed on the sword.\n");
        
    set_id(({"sword", "Blade of the Woods", "blade"}));
    set_mass(45);
    set_value(0);
    set_wield("%^GREEN%^You feel at one with nature.");
    set_unwield("%^ORANGE%^You feel the powers of nature leave your body.");
    set_type("blade");
    set_hands(1);
    set_wc(13);          // Weapon Class 12 2-handed, a mid's weapon
    set_ac(2);           // Armour Class 2, protects hands a lot
    set_hit((: weapon_hit :));
}
int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(102) > 75) {
write("%^BOLD%^%^GREEN%^Your Sword seems to shimmer as it strikes at your foe.");
result=(random(55+random(50)-random(50)))*((this_player()->query_level()/20)+1);

result=random(result)+1;
this_player()->add_hp(result);
return result;
}
return 0;
}

int query_auto_load()
{                                   
if (this_player()->query_level() > 10) return 1;
}
