// bailing.c 白虎堂令牌
#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(HIW"白虎堂令牌"NOR, ({ "bai ling", "ling" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是个两寸长的令牌,上面刻着两个大字[白虎]。\n");
        }
}

