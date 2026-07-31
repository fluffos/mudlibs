// /NPC 蒙面女郎

#include <ansi.h>

inherit NPC;
int auto_perform();
void create()
{
	set_name("蒙面女郎", ({ "nv lang", "nv"}));
	set("long",
	    "这是个身材娇好的女郎, 轻纱遮面,\n"
	    "一双秀目中透出一丝杀气。\n"
	   );
	set("gender", "女性");
	set("age", 20);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 500000);
	set("score", 100000);
	set_skill("force", 170);
	set_skill("dodge", 170);
	set_skill("parry", 170);
	set_skill("hand",170);
	set_skill("strike", 170);
	set_skill("sword",170);
	set_skill("literate",170);
	set_skill("music",170);

	set_skill("zhemei-shou",170);
	set_skill("liuyang-zhang",170);
	set_skill("tianyu-qijian",170);
	set_skill("yueying-wubu",170);
	set_skill("bahuang-gong", 170);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/heiyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",15);
}

#include "/kungfu/class/lingjiu/auto_perform.h"