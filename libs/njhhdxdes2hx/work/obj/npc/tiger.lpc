// tiger.c
inherit NPC;

void create()
{
        set_name("吊睛白额大虫", ({ "tiger" }) );
        set("race", "野兽");
        set("age", 30);
        set("long", @LONG
这是一只吊睛白额大虫，金黄的毛皮上有着黑褐色的斑纹，额头上一片白绒
隐约有一斗大的王字，湛蓝色的眼睛向斜上方吊起，眼中散发着凶猛的光芒。
LONG
);

        set("attitude", "aggressive");

        set("kee", 1000);
        set("max_kee", 1000);
                
        set("gin", 1000);
        set("max_gin", 1000);
        set("sen", 1000);
	set("max_sen", 1000);
        
        set("combat_exp", 1000000);
        set("limbs", ({ "头部", "身体", "尾巴","前脚", "後脚"}) );
        set("verbs", ({ "bite","claw" }) );
	set("str",30);
	set("cor",30);
	set("corpse_ob", "/d/hua/obj/dead_tiger");
	set("chat_chance", 80);
	set("chat_msg_combat", ({
		"老虎一声长啸向你扑来!\n",
		"老虎尾巴猛的一甩，向鞭子一样啪啪作响!\n",
	}));
	set("marks/虎皮", 1);        
        set_temp("apply/attack", 20);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 5);
        setup();
}

            
