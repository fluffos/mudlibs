#include <std.h>
inherit MONSTER;

void create() {
::create();
    
set_name("master dragon");
set_short("%^BOLD%^%^RED%^Master %^YELLOW%^D%^RED%^r%^YELLOW%^a%^RED%^k%^YELLOW%^e%^RESET%^");
set_long("%^RED%^The massive dragon your are looking at is a legend to its own kind."
" Drake has ruled over all dragons for over two centuries.  Theres not another dragon alive that"
" would ever dare test his power and strength..%^RESET%^");
    set_id(({"dragon","drake"}));
    set_level(99);
    set("aggressive", 25);
    set_race("dragon");
    set_class("dragon");
    set_subclass("red");
    set_skill("attack", 445);
    set_skill("defense", 544);
    set_skill("melee", 495);
    set_skill("breath", 445);
    set_skill("claw", 396);
    set_spell_chance(50);
    set_spells(({"flameclaw","breathe"}));
    set_body_type("dragon");
    set_gender("male");
    set_exp(150000);
if(random(10) == 0)
new("/wizards/shinkoro/pkcave/armour/mystical_plate")->move(this_object());

}
