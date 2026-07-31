#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", "商家堡大厅");
	set("long", @LONG
这里是商家堡的大厅，大厅内很是宽敞明亮，地上刻有一个
巨大的铁八卦。正对厅门摆放着一张八仙桌，一人压座中堂，身
材高大魁梧，留着短须，神情甚为严肃，正是「八卦刀」商剑鸣。
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_houting",
		"south"  : __DIR__"shang_xiaojin2",
		"east"  : __DIR__"shang_tinge",
		"west"  : __DIR__"shang_tingw",
	]));
        set("objects", ([
                __DIR__"npc/ming" : 1,
                __DIR__"npc/shang2" : 4,
        ]));
        
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();

}
int valid_leave(object me, string dir)
{
	if ( objectp(present("shang jianming", environment(me))) && 
		dir == "north")
		return notify_fail("商剑鸣拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}


