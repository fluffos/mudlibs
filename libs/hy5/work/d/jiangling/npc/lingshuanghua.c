//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;
int ask_me();

void create()
{
	set_name("凌霜华",({ "ling shuanghua", "ling"}));
	set("gender", "女性" );
	set("nickname", HIY"人淡如菊"NOR);
	set("title",HIM"知府千金"NOR);
	set("age", 18);
	set("long", 
"一个清秀绝俗的少女正在观赏菊花，穿一身嫩黄衫子，当真是人淡如菊。\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("max_qi",1000);
	set("max_jing",1000);
	set("max_neili",3000);
	set("qi",1000);
	set("jing",1000);
	set("neili",3000);
        set("combat_exp", 2000);	
	set("flower_count", 1);
	set("attitude", "friendly");
	set("chat_chance", 5);
	set("chat_msg", ({
		"凌霜华脸红了红，低声道：“对不起，先生别见怪，小丫头随口乱说。”\n",
	}) );
	set("inquiry", ([
		            "丁典" : (: ask_me :),
            "丁大哥" : (: ask_me :),
		"绿菊"   : (: ask_me :),
		"绿菊花" : (: ask_me :),

	]));
	setup();
	carry_object("/d/jiangling/obj/nenhuangshan")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
}


void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
             command("wanfu " + me->query("id"));
        command("say 这位"+RANK_D->query_respect(me)+"是来"+
                "看菊花的吧？不知道爹爹在花园里种了什么，人一进去就会被熏死的，"+
                "你还是请回吧。");
}

        
int accept_kill(object me)
{
        command("say 丁大哥救命啊！" + me->name() + "这个" + RANK_D->query_rude(me) + "要强暴我！\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

int ask_me()
{
        object who=this_player();
        if (who->query_temp("jinboxunhua")) {
                command("say 我不是告诉你了吗？你记性也太那个了。");
                return 1;
        }
        command("say 啊！你是丁大哥的朋友啊！家父在花园里中了剧毒的金波旬花，"
                + "你进去后屏住呼吸就可以了。");
        who->set_temp("jinboxunhua",1);
        return 1;
}

