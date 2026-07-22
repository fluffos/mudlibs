// longling.c 青龙堂令牌
#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(HIY"青龙堂令牌"NOR, ({ "long ling", "ling" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一个两寸长的令牌,上面刻着[青龙]两个大字。\n");
        }
}

