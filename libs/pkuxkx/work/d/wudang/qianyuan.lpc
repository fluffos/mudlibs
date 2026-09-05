// qianyuan.c 前院
// by llin
inherit ROOM;
void create()
{
        set("short", "前院");
        set("long",
"这儿是武当灵霄宫的前院，是武当嫡传弟子修习武功，切\n"
"磋比武的地方。武当弟子学习武功乃是为行侠仗义，惩恶扬善，\n"
"练功都十分刻苦。只见各人或跳或劈，或单打或对练。一位中\n"
"年人袖手站在一旁，不时出声加以指点。\n"
        );
        set("exits", ([
                "west" : __DIR__"ximen",
                "east" : __DIR__"guiquan",
                "south": __DIR__"houtang",
                "north": __DIR__"houyuan",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/yu" : 1,
		CLASS_D("wudang") + "/daotong" : 2,	
			__DIR__"npc/daoshi" : 2,
                ]));
        setup();
        replace_program(ROOM);
}
