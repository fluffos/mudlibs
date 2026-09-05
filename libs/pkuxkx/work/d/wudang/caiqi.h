//caiqi.h
//采气头文件
#include <ansi.h>
void init()
{
  add_action("do_climb","climb");
  add_action("do_caiqi","caiqi");
}

int do_caiqi()
{
	object me,room;
  mapping fam;
  string env=NATURE_D->outdoor_room_event(),shichen;
  int level=0;
  
  me=this_player();
  room=this_object();
  if(file_name(room)==__DIR__"feng")
  	level=0;
  else if(file_name(room)==__DIR__"stone")
  	level=1;
  else if(file_name(room)==__DIR__"ding")
  	level=2;

  if(!(fam=me->query("family")) || fam["family_name"]!="武当派")
  	return notify_fail("你又不是牛鼻子老道，在这里凑什么热闹！\n");
  else if(me->query_skill("taoism",1)<1+150*level)
  	return notify_fail("你至少要先学一点道学基础知识吧？\n");
  else if(me->query_skill("taiji-shengong",1)<1+150*level)
  	return notify_fail("你一点内功修炼要诀都不懂，怎么进行采气？\n");
  else if(time()-me->query("caiqi/time")<=360&&me->query("caiqi/shichen")==env)
  	return notify_fail("每天子午各采气一次就够了！多了对身体不利！\n");
  else if(me->is_busy()||me->is_fighting())
  	return notify_fail("你现在正忙着呢。\n");
  else if(env!="event_midnight"&&env!="event_noon")
  	return notify_fail("仅子午两个时辰能够进行采气！\n");
  
  if(env=="event_midnight")
  	shichen="子时";
  else
  	shichen="午时";

  tell_room(room, HIG+RANK_D->query_respect(this_player()) + 
    "面向东南，五心朝天盘膝而坐，脚分阴阳，手掐子午，二目垂帘，眼观鼻，鼻观心，意守丹田，开始进行"+ shichen + "采气！\n"+NOR);
  me->start_busy(62);
//  remove_call_out("in_caiqi");
  call_out("in_caiqi",10,me,level,env);
  return 1;
}

//采气会给适当的taoism和太极神功，并且如果开始门派是武当的弟子会极低概率给先天跟骨奖励。
//判师和出师的武当弟子就没有这个福利了。
void in_caiqi(object me,int level,string env)
{
	int tj_lvl;
	
	if(!level&&me->query("combat_exp")>10000000) {
		  me->start_busy(1);
			tell_room(this_object(), HIM+RANK_D->query_respect(this_player()) + 
		"发现此处稍有嘈杂，对你的心境造成了影响，也许应该再往上走走了！\n"+NOR);
		  return;
		}
	if(me->query_busy()<10) {
		if(me->query_busy())
			me->start_busy(1);
		tell_room(this_object(), HIM+RANK_D->query_respect(this_player()) + 
		"大脑一片空明，感觉一股热气在任督二脉盘旋，发现自己对道家炼气要诀又有了进一步的理解！\n"+NOR);
		me->add("caiqi/times", 1);
		me->set("caiqi/time", time());
		me->set("caiqi/shichen", env);
		if(!level&&me->query_skill("taoism",1)<=150)
			me->improve_skill("taoism",500+me->query_skill("taoism",1));
		if(!level&&(tj_lvl=me->query_skill("taiji-shengong",1))<=150)
			if ( me->query("combat_exp")>=5000 || tj_lvl<=30 )
			  me->improve_skill("taiji-shengong",500+tj_lvl);
		if(!level) {
			me->add("max_neili",random(5)+1);
			me->add("max_jingli",random(5)+1);
		}
/*		if(!level&&!me->query("caiqi/con_feng")&&
			 me->query("caiqi/times")>=100&&
			 random(10000)%600<=1&&
			 !me->query("betrayer")&&
			 !me->query("reborn/chushi")) {
			tell_object(me, HIY+"你突然感觉一股热气在骨髓经络之间来回摩擦，浑身酥酥麻麻的，似乎你的跟骨又提高了一点。\n"+NOR);
			message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在天柱峰下采气多年终成正果，提高先天跟骨!\n"NOR,users());
		  me->set("caiqi/con_feng",1);
		  me->add("con",1);
		  me->set("caiqi/times",1);
		}*/
		if(level==1&&me->query_skill("taoism",1)<=300)
			me->improve_skill("taoism",2000+random(5*me->query_skill("taoism",1)));
		if(level==1&&me->query_skill("taiji-shengong",1)<=300)
			me->improve_skill("taiji-shengong",1500+me->query_skill("taiji-shengong",1));
		if(level==1&&
			 !me->query_temp("caiqi/con_stone")&&
			 random(10000)%1000<=10&&
			 !me->query("betrayer")&&
			 !me->query("reborn/chushi")&&
			  me->query("combat_exp")/10000>=1000) {
		  me->add_temp("apply/constitution",3+random(6));
		  me->receive_damage("qi",-1000);
		  me->set_temp("caiqi/con_stone",1);
		  tell_object(me, HIY+"你突然感觉好像一道闪电劈在身上，整个身子骨都酥酥麻麻的，经脉突然通了一大半。\n"+NOR);
		}
/*		if(level==1&&!me->query("caiqi/con_stone")&&
			 me->query("caiqi/times")>=300&&
			 random(10000)%600<=1&&
			 !me->query("betrayer")&&
			 !me->query("reborn/chushi")&&
			 me->query("combat_exp")/10000>=10000) {
			tell_object(me, HIY+"你突然感觉一股热气在骨髓经络之间来回摩擦，浑身酥酥麻麻的，似乎你的跟骨又提高了一点。\n"+NOR);
			message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在天柱峰上巨石采气多年终成正果，提高先天跟骨!\n"NOR,users());
		  me->set("caiqi/con_stone",1);
		  me->add("con",1);
		  me->set("caiqi/times",1);
		}*/
		if(level>1) {
			me->improve_skill("taoism",4000+random(15*me->query_skill("taoism",1)));
			me->improve_skill("taiji-shengong",2000+me->query_skill("taiji-shengong",1));
		}
		if(level>1&&!me->query("caiqi/con_ding")&&
			 me->query("caiqi/times")>=300&&
			 !(random(10000)%1000)&&
			 !me->query("betrayer")&&
			 !me->query("reborn/chushi")&&
			 me->query("combat_exp")/10000<=3000) {
			tell_object(me, HIY+"你突然感觉一股热气在骨髓经络之间来回摩擦，浑身酥酥麻麻的，似乎你的跟骨又提高了一点。\n"+NOR);
			message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在天柱峰顶采气多年终成正果，提高先天跟骨!\n"NOR,users());
		  me->set("caiqi/con_ding",1);
		  me->add("con",1);
		  me->set("caiqi/times",1);
		}
	}
	else {
		tell_room(this_object(), HIC+RANK_D->query_respect(this_player()) + 
    "正在慢慢采集阴阳交替先天混沌之气，一股真气沿着大周天慢慢归集丹田！\n"+NOR);
//  	remove_call_out("in_caiqi");
  	call_out("in_caiqi",10,me,level,env);
  }
}