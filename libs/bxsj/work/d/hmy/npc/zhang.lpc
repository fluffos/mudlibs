// zhang.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("张夫人", ({ "zhang furen", "zhang", "furen"}));
        set("long", "这女子肌肤微黄，双眼极大，黑如点漆。\n"+
		"她掌管日月教在苗疆的下属“五毒教”，使毒手法诡秘奇特，令人防不胜防。\n");
        set("gender", "女性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 700);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen", -1000);

        set_skill("huntian-qigong",100);
        set_skill("ding-dodge",100);
        set_skill("parry",100);        
        set_skill("force",100);
        set_skill("dodge",100);
        set_skill("tianshan-zhang", 100);
        set_skill("staff", 100);
        set_skill("strike", 100);
        set_skill("literate", 80);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "huntian-qigong");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
        setup();

	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();        
}
