// zhong2.c 钟阿四 

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("钟阿四", ({ "zhong asi", "zhong","asi" }));
	set("long",
		"他铁青着脸，一声不吭的站着。\n");
	set("gender", "男性");
	set("age", 38);

	set("str", 23);
        set("int", 15);
        set("con", 20);
        set("dex", 18);

	set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);

        set("jingli",100);
        set("max_jingli",100);
        set("jiali", 1);   
	set("combat_exp", 2000);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}


void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
	
