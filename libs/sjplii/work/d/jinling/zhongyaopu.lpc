//jinling  zhongyaopu.c
inherit ROOM;

void create()
{
        set("short", "中药铺");
        set("long", @LONG
这里是一间中药铺，进得店来，一股药香扑鼻而来，另你精神为之一震。
这里的药品种类齐全，从珍贵的补药到平常的草药无一而不足。老板更是
一代圣手，你要是有什么伤痛病症来这里一定不错。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"xijie2",

]));
        set("objects", ([
		__DIR__"npc/yaoseller" : 1,
]) );

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}