//Cracked by Kafei
// Modified by Apache for Group BWDH
// sdong, 8/8/1999
#define BOARD "/clone/board/bwboard"
int do_attack(string arg);
int do_stop(string arg);
int do_bwscore(string arg);
void nude(object obj);

void create_room() {
	 set("no_death", 1);
	 set("invalid_startroom", 1);
	 set("outdoors", "sjsz");
}

void init_room() {
	 add_action("do_disable", "quit");
	 add_action("do_disable", "lian");
	 add_action("do_disable", "practice");
	 add_action("do_disable", "xue");
	 add_action("do_disable", "learn");
}

int do_disable() {
	 tell_object(this_player(), "你不能在这里干这个。\n");
	 return 1;
}

void move_me(object me, string place)
{
}
void full_all(object me) {
	 me->set("eff_jing", (int)me->query("max_jing"));
	 me->set("jing", (int)me->query("max_jing"));
	 me->set("eff_qi", (int)me->query("max_qi"));
	 me->set("qi", (int)me->query("max_qi"));
	 me->set("jingli", (int)me->query("max_jingli"));
	 me->set("neili", (int)me->query("max_neili"));
	 me->set("food", (int)me->max_food_capacity());
	 me->set("water", (int)me->max_water_capacity());
	 me->remove_all_killer();
	 me->clear_condition();
}



void my_destruct(object obj)
{
}

void nude(object obj)
{
}

// clean up all the flags on a player, set back conditions etc.
void finish(object target) {
}

int do_kickout(string arg) {
}


int do_finish(string arg) {
}

int do_attack(string arg)
{
}

int do_stop(string arg)
{
}


