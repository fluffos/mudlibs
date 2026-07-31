// Obj: /u/poq/sdxl/obj/fire.c 火折
// bye poq@jyqx 97/7

inherit ITEM;

int decayed;

void init();

void create()
{
    set_name("火折",({"fire", "huozhe"}));
    set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("long", "火折，可以用来照明和点火。\n");
        set("unit", "个");
        set("value", 50);
	 }
    setup();
}

void init()
{
    add_action("do_use", "use");
    add_action("do_use", "yong");
}

int do_use(string arg)
{
    object me = this_player();
    object ob = this_object();
    object where = environment(me);

    if (arg != "fire" && arg!="huozhe")
        return notify_fail("你要使用什么？\n");

    if(ob->query_temp("temp/used")==1)
        return notify_fail("火折已经被点燃了！\n");

    message_vision("$N点燃了火折，周围马上亮了起来！\n", me);

    decayed = 0;

    set_name("点燃的火折", ({ "fire", "huozhe" }) );
    set("long", "火折正燃着。\n");
    where->add_temp("temp/light", 100);
    ob->set_temp("temp/used", 1);
//    if( clonep(this_object()) )
    call_out("decay", 120, 2);

    return 1;
}

void decay(int phase)
{
    object me = this_player();
// object ob = this_object();
    object where = environment(me);
	decayed = phase;
	switch(phase) {
		case 1:
            say( "火折燃得正旺。\n" );
            set_name("点燃的火折", ({ "fire", "huozhe" }) );
            set("long", "火折正燃着。\n");
            where->add_temp("temp/huo", 100);
			call_out("decay", 120, phase + 1);
			break;
		case 2:
            say( "火折马上要灭了。\n" );
            set_name("快熄灭的火折", ({ "fire", "huozhe" }) );
            set("long", "火折马上要熄灭了。\n");
            where->add_temp("temp/huo",  -50);
	call_out("decay", 60, phase + 1);
			break;
                case 3:
            say( "火折熄灭了。\n" );
            where->add_temp("temp/huo",  -50);
			destruct(this_object());
			break;
	}
}
