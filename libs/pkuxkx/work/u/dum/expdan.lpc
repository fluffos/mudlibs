//tianyuebing  中秋月饼(加10000经验)
//Made By jason@mudnow.com
//2000-5.-6
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("经验丹",({"expdan","dan"}));
        set("long","这是度每老先生亲自制作的经验丹(eat)?\n");
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
    if ( (int)me->query("wuyi/expdan" ) > 0 ) return notify_fail("你已经拿过礼物了，为人不能贪得无厌，是不是？\n");
message_vision(HIG"$N吃下一个经验丹,觉得突然理解了很多原来想不通的问题,"+HIR"$N的战斗经验增加了!\n"NOR,me);
        me->add("combat_exp",10000);
       me->set("wuyi/expdan",1);
        destruct(this_object());
     return 1;
}
