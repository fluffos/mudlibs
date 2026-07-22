inherit ROOM;
#include <ansi.h>
void check_lianxi(object who);
void finish(object who);
string* jieqi = ({
  	"立春","雨水","惊蛰","春分","清明","谷雨",
  	"立夏","小满","芒种","夏至","小暑","大暑",
  	"立秋","处暑","白露","秋分","寒露","霜降",
  	"立冬","小雪","大雪","冬至","小寒","大寒",
});
string *str=({
	        "你身形微展，飘开三丈，左手食指并右手手掌同点。\n",
	        "你脚步虚晃，指气带起一股寒风。\n",
	        "你轻歌曼行，飘然而起，手指轻巧凌空而下。\n",
	        "你左手拇指一连三指，指掌相叠，带着一丝太阳光芒。\n"
	        "你左手五指乱弹，右掌护身，一束束锐利无俦的指气飞出。\n",
	        "你双手轻和，无名指紧并，一指，两掌，无数指气掌风狂飙而出。\n"
	     });
void create()
{
        set("short", "花海中");
        set("long", @LONG
放眼望去，但见天地间仿佛已被鲜花充满，但却是无人认得出的花
朵，只觉得这些花无比的鲜艳，无比的美丽。风中突然传来一阵阵甜蜜
的花香。这花香不是牡丹，不是玫瑰，也不是梅，不是菊......这花香
甜蜜得竟非世间所有。
LONG
        );
  	set("exits", ([ /* sizeof() == 1 */
  	"out" : __DIR__"huahai2",
	]));
  	set("no_fight", 1);
  	set("no_magic", 1);
	set("no_huicheng",1);
	setup();
}

void init ()
{
  	add_action("do_chakan", "chakan");
  	add_action("do_lian", "练掌");
  	add_action("do_lian", "练习");
  	add_action("do_lian", "lianxi");
  	add_action("do_lian", "practice");
}

void change_knowing(object me)
{
	int k;
	if( !me || !userp(me) || !present(me,this_object())
	 || !living(me) )
	 	return;
	if( me->is_knowing("bhg_siji")<1 
	 && me->is_knowing("bhg_siji_spr")<1  
	 && me->is_knowing("bhg_siji_sum")<1
	 && me->is_knowing("bhg_siji_aut")<1
	 && me->is_knowing("bhg_siji_win")<1 )
	 	return;	 	

	k = me->is_knowing("bhg_siji");
	if( k<=6 )
	{
		me->delete_knowing("bhg_siji");
		me->set_knowing("bhg_siji_spr",k);
	}
	else if( k<=12 )
	{
		k = 12-k;
		k = 6-k;
		me->delete_knowing("bhg_siji");
		me->set_knowing("bhg_siji_spr",6);
		me->set_knowing("bhg_siji_sum",k);
	}
	else if( k<=18 )
	{
		k = 18-k;
		k = 6-k;
		me->delete_knowing("bhg_siji");
		me->set_knowing("bhg_siji_spr",6);
		me->set_knowing("bhg_siji_sum",6);
		me->set_knowing("bhg_siji_aut",k);
	}
	else
	{
		k = 24-k;
		k = 6-k;
		me->delete_knowing("bhg_siji");
		me->set_knowing("bhg_siji_spr",6);
		me->set_knowing("bhg_siji_sum",6);
		me->set_knowing("bhg_siji_aut",6);
		me->set_knowing("bhg_siji_win",k);
	}
	me->save();
	tell_object(me,HIR"【系统】您的四季领悟已自动更新成功。\n"NOR);
}

int do_chakan (string arg)
{
  	object who=this_player();
  	int i,k;
  	string *zs;
	
	if(!userp(who)) return 0;
  	
  	if(who->query_temp("lianxi"))
		return err_msg("你正忙着练习。\n"); 
  	if(who->is_busy())
  		return err_msg("你正忙着呢。\n"); 
  		
  	if( who->is_knowing("bhg_siji")>0 )
  		change_knowing(who);	

 	if( who->is_knowing("bhg_siji_spr")<1  
	 && who->is_knowing("bhg_siji_sum")<1
	 && who->is_knowing("bhg_siji_aut")<1
	 && who->is_knowing("bhg_siji_win")<1 )  	
  		return err_msg(HIW"你尚未领悟到四季百花掌的任何一式特殊招式。\n"NOR);
  		
  	arg = "";
  	arg+= HIG"春"NOR"六式：";
  	if( who->is_knowing("bhg_siji_spr")>0 )
  	{
  		i = who->is_knowing("bhg_siji_spr");
  		if( i>6 ) i = 6;
  		zs = ({"立春","雨水","惊蛰","春分","清明","谷雨",});
  		for(k=0;k<i;k++)
 			arg+= HIG+zs[k]+NOR" "; 
	  	if( i>=6 )
  			arg+= HIR"<已领悟完>"NOR;
  	}	
  	else	arg+= NOR WHT"尚未领悟。"NOR;
  	arg+= "\n";
  	

  	arg+= HIC"夏"NOR"六式：";
  	if( who->is_knowing("bhg_siji_sum")>0 )
  	{
  		i = who->is_knowing("bhg_siji_sum");
  		if( i>6 ) i = 6;
  		zs = ({"立夏","小满","芒种","夏至","小暑","大暑",});
  		for(k=0;k<i;k++)
 			arg+= HIC+zs[k]+NOR" "; 
	  	if( i>=6 )
  			arg+= HIR"<已领悟完>"NOR;
  	}	
  	else	arg+= NOR WHT"尚未领悟。"NOR;
  	arg+= "\n";

  	arg+= HIY"秋"NOR"六式：";
  	if( who->is_knowing("bhg_siji_aut")>0 )
  	{
  		i = who->is_knowing("bhg_siji_aut");
  		if( i>6 ) i = 6;
  		zs = ({"立秋","处暑","白露","秋分","寒露","霜降",});
  		for(k=0;k<i;k++)
 			arg+= HIY+zs[k]+NOR" "; 
	  	if( i>=6 )
  			arg+= HIR"<已领悟完>"NOR;
  	}	
  	else	arg+= NOR WHT"尚未领悟。"NOR;
  	arg+= "\n";

  	arg+= HIW"冬"NOR"六式：";
  	if( who->is_knowing("bhg_siji_win")>0 )
  	{
  		i = who->is_knowing("bhg_siji_win");
  		if( i>6 ) i = 6;
  		zs = ({"立冬","小雪","大雪","冬至","小寒","大寒"});
  		for(k=0;k<i;k++)
 			arg+= HIW+zs[k]+NOR" ";
	  	if( i>=6 )
  			arg+= HIR"<已领悟完>"NOR;
  	}	
  	else	arg+= NOR WHT"尚未领悟。"NOR;
  	arg+= "\n";
  	write(arg);
  	return 1;
}

int do_lian (string arg)
{
	int count,skill1,skill2,lianxi_time,total;
  	object who=this_player();
	string data,*zs;
	
	if(!userp(who)) 
		return 0;
  	if(who->query_temp("lianxi"))
		return err_msg("你正忙着练习。\n"); 
  	if(who->is_busy())
		return err_msg("你正忙着呢。\n"); 
	if( who->query("family/family_name")!="百花谷" )
		return 0;
	if( who->query("kee")<50 )
		return err_msg("你现在太累了。\n");
  	skill1 = (int)who->query_skill("siji-zhang",1);
  	skill2 = (int)who->query_skill("rainbow-zhi",1);
	if(skill1 < 200)
		return err_msg("以你现在的修为来练也是白搭。\n"); 
	if((skill1-skill2) > 20)
		return err_msg("你的柔虹指法修为不足，再练也没用。\n"); 
	skill2 = (int)who->query_skill("brightjade-force",1);
	if((skill1-skill2) > 20)
		return err_msg("你的明玉神功火候不够，再练也没用。\n"); 
		
	switch(NATURE_D->query_jijie())
	{
		case "春" : data = "bhg_siji_spr";zs = ({"立春","雨水","惊蛰","春分","清明","谷雨",});break;
		case "夏" : data = "bhg_siji_sum";zs = ({"立夏","小满","芒种","夏至","小暑","大暑",});break;
		case "秋" : data = "bhg_siji_aut";zs = ({"立秋","处暑","白露","秋分","寒露","霜降",});break;
		case "冬" : data = "bhg_siji_win";zs = ({"立冬","小雪","大雪","冬至","小寒","大寒",});break;
		default	: return err_msg("有问题，找兔子，这个点居然不知道是啥季节！！\n");	
	}
	
	total = who->is_knowing("bhg_siji_spr")+who->is_knowing("bhg_siji_sum")+who->is_knowing("bhg_siji_aut")+who->is_knowing("bhg_siji_win");
	count = who->is_knowing(data);
	if( skill1%20!=0 || total>((skill1-200)/20+1) )
		return err_msg("你目前的修为已经很难让你再领悟许多。\n"); 
	if( count>=6 )
		return err_msg(NATURE_D->query_jijie()+"季六式你已经学完了。\n");	
	
	who->set_temp("lianxi",zs);
	who->set_temp("lianxi_data",data);	
	message_vision(HIC"$N飞身而起，双掌急摆，幻化为四掌、八掌、十掌、百掌，开始在花丛中专心研习四季百花掌。\n"NOR,who);
	who->start_busy(5);
	who->receive_damage("kee",50);
	lianxi_time = 60*count/6+random(60)+time();
	if( wizardp(who) )
		lianxi_time = 1;
        who->set_temp("lianxi_time",lianxi_time);
        check_lianxi(who);
	return 1;
	
}

void check_lianxi(object who)
{       
	int lianxi_time;
	if( !who )
		return;
	if( !living(who) || !present(who,this_object()) )
	{
		who->delete_temp("lianxi");
        	who->delete_temp("lianxi_time");
        	who->delete_temp("lianxi_data");
		return;
	}
	lianxi_time = who->query_temp("lianxi_time");
	if ( time()-lianxi_time>0) 
		finish(who);
	else 
	{
		if ( !random(4))
              		tell_object(who,str[random(sizeof(str))]);
		call_out("check_lianxi",1+random(3),who);
	}
}

void finish(object who)
{
	string data,*zs;
  	int i;
	if( !who )
		return;
	if( !living(who) || !present(who,this_object()) )
	{
		who->delete_temp("lianxi");
        	who->delete_temp("lianxi_time");
        	who->delete_temp("lianxi_data");
		return;
	}		
	zs = who->query_temp("lianxi");
	data = who->query_temp("lianxi_data");
	tell_object(who,HIC"\n你飞身而起，化掌为指、又化指为掌，眼中神光暴射！\n"NOR);
	who->start_busy(2);
        who->delete_temp("lianxi");
        who->delete_temp("lianxi_time");
        who->delete_temp("lianxi_data");
     	if( !zs || !arrayp(zs) || random(who->query("con"))<20 || random(who->query("kar"))<20 )
	{
        	tell_object(who,HIC"然而你的心中陡然升起一种惆怅的感觉！\n"NOR);
        	return;
	}
     	else
     	{
     		who->set_knowing(data,1);
		i = (int)who->is_knowing(data);  
		if( i>6 ) i = 6;   		
     		who->save();	
        	tell_object(who,HIR"\n\n\n恍惚中，你只觉得心灵和指掌已合二为一！\n"NOR);
        	tell_object(who,HIR"恭喜你，你领悟了四季百花掌的一式特殊招式"HIY+zs[i-1]+HIR"！\n"NOR);
        	return;
	}	
}

int valid_leave(object who, string dir)
{
        if (who->query_temp("lianxi"))
        	return notify_fail("你正在修习你的掌法，没空离开！\n");
        else 	return ::valid_leave(who, dir);
}

	 	