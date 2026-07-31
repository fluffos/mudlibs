inherit NPC;
#include <ansi.h>

void create()
{
	set_name("克林顿", ({"shabi"}));
	set("nickname", HIR "你又能把我怎么样...." NOR);
	set("long", HIC "\n这是个男人,裤子掉到脚碗上,穿着个红色的拳击短裤,嘴里老是嘟嘟囔囔的.\n" NOR);
	set("gender", "男性");
	set("age", 51);
	set("qi", 8000);
	set("max_jing", 200);
	set("neili", 0);
	set("max_neili", 0);
	set("jiali", 0);
	set("inmortal",1);
	set("attitude", "friendly");
	set("combat_exp", 2000);
	set("str", 5);
	set("int", 5);
	set("con", 5);
	set("dex", 5);
	set("env/wimpy", 90);
	set("inquiry", ([
		"克林顿"   : "嘿嘿,老子就是",
		"中国"     : "中国是豆腐,好吃的很",
                        "china"	:  "小case,我要它东不敢向西",
                        "莱温斯基"    :  "小美人,不过胖了点,但是够骚",
                       
	]) );
	set("chat_chance", 3);
		set("chat_chance_combat", 20);  
	set("chat_msg_combat", ({
		"中国没有民主!美国最人道\n",
	(: command("chat 莱温斯基真够劲!\n") :),
	(: command("chat 真五聊。\n") :),
	(: command("grin") :),
	(: command("hehe") :),
	(: command("chat 天下我最大,你们能把我怎么样?\n") :),
	(: command("chat 你这" + RANK_D->query_rude(this_player())+"能把我怎么样,小心我用炸弹炸你?\n") :),
	       
 	}) );
	setup();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}
