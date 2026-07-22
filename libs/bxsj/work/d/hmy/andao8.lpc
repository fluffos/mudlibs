// andao8.c
// Created by Numa 19991021

#include <ansi.h>
inherit ROOM;

string *way = ({
	"up",
	"down",
	"west",
	"east",
	"south",
	"north",
	"southeast",
	"southwest",
	"northeast",
	"northwest",
	"southup",
	"southdown",
	"northup",
	"northdown",
	"eastup",
	"eastdown",
	"westup",
	"westdown",
});

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是一条通往监狱的暗道，两旁有许多各式的刑具，在微弱的烛光之下，
散发着冰冷的寒光，令人越看越是心中发毛，想像受刑之人那种惨状及那凄惨
的叫声，心中更感到一阵惊怖。
LONG
	);
	set("exits", ([ 
	  "southeast" : __DIR__"andao7",
	  "enter" : __DIR__"jail_gate",
	]));
	set("objects",([
		__DIR__"npc/shang_gp" : 1,
		__DIR__"npc/yuzu" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	
	if(me->query_temp("hostage/job_2_1")) {
		for(i=0;i<sizeof(way);i++) {
			if (dir == way[i] && objectp(present("yu zu", environment(me)))) {
				tell_room(environment(me),"狱卒盯着" + me->name() + "看了几眼，喝道：" + RANK_D->query_rude(me) + "，居然敢到日月神教的监狱来，看我怎么收拾你！\n");
				return 0;
				break;
			}
		}
	}
	if (dir == "enter" && objectp(present("shangguan peng", environment(me)))) {
		message_vision("上官鹏对着$N大声喝道：" + RANK_D->query_rude(me) + "你要想过去，除非过了我这关。\n",me);
		return 0;
	}
        return ::valid_leave(me, dir);
}
