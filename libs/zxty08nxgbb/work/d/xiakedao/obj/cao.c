// cao.c
inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("腐心草", ({"fuxin cao","cao"}));
        set("unit", "根");
        set("long", "这是一朵无根小草,长得很小,却给人一种欣欣向荣的感觉。\n");
        setup();
}
int do_eat(string arg)
{
//        int force_limit, neili_limit;
        if (!id(arg))  return notify_fail("你要吃什？\n");
        if(arg=="cao")
        {
               message_vision(HIG "生吃腐心草? 熬了粥再喝吧...\n" NOR, this_player());
//               force_limit = this_player()->query_skill("force",1)*10;
//               neili_limit = this_player()->query("max_neili");
//               if ( neili_limit <= force_limit  )
//               {
//                      this_player()->add("max_neili",5);
//                      this_player()->unconcious();
//               }
//               message_vision(HIG "$N吃下一株腐心草，顿然间有点肚子疼...\n" NOR, this_player());
//               destruct(this_object());
        }
        return 1;
}
