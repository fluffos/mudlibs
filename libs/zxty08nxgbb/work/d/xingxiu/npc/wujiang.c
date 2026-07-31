// wujiang.c 武将
inherit NPC;
void create()
{
        set_name("武将", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "他是嘉峪关的守将。\n");
        set("combat_exp", 75000);
        set("shen", 1000);
        set("attitude", "peaceful");
        set_skill("unarmed", 55);
        set_skill("force", 55);
        set_skill("sword", 55);
        set_skill("dodge", 55);
        set_skill("parry", 55);
        set_temp("apply/attack", 55);
        set_temp("apply/damage", 30);
        set("neili", 300); 
        set("max_neili", 300);
        set("jiali", 10);
        setup();
        carry_object(__DIR__"obj/gangjian")->wield();
        carry_object(__DIR__"obj/tiejia")->wear();
}
void init()
{
    ::init();
    add_action("do_kill","kill");
    add_action("do_kill","hit");
}
int do_kill(string arg)
{
    call_out("kill",1,arg,this_player());
    return 0;
}
int kill(string arg,object obj)
{
    object ob;
    if (!obj)
        return  0;
    if (environment(obj)!=environment())
        return 0;
    if (this_object()->id(arg)){
    command("say 想打架？你是自找死路！ 兄弟们，上！");
                if( objectp( ob = present("guan bing", environment(this_object())) ) )
                     if (!ob->is_killing(this_player()))
                 ob->kill_ob(this_player());    
    }
    return 0;
}
int accept_fight(object me)
{
        command("say 老夫从不枉杀无名之人。");
        return 0;
}
