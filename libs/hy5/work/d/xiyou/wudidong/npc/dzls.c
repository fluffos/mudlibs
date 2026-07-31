// Created by kuku@sjsh  2003.2
// 无底洞负责给书的npc 

inherit NPC;
int ask_book();
int ask_blade();


void create()
{
        set_name("打杂老鼠", ({"daza laoshu", "laoshu"}));
        set("age", 22);
        set("title","无底洞");
        set("gender", "男性");
        set("int", 35);
        set("long","它是无底洞专门负责发书和刀的老鼠，如果你是无底洞弟子要看书学习最好找它。\n");
        set("attitude", "friendly");
        set("combat_exp", 40000);
        set("combat_exp", 100000);
        set("max_neili", 400);
        set("neili", 400);
        set("force_factor", 5);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("literate", 150);
 
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        call_out("greeting", 1, this_player());
        ::init();
}

void greeting(object who) 
{
        if( !who || environment(who) != environment() ) return;
        if( who->query("family/family_name")!= "陷空山无底洞" ) return;
        tell_object(who,"打杂老鼠悄悄告诉你：想要无底洞的宝物吗？这里有空白帐本(ask laoshu about book)和枯骨刀(ask laoshu about blade)。\n");  
}


