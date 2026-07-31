// mawude.c 马五德

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("马五德", ({ "ma wude", "ma", "wude" }) );
	set("gender", "男性");         
        set("title", "滇南普洱老武师");
        set("age", 65);
	set("long","马五德是大茶商，豪富好客，颇有孟尝之风。\n");
        set("combat_exp", 200000);
        set("shen_type", 1);
	set("attitude", "peaceful");
        set("unique", 1);

        set("str", 28);
        set("con", 26);
	set("int", 20);
	set("dex", 24);
        set("per", 13);

        set("max_qi", 800);
        set("max_jing", 500);
        set("neili", 800);
        set("eff_jingli", 500);
        set("max_neili", 800);
       
        set_skill("force", 80);  
        set_skill("yijin-jing", 80);
        set_skill("sword", 80);
        set_skill("dodge", 80);
        set_skill("strike", 80);
        set_skill("cuff", 80);
        set_skill("weituo-zhang", 80);
        set_skill("parry", 80);
        set_skill("luohan-quan",80);
        set_skill("shaolin-shenfa", 80);
        map_skill("parry", "luohan-quan");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("force","yijin-jing");
        map_skill("strike", "weituo-zhang");
        prepare_skill("strike", "weituo-zhang");
        prepare_skill("cuff", "luohan-quan");

	setup();
        carry_object("/clone/misc/cloth")->wear();
}
