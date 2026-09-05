// Room: /city/shuyuan.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "书院");
	set("long", 
"这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在太师椅上
讲学，那就是扬州城最有学问的夫子了。在他的两侧坐满了求学的学生。一张古意
盎然的书案放在夫子的前面，案上摆着几本翻开了的线装书籍。夫子的身后是一个
书架(shujia)讲堂内多历代楹联石刻，足见书院历史的悠久。值得一提的是嵌在讲
堂前左壁的"+HIY"学规(xuegui)"+NOR"。\n"

	);

	set("exits", ([
		"south" : __DIR__"dongdajie1",
        "west" : __DIR__"bookstore",
        "north" : "/d/wizard/guider_room",
	]));

	set("item_desc", ([
		"xuegui" : "日讲经书三起，日看纲目数页。"  
			"\n通晓时务物理，参读古文诗赋。" 
			"\n读书必须过笔，会课按时蚤完。"
			"\n夜读仍戒晏起，疑误定要力争。\n\n"
			"求学需缴学费十两\n",
	 /* "notice" : "从即日起，本书院承包官府修改称谓服务。\n"  
                        "\n输入apply命令可看到具体方法。\n" 
			"\n另，本书院为提供猜谜服务，对一些新手可能有一些意外奖励哦。\n"
			"\n猜谜相关请ask zhu xi about question或者rule\n",*/
	]));
	
	set("objects", ([
		__DIR__"npc/fuzi": 1,
	]));
    set("least_msg",1);

	setup();
}

int valid_leave(object me, string dir)
{
	me->set_temp("mark/朱", 0);
	return 1;
}


