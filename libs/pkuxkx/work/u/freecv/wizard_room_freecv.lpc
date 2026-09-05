//Use for:  freecv's happy palace
//Created By freecv 2004.4.3 PM   盗版zoom的
 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "freecv 小窝");
        set("sleep_room", "1");
        set("long","
这里就是英明神武英俊不高达智慧不动人的freecv的小窝了略微凌乱的床
显示出主人的不羁，铺满尘灰的书架透露着当家人的博学, 眼前是一个ppmm.
摇摇欲坠的桌上是一台冬天当空调夏季是暖气心乱时还可充作摇滚 music
mixer的电脑，据说里面大有古怪来到这里，你只觉得心旷神怡，说不出的
畅快，一个字：舒服 !!! \n\n\n"
       );
       set("valid_startroom",1);
      set("no_die",1);
        set("objects", (["/u/freecv/obj/fridge" : 1,
                   ]));
       set("exits", ([
//                "down"    : "/u/freecv/biwuchang",
                "east"   : "/d/wizard/wizard_room",
                "out":"/d/city/guangchang",
                "up":"/d/wizard/wizard_room_pal",
       ]));
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
    if ( !me->query("zyhb") ) me->set("zyhb",1);
        if (!wizardp(me) && me->query("id") != "freecv"&& me->query("id")!="feixuan")
                {
                return notify_fail("哈哈，这里岂是这么容易出去的，你就老老实实呆在这里吧:(\n");
                }
        else if (wizardp(me) && me->query("id") != "freecv")
                {
                  me->set("env/immortal",0);
                  me->set("combat_exp",1);
                  me->set("neili_max",1);
                  me->set("jingli_max",1);
                  me->set("int",1);
                  me->set("str",1);
                message_vision("此山慧自开，此树freecv栽，既从此处过，雁~~过~~拔~~毛！！！！！:(\n",me);
                }
return ::valid_leave(me, dir);
} 

void init()
{
    object ob=this_player();
    add_action("do_down","down");
    if (ob->query("id")!="freecv")
        ob->set("env/immortal",0);
}

int do_down()
{
    this_player()->move("/u/freecv/biwuchang");
    return 1;
}
