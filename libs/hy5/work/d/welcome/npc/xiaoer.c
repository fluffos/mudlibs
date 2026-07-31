//侠客行100海洋版II
// xiaoer.c 平安城店小二
//星星lywin 2000/6/1 儿童节

#include <ansi.h>
#include <command.h>
inherit NPC;
inherit F_DEALER;
#include "/quest/givegift.c"
void consider();
int do_gongzuo();
int ask_done();
void create()
{
        set_name("店小二", ({"xiao er", "xiao"}));
        set("gender", "男性");
        set("age", 25);
        set("long", 
                "他是平安客栈的店小二。\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
		"/d/city/npc/obj/sniurou",
		"/d/city/npc/obj/sjiudai",
	        "/d/bawang/npc/obj/shaoji",
	}));
        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
        ]) );

        setup();
        
        carry_object("clone/cloth/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {

			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

int do_gongzuo()
{      
        object me;
        me = this_player(); 
        
    if (me->query("combat_exp")>=80000 && !wizardp(me)  && me->query("nbjob",1)!=8)
    {
                tell_object(me,"这点小事怎么敢劳您的大驾。\n");
                return 1;
    }  
    if( me->query_temp("gongzuo/xipanzi")>0)
    {
                tell_object(me,"快去洗盘子吧。\n");
                return 1;
    }  
    message_vision(CYN"小二对$N说道：这几天客人多！盘子洗不过来，你去厅堂找管事要点盘子来洗吧。\n"NOR,me); 
        me->set_temp("gongzuo/xipanzi", 1);
        return 1;   
}
int accept_object(object me, object ob)
{
        object ob1;
        int exp,pot;
        if (me->query_temp("gongzuo/xipanzi")<1)
        {
         command("say 你没有找我要过工作吧。\n");
        }
        else if ( ob->query("name") != "盘子" )
//        else if (strsrch(ob->query("name"), "盘子") < 0) 
        {
            command("say 这是洗好的盘子？你不是开玩笑吧！\n");
        }
        else
        {
    message_vision(CYN"小二对$N说道：辛苦了，这是你的工钱。\n"NOR,me);
    message_vision(CYN"小二递给$N一些银子。\n"NOR,me);  
                me->set_temp("nbjob9",1);
                me->delete_temp("gongzuo/xipanzi");
                me->delete_temp("gongzuo/gepanzi");
                if (me->query("combat_exp")>=5000)
                {
                  //me->add("combat_exp",2);
                  //me->add("potential",1);
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  exp=3;
                  addnl(me,"exp",exp);
me->set_temp("nbjob9",1);
                  call_out("destroying", 0, this_object(), ob);
                }
                else if (me->query("combat_exp")< 5000)
                {
                //me->add("combat_exp",30+random(10));
                //me->add("potential",10+random(10));
                ob1=new("/clone/money/silver");
                ob1->move(me); 
                exp=30+random(10);
                me->set_temp("nbjob9",1);
                addnl(me,"exp",exp);
                call_out("destroying", 0, this_object(), ob);
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
