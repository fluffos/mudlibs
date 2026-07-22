
inherit ROOM;

void create()
{
	set("short", "薛涛井");
	set("long", @LONG
这里是一代女诗人薛涛葬身之地，四周竹林环绕，静悄悄的
连自己的脚步声都听得到，你的面前有口古井，上面长满了青苔，
看起来已经很久没人来过了。
LONG
	);

	set("exits", ([
                "west" : __DIR__"wanliqiao",
	]));

        set("outdoors", "chengdu");
	setup();
	replace_program(ROOM);
}



