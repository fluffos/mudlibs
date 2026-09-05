// seng2.c
// seagate@pkuxkx, 2010/10/08

#include <ansi.h>
inherit NPC;

string ask_pichai();
string ask_dao();

void create()
{
        set_name("中年僧人", ({ "seng ren", "seng" }) );
        set("gender", "男性" );
        set("age", 38);
        set("long", "这是个身强力壮、皮肤黝黑的中年僧人。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);
        set_skill("unarmed", 50);
        set_skill("dodge", 35);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set("armor_count",100);
        set("combat_exp", 7500);
        set("attitude", "peaceful");
        set("inquiry", ([
        	"劈柴" : (: ask_pichai :),
        	"柴刀" : (: ask_dao :)
        ]));
        setup();
}

void init()
{
	add_action("do_jiao", "jiao");
}

//劈柴任务的发布人，劈柴任务由他分配你到底应该上缴什么样材质的木柴。
//劈柴任务分为先问他确定任务要求（ask 劈柴），然后找他要柴刀（需要劈
//的时候再要也行。），领未处理的木柴，放到木墩上，劈开，获得处理后的
//木柴，上缴木柴直到达到核定数量为止。
//set_temp("quest_pichai")里面存放和此任务相关的所有属性
//chaidao              1或者没有表示是否领过柴刀，领过不能重新领。
//reqwood              要求的木柴名称
//reqinch              要求的木柴尺寸
//reqamount            要求的木柴数量
//prepwood             1或者没有表示是否领过未处理的木柴，
//                     领过以后只要加工完才能再领。
//putwood              1或者没有表示未处理的木柴是否放置在木墩上
//name                 放置在木墩上的未处理木柴名称
//size                 放置在木墩上的未处理木柴的尺寸
//material             放置在木墩上的未处理木柴的材质
//start                1或者没有表示是否开始劈柴任务，没有这个标志不能启动劈柴任务。
//success              1或者没有表示劈柴任务是否完成了，完成就可以回去领赏去。
//promoter             任务发布人名称
string ask_dao()
{
	object ob,me;
	me=this_player();
	if(me->query_temp("quest_pichai/chaidao"))
		return "你已经领过柴刀了，不能再领了。\n";
	else if(!me->query_temp("quest_pichai/reqwood"))
		return "中年僧人瞥了你一眼，说道：“柴刀我还在用呢，等等吧。”\n";
	
	ob=new(__DIR__"obj/chaidao");
	ob->move(me);
	me->set_temp("quest_pichai/chaidao",1);
	return "中年僧人递给"+me->query("name")+"一把柴刀，悄声说道：“柴刀用完了要记得上缴啊。”\n";
}

//劈柴任务分配函数，不能重复分配任务，必须有一个前置的启动过程才能触发本任务。
string ask_pichai()
{
	object me;
	string *wood=({
		"松柴",
		"柏柴",
		"杨柴"
//		"柳柴",
//		"槐柴"
		});
	int inch,amount;
	
	me=this_player();
	
	if(me->query_temp("quest_pichai/reqwood"))
		return "你已经领过任务了，请劈完分配给的木柴再领新任务吧。\n";
  else if(!me->query_temp("quest_pichai/start"))
  	return "中年僧人遗憾地对你说：“今天劈的木柴足够用了，请明天再来吧。”\n";
  
  inch=random(3)+1;
  amount=(6*(random(2)+1))/inch;
  me->set_temp("quest_pichai/reqwood", wood[random(sizeof(wood))]);
  me->set_temp("quest_pichai/reqinch", inch);
  me->set_temp("quest_pichai/reqamount", amount);

	this_object()->newbieDesc("给厨房劈"+HIM+chinese_number(amount)+NOR+"根"+HIY+chinese_number(inch)+"寸宽的"+me->query_temp("quest_pichai/reqwood")+"。\n");
  return "中年僧人告诉"+me->query("name")+"：“厨房现在紧急需要"+HIY+chinese_number(inch)+"寸宽的"+
         me->query_temp("quest_pichai/reqwood")+HIM+chinese_number(amount)+NOR+"根，劈完以后上缴(jiao)到我这里来。\n劈柴(pi)前先找我领工具，干完活记得把柴刀还回来。”\n";
}

/*将劈好的柴火上缴给僧人。
  命令格式为jiao 数量 木柴id或者jiao 木柴id*/
int do_jiao(string arg)
{
	string wood,name;
	object ob,me;
	int    amount,inch,lp,woodamt;
	
	me=this_player();
	inch=me->query_temp("quest_pichai/reqinch");
	name=me->query_temp("quest_pichai/reqwood");
	woodamt=me->query_temp("quest_pichai/reqamount");
	
	if(!arg) {
		printf("命令格式：jiao 数量 木柴id或者jiao 木柴id或者jiao 柴刀id。\n");
		return 1;
	}
	else if(!sscanf(arg,"%d %s",amount,wood)) {
		if(!sscanf(arg,"%s",wood)) {
			printf("命令格式：jiao 数量 木柴id或者jiao 木柴id或者jiao 柴刀id。\n");
			return 1;
		}
		else {
			amount=1;
		}
	}
	else if(!wood) {
		printf("命令格式：jiao 数量 木柴id或者jiao 木柴id或者jiao 柴刀id。\n");
		return 1;
	}
	
	if(!me->query_temp("quest_pichai/reqwood")) {
		printf("中年僧人推迟了一下，说道：“目前厨房木柴还够用，这些还是你留着自己用吧。”\n");
		return 1;
	}
	else if(me->query_temp("quest_pichai/success")) {
		printf("中年僧人推迟了一下，说道：“目前厨房木柴还够用，这些还是你留着自己用吧。”\n");
		return 1;
	}
	else if(me->query_temp("quest_pichai/reqamount")<=0||!me->query_temp("quest_pichai/reqamount")) {
		ob=present(wood,this_player());
		if(!ob) {
			printf("命令格式：jiao 数量 木柴id或者jiao 木柴id或者jiao 柴刀id。\n");
			return 1;
		}
		else if(ob->query("name")=="柴刀"&&!ob->query("value")) {
			tell_object(me,"中年僧人收走了你的柴刀。\n");
			me->set_temp("quest_pichai/success",1);
			destruct(ob);
			return 1;
		}
		else {
			tell_object(me,"中年僧人说道：“你劈的木柴够多了！剩下的自己先留着吧。”\n");
			return 1;
		}
	}
	
	for(lp=0;lp<amount;lp++) {
		ob=present(wood,this_player());
		if(!ob) {
			printf("你要上缴什么东西？\n");
			return 1;
		}
		else if(strcmp(ob->query("name"),chinese_number(inch)+"寸宽的"+name)) {
			printf("你上缴的"+ob->query("name")+"和我要的"+chinese_number(inch)+"寸宽的"+name+"似乎并不相符啊。\n");
			return 1;
		}
		else if(ob->query("owner")!=me->query("id")) {
			printf("这根木柴不是你劈的，你拿错木柴了！\n");
			return 1;
		}
		
		woodamt--;
		me->set_temp("quest_pichai/reqamount",woodamt);
		if(woodamt>0)
			tell_object(me,"你上缴了一根"+ob->query("name")+"，还需要再上缴"+chinese_number(woodamt)+"根木柴。\n");
		else {
			tell_object(me,"你上缴了一根"+ob->query("name")+"，把"+GRN+"柴刀"+NOR+"还给我再回去向"+me->query_temp("quest_pichai/promoter")+"领赏。");
			return 1;
		}
		destruct(ob);
	}
	return 1;
}