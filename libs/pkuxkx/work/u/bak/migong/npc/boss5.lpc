#include <ansi.h>
inherit NPC;

void create()
{
        set_name("小元帅", ({ "xiao yuanshuai","yuanshuai"}));
        set("gender", "男性");
	 set("long", "他看起来威风凛凛，满脸杀气。\n");
        set("age", 36);
        set("attitude", "aggressive");
        set("shen", -80000);
        set("str", 28);
        set("int", 20);
        set("con", 25);
        set("dex", 27);

        set("max_qi", 3500);
        set("max_jing", 1500);
        set("neili", 3800);
        set("max_neili", 3800);
        set("jiali", 100);
        set("combat_exp", 2700000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.diezhang" :),
         }));
         set_skill("force", 250);
         set_skill("xuantian-wuji", 300);
         set_skill("dodge", 250 + random(30));


        set_skill("kunlun-shenfa", 260);
        set_skill("strike", 250 + random(30));
        set_skill("kunlun-zhang", 270 + random(30));
        set_skill("parry", 140);
        set_skill("literate", 80);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "kunlun-zhang");
        set_temp("apply/attack", 50);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 110);
        prepare_skill("strike", "kunlun-zhang");

        setup();
	
	  carry_object("/d/migong/obj/shen_dan5");
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", random(4));
}
