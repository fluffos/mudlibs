#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"明教令牌"NOR, ({"mingjiao ling"}));
        set("unit", "块");
        set("long", "一快从明教首领身上抢来的令牌。\n");
        set("value", 0);
        setup();
}

