// ren.c 任我行
//by bing

inherit NPC;
inherit F_MASTER;

#include "riyuenpc2.h"
#include <ansi.h>
void heal();
void suck();

void create()
{
        set_name("任我行", ({ "ren woxing", "ren" }));
        set("title",MAG "日月神教" NOR + HIR "前教主" NOR);
        set("long","他长须垂至胸前，胡子满脸，再也瞧不清他的面容，头发须眉都是深黑之色，全
无斑白。手腕上套着个铁圈，圈上连着铁链通到身后墙壁之上，再看他另一只手和
双足，也都有铁链和身后墙壁相连。\n");
        set("gender", "男性");
        set("age", 65);
        set("attitude","heroism");
        set("shen_type", -1);
	set("shen",-50000);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("no_use/qiankun-danuoyi",1);
        set("no_use/iron-cloth",1);
         set("max_qi",3000);
        set("max_jing", 2000);
        set("neili",3000);
            set("no_get",1);
        set("max_neili",3000);
         set("jiali",200);
         set("combat_exp",2000000);
	set("score",5000);
          set("chat_chance", 10);
        set("chat_msg", ({
		"任我行说道：「几年前我一时失察，竟中了东方不败这厮的奸计，被囚在这个破地方。」\n",
                (: heal :),
		"任我行说道：「东方不败这厮奸诈之极，竟能骗得过我，真是让我佩服。」\n",
		"任我行摇摇头，叹了口气。\n",
		"任我行自言自语道：「不知道盈盈怎么样了，我在这里唯一牵挂的就是她啊！」\n",
        }));
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
 		(: suck :),
		(: suck :),
		(: perform_action, "sword.xuanmu" :),
		(: perform_action, "blade.lianhuan" :),
        }) );
        set("inquiry", ([
            "东方不败" : "哼！这厮篡了我的位子，把我关在这暗无天日的地牢里，总有一天我要找他算帐！",
            "东方教主" : "你管这贼厮鸟叫教主？我才是日月神教的教主！你等着看吧，我会把这个位置抢回来的！",
	    "任我行" : "老夫就是任我行！你也知道我的名头？",
	    "任教主" : "嗯，这还差不多，看来我旧日的下属还没全忘了老夫啊！",
	    "任盈盈" : "她是我的宝贝女儿。她现在好么？东方不败对她怎么样？",
	    "圣药" : "那是我教教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
	    "三尸脑神丹" : "那是我教教主对有功之人的赏赐，吃了以后对教主更加忠心。在风雷堂童堂主处领取。",
       ]) );

        set_skill("force", 300);
        set_skill("xixing-dafa", 250);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("kaishan-zhang", 300);
	set_skill("ryingzhua-gong",300);
	set_skill("claw",300);
	set_skill("sword",300);
	set_skill("riyue-jian",300);
	set_skill("blade",200);
	set_skill("riyue-dao",300);
        set_skill("feitian-shenfa", 300);
        set_skill("strike", 300);
        set_skill("literate",200);
        map_skill("force", "xixing-dafa");
        map_skill("parry", "riyue-jian");
        map_skill("dodge", "feitian-shenfa");
        map_skill("strike", "kaishan-zhang");
	map_skill("claw","ryingzhua-gong");
	map_skill("blade","riyue-dao");
        map_skill("sword","riyue-jian");
	prepare_skill("strike", "kaishan-zhang");
	prepare_skill("claw","ryingzhua-gong");
	prepare_wskill("blade","riyue-dao");
	prepare_wskill("sword","riyue-jian");
	reset_action();
	create_family("日月神教", 19, "弟子");
        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/d/riyuejiao/obj/tiehuan")->wear();
	carry_object("/d/riyuejiao/obj/tiehuan2")->wear();
	carry_object("/d/riyuejiao/obj/riyuedao")->wield();
	carry_object("/d/riyuejiao/obj/riyuejian")->wield();
       }
void init()
{
	object ob;
	mapping fam;
        ::init();
	ob = this_player();
	if (interactive(ob) && !is_fighting()) {
		remove_call_out("greet");
		call_out("greet", 1, ob);
	}
	add_action("do_move", "move");
        add_action("do_none","hit");
        add_action("do_none","fight");
        add_action("do_full","kill");
        add_action("do_none","hitall");
        add_action("do_none","perform");
        add_action("do_none","yong");
}
int do_none()
{
        object me = this_object();
        me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
        me->set("neili",me->query("max_neili"));
        message_vision("$N对著任我行大喝一声：看招！\n",this_player());
        me->fight_ob(this_player());
        return 1;
}
int do_full()
{
	 object ob;
        object me = this_object();
        me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
        me->set("neili",me->query("max_neili"));
        message_vision("$N对著任我行喝道：「老匹夫！今日不是你死就是我活！」\n",this_player());
        me->kill_ob(this_player());
        return 1;
}

void attempt_apprentice(object ob)
{
	command("say 老夫这个样子怎么收你为徒？");
}

int accept_object(object me,object ob)
{
	object obj;
	if ((string)ob->query("id") == "gangsi ju")
	if (me->query_temp("riyue/save_ren") == 1)
		{
        		message_vision("任我行微微一怔，等到看清了手里的东西，立刻面现喜色，开始哈哈大笑，声若洪钟。\n", me);
			message_vision("只听得门外「咚咚」几声响，江南四友都已经被震晕在地，$N也感到头昏脑胀，摇摇欲坠......\n",me);
			obj = new("/d/riyuejiao/obj/tiehuan");
			obj->move(me);
			obj = new("/d/riyuejiao/obj/tiehuan2");
			obj->move(me);
			me->unconcious();
			me->move("/d/riyuejiao/meizhuang/prison3");
			me->set("save_ren",1);
		   	remove_call_out("destroying");
			call_out("destroying", 1, me, ob);
			return 1;
		}
	else	
		{
			message_vision("任我行微微一怔，等到看清了手里的东西，立刻面现喜色，但又怀疑地看了$N一眼
把钢丝锯收了起来没说话。\n",me);
          	    	remove_call_out("destroying");
			call_out("destroying", 1, me, ob);
			return 1;
		}	
	return 0;

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

void greet(object me)
{
	if (me->query_temp("riyue/杀任"))
	{
		command("l " + me->query("id"));
		command("say 东方不败那厮让你来杀我？你先得问问我手里的刀和剑！");
		command("kill " + me->query("id"));
		return;
	}
	
	command("say 你能打败这四个老贼闯进来？你的武功很不错啊！");
	command("look " + me->query("id"));
	command("say " + RANK_D->query_respect(me) + "跟我比划比划？");
	return;
}

int do_move(object me)
{
	command("say 乱动什么！");
	return 1;
}

void suck()
{
        object *enemy,target;
	
	if ( this_object()->query("qi") < this_object()->query("eff_qi")*2/3 )
		command("exert recover");
	else
	{
	        enemy = query_enemy() - ({ 0 });
        	target = enemy[random(sizeof(enemy))];
        	command("exert maxsuck " + target->query("id"));
        }
}

void die()
{
	object obj,me,corpse;
	me = this_object();

	if( objectp(obj = me->get_damage_origin_object()) && ((obj->query_temp("riyue/杀任")))) 
	{
		 obj->set_temp("riyue/killer",1);
	}
	message_vision("任我行死了。\n",obj);
	corpse = new("/d/riyuejiao/obj/corpse");
	corpse->move("/d/riyuejiao/meizhuang/prison2");
	obj->move("/d/riyuejiao/meizhuang/prison2");
	destruct(me);
	
}
