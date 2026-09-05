// /d/beijing/npc/dangpuhuoji.c

#include <ansi.h>

inherit NPC;


void create()
{
        set_name("当铺伙计", ({ "huo ji", "huoji" }) );
	set("long", "这是一为当铺的伙计。\n");
        set("gender", "男性");
        set("age", 20);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 23);
        set("con", 19);
        set("dex", 20);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);
        set("combat_exp", 80000);

        set_skill("literate", 100);
        set_skill("dodge", 30);
		set_skill("force", 30);
		set_skill("parry", 30);
		set_skill("unarmed", 30);


        setup();
        carry_object("d/city/obj/cloth")->wear();
}

int init()
{
  object ob;
  ob = this_player();
  ::init();

  if( interactive(ob = this_player()) && !is_fighting() ) {
       remove_call_out("greeting");
       call_out("greeting", 1, ob);
  }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        message_vision(	"$N朝$n微微笑了笑。\n",this_object(),ob );
        switch( random(2) ) {
                case 0:
                        command( "say 这位" + RANK_D->query_respect(ob)
                                + "，想要典当什么贵重物品吗？这可找对人了。\n");
                        break;
                case 1:
                        command( "say 这位" + RANK_D->query_respect(ob)
                                + "，我这有各种价值不菲的物品，看看您想要购买哪一件。\n");
                        break;
        }
}