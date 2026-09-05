// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "司封司衙门");
	set("long", @LONG
这里是司封司的衙门。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","libu");
	set("exits", ([
		"southwest" : __DIR__+query("yamen")+"court",
	
	]));
	setup();
}
void init()
{
	add_action("do_guidang","guidang");
}
int profile(object me)
{
	object ob=load_object("/d/song/record/other");
	if (!ob)	
	{
		tell_object(me,"吏部的宗卷似乎被人破坏了。\n");
		return 0;
	}
	me->set_temp("songtasks/libu/zongjuan",ob->query("dasong_officers/data"));
	me->set_temp("songtasks/libu/zongjuan_id",ob->query("all_the_dasong_officers"));
	return 1;
}
int do_guidang()
{
	object me=this_player();
	mapping person_data;
	string name,title,pro,excel,credit,*ids;
	if (me->query_temp("songtasks/libu/task")!=2)
	{
		write("吏部重地，闲人免进！\n");
		me->move(__DIR__"libucourt");
		return 1;
	}
	if (time()-me->query_temp("songtasks/libu/zongjuan_time")<2)
	{
		write("你当是看闲书吗？专心点！\n");
		return 1;
	}
	if (me->query_temp("songtasks/libu/2/finish"))
	{
		write(HIG+"这些宗卷基本归档完成了，你可以回去复命了。\n"+NOR);
		return 1;
	}
	if (!me->query_temp("songtasks/libu/zongjuan"))
	{
		if (profile(me)==0)
		{
			return 1;
		}
	}
	ids=me->query_temp("songtasks/libu/zongjuan_id");
	person_data=me->query_temp("songtasks/libu/zongjuan/"+ids[random(sizeof(ids))]);
	name=person_data["name"];
	title=person_data["position"];
	pro=person_data["profession"];
	excel=chinese_number(person_data["excellent_records"]);
	credit=chinese_number(person_data["credit"]);
	message_vision("$N开始翻阅吏部的宗卷……\n",me);
	write(WHT+"你读到："+name+"，"+title+"，"+pro+"职官员");
	if (DASONG_D->get_my_pin(me)<=3)
	{
		write(excel+"次仕途优评。");
		if (DASONG_D->get_my_pin(me)==1)
		{
			write("功勋"+excel+"点");
		}
	}
	write("。\n"+NOR);
	me->set_temp("songtasks/libu/zongjuan_time",time());
	me->add_temp("songtasks/libu/zongjuan_degree",1);
	if (me->query_temp("songtasks/libu/zongjuan_degree")>8+random(8))
	{
		me->set_temp("songtasks/libu/2/finish",1);
		write(HIG+"这些宗卷基本归档完成了，你可以回去复命了。\n"+NOR);
	}
	return 1;
}