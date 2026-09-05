#include <ansi.h>
inherit NPC;
string ask_for();
void create()  
{	set_name("猎户", ({ "lie hu","hu"}));
	set("gender", "男性");
        set("age", 65);
	set("str", 21);
	set("dex", 16);                                  
	set("long", "他是本地的一个猎户，躺在床上，不住的呻吟,看样子病的不轻。\n");
	set("combat_exp", 1000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 20);
	set_skill("force", 30);
	set("neili", 100); 
	set("max_qi", 100); 
	set("qi", 100); 
	set("max_neili", 100);
       
        set("inquiry",([  
              "求医"  : (: ask_for :),
                "大夫"  : (: ask_for :),
                  "医生"  : (: ask_for :),

          ]));


        set("chat_chance", 10);
        set("chat_msg", ({    
       "救命啊，我在山上打猎的时候，被毒蛇给咬伤了。谁去帮我找个医生啊，我快不行了！\n",
                }) );
        setup();
	carry_object(__DIR__"obj/cloth")->wear();

}

string ask_for()
{       object me=this_player();
        me->set_temp("qiuyi", 1);
        command("thank " + me->query("id"));
        return "襄阳城中有一位名医，名叫程神医，你去帮我叫她来，她一定能治我的伤!";
}
int destroying(object ob)
{
        destruct(ob);
        return 1;
}
int accept_object(object me, object ob)
{

        if (ob->query("id")=="shanling wan" && me->query_temp("送药") )
     {
               command("wa " + me->query("id"));
               me->delete_temp("送药"); 
                command("say 谢谢你啦.");
               this_object()->start_busy(4);
                call_out("destroying",1,ob);
                me->set("shen",(int)me->query("shen") + 5000);
                return 1;
        
    }
}
