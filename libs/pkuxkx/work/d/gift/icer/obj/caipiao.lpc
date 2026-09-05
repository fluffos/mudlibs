// caipiao.c 彩票
// by icer

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
        set_name(HIR +"名字"+ NOR, ({ "cai piao" }));
        set("long","这是一张名字，票号是Number。\n");
        set_weight( 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
set("value",1);
                set("no_store",1);
                set("no_pawn",1);
                set("no_sell",1);
                set("owner", "OWNER");
                set("auto_load", 1);
                set("material", "gold");
        }
        setup();
}       

string query_autoload()
{
        return query("name");
}

void autoload()
{
}



