
#include <discastle.h>
inherit MONSTER;

void create() 
{
        ::create();
        set_name("bell");
set("short", "The bellhop");
        set("long", "He looks tired. Apparently this young man isn't used to dealing with the amount of customers that the Mad Cow Inn seems to get every day.");
        set("id", 
                ({"monster","bell hop", "manager"})
        );
        set("race", "human");
        set_body_type("human");
        set_gender("male");
                set_class("fighter");
        set_subclass("berserker");
        set_spell_chance(40);
        set_spells( ({"rage"}) );
        new(ITEMS"keyring")->move(this_object());
        add_money("gold", 50);     
        add_money("platinum", 5);

        set_languages( ({"selunian"}) );
        set_speech(5, "selunian",
        		 ({"The bar is to the east",
                "Sorry, we're out of rooms",
                "Wow, lots of bandits, huh?"}),
                0);
        set_level(45);

}                                            


