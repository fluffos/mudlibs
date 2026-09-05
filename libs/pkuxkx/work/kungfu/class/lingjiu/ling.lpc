// liangong-fu.c
// 增加奖励by yhzzyahoo@2015.11.5
inherit ITEM;
#include <ansi.h>
//定义任务函数
int consider_lv(object ob,int a);
//定义任务随机时间。
nosave int i = random(9)+5;
void create()
{
        set_name("灵鹫灭敌令", ({ "lj lingpai","ling"}));
        set("long", "一块灵鹫灭敌令,有了它的弟子一般负责护卫任务(huwei)。\n");
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("value", 0);
                set("unit", "块");
        }
        setup();
}

void init()
{
//定义任务命令
        add_action("do_huwei","huwei");
        add_action("do_touxiang","touxiang");
}
int do_huwei()
{
	object ob,me=this_player();
	string targ;
	object obj;
	int maxpot;
	//检查是否接了任务
	if(!me->query_temp("ljhw"))
	return notify_fail("你不能用这块令牌做任务。\n");
	//检查是否是本人的令牌
	if (this_object()->query("userid")!=me->query("id"))
	return notify_fail("这不是你的灵鹫灭敌令!!\n");
	//检查是否在任务地点,这一句为防背人BUG.
	if (!environment(me))  return notify_fail("这里不是要你护卫的地方!\n");
	//检查是否在任务地点
	if (environment(me)->query("short") !=me->query_temp("ljhwjob"))
	return notify_fail("不是叫你到"+me->query_temp("ljhwjob")+"去护卫吗!\n");
	if (base_name(environment(me))[0..9] != "/d/lingjiu")
		return notify_fail("这不是灵鹫的" + me->query_temp("ljhwjob") + "！\n");
	//种种限制条件
	        if (me->is_busy())
	        {
	          tell_object(me,"你正忙着呢！\n");
	          return 1;
	        }
		if( me->is_fighting() )
	        {
	          tell_object(me,"等打完了，再说吧，！\n");
	          return 1;
	        }
	
	        if ((me->query("jing") < 50))
	        {  
	          tell_object(me,"你的精力不能集中！\n");
	          return 1;
	        }
	        if ((me->query("qi") < 50 ))
	        {
	          tell_object(me,"你的身体状态太差!\n");
	          return 1;
	        }
	        if ((me->query("jingli") < 60))
	        {  
	          tell_object(me,"你的精力不够！\n");
	          return 1;
	        }
	        if ((me->query("neili") < 60 ))
	        {
	          tell_object(me,"你的内力不够!\n");
	          return 1;
	        } 
	//开始任务
	message_vision(HIW"\n$N在"+me->query_temp("ljhwjob") + "来回走动，寻找敌人!\n"NOR,me);
	me->add("jing",-50);
	me->add("neili", -50);
	//增加任务次数,到一定次数，结束任务
	me->add_temp("ljjob",1);
	//检查是否可以战斗的地点
	if( !environment(me)->query("no_fight"))
	//随机出现敌人，并COPY玩家数据
	if (random(10)>3 && me->query_temp("ljjob") < i )
	{
                switch(random(5))
		{
			case 0:
				obj = new(__DIR__"jianghuke");
				break;
			case 1: 
				obj = new(__DIR__"shaolin");
				break;
			case 2:
				obj = new(__DIR__"emei");
				break;
			case 3:
				obj = new(__DIR__"wudang");
				break;
            case 4:
                obj = new(__DIR__"mingjiao");
            break;
		}
		obj->do_copy(me,maxpot,2);
		obj->set("userid",me->query("id"));
		obj->move(environment(me));
		message_vision(HIY"$N狂笑道：今天我要见识见识你们灵鹫宫有什么厉害?\n"NOR, obj);
		obj->set("uni_target",me);
		me->kill_ob(obj);
		obj->kill_ob(me);
                me->start_busy(0);
                me->start_busy(random((int)me->query_temp("lingjiuhuwei/killed_number")));
	}
	else
		me->start_busy(5);
	//检查任务次数，是否满足要求
	if ((me->query_temp("ljjob") >i||time()-(int)me->query("huwei_last_time")>150)&& 
	!me->is_fighting())
	{
//		tell_object(me,HIW"护卫时间已经到了，你的任务完成了。\n"NOR);
		tell_object(me,HIG"护卫时间已经到了，你的任务完成了。\n"NOR);		
		message_vision(HIG"$N任务完成，把令牌交给了别的弟子。\n"NOR,me,ob); 
		me->start_busy(5);
		call_out("destroying", 0, me);                       
	}

        return 1;
}
void destroying(object me)
{   
int exp,pot,sc,rep;
if (!me) return;
//奖励并结束任务
//        sc= random(36)+5;
	exp = (me->query_temp("lingjiuhuwei/killed_number"))* (random(300) + 100);
	sc = (me->query_temp("lingjiuhuwei/killed_number"))* (random(4)+2);
//         rep = (me->query_temp("lingjiuhuwei/killed_number"))* (random(150) + 100);
   rep = (me->query_temp("lingjiuhuwei/killed_number"))* (random(1200) + 1200);
me->add("jobs/completed/lingjiu_huwei",1);
me->add("combat_exp",exp);
pot = REWARD_D->add_pot(me,exp);
tell_object(me,"你的经验提高了"+chinese_number(exp)+"点,\n潜能提高了"+chinese_number(pot)+"点。\n");

if (me->query("family/family_name") == "灵鹫宫")
{
	me->add("score", sc);
	me->add("repute",rep/2);
	tell_object(me,"你的师门忠诚度提高了"+chinese_number(sc)+"点。\n");
	tell_object(me,"你的武林声望提高了"+chinese_number(rep/2)+"点。\n");

}
else 
{
	rep = REWARD_D->add_rep(me, rep);
	tell_object(me,"你的武林声望提高了"+chinese_number(rep)+"点。\n");
}
        me->delete_temp("ljjob");
        me->delete_temp("ljhw");
        me->delete_temp("ljhwjob");
        me->delete_temp("lingjiuhuwei");
        destruct(this_object());
}
int do_touxiang()
{
        object *inv, me,ob;
        int i,exp,pot,found;
        exp= random(3000) + 1000;//投降处罚相应减半，与获得同步 By Zine Nov 10 2010
        pot= exp/5;
        me = this_player();
        ob = this_object();

	if (this_object()->query("userid") != me->query("id"))
		return notify_fail("这不是你的灵鹫灭敌令！\n");
	found = 0;
        inv = all_inventory(environment(me));
                for(i=sizeof(inv)-1; i>=0; i--) {
                    if ( (inv[i]->query("uni_target") == me) && (inv[i]->query("userid")==me->query("id")) )
                    {
			    if (inv[i]->query("no_touxiang") || random(10) == 1)
				{
					message_vision(inv[i]->query("name") + "嘿嘿一笑：打不过就想投降？老子就是来灭灵鹫的！投降？休想！\n",me);
					inv[i]->set("no_touxiang",1);
					return 1;
				}
	        	message_vision("$N抛下武器向" + inv[i]->query("name") + "投降，" + inv[i]->query("name") + "冷笑一声：灵鹫功夫也不过如此！\n",me,this_object());	
	        	found = 1;
                    	destruct(inv[i]);
                    }
                   }
        if (!found)
        	return notify_fail("你要向谁投降？\n");
        tell_object(me,"你的经验下降了" + chinese_number(exp) + "点！你的潜能下降了" + chinese_number(pot) + "点！\n");
	if (me->query("combat_exp") > 100000)
	        me->add("combat_exp",0-exp);
        me->add("potential",0-pot);
        me->apply_condition("ljjob2_busy",20);
        if (me->query("potential") < me->query("learned_points"))
        	me->set("potential",me->query("learned_points"));
        me->set_temp("lingjiuhuwei/killed_number",0);
        me->delete_temp("ljjob");
        me->delete_temp("ljhw");
        me->delete_temp("ljhwjob");
        me->delete_temp("lingjiuhuwei");
        destruct(this_object());
        return 1;

}
