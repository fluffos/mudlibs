// 长江天险
// edit: by zine Sep 2 2010

inherit __DIR__"skfroom1";
#include <ansi.h>
#include "qiuyuan.h"

void create()
{
	set("short", "长江天险");
	set("long", @LONG
这里是长江边的一块开阔地。前后四通八达十分适合骑兵布阵绞杀。你可以
观察(guancha)女真出兵动向。
LONG
	);
	set("exits", ([ 
        "east" : __DIR__"changjiang-2a",
        "south" : __DIR__"changjiang-2b",
        "west" : __DIR__"changjiang-2c",
        "north" : __DIR__"changjiang-2d",
	]));
    set("objects", ([
		__DIR__"npc/mes2" : 1,
	]));
	set("no_task",1);
	setup();
	::create();
}

void init()
{
	object me=this_player();
    add_action("do_guancha","guancha");
    add_action("do_back","back");
    add_action("do_qiuyuan","qiuyuan");
	::init();
	return;
}

int do_guancha()
{	
	object me = this_player();
    int g1,g2,qb,qb2;
    string n1,n2,*direction=({"东","南","西","北"});
    qb=(int)me->query_temp("skf/bingnumber")+1+random(3);
	me->set_temp("skf/canceltimeup",1);
    this_object()->set("user",me->query("id"));
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着呢！\n");
    if (me->query_temp("skf/guancha"))
	return notify_fail("你不是已经观察过了吗？\n");
	else
	{
		me->set_temp("skf/guancha",1);
		me->add("zhusantimes",1);
		n1=direction[random(sizeof(direction))];
		direction-=({n1});
		n2=direction[random(sizeof(direction))];
		g1=1+random(qb);
        g2=qb-g1;
		if (g2==0)
		g2=1;
		tell_object(me,"通过仔细观察，你发现有"+chinese_number(g1)+"队女真骑兵从"+n1+"方向奔袭过来，\n另有"+chinese_number(g2)+"队骑兵从"+n2+"方向掩杀过来。\n");
		me->set_temp("skf/n1",n1);
		me->set_temp("skf/n2",n2);
		me->set_temp("skf/g1",g1);
		me->set_temp("skf/g2",g2);
		me->set_temp("skf/qb",g1+g2);
		remove_call_out("finalwar");
		call_out("finalwar",60,me);
		return 1;
	}
}

int finalwar(object me)
{
    int g1,g2,qb2;
    string n1,n2,*direction=({"东","南","西","北"});
	message_vision(HIR"女真骑兵逼近五里以内了。\n"NOR,me);
	call_out("qbarrive2",10,me);
    if (random(1000)>799)// 1/5几率女真增兵
	{
		qb2=8+random(3);
		message_vision(BLINK+HIR"一个斥候极速打马冲了过来：大人，女真增兵了！\n"NOR,me);
		n1=direction[random(sizeof(direction))];
		direction-=({n1});
		n2=direction[random(sizeof(direction))];
		g1=1+random(qb2);
        g2=qb2-g1;
		if (g2==0)
		g2=1;
		tell_object(me,"斥候道：又有"+chinese_number(g1)+"队女真骑兵从"+n1+"方向奔袭过来，\n此外可能有"+chinese_number(g2)+"队骑兵从"+n2+"方向掩杀过来。\n");
		me->set_temp("skf/n3",n1);
		me->set_temp("skf/n4",n2);
		me->set_temp("skf/g3",g1);
		me->set_temp("skf/g4",g2);
		me->set_temp("skf/qb2",g1+g2);
		me->add_temp("skf/qb",g1+g2);
		me->set_temp("skf/qbzengyuan",1);
		tell_object(me,"你心中暗道：不妙！\n");
		tell_object(me,"你可以选择独立阻击女真骑兵，也可以立刻派人向史督师求援(qiuyuan)。\n");
	}
	return 1;
}

int qbarrive2(object me)
{
	message_vision(HIR"女真骑兵逼近一里以内了。\n"NOR,me);
	call_out("qbarrive3",3,me);
	return 1;
}

int qbarrive3(object me)
{
	message_vision(RED"马蹄声已经清晰可闻。\n"NOR,me);
	call_out("theend",2,me);
	return 1;
}

int theend(object me)
{
	object room;
    string *dirs=({"东","南","西","北"});
	string *rooms=({"changjiang-2a","changjiang-2b","changjiang-2c","changjiang-2d"});
    if (member_array(me->query_temp("skf/n1"),dirs)!=-1)
    {
        room=load_object(__DIR__+rooms[member_array(me->query_temp("skf/n1"),dirs)]);
		if (room->isroom())
		room->fighting(1);
    }
    if (member_array(me->query_temp("skf/n2"),dirs)!=-1)
    {
        room=load_object(__DIR__+rooms[member_array(me->query_temp("skf/n2"),dirs)]);
		if (room->isroom())
		room->fighting(2);
    }
    if (me->query_temp("skf/qbzengyuan"))
    {
        remove_call_out("qbzengyuan");
        call_out("qbzengyuan",2,me);
    }
    return 1;
}

int qbzengyuan(object me)
{
	object room;
    string *dirs=({"东","南","西","北"});
	string *rooms=({"changjiang-2a","changjiang-2b","changjiang-2c","changjiang-2d"});
    if (member_array(me->query_temp("skf/n3"),dirs)!=-1)
    {
        room=load_object(__DIR__+rooms[member_array(me->query_temp("skf/n3"),dirs)]);
		if (room->isroom())
		room->fighting(3);
    }
    if (member_array(me->query_temp("skf/n4"),dirs)!=-1)
    {
        room=load_object(__DIR__+rooms[member_array(me->query_temp("skf/n4"),dirs)]);
		if (room->isroom())
		room->fighting(4);
    }
    return 1;
}
