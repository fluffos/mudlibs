//饺子，春节礼物
#include <ansi.h>

inherit ITEM;

string *names = ({
        HIR"猪肉白菜饺子"NOR,
        HIY"萝卜牛肉饺子"NOR,
        HIM"冬瓜鸡蛋饺子"NOR,
        HIC"三鲜饺子"NOR,
        HIB"大虾饺子"NOR,
        HIW"鲜鱼饺子"NOR,
});


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name( names[random(sizeof(names))] , ({ "jiao zi","jiao" }) );
        set("unit", "盘");
        set("long", HIC"这是一盘热气腾腾的饺子，是春节的传统食物。\n"NOR);
        set("value",0);
		set("no_give",0);
        set("no_store",1);
        setup();
}

int do_eat(string arg)
{
    object me = this_player();
	object ob = this_object();
    if (!arg)  return 0;
	if (ob->query("owner") != me->query("id"))
		{
             return notify_fail("这不是你的饺子，你也不怕别人下毒害你？\n");
		}

    if((arg=="jiao zi") || (arg=="jiao")) 
    {

		if (time() > 1456283990) //正月十五晚12点失效    	
			return notify_fail("你吃了一口，发现饺子已经过了保质期，没法再吃了！\n");
    	if (me->query_temp("eating_jiaozi")) return notify_fail("你嘴里还有一个饺子呢，当心噎着！\n");
    	if(me->query("food")*100/me->max_food_capacity()>80) 
    		return notify_fail("你现在根本不饿，吃不下这么一大盘饺子。\n");    
    	message_vision("$N随手拿了个小盘子，倒了点饺子醋，夹起饺子津津有味地吃起来。\n",me);
    	me->set_temp("eating_jiaozi",1);
		remove_call_out("eat_jiaozi");
    	call_out("eat_jiaozi",5,me);
    	return 1;
    }
    return 0;
}

int eat_jiaozi(object me)
{
		int i;
		object bonus;
	//    object ob=this_object();
	object ob;
	string skill;
	mapping skills;
	int level,add_temp;
	me = this_player();
	ob = this_object();

if (ob->query("owner") != me->query("id"))
		{
             return notify_fail("这不是你的饺子，你也不怕别人下毒害你？\n");
		}
    	me->delete_temp("eating_jiaozi");

	    	i = random(100);
	    	if (i == 1 || i==0 || i > 96) {
	                 if ((me->query("age") >18 || me->query("combat_exp")>1000000))
	    		{
		    		tell_object(me,HIY"你吃着正高兴，忽然觉得被什么东西硌了一下，赶紧吐出来，定睛一看，原来是一枚大金币！\n"NOR);
		            message("vision",me->name()+"忽然捂着嘴，大叫一声，吐出一块金灿灿的东西。\n",environment(me),({me}));
		 //           me->add("bonus2016/money",1);
		            bonus = new("/clone/gift/jinbi_hou");
					CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "吃到了"+HIY + "猴年吉祥金币" + HIM + "！"+NOR);
			        bonus->move(me);
		        }
	        }
			if (i == 2 || i==82 || i == 92) {
				if (me->query("bonus2016/yaowu") <1)
				{
					tell_object(me,HIR"你吃着吃着忽然吃到了一块苦岑涔的饺子，眉头一皱：这是啥啊！\n"NOR);
					message("vision",me->name()+"突然苦尽甘来，立刻美滋滋地大嚼了几口。\n",environment(me),({me}));
					me->add("bonus2016/yaowu",1);
					me->add("max_jingli",100);
					me->add("max_neili",100);
					CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "吃到了"+HIR + "药物饺子" + HIM + "！"+NOR);
				}
			}
			if ((i==3 || i==73 || i==93) && me->query("bonus2016/age")<1)
			{
				tell_object(me,HIG"你吃着吃着，忽然吃到一块滋味鲜美的蘑菇，想起蘑菇有返老还童的功效，便放心吃了下去。\n"NOR);
					message("vision",me->name()+"吃着吃着忽然容光焕发，似乎更年轻了。\n",environment(me),({me}));
					me->add("bonus2016/age",1);
					if (me->query("age")>27)
					{
						 me->add("mud_age",-172800);
					}
					CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "吃到了"+HIR + "蘑菇饺子" + HIM + "！"+NOR);
			}
			if ((i==4 && random(100)==1 && me->query("bonus2016/special")<1 && me->query("betrayer")>1))
			{
				tell_object(me,HIR"你忽然吃到一个味道非常不一样的饺子，鲜美无比，堪称极品！\n"NOR);
				shout(HIR+REV+me->query("name")+"吃到了极品饺子！判师次数减一次！！！\n"NOR);
					me->add("bonus2016/special",1);
					me->add("betrayer",-1);
				log_file("2016jiaozi",me->query("id") + "吃到判师饺子。\n");

			}
			if ((i==5 || i==15 || i=55 || i==35|| i== 95)&&(me->query("bonus2016/newskill")<2))
			{
				tell_object(me,HIG"你吃着吃着，忽然吃到一块奇怪的饺子，吃完身体有点奇怪的感觉。\n"NOR);
				message("vision",me->name()+"似乎自己对武学的领悟更深了一层。\n",environment(me),({me}));
				me->add("bonus2016/newskill",1);
				CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "吃到了"+HIR + "奇怪饺子" + HIM + "！"+NOR);
			skills = me->query_skills();
			if (!skills || sizeof(skills)==0)	//没功夫，直接给他本literate
			{
				write("你都没有技能，来混啥混啊！");
			}
			else 
			{
				i = random(sizeof(skills));
				skill = keys(skills)[i];
				level = values(skills)[i];
				if (level >= 100)	//取这个功夫
				{
					  add_temp = 1+random(3);
					  if ( !intp(skills[skill]) )
					  {
						skill="force"; 
					  } //多层技能的不奖励等级
					  
					  if(skill == "tianmo-jieti") 
					  {
						skill="force"; 
						  };//不奖励天魔解体
					  
					  if(skill == "business") 
					  {
						skill="force"; 
					  };//不奖励经商之道
					  if (SKILL_D(skill)->professional())
					  {
						  skill="force";
					  };//不奖励专业技能
					  if (!me->query("chushi") && !me->query("betrayer"))
					  {
						  add_temp += 1;
					  }
					  if (skill == "zui-quan")
					  {
						  add_temp = 1;
					  }
					level += add_temp;
					me->set_skill(skill,level);
					tell_object(me,"你吃到了奇怪饺子，你的"+CHINESE_D->chinese(skill)+"升级了！\n");		

					log_file("2016newyear",me->name() + "得到了能读到" + level + "级的" + CHINESE_D->chinese(skill)+"秘籍\n");
		//	return;
		}
	}

			}
		me->add("food",80);
		tell_object(me,"你把饺子全部咽了下去，开始细细回味饺子的滋味.....\n");		
		destruct(this_object());
	   return 1;
}
