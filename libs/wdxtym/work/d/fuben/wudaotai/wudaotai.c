#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "老魔试练楼");
	set("long",""HIR"武侠之路"HIY"漫漫而远兮！"NOR"");
    
	set("sllv",1);
	set("objects",([
	]));

	set("action_list", ([
	    HIY"开始挑战"NOR"" : "wdt",
		//HIY"补领称号"NOR"" : "wdtjl",
		HIR"结束挑战"NOR"" : "wdtjs",
	]));
	set("cost", 1);
	setup();
}

void init()
{
       add_action("wdtjs", "wdtjs");
       add_action("wdtjs1", "wdtjs1");
	   add_action("wdt", "wdt");

}

int wdt()
{
	object me,slnpc,slroom,*slrooms;
	mixed last,now;
	mapping fam;
	int lvl,i;
	string *slnpcs;
	now = localtime(time());
	me = this_player();


	if(me->query_condition("killer")){
		tell_object(me,"你正在被通缉，不能在这里登楼！\n");
		return 1;
	}

	if (me->query("wdtcs")<1){
		tell_object(me,"你没有次数了，不能在这里登楼！\n");
		return 1;
	}
}

int wdtjs()
{
	write(ZJOBLONG"你确定要结束爬楼吗？\n"ZJOBACTS2"确定:wdtjs1\n");
	return 1;
}
	
int wdtjs1()
{
	object slroom ;
	object me = this_player();
	

	slroom = this_object();

	tell_object(me,sprintf(ZJOBLONG""HIY"你结束了"HIR"老魔试练楼"HIY"的挑战！$br#"HIC"你爬到了第"HIG""+chinese_number(me->query("wudaota"))+""HIC"层！"NOR"\n"));
	//log_file("wudaota", sprintf("%s：%s完成%d级千尺瀑试炼，修为值=%d。\n",ctime(time()),me->query("id"),me->query("wudaota"),me->query("combat_exp")));
	this_player()->move("/d/city/kedian");
	this_player()->delete("wudaota");
	this_player()->add("wdtcs",-1);
	this_player()->remove_all_killer();
	destruct(slroom);
	
	return 1;
}

void nextlv(int delay)
{
	add("sllv",1);
	call_out("nextlv2",delay);
}

int nextlv2()
{
	object slnpc;
	string *slnpcs;
	object me = this_player();
	slnpcs = ({
		"/d/fuben/wudaotai/npc/sldz",
	});
	slnpc = new(slnpcs[random(sizeof(slnpcs))]);
        if(query("sllv")<10)
		slnpc->set("name","楼"+chinese_number(query("sllv"))+"守护者");
	    else if(query("sllv")==10)
		slnpc->set("name",HIG"武林高手"NOR"");
	    else if(query("sllv")<30)
		slnpc->set("name",HIC"侠士"+chinese_number(query("sllv"))+""NOR"");
	    else if(query("sllv")==30)
		slnpc->set("name",HIY"绝世高手"NOR);
	    else if(query("sllv")<70)
		slnpc->set("name",HIY"长生者"+chinese_number(query("sllv"))+""NOR"");
	    else if(query("sllv")==70)
		slnpc->set("name",HIC"神"HIG"话"NOR"");
	slnpc->move(this_object());
	return 1;
}

int valid_leave(object me, string dir)
{
	return ::valid_leave(me, dir);
}
