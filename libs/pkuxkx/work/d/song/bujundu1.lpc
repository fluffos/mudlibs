// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "正厅");
	set("long", @LONG
这里是步军都指挥使司主官办公的所在。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		"south" : __DIR__"bujunducourt",
		//"east" : __DIR__"bujundu3",
		//"out" : __DIR__"bujundu",
		//"north" : __DIR__"streetn7",//吏部
		//"west" : __DIR__"bujundu2",//礼部
	]));
	set("objects", ([
    __DIR__"npc/bujundu1" : 1,
	__DIR__"npc/bujundu2" : 1,
        ])); 
	set("songtasks/task_myself","bujun");//任务mark
	set("songtasks/task_myid","步军都");//任务军名
	set("songtasks/task_my_number",1);//任务编号
	set("songtasks/task_myjun_number",2);//任务军号
	set("songtasks/task_myjun_id","bujun du");//任务军名号
	set("songtasks/task_weapon","枪");//军武器
	setup();
}