
inherit ROOM;

void create()
{
        set("short", "无名山脚");
        set("long", @LONG
在你面前是一座普通的山峰。一条不算很宽也不算很陡的山道
从北面向上延伸着。在左面的山石写着＂无名山＂三个大字。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road2",
  "southwest" : "/d/road/cqdukoub",
]));
        set("outdoors", "taoguan");
        setup();
        replace_program(ROOM);
}
