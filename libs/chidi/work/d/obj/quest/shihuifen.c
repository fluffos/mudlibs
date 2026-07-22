inherit ITEM;

#include <task.h>
void create()
{
        set_name(HIW "石灰粉" NOR, ({"shihui fen", "fen"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "普通江湖人用的石灰粉。\n");
                set("unit", "包");
                 set("owner_name","小桂子");
                 set("owner_id","xiao guizi");
        }
}


