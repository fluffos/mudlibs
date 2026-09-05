// Room: /d/beijing/shiwei_shitang.c
#include <ansi.h>
inherit ROOM;
#include "beijing_defs.h"

int do_eat(string);
int do_drink(string);
int vomit(object);

void create()
{
        set("short", HIY"食堂"NOR);
        set("long",
HIC"这里是侍卫们吃饭的地方。低等侍卫们来来往往，边吃
边聊天。偶尔也能看到一些侍卫营的大官。餐桌（table）上放
了好些吃的喝的，你就随便用吧。\n"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
        "west"  : __DIR__"jiaochang",
        ]));
        set("objects", ([ /* sizeof() == 4 */
        __DIR__"npc/shiwei"  : 2,
        ]));

	set("item_desc", ([
	"table" : "桌上放了许多馒头可吃 (eat)，也有清水可喝 (drink)\n",
	"桌子" : "桌上放了许多馒头可吃 (eat)，也有清水可喝 (drink)\n",
	"餐桌" : "桌上放了许多馒头可吃 (eat)，也有清水可喝 (drink)\n",
        ]));

        setup();
}

void init()
{
    add_action("do_eat", "eat");
    add_action("do_drink", "drink");
}

int do_eat(string arg)
{
    object player=this_player();
    int    food, max_food;

    if (arg)
	return command("eat "+arg);

    if (player->is_busy())
	return notify_fail("你正忙着呢。\n");
    food = player->query("food");
    max_food = player->max_food_capacity();

    if (food >= max_food)
	return notify_fail("你已经吃撑了，还要吃？\n");

    food += max_food/10;
    if (food > max_food) food = max_food;
    message_vision("$N拿起桌上的馒头吃了两口。\n", player);
    player->start_busy(2);
    player->set("food", food);

    if (!IS_SHIWEI(player) && player->query("class") !=  "officer" &&
	!wizardp(player)){
	message_vision("$N发现旁边有人偷偷的笑了一声。\n", player);
	call_out("vomit", 5, player);
    }
    return 1;
}

int vomit(object player)
{
    message_vision("$N突然呕吐起来。吐出来的馒头里面好象还有什么东西在蠕动。\n",
		player);
//    player->set("food",0);
    player->start_busy(5);
    return 1;
}

int do_drink(string arg)
{
    object player=this_player();
    int    water, max_water;

    if (arg)
	return command("eat "+arg);

    if (player->is_busy())
	return notify_fail("你正忙着呢。\n");
    water = player->query("water");
    max_water = player->max_water_capacity();

    if (water >= max_water)
        return notify_fail("你已经喝饱了，还要喝？\n");

    water += max_water/10;
    if (water > max_water) water = max_water;
    message_vision("$N端起桌上的水盆喝了两口。\n", player);
    player->start_busy(1);
    player->set("water", water);

    if (!IS_SHIWEI(player) && player->query("class") !=  "officer" &&
	!wizardp(player)){
	message_vision("$N发现旁边有人偷偷的笑了一声。\n", player);
	F_POISON->poison_attack(this_object(),player,"slumber_drug",
	    player->query_condition("slumber_drug")+100);
    }
    return 1;
}
