// /NPC meijian.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
	set_name("梅剑", ({ "mei jian", "mei"}));
	set("long",
	    "这是个容貌姣好的女子, 瓜子脸蛋,\n"+
	    "眼如点漆, 清秀绝俗.\n"+
	    "你总觉得在哪见过她.\n");
	set("gender", "女性");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);

	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 8500);
	set("max_jing", 8500);
	set("neili", 21000);
	set("max_neili", 21000);
	set("jiali", 20);

	set("combat_exp", 900000);
	set("score", 10000);
	set_skill("yangyanshu", 160);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("hand",70);
	set_skill("strike", 70);
	set_skill("sword",100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("hand", 100);
	set_skill("qingyun-shou", 180);
	set_skill("panyang-zhang", 180);
	set_skill("liuyue-jian", 180);

	set_skill("zhemei-shou",120);
	set_skill("liuyang-zhang",120);
	set_skill("tianyu-qijian",120);
	set_skill("yueying-wubu",120);
	set_skill("bahuang-gong", 120);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	prepare_skill("sword","tianyu-qijian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));
	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",15);
}

void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if ((string)ob->query("family/family_name") == "灵鹫宫") 
             {
               message_vision("梅剑冲着$N点点头，微微笑了笑。\n",ob);
               return;
              }
        if (!(string)ob->query("family/family_name"))
             {
               message_vision("梅剑冲着$N微笑说：你是来拜师的吧，拜我吧。\n",ob);
               return;
              }
}

void attempt_apprentice(object ob)
{
   if ((string)ob->query("gender")=="女性")
   {
		message_vision("梅剑垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
       command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
       return;}
   else
      {
		message_vision("梅剑瞪着你看了半天,说道：“阁下是否该去做做手术?”\n",ob);
       return;}
}
