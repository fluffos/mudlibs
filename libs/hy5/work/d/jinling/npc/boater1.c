// boater1.c

inherit NPC;

void do_hua();

void create()
{
	set_name("ÉÒ¹«", ({ "boater" }) );
	set("gender", "ÄÐÐÔ");
	set("age", 41);
	set("chat_chance",15);
        set("chat_msg", ({
        (: do_hua :) }), );
	setup();
//	carry_object(__DIR__"obj/sticket");
}

