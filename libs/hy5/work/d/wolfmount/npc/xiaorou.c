#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("嬉小柔", ({"xiaorou"}) );
        set("gender", "女性" );
        set("nickname", HIG "迷狼"NOR);
        set("long", "她穿得很随便，两边开叉的长裙，每走一步都会露出大腿来。\n");
        set("attitude", "friendly");
/*      set("max_jing", 300);
        set("max_qi", 300);
        set("max_jing", 300);  */
        set("age", 15+random(5));
//      set("str", 10);
        set("cor", 10);
        set("cps", 15);
        set("combat_exp", random(100000)+100000);
        create_family("狼山", 1, "第四代弟子");
   set("max_qi", 13500);
        set("jing", 12000);
        set("max_jing", 12000);
        set("neili", 13500);
        set("max_neili", 13500);
        set("jingli", 12000);
        set("max_jingli", 11000);

        set("combat_exp", 3500000);
        set("score", 1000);
        set_skill("persuading", 280);
        set_skill("force", 100);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("claw", 100);
        set_skill("literate", 200);
        set_skill("mahayana", 250);
        set_skill("jinding-zhang", 200);
        set_skill("jiuyin-baiguzhao", 300);
        set_skill("tiangang-zhi", 200);
        set_skill("huifeng-jian", 290);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 320);
        set_skill("feiyu-bian", 200);
        set_skill("bagua-dao", 180);
        set_skill("bagua-zhang", 180);

        set_skill("huixin-strike", 380);
        set_skill("piaoxue-hand", 380);
        set_skill("yinlong-whip", 380);
        set_skill("yitian-jian", 380);
        set_skill("whip", 220);
        set_skill("hand", 220);
        
        map_skill("force","linji-zhuang");
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        map_skill("whip","yinlong-whip");

	        map_skill("hand","piaoxue-hand");
        map_skill("strike","huixin-strike");
        map_skill("parry","yinlong-whip");
        map_skill("sword","yitian-jian");
        prepare_skill("strike", "huixin-strike");
        prepare_skill("hand", "piaoxue-hand");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "whip.duoming" :),
                (: perform_action, "whip.zhu" :),
                (: perform_action, "strike.cuixin" :),
                (: perform_action, "strike.gu" :),
                (: perform_action, "hand.yun" :),
                (: perform_action, "hand.zhao" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "嬉小柔眼睛里带着种梦幻般的憧憬，痴痴道：“每天吹起七彩海螺时，\n就是黎明到来的时刻。”\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
} 
void init()
{
        object conch;
        ::init();
        if( ! this_object()->query("given") )
        {
                this_object()->set("given",1);
                if (!random(3))
                {
                        conch=new(__DIR__"obj/conch");
                        conch->move(this_object());
                   return;
                }
                else
                {
                        say("嬉小柔轻抚着你的脸，梦呓般低语．．．．\n");
                        return;
                }
        }
        return;
}  
