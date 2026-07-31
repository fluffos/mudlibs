// lan.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("蓝凤凰", ({ "lan fenghuang", "lan", "fenghuang"}));
        set("long", "这女子肌肤微黄，双眼极大，黑如点漆。\n"+
        	    "她掌管日月教在苗疆的下属“五毒教”，使毒手法诡秘奇特，令人防不胜防。\n");
        set("title",HIY"日月神教  "HIR"五毒圣姑"NOR);
        set("gender", "女性");
        set("age", 23);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("per", 25);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 2800);
        set("max_jing", 1600);
        set("eff_jingli", 1600);
        set("jiali", 50);
        set("combat_exp", 1500000);

        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("force", 180);
        set_skill("strike", 180);
        set_skill("literate", 100);
        set_skill("ding-dodge", 180);        
        set_skill("huntian-qigong", 180);
        set_skill("zhusha-zhang", 180);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "huntian-qigong");
        map_skill("parry", "zhusha-zhang");
        map_skill("strike", "zhusha-zhang");
        prepare_skill("strike", "zhusha-zhang");
        
	create_family("日月神教",3,"第子");
       	setup();
	carry_object(MISC_D("cloth"))->wear();        
}
