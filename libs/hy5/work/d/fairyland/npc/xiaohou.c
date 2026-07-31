// xiaohou.c
// By jpei

inherit NPC;

void wander_about();

void create()
{
        set_name("小猴", ({ "xiao hou", "xiao", "hou", "monkey" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只长着白毛的小猴。\n");

        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100);
    
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
	if (clonep()) call_out("wander_about", 10);
}

void init()
{
	object ob = this_player();

	if (base_name(environment())[<6..] == "shanbi") {
		if ( random(300)) {
			set("get_wound", 1);
			say("一个小猴忽然从陡峭的山壁上失足掉了下来，后腿被一块石头压住了，动弹不得。\n");
		}
	}
	if (ob->query_temp("help_monkey")  && !query("get_wound") && !random(3)) {
		tell_object(ob, "那只你救过的小猴忽然跑了过来，吱吱喳喳，叫个不停。\n");
		tell_object(ob, "顺着它的手指看去，只见一个白色大猿蹲在那里，神情痛苦。\n");
		new("/d/fairyland/npc/dabaiyuan")->move(environment(ob));
		ob->delete_temp("help_monkey");
	}
	else if (!query("get_wound"))
		::init();;
}

int return_home(object home)
{
	if (query("get_wound")) return 1;
	return ::return_home(home);
}

void wander_about()
{
	if (!is_fighting()) {
		if (!query("get_wound")) {
                call_out("dis", 0);
//                  destruct(this_object());
//			random_move();
		}
		else {
			add("get_wound", 1);
			if (query("get_wound") > 15) {
				say("小猴发出一声凄厉的惨叫，两腿一蹬死了。\n");
				destruct(this_object());
				return;
			}
			say("小猴发出“吱吱”的惨叫声。\n");
		}
	}
	call_out("wander_about", 10);
}

void dis()
{
	destruct(this_object());
}
