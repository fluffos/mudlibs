// nanhai.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW "白虎" NOR, ({ "white tiger", "white", "tiger" }) );
	set("title", HIC "神兽" NOR);
	set("gender", "男性");
	set("age", 5);
	set("long", @LONG
这是一只巨大的白虎，雄壮无比。乃为太白金星的坐骑。
LONG );
	set("combat_exp", 10000000);
        set("shen_type", 0);
	set("attitude", "heroism");
        set("max_neili", 220000);
        set("neili", 220000);
        set("max_jing", 180000);
        set("jing", 180000);
        set("max_qi", 340000);
        set("qi", 340000);
        set("jingli", 120000);
        set("max_jingli", 120000);
        set("zjb_dj/dj", 10);

        set("str", 160);
        set("int", 30);
        set("con", 80);
        set("dex", 80);

	set_skill("unarmed", 1800);
	set_skill("sword", 1800);
	set_skill("parry", 1800);
	set_skill("dodge", 1800);
	set_skill("force", 1800);

        set("jiali", 300);

        set_temp("apply/attack", 400);
        set_temp("apply/unarmed_damage", 600);
        set_temp("apply/armor", 1000);

        if (clonep(this_object()))
        {
                set("chat_chance", 30);
                set("chat_msg", ({ (: random_move :) }));
                set("born_time", time());
                keep_heart_beat();
        }

	setup();
}

void fight_ob(object ob)
{
	if (is_fighting(ob))
		return;

        message_vision(HIW "$N一声长啸，张牙舞爪，面目狰狞。\n" NOR, this_object(), ob);

        ::fight_ob(ob);
	if (! is_killing(ob->query("id")))
        	kill_ob(ob);
}



int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        ob->receive_wound("qi", 200 + random(200), me);
        me->set("neili", me->query("max_neili"));
        return HIW "$N" HIW "周围云雾缭绕，面目狰狞，登时令$n"
               HIW "迷惑不已，难以自拔。\n" NOR;
}

void unconcious()
{
        die();
}

void die()
{
        object ob;
        string str;
        string* prize = ({
             "/clone/fam/etc/hugu",
             "/clone/fam/etc/hujin",
             "/clone/fam/etc/hupi",
        });

        str = prize[random(sizeof(prize))];
        ob = new(str);
        command("chat 盎~！盎~~！！");
        CHANNEL_D->do_channel(this_object(), "rumor", HIW "畜生，快快跟我回去吧！" NOR);
        command("chat 盎~！盎~~！！");
        CHANNEL_D->do_channel(this_object(), "rumor", HIM "听说白虎被太白金星抓回天庭！\n" NOR);        
        message_sort(HIR "$N" HIR "身子一扭，消失在云气中，"
                     "只听叮玲玲的一声，从$N" HIR "身上掉下了一" +
                     ob->query("unit") + ob->name() +
                     HIR "。\n" NOR, this_object());
        ob->move(environment());
        destruct(this_object());
}

void random_move()
{
	if (time() - query("born_time") > 1800)
	{
		message_vision("$N急急忙忙的走了。\n", this_object());
                CHANNEL_D->do_channel(this_object(), "rumor",
                        "听说" + name() + HIM "逍遥世间，后来终于被太白金星抓回天庭。" NOR);
		destruct(this_object());
		return;
	}
}
