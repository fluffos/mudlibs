// Room: /d/gaochang/zoulang1.c

inherit ROOM;


string look_writing();


void create()
{
        set("short", "走廊");
        set("long", @LONG
这里是殿堂走廊。房顶一侧支在南面的高墙上，另一侧则与
北边殿堂的屋顶相连。彩梁画栋，连顶棚也用彩漆绘满了各种
飞天的图形，每幅画似乎都在诉说一个娓娓动人的故事。
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"zoulange",
                "southwest" : __DIR__"zoulangw",
                "north" : __DIR__"mishi",
                "westup" : "/d/hj/mg3",
        ]));
       set("objects", ([
                __DIR__"npc/wuaer": 1,
        ]));      
        set("item_desc",([
                "writing"                :        (: look_writing :),
        ]));
       setup();
     replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && (me->query_cor()<25) && !wizardp(me))
                return notify_fail("\n突然之间，前面一个阴森森的声音喝道：
「我在这里已安安静静的住了一千年，谁也不敢来打扰我。那一个大胆过来，立刻就
 死！」\n
你只觉得心头一寒，脚下直哆嗦，再也往前走不了一步。\n ");
        return 1;
}

