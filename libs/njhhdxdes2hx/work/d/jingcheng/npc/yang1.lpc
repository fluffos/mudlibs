//created by ysg,add by kiss
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("扬中顺", ({ "yang zhongshun" , "yang" , "zhongshun" }));
	set("title","药铺掌柜");
	set("nickname", CYN"袖手神医"NOR); 
	set("long",
	"杨老板是长安城里祖传的名医。虽然年轻，却早已名声在外。不过他有个怪僻：就是不高兴的时候，\n"
	"任你天王老子、就是当今皇上来了也无济于事，他就是不愿意管。所以才得了「袖手神医」这么一个名头。\n");
	set("gender", "男性");
	set("age", 35);
   set("vendor_goods",([
         __DIR__"obj/jinchuang":20,
        __DIR__"obj/gao":20,
   ]));
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 30);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", random(100000));
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"扬中顺冷冷的瞅了你一眼，扭过头去继续看他的永远看不完的医书。\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
        add_action("do_vendor_list","list");
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
string greeting(object me)
{
	int my_max_qi;
	
	my_max_qi = me->query("max_kee");

	if( ((int)me->query("kee")*100/my_max_qi) > 95 )
		return RANK_D->query_respect(me)+"看起来气血充盈，不知到小店来有何贵干？\n";

	if( ((int)me->query("kee")*100/my_max_qi) > 75 )
		return RANK_D->query_respect(me)+"些许小伤，本店有特制伤药，包你药到病除。\n";

	if( ((int)me->query("kee")*100/my_max_qi) > 55 )
		return RANK_D->query_respect(me)+"伤得可不轻啊，不过本店的特制伤药专治各种刀伤、剑伤，有特效哦。\n";	

	return RANK_D->query_respect(me)+"伤势沉重，若不马上救治，可是有生命危险的！\n";	
}
