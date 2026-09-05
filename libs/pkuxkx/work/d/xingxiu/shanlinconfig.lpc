// Zine 19 Oct 2010 星宿山林配置

inherit ROOM;
#include <ansi.h>
string* wudu = ({

       __DIR__"npc/she",
	   __DIR__"npc/hama",
       __DIR__"npc/wugong",
       __DIR__"npc/xiezi",
       __DIR__"npc/zhizhu",
     
});

string* wudu2 = ({

       __DIR__"npc/she2",
	   __DIR__"npc/hama2",
       __DIR__"npc/wugong2",
       __DIR__"npc/xiezi2",
       __DIR__"npc/zhizhu2",
     
});

string* ducao = ({

       __DIR__"obj/leaf1",
	   __DIR__"obj/leaf2",
       __DIR__"obj/leaf3",
       __DIR__"obj/leaf4",
       __DIR__"obj/leaf1",
	   __DIR__"obj/leaf2",
       __DIR__"obj/leaf3",
       __DIR__"obj/leaf4",
       __DIR__"obj/leafe",
       __DIR__"obj/leaff",
       __DIR__"obj/leafg",
       __DIR__"obj/leafh",
       __DIR__"obj/leafe",
       __DIR__"obj/leaff",
       __DIR__"obj/leafg",
       __DIR__"obj/leafh",
     
});

int change_night_desc();



void init()
{
    object me=this_player();
	set("no_die",1);
	me->listen_to_die(this_object());
	if (me->query("family/family_name")=="星宿派")
	{
		me->set("startroom", base_name(this_object()));
		me->set_temp("revive_room",base_name(this_object()));
	}
    add_action("do_pi", ({ "pi","chop" }));
    add_action("do_fan", ({ "fan","xian" }));
    add_action("do_zhai", ({ "zhai" }));
    add_action("do_dig", ({ "wa" }));
	if (!this_object()->query("day")||!userp(me)||me->query("family/family_name")=="星宿派"||(me->query("emnewbiejob_miejue_task")==1&&me->query("family/family_name")=="峨嵋派"))
	return;
	if (me->query_skill("force",1)>=400)//内功高深免疫
	{
		tell_object(me, HIW "你运起本门纯正内功，抵御雾中的毒气。\n" NOR );
		return;
	}
	me->apply_condition("xxfog-poison", me->query_condition("xxfog-poison")+random(10)*2);
	tell_object(me, HIB "山林中的雾气蕴藏着寒毒，你中毒了！\n" NOR );
}

void create()
{
	set("no_task",1);
    set("valid_startroom", 1);
    set("shuhp",5+random(5));
    set("outdoors", "xingxiuhai");

    
}

int delxian()
{
    this_object()->delete("xian");
    return 1;
}

int removexian(object me)
{
    if (me)
    {
        me->delete_temp("xxnewbiejob/xian");
        return 1;
    }
    
}



int do_dig()
{
    object me=this_player();
    object dc;
    
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着呐！\n");
    }
    
   
        if (random(10)>1)
        {
            
            message_vision("$N摘下树边的一根不知名小草。\n",me);
            dc = new( ducao[random(sizeof(ducao))] );
            dc->set("owner",me->query("id"));
//            dc->set("no_drop",1);
            dc->set("no_get",1);
            dc->move(me);
            me->add_busy(random(3));
            
            return 1;
        }
        else
        {
            message_vision("$N在地上找了半天，却什么也没发现。\n",me);
            me->add_busy(random(3));
            return 1;
        }
        
    
    
}

int do_fan()
{
    object me=this_player();
    object wd;
	string file;
    int cdtime=50,rdm;
	if (me->query("antirobot/deactivity") > 1)
	cdtime=60-random(5);
	if (me->query("antirobot/deactivity") > 2)
	cdtime=70-random(5);
	if (this_object()->query("xian")||me->query_temp("xxnewbiejob/xian"))
	return notify_fail("你当真以为星宿海遍地毒虫？还是你要犁地？\n");
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着呐！\n");
	if ((int)me->query_skill("poison", 1) >= 700)
	return notify_fail("你的毒技已经较为高深，毒虫留给门中后辈们吧。\n");
	if ((int)me->query_skill("poison", 1) >= 600&&!me->query("safari_skill/xx_dushen"))
	return notify_fail("你的毒技已经较为高深，毒虫留给门中后辈们吧。\n");
    if ((int)me->query_skill("poison",1) <= 300)
    {
		rdm=4;
		file=wudu[random(sizeof(wudu))];
		this_object()->set("xian",1);
		call_out("delxian",30);  
    }
    else
    {
		rdm=3;
		file=wudu2[random(sizeof(wudu2))];
		cdtime=cdtime*10/9;
	}
	if (random(10)>rdm)
	{
		message_vision("$N掀起地上的石块，一只不知名的虫子爬了出来。\n",me);
		wd = new(file);
		wd->set("name",me->query("name")+"发现的 "+wd->query("name"));
		wd->set("owner",me->query("id"));
		wd->move(this_object());
		me->set_temp("xxnewbiejob/xian",1);
		call_out("removexian",1+cdtime,me);
	}
    else
    {
        message_vision("$N在地上找了半天，却什么也没发现。\n",me);
    }
	me->add_busy(random(3));
	return 1;
}

int do_pi()
{
	object me = this_player();
	object gangfu=present("da futou",me);
    object yuanmu;
    if (!(me->query_temp("xxnewbiejob/bpz")))
		return notify_fail("未得星宿派大弟子同意，不许乱砍滥伐！\n");
    if (this_object()->query("nochop"))
    {
        return notify_fail("这里已经没有成材的古树，只剩下小树苗了！\n");
    }
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着呐！\n");
        }
	if(!present("da futou", me))
		{
			return notify_fail("你似乎应该找把斧头来砍树。\n");
		}
	else
		{
			if(gangfu->query("equipped"))
				{
					message_vision("$N使出吃奶的劲，拿起斧头，向古树劈去。\n", me);
                    if (this_object()->query("shuhp")<=0)
                    {
                        me->add_busy(1+random(2));
                        me->delete_temp("xxnewbiejob/bpz");
                        me->set_temp("xxnewbiejob/bpz1",1);
                        message_vision(HIY"古树晃了两晃，终于倒了下来。\n"NOR, me);
                        tell_object(me,"这时大斧头使用过度，也终于折断了。\n");
                        destruct(gangfu);
                        yuanmu=new(__DIR__"obj/yuanmu");
                        yuanmu->set("owner",me->query("id"));
                        yuanmu->move(this_object());
                        this_object()->set("shuhp",5+random(5));
                        this_object()->set("nochop",1);
                        remove_call_out("nochop");
                        call_out("nochop",120);
                        return 1;
                    }
                    else
                    {
                        me->add_busy(1+random(2));
                        this_object()->add("shuhp",-1);
                        return 1;
                    }
				}
			else
				{		
					tell_object(me,"你不把斧头拿到手上怎么劈？\n");
                    return 1;
		        }
		}
}

int nochop()
{
    this_object()->delete("nochop");
    return 1;
}

int found2(object me)
{
	object ob = new("/d/xingxiu/obj/yeguo");
	if (ob) 
		{
			if (random(10)>7)
			{
				ob->move(me);
				me->add_busy(random(2));
				message_vision("$N摘了一只野果下来。\n", me);
			}
			else
			{
				message_vision("$N左看右看，却没发现合适的野果。\n", me);
				me->add_busy(1);
			}
		}
	return 1;
}

int do_zhai()
{
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    if(present("fruit", me) ) 
		{ 
			return notify_fail(WHT"这里虽然盛产野果，你也给师兄弟们留点啊。\n"NOR);
		}
    else 
		{ 
			found2(me);    
        }
	return 1; 
}

int valid_leave(object me, string dir)
{       
    me->remove_listen_to_die(this_object());        
    return ::valid_leave(me, dir);
}