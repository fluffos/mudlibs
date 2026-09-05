// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include "/d/song/diaobing_finish_adv.h"
#include "/d/song/diaobing_start_adv.h"
#include <ansi.h>
void create()
{
	set("short", "马军都驻地");
	set("long", @LONG
这里是马军都的驻地，马军都为三衙禁军，负责拱卫京师。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"south" : "/d/hangzhou/ximen",
		"north" : __DIR__"majun2",
		//"enter" : __DIR__"bingbucour",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
          __DIR__"npc/songbing_m" : 2,
		__DIR__"npc/songbing_m2" : 2,
		__DIR__"npc/majun_npc3" : 1,
        ])); 
	set("songtasks/task_myself","majun");//任务mark
	set("songtasks/task_myid","马军都");//任务军名
	set("songtasks/task_my_number",1);//任务编号
	set("songtasks/task_myjun_number",3);//任务军号
	set("songtasks/task_myjun_id","majun du");//任务军名号
	set("songtasks/task_weapon","戟");//军武器
	set("at_hangzhou",1);
	setup();
}