// poem.c
#include <ansi.h>
#include <localtime.h>
inherit ITEM;

void create()
{
        set_name("【蚀月咒】参悟心得", ({"shiyue book","book","xinde",}));
        set_weight(100);
       	set("unit", "本");
	set("long","此乃月宫前辈们参悟「蚀月咒」的心得秘籍。\n");
       	set("value", 0);
       	set("no_give","给别人了，你如何交代？\n");
       	set("no_drop","这样的话，你如何交代？\n");
       	set("no_sell","这样的话，你如何交代？\n");
       	set("channel_id","嫦娥(Chang e)");
       	set("num",1);
	setup();
}

void init()
{
	add_action("do_look", "look");
	add_action("do_canwu", "canwu");
	add_action("do_canwu", "du");
	add_action("do_canwu", "read");
	add_action("do_canwu", "study");
}

varargs string query_time(int data)
{
	mixed *local;
	if( !data || data<=0 )
		data = ((time()-900000000)*60);
	local = localtime(data);
	return sprintf("%s",chinese_number(local[LT_HOUR]%2 * 2 + local[LT_MIN]/30 + 1));
}

void init_time()
{
	string str,*strs;
	if( query("time") )
		return;
	strs = ({ "子","丑","戌","亥" });
	str = strs[random(sizeof(strs))];
	set("time",str);			
}

int do_look(string arg)
{
	string shi;
	object me = this_player();
	if( !arg || !id(arg) || !present(this_object(),me) )
		return 0;
	if( query("owner_id")!=me->query("id") )
		return 0;
	if( !query("time") )
		init_time();
	shi = query("time");	
	arg = this_object()->long();
	arg+= "\n扉页上刻着几个古朴篆书：";
	if( random(me->query_skill("literate",1)/10)<10 )
		arg+= "可惜你看不懂写的是什么。\n";
	else	arg+= "此诀于"+shi+"时在月夜之下参悟(cangwu)，方可有所心得。\n";
	write(arg);
	return 1;
}

void shiyue(object me,object env)
{
	int succ;
	if( !me || me->is_knowing("moon_shiyue") )
	{
		remove_call_out("shiyue");
		destruct(this_object());
		return;
	}
	if( !living(me)
	 || !env || !present(me,env) )
	{
		remove_call_out("shiyue");
		CHANNEL_D->do_channel(this_object(),"chat","本门弟子"+me->name()+HIC"参悟「"HIR"蚀月咒"HIC"」奥妙，奈何天资拙笨，唉。"NOR);
		me->set("family/last_shiyue_fail",time());
		me->save(1);
		me->start_busy(1);
		tell_object(me,HIY"【师门】你领悟「"HIR"蚀月咒"HIY"」失败！"NOR"\n");
		destruct(this_object());
		return;
	}
	if( random(query("num"))>10 )
	{
		remove_call_out("shiyue");
		succ = 20+random(15)+random(5);
		if( succ<=random(me->query_kar()) )
		{
			tell_object(HIC"\n你如醍醐灌顶豁然开朗，不由兴奋的满脸通红，娇艳无比！\n"NOR);
			message("vision",HIC"\n"+me->name()+HIC"好似猛地领悟到了什么，一时间兴奋的满脸通红，好不可人！\n"NOR,env,({me}));
			CHANNEL_D->do_channel(this_object(),"chat","本门弟子"+me->name()+HIC"成功参悟了「"HIR"蚀月咒"HIC"」奥妙，叫人好不欢喜。"NOR);
			me->set_knowing("moon_shiyue",1);
			me->save(1);
			me->start_busy(1);
			tell_object(me,HIY"【师门】你领悟「"HIR"蚀月咒"HIY"」成功！"NOR"\n");
			destruct(this_object());
			return;
		}
		else
		{
			tell_object(HIC"\n你领悟了半天，结果只觉得满脑子浆糊，不由失望的站起身来。\n"NOR);
			message("vision","\n"+me->name()+"失望的站了起来，掸了掸屁股上的灰尘。\n"NOR,env,({me}));
			CHANNEL_D->do_channel(this_object(),"chat","本门弟子"+me->name()+HIC"参悟「"HIR"蚀月咒"HIC"」奥妙，奈何天资拙笨，唉。"NOR);
			me->set("family/last_shiyue_fail",time());
			me->save(1);
			me->start_busy(1);
			tell_object(me,HIY"【师门】你领悟「"HIR"蚀月咒"HIY"」失败！"NOR"\n");
			destruct(this_object());
			return;
			
		}
	}
	else
	{
		remove_call_out("shiyue");
		add("num",1+random(3));
		message_vision("\n$N沐浴在皎洁的月光中，祥宁之态，娇美不可方物。\n\n",me);
		tell_object(me,"你静静感受着月圆月缺的痛苦。\n");
		me->delete_temp("last_damage_from");
		me->receive_wound("kee",200+random(200));
		me->receive_wound("sen",200+random(200));
		me->set_temp("death_msg","感伤月圆月缺而亡。");
		me->start_busy(10);
		call_out("shiyue",2+random(5),me,env);
	}
	
}

int do_canwu(string arg)			
{
	int t;		
	string year,mon,day,shi,ke;
	object env,me = this_player();
	if( !arg || !id(arg) || !present(this_object(),me) )
		return 0;
	if( query("owner_id")!=me->query("id") 
	 || me->query("family/family_name")!="月宫" )
		return 0;
	if( !query("time") )
		return 0;
	env = environment(me);
	if( !wizardp(me) && !me->query("env/test") )
	{				
		t = NATURE_D->query_current_day_phase();
		if( t<6 )
			return err_msg("大白天的哪儿有月光？！\n");
		if( !env || !env->query("outdoors") )
			return err_msg("这里没有月光。\n");
		if( env->query("no_fight") || env->query("no_magic") )
			return err_msg("这里是安全区。\n");
		arg = NATURE_D->game_time();
		if( sscanf(arg,"%s年%s月%s日%s时%s刻",year,mon,day,shi,ke)!=5 )
			return 0;
		if( shi!=query("time") )
			return err_msg("现在不是"+query("time")+"时。\n");
	}
	if( me->is_busy() )
		return err_msg("你现在正忙着。\n");
	me->start_busy(10);
	message_vision(HIC"\n$N"HIC"盘膝坐下，片片月光落下，整个人沐浴在月光之中，背后隐现巨大的月轮与头顶的月亮遥相呼应。\n"NOR,me);
	remove_call_out("shiyue");
	call_out("shiyue",3+random(4),me,env);
	return 1;
}					