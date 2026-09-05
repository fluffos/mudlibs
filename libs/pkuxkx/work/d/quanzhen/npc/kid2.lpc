// kid2.c
// Made by Ysg(1997.10.22)

#include <ansi.h>
inherit NPC;

void ask_ren(object who);
void ask_ling(object who);

string *name =({
YEL"孙悟空糖人"NOR,YEL"猪八戒糖人"NOR,YEL"沙僧糖人"NOR,YEL"唐僧糖人"NOR,
});
string comm_name(){
	return name[ random( sizeof(name) ) ];
}   
string name = comm_name();

void create()
{
	set_name("小孩",({ "kid" }) );
        set("gender", "男性" );
        set("age", 7);
        set("long", 
	"这是个富人家的小孩子，头上扎着个冲天小辫，看上去活波可爱。\n");
        set("combat_exp", 200);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "friendly");
	set("chat_chance", 10);
	set("chat_msg", ({
		"小孩兴奋的拍着手说：“看糖人喽，真好玩。\n",
		"小孩看着糖人，不禁口水都流下来了。\n",
	}));
	set("inquiry", ([
                "糖人"   : (: ask_ren :),
		"令牌"   : (: ask_ling :),
        ]));
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}

void greeting(object me)
{
	if( me->query_temp("ling") ) me->delete_temp("ling");
	message_vision("小孩用祈求的眼光看着$N。\n", me);
}

int ask_ren(object who)
{
	message_vision("$N歪着头想了想，道：“"+RANK_D->query_close(who)+
	"，我拿别的东西跟你换糖人，你说好不好？”\n", this_object());
	return 1;
}

int ask_ling(object who)
{
	if( who->query_temp("ling") ){
	tell_object(who,"小孩摇摇头，说：“我不知道这是什么，这是我从家里偷出来的。\n"
	"听说是很贵重的东西哟。\n");
	return 1;
	}
	return 0;
}

int accept_object(object who, object what)
{	
	object obj;

	if( strsrch( (string)what->query("name"), "糖人") != -1 ){
		if( (string)what->query("name") == name && !userp(what) ){
			tell_object(who,"小孩悄悄的给你一个令牌。\n");
			tell_object(who,GRN"小孩在你耳边轻轻的说：你可不要告诉别人哦。\n");
			who->set_temp("ling");
			obj = new(__DIR__"obj/lingpai");
			obj->move(who);
			return 1;
		} else {
		message_vision("$N摇摇头头说：我不要这个，我要的是"+name+"\n", this_object());
		return 1;
		}
	}
	tell_object(who,"小孩一脸不高兴的样子，说道：“不羞，不羞，大人骗小孩子。”\n");
	command("shake "+who->query("id"));
	return 1;
}
