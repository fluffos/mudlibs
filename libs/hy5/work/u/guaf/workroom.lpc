// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
            set("short", "刮风休息室");
	set("long", @LONG
这里是刮风的休息场所，新装修的房子，还没有什么家具。房
子朝阳的方向有一个大大的落地窗户，外面的阳光通过玻璃照亮了
整个房间。靠房子的东边有一张床，很普通的床，上面的被子叠的
整整齐齐，看的出主人是个很有条理的人。


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
