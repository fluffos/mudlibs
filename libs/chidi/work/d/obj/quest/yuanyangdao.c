inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIR "鸳鸯刀" NOR, ({"yuanyang dao", "dao"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一对江湖上闻名的神秘飞刀。\n");
                set("unit", "对");
               set("owner_name","骆冰");
                 set("owner_id","luo bing");
        }
}

