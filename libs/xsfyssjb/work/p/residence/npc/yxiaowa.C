 // banker.c
#include <ansi.h>
inherit NPC;
inherit F_BANKPAWNOWNER;
inherit F_VENDOR;
string ask_me(object who); 
void create()
{
        set_name("胡姥姥", ({ "waiter", "mentong" }) );
        set("title", "大观园");
        set("gender", "女性" );
        set("age", 77);
        set("richness",1000000);
        set("class","quanli");
        set("str", 50);
        set("cor", 70);
        set("cps", 60);
        set("int", 50);
        set("per", 40);
        set("con", 30);
        set("spi", 20);
        set("kar", 10);
        set("long",
"只见这人一身锦衣华服，汉玉悬腰。\n"
                );
        set("chat_chance", 2);
        set("chat_msg", ({
                "胡姥姥从兜里抓了把蚕豆放到嘴里。。。\n",
                }) );
        set("combat_exp", 50000000);
        set("fly_target",1);
        set("attitude", "friendly");
        set("env/wimpy", 70);
        set("max_atman", 10000);
        set("atman", 1000);             
        set("atman_factor", 3);
        set("max_force", 10000);
        set("force", 1000);
        set("force_factor", 50);
        set("max_mana", 10000);
        set("mana", 1000);

   set("mana_factor", 3);
//      set_skill("spells", 160);


    set_skill("move", 120);
    set_skill("parry",200);
    set_skill("dodge", 120);
    

    set_skill("unarmed",160);
    set_skill("staff",200);


    set_skill("xioushan-water",220);
    set_skill("yinshe-stick",220);
    set_skill("stormdance",200);
    

    map_skill("dodge", "stormdance");
    map_skill("move", "stormdance");
     map_skill("unarmed", "xioushan-water");
    map_skill("staff","yinshe-stick");
    map_skill("parry","feiyuancurse");

    set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.yinshechudon" :),
                
        }) ); 


        setup();
         carry_object("/d/guanwai/npc/obj/junkstaff")->wield();
        carry_object("/obj/armor/cloth")->wear();
        //carry_object("/d/baiyun/npc/obj/bsword")->wield();
  
} 
void init()
{
        ::init();
        
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        add_action("do_vendor_list","list");
        add_action("do_loan","loan");
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
} 
int accept_fight(object me)
{
        command("inn");
        command("say 老人家也欺负？！");
                return 1;
}
     