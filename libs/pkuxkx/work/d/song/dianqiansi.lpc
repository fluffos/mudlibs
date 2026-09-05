// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include "/d/song/diaobing_finish.h"
#include <ansi.h>
void create()
{
	set("short", "殿前都驻地");
	set("long", @LONG
这里是殿前都的驻地，殿前都负责拱卫皇城。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"out" : "/d/hangzhou/palace/heningnei",
		//"north" : __DIR__"dianqiansi2",
		//"enter" : __DIR__"bingbucour",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("objects", ([
          __DIR__"npc/songbing_d" : 2,
		__DIR__"npc/songbing_d2" : 2,
		__DIR__"npc/dianqian_npc3" : 1,
        ])); 
	set("songtasks/taskfrom","pengri");//接收任务来源mark
	set("songtasks/taskcfrom","捧日卫");//接收任务来源
	set("songtasks/tasknumber",1);//接受任务编号
	set("at_hangzhouplace",1);
	setup();
}

void init()
{
	add_action("do_diao","diao");
}
int get_special_site(object me)
{
	object place1,place2;
	string place,*places=({"/d/hangzhou/palace/heningnei","/d/hangzhou/heningmen","/d/hangzhou/wall1","/d/hangzhou/wall2","/d/hangzhou/walla","/d/hangzhou/wallb","/d/hangzhou/lizhengmen"});
	place=places[random(sizeof(places))];
	places-=({place});
	place1=load_object(place);
	place1->set_temp("songtasks/tingzhu/"+me->query("id"),1);
	place2=load_object(places[random(sizeof(places))]);
	place2->set_temp("songtasks/jixing/"+me->query("id"),1);
	tell_object(me,HIR+"按照这次巡逻的事前约定，你应在"+place1->query("short")+HIR+"停驻(tingzhu)，在"+place2->query("short")+HIR+"处疾行(jixing)。\n"NOR);
	return 1;
}
int do_diao()
{
	object army,me=this_player();
	if (me->query_temp("songtasks/dianqian/task")!=3&&me->query_temp("songtasks/dianqian/task")!=4)
	{
		tell_object(me,"没有任命，不能随意调兵。\n");
		return 1;
	}
	if (me->query_temp("songtasks/dianqian/diaobing"))
	{
		tell_object(me,"你已经调出了一营精兵。\n");
		return 1;
	}
	if (present("dianqian du ying",this_object()))
	{
		tell_object(me,"这里已经有一营殿前都精兵整装待发了。\n");
		return 1;
	}
	army=new("/d/song/obj/army");
	army->set_leader(me,1,"营","刀");
	army->move(this_object());
	me->set_temp("ARMY",army);
	if (me->query_temp("songtasks/dianqian/task")==3)
	{
		me->set_temp("songtasks/dianqian/diaobing",1);
		get_special_site(me);
		message_vision("$N传令军中，调出了一营殿前都士兵，准备负责巡逻皇城。\n",me);
	}
	if (me->query_temp("songtasks/dianqian/task")==4)
	{
		me->set_temp("songtasks/dianqian/diaobing",2);
		message_vision("$N传令军中，调出了一营殿前都士兵，准备换防捧日卫驻地。\n",me);
	}
	DASONG_D->multi_record(me,1,"部队出征",2);
	tell_object(me,"你可以带领(lead)部队，前进(forward)巡逻。\n");
	return 1;
}