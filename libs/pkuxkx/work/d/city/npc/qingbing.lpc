// 清军细作

#include <ansi.h>
inherit NPC;
int do_copy(object ob);
int kill2();
int bonus;

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
	set_skill("strike", 500);
	set_skill("cuff", 500);
	set_skill("hand", 500);
	set_skill("dodge", 500);
	set_skill("sword", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
	set_skill("blade", 500);
	set_skill("hammer", 500);
	set_skill("axe", 500);
	set_skill("staff", 500);
	set_skill("literate", 500);
	set_skill("whip", 500);
	set("no_get", 1);
	set("random_npc",1);
	setup();
	
	
	carry_object(__DIR__"items/cloth2")->wear();
	carry_object(__DIR__"items/yinggong")->wield();
	
	call_out("start",1);
	call_out("dest", 300);
}

int copy(object me)
{
	object ob=this_object();
	int i;
	int exp,exp2,lv;
	lv=500;
	exp = me->query("combat_exp");
	if ( exp < 500000 )
		exp=500000;
//	exp2=exp*10;
	while ((lv*lv/10)*lv<exp)
	{
		lv=lv+10;
	}
	ob->set_skill("dodge",lv);
	ob->set_skill("parry",lv);
	ob->set_skill("force",lv);
	ob->set_skill("strike",lv);
	ob->set_skill("longfeng-xiang",lv);
	ob->set_skill("bixue-xinfa",lv);
	ob->set_skill("juehu-zhang",lv);
	ob->set_skill("staff",lv);
	ob->set_skill("juemen-gun",lv);
	ob->map_skill("force", "bixue-xinfa");
	ob->map_skill("dodge", "longfeng-xiang");
	ob->map_skill("strike", "juehu-zhang");
	ob->map_skill("parry", "juehu-zhang");
	ob->map_skill("staff", "juemen-gun");
	ob->prepare_skill("strike", "juehu-zhang");

	ob->set("max_qi", me->query("max_qi")*2/3);
	ob->set("qi", ob->query("max_qi"));
	ob->set("max_jing", me->query("max_jing")*2/3);
	ob->set("jing", ob->query("max_jing"));
	ob->set("max_neili", me->query("max_neili")*2/3);
	ob->set("neili", ob->query("neili"));
	ob->set("combat_exp", exp);
}

int start()
{
	int i;
	object room=environment();
	object* all;
	if (environment())
	{
		all=all_inventory(environment());
	}
	for (i=0;i<sizeof(all) ;i++ )
		{
			if(!objectp(all[i])) continue;
			if (all[i]->query("id") == "qi bing")  //不杀自己
			{
				continue;
			}
			if (!living(all[i])) //不杀死物
			{
				continue;
			}
			else  //其他通杀
			{
				kill_ob(all[i]);
				all[i]->add_busy(3);
			}
			
		}
	call_out("shoot",2);
	return 1;
}
void destenv()
{
    int i,flag=0;
    object *ob;
    object env=environment(this_object());
    if (env&&base_name(env)=="/d/city/changjiang")
    {
        ob=all_inventory(env);
        for (i=0;i<sizeof(ob);i++)
        {
            if (userp(ob[i]))
            {
                flag=1;
            }
            if (!ob[i]->is_character())
            {
                    destruct(ob[i]);
            }
        }
        if (flag==0)
        {
            destruct(env);
        }
    }
    return;
}
void dest()
{
	object ob = this_object();
	if (environment(ob)) message_vision("$N匆匆忙忙地离开了。\n",ob);
	destruct(ob);
	return;
}

int bonus(object passer)
{
	int skftime;
	if ( !objectp(passer) )
	  return 1;
	
	if (passer->query("skfjob_last_time"))
	skftime=time()-(passer->query("skfjob_last_time"));
	if (skftime<0)
	{
		passer->add_temp("skf/credit",-5);
	}
	if (skftime>=0)
	{
		passer->add_temp("skf/credit",5);
	}
	if (skftime>=60)
	{
		passer->add_temp("skf/credit",5);
	}
	if (skftime>=120)
	{
		passer->add_temp("skf/credit",5);
	}
	if (skftime>=180)
	{
		passer->add_temp("skf/credit",5);
	}
	if (skftime>=240)
	{
		passer->add_temp("skf/credit",5);
	}
	passer->add("score",10);//暂时奖励
	passer->delete_temp("skf");
    passer->delete("skf/jobasked");
	passer->set_temp("skf/canceltimeup",1);
	return 1;	
}

int shoot()
{
	int i;
	object room=load_object("/d/city/changjiang");
	object* all=all_inventory(room);
	object passer;
		for (i=0;i<sizeof(all) ;i++ )
		{
			if(!objectp(all[i])) continue;
			if (all[i]->query("id") == "qi bing")
			{
				continue;
			}
			if (!living(all[i]))
			{
				continue;
			}
			else 
			{
				tell_object(all[i],this_object()->query("name")+HIY"举起了硬弓，开始对你第一轮攒射。\n"NOR);
				tell_object(all[i],RED"狼牙箭深深钻进你的身体，一股血箭飙了出来。\n"NOR);
                all[i]->set_temp("last_damage_from",this_object());
				if (all[i]->query("qi")<1000)
					{
						all[i]->die();
						passer=all[i];
						bonus(passer);
						call_out("aftereffect",10,passer);
						CHANNEL_D->do_channel(environment(), "rumor",sprintf("%s在与女真骑兵的决战中，为国捐躯，大义凛然。", all[i]->query("name")));
					}
				else
					{
						all[i]->add("qi",-1000);
						all[i]->start_busy(5);
					}
			}
		}
		
	
	call_out("shoot2",4);
	
	
	return 1;
	
}

int shoot2()
{
	int i;
	object room=load_object("d/city/changjiang");
	object* all=all_inventory(room);
	object passer;
	
		for (i=0;i<sizeof(all) ;i++ )
		{
			if(!objectp(all[i])) continue;
			if (all[i]->query("id") == "qi bing")
			{
				continue;
			}
			if (!living(all[i]))
			{
				continue;
			}
			else 
			{
				tell_object(all[i],this_object()->query("name")+HIW"举起了硬弓，开始对你第二轮攒射。\n"NOR);
				tell_object(all[i],RED"狼牙箭深深钻进你的身体，一股血箭飙了出来。\n"NOR);
                all[i]->set_temp("last_damage_from",this_object());
				if (all[i]->query("qi")<1000)
					{
						all[i]->die();
						passer=all[i];
						bonus(passer);
						call_out("aftereffect",10,passer);
						CHANNEL_D->do_channel(environment(), "rumor",sprintf("%s在与女真骑兵的决战中，为国捐躯，大义凛然。", all[i]->query("name")));
					}
				else
					{
						all[i]->add("qi",-1000);
						all[i]->start_busy(5);
					}
			}
		}
		
	
	call_out("shoot3",4);
	
	
	return 1;
	
}

int shoot3()
{
	int i;
	object room=load_object("d/city/changjiang");
	object* all=all_inventory(room);
	object passer;
		for (i=0;i<sizeof(all) ;i++ )
		{
			if(!objectp(all[i])) continue;
			if (all[i]->query("id") == "qi bing")
			{
				continue;
			}
			if (!living(all[i]))
			{
				continue;
			}
			else 
			{
				tell_object(all[i],this_object()->query("name")+MAG"举起了硬弓，开始对你第三轮攒射。\n"NOR);
				tell_object(all[i],RED"狼牙箭深深钻进你的身体，一股血箭飙了出来。\n"NOR);
                all[i]->set_temp("last_damage_from",this_object());
				if (all[i]->query("qi")<1500)
					{
						all[i]->die();
						passer=all[i];
						bonus(passer);
						call_out("aftereffect",10,passer);
						CHANNEL_D->do_channel(environment(), "rumor",sprintf("%s在与女真骑兵的决战中，为国捐躯，大义凛然。", all[i]->query("name")));
					}
				else
					{
						all[i]->add("qi",-1500);
						all[i]->start_busy(5);
					}
			}
		}
		
	
	call_out("shoot4",4);
	
	
	return 1;
	
}

int shoot4()
{
	int i;
	object room=load_object("d/city/changjiang");
	object* all=all_inventory(room);
	object passer;
		for (i=0;i<sizeof(all) ;i++ )
		{
			if(!objectp(all[i])) continue;
			if (all[i]->query("id") == "qi bing")
			{
				continue;
			}
			if (!living(all[i]))
			{
				continue;
			}
			else 
			{
				tell_object(all[i],this_object()->query("name")+HIR"举起了硬弓，开始对你进行最后的齐射。\n"NOR);
				tell_object(all[i],RED"狼牙箭深深钻进你的身体，一股血箭飙了出来。\n"NOR);
                all[i]->set_temp("last_damage_from",this_object());
				all[i]->die();
				passer=all[i];
				bonus(passer);
				call_out("aftereffect",10,passer);
				CHANNEL_D->do_channel(environment(), "rumor",sprintf("%s在与女真骑兵的决战中，为国捐躯，大义凛然。", all[i]->query("name")));

			}
		}
    call_out("destenv",14);
	call_out("dest",15);
	return 1;
}

//战死的bonus



int aftereffect(object passer)
{	
	tell_object(passer,RED"三日之后，清军破城，督师史可法壮烈就义。\n"NOR);
	tell_object(passer,"总兵刘肇基率余部继续与清军展开巷战，皆战死。\n");
	call_out("aftereffect2",3,passer);
	return 1;
}

int aftereffect2(object passer)
{	
	tell_object(passer,"扬州城内，诸妇女长索系颈，累累如贯珠，一步一跌，遍身泥土。\n");
	tell_object(passer,"满地婴儿，或衬马蹄，或藉人足，肝脑涂地，泣声盈野。\n");
	tell_object(passer,"满清军队在繁华的扬州城内，杀人、纵火、强奸、抢劫，暴行一直持续了六天。\n");
	tell_object(passer,WHT"史称“扬州十日”。\n"NOR);
	return 1;
}