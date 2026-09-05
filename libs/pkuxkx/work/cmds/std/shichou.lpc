//shichou.c
//by gudu
//2002.11.8
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>
inherit F_CLEAN_UP;

int refresh(object me)
{
    me->delete_temp("释仇");
    return 1;
}

int main(object me, string arg)
{
        object obj;
        string *killer;
        
        if( !arg )
                return notify_fail("你跟谁释仇啊？\n");
        obj = find_player(arg);
        if(me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if(me->query("jingli")<80)
                return notify_fail("你现在精力不足呀？\n");
        if(!obj || !me->visible(obj)) 
                return notify_fail("这里没有这个人。\n");
        if (obj==me) //shichou自己不合理 Zine 
        {
            return notify_fail("那么恨自己不如插自己几刀啊！\n");
        }
        if (me->query_temp("释仇")) //禁止flood刷屏 Zine
        {
            return notify_fail("歇会再喊吧，别老是flood频道。\n");
        }
        message( "channel:" + "chat",HIR + "【闲聊】" + me->query("name") + "幽幽地感慨了一声～～冤冤相报何时了～～：  " + obj->query("name") + "让我们冰释前嫌，重新做朋友吧!" + "\n"NOR,users());
        me->set_temp("释仇",1);
        call_out("refresh",5,me);
        me->add("jingli",-20);
        me->remove_killer(obj);
        return 1;
}


 


