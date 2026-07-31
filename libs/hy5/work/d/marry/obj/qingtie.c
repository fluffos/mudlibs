// qingtie.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(BOLD HIR"请帖"NOR, ({ "qing tie","tie" }) );
        set_weight(3);
        set("value", 0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一张参加婚礼用的请贴。\n
上面写着：请阁下于三日内在扬州武庙座马车参加婚礼。\n");
                set("unit", "张");
        }
}
