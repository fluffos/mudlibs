 inherit NPC;
#include <ansi.h> 
void create()
{
        object armor,weap;
        set_name("小厮", ({ "xiao si" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
"太湖二十四舵的总舵把子王震湘王老爷子手下的贴身小厮。\n"
);
                  
        set("attitude", "friendly");
        set("score", 0);
        set("class","yinshi");
        
        set("combat_exp", 2000000);        
        set("int", 30);
        set("cps", 40);
        set("spi", 30);
        set("fle",50);
        set("str",36);
        
        set("neili", 1000);
        set("max_neili",1000);
        set("force_factor", 60);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 500);
        set("max_mana", 500);
     set("max_qi", 18000);
	set("max_jing", 18000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("max_neili", 24000);
	set("jiali", 100);
	set("combat_exp", 8500000);
	set("score", 400000);

	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("huagong-dafa", 380);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 380);
	set_skill("dodge", 250);
	set_skill("zhaixinggong", 380);
	set_skill("strike", 250);
	set_skill("chousui-zhang", 380);
	set_skill("claw", 350);
	set_skill("sanyin-wugongzhao", 380);
	set_skill("parry", 200);
	set_skill("staff", 300);
	set_skill("poison", 380);
	set_skill("tianshan-zhang", 380);
	set_skill("chanhun-suo", 380);
	set_skill("whip", 380);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "whip.duo" :),
(: perform_action, "whip.huixuan" :),
(: perform_action, "whip.suo" :),
         }) );
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(3));
        
        weap=new("/clone/weapon/whip");
        weap->set_name("短马鞭",({"whip"}) );
        weap->move(this_object());
        weap->wield();
        
        armor=new("/clone/misc/cloth");
        armor->set_name("灰布衣",({"cloth"}) );
        armor->move(this_object());
        armor->wear();
}       
