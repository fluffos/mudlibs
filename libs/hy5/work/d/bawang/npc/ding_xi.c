 inherit NPC;
#include <ansi.h> 
void init();
int do_killing(string);
int accept_object(object,object);
void create()
{
        set_name("丁喜", ({ "ding xi", "xi","dingxi" }) );
        set("gender", "男性" );
        set("title", HIG "花喜鹊"NOR);
        set("age", 20);
        set("int", 30);
        set("per", 30);
        set("class","wolfmount");
        if (random(3)) set("attitude","friendly");
        set("long",
                "他总是很随和，很自信。嘴边总是带着自信的微笑。\n人们总是称他“讨人喜欢的丁喜”或者“聪明的丁喜”\n"
                );
        set("max_neili", 2000);
        set("force", 2000);
        set("force_factor", 50);
        set("cor",200);
        set("combat_exp", 3000000);
        set("score", 90000);
        set("resistance/kee",40);
        set("resistance/gin",40+random(50));
        set("resistance/sen",40);
        
     set_skill("strike",270);
        set_skill("finger",270);
        set_skill("dodge",280);
        set_skill("force", 270);
	set_skill("canhe-zhi", 300);
	set_skill("murong-jianfa",250);       
        set_skill("shenyuan-gong", 250);
	set_skill("yanling-shenfa", 250);   
	set_skill("xingyi-zhang",280);
        set_skill("douzhuan-xingyi", 280);
	set_skill("parry", 280);
	set_skill("sword", 260);
	set_skill("literate", 280);
        set_skill("murong-daofa", 280);
        set_skill("blade",260);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");
         map_skill("strike", "xingyi-zhang");
	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                 (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.qixing" :),
 		(: command("unwield sword") :),
		(: command("wield sword") :),           
                (: perform_action, "dodge.yanling" :),                
                   (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/shortsword")->wield();
} 
void init()
{
        add_action("do_killing", "kill");
        ::init();
} 
int do_killing(string arg)
{
        object player, victim;
        string name;
        player = this_player();
        if( !arg) return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = (string)victim->name();
                if( (string)name == "王若兰")
                {
                        message_vision("$N冷冷地道：“看来我是不动手不行了。”\n", this_object());
                        this_object()->kill_ob(player);
                        player->kill_ob(this_object());
                        return 1;
                }
                else if((string)name == "归东景")
                {
                        if(!player->query("m_success/杀归东景"))
                        {
/*                              message_vision( HIM "在这电光火石的一瞬，你眼前一花，只见归东景心口处已经多了一个血洞！ 
归东景目瞪口呆地看着自己的伤口，又看了看丁喜，道：“你好快的身手......”
言未迄，他已倒在地上。
原来是$N趁归东景分神之际，不知用了什么手法，将其击倒。\n"NOR,this_object());
                           victim->die();          */
// adjusted by silencer, let player 付出一点劳动，不要完全让丁喜代劳。                          
                        message_vision( HIM "在这电光火石的一瞬，你眼前一花，只见归东景肩口处已经多了一个血洞！ 
归东景目瞪口呆地看着自己的伤口，又看了看丁喜，道：“你好快的身手......”
言未迄，他已摇摇欲坠。
原来是$N趁归东景分神之际，不知用了什么手法，击中了他。\n"NOR,this_object());    
                                victim->set("qi",victim->query("max_qi")/2);
                                victim->set("eff_qi",victim->query("qi"));
                                player->add("score",100);
                                player->add("combat_exp",500);
                                player->set("m_success/杀归东景",1);
                        }
                }
        }
        return 0;               
}
