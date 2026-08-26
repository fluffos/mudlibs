#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
    ::create();
    set("short", "The King of Tormeid") ;
    set("long", @ENDLONG
This is the mighty King of Tormeid.  He rules the castle with an iron fist
and a kind heart.  He is a wise and noble man.  He carries with him the
mighty Sceptre of Tormeid, an ancient and powerful artifact passed down 
in the Royal family for centuries.
ENDLONG
    );
    set("id", ({ "man", "king" }) ) ;
    set("gender", "male");
    set("race", "human");
    set_name("king of Tormeid") ;
    credit(random(83) * random(83) + 1000) ;
    set_alignment("ln") ;
    set("damage", ({ 2, 4 }) );
    set_size( 6);
    set("stat/constitution", 18);
    set("stat/strength", 18);
    set_skill("Clubbing Weapons", 5, "strength");
    set_skill("One Weapon Style", 2, "Strength");
set("CLASS", "warrior");
    set("armor_class", -2);
    set("base_ac", -2);
    set("weapon_name", "fists");
    set("stat/intelligence", 17) ;
    set("stat/wisdom", 17) ;
    set("stat/charisma", 17) ;
    set_level(60);
    set_verbs( ({ "swing at", "attack" }) );
    arm(WEP(royal_sceptre), "sceptre") ;
    wear(ARM(crown), "crown") ;
    wear(ARM(king_robes), "robes") ;
    wear(OBJ(king_key), "key") ; // i know its not armor.
    wear(ARM(king_ring), "ring") ;
    wear(ARM(regen_ring), "ring") ;
}


int query_king() {return 1; }
