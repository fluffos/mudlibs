 // waiter.c
inherit NPC;
#include <ansi.h>
inherit F_VENDOR;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
        set_name("八月初八", ({ "devil waiter","waiter" }) );
        set ("nickname",HIR"人厨"NOR);
        set ("title","青龙会 分舵舵主");
        set("gender", "男性" );
        set("age", 52);
        set("long",
        "没有人知道个人的来历，在青龙地城中甚至连七月十五的舵主都忌惮他三分，\n也没有知道他姓什么，只知道他是八月初八分舵之中的唯一的一个活人\n，而在他手里，也只有供他宰杀烧烹的死人。\n");
        set("attitude", "friendly");
        
        set("combat_exp", 4000000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 2);
        
        set("class","bat");
        set("force",1000);
        set("max_neili",1000);
        set("force_factor",50);
        
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("blade",150);
        set_skill("bat-blade",500);
        set_skill("meng-steps",150);
        set_skill("move",200);
        set_skill("blade",150);

        
        map_skill("dodge","meng-steps");
        map_skill("move","meng-steps");
   map_skill("blade","bat-blade");
        map_skill("parry","bat-blade");

        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
        "八月初八舔了舔屠刀上的血迹，挽了挽袖子，喃喃道：人肉包似乎没料了，\n该去弄些新鲜的才是。。\n",
        "八月初八眯缝着眼睛盯了你一眼，夜枭般怪笑道：新鲜出笼的人肉包啊，\n嘿嘿，滋味不错呦。\n",
        }) ); 
        set("rank_info/respect", "人厨");

        
        	set("vendor_goods", ({
		__DIR__"obj/renroubao",
		__DIR__"obj/bloodleg",
	}));
        setup();
        
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/butcherknife")->wield();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
                else add_money("gold", random(4));
} 
void init()
{       
        object ob;
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}   
