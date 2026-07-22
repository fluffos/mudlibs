//jinling  yantang.c
inherit ROOM;

void create()
{
        set("short", "燕堂");
        set("long", @LONG
这里建筑古朴典雅，堂内悬挂王导、谢安画像，仕子游人不断，是一个相
当另人怀古的一个所在。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"wuyigang",

]));
        set("objects", 
        ([ //sizeof() == 1
		__DIR__"npc/wangwei" : 1,
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}