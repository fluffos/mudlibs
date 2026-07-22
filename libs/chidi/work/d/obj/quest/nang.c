inherit ITEM;
#include <task.h>
void create()
{
        set_name("三字经", ({"san zijing", "jing"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "朱丹臣的书本。\n");
                set("unit", "个");
               set("owner_name","朱丹臣");
               set("owner_id","zhu danchen");
        }
}
