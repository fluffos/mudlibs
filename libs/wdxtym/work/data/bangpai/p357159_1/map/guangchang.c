// by ranger_游侠
// banghui.c
//#include <bangpai.h>
inherit ROOM;

void create()
{
	set("short", "帮会广场");
	set("long", "这里是帮派广场，是兄弟们聚会的地方。");
	set("exits", ([
		"south" : __DIR__"liangong",
		"east" : __DIR__"chufang",
		"west" : __DIR__"liandan",
		"north" : __DIR__"biguan",
	]));
	set("action_list", ([
		HIG"帮派任务"NOR:"bpquest",
	]));
		set("bangpai_room","1");
		set("bangpai/guangchang",1);
	set("no_fight","1");
	setup();
}

void init()
{
	add_action("do_quest", "bpquest");
}

int do_quest(string arg)
{
	object me;
	me = this_player();

	if (! arg || arg == "")
	{
	 string msg=ZJOBLONG;
	  msg += "为了帮派的发展，为了锻炼帮众的能力，帮派颁布有如下任务可以领取：\n";
	  msg += ZJOBACTS2;
	  msg += "割草:bpquest grass";
			tell_object(me,msg+"\n");
			return 1;
    }		
  
		
    if (me->query("bangpai/finish")>=20)
    	return notify_fail("你今天做的帮派任务够多了，暂时没有什么任务给你做了。\n");
    	
	if (arg == "grass")
	{ 
		 if (me->is_busy())
			return notify_fail("你的动作还没有完成，不能移动。\n");
         if  (!me->query_temp("bangpai/quest/grass"))
      {
      
        me->set_temp("bangpai/quest/grass",1);
        tell_object(me,HIY"最近帮派草料急缺，你去扬州南边的宜兴镇割点草回来，速去速回！\n");     
       
      }   else
        if  (me->query_temp("bangpai/quest/grass"))
      {
           object grass;
           
            if (!objectp(grass=present("quest grass",me))||grass->query_amount()<10)
        	return notify_fail("你的草料呢？还不快去割草！\n");
        	
        	grass->add_amount(-10);
        	me->add("combat_exp",1000);
        	me->add("potential",1000);
        	me->delete_temp("bangpai/quest/grass");
        	me->add("bangpai/finish",1);
        	BANGHUI_D->set_banghui(me->query("banghui/name")+"/exp", BANGHUI_D->query_banghui(me->query("banghui/name")+"/exp")+10);
        	BANGHUI_D->set_banghui(me->query("banghui/name")+"/gongxian/"+me->query("id"), BANGHUI_D->query_banghui(me->query("banghui/name")+"/gongxian/"+me->query("id"))+10);
        	tell_object(me,"你获得了1000点修为和潜能，10点帮会贡献，继续加油啊！\n");      
        	 	
       }
		return 1;
	}
	return 1;
}       
