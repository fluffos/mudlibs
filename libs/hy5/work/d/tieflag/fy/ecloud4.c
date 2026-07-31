 inherit ROOM;
void create()
{
        set("short", "东云路东");
        set("long", @LONG
这里又是乱哄哄的，有弹棉花的嗡嗡声也有小贩的叫卖声。大家似乎都忙忙碌
碌的，但好像又不知道忙些什么。南部有一个大水池，水色墨绿，散发着淡淡的青
烟。烟色迷离，这里的一切都笼罩在似乎不存在的烟中。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ecloud5",
  "west" : __DIR__"ecloud3",
"north" : __DIR__"mianhua",
"south" : __DIR__"ponder",
]));
        set("objects", ([
        __DIR__"npc/drugseller" : 1,
                        ]) ); 
        set("outdoors", "fengyun");
        set("coor/x",40);
        set("coor/y",0);
        set("coor/z",0);
        set("coor/x",40);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
