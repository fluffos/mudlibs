// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "/d/song/diaobing_finish_adv.h"
#include "/d/song/diaobing_start_adv.h"
void create()
{
	set("short", "天武卫驻地");
	set("long", @LONG
这里是上四军之一——天武卫的驻地。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"shuishi",
		"northwest" : "/d/hangzhou/shanlu3",
		//"southwest" : __DIR__"qiantang",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
          __DIR__"npc/tianwu_npc4" : 1,
		__DIR__"npc/tianwu_npc5" : 1,
		__DIR__"npc/songbing_tw" : 2,
        ])); 
	set("songtasks/task_myself","tianwu");//任务mark
	set("songtasks/task_myid","天武卫");//任务军名
	set("songtasks/task_my_number",1);//任务编号
	set("songtasks/task_myjun_number",4);//任务军号
	set("songtasks/task_myjun_id","tianwu wei");//任务军名号
	set("songtasks/task_weapon","刀");//军武器
	set("at_hangzhou",1);
	setup();
}