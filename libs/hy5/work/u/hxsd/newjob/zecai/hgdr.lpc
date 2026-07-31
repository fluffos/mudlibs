// huogongdaoren.c 火工道人
// by mask 1999/11
inherit NPC;

#include <ansi.h>;
int ask_me() ;
void create()
{
        set_name("火工道人", ({ "daoren" }));
        
        set("long", 
                "他就是一个年长的出家人。\n");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 15);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 15);
        set("combat_exp", 100000);
        set("score", 20000);
        set("inquiry", ([
             "工作" : (: ask_me() :),
             "work" : (: ask_me() :),
        ])); 
        set("count",10); 
        setup();
}


int ask_me()
 {
 object me;
 mapping myfam;
 me=this_player();
        
 myfam = (mapping)me->query("family");

 if ((!myfam || myfam["family_name"] != "武当派"))
 return notify_fail("道人对你说道：“这是我武当派的事，与你何干？”\n");

 if (query("count")<1)
 return notify_fail("道人说道：“今天没什么事了，你明天再来吧。”\n");

 if (!me->query_temp("questd"))
 {
 tell_object(me,"道人对你说道：“去菜地里摘点菜回来给我。”\n"); 
 add("count",-1);
 me->set_temp("job",1);              
 return 1;       
 }

 else 
 tell_object(me,"道人对你说道：“快去做你的事，不许偷懒？”\n");
 return 1;
 }
int accept_object(object me, object ob)
{
        
        command("smile");
        if((string)ob->query("id")=="xian cai") 
        { 
                remove_call_out("destroying");
                call_out("destroying", 1, this_object(), ob);

                if(me->query_temp("job")!=1) 
                return notify_fail("道人对你笑着说：“好，我们正等着做菜呢！”\n"); 
                if(me->query_temp("cai")!=1)
                return notify_fail("道人对你笑着说：“好，我们正等着做菜呢！”\n");        

                  command("say 太好了，我们正等着给大伙做饭呢！");
                  me->delete_temp("job"); 
                  me->delete_temp("cai");
                  me->add("combat_exp",10);
                  me->add("potential",5); 
                  tell_object(me,HIY"你得到了火工道人的奖励。\n"NOR,me);

                return 1;
        }
}
void destroying(object me, object ob)
{
        destruct(ob);
        return;
}


