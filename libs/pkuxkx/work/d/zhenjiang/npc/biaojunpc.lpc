// bj

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("张经",({ "zhang jing", "zhang", "jing" }) );
        set("gender", "男性" );
        set("title",HIC"飞龙镖局 "+NOR+"总镖头"+NOR);
        set("age", 40+random(20));
        set("long", "这是个外家高手，一看就不好惹。\n");
		set("str", 1);
        set("dex", 1);
        set("con", 1);
        set("int", 1);
		set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 1);
        set("attitude", "peaceful");
        set_skill("sword", 250);
        set_skill("parry",250);
        set_skill("dodge", 250);
        set_skill("force",250);
        set_skill("literate",250);
        set_skill("taiyi-zhang",250);
        set_skill("strike",250);
        set_skill("taiyi-jian",250);
        set_skill("taiyi-shengong",250);
        set_skill("taiyi-you",250);
        

        map_skill("parry","taiyi-zhang");
        map_skill("sword","taiyi-jian");
        map_skill("force","taiyi-shengong");
        map_skill("dodge","taiyi-you");
        map_skill("strike","taiyi-zhang");

        
        prepare_skill("strike","taiyi-zhang");
        setup();
        add_money("silver", 20+random(8)*10);
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
