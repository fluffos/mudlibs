// NPC: shashou.c
// Date: Look 99/04/25

inherit NPC;
#include <ansi.h>
#include "skill.h"

void create()
{
        set_name("蒙面杀手", ({ "sha shou", "shashou" }));
        set("nickname", "坏事做绝");
        set("long", 
"他是一个隐性埋名的人，不知为何与人结下冤仇。整天追杀仇家。\n");
        set("gender", "男性");
        set("age", 40 + random(20));
//      set("attitude", "aggressive");
        set("shen_type", 0);
        set("per", 10 + random(10));
        set("str", 30 + random(5));
        set("int", 30 + random(5));
        set("con", 30 + random(5));
        set("dex", 30 + random(5));
        
        set("max_qi", 3000);
        set("max_jing", 1800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("eff_jingli", 1800);

        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 5000);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        mapping killerskill1;
        int number,k_qi,k_neili,k_jing;
        string t_force,t_dodge;

        object me, obj = this_player();
        object ob_mubiao;
        me = this_object();
        ::init();

        if(userp(obj) && obj->query_temp("mubiao",1)
           && !environment(obj)->query("no_fight"))
                {
        number = (int)obj->query("max_pot");
        k_qi = (int)obj->query("max_qi");
        k_jing = (int)obj->query("max_jing");
        k_neili = (int)obj->query("max_neili");

        killerskill1 = skill2[random(sizeof(skill2))];
        number = (int)(number - 110 - (random(25)?1:-1)*random(number/10));
        if (number>400) number = 400;
/*
        if (userp(ob) && (number > ((int)ob->query("max_pot")-100)))
        if (number > ((int)ob->query("max_pot")-100))
        write_file("/log/HS_JOB",sprintf("%s %s(%s) 第%d次任务目标等级%d，本人等级%d。\n",
        ctime(time())[4..19],ob->name(1),ob->query("id"),(int)ob->query("hs_job"),number,(int)ob->query("max_pot")-100));
*/

        t_force = k_force[random(sizeof(k_force))];
        t_dodge = k_dodge[random(sizeof(k_dodge))];       

        me->set_skill("force",number);
        me->set_skill("dodge",number);
        me->set_skill("parry",number);
        me->set_skill(t_force,number);
        me->set_skill(t_dodge,number);
        me->set_skill(killerskill1["t_skill"],number);
        me->set_skill(killerskill1["b_skill"],number);
            

/* set killer's  skill maps */

        me->map_skill("force",t_force);
        me->map_skill("dodge",t_dodge);
        me->map_skill("parry",killerskill1["t_skill"]);
        me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
       
/* set killer's skill prepares */

        me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

/* copy entire dbase values */

        me->set("max_qi",k_qi);
        me->set("eff_qi",k_qi);
        me->set("qi",k_qi);
        me->set("max_jing",k_jing);
        me->set("eff_jing",k_jing);
        me->set("jing",k_jing);
        me->set("max_neili",k_neili);
        me->set("neili",k_neili);
        me->set("combat_exp",obj->query("combat_exp"));

                   me->set_temp("apply/attack",  random(30));
                   me->set_temp("apply/dodge",  random(50));
                   command("sneer " + obj->query("id"));
                   command("say "+RANK_D->query_respect(obj)+"，这"+obj->query_temp("mubiao")+"与我有血海深仇，你实在不该来趟这趟混水。\n");
                   command("say 我先料理了你这个管闲事的。再去杀那贱人不迟。\n");
//                 obj[i]->kill_ob(me);
                   me->kill_ob(obj);
                   remove_call_out("dest");
                   call_out("dest", 50);
                }
}

void dest()
{
       object me;
       me = this_object();

       tell_room(all_inventory(environment(me)),me->query("name")+"道：他奶奶的，点子硬的很啊，下回老子再找你算帐！\n");
       tell_room(all_inventory(environment(me)),me->query("name")+"一个闪身，匆匆离开。\n");
       destruct(me);
}
