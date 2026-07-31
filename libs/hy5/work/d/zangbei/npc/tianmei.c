#include <ansi.h>
#include <command.h>
inherit NPC; 
void throw_away(object ob); 
void create()
{ 
        set_name(YEL"天美公主"NOR,({"tianmei"}));
        set("title","西方神教");
        set("gender", "女性" );
        set("long", "
天美公主是魔教前教主夫人弱柳夫人的女儿，多年前和叁大长老铁燕，银龙，金狮
一起叛教出走，另立新帜。其间又与神剑谢晓峰有过一段情缘，生下了女儿谢小玉。\n"); 
        set("age",20);
        set("combat_exp", 7500000);
        //set("class","swordsman");               
        set("attitude","friendly");
  set("reward_npc", 1);
       set("difficulty", 20);
       set("no_busy", 9);
       set("ill_boss",5);
              set_skill("move", 100);
    set_skill("parry",100);
    set_skill("dodge", 100);
    set_skill("force", 80);
    set_skill("literate", 120);
    set_skill("blade", 100);
    set_skill("unarmed",100);
    set_skill("demon-steps",80);
    set_skill("demon-strike",80);
    set_skill("demon-blade",120);
    set_skill("demon-force",120);
    map_skill("parry", "demon-blade");
    map_skill("blade", "demon-blade");
    map_skill("dodge", "demon-steps");
    map_skill("force", "demon-force");
    map_skill("unarmed", "demon-strike");


        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_neili",1500);
        set("neili",1500);
        set("force_factor",120); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      set("death_msg",CYN"\n$N  ㄩ  媪    颇    惆  腔［陛陛陛［［［ \n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);    
          set("chat_msg_combat", ({
        (: perform_action, "unarmed.dimo" :),
            (: perform_action, "dodge.lianhuanbabu" :),
            (: perform_action, "unarmed.dimo" :),

            }) );             
       // auto_npc_setup();("wang",300,200,0,"/obj/weapon/","fighter_w","shadowsteps+dabei",2);
                
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 

void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player())) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        object *inv;
        string my_position;
        if( !ob || environment(ob) != environment()) return;
        if (ob->query("learn_tianmei"))  
        {
        command("hmm");
        command("say 十叁剑是唯一能克神剑的武功，但这上面的破绽应该怎麽弥补？");
        return;
        }
        if (ob->query("m_killer/谢晓峰")) 
        {
        command("ack");
        command("say 这位英雄竟能杀了谢晓峰那个负心人，真是大快我心。。。");
        command("sigh");
        ob->set("learn_tianmei",1);
        }
} 
void throw_away(object ob) {
        if( !ob || environment(ob) != environment() ||is_fighting(ob)) return;
        this_object()->kill_ob(ob);
        ob->kill_ob(this_object());
}       
 

int recognize_apprentice(object ob){
    if(ob->query("learn_tianmei")) {

        return 1;
    } else {
        if (random(2))
        message_vision("$N摇了摇头：「大仇未报。。。」”\n", 
                        this_object());
        else 
        message_vision("$N凝视你片刻，但却依然默不作声。”\n", 
                        this_object(), ob);             
                return 0;
    }
} 
