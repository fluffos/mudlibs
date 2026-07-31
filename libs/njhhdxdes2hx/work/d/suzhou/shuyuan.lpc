// Room: /d/suzhou/shuyuan.c
//by dwolf
//97.11.5
         
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"静心斋"NOR);
	set("long", @LONG
	这里是静心斋的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在太师
椅上讲学，他就是千古大儒金庸先生了。在他的两侧坐满了求学的学生。一张古意盎
然的书案放在金先生的前面，案上摆着几本翻开了的线装书籍。金先生的身后是一
个书架(shujia)讲堂内多历代楹联石刻，足见书院历史的悠久。值得一提的是嵌在
讲堂前左壁的学规(xuegui)。据说是金先生有许多藏书，不知道他放哪儿了。
LONG
	);

	set("exits", ([
		"north" : __DIR__"wroad2",
        ]));

	set("item_desc", ([
		"xuegui" : "日讲小说三章，日看纲目数页。"  
			"\n通晓江湖规矩，参读古人抱负。" 
			"\n读书必须过笔，会课按时蚤完。"
			"\n夜读仍戒晏起，疑误定要力争。\n\n"
			"求学需缴学费十两\n",      
		"shujia" : "书架现在是空的。不知书都到哪儿去了。",
	]));
	
	set("objects", ([
		__DIR__"npc/jin": 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	me->set_temp("mark/金", 0);
	return 1;
}

