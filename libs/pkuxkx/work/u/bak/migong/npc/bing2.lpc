#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG"蒙古兵"NOR, ({ "menggu bing","bing"}));
        set("gender", "男性");
	set("long", "一个满脸横肉的家伙。\n");
        set("age", 36);
        set("attitude", "aggressive");
        set("shen", 0);
        set("str", 28);
        set("int", 20);
        set("con", 25);
        set("dex", 27);

        set("max_qi", 1200);
        set("max_jing", 1500);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 20);
        set("combat_exp", 1100000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.diezhang" :),
         }));
         set_skill("force", 100);
         set_skill("xuantian-wuji", 220);
         set_skill("dodge", 120 + random(30));


        set_skill("kunlun-shenfa", 180);
        set_skill("strike", 120 + random(30));
        set_skill("kunlun-zhang", 200 + random(30));
        set_skill("parry", 190);
        set_skill("literate", 80);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "kunlun-zhang");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 70);
        prepare_skill("strike", "kunlun-zhang");

        setup();
        carry_object("/d/migong/obj/dan2");
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", random(200));
}
