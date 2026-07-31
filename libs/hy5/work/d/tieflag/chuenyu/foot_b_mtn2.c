 // Room: /d/chuenyu/foot_b_mtn.c
inherit ROOM; 
void create()
{
        set("short", "黑松山腰");
        set("long", @LONG
你正在艰难的走在唯一通往山顶的小路上。路边堆着很多面目
狰狞的巨石。几棵幼松顽强的从石缝中挤了出来。你在这
里可以看到山顶城堡的大致轮廓。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"foot_b_mtn",
  "up" : __DIR__"high_b_mtn",
]));
        set("outdoors", "chuenyu"); 
        set("coor/x",110);
        set("coor/y",140);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
} 
