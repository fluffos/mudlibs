// zhangcui.c

inherit NPC;
inherit F_MASTER;
string ask_huijia()
{
 object ob,me=this_player();
 int i;
i=query_temp("marks/bing");
//if(!i=0)

if(!me->query_temp("marks/bing"))
{
write("谢谢你送无忌回来,这本书留做纪念吧.\n");
ob=new("/d/binghuodao/npc/obj/force_book");
me->set_temp("marks/bing/zhang",1);
ob->move(me);
return "\n";
}
else 
{
return "无忌出去玩,还没回来,帮我们找找吧.\n";
}
}
void create()
{
set_name("张翠山", ({ "zhang cuishan", "zhang" }));  
set("nickname","武当五侠");
        set("long", 
                "他就是张三丰的五弟子、武当七侠之中的张翠山。\n"
                "身穿一件干干净净的白色道袍。\n");
        set("gender", "男性");
        set("age",31);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 35);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 1500);
        set("max_neili", 4500);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 600000);
        set("per", 28);

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
        set_skill("unarmed", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");

        create_family("武当派", 2, "弟子");
set("inquiry", ([
        "张无忌" : (:ask_huijia:) ,
         ]) );
        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.zhen" :),
                (: exert_function, "recover" :),
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/binghuodao/npc/obj/skin")->wear();

}
void attempt_apprentice(object ob)
{
                command("say 我是已无面目再回去见师傅他老人家了，如何还敢收徒。");
                return;

}
