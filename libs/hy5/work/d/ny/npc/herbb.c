
// herbalist.c
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;


void create()
{
    set_name("林掌柜", ({ "herbalist" }) );
    set("title", "林家铺子");
        set("gender", "男性" );
        set("age", 54);
        set("long",
        "林掌柜是这附近相当有名的大善人，常常施舍草药给付不起药钱的穷人\n"
                "。此外他的医术也不错，年轻时曾经跟著山烟寺的玄智和尚学医，一般\n"
                "的伤寒小病直接问他开药吃比医生还灵。\n" );
        set("combat_exp", 130000);
        set("attitude", "friendly");
        set("inquiry", ([

                "解毒": 
"哎哟，你不说我倒忘了，过两天我一定去向玄智大师请教......\n",
        ]) );

        set_skill("literate", 70);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/clone/misc/yaodan",
                "/clone/misc/neilidan",
		"/d/shenlong/obj/xionghuang",
	}));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
void init()
{
        object ob;

        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");


}