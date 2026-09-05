//一灯
//by icer
#include <ansi.h>


void consider();
void heal();
inherit NPC;

int ask_cure();
int ask_ying();

void create()
{
        set_name("一灯大师", ({ "yideng dashi","dashi","yideng" }));
        set("long", "他身穿粗布僧袍，两道长长的白眉从眼角垂了下来，面目慈祥，眉间隐含愁苦，\n
但一番雍容华贵的神色，却是一望而知。\n");
        set("gender", "男性");
        set("rank_info/respect", "大师");
        set("age", 78);
        set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("no_get",1);
        set("shen_type", 500000);

        set_skill("finger", 300);
        set_skill("force", 300);
        set_skill("dodge", 600);
        set_skill("parry",300);
        set_skill("yiyang-zhi",400);
        set_skill("xiantian-gong",200);
        map_skill("finger","yiyang-zhi");
        map_skill("parry","yiyang-zhi");
        map_skill("force","xiantian-gong");
        prepare_skill("finger", "yiyang-zhi");

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
		(:  heal :),
        }) );
        set("combat_exp", 10000000);

        set("attitude", "peaceful");
        set("class", "bonze");
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("jiali", 150);
        set("neili", 3000);
        set("max_neili", 3000);
        set("inquiry", ([
            "治伤" : (: ask_cure :),
            "瑛姑" : (: ask_ying :),
       ]) );

        setup();
        carry_object("/d/shaolin/obj/cloth")->wear();
}

int check()
{
        object room;
        
        room = environment(this_object());
        if (base_name(room) == "/d/dalicheng/yideng/shiwu")
                return 1;
        return 0;
}

int ask_cure()
{
        if (!check())
                return notify_fail("一灯大师不打算给你疗伤。\n");
        if (this_player()->query("task_duan1")||this_player()->query("task_duan2"))
        return notify_fail("一灯大师不打算给你疗伤。\n");
        command("say 好吧，我就来给你治好伤。\n");
        write("一灯使出一阳指功夫，给你治好了伤。\n");
        this_player()->set("eff_qi",this_player()->query("max_qi",1));
        this_player()->set_temp("marks/段1",1);
        return 1;
}

int ask_ying()
{
        object me;
        me = this_player();
        
        if (!check())
                return 1;
        if (me->query("task_duan3"))
        {
                command("say 多谢施主成全，瑛姑现在很好。\n");
                return 1;
        }
        if (me->query("task_duan2"))
        {
                command("say 多谢施主！\n");
                command("say 以前郭靖黄蓉曾来此与我研讨九阴真经，我就将它传与你，作为报答吧！\n");
                write("一灯大师向你详细讲述了九阴真经的内容。\n");
                write("你的根骨增加了！！\n");
                write("你的悟性增加了！！\n");
                me->add("con",3);
                me->add("xiantian/con/yideng",3);
                me->add("int",5);
                me->add("xiantian/int/yideng",5);
                me->delete("task_duan2");
                me->set("task_duan3",1);
                me->delete("task_duan1");
                return 1;
        }
        if (!me->query_temp("marks/段1"))
        return notify_fail("一灯大师欲言又止，神色凄凉。\n");
        command("sigh");
        command("say 我很对她不起，如果你能让她原谅我，我将感激不尽。如果你见到她，\n
请告诉她我已经出家了，法号一灯。\n");
        command("say 从后山可以直接下山。如果你完成了到我这里来可以从瀑布那里\n
直接走捷径(jiejing)。\n");
        this_player()->set("task_duan1",1);
        return 1;
}
int accept_object(object me, object ob)
{
        if (!check())
                return 1;
        if (me->query("task_duan3"))
        {
                return notify_fail("一灯大师惊诧地望着你：瑛姑不是已经原谅我了吗？怎么又给我这个指环？\n");
        }
        if ((ob->query("id")=="zhi huan") && (me->query_temp("marks/killed_qiu",1)))
        {
                write("一灯大师接过指环，说道：多谢这位施主。如果施主方便，我想\n
跟施主研讨一下九阴真经如何？\n");
                write("一灯大师传授予你九阴真经的易筋锻骨篇。\n
你的根骨增加了！！\n");
                me->add("con",3);
                me->add("xiantian/con/yideng2",3);
                me->delete("task_duan1");
                me->set("task_duan3",1);
                return 1;
        }
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(1) )
        {
            case 0:
            command("perform finger.fuxue " + target->query("id"));
             break;
             }
}

void heal()
{
        object ob=this_object();
        
        if (ob->query("bihua"))
                return;
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("exert lifeheal");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                ob->set("water",ob->max_water_capacity() );
                ob->set("food",ob->max_food_capacity() );
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}
