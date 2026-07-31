
#include <ansi.h>

inherit NPC;
inherit F_DEALER;

int redeem(string arg);

void create()
{
        set_name("化骨龙", ({ "huagu long", "long" }));
        set("title", "龙升典当行老板");
        set("shen_type", 0);

        set("gender", "男性");
        set_max_encumbrance(100000000);
        set("age", 35);
        set("str", 100);
        set("long",
                "他是宗主的第十三个儿子，他性格豪放不羁，与宗主府的人格格不入。\n");
        set("no_get_from", 1);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/attack", 60);
        set_temp("apply/attack", 60);
        set_temp("apply/damage", 65);

        set("combat_exp", 200000);
        set("attitude", "friendly");
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_sell", "sell");
        add_action("do_value", "value");
        add_action("do_redeem", "redeem");
}

void die()
{
        message_vision("\n$N死了。\n", this_object());
        destruct(this_object());
}
int do_redeem(string target)
{
        object dest, *all;
        int i, value;

        all = users();

        if (!target)
                return notify_fail("你想赎谁？ 1\n");

        for(i=0; i<sizeof(all); i++) 
        {
//              if( target == (string)all[i]->id() || target == all[i]->name() )
                if( target == (string)all[i]->query("id") || target == all[i]->query("name") )
                        dest = all[i];
        }
        if( !dest )
                return notify_fail("化骨龙说到：他现在不在游戏中，过会再来吧。\n");
        else if( !dest->query_temp("selled"))
                return notify_fail("化骨龙急道：你可别诬陷好人，我怎么会非法扣押玩家呢！\n");

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

        switch (MONEY_D->player_pay(this_player(), dest->query("per") * 700))
        {
        case 0:
                return notify_fail("穷光蛋，一边呆着去！\n");
        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        default:
                set_temp("busy", 1);
                message_vision("$N从$n那里赎回了一" + dest->query("unit") + 
                        dest->query("name") + "。\n", this_player(), this_object());
                dest->move("/d/city/kedian");
                dest->set("startroom","/d/city/kedian");
                dest->delete_temp("selled");
                message("vision",
                        HIY "只听见嗖的一声，一个遍体鳞伤的家伙从天花板上掉了下来！\n" NOR,
                        environment(dest), dest);
                tell_object(dest, "你被" + this_player()->query("name") + "赎了出来。\n");
        }
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

        return 1;
}       


