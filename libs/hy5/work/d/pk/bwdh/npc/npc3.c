// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// 岳不群
// 此npc上的xunshan设置不当！
// 星星lywin改于2000/6/11

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
int do_xunshan();
string ask_me();
string ask_feng();

void create()
{
        set_name("小岳不群", ({ "yue buqun", "yue" }) );
        set("title", "华山派掌门");
        set("nickname", "君子剑");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "岳不群自幼执掌华山派，乃当今武林中一等一的高手。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 14400);
        set("max_neili", 14400);
        set("jiali", 50);
        set("max_qi",8200);
        set("max_jing",5200);

        set("combat_exp", 1400000);
        set("shen", -200000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.feilong" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
	    "宁中则" : "她是我夫人。\n",
	    "岳灵姗" : "她是我女儿。\n",
	    "紫霞功" : "那是本门至高无上的内功心法。\n",
	    "紫霞神功" : "那是本门至高无上的内功心法。\n",          
	    "思过崖" : "那是本派弟子修行思过之处。\n", 
        ]) );

        set_skill("unarmed", 80);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 200);
        set_skill("zixia-shengong", 200);
        set_skill("huashan-ken", 200);
        set_skill("feiyan-huixiang", 200);
        set_skill("pixie-sword",80);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("华山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/book/zixia_book");
        carry_object(__DIR__"obj/badan");
}
