inherit NPC;
inherit F_DEALER;
#include <ansi.h>
void create()
{
    set_name("蓝阳光", ({ "sunshine" }) );
    set("gender", "女性" );
    set("age", 17);
    set("title", HIY "金色的"NOR);
        set("long",
        "一个年轻的女孩子，身上穿的衣服，比蓝天更蓝，比海水更蓝。\n你也从未见过如此明朗，如此令人愉快的女孩子。\n");
        set("attitude", "friendly");
        set("class","legend");
        set("chat_chance", 1);
        set("chat_msg", ({
"蓝阳光突然收敛了笑容，肃然道：圣母恰母尊的子孙们只流血，不流泪，\n男人去前方流血，就由我们女人来打造兵器。\n",
"蓝阳光噗哧一笑道：那个小方看上去凶巴巴的，心比我们女人还要软。。\n",
                }) );
        set("per",30);
        set("combat_exp",3000000);

	set("vendor_goods", ({
               __DIR__"obj/gw_sword",
               __DIR__"obj/gw_spear",
               __DIR__"obj/gw_hammer",
               __DIR__"obj/gw_whip",
               __DIR__"obj/gw_axe",
               __DIR__"obj/gw_blade",
               __DIR__"obj/gw_staff",
               __DIR__"obj/gw_dagger",
               __DIR__"obj/gw_stone",
               __DIR__"obj/gw_iron",
	}));
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("unarmed",100);

        setup();
    carry_object(__DIR__"obj/heipifeng")->wear();
}
void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
        ::init();
}  
