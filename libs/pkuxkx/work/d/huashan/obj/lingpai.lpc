// paper.c
inherit ITEM;
#include <ansi.h>
int checkenv();
void create()
{
        set_name("令牌", ({"ling pai", "ling"}));
        set_weight(100);
        set("unit", "块");
        set("long","这是一块木制的令牌，华山弟子通常拿着这个令牌巡山。\n");
        set("material", "wood");
        set("is_ling",1);
        setup();
        call_out("checkenv",1);
}

int checkenv()
{
    object ob=this_object();
    object me=environment(ob);
    object env;
    string roomid;
    if (!me)
    {
        destruct(ob);
        return 1;
    }
    if (!userp(me))
    {
        message_vision("$N被丢在了路边，渐渐被杂物掩盖。\n",ob);
        destruct(ob);
        return 1;
    }
    if (!me->query_temp("hsnewbiejob/xunshan/start"))
    {
        return 1;
    }
    env=environment(me);
    if (env->query("room"))
    {
        roomid=env->query("room");
        if (!me->query_temp("hsnewbiejob/xunshan/rooms/"+roomid))
        {
            message_vision("$N在"+env->query("short")+"巡弋，尚未发现敌踪。\n",me);
            me->set_temp("hsnewbiejob/xunshan/rooms/"+roomid,1);
        }
    }
    remove_call_out("checkenv");
    call_out("checkenv",1+random(4));
    return 1;
}

