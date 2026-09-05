//范安及 主管音乐

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("范安及", ({ "fan anji", "fan" }));
	set("title",HIC"左骁卫将军"NOR" "MAG"总监教坊内作使"NOR);
  set("gender", "无性");
	set("age", 50);
	set("long", "他主管着整个内教坊的大小事务，是唐玄宗的亲信宦官。\n");
	
	set("combat_exp", 100000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("music::music-theory", 300);
	set_skill("music::qin", 300);
	set_skill("music::qin::gaoshan-liushui", 300);
	set_skill("music::qin::guangling-san", 300);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

  set("inquiry", ([
    "练习室" : "教坊内的练习室对所有人开放，按照1两银子/分钟的标准收取费用，只要缴纳（jiaona）\n足额的财物以后，在该时间段内将无人打扰你研习乐谱。\n",
  ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_jiaona", "jiaona");
}

int do_jiaona(string arg)
{
	int amount;
	object me=this_player();
	
	if (!arg || !sscanf(arg, "%d", amount) )
	  return notify_fail("命令格式：jiaona 数字，表示缴纳多少两银子。\n");
	
	if ( me->query("balance")<amount*100 )
		return notify_fail("你身上的银两不够，请存足钱以后再过来。\n");
	
	me->add("balance", -100*amount);
	if ( !me->query_temp("changan/jf_time") || 
		   me->query_temp("changan/jf_time")<=time() )
	  me->set_temp("changan/jf_time", time()+amount*60);
	else
		me->set_temp("changan/jf_time", me->query_temp("changan/jf_time")+amount*60);
	tell_object(me, "你递给教坊使大人"+chinese_number(amount)+"两银子，\n范安及说道：你可以选择一个练习室研习到"+ctime(me->query_temp("changan/jf_time"))+"为止。\n");
	return 1;
}

void die()
{
  remove_all_enemy();
  all_inventory(environment())->remove_killer(this_object());
  set("eff_qi", query("max_qi"));
  set("qi", query("max_qi"));
  set("eff_jing", query("max_jing"));
  set("jing", query("max_jing"));
  message_vision("$N跪地求饶道：大侠饶命啊。\n", this_object());
}

void unconcious()
{
  die();
}
        