// Feb. 6, 1999 by Winder
// jinshe.c 金蛇郎君
#include <ansi.h>
inherit NPC;

void dest(object ob);
int ask_me();
int ask_me2();
void create()
{
	set_name("袁承志", ({"yuan chenzhi", "yuan", "chenzhi"}));
	set("nickname", HIY"七省武林盟主"NOR);
	set("gender", "男性");
	set("age", 25);
       set("long", "
明朝大将袁崇焕儿子。他机缘巧合下更拜了华山派掌门神剑仙猿穆人清为师。\n 并从铁剑门的千变万劫木桑道人和金蛇郎君夏雪宜的金蛇秘笈学得一身惊人武功。\n下山后，他行侠丈义，结识夏雪宜之女温青青和长平公主阿九。二十多岁便成为七省武林盟主。\n");

 	set("attitude", "peaceful");
	
	set("str", 100);
	set("int", 30);
	set("con", 30);
	set("dex", 135);

	set("inquiry", ([
		"营救" : (: ask_me :),
		"大事" : (: ask_me2 :),
		"救国" : (: ask_me2 :),
	]));
	set("qi", 50000);
	set("max_qi", 50000);
	set("jing", 50000);
	set("max_jing", 50000);
	set("neili", 50000);
	set("max_neili", 50000);
	set("jiali", 100);
	set("no_get",1);
	
	set("combat_exp", 9000000);
	set_skill("jinshe-zhang",380);
	set_skill("force", 300);		// 基本内功
	set_skill("huntian-qigong", 300);	// 混天气功
	set_skill("unarmed", 320);		// 基本拳脚
	set_skill("dodge", 300);		// 基本躲闪
	set_skill("strike", 300);
	set_skill("parry", 300);		// 基本招架
        set_skill("sword", 300);                // 基本剑法
        set_skill("jinshe-jian",400);           // 金蛇剑法
	
	map_skill("force", "huntian-qigong");
	map_skill("sword", "jinshe-jian");
	map_skill("parry", "jinshe-jian");
	map_skill("strike", "jinshe-zhang");
        prepare_skill("strike", "jinshe-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuangwu" :),                
                (: perform_action, "sword.kun" :),                
                (: perform_action, "sword.shi" :),                
                (: perform_action, "sword.suo" :),                
                (: perform_action, "sword.wan" :),                
                (: perform_action, "strike.fugu" :),  
        }) );
	set_temp("apply/attack",  250);
	set_temp("apply/defense", 250);        	
	set_temp("apply/damage", 2250);   
	set_temp("apply/armor", 2250);   
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book13")>=3))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 谢谢这位兄弟。。\n",this_object(),who);
	message_vision("$N对$n说道： 我这要去华山杀了那恶人玉真子，兄弟我先走了。\n",this_object(),who);
if((int)who->query("jinyong/book13")==2)
{
	i = 800+random(1800);
	who->set("jinyong/book13",3);
	who->add("combat_exp",i+12880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+12880)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();	
	
	
}


	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N说完闪了闪身就消失在门外......\n"NOR,ob);
destruct(this_object());
   return;      
}


int ask_me2()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book13")>=4))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	command("bow " + who->query("id"));
	message_vision("$N对$n说道： 我得知 大太监曹化淳联系了 金国皇帝皇太极 有秘谋。\n",this_object(),who);
	message_vision("$N对$n说道： 你也要去办这个大事？ 那先考验一下你的武功吧。\n",this_object(),who);
who->set_temp("book1342",1);
kill_ob(who);
	return 1;
}


void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

                if ((int)who->query("jinyong/book13")==3)
{
                i = 500+random(2000);
		who->set("jinyong/book13",4);
		who->add("combat_exp",i+12000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+12000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		//message("channel:chat", HIB"【海洋III】听说"+who->name() + "完成了笑傲江湖的所有任务!"NOR"\n", users());
		message_vision("$N对$n说道： 你的武功不错，那我们在盛京皇宫见面。\n",this_object(),who);
		who->save();
}		
		
	call_out("destroying", 0);

}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    