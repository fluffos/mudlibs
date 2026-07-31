// /u/dubei/sdxl/muwu
// by dubei
 
inherit ROOM;
int do_zhao(string arg);

void create()
{
        set("short","木屋");
        set("long", @LONG
这是一间普通的小木屋，屋里乱七八糟堆放着一些猎人们
常用的物品，屋内光线暗淡，墙角有一堆点燃的篝火显然刚刚
熄灭。
LONG                           
        );
 
        set("exits", ([
                "out" : __DIR__"conglin4",
 
        ]));
 
        set("zhi_count", 1);

        setup();

}

void init()
{
        add_action("do_zhao", ({"zhao","find"}));
}

int do_zhao(string arg)
{
        object me=this_player();

        if ( arg != "枯树枝" )
            return notify_fail("你要找什么？\n");
        if (query("zhi_count") > 0) 
          {
           message_vision("$N在墙脚里翻出一些枯树枝。\n", me);
           add("zhi_count", -1);
 
           new(__DIR__"obj/kusz")->move(me);
          }
        else
           message_vision("$N翻来翻去什么也没找着。\n", me);
     return 1;
}
