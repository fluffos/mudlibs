//jinling  wuqidian.c
inherit ROOM;

void create()
{
        set("short", "武器店");
        set("long", @LONG
这里是金陵城的武器店。出售各种兵器，虽没有什么神兵利器，但所做的
的兵器也都可以称的上是利器，而且种类齐全，价格适中，深受江湖人事的
欢迎。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"beijie2",

]));
        set("objects", ([
		__DIR__"npc/tiejiang" : 1,

			]) );

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}