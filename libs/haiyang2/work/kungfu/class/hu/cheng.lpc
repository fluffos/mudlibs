// cheng.c

#include <ansi.h>;

inherit NPC;


void create()
{
        set_name("程灵素", ({ "cheng lingsu", "cheng" }));
        set("gender", "女性");
        set("age", 24);
        set("long", @long
她看上去双眉紧缩，不知道有什么心事，长得相貌平平，并不出众。
身材瘦小，穿着粗布衣衫。
long);
        set("attitude", "peaceful");
        set("str", 22);
        set("int", 35);
        set("con", 31);
        set("dex", 27);
        set("chat_chance", 10);
        set("chat_msg", ({
                "程灵素哀哀的叹了口气。\n",
        }));

        set("qi", 2500);
        set("max_qi", 2500);
        set("jing", 1200);
        set("max_jing", 1200);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 40);
        set("combat_exp", 400000);
     
        set_skill("force", 150);
        set_skill("duji", 270);
        set_skill("poison", 270);
        set_skill("miaoshouhuichun", 270);

        set("inquiry",([
                "胡斐":     "他...他...\n",
                "袁紫衣":   "我...你提他干什么？\n",
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

