//侠客行100海洋版II
// xiaoer.c 平安城店小二
//星星lywin 2000/6/1 儿童节

#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
int ask_done();
void create()
{
        set_name("大师傅", ({"shifu", "fu"}));
        set("gender", "男性");
        set("age", 45);
        set("long", 
                "他是小吃店的做菜大师傅。\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
}
int do_gongzuo()
{      
        object me;
        me = this_player(); 
        
    if (me->query("combat_exp")>=30000)
    {
                tell_object(me,"这点小事怎么敢劳您的大驾。\n");
                return 1;
    }  
    if( me->query_temp("gongzuo/zuocai")>0)
    {
                tell_object(me,"快去做菜吧。\n");
                return 1;
    }  
    message_vision(CYN"大师傅对$N说道：这几天客人多！菜做不过来，你帮我做菜吧。\n"NOR,me); 
        me->set_temp("gongzuo/zuocai", 1);
        return 1;   
}
int accept_object(object me, object ob)
{
        object ob1;
        if (me->query_temp("gongzuo/zuocai")<1)
        {
         command("say 你没有找我要过工作吧。\n");
        }
        else if ( ob->query("name") != "做好的菜" )
//        else if (strsrch(ob->query("name"), "做好的菜") < 0) 
        {
            command("say 这是做好的菜？你不是开玩笑吧！\n");
        }
        else
        {
    message_vision(CYN"大师傅对$N说道：辛苦了，这是你的工钱。\n"NOR,me);
    message_vision(CYN"大师傅递给$N一些银子。\n"NOR,me);  
                me->delete_temp("gongzuo/zuocai");
                me->delete_temp("gongzuo/zuocai");
                if (me->query("combat_exp")>=15000)
                {
                  me->add("combat_exp",2);
                  me->add("potential",1);
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  call_out("destroying", 1, this_object(), ob);
                }
                else if (me->query("combat_exp")< 15000)
                {
                me->add("combat_exp",50+random(10));
                me->add("potential",30+random(10));
                ob1=new("/clone/money/silver");
                ob1->move(me); 
                ob1=new("/clone/money/silver");
                ob1->move(me); 
                call_out("destroying", 1, this_object(), ob);
                }
            return 1;
        }
    return 0;
}

void destroying(object me, object obj)
{
//        destruct(obj);
        return;
}
