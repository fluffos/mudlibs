// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;
void create()
{
	set_name("美蚕娘", ({ "mei canniang" , "mei" , "canniang" }));
	set("nickname", CYN"倾国倾城"NOR); 
	set("long",
	"她是美蚕娘， 容貌姣好，楚楚动人\n");
	set("gender", "女性");
	set("age", 19);
	set("attitude", "peaceful");
        set("vendor_goods", ([
              __DIR__"obj/hongmg":20,
              __DIR__"obj/mudan":20,
              __DIR__"obj/shaoyao":20,
              __DIR__"obj/shbxsh":20,
              __DIR__"obj/juhua":20,
              __DIR__"obj/shchhua":20,
]));
	set("shen_type", 1);
	set("str", 10);
	set("int", 10);
	set("con", 10);
	set("dex", 10);
	set("per", 30);
	set("combat_exp", 100);
	set("score", 10000000);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10); 
//     add_action("do_vendor_list", list);
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
 	command("say 这位"+(string)RANK_D->query_respect(me)+"要买花吗？
上好的鲜花！这是奴家亲手种的。\n");
}
