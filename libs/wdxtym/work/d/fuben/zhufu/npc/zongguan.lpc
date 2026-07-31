inherit NPC;
#include <ansi.h>

//可爆出物品列表


void create()
{
	set_name(HIR"朱福"NOR, ({ "zhu fu", "zhu fu"}) );
	set("gender", "男性");
	set("age", 45);
	set("long", "这家伙一副笑眯眯的样子，看上去人畜无害。\n");
 	set("max_qi",200000);
	set("eff_qi", 200000);
	set("qi", 200000);
	set("max_jing", 200000);
	set("eff_jing", 200000);
	set("jing", 200000);
	set("twtnpc",1);
 	set("max_neili", 200000);
 	set("neili",200000);
	set("combat_exp", 10000000+random(30000000));

	set("attitude", "peaceful");
	set("str", 1000);
	set("int", 300);
	set("con", 30000);
	set("dex", 300);
                     set_skill("force", 500);
                     set_skill("huagong-dafa", 500);
                     set_skill("guixi-gong", 500);
                     set_skill("throwing", 500);
                     set_skill("feixing-shu", 500);
                     set_skill("dodge", 500);
                     set_skill("zhaixinggong", 500);
                     set_skill("strike", 500);
                     set_skill("chousui-zhang", 500);
                     set_skill("claw", 500);
                     set_skill("sanyin-wugongzhao", 500);
                     set_skill("whip", 500);
                     set_skill("chanhun-suo", 500);
                     set_skill("parry", 500);
                     set_skill("staff", 500);
                     set_skill("poison", 500);
                     set_skill("tianshan-zhang", 500);

                     map_skill("force", "huagong-dafa");
                     map_skill("dodge", "zhaixinggong");
                     map_skill("strike", "chousui-zhang");
                     map_skill("claw", "sanyin-wugongzhao");
                     map_skill("whip", "chanhun-suo");
                     map_skill("parry", "tianshan-zhang");
                     map_skill("staff", "tianshan-zhang");

                     prepare_skill("strike", "chousui-zhang");
                     prepare_skill("claw", "sanyin-wugongzhao");

                     set("chat_chance_combat", 80);
                     set("chat_msg_combat", ({
                          (: perform_action, "staff.fugu" :),
                          (: perform_action, "staff.xue" :),
                          (: perform_action, "strike.biyan" :),
                          (: perform_action, "strike.huolang" :),
                          (: perform_action, "strike.huoqiu" :),
                          (: perform_action, "strike.huoyan" :),
                          (: perform_action, "claw.zhua" :),
                          (: exert_function, "recover" :),
                          (: exert_function, "powerup" :),
                     }));
				set("weapon", "gangzhang");
	set_temp("apply/armor", 1000);
	set_temp("apply/damage",500);			 

	setup();

}
void init(object me)
{
	object ob;

	me = this_player();
	ob = this_object();
	::init();

	if (userp(me)) {
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 100);
		if (!random(3))
			ob->do_clone(me, 100);
		command("say 你来干嘛？\n");
		kill_ob(me);
		me->kill_ob(this_object());
	}
}
void die()
{
		string short;
	mapping yours,my,a,b;
	object ob,*tar,obj;
	  object gift;
	  int i,j,k;
	ob=this_object();
	tar = ob->query_enemy();
	
	for(k=0;k<sizeof(tar);k++)
	{
	if(tar[k]->query("yipairw4")==1&&!tar[k]->query("yipairw5"))
	{
	tar[k]->set("yipairw5",1);
	gift=new("clone/book/yipai");
    gift->move(tar[k]);
	tell_object(tar[k],"你获得了"+ob->query("name")+"身上携带的《一拍两散》，是时候回去找流浪公子了！\n");
	}
	if(tar[k]->query("fbzhufu")>0)
	{
	   tar[k]->add("combat_exp",100000);
	   tar[k]->add("potential",200000);
	   tar[k]->add("fbzhufu",-1);
	   for(j=0;j<5;j++)
	   {
	   	obj=new("clone/gift/shuhua");
		obj->move(tar[k]);
	   }
       if(!(short=tar[k]->query("banghui/name")))
	   tell_object(tar[k],HIC"你杀死"+name()+"，"HIY"由于你没有帮派，没有获得帮派贡献！100000点修为，200000点潜能"NOR"\n");
       else
	   {
		BANGHUI_D->set_banghui(short+"/gongxian/"+tar[k]->query("name"), BANGHUI_D->query_banghui (short+"/gongxian/"+tar[k]->query("name"))+50);
		BANGHUI_D->set_banghui(short+"/exp", BANGHUI_D->query_banghui(short+"/exp")+50);
	   tell_object(tar[k],HIC"你杀死"+name()+"，"HIY"获得了50帮派贡献！100000点修为，200000点潜能"NOR"\n");
	   } 	   
	}else
    tell_object(tar[k],HIC"你杀死"+name()+"，"HIY"由于你次数上限，你没有获得任何东西！"NOR"\n");
	}
	::die();
}