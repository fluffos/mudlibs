//放逐岛 shanding

#include <ansi.h>
#include <room.h>
inherit FANGZHU_ROOM; //放逐岛继承文件，不是普通的room

void create ()
{
  set ("short","放逐岛");
  set ("long", @LONG

这里是人迹罕至的放逐岛，荆棘丛生，一片荒芜，只有豺狼猛兽，
极难见到半个人影。
LONG);
        
        set("outdoors", "fangzhudao");
        set("exits", ([ /* sizeof() == 4 */             
                "enter" : __DIR__"shandong",            
        ]));
        
        set("objects", ([ /*     */   
        ]));
  
        set("alternative_die",1); 
        set("fangzhuroom",1); 
//放逐岛房间标志，cmds npc 判断所需！
        
        setup();
        setup2();
}

void init2()
{
}

void init()
{
        add_action("do_jump", "jumpdown");
}

int do_jump()
{
        object me=this_player();
        
        if(me->is_busy())
                return notify_fail("你忙的过来吗？\n");

        message_vision("$N鼓足勇气跳下山崖。\n", me);
        me->start_busy(2);

        call_out("success", 3, me);
        return 1;
}

int success(object me)
{
        message_vision("$N轻飘飘的落到地下。\n", me);
        me->move(__DIR__"shanjiao");
        me->receive_damage("kee", 300);
        me->receive_damage("sen", 300);
        return 1;
}
