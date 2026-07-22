// huwan.c
// caiji@SJ 8/27/2000 根据少林护腕修改，如感觉雷同的话，请帮忙CUT。

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name( "翡翠护腕", ({ "feicui huwan", "huwan" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一双能增强防御能力的护腕。\n");
                set("value", 6000);
                set("material", "wrists");
                set("armor_prop/armor", 4);
                set("wudang",1);
        }
        setup();
}
