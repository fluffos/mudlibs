// Room: /d/tianshan/xcmen.c
// By Linux

inherit ROOM;
int do_drop(object me, object obj);

void create()
{
	set("short", "仙愁门");
	set("long", @LONG
这里是仙愁门，仙愁门三面环海，云天无际，凛冽北风掠过身边，吹
得人如腾云驾雾，彷佛这里真的是与天接壤之处。
LONG);
	 set("exits", ([
                "northup" : __DIR__"shanjin1",
        ]));         
	set("outdoors", "天山");
	setup();
}

void init()
{
        add_action("do_jump", ({"jump", "tiao", "yue"}));
}

int do_jump(string arg)
{
        object me=this_player();
        object *inv;
        int i;

        if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢！\n");
        if (arg == "down") { 
                message_vision( "$N一个纵身，跳下了悬崖。\n",me);
                me->move(__DIR__"yadi");
                me->set_temp("last_damage_from", "跳下悬崖摔");
                me->unconcious();
                me->die();
                return 1;
        }
        if( (!arg) || !((arg == "duimian") || (arg == "对面")))
                return notify_fail("你要跳到哪里去，山下吗？\n");

        inv = filter_array(deep_inventory(me), (: userp :));
        if (sizeof(inv)) {
                message_vision("$N一纵身想跳到对面百丈涧上，不料一个失足......\n", me);
                me->unconcious();
                return 1;
        }

        if( (int)me->query_skill("dodge", 1) < 100 )
                return notify_fail("你觉得自己的轻功太差，跳过去岂不是送死！\n");
        
        message_vision("\n$N向后退了几步，往前急速越了几步，借着上下坡的重心下移，人在半空，真\n"
			"气一浊，身形急速下坠,又在空中轻巧的一个盘旋，已经落在对面的百丈涧上。\n\n",me);
        inv = deep_inventory(me);
        i= random(sizeof(inv));
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 80) {
                do_drop(me, inv[i]);
        }
	me->add_busy(2);
        me->move(__DIR__"bzhanjian");
        tell_room(environment(me), me->name() + "从对面的百丈涧荡了过来。\n",me);
        return 1;
}

int do_drop(object me, object obj)
{
        mixed no_drop;
        if( no_drop = obj->query("no_drop")) return 1;
        if( obj->is_character())
                return 1;
        else {
                message_vision( sprintf("但是$N由于用力过度，身上的一%s$n丢下了山涧，再也找不回来了。\n", obj->query("unit")),me, obj );
                destruct(obj);
        }
        return 1;
}
