// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit CLASS_D("generate") + "/chinese"; 

int  is_stay_in_room()  { return 1; }
void random_move();

void create()
{
        mapping my;
        int lvl;

        ::create();
        set("gender", "男性");
        set("age", 30 + random(30));
        set("long", "");
        set("attitude", "friendly");
        set("chat_chance", 30);
        set("chat_msg", ({ (: random_move :) }));
        set("chat_chance_combat", 120);
        set("scale", 150);
        set("no_get", 1);

        set_temp("apply/armor", 100);
        set_temp("apply/damage", 15);
        set_temp("born_time", time());
        set_temp("dest_time", 600 + time());

        add_money("silver", 10 + random(20));

        if (clonep()) keep_heart_beat();
}

/*
void init()
{
        object ob;
        
        ob = this_player();
        
        if (! ob->query("bunch/bunch_name") ||
            ob->query("bunch/bunch_name") != query("is_attacking"))
                return;
        
        this_object()->kill_ob(ob);
        ob->kill_ob(this_object());
}
*/

void kill_ob(object ob)
{
        int lvl;

        if (! is_busy())
                exert_function("powerup");

        if (ob->query("bunch/bunch_name") != query("is_attacking"))
        {
                ::kill_ob(ob);
                return;
        }

        ::kill_ob(ob);
}

int accept_fight(object ob)
{
        command("say 好！咱们就比划比划！");
        kill_ob(ob);
        return 1;
}

int accept_hit(object ob)
{
        command("say 你死去吧！");
        kill_ob(ob);
        return 1;
}

int accept_kill(object ob)
{
        command("say 哼！找死！");
        return 1;
}

void random_move()
{
        if (time() > query_temp("dest_time"))
        {
                message_vision("$N急急忙忙的走了。\n", this_object());
                destruct(this_object());
                return;
        }
        GROUP_D->random_move(this_object());
}

void die(object killer)
{
        object ob;
        string msg;

        if ((objectp(ob = killer)
           || objectp(ob = query_last_damage_from()))
           && ob->query("bunch/bunch_name") == query("is_attacking"))
        {
                GIFT_D->delay_bonus(ob, ([ "prompt"  : "击毙" + query("name") + "之后",
                                           "exp"    : 400 + random(400) + query("bonus"),
                                           "pot"    : 100 + random(200) + query("bonus") / 3,
                                           "score"  : random(40) + 50,
                                           "weiwang": random(30) + 20, ]));

                BUNCH_D->add_bunch_fame(ob->query("bunch/bunch_name"), query("bonus"));  
        }
        set_temp("die", 1);
        ::die(killer);
}

