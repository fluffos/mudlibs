// maodongzhu.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("毛东珠", ({"mao dongzhu", "mao", "dongzhu"}));
	set("title",HIY"神龙教"HIR"赤龙使"NOR"座下弟子");
	set("nickname",HIY"假太后"NOR);
	set("long",
"一个三十岁左右的贵妇，她脸色极白，目光炯炯，但眉头微蹙，似
乎颇有愁色，又好象在想什么心事，你不禁寻思：“她身为皇太后，
还有什么不开心的？啊，是了，她死了老公。就算是皇太后，死了
老公，总不会开心。”\n");

	set("gender", "女性");
	set("attitude", "peaceful"); 
	set("age", 40);
	set("per", 21);
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
        set("max_qi", 25000);
	set("max_jing", 25000);
	set("neili",28000);
	set("max_neili", 25000);
//	set("jiali", 100);
	set("combat_exp", 5500000);
	set("score", 2400000);
        set_skill("claw", 100);
        set_skill("strike", 100);
	set_skill("dulong-shenzhua", 200);
	set_skill("xuanming-zhang", 200);
        set_skill("force", 250);
	set_skill("shenlong-xinfa", 150);
        set_skill("dodge", 250);
	set_skill("yixingbu", 200);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 280);
        set_skill("strike", 280);
	set_skill("huagu-mianzhang", 280);
        set_skill("parry", 250);
        set_skill("staff", 250);
        set_skill("sword", 250);
        set_skill("zhaosheshu", 250);
        set_skill("yangsheshu", 250);
	set_skill("shedao-qigong", 200);
	set_skill("literate", 190);

	
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "juehu-shou");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "juehu-shou");
        map_skill("staff", "shedao-qigong");
        map_skill("sword", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("hand", "juehu-shou");


	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
		(: command("smile") :),
(: perform_action, "strike.bujue" :),
(: perform_action, "strike.hua" :),
(: perform_action, "strike.lianhuan" :),
                (: perform_action, "strike.hua" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.shewu" :),
                (: perform_action, "hand.flower" :),
                (: perform_action, "hand.meinu" :),                
                (: perform_action, "hand.yingxiong" :),                
 (: perform_action, "sword.chang" :),
                (: perform_action, "sword.chang2" :),
                (: perform_action, "sword.chang3" :),
                (: perform_action, "sword.cui" :),
                (: perform_action, "sword.fei" :),
                (: perform_action, "sword.wanshe" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.juehu	" :),                
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
        set("inquiry", ([
                "陷害" : "你什么意思......。\n",
        ]));
        set("chat_chance", 5);
        set("chat_msg", ({
"皇太后说道：小桂子知道的事太多了，不堵住他的嘴，我睡也睡不着．\n",
        }) );
        
	setup();
//	carry_object(VEGETABLE_DIR"xionghuang");
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	//carry_object(__DIR__"obj/yaoshi");
	add_money("gold",1);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
		kill_ob(ob);
	}
	return;
}


int accept_object(object me, object obj)
{
	object pai;
if (query("isok")==1) return 0;

        if( (string) obj->query("name") == "小桂子"
        || obj->query("id") =="xiao guizi" )
	{
        message_vision("$N向$n点了点头：\n",this_object(),me);
        command("heihei");
	command("say 做得好，除去我的心病！\n");
	command("say 这本42章经，就交给你保管了！\n");
	pai = new("/d/city2/obj/book14_2");
	if(pai)
	pai->move(me);
        message_vision("$N拿出一本42章经给了$n。\n",this_object(),me);
this_object()->set("isok",1);
set("isok",1);
        call_out("destroying", 0, obj,me);                       
	return 1;	
	}
else       return 0;
}

void destroying(object obj, object ob, object me)
{   

   if(obj) destruct(obj);
}
