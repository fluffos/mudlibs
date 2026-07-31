// hong.c 洪安通

#include <ansi.h>;
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

void create()
{
	set_name("洪安通", ({ "hong antong", "hong" }));
	set("title",  HIY"神龙教"NOR"教主" );
	set("nickname", HIR "永享仙福" NOR);
	set("long", "他就是武功盖世、令江湖人等谈之色变的神龙教教主洪安通。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 130);
	set("int", 130);
	set("con", 130);
	set("dex", 130);
	
	set("max_qi", 50000);
	set("max_jing", 50000);
	set("neili", 53000);
	set("max_neili", 53000);
	set("jiali", 100);
	set("combat_exp", 16000000);
	set("score", 400000);

       set_skill("force", 1000);
	set_skill("shenlong-xinfa", 980);
       set_skill("dodge", 1200);
	set_skill("yixingbu",300);
       set_skill("hand", 1200);
	set_skill("shenlong-bashi", 980);
       set_skill("strike", 1200);
	set_skill("huagu-mianzhang", 980);
       set_skill("parry", 1000);
       set_skill("staff", 1300);
       set_skill("sword", 1000);
	set_skill("shedao-qigong", 980);
	set_skill("literate", 90);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-qigong");
        map_skill("staff", "shedao-qigong");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
	create_family("神龙教",1,"教主");

        set("inquiry", ([
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"洪安通" :  "\n你不想活了是不是?\n",
		"教主" :  "\n我就是神龙教教主。\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
       ]) );
	set("chat_chance_combat", 80);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat 凭你这" + RANK_D->query_rude(this_player())+",也敢在太岁爷头上动土?\n") :),
		(: command("say 你活得不耐烦了找死啊？\n") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

int recognize_apprentice(object me)
{
        if( me->query("learnhong")) return 1;
        if ((int)me->query("shen") > -1000) {
                command("say 我越看你越象白道派来卧底的。");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把我放在眼里，我又怎能容你？!");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        } else {
                command("say 我洪安通比起古往今来的圣人怎么样啊？");
                message_vision("洪安通微闭双眼，手捻长须，一付等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
	return 0;
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说我什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "万年不老") >=0 && (strsrch(arg, "永享仙福") >=0
         || strsrch(arg, "寿与天齐") >=0 || strsrch(arg, "文武仁圣") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
                this_player()->set("learnhong", 1);
                command("recruit " + this_player()->query("id"));
        } else {
                command("say 你如此不把我放在眼里，我又怎能容你？!");
			this_object()->set_leader(this_player());
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player()); 
        }
        return 1;
}

// 万年不老,永享仙福,寿与天齐,文武仁圣

void die()
{
message_vision("\n$N奇道：“咦,居然有人能杀了我,....”说完睁着两眼倒地死了。\n", this_object());
	::die();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_flatter", "flatter");
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
	   set("combat_exp",500000);
	   set("qi",10);
	   set("jing",10);
	}
	return;
}

void attempt_apprentice(object ob)
{
    if (ob->query("party/party_name") != HIY "神龙教" NOR ) {
        command("say 你不是本教教众, 想来找死啊!");
	return;
    }
    if ((int)ob->query_skill("shenlong-xinfa",1) < 60 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
	return;
    }
    if ((int)ob->query_skill("shedao-qigong",1) < 60 ) {
        command("say 你的本门杖法太低了,还是努努力先提高一下吧!");
	return;
    }
    if ((int)ob->query("shen") > -10000  ) {
        command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
	return;
    }
    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
}
 
