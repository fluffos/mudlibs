 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void healing(); 
void create()
{
        set_name("欧阳朔", ({ "ouyang shuo" }) );
        set("gender", "男性" );
        set("age", 39);
        set("title", MAG"紫电青霜阁主人"NOR);
        set("long",
                "一个穿戴整齐的中年人，举止谈吐优雅。\n");
        set("combat_exp", 2500000);
        set("attitude", "friendly");
        set("class","beggar");
        set("per",30); 
        set("force",1800);
        set("max_neili",1800);
        set("force_factor",80);
        set("str",36);
        	set("vendor_goods", ({
        __DIR__"obj/shuangyi",
        __DIR__"obj/dragonsword",
        __DIR__"obj/dragonwhip",
        __DIR__"obj/fengblade",
        __DIR__"obj/duanshan",
        __DIR__"obj/meispear",  
        __DIR__"obj/pilihammer",    
	}));

        
        

        set_skill("dodge",140);
        set_skill("parry",140);
        set_skill("unarmed",140);

        

        
        setup();
        carry_object(__DIR__"obj/oucloth")->wear();
} 
void init()
{

	add_action("do_buy", "buy");
	add_action("do_list", "list");
        ::init();
}  

