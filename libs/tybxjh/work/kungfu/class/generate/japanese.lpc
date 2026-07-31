inherit NPC;
object killertemp,killer_ob;

void create()
{
        NPC_D->generate_jp_name(this_object());
        set("long", "日本鬼子。\n");
        set("gender", "男性");
        set("age", 30);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        // the follow 5 setting has no use
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 100);
        set("combat_exp", 3000000);
        set("scale", 135);

        set_skill("force", 1);
        set_skill("fushang-neigong", 1);
        set_skill("dodge", 1);
        set_skill("renshu", 1);
        set_skill("parry", 1);
        set_skill("dongyang-dao", 1);
        set_skill("blade", 1);

        map_skill("blade", "dongyang-dao");

        set("rank_info/rude", "鬼子");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        setup();

       carry_object("/clone/misc/cloth")->wear();
          carry_object("/kungfu/class/generate/dao")->wield();
}

string challenge()

{
        set("opinion/msg", ({
                (random(2) ? "此人来自东洋扶桑，据说那里的东洋刀法极其怪异。"
                           : "东洋扶桑远在东海之外，那里的武士擅长使用窄刃长刀。"),
                (random(2) ? "是啊，东洋忍术也是诡秘得很。"
                           : "没错，不过东洋刀造型奇特，配合忍术还是颇有威力。"),
                (random(2) ? "哼！此人气焰如此嚣张，实为习武者大忌！"
                           : "此人可谓鼠目寸光，须知武道无穷，一丝也马虎不得！"),
        }));

        command(random(2) ? "haha" : "heng");
        switch (random(3))
        {
        case 0:
                return "我！大和武士" + name() + "，来向你们中原"
                        "武人挑战！谁敢出来迎战？";

        case 1:
                return "我就是东洋扶桑国的" + name() + "，你们中"
                        "原有没有人是我的对手？";

        default:
                return "我" + name() + "代表大和武士来向你们挑战"
                        "，有种的就给我滚出来！";
        }
}

void unconcious()
{
 killer_ob=this_object()->query_temp("last_damage_from");
  command("chat 八格呀路！");
 ::unconcious();
}

void die()
{
if(killertemp==killer_ob)
{
tell_object(killer_ob,"你得到了100点江湖威望!\n");
killer_ob->add("potential",10000);
killer_ob->add("combat_exp",20000);
}
::die();
}


void competition_with(object ob)
{
        object me=this_object();

        int max_skill=3;
int i;
        int *level;
       mapping skill_status;
mapping hp_status;
       if((skill_status = ob->query_skills()))
       level=values(skill_status);
       for(i=0; i<sizeof(skill_status); i++) {
       if(level[i]>max_skill)max_skill=level[i];
       }
        set_skill("force", max_skill);
       set_skill("fushang-neigong", max_skill);
        set_skill("dodge", max_skill);
       set_skill("renshu", max_skill);
        set_skill("parry", max_skill);
       set_skill("dongyang-dao", max_skill);
       set_skill("blade", max_skill);
       me->map_skill("blade","dongyang-dao");
       me->map_skill("dodge","renshu");
       me->map_skill("parry","dongyang-dao");

   hp_status = ob->query_entire_dbase();
   me->set("marks", hp_status["marks"]);
   me->set("combat_exp", hp_status["combat_exp"]*9/8);
   me->set("max_qi",    hp_status["max_qi"]);

   me->set("eff_qi",    hp_status["eff_qi"]);
   me->set("qi",        hp_status["eff_qi"]);
   me->set("max_jing",  hp_status["max_jing"]);
   me->set("eff_jing",  hp_status["eff_jing"]);
   me->set("jing",      hp_status["eff_jing"]);
   me->set("max_neili", hp_status["max_neili"] * 3/2);
   me->set("neili",     hp_status["max_neili"] * 5/2);
   me->set("jiali",     hp_status["jiali"]);
   killertemp=ob;
        command("say 八格呀路，你死去吧！\n");
        kill_ob(ob);
}

