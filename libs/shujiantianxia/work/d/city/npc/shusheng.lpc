//  shusheng.c

inherit NPC;

void create()
{
	set_name("书生", ({ "shu sheng", "student", "sheng", "shu" }));
	set("gender", "男性");
	set("age",22);
	set("per", 26);
	set("long","这是一名扬州府的秀才，年级轻轻。他除了四书五经外，也最爱打听些江湖传闻。\n");

        set("chat_chance", 3);
       	set("chat_msg", ({
 		"书生说道：“传说古往今来，武学到达最高境界便是无形胜有形了。”\n",
 		"书生说道：“武当山的张三丰真人是当今世上唯一的武学大宗师。”\n",
       	}) );
	set("combat_exp", 21000);
	set("shen", 20);
	set("attitude", "friendly");
	setup();
	carry_object(ARMOR_D("jinduan"))->wear();
}

