// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/xiaoer.c

inherit F_VENDOR_SALE;

void create()
{
       set_name("王小二", ({"wang xiaoer", "wang","xiaoer","er","waiter" }));
       set("long", "小酒店的伙计，一副精明干练的模样．\n");
       set("gender", "男性");
	set("title", "伙计");
	set("combat_exp", 3000);
       set("age", 46);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ([
                "jiudai": "/d/ourhome/obj/hdjiudai",
                "gourou": "/d/ourhome/obj/gourou",
                "yumi": "/d/qujing/huangfeng/obj/yumi",
		    "mifan": "/d/qujing/huangfeng/obj/mifan",
        ]) );

	setup();
       add_money("silver", 2);
	add_money("coin", random(80));
        carry_object("/obj/cloth")->wear();

}