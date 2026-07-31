//Cracked by Roath
//fear 2002 1 31

inherit ROOM;

void create()
{
        set("short", "山洞口");
        set("long", @LONG
这里是一道山壁，山壁是光滑的天然花岗岩形成的。山壁上面有个
极大的裂缝，似乎是一个山洞。从山洞口望进去，里面非常幽暗。往东
北方过去是一条碎石小路。
LONG
        );
        set("exits", ([
                "enter" : __DIR__"cave2",
				 "northeast" : __DIR__"xiaolu",
        ]));

	set("outdoors", "lingshedao");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

