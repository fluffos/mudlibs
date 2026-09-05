// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "/d/song/diaobing_finish.h"
#include "/d/song/diaobing_start.h"
void create()
{
	set("short", "捧日卫驻地");
	set("long", @LONG
这里是上四军之一——捧日卫的驻地。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"shuishi",
		"out" : "/d/hangzhou/guandaon1",
		//"southwest" : __DIR__"qiantang",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
          __DIR__"npc/pengri_npc4" : 1,
		__DIR__"npc/pengri_npc5" : 1,
		__DIR__"npc/songbing_pr" : 2,
        ])); 
	set("songtasks/taskfrom","dianqian");//接收任务来源mark
	set("songtasks/taskcfrom","殿前司");//接收任务来源
	set("songtasks/tasknumber",4);//接受任务编号

	set("songtasks/task_myself","pengri");//任务mark
	set("songtasks/task_myid","捧日卫");//任务军名
	set("songtasks/task_my_number",1);//任务编号
	set("songtasks/task_my_number2",3);//任务编号2
	set("songtasks/task_myjun_number",5);//任务军号
	set("songtasks/task_myjun_id","pengri wei");//任务军名号
	set("songtasks/task_target","殿前司");//换防目的地
	set("songtasks/task_weapon","刀");//军武器
	set("at_hangzhou",1);
	setup();
}
