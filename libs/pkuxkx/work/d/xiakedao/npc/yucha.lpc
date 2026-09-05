//愚茶道长童颜鹤发的老道

// Xiakedao NPC
// modified by aiai on 4/23/1999

#include <ansi.h>

inherit NPC;

void consider();

void create()
{
        set_name(HIW"愚茶道长"NOR, ({"yucha daozhang", "yucha"}));
        set("nickname", HIY"武当掌门"NOR);
        set("title",GRN "侠客岛" NOR + YEL "二代传人" NOR);
        set("gender", "男性");
        set("age", 80);
        set("long","这是一个童颜鹤发的老道，据说是前武当派的掌门人，后因迷恋侠客岛\n"
"武学，久居于侠客岛之上。其剑法功夫独步天下。\n");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("chat_chance", 10);
        set("chat_msg", ({
                  ( "白居易诗云：‘勿轻直折剑，犹胜曲全钩’。可见我这直折之剑，方合石壁注文原意\n" ),
        }));

       
        set("max_qi", 5000);
        set("max_jing",5000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 200);
        
        set("combat_exp", 1500000);
        set("score", 50000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
/*        
        set("inquiry", ([
                "" : (: ask_me :),
        ]) );
*/
        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("cuff", 250);
        set_skill("taiji-quan", 250);
        set_skill("xiake-shenfa", 300);
        set_skill("xiake-shengong",300);
        set_skill("xiake-jianfa",300);
        set_skill("literate", 300);
        map_skill("dodge", "xiake-shenfa");
        map_skill("force","xiake-shengong");
        map_skill("parry","xiake-jianfa");
        map_skill("sword","xiake-jianfa");
        map_skill("cuff","taiji-quan");
        
        prepare_skill("cuff", "taiji-quan");

        create_family("侠客岛",2,"传人");
        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
//      carry_object("")->wear();
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        switch( random(2) )
        {
            case 0:
                command("perform feijian " + target->query("id"));
                break;
            case 1:
                command("perform feijian " + target->query("id"));
                break;
             }
}
