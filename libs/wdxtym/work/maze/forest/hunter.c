#include <ansi.h>
inherit NPC;

mixed teach_hunting();

void create()
{
        set_name("丛林狩猎者", ({"hunter"}));
        set("long", @LONG
这是一个猎物收购者，给他一定数量的猎物，获取你的奖励！
十张狼皮 五块狼肉
十张熊皮 五块熊肉
十张虎皮 五块虎肉
十张豹皮 五块豹肉
十张蛇皮 五块蛇肉
......
LONG);
        set("gender", "男性" );
        set("class", "swordman");
        set("age", 45);
        set("str", 200);
        set("con", 26);
        set("int", 28);
        set("dex", 200);
        set("combat_exp", 12000000);
        set("attitude", "peaceful");

        set_skill("unarmed", 300);
        set_skill("dodge", 300);

        set("max_qi", 4500);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);

        set("inquiry", ([
                "hunting" : ( :teach_hunting: ),
                "捕猎"    : ( :teach_hunting: ),
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();

 }

int accept_object(object me, object ob)
{
        if( !me || environment(me) != environment() ) return 0;
        if (me->is_fighting()) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
        if (ob->is_character() || ob->is_item_make())
        {
                message_vision(CYN "$N" CYN "瞪着$n" CYN "，使劲的摇着头"
                               "道：我要这干什么？\n" NOR, this_object(), me);
                return 0;
        }
        if ( (string)ob->query("id") == "bushou jia")
        {
                command("nod");
                command("say 这个我正用得着，在下无以为报，如果你愿意，我\n可以"
                        "教你一些捕猎的技巧。");
                me->set_temp("marks/hunter", 1);
                destruct(ob);
                return 1;
        }
        if (strsrch(ob->query("name"), "皮") >= 0 ||
            strsrch(ob->query("name"), "肉") >= 0)
        {
                object reward;
                int amount;

                amount = this_object()->query("hunter_count");
                amount += ob->query_amount();
                this_object()->set("hunter_count", amount);
                message_vision(CYN "$N" CYN "看了看" + ob->name() + CYN "，对$n"
                               CYN "道：还不错，辛苦你了。这点银子你收下吧。\n" NOR,
                               this_object(), me);

                reward = new("/clone/money/silver");
                reward->set_amount(ob->query("base_value") * ob->query_amount() / 100);
                reward->move(me, 1);
                if ((amount % 10) == 0)
                {
                        reward = new("/clone/money/gold");
                        reward->set_amount(1);
                        reward->move(me, 1);
                        message_vision(CYN "$N" CYN "对$n道：辛苦你了。这点金子你收下吧。\n" NOR,
                                       this_object(),  me);
                }
                destruct(ob);
                return 1;
        }

        command("shake");
        command("say 这是什么东西，我不需要！");
        return 0;
}

mixed teach_hunting()
{
        object me = this_player();
        int jing, add;

        jing = me->query("jing");
        add = me->query_int() * 2 + random(me->query_int());

        if (! me->query_temp("marks/hunter"))
                return "你我素无往来，何出此言？\n";

        if (me->is_busy() || me->is_fighting())
        {
                write("你现在正忙着。\n");
                return 1;
        }

        if (jing < 20)
        {
                write("你的精神无法集中。\n");
                return 1;
        }

        if (count_lt(count_sub(me->query("potential"), me->query("learned_points")), 1))
        {
                write("你的潜能不够，无法继续学习。\n");
                return 1;
        }
        write(HIW "猎人给你讲解了有关捕猎的一些技巧。\n" NOR);
        write(HIY "你听了猎人的指导，似乎有所心得。\n" NOR);

        me->add("learned_points", 1);

        me->improve_skill("hunting", add);

        me->add("jing", -(5 + random(6)));

        return 1;

}


