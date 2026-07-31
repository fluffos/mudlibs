// zhou.c 周威信
// modified by zly 6/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("周威信", ({"zhou", "weixing", "xing"}));
	set("title", "威信镖局的总镖头");
	set("nickname", "铁鞭镇八方");
        set("shen_type", -1);
	set("gender", "男性");
	set("age", 58);
	set("long", 
		"这个老头，便是天下知名陕西西安府威信镖局的总镖头，但看起来一点都不显眼。\n"
		"他左手按着腰间铁鞭，紧惕地看着四周。\n"
	);

	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	
	set("combat_exp", 150000);
	
	set_skill("force", 200);		
	set_skill("huntian-qigong", 200);	
	set_skill("dodge", 200);			
	set_skill("xiaoyaoyou", 200);		
	set_skill("parry", 200);			
	set_skill("whip", 200);		
	set_skill("yunlong-bian", 200);
		
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "yunlong-bian");
        map_skill("whip","yunlong-bian");
	set("chat_chance", 3);
	set("chat_msg", ({
	"在下道经贵地，没跟朋友们上门请安，甚是失礼，要请好朋友恕罪。\n"
	"周威信轻声说：“江湖上有言道：忍得一时之气，可免百日之灾”。 \n",
	"周威信低声道: “江湖上有言道：容情不动手，动手不容情”。\n",
        "周威信小声道：“江湖上有言道：只要人手多，牌楼抬过河”。\n",
	}));   

} 


