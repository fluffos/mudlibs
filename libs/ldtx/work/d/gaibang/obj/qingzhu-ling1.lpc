// qingzhu-ling1.c 青竹令
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("青竹令", ({"qingzhu ling", "qingzhu", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是一面青竹令，由简长老签发，凭此可以和同门大师兄比
划。\n");
                set("material", "steel");
                set("no_give_user", 1);
                set("no_get", "那东西那不起来。\n");
        }
}
