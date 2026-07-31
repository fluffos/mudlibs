// XieXun.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
// inherit F_MASTER;
inherit F_UNIQUE;

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

  	if(!who->query("jinyong/book12"))
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
//destruct(present("mu chai",me));
destruct(present("chang teng",me));
call_out("make_chuan",20,me);
return "一会木筏作好通知你.！\n";

}
}

void create()
{
        set_name("谢逊", ({"xie xun", "xie", "xun", }));
        set("long",
        "他是一位身材魁伟异常的的老者，身穿一件白布长袍。\n"
        "他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。\n"
        );

        set("title",HIG "明教" HIY "金毛狮王" NOR);
        set("level",9);
        set("gender", "男性");
        set("attitude", "peaceful");

        set("age", 63);
        set("shen_type", 1);
        set("per", 25);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 15500);
        set("max_jing", 15500);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 250);

        set("combat_exp", 8000000);
        set("score", 800000);

        set_skill("force", 260);
        set_skill("dodge", 240);
        set_skill("sword", 240);
        set_skill("blade", 240);
        set_skill("parry", 240);
        set_skill("cuff", 200);
        set_skill("blade", 250);
        set_skill("jinwu-daofa", 250);
        set_skill("jiuyang-shengong", 250);
        set_skill("lingxu-bu", 250);
        set_skill("damo-jian", 250);
        set_skill("qishang-quan", 250);
        set_skill("hunyuan-zhang", 250);
        set_skill("literate", 100);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "lingxu-bu");
        map_skill("cuff", "qishang-quan");
        map_skill("parry", "hunyuan-zhang");
        map_skill("sword", "damo-jian");
        map_skill("blade", "jinwu-daofa");

        set_temp("apply/attack", 700);
        set_temp("apply/defense", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        prepare_skill("cuff","qishang-quan");

        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: command("perform hunpofeiyang") :),
        }) );
        create_family("明教",35, "法王");
set("inquiry", ([
        "回中土" : (:ask_huijia:) ,
        "造船" : (:ask_zhaochuan:) ,
         ]) );
set("chat_chance",8);
        set("chat_msg",({
           "谢逊抚刀沉思道:屠龙刀啊屠龙刀,你到底有什么秘密呢?\n",
           "谢逊恨恨的说道:成昆老贼,你害我家破人亡,我不亲手杀了你,死不瞑目.\n"
        }) );
        setup();
         carry_object(__DIR__"obj/killdragon")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wear();
}
/*
void init()
{
        object me,ob;
        me = this_object () ;
        ob = this_player () ;

        ::init();

        if (interactive(this_player()) && this_player()->query_temp("fighting"))
        {
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
                this_player()->add_temp("beat_count", 1);
        }       
        if( interactive(ob) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me, ob);
        }
}
*/
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

int accept_object(object who,object ob,object me)
{
        me = this_player () ;
//if(query_temp("marks/bing"))
//{
if(ob->query("id")=="teng") me->set_temp("teng",1);
if(ob->query("id")=="mu chai") me->set_temp("mutou",1);

if(me->query_temp("mutou"))
{
if(me->query_temp("teng")) 
{
write("一会木筏作好通知你.\n");
call_out("make_chuan",20,who);
//return "请你等一会!.\n";  
}
}
return 1;
}

void die()
{
        object ob;
        
        ob = this_object();
        write("谢逊大叫一声！逃下了山去，不见了人影。\n");
        destruct(ob);
        return;
}
