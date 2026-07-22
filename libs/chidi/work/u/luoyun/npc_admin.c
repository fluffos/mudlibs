inherit BHNPC;
inherit F_MASTER;
int ask_me();
void create()
{
    set_name("新手指导", ({ "npc_admin" }));
    set("long", 
        "他就是江湖里第一个注册的玩家。\n");
    set("gender", "男性");
    set("title",HIR"逍遥派第三代弟子"NOR);
    set("nickname",HIC"江湖"NOR+HIG"第一个注册的玩家"NOR);
    set("age", 150);
    set("attitude", "peaceful");
    set("str", 25);
    set("int", 27);
    set("con", 25);
    set("dex", 25);
    set("no_suck",1);
    set("no_suck2",1);
    set("inquiry", ([
        "疗伤" : (:ask_me:),
    ]) );
    set("qi", 2800000);
    set("max_qi", 2800000);
    set("jing", 18000000);
    set("max_jing", 1800000);
    set("neili", 2000000);
    set("max_neili", 2000000);
    set("jiali", 6000);
    set("combat_exp", 1500000000);
    set_skill("force",1000);
    set_skill("blade", 1000);
    set_skill("dodge", 1000);
    set_skill("unarmed",1000);
    set_skill("parry", 1000);
    set_skill("lingboweibu",1000);
    set_skill("literate", 1500);
    set_skill("hubo", 1000);
    set_skill("qimen-flee",1000);
    set_skill("taoism", 1000);
    set_skill("piaomiao-shenfa", 1000);
    set_skill("throwing", 1000);
    set_skill("zhemei-shou", 1000);
    set_skill("fadai-qigong", 1000);
    map_skill("unarmed", "zhemei-shou");
    map_skill("dodge", "lingboweibu");
    map_skill("force", "fadai-qigong");
    create_family("逍遥派", 3, "弟子");
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
    command("recruit " + ob->query("id"));
    ob->set("class","shaman");
 }
int ask_me()
{
    object ob;
    ob=this_player();
    if (ob->query("family/family_name") != "逍遥派")
        {
         command("say 你不是我派弟子，我不可以为你疗伤。\n");
         return 1;
}
else
    if (ob->query_temp("heal"))
{       
        command("shake"+ob->query("id"));
        command("say 现正在跟你疗伤呢，别乱动！\n");
        return 1;
}
else
     if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
    {
        command("?"+ob->query("id"));     
        command("say 你没有受任何伤啊？\n");
        return 1;
    }
    else
{
    message_vision("杀喂$N服下一颗药丸,然后盘膝坐下，双掌贴着$N的背心。\n", ob);
    ob->set_temp("heal",1);
    remove_call_out("recover");
    call_out("recover",5,ob);
    return 1;
}   
}

int recover(object ob)
{   
    ob->set("eff_qi", ob->query("max_qi"));
    ob->set("eff_jing",ob->query("max_jing"));  
    message_vision("大约过了一盅茶的时份，杀慢慢地站了起来。\n",ob);
    command("say 你的伤势已经全好了,可以走啦。\n");
    if (ob && ob->query_temp("heal"));   
    ob->delete_temp("heal");   
    return 1;
}
