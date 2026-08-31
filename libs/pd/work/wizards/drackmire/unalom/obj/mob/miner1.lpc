#include <std.h>
#include "unalom.h"
inherit MONSTER;

void create()
{
  object key;
 ::create();

        set_name("dwarven miner");
        set_id(({"dwarf", "miner", "dwarfen miner" }));
        set_short("a dwarven miner");
        set_long("One of the dwarven miners stationed here on Unalom, "
        "he's here trying to mine the mysterious rocks that seem to "
        "to be ubiquitous on the island. He looks terrified about "
        "something as he bites his nails through his thick beard.");
        set_alignment(200);
        set_race("dwarf");
        set_property("transformed", 0);
        set_gender("male");
        set_body_type("human");
        set_level(30);
        set_says(8, ({ "The shadows here do weird things.  I don't like it.",
                  "A lot of my brothers have died in the mines here...people "
                   "say the shadows got them." }),0);
         
        
        key = new(OBJECT);
        key->set_name("key");
        key->set_id( ({ "shimmering key", "unalom key" }) );
        key->set("short", "a shimmering key");
        key->set("long", "The light seems to reflect off this key in weird ways.");
        key->set_weight(2);
        key->set_value(1);
        key->move(this_object());
        
        new(UNAWEAP"dwaxe")->move(this_object());
          command("wield axe");
        new(UNAARM"dwatunic")->move(this_object());
          command("wear tunic");
}
