#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(HIW"武器领取令牌"NOR, ({ "wuqi ling", "ling" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一个两寸长的令牌,上面刻着[武器]两个大字。\n");
        }
}

