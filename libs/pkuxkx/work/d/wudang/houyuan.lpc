// qianyuan.c 后院
// by llin
inherit ROOM;
void create()
{
        set("short", "后院");
        set("long",
"这儿是武当灵霄宫的后院，是武当嫡传弟子修习武功，切\n"
"磋比武的地方。武当弟子如在武学上有何不明了之处，总会在\n"
"此处找到长辈得到点拨。只见院中不少道士，互相切磋比划武\n"
"艺，甚是热闹。北面是一道残旧的小木门。西面是一间大屋子，\n"
"门窗紧闭。东边不知是什么所在，依稀飘来一丝幽幽的茶香。\n"
        );
        set("exits", ([
                "west" : __DIR__"xilang",
                "east" : __DIR__"donglang",
                "south": __DIR__"qianyuan",
                "north": __DIR__"houmen",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/yin" : 1,
		CLASS_D("wudang") + "/daotong" : 2,	
			__DIR__"npc/daoshi" : 2,
                ]));
        setup();
        replace_program(ROOM);
}
