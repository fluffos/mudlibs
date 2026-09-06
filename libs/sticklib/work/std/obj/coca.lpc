#include <stats.h>
#include <conditions.h>
#include <treasure.h>

#define STRENGTH 30

int amount;

void create_treasure()
{
    set_name("leaf from coca-plant");
    set_id( ({ "leaf", "coca", "piece of leaf" }) );
    set_short("a leaf from a coca plant");
    set_long("Chewing on this leaf heals the eaters fatigue, but it might "+
      "have some side-effects.\n");
    set_weight(1);
    set_value(250);
    amount = 5;
}

void init_treasure()
{
    add_action("eat_cmd", "eat");
    add_action("eat_cmd", "chew");
}

int eat_cmd(string str)
{
    if (!id(str))
	return notify_fail("Eat what?\n"), 0;

    write("The leaf has a very powerful taste.\n");
    if (!this_player()->eat_food(STRENGTH)) {
	return 1;
    }

    this_player()->add_fp(
      (int)this_player()->query_stat(ST_CON)+
      (int)this_player()->query_stat(ST_STR)
      + random(25));
    this_player()->add_stat(ST_FP_HEAL_RATE,1,100,0);

    this_player()->add_condition(C_HALLUCINATING,random(40)+1);
    if (--amount) {
	write("You chew a piece of the leaf.\n");
	set_value(amount * 50);
	set_short((amount==1) ? "a small piece of cocaleaf" :
	  "a piece of cocaleaf");
    } else {
	write("You chew the last piece of the leaf.\n");
	destruct(this_object());
    }

    return 1;
}
