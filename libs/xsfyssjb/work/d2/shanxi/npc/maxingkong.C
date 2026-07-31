inherit NPC;
#include <ansi.h>
int wieldblade();

void create()
{
    set_name("马行空", ({ "ma xingkong", "ma"}) );
    set("nickname", HIW "云里神龙"NOR);
    set("title","关中联营镖局 总镖头");
    set("gender", "男性" );
    set("class","shaolin");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 45);
    set("per", 15);
    set("agi", 300);
    set("str", 500);
    set("int",30);
    set("ill_boss",5);
    set("attitude","friendly");
    set("max_force", 3000);
    set("force", 3000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    
    set("long", "
马行空在武林中享名已很久，手上的功夫也不错，并不是那种徒有盛名的人，\n但现在声音里却总带着种说不出的馅媚讨好之意。\n");
    
    
    
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       // (: perform_action, "unarmed.qianshouqianbian" :),
        (: wieldblade  :),

        //(: perform_action, "dagger.pingshuixiangfeng" :),
             }) );
             
    set("combat_exp", 5000000);
    set("chat_chance", 1);
    set("chat_msg", ({
                "马行空伸手往腰上一探，已亮出了一条"+MAG"鱼鳞紫金滚龙棒"NOR+"，迎风一抖伸得笔直。\n",
            }) ); 
    

    set_skill("dagger", 150);
    set_skill("move", 160);
    set_skill("parry",120);
    set_skill("dodge", 120);
    set_skill("force", 180);
    set_skill("literate", 100);
    set_skill("unarmed",999);
    set_skill("henglian",999);

    set_skill("iron-cloth",999);
    set_skill("dabei-strike",999);
    set_skill("puti-steps",120);
    set_skill("fumostaff",20);
    set_skill("xiaochengforce",200);

    map_skill("iron-cloth", "henglian");
    map_skill("dodge", "puti-steps");
    map_skill("move", "puti-steps");
    map_skill("force", "xiaochengforce");
    map_skill("unarmed", "dabei-strike");

    map_skill("dagger","fumostaff");
    map_skill("parry","fumostaff");

   setup();
   carry_object(__DIR__"obj/dragonstaff")->wield();
   carry_object("/d/fugui/npc/obj/m_cloth1")->wear(); 
} 
int wieldblade()
{
command("unwield all");
perform_action("unarmed.qianshouqianbian");
command("wield staff");
return 1;
}
