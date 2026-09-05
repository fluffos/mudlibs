// yiru@hero
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
    set_name(HIW "飞星传恨" NOR, ({ "star","sword" }) );
    set_weight(3000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "柄");
        set("long", "一柄寒光闪闪的宝剑。\n");
        set("value", 0);
        set("rigidity",3000);
        set("no_drop", 1);
        set("no_get", 1);
        set("owner", "yiru");
        set("material", "steel");
        set("wield_msg", "只见寒光一闪，$N手中的$n已然出鞘！\n");
        set("unwield_msg", "$N手中的$n悄无声息的入鞘了。\n");
        set("weapon_prop/courage", 30);
        set("weapon_prop/spirituality", 3);
        set("max_enchant",3);
    }
    init_sword(30);
    setup();
}

int query_autoload() { return 1; }


