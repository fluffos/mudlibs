//放逐岛 shanjiao

#include <ansi.h>
#include <room.h>
inherit FANGZHU_ROOM; //放逐岛继承文件，不是普通的room

string *list=({
        "tiger","fox","wolf","heibao","pig",
});

void create (int num)
{
  set ("short", "放逐岛");
  set ("long", @LONG

这里是人迹罕至的放逐岛，荆棘丛生，一片荒芜，只有豺狼猛兽，
极难见到半个人影。这里是岛上唯一的一座荒山的山脚下，杂草
丛生，没有一点生命的痕迹。
LONG);
        num=random(3)+4;        
        set("outdoors", "fangzhudao");
        set("exits", ([ /* sizeof() == 3 */
                "west" : __DIR__"fangzhudao30",
        ]));
        set("objects", ([
                __DIR__"npc/heibao" : 1,
                __DIR__"npc/pig" : 1,
                __DIR__"npc/tiger" : 1,  
                __DIR__"npc/fox":1,             
        ]));
  
        set("alternative_die",1); 
        set("fangzhuroom",1); 
        set("npc_num",num);//自己可以设定！
        set_heart_beat(300);
        setup();
        setup2();
}

void init2()
{
}

void heart_beat()
{      
        reset();
}

/* 以下是更新时间、 内容的设定*/
void reset() 
{
        object guai;
        int i;
 
        this_object()->add_temp("npc_times",1);
        if (this_object()->query_temp("npc_times")>10){
                this_object()->set_temp("npc_times",1);
                if(this_object()->qurey("npc_num")> 0){
                        for(i=0;i<this_object()->query("npc_num");i++) { 
                                guai = new("/d/quest/fangzhudao/npc/"+list[random(sizeof(list))]);
                                guai->move(this_object());
                        }
                }
        }
        ::reset();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me=this_player();

        if( !arg || (arg!="hill") )
                return notify_fail("你要爬什么？\n");
        if(me->is_busy())
                return notify_fail("你很忙，爬什么呀！\n");

        message_vision("$N搓了搓手，扒着石头的缝隙向山上爬去。。。\n", me);
        me->start_busy(3);

        if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
                call_out("faila", 3, me);
                return 1;
        }

        if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=150 ){
                call_out("faila", 3, me);
                return 1;
        }

        call_out("success", 3, me);
        return 1;
}

int success(object me)
{
        message_vision("$N越爬越高，渐渐隐入了云中。。。\n", me);
        me->move(__DIR__"shanding");
        me->receive_damage("kee", 300);
        me->receive_damage("sen", 300);
        message_vision("$N慢慢的爬了上来。\n", me);
        return 1;
}

int faila(object me)
{

        tell_object(me, "你手上一个不稳，从山上掉了下来。。。\n");
        tell_room(environment(me), me->name()+"晃悠悠的从山上掉了下来。\n", ({me, me}));
        
        return 1;
}
