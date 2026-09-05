#include <localtime.h>
#include <ansi.h>
inherit ROOM;
int boat_manager();
string look_tree();
void create()
{
	set("short", "鄱阳湖边");
	set("long", @LONG
这里是鄱阳湖畔，东边是一个大湖(lake)，湖畔系着一只小舟(boat)。一个
人正悠闲地钓着鱼。湖边有棵大树(tree)，树上刻了句半文不文的语句(ju)。东
面湖水处的浅滩可以涉水(sheshui)过去。
LONG );
	set("outdoors", "jiangzhou");
   
    set("item_desc", ([
		"lake" : "碧波荡漾的湖面，谁还能想起这里曾是本朝太祖和陈友谅大战的主战场？\n", 
        "boat" : "一只小舟，被系在岸边的大青石上，如果得到主人允许，也许你可以上舟(shang)一晤。\n",
        "岩缝" : "巨岩有一处裂缝，似乎可以伸手进去摸索一下。\n", 
        "tree" : (:look_tree:),
        "ju" : "悟、根、身、臂，从零开始，周而复始。\n",
	]));
	set("no_clean_up", 0);
  set("no_fight", 1);
  set("no_perform", 1);
  set("no_steal", 1);
  set("no_sleep_room", 1);

	set("exits", ([
		"west"     : __DIR__"guandaos2",
        "southwest" : __DIR__"guandaos3",
		
	]));
    set("couldfish",1);
    set("objects", ([
        "/d/jiangzhou/npc/diaoyuren" : 1,
        "/d/jiangzhou/obj/rock" : 1,
        ]));
	setup();
	
}

string look_tree()
{
    mixed* timeinfos;
    int hour;
    timeinfos = localtime(time());
    hour = timeinfos[LT_HOUR];
    if (hour==0||hour==4||hour==8||hour==12||hour==16||hour==20)
    {
        return "树上有张纸条：上面写道，这年头，"+HIR+"悟性"+NOR+"最吃香。\n";
    }
    if (hour==1||hour==5||hour==9||hour==13||hour==17||hour==21)
    {
        return "树上有张纸条：上面写道，这年头，"+HIR+"根骨"+NOR+"最吃香。\n";
    }
    if (hour==2||hour==6||hour==10||hour==14||hour==18||hour==22)
    {
        return "树上有张纸条：上面写道，这年头，"+HIR+"身法"+NOR+"最吃香。\n";
    }
    if (hour==3||hour==7||hour==11||hour==15||hour==19||hour==23)
    {
        return "树上有张纸条：上面写道，这年头，"+HIR+"臂力"+NOR+"最吃香。\n";
    }
}

void init()
{ 
	add_action("do_shang","shang");
    add_action("do_sheshui","sheshui");
}

int do_sheshui()
{
    object me=this_player();
    object ob=this_object();
    object next_room;
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (next_room=load_object(__DIR__"qiantan"))
    {
        message_vision("$N卷起裤脚，涉水走向东面的湖边浅滩。\n",me);
        tell_room(next_room,me->query("name")+"涉水走了过来。\n");
        me->move(next_room);
        return 1;
    }
    else
    {
        tell_object(me,"涨潮了，东面的浅滩无法涉水过去了。\n");
        return 1;
    }
}

int do_shang(string arg)
{
    object me=this_player(),pl;
    object boat,ren,*team;
    int bts,count=0;
    if (!me->query_temp("pyh/boatpermit"))
    return notify_fail("你还没有得到主人允许呢，不能上船！\n");
    ren=find_object("d/jiangzhou/npc/diaoyuren");
    bts=boat_manager();
    CHANNEL_D->do_channel(ren, "sys", "潘阳湖中目前还有%d只船。\n", bts);
    boat=new("/d/jiangzhou/boat");
	boat->delete("pyh");
	if (team=me->query_temp("pyh/team"))
	{
		tell_room((environment(me)),me->query("name")+"一行人准备依次跳上小舟。\n");
		for (int i=0;i<sizeof(team);i++)
		{
			if (team[i]&&living(team[i])&&present(team[i],this_object()))
			{
				team[i]->move(boat);
				team[i]->set_temp("pyh/boat_flag", boat);
				pl=team[i];
				count+=1;
			}
		}
		if (count>1)
		{
			boat->set("pyh/team_member",team);
			boat->set("pyh/member_number",sizeof(team));
			boat->set("pyh/target_distance",me->query_temp("pyh/downflow"));
		}
		else
		{
			boat->set("pyh/singer_user",pl);
			boat->set("pyh/target_distance",pl->query_temp("pyh/downflow"));
			for (int i=0;i<sizeof(team);i++)
			{
				if (team[i])
				{
					team[i]->delete_temp("pyh/team");
					if (team[i]==pl)
					tell_object(pl,HIR"因为事到临头，只有你一人上船，此次变成了单人漂流。\n"NOR);
					else
					tell_object(team[i],HIR"因为事到临头，你却没有上船，此次组队漂流取消了。\n"NOR);
				}
			}
		}
	}
	else
	{
		tell_room((environment(me)),me->query("name")+"轻轻一纵，跳上小舟。\n");
		me->move(boat);
		me->set_temp("pyh/boat_flag", boat);
		boat->set("pyh/singer_user",me);
		boat->set("pyh/target_distance",me->query_temp("pyh/downflow"));
	}
    boat->set("xiufu",0);
    boat->set("pyh/zhi",3);//机关使用次数。
    message_vision("$N轻轻地踏上了小船，生怕把它倾覆。\n",me);
    return 1;
}

/*
船只管理，清理未使用的船只。
*/
int boat_manager()
{
	object *boatL, *invL;
	int btlp, ivlp, userMark;
	boatL=children("/d/jiangzhou/boat");
	for(btlp=0;btlp<sizeof(boatL);btlp++)
	{
		invL=all_inventory(boatL[btlp]);
		userMark=0;
		for(ivlp=0;ivlp<sizeof(invL);ivlp++)
			if(userp(invL[ivlp]))
				userMark=1;
		if (!userMark)
			destruct(boatL[btlp]);
	}
	return sizeof(boatL);
}

int valid_leave(object me,string dir)
{
	object *all_ob=deep_inventory(me);
	for (int i=0;i<sizeof(all_ob);i++)
		if (all_ob[i]->query("pyh_gem_box"))
			return notify_fail("岸边的钓鱼人一把拉住你，指了指"+all_ob[i]->query("name")+"，还没有分成呢。\n");
	return ::valid_leave(me,dir);
}