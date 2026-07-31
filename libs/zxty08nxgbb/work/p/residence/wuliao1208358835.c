inherit ROOM;
void create()
{
set("short", "休息室");
set("long", @LONG
这里是魔宫休息的地方。这里非常宽敞，一共是四间屋子连在
了一起，共摆放了大大小小十几张床。靠窗子的地方来放了几张桌子、
椅子，有几个人正在那里喝茶、聊天。

LONG
);
        set("exits", ([
"south" : "/p/residence/wuliao1208358416.c",
]));
set("objects", ([
       ]) );
        set("owner", "bigtie7001");
//        set("class", "$HIC$圣剑$HIR$魔宫");
        set("banghui", "$HIC$圣剑$HIR$魔宫");
        set("no_fight",1);
        set("sleep_room", "1");

setup();
}


