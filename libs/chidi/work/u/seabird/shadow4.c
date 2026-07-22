#include <ansi.h>

inherit BHNPC;

void create()
{
        set_name("任我行--虚", ({ "ren woxing shadow", "shadow" }));
        set("title", BLU "日月神教教主"NOR );
        set("long", "只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清秀，
身材甚高，一头黑发，穿的是一袭青衫。与前三个人一样，也是虚幻的。\n");
        set("gender", "男性");
        set("class", "scholar");
        set("age", 55);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 13000);
        set("per", 127);
        set("int", 130);
        set("con", 31000);
        set("dex", 130);
        
        set("max_qi", 311000);
        set("max_jing", 41100000);
        set("neili", 400110);
        set("max_neili", 941100000);
        set("jingli", 400110);
        set("max_jingli", 941100000);
        set("jiali", 40110);
        set("combat_exp", 1001100000);
        set("score", 50001100);

        set_skill("literate", 1100);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 2010);
        set_skill("parry", 30);
        set_skill("sword", 30);
        set_skill("changquan", 2010);
        set_skill("kuihua-xinfa", 30);
        set_skill("lingxu-bu", 30);
        set_skill("damo-jian", 30);
        set_skill("taiji-jian", 30);
        set_skill("huifeng-jian", 2010);
        set_skill("taishan-sword", 30);
        set_skill("hengshan-jian", 2010);
        set_skill("hengshan-sword", 30);
        set_skill("huashan-sword", 2010);
        set_skill("songshan-sword", 2010);

        map_skill("dodge", "lingxu-bu");
        map_skill("force", "kuihua-xinfa");
        map_skill("unarmed", "changquan");
        map_skill("sword", "damo-jian");
        map_skill("parry", "damo-jian");

        set("inquiry", ([
        //        "过关" :  (: ask_bijian :),
        //        "比剑" :  (: ask_bijian :),
        ]) );
        setup();
    carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{     
                add_action("do_kill","team kill");
//                 add_action("do_kill","touxi");
                add_action("do_kill","kill");
                add_action("do_kill","hit");
                add_action("do_kill","fight");
                add_action("do_kill","steal");
                add_action("do_kill","beg");
                add_action("do_kill","persuade");
                add_action("do_kill","perform");
                //add_action("do_kill","exert");
                //add_action("do_kill","yun");
                add_action("do_kill","throw");
                add_action("do_kill","conjure");
}       

int do_kill(string arg)
{
        string what,who;
        if(!arg) return 0;
                               
        if(this_object()->id(arg))
        {
                write("这是给你吸内力的任我行，干吗老打他？！\n");
                return 1;
        }
        else
        if(sscanf(arg,"%s from %s",what,who)==2 && this_object()->id(who))
        {
                write("这是给你吸内力的任我行，干吗老打他？！\n");
                return 1;
        } else
        if(sscanf(arg,"%s at %s",what,who)==2 && this_object()->id(who))
        {
                write("这是给你吸内力的任我行，干吗老打他？！\n");
                return 1;
        } else
        if(sscanf(arg,"%s on %s",what,who)==2 && this_object()->id(who))
        {
                write("这是给你吸内力的任我行，干吗老打他？！\n");
                return 1;
        } else
        if(sscanf(arg,"%s %s",what,who)==2 && this_object()->id(who))
        {
                write("这是给你吸内力的任我行，干吗老打他？！\n");
                return 1;
        } else
        if( arg == "roar" || arg =="hou" )
        {
                write("这是给你吸内力的任我行，干吗老打他？！\n");
                return 1;
        }  

        return 0;
}


void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        command("peace " + ob->query("id"));
}
void unconcious()
{
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("neili", 400110);
        set("max_neili", 941100000);
        set("jingli", 400110);
        set("max_jingli", 941100000);
        say( "任我行狞笑着说：我是无敌不死版！\n");
        }

void die()
{
        unconcious();
}

