//   zhanglang.c
//  by victori
inherit NPC;
void create()
{
        set_name("蟑螂", ({ "zhang lang","lang" }) );
	 set("race", "野兽");
        set("age", 4);
	 set("per", 30);
        set("long", "一只令人恶心的小虫子，正好奇的看着你。\n");
        set("combat_exp", 60);
        set("attitude", "friendly");
//      set("env/wimpy", 60);
	set_skill("dodge", 5);
	set_skill("unarmed", 5);
	set_skill("parry", 5);
	set("max_qi", 100);

  	set("chat_chance",10);
  	set("chat_msg",({
        "叽叽...叽叽叽叽，....叽叽叽..~~~~。\n",
 //       (:random_move:)
    	}));
        setup();
//        add_money("coin", 50);
set("inquiry", ([
//        "name": "大家都叫我阿牛．平常上山打柴，有时也采些药材．\n",
//        "here": "此乃卧龙岗．听说山上有位卧龙先生．\n",
]) );
//       carry_object("/d/city/obj/cloth")->wear();
}
