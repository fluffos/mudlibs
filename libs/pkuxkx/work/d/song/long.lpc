// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", MAG"龙卫指挥使司"NOR);
	set("long", @LONG
这里是上四军之一——龙卫的帅帐。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"southwest" : "/d/hangzhou/palace/heningnei",
		//"north" : __DIR__"dianqiansi2",
		//"enter" : __DIR__"bingbucour",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
        //  __DIR__"npc/songbing_d" : 2,
		//__DIR__"npc/songbing_d2" : 2,
		__DIR__"npc/long_npc1" : 1,
		__DIR__"npc/long_npc2" : 1,
		__DIR__"npc/long_npc3" : 1,
        ])); 
	set("songtasks/task_myself","longwei");//任务mark
	set("songtasks/task_myid","龙卫");//任务军名
	set("songtasks/task_my_number",1);//任务编号
	set("songtasks/task_myjun_number",7);//任务军号
	set("songtasks/task_myjun_id","long wei");//任务军名号
	set("songtasks/task_weapon","枪");//军武器
	set("at_hangzhoupalace",1);
	setup();
}