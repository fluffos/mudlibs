// x_lama.c 小喇嘛

inherit NPC;

void create()
{
        set_name("小喇嘛",({
		"xiao lama",
		"xiao",
		"lama",
	}));
	set("long",
                "这是雪山寺的小喇嘛，一脸的稚气，看来刚入门不久。\n"
	);


	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

        set("age", 13);
        set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("combat_exp", 500);
create_family("雪山寺", 4, "弟子");

	setup();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
}
