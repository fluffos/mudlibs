#include <ansi.h>

inherit NPC;

void create()
{
        set_name("锺兆英", ({ "zhong zhaoying", "zhong", "zhaoying", "ying" }));
        set("long", @LONG
这人是锺氏三雄的老二锺兆英。只见他身穿白
色粗麻布衣服，白帽白鞋，衣服边上露着毛头，
竟是刚死了父母的孝子服色，脸色惨白，鼻子
又扁又大，鼻孔朝天，留着黑胡子。
LONG );
        set("nickname", HIR "锺氏三雄" NOR);
        set("title", "鄂北锺氏兄弟");
        set("gender", "男性");
        set("age", 43);
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 27);
        set("con", 25);
        set("dex", 24);

          set("qi", 14500);
        set("max_qi", 14500);
        set("jing", 13000);
        set("max_jing", 13000);
        set("neili", 13000);
        set("max_neili", 13000);
        set("jiali", 80);
        set("combat_exp", 1800000);
        set("score", 3000);

      set_skill("force", 160); 
        set_skill("lengyue-shengong", 160); 
        set_skill("dodge", 240); 
        set_skill("taxue-wuhen", 140); 
        set_skill("sword", 160); 
       
        set_skill("blade", 140); 

        set_skill("strike", 260); 
        set_skill("cuff", 260); 
        set_skill("tianchang-strike", 160); 
        set_skill("parry", 160); 
        set_skill("literate", 140); 
        set_skill("martial-cognize", 160); 


        set_skill("hujia-quan", 380); 
        

        map_skill("force", "lengyue-shengong"); 
        map_skill("dodge", "taxue-wuhen"); 

        map_skill("parry", "miaojia-jian"); 
        map_skill("strike", "tianchang-strike"); 
        map_skill("cuff", "hujia-quan"); 
        
        prepare_skill("strike", "tianchang-strike"); 
        prepare_skill("cuff", "hujia-quan"); 

        create_family("鄂北锺氏", 6, "传人");

        setup();

        //carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 15);
}

void attempt_apprentice(object ob)
{
        command("hmm");
        command("say 走开，我不收徒。");
}

