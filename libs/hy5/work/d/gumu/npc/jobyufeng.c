// yufeng.c //玉蜂
// By Lgg,1998.9

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW "采蜜玉蜂" NOR, ({"yufeng","feng","bee"}) );
        set("race", "野兽");
        set("age", 8);
        set("long", "这是一只玉色的蜜蜂，个头比普通蜜蜂大得多，\n"
                    "翅膀上被人用尖针刺有字。\n");

        set("str", 40);
        set("dex", 50);

        set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
        set("verbs", ({ "bite", "poke" }) );

        set_temp("apply/attack", 100);
        set_temp("apply/armor", 100);
        set("jobfeng",1);
        set("chat_chance", 2);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
        "玉蜂在你头顶转了一圈，似乎发现这不是可采蜜的地方，就嗡嗡嗡地飞走了。\n",
        "玉蜂围绕着鲜花飞飞停停，似乎也不着重在采蜜上。\n",
         }) );

        setup();
}
void init( )
{
        call_out("hunting",180);
}

void hunting()
{
object ob=this_object();
command("emote 玉蜂在你头顶转了一圈，似乎发现这不是可采蜜的地方，就嗡嗡嗡地飞走了。");
destruct(ob);
}
void die()
{
	unconcious();
}
