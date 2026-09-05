#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIC"蒙古兵"NOR, ({ "menggu bing","bing"}));
        set("gender", "男性");
	set("long", "一个满脸横肉的家伙。\n");
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
        set("jiali", 50);
        set("combat_exp", 2600000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.diezhang" :),
         }));
         set_skill("force", 250);
         set_skill("xuantian-wuji", 250);
         set_skill("dodge", 250 + random(30));


        set_skill("kunlun-shenfa", 260);
        set_skill("strike", 250 + random(30));
        set_skill("kunlun-zhang", 250 + random(30));
        set_skill("parry", 140);
        set_skill("literate", 80);
        map_skill("force", "xuantian-wuji");
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "kunlun-zhang");
        set_temp("apply/attack", 50);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 100);
        prepare_skill("strike", "kunlun-zhang");

        setup();
        carry_object("/d/migong/obj/dan5");
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", random(4));
}
