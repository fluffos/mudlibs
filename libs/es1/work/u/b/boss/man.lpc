#include <mudlib.h>
#include <ansi.h>
inherit MONSTER ;

void create()
{
        ::create();
        set_level(1);
        set_name("richman",""+HIB"富人"+NOR"");
        add( "id", ({ "rat" }) );
        set_short(""+HIB"富人"+NOR"");
        set_long(""+HIR"波士的老大，很刻薄。"+NOR"\n");
        set("unit", "只");
        set_perm_stat("int", 1);
        set ("wealth", ([ "gold": 30000 ]) );
    equip_armor( "/d/mage/tower/armors/wizard_amulet" );
    equip_armor( "/d/mage/tower/armors/wizard_robe" );
    equip_armor( "/d/mage/tower/armors/wizard_shoe" );
    equip_armor( "/d/mage/tower/armors/wizard_cloak" );
    equip_armor( "/d/mage/tower/armors/wonderful_hat" );
    equip_armor( "/d/island/forest/obj/leggings" );
    equip_armor( "/d/eastland/saulin_temple/obj/eagle_bracer" );
    equip_armor("/d/monk/guild/armors/holy_ring");
}
