//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
   set_name("妇人", ({ "woman", "fu ren"}));
   set("gender", "女性" );
   set("age", 45);
   set("per",40);
   set_level(1);
   set("long","一位不施脂粉犹美，风流还似少年才的美妇。\n");
   set("combat_exp", 600+random(400));
   set("daoxing", 600+random(400));
   set("attitude", "friendly");
   set_skill("dodge", 10);
   set_skill("unarmed", 10);
   setup();
   carry_object("/d/qujing/dudi/obj/cloth")->wear();
   add_money("silver", 3+random(20));
}

void init()
{
        object ob = this_player();
        add_action("do_yes","yes");
	remove_call_out("checking");
        call_out("checking",1,ob);
}