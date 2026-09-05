// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "/d/song/sansi_balance.h"
#include <gene_map.h>
void create()
{
	set("short", "值房");
	set("long", @LONG
这里是三司使正官的值房。
LONG
	);
       //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"north" : __DIR__"sansinei",
		//"out" : __DIR__"sansishi",
		//"west" : __DIR__"sansishicourt",//吏部
		//"south" : __DIR__"sansishi1",//礼部
	]));
	set("objects", ([
    __DIR__"npc/sansishi" : 1,
        ]));  
	setup();
}

int do_write(string arg)
{
	int answer;
	object me=this_player();
	if (me->query_temp("songtasks/sansishi/task")!=3)
	return 0;
	if (me->query_temp("songtasks/sansishi/3/finish"))
	{
		tell_object(me,"户籍造册完成，向三司使复命吧。\n");
		return 1;
	}
	if(!arg || (sscanf(arg, "%s %d", arg, answer)< 2 ))
    {
        tell_object(me,"你必须确切写下记录，格式举例：write 江州 30。\n");
        return 1;
    }
	if (arg==me->query_temp("songtasks/sansishi/task3_xplace")&&answer==me->query_temp("songtasks/hubu/question_x"))
	{
		me->set_temp("songtasks/sansishi/task3_clearx",1);
		message_vision("$N在宗卷上写下："+arg+"核查，记有"+chinese_number(answer)+"丁。\n",me);
		if (me->query_temp("songtasks/sansishi/task3_cleary"))
		{
			me->set_temp("songtasks/sansishi/3/finish",1);
			tell_object(me,"户籍造册完成，向三司使复命吧。\n");
		}
		return 1;
	}
	if (arg==me->query_temp("songtasks/sansishi/task3_yplace")&&answer==me->query_temp("songtasks/hubu/question_y"))
	{
		me->set_temp("songtasks/sansishi/task3_cleary",1);
		message_vision("$N在宗卷上写下："+arg+"核查，记有"+chinese_number(answer)+"丁。\n",me);
		if (me->query_temp("songtasks/sansishi/task3_clearx"))
		{
			me->set_temp("songtasks/sansishi/3/finish",1);
			tell_object(me,"户籍造册完成，向三司使复命吧。\n");
		}
		return 1;
	}
	write("记录不符，你再仔细想想，哪里填错了。\n");
	return 1;
}
int show_map(object me)
{
	string map,area1,area2;
	string *taskwhere=({"镇江","苏州","扬州","江州","岳阳","南昌","泉州","福州"});
	area1=taskwhere[random(sizeof(taskwhere))];
	taskwhere-=({area1});
	area2=taskwhere[random(sizeof(taskwhere))];
	map=gene_area_songjob(area1,area2);
	me->set_temp("songtasks/sansishi/task3_xplace",area1);
	me->set_temp("songtasks/sansishi/task3_yplace",area2);
	tell_object(me,map);
	tell_object(me,"请用write命令，填写甲乙两地的民众人数，格式举例：write 江州 30。\n");
	return 1;
}
int do_zaoce()
{
	object me=this_player();
	if (me->query_temp("songtasks/sansishi/task")!=3)
	return 0;
	if (me->query_temp("songtasks/sansishi/3/finish"))
	{
		tell_object(me,"户籍造册完成，向三司使复命吧。\n");
		return 1;
	}
	if (!me->query_temp("songtasks/sansishi/task3_answerd"))
	return notify_fail("你从户部尚书那里得到确切数字了吗？\n");
	return show_map(me);
}