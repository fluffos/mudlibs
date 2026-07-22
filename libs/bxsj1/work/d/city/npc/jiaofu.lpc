// jiaofu.c 轿夫
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("轿夫", ({ "jiao fu", "jiaofu", "fu" }));
	set("long", "这是一个身强体壮的轿夫，相貌端正，穿戴整齐。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("str", 50);
	set("int", 10);
	set("max_qi", 600);
	set("combat_exp", 10000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);

	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("cloth"))->wear();
}