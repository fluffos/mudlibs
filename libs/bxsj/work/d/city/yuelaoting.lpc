// /d/city/yuelaoting.c
// update by beyond
// add help by Lklv

#include <ansi.h>

inherit ROOM;
string jiehun_zn();

void create()
{
	set("short", HIG"月老亭"NOR);
	set("long", @LONG
这里是月老亭，是举办婚礼的场所。亭子四周的柱子上贴满了字条，也有
些人物肖像画，看来有不少人留了名字在这里，希望能找个如意佳偶。有几张
字条被人用红笔勾了出来，十分显眼。很多有情人都是在这里由月下老人主持
他们的婚礼。亭边的柱子上挂着一个，木牌(mu pai)。
LONG
        );
        set("item_desc", ([
                "mu pai" : (: jiehun_zn() :),
        ]));
	set("exits", ([
		"west" : __DIR__"yueqidian",
		"north" : __DIR__"yltw",
        ]));
	set("objects",([
		NPC_D("yuelao") : 1,
                NPC_D("shuanger") : 1,
        ]));
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("incity",1);
	setup();
	call_other("/clone/board/yuelao_b", "???");
}

string jiehun_zn()
{
	object me = this_player();
	if (!me->query_temp("look_zn")){
	write("\n
		"HIM"结婚指南"NOR"
	订婚：
	    男方输入指令： qiu <女方英文名字>
	    女方输入指令： marry <男方英文名字>

	结婚：
	    男女双方需要都到月老亭，并且需要找个主持人在场。
	    主持人输入指令： zuomei <女方英文名字>
	    男  方输入指令： jiehun <女方英文名字>

        坐花轿：
            在月老亭北，轿夫头处。
            男方输入指令： give tou 100 gold
            女方输入指令： enter jiao
            然后女方就坐在了轿子里，男方可以领头，轿夫们会抬着轿子跟着男方。
            若不想逛了，结束游行，男方输入指令： say here
		");
		me->set_temp("look_zn", 1);
		return "\n";
	}
	else
	write("\n
		"HIY"离婚指南"NOR"
	离婚：
            婚姻中的双方需要都在线，
	    其中一方在此输入指令： lihun <对方英文名字>

        特例：
            婚姻中的任何一方，超过三个月没有上线，
            另外一方可以单方面提出离婚。
            指令同上。
		");
		me->delete_temp("look_zn");
		return "\n";
}
