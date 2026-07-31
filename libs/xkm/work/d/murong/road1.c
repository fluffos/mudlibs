//Cracked by Roath
// Room: /d/murong/road1


inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条曲曲弯弯的小路，用鹅卵石铺成，两边种
着许多柳树，透过柳树，你可以看到几处山石花木。
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "east" : __DIR__"tingyu",
        "west" : __DIR__"qing1",
        "northeast" : __DIR__"xiaoqiao",
                      ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
