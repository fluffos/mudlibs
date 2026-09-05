//元宵，专为庆祝icer得女而写，特殊效果为春节饺子2倍，不可随意开放
#include <ansi.h>

inherit ITEM;

string *names = ({
        HIR"芝麻元宵"NOR,
        HIY"豆沙元宵"NOR,
        HIM"水果元宵"NOR,
        HIC"什锦元宵"NOR,
        HIB"山楂元宵"NOR,
        HIW"桂花元宵"NOR,
});


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name( names[random(sizeof(names))] , ({ "yuan xiao","xiao" }) );
        set("unit", "碗");
        set("long", HIC"这是一碗香气四溢的元宵，是元宵佳节的传统食物。\n"NOR);
        set("value",0);
        set("no_store",1);
        setup();
}

int do_eat(string arg)
{
    object me = this_player();
    if (!arg)  return 0;
    if((arg=="yuan xiao") || (arg=="xiao")) 
    {
		if (time() > 1298563238) //2月24日24点失效    	
			return notify_fail("你吃了一口，发现元宵已经过了保质期，没法再吃了！\n");
    	if (me->query_temp("eating_jiaozi")) return notify_fail("你嘴里还有一个元宵呢，当心噎着！\n");
    	if(me->query("food")*100/me->max_food_capacity()>80) 
    		return notify_fail("你现在根本不饿，吃不下这么一大碗元宵。\n");    
    	message_vision("$N用筷子夹起一个元宵，津津有味地吃起来。\n",me);
    	me->set_temp("eating_jiaozi",1);
    	call_out("eat_jiaozi",5,me);
    	return 1;
    }
    return 0;
}

int eat_jiaozi(object me)
{
		int i;
		object bonus;

    	me->delete_temp("eating_jiaozi");

	    	i = random(100);
	    	if (i == 1 || i==0 || i >90) {
	                 if (me->query("bonus2011/money") <= 20 && (me->query("age") >15 || me->query("combat_exp")>1000000))
	    		{
		    		tell_object(me,HIY"你吃着正高兴，忽然觉得被什么东西硌了一下，赶紧吐出来，定睛一看，原来是一枚大金币！\n"NOR);
		            message("vision",me->name()+"忽然捂着嘴，大叫一声，吐出一块金灿灿的东西。\n",environment(me),({me}));
		            me->add("bonus2011/money",1);
		            bonus = new("/clone/gift/jinbi_tu");
					CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "吃到了"+HIY + "兔年吉祥金币" + HIM + "！"+NOR);
			        bonus->move(me);
		        }
	        }
			if (i == 2||i == 3) {
				if (me->query("bonus2011/kar") <1)
				{
					tell_object(me,HIR"你吃着吃着忽然咬到一块香喷喷的栗子，心里一喜：看来今年有福了！\n"NOR);
					message("vision",me->name()+"吃着吃着忽然脸色一喜，美滋滋地大嚼了几口。\n",environment(me),({me}));
					me->add("bonus2011/kar",1);
					me->add("kar",1);
					CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "吃到了"+HIR + "福字元宵" + HIM + "！"+NOR);
				}
			}
			if (i==4 && me->query("bonus2011/per")<1)
			{
				tell_object(me,HIG"你吃着吃着，忽然吃到一块滋味鲜美的蘑菇，想起蘑菇有美容功效，便放心吃了下去。\n"NOR);
					message("vision",me->name()+"吃着吃着忽然容光焕发，似乎更漂亮了。\n",environment(me),({me}));
					me->add("bonus2011/per",1);
					me->add("per",1);
					CHANNEL_D->do_channel(this_object(),"rumor",me->query("name") + "吃到了"+HIR + "蘑菇元宵" + HIM + "！"+NOR);
			}
			if ((i==5 && random(3000)==1 && me->query("bonus2011/special")<1 && me->query("betrayer")>1))
			{
				tell_object(me,HIR"你忽然吃到一个味道非常不一样的元宵，鲜美无比，堪称极品！\n"NOR);
				shout(HIR+REV+me->query("name")+"吃到了极品元宵！判师次数减一次！！！\n"NOR);
					me->add("bonus2011/special",1);
					me->add("betrayer",-1);
				log_file("2011jiaozi",me->query("id") + "吃到判师饺子。\n");

			}
		me->add("food",80);
		tell_object(me,"你把元宵全部咽了下去，开始细细回味元宵的滋味.....\n");		
		destruct(this_object());
	   return 1;
}
