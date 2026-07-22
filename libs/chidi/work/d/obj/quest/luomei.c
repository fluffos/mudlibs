inherit ITEM;

#include <task.h>
void create()
{
 set_name(HIY "玉笛谁家听落梅" NOR, ({"luo mei", "mei"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一道菜，是黄容为洪七公所做。\n");
set("unit", "道");
               set("owner_name","洪七公");
               set("owner_id","hong qigong");
        }
}


