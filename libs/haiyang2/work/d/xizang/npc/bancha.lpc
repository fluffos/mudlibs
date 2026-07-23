#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("班察巴那", ({ "bancha bana","bancha" }) );
        set("gender", "男性" );
        set("long",
                "他的衣着依旧鲜明华丽，看来如同天神般英俊威武。\n"
                );
        set("title", "圣母峰下 第一勇士");
        set("nickname", HIY "五花箭神"NOR);
        set("attitude", "peaceful");

        set("age", 38);
        set("str", 80);
        set("int", 55);
        set("con", 55);
        set("dex", 85);
        set("combat_exp", 8500000);
        
        set("max_qi", 25000);
        set("max_jing", 25000);
        set("max_jing", 25000);
        
        set("max_neili", 30000);
        set("neili", 30000);
        set("jiali", 50);
        set_temp("apply/damage", 200); 
        
        set_skill("dodge", 380);
        set_skill("unarmed", 380);
        set_skill("throwing", 380);
        set_skill("unarmed", 300);
        set_skill("parry", 300);
        set_skill("throwing", 300);
        set_skill("xuanyuan-arrow", 380);
        set_skill("changquan", 380);
        set_skill("lingxu-bu", 380);
        map_skill("dodge", "lingxu-bu");
        map_skill("parry", "changquan");
        map_skill("throwing", "xuanyuan-arrow");
        map_skill("unarmed", "changquan");        
      set_skill("unarmed", 300);
        set_skill("hammer", 350);
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("literate", 300);
	set_skill("dodge", 300);

	set_skill("pangu-hammer", 350);
	set_skill("pofeng-strike", 320);
	set_skill("putiforce", 350);
	set_skill("nodust-steps", 300);

	map_skill("unarmed", "pofeng-strike");
        map_skill("hammer", "pangu-hammer");
        map_skill("force", "putiforce");
        map_skill("parry", "pangu-hammer");
        map_skill("dodge", "nodust-steps");
	      set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luanpofeng" :),
                (: perform_action, "hammer.kaitianpidi" :),
        }) );
	set_skill("magic",100);
        set_temp("apply/attack", 200);
        set_temp("apply/defence", 200);
        set_temp("apply/damage", 380);
        set_temp("apply/armor", 380);
        setup();
        carry_object("/clone/master/obj/jumbohammer")->wield();
        carry_object(__DIR__"obj/arrow");        
        carry_object("/clone/misc/cloth")->wear();
       add_money("silver",5);
//carry_object("/d/mingjiao/yuan/obj/arrow")->wield();
} 
int accept_fight(object me)
{
        if(me->query("combat_exp") > 500000)
        {
            command("say 好,看你似乎有点能耐,来,和我过几招!\n");
                return 1;
        }
        else
        {
            command("say 就你?无端弄脏了我的五花神箭!\n");
                return 0;
        }
} 
void win_enemy(object loser)
{
        command("say 想跟我斗，你还差的远呢！\n");
}
void lose_enemy(object winner)
{
        command("say 你本事不错，我口服心服。\n");
        winner->set_temp("marks/won_bancha",1);
}  
