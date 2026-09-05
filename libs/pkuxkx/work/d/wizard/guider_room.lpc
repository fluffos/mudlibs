#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"敬师堂"NOR);
        set("long", @LONG
这是一间方方正正的屋子，正北挂着千秋文圣孔子像，前面摆着香案，
青烟袅袅。新人可以在这里拜入(baishi)导师门下，接受导师的帮助，以最
快的速度融入北侠。新人经验超过10M ，并且通过实名验证以后，就可以在
这里结业，并给导师评分。(pingfen)           
LONG );

        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg", 1);
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("exits", ([
                "south" : "/d/city/shuyuan",
        ]));
        set("room_location", "/d/city/");
        setup();
}

void init()
{
    add_action("do_bai","baishi");
    add_action("do_agree","agree");
    add_action("do_pingfen","pingfen");
}
int apps_limit(object me)
{
	int lv,*limits=({20,25,25,30,30,30,30,30,30,35});
	if (lv=GUIDER_D->group_level(me))
	{
		if (lv>10)
		lv=10;
		if (lv<1)
		lv=1;
		return limits[lv-1];
	}
	return 20;
}
int do_bai(string arg)
{
    object guider;
    object me = this_player();

    if(!arg)
    {
        write("bai 某人。这个人必须也在这里，并且是新手导师。用wizlist可以查看北大侠客行MUD有哪些新手导师。\n");
        return 1;
    }
    if(!objectp(guider = present(arg,this_object())) || !userp(guider) || SECURITY_D->get_status(guider->query("id")) != "(guider)" )
    {
        write("bai 某人。这个人必须也在这里，并且是新手导师。用wizlist可以查看北大侠客行MUD有哪些新手导师。\n");
        return 1;
    }

    if(GUIDER_D->is_app(me->query("id"))!="")
    {
		if (GUIDER_D->is_app(me->query("id"))=="is_GUIDER")
		{
			write("开玩笑吧，你自己就是新手导师。\n");
		}
        else if(GUIDER_D->is_app(me->query("id")) == arg)
        {
            message_vision("$N恭恭敬敬的向$n磕头叫道：师傅！\n",me,guider);
        }
        else
        {
            write("你已经有导师了，他是"+GUIDER_D->is_app(me->query("id"))+"，去找他吧。如果他长期不上线帮助你，你可以向巫师投诉。\n");
        }        
        return 1;
    }

    if(me->query("combat_exp") > 10000000)
    {
        write("你已经不是新手了。\n");
        return 1;
    }
    
    if(arrayp(GUIDER_D->app_list(guider->query("id"))) && sizeof(GUIDER_D->app_list(guider->query("id"))) >= apps_limit(guider) && member_array(me->query("id"),GUIDER_D->app_list(guider->query("id"))) == -1)
    {
        write(guider->query("id")+"已经收了太多的学生了，没有精力照顾你。请你另找导师吧。\n");
        return 1;
    }
    write("你打算拜"+guider->name()+"为导师。请等待对方的答复。\n");
    tell_object(guider,me->name()+"想要拜你为导师，如果你同意，请输入agree "+me->query("id")+"\n");
    me->set_temp("newbie/guider",arg);
    return 1;
}

int do_agree(string arg)
{
    object app;
    object me = this_player();
    string* apps;
	if (SECURITY_D->get_status(me->query("id")) != "(guider)")
	{
		return 0;
	}
    if(!arg)
    {
        write("agree 某人。这个人必须也在这里，并且愿意拜你为导师。\n");
        return 1;
    }
    if(!objectp(app = present(arg,this_object())) || !userp(app) || app->query_temp("newbie/guider") != me->query("id") )
    {
        write("agree 某人。这个人必须也在这里，并且愿意拜你为导师。\n");
        return 1;
    }
    
    message_vision("$N同意收$n为徒，负责指导$n的新手历程了。\n",me,app);
    write("恭喜你！希望你能将"+app->name()+"培育为将来的天下高手！\n");
    tell_object(app,"恭喜你！希望你在"+me->name()+"的帮助下，成为将来的天下高手！\n");    
    
    app->delete_temp("newbie/guider");
    GUIDER_D->add_app(me,app->query("id"),0,0);
	/*
    if(member_array(app->query("id"),apps) == -1)
    {
        //这是考虑某些拜师后又自杀的情况。
        apps += ({app->query("id")});
    }
    me->set("guider/apps",apps);
    me->set("guider/modify_time",time());//By Zine，记录变更关系实际，方便文件同步
    */
	shout(HIY +""+me->name()+"今天成为新人"+app->name()+"的导师！\n"NOR);

    return 1;
}

int do_pingfen(string arg)
{
    object guider;
    object me = this_player();
    string id;
    int score;
    string* apps;
    string* old_apps;
	if (GUIDER_D->is_app(me->query("id"))==""||GUIDER_D->is_app(me->query("id"))=="is_GUIDER")
	{
		write("想要评分，至少得有一个导师吧？\n");
		return 1;
	}
    if(!arg)
    {
        write("pingfen 某人 分数(0~10)。这个人必须也在这里，并且是你的新手导师。\n");
        return 1;
    }
    if(sscanf(arg,"%s %d",id,score) != 2)
    {
        write("pingfen 某人 分数(0~10)。这个人必须也在这里，并且是你的新手导师。\n");
        return 1;
    }
    if(!objectp(guider = present(id,this_object())) || !userp(guider) || SECURITY_D->get_status(guider->query("id")) != "(guider)" || member_array(me->query("id"),GUIDER_D->app_list(guider->query("id")))==-1)
    {
        write("pingfen 某人 分数(0~10)。这个人必须也在这里，并且是你的新手导师。\n");
        return 1;
    }

    if(score < 0 || score > 10)
    {
        write("请在0到10分之间评分。\n");
        return 1;
    }

    if(me->query("combat_exp") < 10000000)
    {
        write("你只有在经验超过10M后才能给导师评分并结束指导关系。\n");
        return 1;
    }

    if(!me->is_realuser() && me->query("reborn/all") < 1 )
    {
        write("你只有通过实名验证或者过劫难后才有资格给导师评分。\n");
        return 1;
    }
    
    if(!me->is_realuser())
    {
        //非实名玩家，最多给到5分
        if(score > 5) 
        {
            write("由于你不是实名玩家，你最多只能给你的导师以5分的评价。\n");
            score = 5;
        }        
    }
    
    write("你决定给你的导师"+guider->name()+"评"+chinese_number(score)+"分。你们的师徒关系现在解除。希望你们是永远的朋友。\n");
    tell_object(guider,me->name()+"对你的评价是"+chinese_number(score)+"分。你们的师徒关系现在解除。希望你们是永远的朋友。\n");

    GUIDER_D->add_app(guider,me->query("id"),0,1);
	GUIDER_D->del_app(me->query("id"));
	GUIDER_D->add_score(guider->query("id"),score*100);
    //guider->add("guider/score",score*100);
    return 1;

}
