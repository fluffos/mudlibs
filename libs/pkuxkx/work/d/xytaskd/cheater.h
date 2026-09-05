#include <title.h>
#include "xytaskd.h"

void create()
{
	int bts=join_bts(0), hour=now_hour();
	
	if ( bts>=5 )
	  set_name(HIM"蒙古奸细"NOR, ({ "menggu jianxi", "jianxi" }));
	else
		set_name("蒙古奸细", ({ "menggu jianxi", "jianxi" }));
		
	set("age", 22);
	set("changed", 0);
	set("no_clean_up", 1);
  set("max_qi", 4000+random(3000));
  set("eff_qi",4000+random(3000));
  set("qi",4000+random(3000));
	set("max_jing", 800);
	set("menggu", 1);
	set("gender", "男性");
	set("long", "一个鬼鬼祟祟的蒙古奸细。\n");
	set("attitude", "aggressive");

	set("str", 24);
	set("dex", 16);
	set("shen_type", 1);

//当有5个以上BT参与保卫的时候蒙古兵难度变高	
	if ( bts>=5 )
	{
		set("combat_exp", (6000+random(1000))*10000);
		set_skill("unarmed", 600);
		set_skill("dodge", 600);
		set_skill("parry", 600);
		set_skill("blade", 600);
		set_skill("force", 600);
	  set_temp("apply/attack", 300);
	  set_temp("apply/defense", 680);
	  set_temp("apply/damage", 200);
	  set_temp("apply/armor", 680);
	}
	else
	{
	  set("combat_exp", 1000000+random(300000));
	  set_skill("unarmed", 40);
	  set_skill("dodge", 40);
	  set_skill("parry", 40);
	  set_skill("blade", 40);
	  set_skill("force", 40);
	  set_temp("apply/attack", 40);
	  set_temp("apply/defense", 340);
	  set_temp("apply/damage", 20);
	  set_temp("apply/armor", 340);
	}
	
	if(random(100)<5)
		set_skill("disguise", 200+random(301));
	else
	  set_skill("disguise", 100+random(151));

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
                "冲啊.......\n",
                "杀啊.......\n",
	}));
	set_face( FACE_ORIGIN, query("name"), query("id") );
  set_face( FACE_FACT, query("name"), query("id") ); 
  	//不能搬运，以免引起mgb_number的错误
	set("no_get",1);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/armor/tiejia")->wear();
	set("index",0);
//	remove_call_out("start_move");
//	call_out("start_move",1);
  remove_call_out("cheat");
  call_out("cheat",1);
  	remove_call_out("des");
	call_out("des",1800);

}

void init()
{
	add_action("do_kill","kill");
	add_action("do_yun","exert");
	return ;
}
int cheat()
{
	object *inv,obj,ar,weapon1,weapon2;
	mapping armor;
	string msg,title;
	int i;
	if(query("changed")) return 1;
	if (!environment(this_object())) return 1;
	inv=all_inventory(environment(this_object()));
	for(i=0;i<sizeof(inv);i++)
	{
		obj=inv[i];
		if(!obj->is_character()) continue;
		if(!living(obj)) continue;
		if(userp(obj))
		{
			//伪装
			armor=obj->query_temp("armor");
			ar=armor["cloth"];
			weapon1=obj->query_temp("weapon");
			weapon2=obj->query_temp("secondary_weapon");
			if(ar) msg="身穿"+ar->query("name")+"走了过来。\n";
			else msg="光着身子走了过来。\n";
			if(weapon1) msg="右手拿着"+weapon1->query("name")+"，"+msg;
			if(weapon2) msg="左手拿着"+weapon2->query("name")+"，"+msg;
			msg=obj->query("name")+msg;
			set("come_msg",msg);
//奸细伪装的识别难度取伪装技能等级
//首先取到玩家的title
      if ( obj->query("nickname") )
      	title=sprintf("「%s」", obj->query("nickname"));
      
      if ( obj->show_title() && !title )
      	title=obj->show_title();
      else if ( obj->show_title() )
      	title=sprintf("%s %s", obj->show_title(), title);
      else {
        if ( obj->query("title") && !title)
      	  title=obj->query("title");
        else if ( obj->query("title") )
      	  title=sprintf("%s %s", obj->query("title"), title);
      
        if ( obj->query("job_title") && !title)
      	  title=obj->query("job_title");
        else
      	  title=sprintf("%s %s", obj->query("job_title"), title);
      }
      
			set_face("xy", obj->query("name"), obj->query("id"), query_skill("disguise",1), 
  	             (["long":obj->query("long"),
  	             	 "age":obj->query("age"),
  	             	 "title":title]));

			set("changed",1);
			return 1;
		}
	}
	remove_call_out("cheat");
	call_out("cheat",1);
	return 1;
}

int start_move()
{
        remove_call_out("do_move");
        call_out("do_move", 1);
        return 1;
}

int do_move()
{
	object here;
	string leave_direction;
	string *pname;
	object room,me,obj,bing,*inv;
	int i,menggu_number;
	me=this_player();
	bing=this_object();
	if(spot[query("index")]=="HALT") 
	{
	    CHANNEL_D->do_channel(this_object(), "bd", HIM + "蒙古奸细混入帅府！" NOR, -1);
		return 1;
	}
	if(query("victory"))
	{
			destruct(this_object());
			return 1;
	}
	if(bing->is_fighting())
	{
		bing->remove_all_killer();
		bing->remove_all_enemy();
		remove_call_out("do_move");
                call_out("do_move", 2);
		return 1;
	}
	if(!living(bing))
	{
		remove_call_out("do_move");
		call_out("do_move", 5);
		return 1;
	}
	here=environment(this_object());
	if(here) pname=keys(here->query("exits"));
	if (sizeof(pname) > 0)
		leave_direction=pname[random(sizeof(pname))];
	if(!leave_direction)

		message_vision(query("name")+"向前离开。\n",bing);
	else if(leave_direction=="east")
		message_vision(query("name")+"往东离开。\n",bing);
	else if(leave_direction=="south")
		message_vision(query("name")+"往南离开。\n",bing);
	else if(leave_direction=="west")
		message_vision(query("name")+"往西离开。\n",bing);
	else if(leave_direction=="north")
		message_vision(query("name")+"往北离开。\n",bing);
	else 
		message_vision(query("name")+"往"+leave_direction+"离开。\n",bing);
	room=load_object(spot[query("index")]);

	environment()->add("mgb_number",-1);
	if(environment()->query("mgb_number") < 0)
	{
		environment()->set("mgb_number",0);
	}
    bing->move(room);
	//以防房间的标记有以前的残留，确保从0开始.因为所有的mgb一定会调用destruct，所以不存在残留>0的mgb_number的情况
	if(room->query("mgb_number") < 0)
	{
		room->set("mgb_number",0);
	}

	room->add("mgb_number",1);

	if(!query("changed")) message_vision("一个"+query("name")+"走了过来.\n",bing);
	else
	{
	if(query("come_msg")) message_vision(query("come_msg"),bing);
	else message_vision(query("name")+"身穿铁甲手持钢刀走了过来.\n",bing);
	}
	if(room->query("shuaifu"))
	{
		room->add("destroy",1);
	    CHANNEL_D->do_channel(this_object(), "bd", HIM + "蒙古奸细混入帅府！" NOR, -1);
		menggu_number = room->query("mgb_number");
		menggu_number += room->query("destroy");

		if(menggu_number>25)  //失败判据奸细杀郭靖要求低些
		{
			object xytaskd;
			xytaskd=load_object("/adm/daemons/xytaskd.lpc");
			xytaskd->set("begin",0);
			xytaskd->set("victory",0);
			//任务失败
			room->set("shuaifu",0);
			CHANNEL_D->do_channel(this_object(), "bd", HIR + "郭靖夫妇被蒙古奸细杀死，帅府被占，襄阳沦陷！" NOR, -1);
		}
		return 1;
	}
	add("index",1);
	if(room->query("gate"))
	{
		room->add("destroy",1);
		menggu_number = room->query("mgb_number");
		menggu_number += room->query("destroy");

		if(menggu_number<GATE_BREAK)
		{
		}
		else
		{
			room->set("gate",0);
			message_vision(HIR"蒙古兵破门而入！\n"NOR,this_object());
			// 沦陷
			CHANNEL_D->do_channel(this_object(), "bd", HIM + room->query("short") + "被奸细从内部将城门打开！" NOR, -1);
			CHANNEL_D->do_channel(this_object(), "bd", HIR + room->query("short") + "沦陷！" NOR, -1);
			(load_object("/adm/daemons/xytaskd.lpc"))->add("occupied",1);
			(load_object("/adm/daemons/xytaskd.lpc"))->set(GATE,1);
		}
	}
	if(!room->query("gate")||query("changed"))
	{
		remove_call_out("do_move");
		call_out("do_move", random(20));
	}
	else
	{
		remove_call_out("do_judge");
		call_out("do_judge",1,room);
	}
	return 1;
}

int do_judge(object room)
{
	int menggu_number;
	object obj,*inv;
	int i;
	if(!room->query("gate")||query("changed"))
	{
		remove_call_out("do_move");
		call_out("do_move", random(10));
		return 1;
	}
	menggu_number = room->query("mgb_number");
	menggu_number += room->query("destroy");
	if(menggu_number<GATE_BREAK)
	{
		remove_call_out("do_judge");
		call_out("do_judge",1,room);
		return 1;
	}
	else
	{
		room->set("gate",0);
		remove_call_out("do_move");
		call_out("do_move", 1);
		message_vision(HIR"蒙古兵破门而入！\n"NOR,this_object());
		// 沦陷
		CHANNEL_D->do_channel(this_object(), "bd", HIM + room->query("short") + "被奸细从内部将城门打开！" NOR, -1);
		CHANNEL_D->do_channel(this_object(), "bd", HIR + room->query("short") + "沦陷！" NOR, -1);
		(load_object("/adm/daemons/xytaskd.lpc"))->add("occupied",1);
		(load_object("/adm/daemons/xytaskd.lpc"))->set(GATE,1);
		return 1;
	}
}

int do_kill(string arg)
{
	if(sizeof(this_player()->query_enemy())>10)
	{
		tell_object(this_player(),HIW"你对付的人够多了！\n"NOR);
		return 1;
	}
	return 0;
}

int do_yun()
{
	tell_object(this_player(),"你想运用内功御敌，怎奈蒙古兵实在太多，你竟然无法使出!!\n");
	return 1;
}

int die()
{
	object me,xytaskd;
	if(query("victory"))
	{
		message_vision(this_object()->name()+"死了,你仔细一看发现他竟然是蒙古奸细假扮的！\n",this_object());
		all_inventory(environment())->remove_killer(this_object());
		destruct(this_object());
		return 1;
	}
	me=this_object()->get_damage_origin_object();
	//if(!me) me=offensive_target(this_object());
	if(!me) me=this_player();
	xytaskd=load_object("/adm/daemons/xytaskd.lpc");
/*	if(query("taskid")!=me->query_temp("xytaskd/taskid"))
	{
 		me->delete_temp("xytaskd");
	}*/
	me->add_temp("xytaskd/jianxi",1);
	me->set_temp("xytaskd/taskid",xytaskd->query("taskid"));
	//::die();
	message_vision(this_object()->name()+"死了,你仔细一看发现他竟然是蒙古奸细假扮的！\n",this_object());
	all_inventory(environment())->remove_killer(this_object());
	CHANNEL_D->do_channel(this_object(), "bd", HIW + me->query("name")+HIM"锐眼识穿蒙古奸细！" NOR, -1);
	destruct(this_object());
	return 1;
}

/*
int unconcious()
{
die();
return 1;
}
*/

int des()
{
	destruct(this_object());
	return 1;
}

void pre_destruct()
{
    if(objectp(environment()))
	{
		environment()->add("mgb_number",-1);
	}
	return ::pre_destruct();
}