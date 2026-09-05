// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
int guess(object me);
void create()
{
	set("short", "大堂");
	set("long", @LONG
这里是御史台的前厅，可以在此问案(shengtang)。
LONG
	);
       // set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"yushitai",
		"south" : __DIR__"yushitai3",
		"north" : __DIR__"yushitai",//吏部
		//"east" : __DIR__"libu2",//礼部
	]));

	setup();
}
void init()
{
	add_action("do_answer","answer");
	add_action("do_shengtang","shengtang");
}
int remove_npc(object me)
{
	object *all=all_inventory(this_object());
	string name;
	for (int i=0;i<sizeof(all);i++)
	{
		if (!userp(all[i])&&all[i]->query("player")==me)
		{
			name=all[i]->query("name");
			destruct(all[i]);
		}
	}
	message_vision("$N问话完毕，"+name+"等人被带了下去。\n",me);
	return 1;
}
int do_answer(string arg)
{
	object me=this_player();
	if (!me->query_temp("songtasks/yushitai/task1_answer"))
	{
		return 0;
	}
	if (!arg)
	{
		return notify_fail("请回答你心目中人的中文名。\n");
	}
	if (arg!=me->query_temp("songtasks/yushitai/task1_answer"))
	{
		remove_npc(me);
		write("看来你不是这块料啊，弄错了，其实应该是"+me->query_temp("songtasks/yushitai/task1_answer")+"才对。\n");
		me->delete_temp("songtasks");
		return DASONG_D->task_finish(me,-2);
	}
	remove_npc(me);
	me->set_temp("songtasks/yushitai/1/finish",1);
	tell_object(me,"不错，正是"+me->query_temp("songtasks/yushitai/task1_answer")+"，你可以回去复命了。\n");
	me->delete_temp("songtasks/yushitai/task1_answer");
	return 1;
}
int do_shengtang()
{
	object me=this_player();
	if (!me->query("song/pro"))
	return 0;
	message_vision("$N满怀信心地坐在正堂，大声道：“升堂～”\n",me);
	if (me->query_temp("songtasks/yushitai/task")!=1)
	{
		tell_object(me,"可惜根本没人回应，威武～，你还是回家玩去吧。\n");
		return 1;
	}
	if (me->query_temp("songtasks/yushitai/1/finish"))
	{
		tell_object(me,"你不是问完了吗？那就回去复命吧。\n");
		return 1;
	}
	if (me->query_temp("songtasks/yushitai/task1_shengtang"))
	{
		tell_object(me,"快来问案吧。\n");
		return 1;
	}
	me->set_temp("songtasks/yushitai/task1_shengtang",1);
	tell_room(this_object(),"众衙役回应：“威武～～～”\n");
	return guess(me);
}
int guess(object me)
{
	int n;
	string p1,p2,p3,w1,w2,w3,*places=({"福建路","江南东路","江南西路","广南西路","广南东路","荆湖北路","荆湖南路","利州路","夔州路","梓州路","成都府路","两浙路",});
	string npc,*dos=({"卖","收购","喜欢吃","经营","帮老婆买","囤积"}),*things=({"烧饼","油条","酱油","青菜","酒酿","烧酒","醋","碳","猪","粮食","武器"}),where,job;
	object npc1,npc2,npc3;
	p1=places[random(sizeof(places))];
	places-=({p1});
	p2=places[random(sizeof(places))];
	places-=({p2});
	p3=places[random(sizeof(places))];
	w1=dos[random(sizeof(dos))]+things[random(sizeof(things))];
	w2=w1;
	while (w2==w1)
	w2=dos[random(sizeof(dos))]+things[random(sizeof(things))];
	w3=w2;
	while (w3==w1||w3==w2)
	w3=dos[random(sizeof(dos))]+things[random(sizeof(things))];
	npc1=new(__DIR__"npc/suspect");
	npc1->set("place",p1);
	npc1->set("do",w1);
	npc1->set("player",me);
	npc2=new(__DIR__"npc/suspect");
	npc2->set("place",p2);
	npc2->set("do",w2);
	npc2->set("player",me);
	npc3=new(__DIR__"npc/suspect");
	npc3->set("place",p3);
	npc3->set("do",w3);
	npc3->set("player",me);
	npc1->move(this_object());
	npc1->set("not_do",({w2,w3}));
	npc1->set("not_place",({p2,p3}));
	npc2->move(this_object());
	npc2->set("not_do",({w1,w3}));
	npc2->set("not_place",({p1,p3}));
	npc3->move(this_object());
	npc3->set("not_do",({w1,w2}));
	npc3->set("not_place",({p1,p2}));
	n=random(3)+1;
	switch (n)
	{
	case 1:
	where=p1;
	job=w1;
	npc=npc1->query("name");
	break;
	case 2:
	where=p2;
	job=w2;
	npc=npc2->query("name");
	break;
	case 3:
	where=p3;
	job=w3;
	npc=npc3->query("name");
	break;
	}
	me->set_temp("songtasks/yushitai/task1_answer",npc);
	tell_object(me,"现在线索是"+w3+"的是"+p3+"人士，"+w2+"的是"+p2+"人士，"+w1+"的来自"+p1+"。\n");
	tell_object(me,"你分别对每人问问话(ask about 问话)，多半能得到答案。\n");
	if (random(100)>49)
	tell_object(me,"请问这三人中谁来自"+where+"？\n");
	else
	tell_object(me,"请问这三人中谁是"+job+"的？\n");
	tell_object(me,"请用answer回答你心目中人的中文名。\n");
	return 1;
}