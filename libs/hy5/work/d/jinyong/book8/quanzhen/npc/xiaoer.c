// xiaoer.c 小二

inherit NPC;
inherit F_DEALER;
int ask_me();

void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ({
                "/d/quanzhen/npc/obj/jitui",
                "/d/quanzhen/npc/obj/jiudai",
                "/d/quanzhen/npc/obj/baozi",
        }));
        
        set("inquiry", ([
	     "打架": (: ask_me :),
	     "fight": (: ask_me :),
       	]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
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
        switch( random(3) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来打个尖，歇歇脚吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                	if(ob->query("jinyong/book8"))
                	{
	                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
	                                + "，请进请进。\n");
	                        break;                	
	                }
                	else
                	{
	                        say( "店小二苦着脸说道：这位" + RANK_D->query_respect(ob)
	                                + "，楼上有人打架闹事，抱歉招呼不周，请多担待。\n");
	                        ob->set_temp("jinyong/book8/xiaoer",1);
	                        break;
                    	}
        }
}

int ask_me()
{
	int i;

	object who = this_player();
	if(!who->query_temp("jinyong/book8/xiaoer"))
	{
		message_vision("$N对$n说道： 什么打架？ 客官千万别乱说，搅了小店的生意。\n",this_object(),who);
		return 1;
	}
	else
	{
		message_vision("$N对$n说道： 楼上来了个自称青城派的闹事，和另外一个华山派的剑客正打着呢。\n",this_object(),who);
		message_vision("我看客官也是武林人士，能否帮忙劝解一下，小店感激不尽。\n",this_object());
		who->delete_temp("jinyong/book8/xiaoer");
		who->move("/d/jinyong/book8/quanzhen/jiulou2");
		return 1;
	}
}