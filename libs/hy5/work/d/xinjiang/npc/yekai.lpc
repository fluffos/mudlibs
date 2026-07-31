 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("叶开", ({ "ye kai", "ye", "kai" }) );
        set("gender", "男性" );
        set("nickname","不带刀的人");
        set("age", 24);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("reward_npc", 1);
        set("difficulty", 50);
        set("max_qi",100000);
        set("max_jing",100000);
        set("max_sen",100000);
        set("int", 30);
        set("per", 30);
        set("attitude","friendly");
        set("max_neili", 15000);
        set("neili", 15000);
        set("courage",1000);
        set("force_factor", 3);
        set("long","一个眼睛大大的青年人，手指细长，皮肤白腻。\n");
        create_family("风云一刀", 3, "人杰");
        set("combat_exp", 10000000);
        set("score", 200000); 
        set("chat_chance", 3);
        set("chat_msg", ({
                "叶开叹口气，呆呆地望着鞋底的大洞。\n",
                "叶开道：我从来都是救人的，从不害人。\n",
        }) );
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("throwing", 300);
        set_skill("feidao", 220);
        set_skill("force", 40);
        set_skill("literate", 200);
        map_skill("throwing", "feidao");
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
