// wdroad6.c 黄土路

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里是鄂西，据
说经常有土匪出没，不可久留。
LONG
	);
        set("outdoors", "武当");

	set("exits", ([
                "east" : "/d/xiangyang/hanshui2",
		"west" : "/d/group/entry/wdroad7",
	]));
        set("objects",([
                CLASS_D("wudang")+"/quanjiannan" : 1,
                CLASS_D("wudang")+"/qlbz" : 2,
        ]));

        setup();
}
