#include <std.h>
inherit WEAPON;

int weapon_hit(object ob);

void create() {
::create();
    set_name("Syphon killer");
    set_short("Syphon killer");
    set_long(
      "\n"
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
      " '\\;MMMMM$@@@$MMMMM;/'\n"
      "  \"~~~\"*;!8@8!;*~~~\"\n"
      "        ;888;\n"
      "        ;888;\n"
      "        ;888;\n"
      "        ;888;\n"
      "        d8@8b\n"
      "        O8@8O\n"
      "        T808T\n"
      "         `~` \n"
      "The sword has \"Syphon will die\" printed on the sword\n");
        
    set_id(({"sword", "slayer", "syphon slayer"}));
    set_mass(900);
    set_value(180);
/*    set_type("blade"); */
    set_hands(2);
    set_wc(12);          // Weapon Class 12 2-handed, a mid's weapon
    set_ac(2);           // Armour Class 2, protects hands a lot
    set_hit((: weapon_hit :));
}

int weapon_hit(object ob)
{
 if ( ob->query_name() == "syphon" )
   {
    message("info",
      "The sword flames in hatred of syphon.\n", environment(ob));
    return 500;
   }
 return 1;
}

int query_auto_load()
{
 if (this_player()->query_level() > 10) return 1; else return 0;
}
