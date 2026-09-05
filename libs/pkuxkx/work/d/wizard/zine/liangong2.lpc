#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", CYN+"静室二层"+NOR);
        set("long", @LONG
这是铜雀台的静室二层，你可以在这里挑战(tiaozhan)自己的极限。如果觉
得满意，可以记录(record)下自己的战绩！

LONG
        );
        set("exits", ([
			"down" : __DIR__"liangong",
        ]));
        
        set("no_die",1);
		set("no_sleep_room",1);
        setup();
      
}
void init()
{
	mapping hp_status;
	object me=this_player();
	add_action("do_tiaozhan","tiaozhan");
	add_action("do_record","record");
	add_action("do_none",({"exercise","study","practice","respirate"}));
	me->listen_to_die(this_object());
	if (!me->query_temp("tqt/liangong2/hp_obtain"))
	{
		me->set_temp("tqt/liangong2/hp_obtain",1);
		hp_status=me->query_entire_dbase();
		me->set_temp("tqt/liangong2/record/max_qi",hp_status["max_qi"]);
		me->set_temp("tqt/liangong2/record/eff_qi",hp_status["eff_qi"]);
		me->set_temp("tqt/liangong2/record/qi",hp_status["qi"]);
		me->set_temp("tqt/liangong2/record/max_jing",hp_status["max_jing"]);
		me->set_temp("tqt/liangong2/record/eff_jing",hp_status["eff_jing"]);
		me->set_temp("tqt/liangong2/record/jing",hp_status["jing"]);
		me->set_temp("tqt/liangong2/record/max_neili",hp_status["max_neili"]);
		me->set_temp("tqt/liangong2/record/neili",hp_status["neili"]);
		me->set_temp("tqt/liangong2/record/max_jingli",hp_status["max_jingli"]);
		me->set_temp("tqt/liangong2/record/jingli",hp_status["jingli"]);
		return;
	}
}
int do_none()
{
	tell_object(this_player(),"这里只能挑战(tiaozhan)或者破纪录(record)。\n");
	return 1;
}
int do_record()
{
	object me=this_player();
	int n;
	if (!me->query_temp("tqt/liangong2/lv"))
	{
		tell_object(me,"还没开始呢，就想着破纪录？\n");
		return 1;
	}
	n=me->query_temp("tqt/liangong2/lv")+1;
	if (me->query("tqt/challenge_level")>=n)
	{
		tell_object(me,"这次挑战并不比你上次的记录"+chinese_number(me->query("tqt/challenge_level"))+"级高呢！");
		return 1;
	}
	me->set("tqt/challenge_level",n);
	tell_object(me,"你记录下自己在铜雀台静室二层的挑战记录是"+chinese_number(me->query("tqt/challenge_level"))+"级。\n");
	me->save();
	return 1;
}


int do_tiaozhan()
{
	object fighter,me=this_player();
	int exp=me->query("combat_exp"),n=(int)me->query_temp("tqt/liangong2/lv")+1;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (exp/10*(10+n-1)>2000000000)
	{
		tell_object(me,"你的境界太高已不是铜雀台所能估量的了。\n");
		return 1;
	}
	message_vision("$N开始挑战铜雀台静室二层。当前挑战级别是"+chinese_number(n)+"级。\n",me);
	tell_object(me,HIG"你的状态被恢复！\n"NOR);
	me->set("eff_qi",me->query("max_qi"));
	me->set("qi",me->query("max_qi"));
	me->set("eff_jing",me->query("max_jing"));
	me->set("jing",me->query("max_jing"));
	me->set("neili",me->query("max_neili"));
	me->set("jingli",me->query("max_jingli"));
	fighter=new(__DIR__"npc/target");
	fighter->do_copy(me,me->query_temp("tqt/liangong2/lv"));
	fighter->move(this_object());
	fighter->kill_ob(me);
	return 1;
}

int valid_leave(object me,string dir)
{
	if (!userp(me)&&dir=="down")
	{
		return notify_fail("DENIED.\n");
	}
	if (me->query_temp("tqt/liangong2/hp_obtain")&&me->query_temp("tqt/liangong2/record/max_qi")&&dir=="down")
	{
		me->set("max_qi",me->query_temp("tqt/liangong2/record/max_qi"));
		me->set("eff_qi",me->query_temp("tqt/liangong2/record/eff_qi"));
		me->set("qi",me->query_temp("tqt/liangong2/record/qi"));
		me->set("max_jing",me->query_temp("tqt/liangong2/record/max_jing"));
		me->set("eff_jing",me->query_temp("tqt/liangong2/record/eff_jing"));
		me->set("jing",me->query_temp("tqt/liangong2/record/jing"));
		me->set("max_neili",me->query_temp("tqt/liangong2/record/max_neili"));
		me->set("neili",me->query_temp("tqt/liangong2/record/neili"));
		me->set("max_jingli",me->query_temp("tqt/liangong2/record/max_jingli"));
		me->set("jingli",me->query_temp("tqt/liangong2/record/jingli"));
		me->delete_temp("tqt/liangong2/hp_obtain");
		me->delete_temp("tqt/liangong2/record");
		me->remove_listen_to_die(this_object());
		me->delete_temp("revive_room");
	}
	return ::valid_leave(me,dir);
}