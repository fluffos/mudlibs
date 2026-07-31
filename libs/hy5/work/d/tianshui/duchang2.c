// design by 发现号(find) . all right reserved.

// Room: /u/xiaozhen/duchang2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "赌场二楼");
	set("long", @LONG
这里是天水赌馆的二楼，墙上挂着一块木牌(sign)。这里专
门让从军营里偷偷溜出来的军爷耍钱的地方，并不对外开放。几
位军官正赌的高兴。西边有一扇木门。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"duchang",

]));
        set("item_desc", ([
                "sign" : 
"本赌场现只开放赌「大小」,规则如下:\n"
"三粒色子点数总和：\n"
"       四   至 十   为「小」，\n"
"       十一 至 十七 为「大」，\n"
"       三粒色子点数相同，则大小通吃。\n"
"开大赔大，开小赔小，赌一赔一。\n"
"本赌场只接受银子为赌注,一次最少押\n"
"五两，最多押二十两。\n",
        ]));

	
	set("objects",([
	__DIR__"npc/zhao_qixian" : 1,
	__DIR__"npc/judge2" : 1,
]));
	setup();
}

int valid_leave(object who,string arg)
{
	object obj;
	obj = present("zhao qixian",environment(who));
	if(!obj) return 1;
	if(!obj->query("bet_another_id")) return 1;
	if(obj->query("bet_another_id") != who->query("id")) return 1;
	obj->delete("bet_another_name");
	obj->delete("bet_another_id");
	obj->set("money_my",200);
	return 1;
}