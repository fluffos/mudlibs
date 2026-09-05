// Modified by iszt@pkuxkx, 2007-04-26, added exit eastup
// seagate@pkuxkx 增加对挑水任务的支持

inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", HIY"佛心井"NOR);
        set("long", @LONG
这是一口千年古井，井旁是用青石砌成的井台，上面是用生铁铸就的一
个高一尺的井缘。井内深达十几丈，黑漆漆的望不到底。井口处有一个木制
的辘轳，用来打水(fill)。相传这里曾是达摩老祖汲水之处。
LONG);

        set("exits", ([
                "westdown" : __DIR__"shijie5",
        ]));
        set("objects", ([
                __DIR__"npc/jue-yuan" : 1,
        ]));
        set("work", ([
                "gift" : "dexerity",
                "gift_name" : "后天身法",
                "boss" : "jueyuan dashi",
                "msg_num" : 2,
                "msg0" : CYN"$N将打满水的木桶搬下井台，累得气喘吁吁。\n"NOR,
                "msg1" : CYN"$N提起几个空桶，走上井台。\n"NOR,
        ]));

        set("resource/water",1); 
        set("outdoors", "少林");

        setup();
}

void init()
{
	add_action("do_fill", "fill");
}

int do_fill(string arg)
{
	object ob,me;
	
	me=this_player();
	ob=present("mu tong", me);
	
	if(arg!="mu tong"&&arg!="tong"&&arg!="木桶") {
		printf("往木桶里面装水的命令格式是：fill 木桶或者木桶id。\n");
		return 1;
	}
	else if(!ob) {
		printf("你用什么东西装水？\n");
		return 1;
	}
	else if(!me->query_temp("quest_fillwater/start")) {
		printf("前面有好几个挑水的武僧正在用水，看来还要再等一阵子！\n");
		return 1;
	}
	else if(!ob->query("carried")) {
		printf("你手里没有提着木桶，装不了水。\n");
		return 1;
	}
	
	ob->set("water",100);
	tell_room(this_object(), RANK_D->query_respect(me)+"打上井水装满了自己手里的两个木桶。\n");
	return 1;
}