// Room: chanfang.c
#include <ansi.h>  
inherit ROOM;

void create()
{
        set("short",HIW"扬州产房"NOR);
        set("long", @LONG
这是一间专门为孕妇准备的产房,你的妻子要生Baby就赶快来哟。
LONG
        );
        set("no_fight",1);
        set("no_sleep_room",1);
        set("no_steal",1);
        set("no_beg",1);
        set("no_study",1);
        set("no_yun",1);

        set("exits", ([
           "down":  __DIR__"yaopu"
        ]));

        setup();
}



void init()
{
       add_action("do_ling","ling");
}

int do_ling(string arg)
{
       object me=this_player(),baby;
       string file;

       if( !arg || (arg != "baby" && arg != "child") ) return 0;

       if( !me->query("couple/child") )
       return notify_fail("你又还没有孩子，来这里凑什么热闹啊？\n");

       if( objectp( baby=find_living(me->query("couple/child")))
          && environment(baby) && baby->query("is_baby") )
       return notify_fail("你们的孩子已经被领走了，好好四处找找吧！\n");

       if( me->query("gender") == "女性" )
       file=read_file("/data/baby/"+me->query("id")+".o");
       else file=read_file("/data/baby/"+me->query("couple/couple_id")+".o");

       if( stringp(file) )
       {
         baby=new("/clone/user/baby");

         baby->load_baby(me);
         baby->move(environment(me));
         message_vision(HIY"$N从产房的临时托儿所把自己的BABY"
                        +"领了回来。。\n"NOR,me);   

       } else
       {
         tell_object(me,MAG"你们的孩子不幸夭折了，请节哀吧。\n"NOR);
         me->delete("couple/child");
       }
       return 1;
}      





