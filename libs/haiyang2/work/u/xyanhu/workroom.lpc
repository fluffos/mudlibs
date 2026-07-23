// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
              set("short", "北京的工作间");
	set("long", @LONG
这里是北京的工作间，自从升arch以来，这里装修一新！
虽然只有一个房间，陈设简朴，但是窗明几净，大方温馨。
北京在这里认真和玩家对话并学习简单编程技巧。
累了的时候就发发呆，或者在工作台上休息一下。


LONG );

	set("exits", ([ /* sizeof() == 1 */
                  "down" : "/d/city/guangchang",
            "wl" : "/d/wizard/wizard_room",
              "lj" : "/u/guaf/lujing",
	]));
                set("objects",([
      "/clone/gem/zhang" : 1,
    ]));
//        set("no_fight", "0");
	set("no_clean_up", 0);
        set("valid_startroom", "1");
	setup();

        call_other("/u/guaf/guaf_b", "???");
	replace_program(ROOM);
}
