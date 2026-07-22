//Cracked by Roath
// garbage.c 垃圾
// used to collect object that has delayed call_out but also need destruct

inherit ROOM;

void create()
{
        set("short", "垃圾箱");
        set("long", @LONG
峨嵋垃圾箱。
LONG
        );

        set("no_clean_up", 1);
	set("no_get", 1);

	set("cost", 0);
        setup();
//	replace_program(ROOM);
}

int start_call_out(function fun, int delay)
{
	call_out("eval_function", delay, fun);
	return 1;
}
