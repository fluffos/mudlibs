#include <ansi.h>
inherit ROOM;

string look_bagua();
void create()
{
    set("short", "桃花山庄正厅");
    set("long", 
"这里是桃花山庄的正厅。整个大厅十分宽阔。厅中挂满了各种\n"
"名家的书法真迹。但最显眼的则是正中挂的一幅对联：\n\n"
   
BLU "            桃花影落飞神剑\n"
    "            碧海潮生按玉箫\n\n"
NOR

"字体遒劲挺拔，气势宏伟。\n\n"

"而在门楣之上钉着八片铁片， 排作八卦(bagua)图案，却又不似寻常
的八卦那么排的整齐，疏疏落落，歪斜不称，显然与四周的布置极不协调。\n"
);
	set("exits", ([
	    "north" : __DIR__"qianyuan",
	    "south" : __DIR__"houyuan",
	    "east"  : __DIR__"daojufang",
	    "west"  : __DIR__"wofang" ,
	]));
	set("item_desc", ([
		"bagua" : (: look_bagua :),
	]) );

	set("objects", ([
	    "/kungfu/class/taohua/huang" : 1,
	    "/d/biwu/champion_th":1,
	    "/d/taohua/npc/yapu":2
	]) );    
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	set("no_beg", "1");
	setup();
	 "/clone/board/taohua_b"->foo();	
//	replace_program(ROOM);
}
string look_bagua()
{
	int i, j, temp;
	int *bagua = ({0,1,2,3,4,5,6,7});
	string *bagua_name = ({"坤","震","坎","兑","艮","离","巽","乾"});
	string result;
	object me = this_player();

	for (i = 0; i < 8; i++)
	{
		j = random(8);
		while (j == i)
			j = random(8);
		temp = bagua[i];
		bagua[i] = bagua[j];
		bagua[j] = temp;
	}		
	for (i = 1; i < 9; i++)
		me->set_temp("bagua_" + i, bagua[i - 1]);
	result = "一个奇怪的铁八卦，上面按顺时针顺序排列着：";
	for (i = 0; i < 8; i++)
		result += bagua_name[bagua[i]];
	return result + "。\n";
}
