//黄衣大汉
//for xiakedao 
// modified by aiai 98/10/27

#include <ansi.h>

inherit NPC;

int ask_dao();
int ask_qudao();

void init();
void delete_served();
void create()
{
	set_name(HIY"黄衣大汉"NOR, ({"huangyi dahan","dahan","huangyi"}) );
       	set("gender", "男性" );
        set("age", 30);
	set("long",
	  "他看起来三十多岁，武工深浅看不出来。但从他的衣着打扮来看，\n"
	  "他一定是侠客岛的人。\n");
	set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 35);
        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
	set("combat_exp", 300000);
        set("score", 10000);
        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("parry", 120);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 50);
        set("inquiry",([
	"侠客岛" : (: ask_dao :),
	"去侠客岛" : ( : ask_qudao :),
	]));
        setup();
        
        carry_object("/d/city/obj/cloth")->wear();
}
int ask_dao()
{
	say("侠客岛便在这附近，岛主每逢腊月初八，都会请各路英雄到岛上一聚，一起喝那腊八粥。\n");
	this_player()->set_temp("marks/侠客岛",1);
	return 1;
}

int ask_qudao()
{

	object me,room;
	object ob,ling;
	me = this_player();
    if ( ! me->query("menpai") ) {
	if ( (! me->query("xkdling")) || ( !objectp(ling = present("shangshanfae ling", me))) )
	{
		say("对不起，我们岛主分付过，只能带接到过他赏善罚恶令的人前往侠客岛。\n");
		return 1;
	}
    }
	if((int)this_player()->query_temp("marks/侠客岛"))
	{
		say("欢迎贵客光临侠客岛，请你上船。\n");
		this_player()->set_temp("marks/去岛",1);
		this_player()->delete_temp("marks/侠客岛");
		message_vision("大汉轻身一跃，跳上船头。\n",me);
        if ( objectp(ling) )
            destruct(ling);
		ob = this_object();
		destruct(ob);
		return 1;
	}
	else
	{
		say("你没事过海干什么？\n");
		return 1;
	}
}

