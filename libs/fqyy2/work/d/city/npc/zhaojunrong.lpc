// zhaocaifeng.c 赵俊容-裁缝
// 20:47 99-1-17
#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
int ask_done();
void create()
{
        set_name("赵俊蓉", ({"zhao junrong", "zhao"}));
        set("gender", "女性");
        set("age", 30);
        set("long", 
                "她是扬州城内有名的裁缝，江湖人称赵天衣。\n");
        set("attitude", "peaceful");             
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("neili", 120);
        set("max_neili", 120);
        set("jiali", 0);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set_skill("force", 10); 
        set_skill("unarmed", 10); 
        set_skill("dodge", 10); 
        set_skill("parry", 10);          

        set("inquiry", ([
                "工作" : (: do_gongzuo :),
        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
}
int do_gongzuo()
{      
        object me;
        me = this_player(); 
        if (me->query("combat_exp")>=10000)
        {
               command("say 你的武功比我恩公叶欢还要高了，这种小事不敢您大架。\n");
               return 1;
         }
    if( me->query_temp("gongzuo/yunbu")>0)
    {
                tell_object(me,"快去把布匹熨好后交给我吧。\n");
                return 1;
    }  
    message_vision(CYN"赵俊容对$N说道：现在熨好的布匹不够用了，你就到后面的库房里去熨些布来。\n"NOR,me); 
        me->set_temp("gongzuo/yunbu", 1);
        return 1;   
}
int accept_object(object me, object ob)
{
        object ob1;
        if (strsrch(ob->query("name"), "熨好的布") < 0) 
        {
            command("say 你别来蒙我啦，这是熨好的布吗？\n");
        }
        else if (me->query_temp("gongzuo/yunbu")<1)
        {
         command("say 我没有叫你帮我熨布呀！\n");
        }
        else
        {
    message_vision(CYN"赵俊容对$N说道：辛苦了，这是你的工钱。\n"NOR,me);
    message_vision(CYN"赵俊容递给$N一些铜钱。\n"NOR,me);  
                me->delete_temp("gongzuo/yunbu");
                me->add("combat_exp",20+random(20));
                me->add("potential",10+random(10));
                ob1=new("/clone/money/silver");
                ob1->move(me); 
    call_out("destroying", 1, this_object(), ob);
            return 1;
        }
    return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

