#include <ansi.h>
inherit NPC;

void create()
{
	set_name("饭岛爱", ({ "girl" }) );
	set("title", HIM "压寨夫人" NOR);
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
饭岛爱是这里的压寨夫人，如果你感兴趣的话，请（ｅｎｊｏｙ）．
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

	setup();
	carry_object("/d/qianjin/npc/obj/pink_cloth")->wear();
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会在这儿玩的开心的！");
        return 1;
}

void init()
{
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
object me;
object wo;
object *inv;
//int maxgin,maxkee, maxsen;
int i;
	me = this_player();
message_vision("$N轻飘飘地向$n走过来，温柔的抚弄$n的黑发．．．\n",this_object(),me);
	me->unconcious();
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			destruct(inv[i]);
		}
	         me->add("eff_jing",-5);
         me->add("jing",-20);
         me->set("qi",me->query("eff_qi"));

	return 1;
}
