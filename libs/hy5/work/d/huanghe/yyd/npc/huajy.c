// huajy.c 花剑影
// zly 7/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("花剑影", ({"Hua jianying", "hua", "jianying"}));
	set("title", HIY"太岳四侠"NOR);
	set("nickname", "流星赶月");
        set("shen_type", 1);
	set("gender", "男性");
	set("age", 36);
	set("long", 
"这人看起来中等身材，白净脸皮，若不是一副牙齿向外出了一寸
，一个鼻头低陷了半寸，倒算得上是一位相貌英俊的人物，他手中拿
的是一对流星锤。\n"
	);

	set("attitude", "aggressive");
        set("vendetta/authority",1);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("max_qi", 34000);
	set("max_jing", 33000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 200);
	set("combat_exp", 9800000);
	set("score", 400000);
	set_skill("unarmed",300);
	set_skill("hammer",280);
	set_skill("tiexue-hammer",320);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 320);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 320);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 180);
	set_skill("literate", 100);
	set_skill("axe", 280);
	set_skill("duanyun-fu", 350);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 350);
	set_skill("tongbi-zhang", 350);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
        }) );

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/liuxing-chui")->wield();
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
 who->set_temp("book143",1);
message_vision("$N说道：萧中慧的事我知道了，我这就去帮她！\n" NOR,this_object());	
	call_out("leavet",1);
}

void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外跳去！\n" NOR,this_object());
        destruct(this_object());
}