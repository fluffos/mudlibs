inherit ITEM;

#include <task.h>
void create()
{
set_name(HIM "可兰经" NOR, ({"kelan jing", "jing"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一本回族的圣经。\n");
                set("unit", "本");
 set("owner_name",MAG "霍青桐" NOR);
               set("owner_id","huo qingtong");
        }
}


