// Room: /d/city/laofang.c
// Build by Looklove@sj 2000/10/16
// 2001.9.29 update

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "牢房");
	set("long", @LONG
这里是牢房，房间里很潮湿，光线昏暗，空气弥漫着一股臭气，让人浑身
都不舒服。几个囚犯躺在角落里呻吟着。透过冰冷厚重的铁门，偶尔传来一阵
阵的吆喝声。大概又是在提审什么犯人。
LONG
	);

        set("no_fight", 1);
	set("no_sleep_room", 1);
	set("no_update", 1);
        set("valid_startroom", 1);
        set("objects", ([
		__DIR__"npc/yuzu" : 1,
	]));
	setup();
}

void init()
{
	object me = this_player();
	if (userp(me) && !wiz_level(me) && !me->query_condition("killer"))
		me->apply_condition("killer", 2);
        if (me->query("succor"))
        	call_out("do_succor",1,me);
}

int do_kill(string arg)
{
        string action = query_verb();
        switch (action) {
        case "kill":
        case "hit":
        case "throw":
        case "fight":
        case "perform":
        case "dazuo":
        case "exercise":
        case "tuna":
        case "lian":
        case "practice":
        case "du":
        case "study":
        case "respirate":
        write("都已经到这个地方了，还想那些俗事做什么？\n");
        return 1;
        }
	return 0;
}
void do_succor(object me)
{
	if (!me) return;
	message_vision(HIW"突然外面传来一阵喊杀声，不一会牢门大开。$N跳了进来叫道：“兄弟，快走。天地会劫狱来了！”\n"NOR, me);
	set("exits/east", __DIR__"dilao");
	me->delete("succor");
	remove_call_out("do_close");
        call_out("do_close", 20, me);
}
void do_close(object me)
{
	if (me) message_vision(HIB"牢房的铁门发出一阵响声，自己关上了。\n"NOR, me);
	delete("exits");
}
