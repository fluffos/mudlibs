// cao
inherit NPC;
#include <ansi.h>

string ask_toy();
string ask_work();
string ask_workover();

void create()
{
        set_name("监工", ({ "jian gong", "gong" }) );
        set("gender", "男性" );
        set("age", 28);
        set("long", 
            "此人是采石场的监工，他正瞪着一双牛头大眼看着你。\n");
        set("combat_exp", 10000);
        set("max_jing", 300);
        set("max_qi", 300);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 20);
        set("attitude", "friendly");
        set("inquiry", ([
            "采石" : "这里就是采石场，我就是这里的监工。",
            "石头" : "满地的石头你看不见呀！",
            "工具" : (: ask_toy :),
            "工作" : (: ask_work :),
            "交工" : (: ask_workover :),
       ]) );

        setup();

        set("hammer_count", 4);
         set("chat_chance", 5);
         carry_object("/clone/cloth/cloth")->wear();
}
int accept_fight()
{
        command("say 一边去，没见我正忙着呢，哪凉快哪呆着去！");
        return 0;
}

string ask_toy()
{
        object ob;
        
        if(present("hammer" , this_player()))
                return "你身上不是有吗？还想要，是不是存心捣蛋啦！";
        if (query("hammer_count") < 1)
                return "我现在手头上也没有，你再等会儿吧！";
        add("hammer_count", -1);
        ob = new("/clone/weapon/hammer");
        ob->move(this_player());
        return "监工说道：“接稳喽！”\n监工给了你一把铁锤。";
}

string ask_work()
{
        if(!this_player()->query("old_title"))
        {
                if ( !this_player()->query("old_title") )
                       this_player()->set("old_title",this_player()->query("title"));
//                this_player()->set("title",HIY"采石工"NOR);
                this_player()->set_temp("stonework",0);
                return "还不去工作，还想不想挣钱了？";
        }
        return RANK_D->query_respect(this_player()) + 
        "不是有工作了吗？难道你想不干了？那你就交工吧！";
}
string ask_workover()
{
        object me, silver;
        me = this_player();
          if(!me->query("old_title"))
                return "你这是什么意思，你想干什么呀？";
        if(me->query_temp("stonework")<6)
        {
               me->set("title",this_player()->query("old_title"));
               me->delete_temp("stonework");
               me->delete("old_title");
               command("nod " + this_player()->query("id"));
               return "来去自由，随便你了！不过就是有点儿可惜了你这样的一个好劳力！\n";
        }
        else 
        {
        this_player()->set("title",this_player()->query("old_title"));
        this_player()->delete_temp("stonework");
        this_player()->delete("old_title");
        silver = new("/clone/money/silver");
        silver->set_amount(random(10)+1);
        silver->move(this_player());
        command("pat " + this_player()->query("id"));
        return "你任劳任怨，真是我的好帮手，但愿这里的人都能象你这样，那就好了！这是你应得的！\n";
        }
}


