// by snowcat 10/05/1997
// zhangmen.c 掌门
//modified for shushan

inherit NPC;
inherit F_SAVE;

void create()
{
	set_name("大弟子", ({ "zhang men", "zhangmen" }) );
	set("gender", "男性" );
	set("age", 30);
	set("str", 30);
	set("per", 30);
	set("int", 30);
	set("long", "掌门大弟子。" );
	set("attitude", "heroism");
	set("combat_exp", 100000);
	set("current_player","none of us");

	setup();

        carry_object("/clone/cloth/cloth")->wear();
}