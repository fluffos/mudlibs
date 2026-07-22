// laoyu.c

inherit NPC;
inherit F_VENDOR;
void create()
{
       set_name("胖嫂", ({"pang sao", "pang", "sao"}));
       set("long",
"胖嫂原是裁缝，后在长安的儿子发了财，便自家开了布店．\n");
       set("gender", "女性");
	set("title", "老板娘");
	set("combat_exp", 1100);
       set("age", 46);
	set("per", 12);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 15);
       set("vendor_goods", ([
                "hat": "/d/gao/obj/hat",
                "shoes": "/d/gao/obj/shoes",
		"magua": "/d/gao/obj/magua",
                "pipao": "/d/gao/obj/piyi",
       ]) );
	setup();
       add_money("silver", 1+random(3));
        carry_object("/d/gao/obj/ao")->wear();

}
void init()
{
         add_action("do_vendor_list", "list");
}
