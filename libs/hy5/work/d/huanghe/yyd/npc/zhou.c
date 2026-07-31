// zhou.c 周威信
// modified by zly 6/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("周威信", ({"zhou weixing", "weixing", "xing"}));
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

	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 8500);
	set("max_neili", 8500);
	set("jiali", 100);
	
	set("combat_exp", 2500000);
	

set_skill("literate", 260);
	set_skill("force", 260);
	set_skill("dodge", 260);
	set_skill("unarmed", 260);
	set_skill("parry", 260);
	set_skill("whip", 300);
	set_skill("blade", 300);
	set_skill("sword", 300);
	set_skill("hand", 260);
	set_skill("claw", 300);
	set_skill("cuff", 300);
	set_skill("strike", 300);
	set_skill("houquan", 390);
	set_skill("yunlong-xinfa", 220);
	set_skill("yunlong-shengong", 220);
	set_skill("wuhu-duanmendao", 220);
	set_skill("yunlong-jian", 220);
	set_skill("yunlong-shenfa", 220);
	set_skill("yunlong-bian", 220);
	set_skill("yunlong-shou", 220);
	set_skill("yunlong-zhua", 220);
	set_skill("baihua-cuoquan", 220);
set_skill("bazhen-zhang", 220);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "baihua-cuoquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "baihua-cuoquan");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	map_skill("cuff", "baihua-cuoquan");
	map_skill("strike", "bazhen-zhang");
	
	prepare_skill("cuff", "baihua-cuoquan");
	prepare_skill("strike", "bazhen-zhang");
//	prepare_skill("unarmed","baihua-cuoquan");

	set("env/wimpy", 60);
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({

                (: perform_action, "whip.chan" :),
                (: perform_action, "cuff.hong" :),
                (: perform_action, "cuff.luan" :),
                (: perform_action, "cuff.yi" :),                	                	
                                
                (: perform_action, "strike.bafang" :),
                (: perform_action, "strike.baxianzuijiu" :),
                (: perform_action, "strike.jueming" :),                	                	


                (: perform_action, "claw.ji" :),
                (: perform_action, "claw.ningxue" :),
	}) );

	set("chat_chance", 3);
	set("chat_msg", ({
	"在下道经贵地，没跟朋友们上门请安，甚是失礼，要请好朋友恕罪。\n"
	"周威信轻声说：“江湖上有言道：忍得一时之气，可免百日之灾”。 \n",
	"周威信低声道: “江湖上有言道：容情不动手，动手不容情”。\n",
        "周威信小声道：“江湖上有言道：只要人手多，牌楼抬过河”。\n",
	}));   
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changbian")->wield();

} 


