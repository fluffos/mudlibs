
inherit NPC;
#include <ansi.h>;
int ask_me();

void create()
{
        set_name("岳不群", ({ "yue buqun", "yue" }) );
        set("title", "华山派掌门");
        set("nickname", "君子剑");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
        set("long",
                "岳不群自幼执掌华山派，乃当今武林中一等一的高手。\n");
        set("attitude", "peaceful");
        set("str", 56);
        set("con", 50);
        set("dex", 50);
        set("int", 58);

        set("neili", 100000);
        set("max_neili", 100000);
        set("jiali", 50);
        set("max_qi",100000);
        set("max_jing",100000);

        set("combat_exp", 8000000);
        set("shen", 20000);
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
        set("inquiry", ([
	    "比武" : (: ask_me :),
        ]) );

        set_skill("unarmed", 400);
        set_skill("sword", 400);
        set_skill("force", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("literate", 200);
        set_skill("huashan-sword", 400);
        set_skill("zixia-shengong", 400);
        set_skill("hunyuan-zhang", 400);
        set_skill("poyu-quan", 400);
        set_skill("feiyan-huixiang", 400);
        set_skill("pixie-sword",400);
        set_skill("zhengqijue",400);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        create_family("华山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int ask_me()
{
	object me = this_player();
	message_vision("$N说道：无名小辈也敢来挑战五岳剑派，好，就让你见识见识华山剑法！\n",this_object());
	me->set_temp("jinyong/book8/wuyue_huashan",1);
	return 1;
}

void unconcious()
{
	die();
}
void die()
{
	message_vision("$N说道：今日败于你手，我无话可说，改日请上华山另行赐教。\n" NOR,this_object());
	destruct(this_object());
}