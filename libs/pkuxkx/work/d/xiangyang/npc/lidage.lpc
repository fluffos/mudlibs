#include <ansi.h>
string ask_for_lan();  
void bu(object me,object ob);
inherit NPC;
void create()  
{	set_name("李大哥", ({ "li dage","li"}));
	set("gender", "男性");
       set("age", 25);
	set("str", 17);
	set("dex", 16);
	set("long", "这是一个二十多岁的小伙子。\n");
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 60);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set("neili", 400); 
	set("max_qi", 600); 
	set("qi", 600); 
	set("max_neili", 400);
	set("neili", 400);      
        set("inquiry",([  
              "小兰"  : (: ask_for_lan :),
              
          ]));

        setup();

}

int dest(object ob)
{
    destruct(ob);
    return 1;
}

int accept_object(object me, object ob)
{
        object obj;
        if (ob->query("id")!="dahong tubu" && ob->query("id")!="qianlv shabu" && ob->query("id")!="tianlan jinduan" && ob->query("id")!="fenhong sichou")
        {
            return notify_fail("李大哥根本不想要你的东西。\n");
        }
        if (!me->query_temp("布料") ) 
        {
            return notify_fail("李大哥说道：咦？你给我这些干什么呀？\n李大哥把布料又还给了你。\n");
        }
        else 
            { 
               command("blush");
               command("xixi " + this_player()->query("id"));
               me->set_temp("小兰",1);
               me->delete_temp("布料"); 
               command("say 你真细心，猜到了我的心事,可是我自己不敢去，你帮我送给她好吗？");
               message_vision("李大哥把布料又还给了$N。\n", me);
		       obj=new(__DIR__"obj/buliao1");
               obj->move(me);
               call_out("dest",1,ob);
               return 1;
            }
        

}
string ask_for_lan()
{    
        command("say 小兰妹妹的两个哥哥都在战场上死了，真可怜.");
        command("say 其实我挺喜欢她的，我想给她卖块好料子做件衣裳，可是我没有钱.\n");
        command("sigh");
        this_player()->set_temp("布料",1);
        return "你能帮我吗?";
}
void bu(object me,object ob)
{
command("give bu to " + me->query("id"));
return;
}
