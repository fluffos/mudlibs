//shichou.c
//by gudu
//2002.11.8
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj;
        string *killer;
        if( !arg )
                return notify_fail("你跟谁释仇啊？\n");
        obj = find_player(arg);
        if(!obj || !me->visible(obj)) 
                return notify_fail("这里没有这个人。\n");
        message( "channel:" + "chat",HIR + "【闲聊】" + me->query("name") + "幽幽地感慨了一声～～冤冤相报何时了～～：  " + obj->query("name") + "让我们冰释前嫌，重新做朋友吧!" + "\n"NOR,users());

        me->remove_all_killer(obj);
        return 1;
}


 


