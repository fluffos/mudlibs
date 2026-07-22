inherit ITEM;
#include <task.h>
void create()
{
        set_name("水壶", ({"shui hu", "hu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "虚竹用的水壶。\n");
                set("unit", "个");
               set("owner_name","虚竹");
               set("owner_id","xu zhu");
        }
}
