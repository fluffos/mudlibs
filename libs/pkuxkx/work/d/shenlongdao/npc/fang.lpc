#include <ansi.h>
//fang yi
inherit NPC;

string ask_me();
int ask_wxb();
string ask2();
string ask3();
//void heal();
void create()
{
        set_name("方怡", ({ "fang yi", "fang" }));
        set("title",MAG "神龙教" NOR + HIC +"圣女" NOR);
        set("long",
                "她就是方怡，不知道什么时候和沐剑屏一起来的神龙岛。\n"
                "她虽然艳如桃李，但看起来冷若冰霜。\n");
        set("gender", "女性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
      
       
        set("shen_type", 1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);
        set("per", 25);
        set("chat_chance", 100); 
        set("chat_chance_combat", 100);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set("combat_exp", 50000);
        set("score", 10000);
        set_skill("force", 60);
        set_skill("shenlong-xinfa", 60);
        set_skill("dodge", 60);
        set_skill("whip", 60);
        set_skill("shenlong-bian", 60);        
        set_skill("yixingbu", 60);
        set_skill("cuff", 60);
        set_skill("meinu-quan", 60);
        set_skill("parry", 60);
        set_skill("kuai-dao",60);
        set_skill("blade", 60);
        set_skill("literate", 60);
         map_skill("force", "shenlong-xinfa");
        map_skill("dodge", "yixingbu");
        map_skill("cuff", "meinu-quan");
        map_skill("parry", "kuai-dao");
        map_skill("whip", "shenlong-bian");
        create_family("神龙教", 3, "弟子");
        setup();
        carry_object("/clone/weapon/changbian")->wield();
 
        set("inquiry", ([
        "韦小宝":   (: ask_wxb() :),
            ]));
        set("book_count", 1);
        setup();

        carry_object("/d/gumu/obj/white")->wear();
}






int ask_wxb()
{
        object ob,letter,me;
        me=this_object();
        ob=this_player();
        if((int)ob->query_temp("shenlong/findwxb_fang")==1)
        {
        command("ah");  
        command("say 他居然还记挂着我！？"); 
        letter = new("/d/shenlongdao/obj/letter_fangyi");
        letter->move(ob);
        command("say 烦劳你把这封信带给我他，让他快来接我！"); 
        command("blush");
        return 1;
        }
        command("say 韦小宝这臭贼自从离岛之后渺无音讯，多半是找了其他女人！");
        command("hate1x");
        command("heng fang yi");
        command("say 找到他之后一定抽他的筋，拨他的皮！");    
        return 1;
}
