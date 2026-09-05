#include <ansi.h>
inherit NPC;
void create()
{
        seteuid(getuid());
     set_name("阿善",({"a shan","shan","mad man","man","mad"}));
        set("title", "疯子");
        set("gender", "男性" );
        set("age", 50);
        set("long", "一位邋邋遢遢的疯子。\n");
        set("attitude", "heroism");
      
        set("str", 21);
        set("con", 30);
        set("int", 27);
        set("dex", 23);
        set("max_qi", 800);
        set("max_jing", 400);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 40);
        set("shen_type", -1);
        set("env/wimpy", 60);
        set_temp("apply/attack",  40);
        set_temp("apply/defense", 40);
        set("combat_exp", 25000);
        set_skill("force", 43);
        set_skill("unarmed", 68);
    
        set_skill("dodge", 59);
        set_skill("parry", 40);
        set_skill("taiji-shengong",50);
        map_skill("force","taiji-shengong");       
//        create_family("武当派", 3, "弟子");
        set("chat_chance", 8);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
//        carry_object("/clone/misc/mask");
        add_money("silver", 10);
}
void init()
{
        object ob, me;
        mapping skill_status, map_status;
        string *sname, *mname;
        int i;
        me = this_object();
        ob = this_player();
        ::init();
        if (me->is_fighting() || wizardp(ob)) return;
        remove_call_out("pretending");
        call_out("pretending", 1, ob);
}
void pretending(object ob)
{
        object me = this_object();
        if(!ob || !userp(ob) || environment(ob) != environment()) return;
      switch( random(6) ){
                case 0:
                       command("look " + ob->query("id"));
                       command("haha");
                       command("cry");
                       command("praise a shan");
                case 1:
                       command("hi " + ob->query("id"));
                       command("exert heal");
                       command("exert recover");
                       break;
                case 2:
                       command("stare " + ob->query("id"));
                       me->fight_ob(ob);
                       ob->fight_ob(me);
                       break;
case 3:
                       command("hit " + ob->query("id"));
                       command("hehe");
                       command("sigh");
                       break;
case 4:
                       command("stare " + ob->query("id"));
                       command("stare " + ob->query("id"));
                       me->fight_ob(ob);
                       ob->fight_ob(me);
                       break;
case 5:
                       command("stare " + ob->query("id"));
                       command("stare " + ob->query("id"));
                       me->fight_ob(ob);
                       ob->fight_ob(me);
                       break;
        }
}
