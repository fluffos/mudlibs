//妙谛大师

// Xiakedao NPC
// modified by aiai on 4/23/1999

#include <ansi.h>

inherit NPC;

void consider();

void create()
{
        set_name(RED"妙谛大师"NOR, ({"miaodi dashi", "miaodi", "san"}));
        set("nickname", RED"少林方丈"NOR);
        set("title",GRN "侠客岛" NOR + YEL "二代传人" NOR);
        set("gender", "男性");
        set("age", 80);
        set("long","这是一个慈眉善目僧人，据说是前少林派的方丈，后因迷恋侠客岛\n"
"武学，久居于侠客岛之上。\n");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
         set("chat_chance", 3);
        set("chat_msg", ({
                  ( "唉！这句“吴钩霜雪明”到底有何深意呢？\n" ),
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
        
/*        set("inquiry", ([
                "" : (: ask_me :),
        ]) );
*/
        set_skill("hunyuan-yiqi", 300);
        
        set_skill("force", 300);
        set_skill("strike", 300);
        set_skill("xiake-strike", 300);
        set_skill("dodge", 300);
        set_skill("xiake-shenfa", 300);
        set_skill("xiake-shengong",300);
        set_skill("weituo-gun", 300);
        set_skill("buddhism", 300);
        set_skill("cuff", 300);
        set_skill("jingang-quan",300);
        set_skill("literate", 300);
        map_skill("strike", "xiake-strike");
        map_skill("dodge", "xiake-shenfa");
        map_skill("force","xiake-shengong");
        map_skill("parry","jingang-quan");
        
        prepare_skill("strike", "xiake-strike");

        create_family("侠客岛",2,"传人");
        
        setup();
//      carry_object("")->wield();
//      carry_object("")->wear();
}

void init()
{
	object ob;
	::init();
	ob = this_player();
	if ((string)ob->query("startroom") == "/d/xiakedao/shishi1")
	ob->set("startroom","/d/city/kedian");
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
