// 宴客厅 Zine
#include <ansi.h> 
inherit ROOM;
#include "/d/quanzhou/yanketing.h"
void create()
{
	set("name", "宴客厅");
	set("short", "宴客厅");
	set("long", @LONG
这里是醉仙楼新开设的宴会厅，装修的古色古香，金碧辉煌。窗外的风景宜
人，几个城里最红的清伶正在表演着歌舞。这里一人一席，客人一落座(luozuo)
马上就会有小厮端上酒水。
LONG);


	set("objects", ([
    //            __DIR__"npc/xian" : 1,
	//	__DIR__"npc/guidao" : 1,
	//	__DIR__"npc/identifier" : 1,
                /*CLASS_D("gaibang") + "/kongkong" : 1,*/
	]));
    set("no_task",1);
    set("no_fight", 1);
	set("no_perform", 1);
	set("no_steal", 1);
	set("no_sleep_room", 1);
	set("exits", ([
                "east" : __DIR__"guodao",
               
	]));
    set("yanke_no","yanke");
    set("palace","醉仙楼");
    set("leave_path","east");
	setup();
	
}
