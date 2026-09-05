//midao

#include <room.h>
#include <ansi.h>
#include "/doc/help.h"
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
inherit ROOM;
int *levelup_cd=({1,3,7,7,7,7});
void create()
{
        
        set("short", "秘室");
        set("long","这里是明教秘室，前方有一扇大石门，上面刻着:
                " + HIR "明教重地，非教主莫入" NOR + "
据说里边机关重重，危机四伏，数十年来，入内者除张无忌外再无人生还。\n");
        set("no_task",1);
        set("exits", ([    
              "out" : __DIR__"neishi",

        ]));


        setup();

}


void init()
{
        add_action("do_push","push");
        add_action("do_improve","improve");
		add_action("do_lian",({"lian","practice"}));
}
int do_lian(string arg)
{
	object me=this_player();
	int skill, skill_basic,times,exp;
	int lv,*lv_limit=({250,500,800,1250,1800,2100});
	string skillname;
	if(me->is_busy()) return notify_fail("你现在正忙着呢。\n");
	if(me->is_fighting() ) return notify_fail("临阵磨枪？来不及啦。\n");
	if(me->query("lingjiu/last_xiulian_time"))
		return notify_fail("你现在正在恢复武功，没有精力研究武功。\n");
		
	if(!arg || (sscanf(arg, "%s %d", arg, times)< 2 ))
		return notify_fail("指令格式：practice|lian <技能> <次数>\n");
	if(times <1 || times>50) return notify_fail("练习次数应该在 1-50 次！\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");
	if (arg!="parry"||skillname!="qiankun-danuoyi")
	return 0;
	if( (int)me->query("learned_points")+3*times >= (int)me->query("potential") )
	{
		tell_object(me,"你的潜能已经发挥到极限了，没有办法再成长了。\n");
		return 1;
	}
	if (me->query("jing")<100)
	{
		tell_object(me,"你现在精血不足，没有办法继续提高乾坤大挪移。\n");
		return 1;
	}
	if (me->query("qi")<100)
	{
		tell_object(me,"你现在气血不足，没有办法继续提高乾坤大挪移。\n");
		return 1;
	}
	if (me->query("neili")<300)
	{
		tell_object(me,"你现在内力不足，没有办法继续提高乾坤大挪移。\n");
		return 1;
	}
	//return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);
	
	if( skill < 100 )
	{
		tell_object(me,"乾坤大挪移100级以内不能通过练习提高。\n");
		return 1;
	}
	if ((skill>1200) && (me->query("family/family_name")!="明教"))
	{
		tell_object(me,"你缺乏明教习练环境，无法将大挪移提高到高深境界了。\n");
		return 1;
	}
	if( skill_basic < 1 )
	{	
		tell_object(me,"你的基本招架太低，无法练习乾坤大挪移。\n");
		return 1;
	}

	if( skill_basic <= skill )
	{
		tell_object(me,"你需要提高基本招架，否则无法提高乾坤大挪移。\n");
		return 1;
	}
	lv=me->query("mingjiao/skill/danuoyi/level");
	if (lv<1)
	lv=1;
	if (skill>=lv_limit[lv-1])
	{
		tell_object(me,"你现在的乾坤大挪移处在第"+chinese_number(lv)+"层，最多只能练习至"+lv_limit[lv-1]+"级乾坤大挪移。\n");
		return 1;
	}
	exp=me->query("combat_exp");
	exp= random(me->query_int()*(exp/(skill*skill*skill))/2);
	if (pure_degree(me)>100)
	exp+=random(exp/2);//纯门派福利
	if (exp < 10)  exp=random(me->query_int()+1);
	me->improve_skill(skillname,exp*times);
	me->add("learned_points",2+random(2)*times);
	me->add_busy(1);
	me->add("jing",-10);
	me->add("qi",-10);
	me->add("neili",-5);
	message_vision(HIY"$N在静心钻研乾坤大挪移的奥秘。\n"NOR,me);
	return 1;  
}
int low_level(object me)
{
	if (pure_degree(me)>100)
	return 5;
	else
	return 4;
}
int fail_pinish(object me,int lv)
{
	int neili,*neili_lose=({50,100,400,800});
	me->set("mingjiao/skill/danuoyi/levelup_time",time());
	if (lv<low_level(me))
	{
		neili=neili_lose[lv-1]+random(neili_lose[lv-1]);
		me->add("max_neili",-neili);
		me->set("neili",0);
		tell_object(me,"你冲击乾坤大挪移第"+chinese_number(lv+1)+"层失败，损失了"+chinese_number(neili)+"点内力，将将控制住内息，不曾走火入魔。\n");
	}
	else
	{
		me->add("mingjiao/skill/danuoyi/level",-1);
		tell_object(me,"你冲击乾坤大挪移第"+chinese_number(lv+1)+"层失败，大挪移跌落至"+chinese_number(lv-1)+"层。\n");
	}
	me->save();
	return 1;
}
int calc_test(int times)
{
	int result=0;
	for (int i=0;i<times;i++)
	{
		result+=random(30)+random(30)+random(30);
	}
	return result;
}
int continue_improve(object me)
{
	string desc,default_desc=RED"$N边读边练乾坤大挪移，半边脸涨得血红，半边脸却发青，但双眼精光炯炯。\n"NOR,*descs=({"","","",HIR"$N脸上忽青忽红，脸上青时身子微颤，如堕寒冰，脸上红时额头汗如雨下。\n"NOR,HIR"$N只觉全身精神力气无不指挥如意，欲发即发，欲收即收，一切全凭心意所至，周身百骸，十分舒服。\n"NOR,HIR"$N自行揣摩乾坤大挪移的心法，努力冲击颠峰。\n"NOR});
	int n,lv=me->query("mingjiao/skill/danuoyi/level"),*lv_limit=({1300,6600,12800,34500,87600,216300}),*probability=({95,75,60,50,20,2}),index=0;
	string *gifts=({"dex","con","per"});
	if (me->query("jing")<=lv*30)
	{
		tell_object(me,"你现在精神不济，无法提升乾坤大挪移。\n");
		return 1;
	}
	if (me->is_busy())
	{
		tell_object(me,"你现在正忙着呢，无法提升乾坤大挪移。\n");
		return 1;
	}
	if (me->query("special_level/energy")>1)
	{
		tell_object(me,"你全神贯注，有如神助。\n");
		probability[0]=100;
		probability[1]+=20;
		probability[2]+=15;
		probability[3]+=10;
		probability[4]+=10;
		probability[5]*=2;
	}
	if (me->query("safari_skill/mj_dny")&&!me->query("chushi/done"))
	{
		tell_object(me,"大挪移心法时刻在你的脑海里面浮现。\n");
		probability[0]=100;
		probability[1]+=3;
		probability[2]+=10;
		probability[3]+=15;
		probability[4]+=10;
		probability[5]*=2;
	}
	desc=descs[lv-1];
	if (desc=="")
	desc=default_desc;
	message_vision(desc,me);
	me->add_busy(2+random(2));
	me->add("jing",-lv*30);
	me->add_temp("mingjiao/qkdny_gain",random(me->query("kar"))+random(me->query("int"))+random(me->query(gifts[random(sizeof(gifts))])));
	if (pure_degree(me)>100)
		index=1;//纯明教冲级时间减半
	n=random(1000)/10;
	if (me->query_temp("mingjiao/qkdny_gain")>lv_limit[lv-1]/(1+index))
	{
		if (wizardp(me))
			tell_object(me,"probability"+n+"\n");
		if (n<probability[lv-1])
		{
			me->add("mingjiao/skill/danuoyi/level",1);
			me->save();
			CHANNEL_D->do_channel(this_object(), "jh", HIW + me->query("name")+HIW+"成功地把乾坤大挪移的层次提升到"+chinese_number(me->query("mingjiao/skill/danuoyi/level"))+"级。", -1);
		}
		else
		{
			fail_pinish(me,lv);
		}
		me->delete_temp("mingjiao/qkdny_gain");
		me->delete_temp("mingjiao/qkdny_levelup");
	}
	/*else
	tell_object(me,"成功似乎就在眼前，但失败的风险也不小，如需继续请输入improve。\n");*/
	return 1;
}
int improve_dny(object me)
{
	int lv,skill_lv;
	int *lv_limit=({150,350,650,1050,1550,1800});
	if (!me->query("mingjiao/skill/danuoyi/level"))
	me->set("mingjiao/skill/danuoyi/level",1);
	lv=me->query("mingjiao/skill/danuoyi/level");
	skill_lv=me->query_skill("qiankun-danuoyi",1);
	if (!skill_lv)
	return 0;
	if (time()-me->query("mingjiao/skill/danuoyi/levelup_time")<levelup_cd[lv-1]*86400)
	{
		tell_object(me,"上次冲击乾坤大挪移更高层次受的内伤未愈，你要再等"+CHINESE_D->chinese_period(levelup_cd[lv-1]*86400+me->query("mingjiao/skill/danuoyi/levelup_time")-time())+"才能继续冲击更高级别。\n");
		return 1;
	}
	if (lv>=7)
	{
		tell_object(me,"你已经达到了乾坤大挪移的七层颠峰，无可再行提升。\n");
		return 1;
	}
	if (skill_lv<lv_limit[lv-1])
	{
		tell_object(me,"你现在的乾坤大挪移处在"+chinese_number(lv)+"层，你必须达到"+lv_limit[lv-1]+"级乾坤大挪移后，才有可能提升层次到"+chinese_number(lv+1)+"层。\n");
		return 1;
	}
	if (lv<low_level(me))
	tell_object(me,RED+"你现在的乾坤大挪移处在"+chinese_number(lv)+"层，你已经达到了提升层次的要求，如果提升失败，可能会损失最大内力，继续请输入improve。\n"+NOR);
	else//高层突破
	tell_object(me,WHT+"你现在的乾坤大挪移处在"+chinese_number(lv)+"层，你已经达到了提升层次的要求，如果提升失败，可能会跌落到第"+chinese_number(lv-1)+"层，继续请输入improve。\n"+NOR);
	me->set_temp("mingjiao/qkdny_levelup",1);
	return 1;
}
int do_improve(string arg)
{
	object me=this_player();
	mapping desc=(["force":"攻击加成","dodge":"攻击命中","damage":"伤害力"]);
	if (!me->query_skill("shenghuo-lingfa")&&!me->query_skill("qiankun-danuoyi"))
	return 0;
	if (!arg)
	{
		if (!me->query_temp("mingjiao/qkdny_levelup"))
		return notify_fail("你要提升圣火令法的哪方面？force，dodge，damage，danuoyi分别对应攻击加成，攻击命中，伤害力以及大挪移的层级提升。\n");
		else if (time()-me->query("mingjiao/skill/danuoyi/levelup_time")<levelup_cd[me->query("mingjiao/skill/danuoyi/level")-1]*86400)
		return notify_fail("上次冲击乾坤大挪移更高层次受的内伤未愈，你要再等"+CHINESE_D->chinese_period(levelup_cd[me->query("mingjiao/skill/danuoyi/level")-1]*86400+me->query("mingjiao/skill/danuoyi/levelup_time")-time())+"才能继续冲击更高级别。\n");
		else
		return continue_improve(me);
	}
	if (member_array(arg,({"force","dodge","damage","danuoyi"}))==-1)
	return notify_fail("你要提升圣火令法的哪方面？force，dodge，damage，danuoyi分别对应攻击加成，攻击命中和伤害力以及大挪移的层级提升。\n");
	if (arg=="danuoyi")
	return improve_dny(me);
	if (improve_chance(me)<1)
	return notify_fail("你的圣火令法提升机会全部用尽了。\n");
	me->add("mingjiao/skill/shenghuo_lingfa/improved_times",1);
	me->add("mingjiao/skill/shenghuo_lingfa/"+arg,1);
	message_vision("$N提升了圣火令法在"+desc[arg]+"方面的作用。\n",me);
	return 1;
}
int do_push(string arg)
{
	string *mkey=({
                "midao0","midao1","midao2","midao3","midao4","midao5","midao6","midao7",
                });
        mapping midao=([
                                mkey[0] : __DIR__"midao0",
                                mkey[1] : __DIR__"midao1",
                                mkey[2] : __DIR__"midao2",
                                mkey[3] : __DIR__"midao3",
                                mkey[4] : __DIR__"midao4",
                                mkey[5] : __DIR__"midao5",
                                mkey[6] : __DIR__"midao6",
                                mkey[7] : __DIR__"midao7",                      
                        ]);

	object me;

        me=this_player();

        me->delete_temp("xiu",0);
        me->delete_temp("sheng",0);
        me->delete_temp("shang",0);
        me->delete_temp("du",0);
        me->delete_temp("jing",0);
        me->delete_temp("si",0);
        me->delete_temp("jing1",0);
        me->delete_temp("kai",0);
	        
        if( !arg || arg=="" )
		return notify_fail("push <物件>\n");

        if(arg=="men" || arg=="door")
	{
                if(me->query("neili")>=300)
        	{
                	message_vision("$N运起内力朝石门推去,石门缓缓地开了。\n",me);
                	set("exits/enter", midao[mkey[random(8)]]);

	                remove_call_out("close");
        	        call_out("close", 5, this_object());

	                return 1;
		}

		return notify_fail("你的内力不够。\n");

	}
	return notify_fail("你要推什么？\n");
}

void close(object room)
{
        message("vision","石门移回原地。\n", room);
        room->delete("exits/enter");
}
