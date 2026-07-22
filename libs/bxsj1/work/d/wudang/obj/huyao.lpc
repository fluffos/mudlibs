// huyao.c
// caiji@SJ 8/27/2000 根据少林护腰修改，如感觉雷同的话，请帮忙CUT。

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        set_name(HIR "丹凤护腰" NOR, ({ "danfeng huyao", "huyao" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条用坚韧之皮革制成的高级护腰，正面有一条火红的凤凰。\n");
                set("value", 6000);
                set("material", "waist");
                set("armor_prop/armor", 4);
                set("wudang",1);
        }
        setup();
}
