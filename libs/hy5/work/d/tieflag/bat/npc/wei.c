 //All Rights Reserved 1998 Apstone, Inc.
inherit NPC;
#include <ansi.h>
int give_book(); 
void create()
{
        set_name("魏行龙", ({ "wei xing long" }) );
        set("title", MAG "紫面煞神" NOR);
        set("gender", "男性" );
        set("age", 35);
//      set("str", 30);
        set("agi", 20);
        set("long",
        "此人左眼睛有一条刀疤，这条刀疤自眼角一直划到耳根，虽长而不太深，
        而且天生异像，面如紫血，若不指明，别人很难发现这条刀疤。\n");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("dodge",100);
        set_skill("parry",100);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");


	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

        set("combat_exp", 900000);
        set("chat_chance", 2);
         set("chat_msg", ({
"魏行龙自言自语道：只要练成了“清风十三式”，就连那独耳老太来我都不怕。\n ",
"魏行龙皱着眉头嘀咕着：“这一招是先虚后实，还是先实后虚，或者都是虚招？\n",
 }) );
        set("inquiry",([
        "清风十三式" : (: give_book:),
         "book" : (: give_book:)
        ]) );
        
        
        
        setup();
   carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object(__DIR__"obj/qfbook");
//      carry_object(__DIR__"obj/qfbook");
} 
int give_book()
{
        command("say “看来阁下是有备而来，这样吧，咱们先比划比划！“");
        if (this_player()->query_temp("marks/wei_win")) 
                this_player()->delete_temp("marks/wei_win");
        this_player()->set_temp("marks/wei",1);
        return 1;
}   
void win_enemy(object loser)
{
        message_vision("$N不屑地对$n哼了一声：要不是老夫手下留情，你这条膀子早废了。\n",this_object(),loser);
} 
void lose_enemy(object winner)          //modified by jusdoit at Dec 17,2001
{                                       
        object book;
        if (winner->query_temp("marks/wei")) {
                message_vision("$N愁眉苦脸地对$n说，阁下果然高明，看来这密籍我想留也留不住了。\n",this_object(),winner);
                message_vision("$N无可奈何地从怀里掏出一本书递给$n。\n",this_object(),winner);
                book = new(__DIR__"obj/qfbook");
                book->move(winner);
                winner->delete_temp("marks/wei");
                winner->set_temp("marks/wei_win",1);
        } else message_vision("$N愁眉苦脸地对$n说，阁下果然高明。\n",this_object(),winner);
        
}   
void init() {
        object ob;
        ::init();
        if(interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
} 
void greeting(object ob) {
   
        string where;
        if(!ob || environment(ob) != environment()) {
                return;
        }
        
        switch( random(5)){
                case 0:
                        say("魏行龙自言自语道：只要练成了“清风十三式”，就连那独耳老太来我都不怕。\n");
                        break;
                case 1:
                        say("魏行龙皱着眉头嘀咕着：“这一招是先虚后实，还是先实后虚，或者都是虚招？\n");
                        break;
                } 
}  
int accept_fight(object me)
{
                if (!this_object()->is_fighting()) {
                        command("grin");
                        command("say 好，正好拿你来喂招！\n");
                        return 1;
                } else command ("say 不忙不忙，一个一个来，老子正缺对手。");
                        return 0;
}                         
