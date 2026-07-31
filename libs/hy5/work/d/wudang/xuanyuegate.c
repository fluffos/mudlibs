//Room: xuanyuegate.c 玄岳门
//Date: Sep 22 1997

inherit ROOM;
#include <ansi.h>

void create()
{
      set("short","玄岳门");
      set("long",@LONG
你的面前是一座林木繁茂的高山，几座山峰在云雾中隐约可见，一条石
阶向山上延伸，走着几个进香客。一个四柱三间五楼式的石坊跨山而建，正
面镌有“治世玄岳”四个大字，原来这就是天下闻名的武当山。武当山一名
太和山，为七十二福地之一，有二十七峰、三十六岩、二十四涧、五台、五
井、三潭、三天门、三洞天和一福地，百里内密树森罗，蔽日参天，景物幽
绝。
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/zhike": 1,
           CLASS_D("wudang") +"/daotong": 2,
      ]));
      set("roomif","$botten#护卫任务|结束任务:volunteer|finish$#");   
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "east"     : __DIR__"slxl3",
          "southup"  : __DIR__"shijie1",
      ]));
      
      
//      set("no_clean_up", 0);
      setup();
}

void init()
{
        add_action("do_quit","quit");
        add_action("do_quit","halt");
        add_action("do_quit","learn"); 
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","persuade");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
        add_action("do_quit","study");
        add_action("do_quit","yandu");        
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
}
int valid_leave(object me, string dir)
{
        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
        if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");

        if (me->query_temp("in_guard") &&
                objectp(present("zhike daozhang", environment(me))))
           return notify_fail("知客道长拦住你说：值守时辰未到，不能擅离职守。\n");

        me->delete_temp("in_guard"); 
        me->delete("guardwd");
        remove_call_out("clone_meng");

        return ::valid_leave(me, dir);
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"，安心的守护！\n");
        return 1;
}
