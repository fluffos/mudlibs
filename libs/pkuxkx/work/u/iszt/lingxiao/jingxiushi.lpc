// File		: jingxiushi.c
// Created By	: iszt@pkuxkx, 2007-02-15

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "静修室");
	set("long", @LONG
雪山派内功同各门各派一样，修习之时最怕受到惊扰，内息进入岔道，走火
入魔。因此，凌霄城中便专门辟出这间屋子作为修习内功的所在。这静修室比外
间休息室又安静了不少，地上随意放着几块较为平整的巨石，供雪山派弟子在其
上打坐(dazuo)练功。
LONG);

	set("indoors", "凌霄城");
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"xiuxishi",
	]));

	setup();
}

void init()
{
	add_action("do_dazuo", "exercise");
	add_action("do_practice", "practice");
}

int do_dazuo(string arg)
{
	object me = this_player();
	int skill = me->query_skill("xueshan-neigong", 1);

	if(skill > 300)
		return 0;
	if(me->query_skill_mapped("force") != "xueshan-neigong")
		return 0;

	remove_call_out("dazuoing");
	call_out("dazuoing", 1, me, skill);

	return 0;
}

int dazuoing(object me, int skill)
{
	if(!me)
		return 0;
	if(!me->query_temp("pending/exercise"))
		return 0;

	if(!random(4))
	{
		tell_object(me, "你摒除杂念，内息运行丝毫不受外界惊扰，似乎内功又有进境。\n");
		me->improve_skill("xueshan-neigong", random(41)*skill/141+4);
	}
	call_out("dazuoing", 1, me);
	return 1;
}

int do_practice(string arg)
{
	write("静修室中不要练功，会打扰其他弟子。\n");
	return 1;
}