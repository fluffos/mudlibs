#include "xytaskd.h"

void create()
{
	int bts=join_bts(0), hour=now_hour();
	
  set_name(HIR"蒙古骑兵"NOR, ({ "menggu qibing", "qibing" }));
	set("age", 22);
  set("no_clean_up", 1);
  set("max_qi", 4000+random(2000));
  set("eff_qi",4000+random(2000));
  set("qi",4000+random(2000));
  set("max_jing", 800);
  set("menggu", 1);
	set("gender", "男性");
  set("long", "一个身穿铁甲骑着战马的蒙古兵。\n");
  set("attitude", "aggressive");

	set("str", 24);
	set("dex", 16);
	set("shen_type", 1);
	
	if ( bts>=5 )
	{
		set("combat_exp", (7000+random(1000))*10000);
		set_skill("unarmed", 600);
		set_skill("dodge", 800);
		set_skill("parry", 800);
		set_skill("blade", 700);
		set_skill("force", 700);
	  set_temp("apply/attack", 400);
	  set_temp("apply/defense", 680);
	  set_temp("apply/damage", 250);
	  set_temp("apply/armor", 680);
	}
	else
	{
    set("combat_exp", 200000+random(300000));
    set_skill("unarmed", 40);
    set_skill("dodge", 240);
    set_skill("parry", 240);
    set_skill("blade", 100);
    set_skill("force", 100);
	  set_temp("apply/attack", 160);
	  set_temp("apply/defense", 340);
	  set_temp("apply/damage", 160);
	  set_temp("apply/armor", 340);
	}
	
  set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
                "冲啊.......\n",
                "杀啊.......\n",
	}));
	setup();
  carry_object("/clone/weapon/gangdao")->wield();
  remove_call_out("start_move");
  call_out("start_move",1);
  carry_object("/clone/armor/tiejia")->wear();
  set("index",0);
}

void init()
{
 add_action("do_yun","yun");
 add_action("do_kill","kill");
 add_action("do_yun","exert");
remove_call_out("des");
call_out("des",1800);
return ;
}
int start_move()
{
remove_call_out("do_move");
call_out("do_move", 1);
return 1;
}
int do_move()
{
object room,me,obj,bing,*inv;
int i,menggu_number;
me=this_player();
bing=this_object();
if(query("victory"))
{
        set("chat_chance", random(300));
        set("chat_msg", ({
       "这些汉狗，简直不堪一击！.\n",
       "大汗说过，襄阳城破之日起，屠城三日！\n",
       "哈哈，哈哈......\n",
       "我们蒙古族个个都是好汉，骁勇善战....\n",
       "哼，想那郭靖本是我们的金刀驸马，现在落的这样下场真是自找的!@#%$@#!@\n",
       "只是可惜我们的华筝公主，却是终生未嫁......\n"
        }) );
		destruct(this_object());
return 1;
}
if(spot[query("index")]=="HALT")
{
	if (query("victory"))
		destruct(this_object());
	remove_call_out("do_move");
	call_out("do_move", 5);
	return 1;
}
if(bing->is_fighting()&&random(10)>2)
{
	if (random(2) == 0)
	{
		bing->remove_all_killer();
		bing->remove_all_enemy();
	}
remove_call_out("do_move");
call_out("do_move", 5);
return 1;
}
if(!living(bing))
{
remove_call_out("do_move");
call_out("do_move", 5);
return 1;
}
if (!environment(bing)) return 1;
if (environment(bing)->query("xytaskd/gongshi"))
{
	message("vision",HIG+ query("name") + "被工事阻挡，进攻的速度缓了一缓。\n"+NOR,environment(bing));
	environment(bing)->add("xytaskd/gongshi",-1);
	if (environment(bing)->query("xytaskd/gongshi") == 0)
		message("vision",HIR"修筑的工事在" + query("name") + "的再三冲击下『轰隆』一声垮掉了！\n"NOR,environment(bing));
	remove_call_out("do_move");
	call_out("do_move", 5);
	return 1;	
}
message("vision",HIR"杀呀，冲啊....."+query("name")+HIR"往前冲去！\n"NOR,environment(bing));
room=load_object(spot[query("index")]);
bing->move(room);
message("vision",HIR"杀呀，冲啊.....一个"+query("name")+HIR"冲了过来！\n"NOR,environment(bing));
if(room->query("shuaifu"))
{
inv=all_inventory(room);
for(i=0;i<sizeof(inv);i++)
{
obj=inv[i];
if(!obj->is_character()) continue;
if(obj->query("menggu"))
{
menggu_number++;
continue;
}
if(!living(obj)) continue;
if(userp(obj))
{
if(sizeof(obj->query_enemy())>=5) continue;
bing->kill_ob(obj);
obj->kill_ob(bing);
continue;
}
if(obj->query("id")!="guo jing"&&obj->query("id")!="huang rong")
{
message_vision(bing->query("name")+"手起刀落,"+obj->query("name")+"就倒在了血泊之中.....\n",bing);
obj->receive_damage("qi", 0, bing);
obj->die();
continue;
}
bing->kill_ob(obj);
obj->kill_ob(bing);
}
if(menggu_number>40)  //失败判据
{
object xytaskd;
xytaskd=load_object("/adm/daemons/xytaskd.lpc");
xytaskd->set("begin",0);
xytaskd->set("victory",0);
//任务失败
room->set("shuaifu",0);
inv=all_inventory(room);
for(i=0;i<sizeof(inv);i++)
{
obj=inv[i];
if(!obj->is_character()) continue;
if(obj->query("menggu")) continue;
if(!living(obj)) continue;
if(userp(obj)) continue;
message_vision(bing->query("name")+"手起刀落,"+obj->query("name")+"就倒在了血泊之中.....\n",bing);
obj->set("killed",1);
obj->receive_damage("qi", 0, bing);
obj->die();
}
CHANNEL_D->do_channel(this_object(), "bd", HIR + "郭靖夫妇由于寡不敌众战死杀场！帅府被占，襄阳沦陷！" NOR, -1);
if(!room->query("occupied"))
{
object task;
room->set("long",@LONG
        这里遭受蒙古兵的洗劫后，已经惨不忍睹。尸横遍野，往日的景象已经荡然无存....
LONG
        );
(task=load_object("/adm/daemons/xytaskd.lpc"))->add("xyoccupied",1);
if (task->query("xyoccupied")>30)
                CHANNEL_D->do_channel(this_object(), "bd", HIR + "襄阳岌岌可危！" NOR, -1);
else if(task->query("xyoccupied")>20)
                CHANNEL_D->do_channel(this_object(), "bd", HIR + "襄阳现在已尸横遍野！" NOR, -1);
else if(task->query("xyoccupied")>10)
                CHANNEL_D->do_channel(this_object(), "bd", HIR + "襄阳大乱！" NOR, -1);
else if(task->query("xyoccupied")>5)
                CHANNEL_D->do_channel(this_object(), "bd", HIR + "襄阳军情堪忧！" NOR, -1);
else
{}
switch (random(5)){
case 0:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "襄阳某处陷入一片火海之中......" NOR, -1);
break;
case 1:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "蒙古兵在襄阳某处烧杀抢掠无恶不作......" NOR, -1);
break;
case 2:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "襄阳的"+room->query("short")+MAG+"被鞑子夷为平地....." NOR, -1);
break;
case 3:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "襄阳某处死伤严重......" NOR, -1);
break ;
case 4:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "襄阳某处已成一片废墟......" NOR, -1);
break ;
}
}
room->set("occupied",1);
}
return 1;
}
if(!room->query("occupied"))
{
object task;
room->set("long",@LONG
        这里遭受蒙古兵的洗劫后，已经惨不忍睹。尸横遍野，往日的景象已经荡然无存....
LONG
        );
(task=load_object("/adm/daemons/xytaskd.lpc"))->add("xyoccupied",1);
if (task->query("xyoccupied")>30)
                CHANNEL_D->do_channel(this_object(), "bd", HIR + "襄阳岌岌可危！" NOR, -1);
else if(task->query("xyoccupied")>20)
                CHANNEL_D->do_channel(this_object(), "bd", HIR + "襄阳现在已尸横遍野！" NOR, -1);
else if(task->query("xyoccupied")>10)
                CHANNEL_D->do_channel(this_object(), "bd", HIR + "襄阳大乱！" NOR, -1);
else if(task->query("xyoccupied")>5)
                CHANNEL_D->do_channel(this_object(), "bd", HIR + "襄阳军情堪忧！" NOR, -1);
else
{}
switch (random(5)){
case 0:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "襄阳某处陷入一片火海之中......" NOR, -1);
break;
case 1:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "蒙古兵在襄阳某处烧杀抢掠无恶不作......" NOR, -1);
break;
case 2:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "襄阳的"+room->query("short")+MAG+"被鞑子夷为平地....." NOR, -1);
break;
case 3:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "襄阳某处死伤严重......" NOR, -1);
break ;
case 4:
                CHANNEL_D->do_channel(this_object(), "bd", MAG + "襄阳某处已成一片废墟......" NOR, -1);
break ;
}
}
room->set("occupied",1);
add("index",1);
inv=all_inventory(room);
for(i=0;i<sizeof(inv);i++)
{
obj=inv[i];
if(!obj->is_character()) continue;
if(obj->query("menggu")) continue;
if(!living(obj)) continue;
if(userp(obj))
{
if(sizeof(obj->query_enemy())>=5) continue;
bing->kill_ob(obj);
obj->kill_ob(bing);
continue;
}
message_vision(bing->query("name")+"手起刀落,"+obj->query("name")+"就倒在了血泊之中.....\n",bing);
obj->receive_damage("qi", 0, bing);
obj->die();
}
if(!room->query("gate"))
{
remove_call_out("do_move");
call_out("do_move", random(8));
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
if (!room->query("gate"))
{
remove_call_out("do_move");
call_out("do_move", random(4));
return 1;
}
inv=all_inventory(room);
for(i=0;i<sizeof(inv);i++)
{
obj=inv[i];
if(obj->query("menggu")) menggu_number++;
}
if(menggu_number<35)
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
                CHANNEL_D->do_channel(this_object(), "bd", HIR + room->query("short") + "沦陷！" NOR, -1);
(load_object("/adm/daemons/xytaskd.lpc"))->add("occupied",1);
return 1;
}
}
int do_kill(string arg)
{
if(sizeof(this_player()->query_enemy())>35)
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
message_vision(this_object()->query("name")+"死了\n",this_object());
destruct(this_object());
return 1;
}
me=this_object()->get_damage_origin_object();
//if(!me) me=offensive_target(this_object());
if(!me) me=this_player();
xytaskd=load_object("/adm/daemons/xytaskd.lpc");
/*if(query("taskid")!=me->query_temp("xytaskd/taskid"))
  me->delete_temp("xytaskd");*/
me->add_temp("xytaskd/number",1);
me->set_temp("xytaskd/taskid",xytaskd->query("taskid"));
//::die();
message_vision(this_object()->query("name")+"死了\n",this_object());
if(random(10)==0&&me) 	
{
	if(me->query("qi")>=me->query("max_qi"))
	{
		switch(random(6)){
		case 0:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳杀敌让敌人闻风丧胆!" NOR, -1);
			break;
		case 1:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳取敌首级如探囊取物!" NOR, -1);
			break;
		case 2:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳中战功赫赫!" NOR, -1);
			break;
		case 3:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳中独当一面!" NOR, -1);
			break;
		case 4:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳杀敌锐不可当!" NOR, -1);
			break;
		case 5:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳杀敌数以万计!" NOR, -1);
			break;
		default :
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳有万夫不当之勇!" NOR, -1);
		}
	}
	else if(me->query("qi")>=me->query("max_qi")/4*3)
	{
		switch(random(3)){
		case 0:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳杀敌勇猛无比!" NOR, -1);
			break;
		case 1:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳以一敌十!" NOR, -1);
			break;
		default :
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳打败敌军!" NOR, -1);
		}
	}
	else if(me->query("qi")>=me->query("max_qi")/2)
	{
		switch(random(3)){
		case 0:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳杀敌战袍都染红了!" NOR, -1);
			break;
		case 1:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳杀敌无数!" NOR, -1);
			break;
		default:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳誓死卫国，力拒敌兵!" NOR, -1);
		}
	}
	else
	{
		switch(random(3)){
		case 0:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳带伤杀敌，令人敬佩!" NOR, -1);
			break;
		case 1:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说"+me->query("name")+HIM"在襄阳置生死于度外，杀敌无数!" NOR, -1);
			break;
		default:
                        CHANNEL_D->do_channel(this_object(), "bd", HIM + "据说已经分不清楚"+me->query("name")+HIM"脸上那些血是自己的，那些血是敌人的了!" NOR, -1);
		}
	}
}
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
