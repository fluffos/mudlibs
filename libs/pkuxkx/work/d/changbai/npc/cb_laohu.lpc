// laohu.c

#include <ansi.h>
#include <combat.h>
#include <login.h>

inherit NPC;

void check_fight(object, object);
int random_walk();
int tigercatch(int ap, int dp);

string *walkrooms = ({
        "/d/changbai/milin1",
        "/d/changbai/milin2",
        "/d/changbai/milin3",
        "/d/changbai/milin4",
});

void create()
{
        set_name("东北虎", ({ "dongbei hu", "hu", "tiger" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", @LONG
一只矫捷的斑斓猛虎，形体巨大，状极威猛，雄伟极了。


    ("`-''-/").___..--''"`-.
     `@_ @ )   `-.  (  *  ).`-.__.`)
     (_Y_.)'  ._   )  `._ `. ``-..-'
      _..`--'_..-_/  /--'_.' ,'
    (il),-''  (li),'  ((!.-'


LONG);
        set("attitude", "aggressive");
        set("max_qi", 1500);
        set("max_jing", 600);
        set("max_jingli", 500);

        set("str", 60);
        set("con", 50);
        set("dex", 40);
        set("int", 10);

	set("max_qi", 2000 + random(2000));

        set("gem_level", ({0, 1}));
        set("item_drop_odds", ({984, 5, 5, 0, 5, 1, 0 }));
        set("luding_monster", 1);

        set_temp("apply/attack", 60);
        set_temp("apply/damage", 40);
        set_temp("apply/armor",  80);

	set("limbs",({"头部", "身体", "爪子", "尾巴"}));
	set("verbs",({"claw", "bite"}));

        set("combat_exp", 500000);

        set_weight(150000);

        set("chat_chance", 5);
      	set("chat_msg", ({
                "老虎在浚巡，吓得你大气都不敢出。\n",
                "老虎仰天长啸，声震山谷，黄叶纷坠。\n",
      	}) );

        setup();
}

void die()
{
	int i;
	object ob, corpse;
	message_vision("$N仰天惨嚎了一声，趴在地上不动了。\n", this_object());
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
void do_attacking(object me)
{
        object ob = this_object();
        string dodge_skill, limb, *limbs, result;
        int ap, dp;

        if( !me || environment(me) != environment()  || !living(me) )
                return;

        say(HIR "\n只见发起一阵狂风。\n" NOR);
        say(HIR "只听得乱树背後扑地一声响，跳出一只吊睛白额大虫来。\n" NOR);
        message_vision(HIR "那大虫又饿，又渴，把两只爪在地上略按一按，和身望$N一扑，从半空里撺将下来。\n" NOR, me);

        ap = COMBAT_D->skill_power(ob, "strike", SKILL_USAGE_ATTACK);
        dp = COMBAT_D->skill_power(me, "dodge", SKILL_USAGE_DEFENSE);

        if( wizardp(me) )
                write("ap = " + ap + "; dp = " + dp + "。\n");

        if( is_busy() ) dp /=3;
        if( dp < 1 ) dp = 1;

        if( !tigercatch(ap, dp) ) {
                dodge_skill = me->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";

                limbs = me->query("limbs");
                limb = limbs[random(sizeof(limbs))];
                result = SKILL_D(dodge_skill)->query_dodge_msg(limb);
                message_vision(result, ob, me);

                message_vision(HIR "那大虫背後看人最难，便把前爪搭在地下，把腰胯向$N一掀，掀将起来。\n" NOR, me);

                if( !tigercatch(ap, dp) ) {
                        limb = limbs[random(sizeof(limbs))];
                        result = SKILL_D(dodge_skill)->query_dodge_msg(limb);
                        message_vision(result, ob, me);

                        message_vision(HIR "大虫见掀$N他不着，吼一声，却似半天里起个霹雳，把这铁棒也似虎尾倒竖起来只一剪。\n" NOR, ob);

                        if( !tigercatch(ap, dp) ) {
                                limb = limbs[random(sizeof(limbs))];
                                result = SKILL_D(dodge_skill)->query_dodge_msg(limb);
                                message_vision(result, ob, me);

                                say(HIR "原来那大虫拿人只是一扑，一掀，一剪；三般捉不着时，气性先自没了一半。\n\n" NOR);
                                kill_ob(me);
                                me->fight(ob);
                                if( (int)me->query("combat_exp") < 100000 )
                                        me->add("combat_exp", 10 + random(10));
                                call_out("check_fight", 1, ob, me);
                                return;
                       }
                }
        }

        message_vision(HIR "$N这一下没有躲开，为虎所伤晕了过去。\n\n" NOR, me);

        me->receive_wound("qi", (int)me->query("max_qi") + 100, this_object());
}

int tigercatch(int ap, int dp)
{
        if( dp < ap / 5 ) return 1;
        if( dp > ap ) return 0;
        if( random(dp - ap / 5) < ap / 20 ) return 1;
        else return 0;
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
