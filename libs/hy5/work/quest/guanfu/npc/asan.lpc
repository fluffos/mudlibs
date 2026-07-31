//  asan阿三
 
inherit NPC;
 
void create()
{
	set_name("阿三", ({ "a san", "a" }));
//	set("nickname", "");
	set("long", 
        "金刚门的高手，一身外功出神入化，出手极其狠毒。\n");
	set("gender", "男性");
	set("age", 46);
	set("attitude", "peaceful");
	set("shen", -10000);
	set("str", 30);
	set("int", 35);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 6500);
	set("max_jing", 6500);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 120);
	set("combat_exp", 1400000+random(900000)); 
	 
	set_skill("force", 165);
	set_skill("hunyuan-yiqi", 365);
	set_skill("dodge", 85);
	set_skill("shaolin-shenfa", 365);
	set_skill("hand", 90);
	set_skill("fengyun-shou", 360);
	set_skill("parry", 165);
	set_skill("buddhism", 165);
	set_skill("literate", 165);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "fengyun-shou");

	prepare_skill("hand", "fengyun-shou");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}
#include "/quest/guanfu/npc/npc.h"
