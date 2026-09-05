

inherit NPC;

void create()
{
	set_name("庙祝", ({ "miao zhu", "miaozhu" }));
	set("gender", "男性");
	set("age", random(50)+20);
	set("long", "他是一个庙里的庙祝，整体乐呵呵的，油水一定很肥。\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

        set("inquiry", ([  
                "name" : "我就是大名鼎鼎的庙祝啊！",
                "rumors" : "这里是古城晋阳，你想知道什么呢？",
        ]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

