 inherit ROOM;
void create()
{
        set("short", "无名山");
        set("long", @LONG
在你面前是一座普通的山峰。一条不算很宽也不算很陡的山道
从北面向上延伸着。在左面的山石写着＂无名山＂三个大字。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road2",
  "eastdown" : __DIR__"sroad",
]));
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2000);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
} 
