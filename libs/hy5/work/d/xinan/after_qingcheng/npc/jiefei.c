// jiefei.c
#include <ansi.h>

inherit NPC;

void create()
{
    set_name("劫匪", ({ "jie fei","fei" }) );
    set("gender", "男性" );
	set("title","青城山");
    set("str",25);
    set("age", random(10)+25);
    set("max_force",800);
    set("force",800);
    set("force_factor",20);
    set("max_kee",380+random(100));
    set("max_sen",580+random(100));

    set("attitude","aggressive");
    set("combat_exp", 50000);

    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/gangdao")->wield();
}
