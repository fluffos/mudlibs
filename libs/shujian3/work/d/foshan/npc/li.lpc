//li.c 李老板 

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("李老板", ({ "li", "laoban" }));
	set("long",
		"李老板正殷勤的招揽着来来往往的行人。\n");
	set("title", "杂货铺老板");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen", 2000);

	set("str", 18);
        set("int", 25);
        set("con", 18);
        set("dex", 21);

	set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);

        set("jingli",400);
        set("eff_jingli",400);
        set("jiali", 1);   
	set("combat_exp", 2000);

        set("vendor_goods", ({
            (["name": "/d/foshan/obj/xiwan","number" : 10]),
            (["name": "/d/foshan/obj/xihu","number" : 10]),
            (["name": "/d/foshan/obj/xipen","number" : 10]),
            (["name": "/d/foshan/obj/tidao","number" : 10]),
            (["name": MISC_D("fire"),"number" : 10]),
        }));
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
