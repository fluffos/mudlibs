#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("Arlon housewife");
    set_short("A young housewife");
    set_long("This young human woman looks to be in her late 20s, early 30s.  Her hair is long and blonde, a trend amongst the housewives of Arlon.  She is fairly tall, with a slender figure.");
    set_id(({"arlon housewife", "housewife", "wife", "human housewife", "arlonhousewife"}));
    set_level(3+random(4));
    set_race("human");
    set_body_type("human");
    set_gender("female");
    set_class("mage");
    set_subclass("pyromancer");
   new(ARM"silkdress")->move(this_object());
     force_me("wear dress");
   new(ARM"platinumring")->move(this_object());
     force_me("wear ring");
   new(ARM"diamondbracelet")->move(this_object());
     force_me("wear bracelet");
    add_money("gold", 25+random(75));
    set_spell_chance(10);   
    set_spells(({"missile"}));   
}



