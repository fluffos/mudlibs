// xiong.c

#include <ansi.h>
inherit NPC;

void check_fight(object, object);
int random_walk();

string *walkrooms = ({
        "/d/changbai/jiaxz",
        "/d/changbai/erld",
        "/d/changbai/banlp",
        "/d/changbai/pubu",
        "/d/changbai/tieby",
        "/d/changbai/jiglz",
});

void create()
{
        set_name("黑熊", ({ "hei xiong", "xiong", "bear" }) );
        set("race", "野兽");
        set("age", 25);
        set("long", "一只身体硕大的狗熊，它正瞪着眼睛看着你。\n");
        set("attitude", "aggressive");
        set_weight(200000);

        set("max_jing", 500);
        set("max_jingli", 500);

        set("str", 90);
        set("con", 80);
        set("dex", 30);
        set("int", 10);

        set("combat_exp", 800000);

	set("max_qi", 3000 + random(2000));

	set("limbs",({"头部", "身体", "爪子", "尾巴"}));
	set("verbs",({"claw", "bite"}));

        set("gem_level", ({0, 1}));
        set("item_drop_odds", ({984, 5, 5, 0, 5, 1, 0 }));
        set("luding_monster", 1);

        set_temp("apply/attack", 50);
        set_temp("apply/damage", 60);
        set_temp("apply/armor", 80);

        set("chat_chance", 5);
        set("chat_msg", ({
//              (: random_walk :),
        }) );

        setup();
}

void die()
{
	int i;
	object ob, corpse;
	message_vision("$N惨嚎了一声，趴在地上不动了。\n", this_object());
    	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	corpse->move(environment(this_object()));

        if (random(4)<1) 
        {
       if (random(2)) GEM_D->drop(this_object(),this_player());
        }

	corpse->set("no_get_from", 1);
	destruct(this_object());
}

void init()
{
        object me;

        ::init();

        if( interactive(me = this_player()) )
		set_leader(me);
}
/*
void do_killing(object me)
{
        if( !me || environment(me) != environment() )
                return;

        kill_ob(me);
}

int random_walk()
{
        mapping exits;
        string *dirs, dir;

        if( member_array(base_name(environment()), walkrooms) == -1 ) {
                message_vision("$N一溜烟跑掉了。\n", this_object());
                destruct(this_object());
        }

        if( !objectp(environment())
        || !mapp(exits = environment()->query("exits"))
        || query("jingli") < query("max_jingli") / 2 )
                return 0;

        dirs = keys(exits);
        dir = dirs[random(sizeof(dirs))];
        if( member_array(exits[dir], walkrooms) == -1 ) return 0;

        command("go " + dir);
        return 1;
}
*/
