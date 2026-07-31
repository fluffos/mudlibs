// zu.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("祖千秋", ({ "zu qianqiu", "zu",}));
        set("nickname","黄河老祖");
        set("long", 
"只见他面皮焦黄，双目无神，疏疏落落有几根
胡子，身材颇瘦削，却挺着个大肚子。\n");
        set("age", 80);        
        set("gender", "男性");
        set("attitude", "peaceful");
        set("shen", -10000);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 1800);
	set("qi", 1800);
	set("jing", 1300);
        set("max_jing", 300);
        set("neili", 700);
        set("max_neili", 2400);
	set("neili", 2400);
	set("eff_jingli", 700);
	set("jingli", 700);
        set("jiali", 50);
        set("combat_exp", 200000);
        set("shen", -2000);

	set_temp("apply/attack", 40);
	set_temp("apply/defence", 40);

        set_skill("tianmo-zhang",110);
	set_skill("strike", 110);
        set_skill("dodge",110);
	set_skill("ding-dodge", 110);
	set_skill("parry", 110);
	set_skill("force", 110);
	set_skill("literate", 100);
	set_skill("tianmogong", 110);

        map_skill("strike", "tianmo-zhang");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");
	map_skill("parry", "tianmo-zhang");
	prepare_skill("strike", "tianmo-zhang");
        setup();
	carry_object("/clone/misc/cloth")->wear();
}
