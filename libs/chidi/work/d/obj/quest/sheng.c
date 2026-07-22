inherit ITEM;
#include <task.h>
void create()
{
        set_name("索命绳", ({"suoming sheng", "sheng"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这个绳子向你头上一套，你可就。。。。\n");
                set("unit", "个");
 set("owner_name",HIR "惊雷" NOR);
               set("owner_id","jing lei");
        }
}
