// yuanziyi.c 袁紫衣

#include <command.h>
#include <ansi.h>

inherit NPC;
int ask_me();
void create()
{
        set_name("袁紫衣", ({ "yuan ziyi","ziyi","yuan"}));
        set("long",
                "她是峨嵋派一个辈份极高的老尼的关门徒弟。\n"
                "一张脸秀丽绝俗。身着一身淡紫衣裳。\n"
                "这一路上去京师她夺了好几家掌门。\n");
        set("gender", "女性");
        set("age", 18);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("title", RED"九家半门派"HIG"总掌门"NOR);
        set("class", "bonze");

        set("inquiry",([
                "胡斐"    : "我和胡大哥毕竟没有缘份的。",
                "掌门"    : "我就喜欢抢掌门！",
                "掌门人大会" : (: ask_me :),
        ]));
        set("str", 30);
        set("per", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);






	set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 3000000);
	set("score", 1000);
	set("book_count", 1);
	set("yao_count", 1);
	
	set_skill("unarmed", 200);
	set_skill("sword", 300);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 300);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("buddhism", 350);
	set_skill("medicine", 280);
	set_skill("goplaying", 280);
	set_skill("baiyun-xinfa",380);	
	set_skill("hengshan-jian", 280);
	set_skill("chuanyun-shou",280);
	set_skill("tianchang-zhang",280); 
	set_skill("whip",180); 
	set_skill("rousi-whip",180); 
	set_skill("canxin-jian",288); 
	set_skill("lingxu-bu", 280);
	set_skill("literate", 150);
	
	map_skill("force","baiyun-xinfa");
	map_skill("sword", "canxin-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "canxin-jian");
	map_skill("dodge", "lingxu-bu");

	prepare_skill("hand", "chuanyun-shou");
	prepare_skill("strike", "tianchang-zhang");
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);

       set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
(: exert_function, "shield" :),
(: exert_function, "powerup" :),				
		(: perform_action, "sword.riluo" :),
		(: perform_action, "sword.shenfeng" :),	
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.xunlei" :),	
	(: perform_action, "dodge.lingxu" :),			
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: perform_action, "hand.break" :),
		(: perform_action, "strike.diezhang" :),
	}));
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/ycloth.c")->wear();
         carry_object(__DIR__"obj/lingpai.c");
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{       
	if(file_name(environment())=="/d/henshan/chating" && !ob->query("jinyong/book1"))
	{
		command("say 本姑娘在这里休息，别来打搅！");
		command("kick "+ob->query("id"));
		ob->move("/d/henshan/hsroad6");
		return;
	}
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	

object fang = present("feng tiannan",where);
	if(fang)
	{
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"还是先打发了面前这位吧！\n",this_object(),who);
		return 1;
	}
	
	
		  	if(((int)who->query("jinyong/book1")!=1))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}	
	
	  	if(((int)who->query("jinyong/book1")>=2))
	{
		message_vision("$N对$n说道： 你在说什么啊！\n",this_object(),who);
		return 1;	
	}
	command("bow " + who->query("id"));
	message_vision("$N对$n说道： 谢谢大侠教命之恩。\n",this_object(),who);
	message_vision("$N对$n说道： 北京康亲王府的掌门人大会必定有惊天阴谋。\n",this_object(),who);


	
	i = 100+random(800);
	who->set("jinyong/book1",2);
	who->add("combat_exp",i+8880);
	who->add("potential",i*9);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+8880)+"点经验"+
	           chinese_number(i*9)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
	//call_out("destroying", 0);                       
	return 1;
}

