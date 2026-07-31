 inherit ROOM;
void create()
{
        set("short", "南风街");
        set("long", @LONG
街道就象水洗过那么的干净，汉白玉砌的路面光明如镜，两侧的瓦房高大宏伟，
双人合抱的杨树十步一株，整齐的排在两边。大街西面一对千斤巨鼎，悬挂在朱门
两旁，这里就是金钱帮的总舵。大街东面巨宅上有一高高的十字架，一些金发碧眼，
身披黑袍的人不时的出出入入。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind3",
  "north" : __DIR__"swind1",
  "east" : __DIR__"church",
  "west" : __DIR__"jinqian",
]));
        set("objects", ([
                __DIR__"npc/dtz1" : 2,
                __DIR__"npc/patrol_soldier": 1,
       ]) );
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
