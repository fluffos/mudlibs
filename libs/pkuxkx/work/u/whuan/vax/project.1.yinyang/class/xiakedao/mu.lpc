//long 须眉全白，脸色红润，有如孩童
//Xiakedao NPC
//modified by aiai on 6/3/1999

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void consider();
string ask_me();
void heal();

void create()
{
        set_name("木剑封", ({"long yifan", "long", "yifan"}));
        set("nickname", RED"与世无争"NOR);
        set("title",GRN "侠客岛" NOR + YEL "岛主" NOR);
        set("gender", "男性");
        set("age", 120);
        set("long", "此人长须稀稀落落，兀自黑多白少，但一张脸却满是皱纹。到底多大年纪，\n"
"委实看不出来，总是在六十岁到九十岁之间，如说已年过百岁，也不希奇。\n");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 80);
        set("int", 80);
        set("con", 80);
        set("dex", 80);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: heal :),
        }));

       
        set("max_qi", 10000);
        set("max_jing",10000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 400);
        
        set("combat_exp", 5000000);
        set("score", 500000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
        
        set("inquiry", ([
                "" : (: ask_me :),
        ]) );
        
        set_skill("force", 500);
        set_skill("strike", 500);
        set_skill("xiake-strike", 500);
        set_skill("dodge", 500);
        set_skill("xiake-shenfa", 500);
        set_skill("literate", 500);
        set_skill("xiake-shengong",500);
        set_skill("literate", 500);
        set_skill("xiake-jianfa",500);
        set_skill("sword",500);
        set_skill("xiake-daofa",500);
        set_skill("blade",500);
        set_skill("throwing",500);
        map_skill("strike", "xiake-strike");
        map_skill("dodge", "xiake-shenfa");
        map_skill("force","xiake-shengong");
        map_skill("sword","xiake-jianfa");
        map_skill("blade","xiake-daofa");
        map_skill("parry","xiake-jianfa");
        prepare_skill("strike", "xiake-strike");

        create_family("侠客岛",1,"岛主");
        
        setup();
//      carry_object("")->wield();
//      carry_object("")->wear();
}

void attempt_apprentice(object ob)
{
      string callname;
        callname = RANK_D->query_respect(ob);
        
        command("say 我木某有生之年不会收徒弟了,但这个岛上有一处秘密所在可供修炼,"+callname+"可以自行方便。\n");
        return ;
}       

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        switch( random(2) )
        {
            case 0:
                command("yun qiankun " + target->query("id"));
                break;
            case 1:
                command("yun qiankun " + target->query("id"));
                break;
             }
}

void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 400");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

        
