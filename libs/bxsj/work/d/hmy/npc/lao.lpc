// lao.c
#include <ansi.h>

inherit NPC;

void create()
{
      
	set_name("老头子", ({ "lao touzi", "lao", "touzi",}));
	set("nickname", "黄河老祖");        
        set("long", "此人身材极之肥胖，远看有如一大肉球般，可身法却极之轻灵，动作如闪电般迅速。\n");
        set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen", 10000);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 40);
        
        set("max_qi", 2300);
        set("max_jing", 1400);
	set("eff_jingli", 1400);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("shen", -4000);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

        set_skill("tianmo-jian",150);
	set_skill("sword", 150);
        set_skill("dodge",150);
	set_skill("ding-dodge", 150);
	set_skill("force", 150);
	set_skill("literate", 100);
	set_skill("tianmogong", 150);
	set_skill("tianmo-zhang", 150);
	set_skill("strike", 150);
	
	map_skill("parry", "tianmo-jian");
        map_skill("sword", "tianmo-jian");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");
        map_skill("strike", "tianmo-zhang");
        prepare_skill("strike", "tianmo-zhang");

        setup();
 
	carry_object(BINGQI_D("panguanbi"))->wield();
	carry_object("/clone/misc/cloth")->wear();        
}
