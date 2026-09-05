// 清军细作

#include <ansi.h>
inherit NPC;
int arrowing();
string *title = ({
	"正黄旗", "正白旗", "正蓝旗", "正红旗", "镶黄旗", "镶白旗", "镶蓝旗", "镶红旗",
});

void create()
{
	string * surname=({"瓜尔佳","钮钴禄","舒穆禄","纳兰","董鄂","马佳","富察","萨克达",});
	string * givenname=({"明珠","索尔图","玄烨","弘历","福临","济尔哈朗","胤祯","旻宁","永琰",});
	set_name(surname[random(sizeof(surname))]+"."+givenname[random(sizeof(givenname))], ({ "qi bing", "bing"}));
	set("title", title[random(sizeof(title))]+"铁骑");
	set("gender", "男性");
	set("age", 30+random(30));
    set("qingqi",1);
	set("long","这是"+query("title")+"的女真的铁骑精兵。\n");
	set("attitude", "peaceful");
	set("combat_exp", 5000000);
	set("str", 20+random(5));
	set("int", 20+random(5));
	set("con", 20+random(5));
	set("dex", 20+random(5));
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("max_neili", 20000);
	set("neili", 5000);
	set("neili", 20000);
	set_temp("apply/armor", 100);
	set("jingli", 20000);
	set("max_jingli", 20000);
	set_skill("dodge",500);
	set_skill("parry",500);
	set_skill("force",500);
	set_skill("strike",500);
	set_skill("longfeng-xiang",500);
	set_skill("bixue-xinfa",500);
	set_skill("juehu-zhang",500);
	set_skill("staff",500);
	set_skill("juemen-gun",500);
	map_skill("force", "bixue-xinfa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("strike", "juehu-zhang");
	map_skill("parry", "juehu-zhang");
	map_skill("staff", "juemen-gun");
	prepare_skill("strike", "juehu-zhang");
	set("no_get", 1);
	
	setup();
	
	
	carry_object(__DIR__"items/cloth2")->wear();
	carry_object(__DIR__"items/yinggong")->wield();
	
	call_out("start",1);
	call_out("dest", 300);
}

int getnumber()
{
    int i,mbnumber,qbnumber;
    object *allob;
    object ob=this_object();
    if (environment(ob))
    {
        allob=all_inventory(environment(ob));
		for (i=0;i<sizeof(allob);i++)
        {
            if (allob[i]->query("mingqi"))
            mbnumber=mbnumber+1;
            if (allob[i]->query("id")==ob->query("target"))
            mbnumber=mbnumber+2;
			if (allob[i]->query("qingqi"))
			qbnumber=qbnumber+1;
        }
        ob->set("qbnumber",qbnumber);
        ob->set("mbnumber",mbnumber);
        return 1;
    }
    else
    {
        return 1;
    }
}

int copy(object me)
{
	object ob=this_object();
	int i;
	int exp,tempskill;
    mapping skills;
	exp = me->query("combat_exp");
	tempskill = to_int(pow(exp/100,0.333)*10);
    if (random(5))
    {
        tempskill = tempskill/5*4;
    }
    if (random(100)>90)
    {
        tempskill = tempskill/3*5;
        exp=exp/3*4;
    }
    if (tempskill==0)
                 tempskill=10;
    skills = ob->query_skills();
    for (i=0;i<sizeof(skills);i++)
    {
        skills[keys(skills)[i]] = tempskill;
    }

	ob->set("max_qi", me->query("max_qi")*2/3);
    if (ob->query("max_qi")>12000)
    {
        ob->set("max_qi",12000);
    }
	ob->set("qi", ob->query("max_qi"));
	ob->set("max_jing", me->query("max_jing")*2/3);
	ob->set("jing", ob->query("max_jing"));
	ob->set("max_neili", me->query("max_neili")*2/3);
	ob->set("neili", ob->query("neili"));
	ob->set("combat_exp", exp);
}

int start()
{
	int i,count;
	object room=environment(this_object());
	object* all;
    object pl;
    count=0;
	if (!room||!room->isroom())
	{
		return 1;
	}
	all=all_inventory(room);
    getnumber();
    if (this_object()->query("qbnumber")>this_object()->query("mbnumber")&&this_object()->query("mbnumber"))
    {
        arrowing();
    }
    for (i=0;i<sizeof(all) ;i++ )
	{
		if(!objectp(all[i])||all[i]->query("id") == "qi bing"||!living(all[i])||all[i]->query("no_show")) 
		{
			count=count+1;
			continue;
        }
		if (all[i]->is_character())
        kill_ob(all[i]);
	}
	if (count>=sizeof(all))
	{
		if (room->query("owner")!="qing")
		{
			room->set("owner","qing");
			room->occupy_msg(room->query("owner"));
			pl=find_player(this_object()->query("target"));
			if (pl&& pl->query_temp("skf/skf2"))
			{
				tell_object(pl,"女真骑兵占领了有利地形，你不得不带队撤退回扬州，回史督师处领罪吧。\n");
				pl->delete_temp("skf");
				pl->set_temp("skf/canceltimeup2",1);
				pl->move("/d/city/junying");
				destruct(this_object());
				return 1;
			}
			if (!pl||!pl->query_temp("skf/skf2"))
			{
				destruct(this_object());
				return 1;
			}
		}
		random_move();
	}
	remove_call_out("start");
    call_out("start",10);
	return 1;
}

void dest()
{
	object ob=this_object();
    object me;
    if (!ob->query("target")||!find_player(ob->query("target")))
    {
        destruct(ob);
	    return;
    }
    me=find_player(ob->query("target"));
    if (me)
    {
        me->add_temp("skf/qb",-1);
        if (me->query_temp("skf/qb")==0)
        {
            me->set_temp("skf/canback",1);
            tell_object(me,BLINK HIG"女真骑兵被全部消灭，你可以回(back)史可法处复命了。\n"NOR);
        }
    }
    if (environment(ob)) 
	message_vision("$N见不能占领长江天险，悻悻地离开了。\n",ob);
	destruct(ob);
	return;
}

int refre()
{
    this_object()->set("arrowcount",0);
    this_object()->set("arrow",0);
	this_object()->set("no_arrow_notice",0);
    message_vision(HIW"$N休息充足，又可以开弓放箭了。\n"NOR);
    return 1;
}

int arrowing()
{
	int i;
    object liveman;
    object ob=this_object();
	object room=environment(this_object());
	object* all=all_inventory(room);
    if (!this_object()->query("buzhen"))
    {
        return 0;
    }
    if (ob->query("arrowcount")>3)
    {
        call_out("refre",10);
        if (!ob->query("no_arrow_notice"))
		{
			message_vision(HIW"$N连射几轮手臂酸软，不得不停了下来。\n"NOR,ob);
			ob->set("no_arrow_notice",1);
		}
        return 1;
    }
    ob->set("arrow",1);
	for (i=0;i<sizeof(all) ;i++ )
	{
		if(!objectp(all[i])) continue;
		if (all[i]->query("qingqi")||!living(all[i])||all[i]->query("no_show")||(all[i]->query("mingpin")&& random(5)))
		continue;
		else 
		{
			if (userp(all[i]))
			{
				tell_object(all[i],this_object()->query("name")+HIY"举起了硬弓，开始对你第一轮攒射。\n"NOR);
				tell_object(all[i],RED"狼牙箭深深钻进你的身体，一股血箭飙了出来。\n"NOR);
			}
			if (all[i]->query("qi")<1000)
			{
				all[i]->die();
			}
			else
			{
				all[i]->add("qi",-1000);
				liveman=all[i];
			}
		}
	}
	if (!liveman)
    {
        return 1;
    }
	message_vision(HIR"女真铁骑举起硬弓，开始乱箭齐射。\n"NOR,ob);
    ob->add("arrowcount",1);
	call_out("arrowing",5);
	return 1;
}

void die()
{
    object ob=this_object();
    object me;
    if (ob->query("target"))
    {
        me=find_player(ob->query("target"));
    }
    if (me)
    {
        me->add_temp("skf/qb",-1);
    }
    if (me->query_temp("skf/qb")==0)
    {
        me->set_temp("skf/canback",1);
        tell_object(me,BLINK+HIG"女真骑兵被全部消灭，你可以回(back)史可法处复命了。\n"NOR);
    }
    ::die();
}