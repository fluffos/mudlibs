// zhaixing.c 摘星子
inherit BHNPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
    set("nickname", "星宿派大师兄");
    set("long", 
        "他就是丁春秋的大弟子、星宿派大师兄摘星子。\n"
        "他三十多岁，脸庞瘦削，眼光中透出一丝乖戾之气。\n");
    set("gender", "男性");
    set("age", 35);
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("str", 36);
    set("int", 38);
    set("con", 36);
    set("dex", 76);
    
    set("max_qi", 1000);
    set("max_jing", 800);
    set("neili", 1800);
    set("max_neili", 1800);
    set("jiali", 60);
        set("combat_exp", 800000);
    set_skill("force", 200);
    set_skill("huagong-dafa", 200);
    set_skill("dodge", 200);
    set_skill("zhaixinggong", 200);
    set_skill("unarmed", 205);
    set_skill("xingxiu-duzhang", 200);
    set_skill("parry", 200);
    set_skill("staff", 200);
    set_skill("tianshan-zhang", 200);
    set_skill("literate", 200);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "xingxiu-duzhang");
    map_skill("parry", "tianshan-zhang");
    map_skill("staff", "tianshan-zhang");
    create_family("星宿派", 2, "弟子");
    setup();
//  carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    command("say 好吧，我就收下你了。");
    command("recruit " + ob->query("id"));
}
void init()
{
        object ob;
        ::init();
   if (this_object()->query("startroom") != base_name(environment()) )  return;
        if (interactive(ob = this_player()) && !is_fighting()) {
                if ((ob->query("shen")>10000) &&
                        (!wizardp(ob))) {
        command("say 星宿海岂是尔等闲逛之地！\n");
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
                }
        }
}
void do_killing(object ob)
{
    if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}
mixed hit_ob(object me,object victim,int damage)
{
   if (!living(this_object()) )  return;
   switch( random(5)) { 
   case 0:
   command("exert maxsuck "+victim->query("id"));
   break;
   case 1:
   command("exert qisuck "+victim->query("id"));
   break;
   case 2:
   command("exert neilisuck "+victim->query("id"));
   break;
   case 3:
   command("exert jingsuck "+victim->query("id"));
   break;
   case 4:
   command("exert jinglisuck "+victim->query("id"));
   break; 
    }
}

