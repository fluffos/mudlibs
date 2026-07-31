// zhangcui.c
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
string ask_huijia2()
{
 object ob,me=this_player();
 int i;
i=query_temp("marks/bing");
//if(!i=0)

if(!me->query_temp("marks/bing"))
{
write("谢谢你送无忌回来,这本书留做纪念吧.\n");
ob=new("/d/binghuodao/npc/obj/force_book");
me->set_temp("marks/bing/zhang",1);
ob->move(me);
return "\n";
}
else 
{
return "无忌出去玩,还没回来,帮我们找找吧.\n";
}
}



string ask_huijia()
{
 object me,ob,ob1,ob3;
int a,b;
// object *ob_list;
// int i;
int i;
me=this_player();
a=me->query_temp("marks/bing");
b=me->query("mufa");
//if(a=0)
if(!me->query_temp("marks/bing"))
{
return "无忌找到了吗?\n";}
//else if(!me->query_temp("marks/bing"))
else if(!me->query("mufa"))
{return "木筏造好了吗.\n";}
else
{ob=new("/d/binghuodao/npc/zhangcui");
ob->move("/d/binghuodao/road11");
ob1=new("/d/binghuodao/npc/susu");
ob3=new("/d/binghuodao/npc/wuji");
ob1->move("/d/binghuodao/road11");
ob3->move("/d/binghuodao/road11");
write("你们走吧.\n");
destruct(present("mufa",me));
ob->move("/d/binghuodao/mufa");
ob1->move("/d/binghuodao/mufa");
ob3->move("/d/binghuodao/mufa");
me->move("/d/binghuodao/mufa");
me->delete_temp("marks/bing");
me->delete("mufa");
tell_object(me, BLU "你在海上航行了很久很久.......\n" NOR ) ;
call_out("goto_taohua",20,me);
}
return "走吧.\n";
}
void goto_taohua (object ob)
{
object ob1,ob2,ob3;   
object who;
int i;
who=ob;
tell_object(ob , "大船终于停在了一个渔港。你走下船来。\n" ) ;
   ob->move ("/d/tanggu/gangkou") ;
ob2=new("/d/binghuodao/npc/zhangcui");
ob2->move("/d/tanggu/gangkou");
ob1=new("/d/binghuodao/npc/susu");
ob1->move("/d/tanggu/gangkou");
ob3=new("/d/binghuodao/npc/wuji");
ob3->move("/d/tanggu/gangkou");
destruct(ob1);
destruct(ob2);
destruct(ob3);

  	if(!who->query("jinyong/book12") && who->query("combat_exp",1) > 500000)
{
		i = 900+random(2000);
		who->set("jinyong/book12",1);
		who->add("combat_exp",i+9000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+9000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}

tell_object(ob,"谢谢你帮我们回到中土.传你些江湖阅历.我们就此告别.\n");
//tell_object(ob,"我们就此告别.\n");
if(!ob->query("send_zhang"))
{ob->set("send_zhang",1);
ob->add("combat_exp",500);}
else {ob->add("combat_exp",1);}
ob->delete("mufa");
ob->delete_temp("marks/bing");
}

string ask_zhaochuan()
{
object me;
me = this_player () ;

if (!present("mu chai", me) && !present("chang teng",me))
{
//write("你身上没有材料！\n");
return "你身上没有材料！\n";
}
if (present("mu chai", me) && present("chang teng",me))
{
write("一会木筏作好通知你.\n");
destruct(present("mu chai",me));
destruct(present("chang teng",me));
call_out("make_chuan",20,me);
return "一会木筏作好通知你.！\n";

}
}

void make_chuan(object who,object me)
{
object ob;
me = this_player () ;
tell_object(who,"船好了.\n");
ob=new("/d/binghuodao/npc/obj/chuan");
ob->move(me);
//ob->move("/d/binghuodao/road11");
me->delete_temp("teng");
me->delete_temp("mutou");
me->set("mufa",1);
}



void create()
{
set_name("张翠山", ({ "zhang cuishan", "zhang" }));  
set("nickname","武当五侠");
        set("long", 
                "他就是张三丰的五弟子、武当七侠之中的张翠山。\n"
                "身穿一件干干净净的白色道袍。\n");
        set("gender", "男性");
        set("age",31);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 35);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 600000);
        set("per", 28);

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
        set_skill("unarmed", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");

        create_family("武当派", 2, "弟子");
set("inquiry", ([
        "张无忌" : (:ask_huijia2:) ,
        "回中土" : (:ask_huijia:) ,
        "造船" : (:ask_zhaochuan:) ,
         ]) );
        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.zhen" :),
                (: exert_function, "recover" :),
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/binghuodao/npc/obj/skin")->wear();

}
void attempt_apprentice(object ob)
{
                command("say 我是已无面目再回去见师傅他老人家了，如何还敢收徒。");
                return;

}
