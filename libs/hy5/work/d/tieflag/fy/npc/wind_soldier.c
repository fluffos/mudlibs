#include <ansi.h>
inherit NPC;
// inherit PURSURER; 
void create()
{
        set_name("风兵", ({ "fengyun garrison", "garrison" }) );
        set("long","
这是个正在执行守城任务的风兵，虽然和许多武林人物比起来，风兵们的
武功实在平常，但他们是有组织、有纪律的战士，谁也不轻易地招惹他们。\n"
"你最好也不要招惹他们。 \n"); 
        set("attitude", "heroism");
        set("pursuer", 1);
        set("vendetta_mark", "authority");
        set("cor", 40);
        set("cps", 2);
        set("combat_exp", 1000000+random(2000000));
        
        set("max_qi",30000);
        set("max_sen",30000);
        set("max_jing",30000);
        
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "风兵喝道：还不快放下武器束手就缚？\n",
                "风兵喝道：大胆刁民竟敢拒捕？反了！反了！\n",
                (: perform_action, "spear.suomengchanhun" :),
        }) ); 
     	set("max_qi", 32000);
	set("jing", 3800);
	set("max_jing", 3800);
	set("neili", 32000);
	set("max_neili", 32000);
	set("jiali", 200);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set("shen", 100000);
	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // 基本内功
	set_skill("huntian-qigong", 330);    // 混天气功
	set_skill("dodge", 150);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 320);        // 逍遥游
	set_skill("parry", 150);             // 基本招架
	set_skill("hand", 200);              // 基本手法

	set_skill("blade", 180);             // 基本刀法
	set_skill("liuhe-dao", 280);       // 四象六合刀
	set_skill("begging", 200);           // 叫化绝活
	set_skill("checking", 200);          // 道听途说
	set_skill("training", 200);          // 驭兽术
	set_skill("strike",285);  // 基本掌法

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // 打狗棒法
	set_skill("suohou-gong", 380);        // 打狗棒法
set_skill("chansi-shou", 380);        // 打狗棒法
set_skill("claw", 380);        // 打狗棒法
set_skill("hand", 380);        // 打狗棒法	
set_skill("club", 380);        // 打狗棒法		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");

       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: command("unwield yuejia qiang") :),
                (: command("wield yuejia qiang") :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100); 
        set("resistance/kee",99);
        set("resistance/gin",99);
        set("resistance/sen",99);
        
        setup(); 
        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/spear")->wield();
} 
int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 500000 ) {
                        say("风兵呵呵的笑道：好说，好说...\n");
                        who->set("vendetta/authority", 0);
                        who->remove_all_killer();
                        this_object()->command("follow none");
                        return 1;
                } else {
                    say("风兵说道：这点钱还不够大爷喝酒的呢！\n");
                        return 0;
                }
        return 0;
}  
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        if(userp(victim)&& victim!=player)
        {
            message_vision(HIW"$N对著$n喝道：大胆狂徒,竟敢在闹市杀人,还不快快束手就缚!\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
}  
int heal_up()
{
        if(environment() && !is_fighting() 
                && query("startroom") 
                && file_name(environment()) != query("startroom")) {
//              command("say ok");
                return_home(query("startroom"));
                return 1;
        }
        return ::heal_up() + 1;
}        
