// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
// whitexiu.c
inherit NPC;

void create()
{
        set_name("白衣秀士", ({"xiu shi","xiushi","xiu","shi"}));
        set("gender", "男性" );
        set("age", 25);
        set_level(60);
        set("long", "一位风流书生，不过他面色看起来怪怪的。\n");
        set("attitude", "peaceful");
        set_skill("unarmed",600);
        set_skill("dodge",600);
        set_skill("parry",600);
        set_skill("force",600);
        set("force_factor", 20);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

void unconcious()
{
	object me = this_object();
	message_vision("$N转身想跑...晚了，一个趔趄，栽倒在地，现了原形，竟是条白花蛇怪。\n",me);
	message_vision("白花蛇簌簌的游走了。\n",me);
	destruct(me);
}

void die()
{
  unconcious();
}
