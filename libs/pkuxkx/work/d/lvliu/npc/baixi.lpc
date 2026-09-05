inherit NPC;
#include <ansi.h>
int random_move();

void create()
{
	set_name(HIW"披毛白犀"NOR,({"bai xi", "xi"}));
    set("race", "野兽");
	set("long","一只体型巨大的白色犀牛。体躯浑圆粗壮，身披厚甲，巨大的身体犹如一堵高墙。\n"
	+"，在额部一前一后长着两只巨大的犀角，高高耸立，坚硬似铁、锋利如枪。\n");
    set("verbs", ({ "bite", "hoof" }));
	set("limbs",({"头","身","腿","尾"}));
	set("attitude","hateful");
    set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :),
	}) );
	set("shen_type",0);
	set("combat_exp", 1000000000);
	set("max_qi", 10000000);
	set("max_jing", 10000000);
    set("lvliu_npc", 1);
	set("lvliu_animal", 1);
	set_temp("apply/attack", 10000);
	set_temp("apply/defense", 5000);
	set_temp("apply/armor", 5000);
	set_temp("apply/damage", 5000);
	setup();
	set_weight(10000000);
}

void init()
{
	object ob;
	::init();
	ob = this_player();
	if (userp(ob) && random(2))
	{
		remove_call_out("do_killing");
		call_out("do_killing", 1, ob);
	}
}

void do_killing(object ob)
{
	if(!ob||environment(ob)!=environment()||environment(ob)->query("no_fight"))
		return;
	message_vision("$N" HIM "烦躁地低吼了一声，向着$n发起了进攻！\n"NOR, this_object(), ob);
	this_object()->kill_ob(ob);
}

int random_move()
{
    mapping exits;
    string *dirs, pos;
	object room;
    int i;
    if(!environment() || this_object()->is_fighting() || this_object()->is_busy()) return 0;
    if(sizeof(environment()->query("exits")) == 0) return 0;
    if( !mapp(exits = environment()->query("exits")) ) return 0;
    dirs = keys(exits);
    i = random(sizeof(dirs));
	room = load_object(environment()->query("exits/"+dirs[i]));
    if (!objectp(room)) return 0;
	pos = base_name(room);
	if (strsrch(pos, "/d/lvliu/pingyuan")<0) return 1;
    command("go " + dirs[i]);
	return 1;
}

void start_busy(mixed new_busy, mixed new_interrupt)
{
	::start_busy(1);
}