// Room: /d/wudang/yudaiyan.c
// By llin 04/01/96 

inherit ROOM;

void create()
{
    set("short", "俞岱岩住处");
    set("long", 
"这里是院落东侧的一间清净的厢房，武当三侠－－俞岱岩\n"
"就住在这里。他遭奸人所害，本已肢体尽废，幸得张无忌取得\n"
"黑玉断续膏加以医治，尽管如此行动仍是不便，整日在房中静\n"
"养；一个小道童在旁伺候着，南面炼丹房是三侠平时研究药理\n"
"用的。\n"
    );

    set("exits", ([
	    "west" : __DIR__"donglang",
	    "south" : __DIR__"danfang"
    ]));
	set("objects",([
		CLASS_D("wudang") +"/yudaiyan" : 1,
		CLASS_D("wudang") +"/daotong" : 1,
		]));                                                    
    setup();
}


