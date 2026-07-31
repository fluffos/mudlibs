 // Copyright (C) 1995 - 2001, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("心灯", ({ "master deng", "master"}) );
    set("vendetta_mark","shaolin");
    set("gender", "男性" );
        set("reward_npc", 1);
        set("difficulty", 10);
    set("age", 64);
    set("per", 35);
    set("agi",30);
    set("int",30);
//    set("str",30+random(30));
    set("cor",30);
    set("attitude","friendly");
    set("max_neili", 1500);
    set("neili", 1500);
//    set("force_factor",30);
    set("long","东林寺七大高手之一。\n");
    create_family("东林寺", 17, "大师");
    set("student_title","长老");    
    set("combat_exp", 4000000);
    set_skill("move", 150);
    set_skill("dodge", 150);
    set_skill("force", 200);
    set_skill("literate", 150);
    set_skill("hammer",200);
    set_skill("shaolin-shenfa",150);
    set_skill("tiexue-hammer",150);
    set_skill("yizhi-chan",175);
    set_skill("damo-jian",150);
    set_skill("hunyuan-yiqi",150);
    set_skill("jingang-quan",150);
    set_skill("unarmed",150);
    set_skill("parry",150);
    map_skill("parry","tiexue-hammer");
    map_skill("unarmed","jingang-quan");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("force", "hunyuan-yiqi");
    map_skill("hammer", "tiexue-hammer");
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: perform_action, "hammer.fanbei" :),
        (: perform_action, "unarmed.qianshouqianbian" :)
            }) );
    setup();
    carry_object(__DIR__"obj/monk_cloth")->wear();
    carry_object(__DIR__"obj/hammer")->wield(); 
} 
void attempt_apprentice(object me)
{
    if(me->query_temp("won_master_yi")||me->query_temp("won_master_17"))
    {
        command("smile");
        command("recruit " + me->query("id") );
                me->delete_temp("won_master_yi");
        me->delete_temp("won_master_17");
        return;
    }
    else
    {
        command("shake");
    }
} 
int accept_fight(object me)
{
    if((me->query("family/family_name") == query("family/family_name") &&
        me->query("family/master_id") == query("id")) || me->query_temp("won_master_17"))
    {
        if (me->query("combat_exp")<1200000) {
                command("say 徒儿，我的功夫你还没练完吧！\n");  
                return 0;
                }
        command("say 好，你赢了我，你就可以去找东林中更高深的师傅了！\n");
        return 1;
    }
    else
    {
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
    }
}
void win_enemy(object loser)
{
    command("say 阿弥陀佛！徒儿还要努力呀！\n");
}
void lose_enemy(object winner)
{
    command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
    winner->set_temp("won_master_17",1);
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "shaolin");
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill");
//      if(this_player()->query("bellicosity") > 100){
//              call_out("jiang_sha", 1, this_player()); --- will adjust daode instead, silencer
//      }
} 
/*
int jiang_sha(object me){
        if(!interactive(me) || environment(me) != environment(this_object())) {
                return 0;
        }
        message_vision("$N说道：“阿弥陀佛，
}*/ 
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
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "shaolin"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：阿弥陀佛,佛门清静之地,岂可妄起杀心?施主请恕老衲得罪了！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}       
