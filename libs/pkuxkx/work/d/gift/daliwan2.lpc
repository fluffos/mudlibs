//tianyuebing  中秋月饼(加10000经验)
//Made By jason@mudnow.com
//2000-5.-6
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("大力丸",({"dali wan","wan"}));
        set("long","这是度每老先生亲自制作的大力丸(eat)?\n");
        set("unit","个");
        set("no_drop",1);
        set("no_get",1);
        set("value",0);
        set("no_store",1);
       setup();
}

void init()
{
    add_action("do_eat","eat");
}

int do_eat(string arg)
{
    object me;
    me = this_player();
message_vision(HIG"$N吃下一个大力丸,觉得突然理解了很多原来想不通的问题,"+HIR"$N的战斗经验增加了!\n"NOR,me);
        me->add("combat_exp",10000);
        destruct(this_object());
     return 1;
}
