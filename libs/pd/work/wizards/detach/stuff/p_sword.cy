#include <std.h>
inherit WEAPON;

int weapon_hit(object ob);

void create() {
::create();
    set_name("Blade of the Woods");

set_short("%^ORANGE%^B%^GREEN%^l%^ORANGE%^a%^GREEN%^d%^ORANGE%^e %^GREEN%^o%^ORANGE%^f %^GREEN%^t%^ORANGE%^h%^GREEN%^e %^BOLD%^%^WHITE%^W%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^o%^RESET%^%^GREEN%^d%^BOLD%^%^WHITE%^s");
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
    set_type("blade");
    set_hands(1);
    set_wc(12);          // Weapon Class 12 2-handed, a mid's weapon
    set_ac(2);           // Armour Class 2, protects hands a lot
    set_hit((: weapon_hit :));
}

int weapon_hit(object ob)
{
 if ( ob->query_subclass() != "ranger" )
   {
    if(random(102) > 75) {
     {
     message("info",
      "%^BOLD%^%^GREEN%^Natural engery begins to fill the room as the Blade of the Woods shimmers, and strikes at its foe.\n", environment(ob));
    {
result=random(result)+1;
this_player()->add_hp(result);
return result;
}
return 0;
}
