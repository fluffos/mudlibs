// /d/city/kongchang

inherit ROOM;
#include <ansi.h>
#include <guanfu.h>
#include "/clone/npc/tdh/skill.h"

void create()
{
	set("short", "广场");
	set("long", @LONG
这是知府旁边的一片小空场，在东边的墙上贴了几张官府悬赏捉拿朝廷要
犯的告示 (wanted list)，下面围观了许多看热闹的人，当中不乏一些武林高
手，但是要捉拿的要犯都很扎手，很少有人随便揭榜(jie)。 但也有不少武林
后起之秀在一旁跃跃欲试。
LONG
	);
	set("outdoors", "扬州");
	set("item_desc", ([
		"wanted list" : (: GF_WANTED->look_wanted() :),
	]));
	set("exits", ([
		"southwest" : __DIR__"guangchangbei",
	]));

	set("incity",1);
	setup();
	call_out( (:call_other:), 1, GF_WANTED, "???");
}

void init()
{
	if( this_player()->query_condition("killer") )
		return;
	add_action("do_jie", ({"xian","jie"}));

	if ( this_player()->query("gf_job")){
		this_player()->add("job_time/官府", this_player()->query("gf_job"));
		this_player()->delete("gf_job");
	}
}

int do_jie(string arg)
{
	object ob;
	if ( this_player()->query_temp("no_guanfu"))
		return notify_fail("你现在不能揭文书。\n");
	if ( this_player()->query_temp("天地会job")) {
		message_vision(HIY"$N伸手刚要揭榜，耳边只听得一声“天地会反贼，哪里走！”突然蹿出一个身影直扑向$N。\n", this_player());
		ob = new("/clone/npc/tdh/bing");
		copy_npc(this_player(), ob, 150);
		ob->move(environment(this_player()));
		ob->kill_ob(this_player());
		this_player()->set_temp("no_guanfu", 1);
		return 1;
	}
	this_player()->set_temp("guanfu_jiebang", 1);
	return GF_WANTED->do_jie(arg);
}
