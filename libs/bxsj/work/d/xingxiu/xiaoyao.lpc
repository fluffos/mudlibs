// Xiaoyao.c:  the sleeping room for Xingxiu
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
	set("short", "逍遥洞");
	set("long", @LONG
这里就是星宿弟子淫乐之处。原来不过是一粗糙的石洞，后因众星宿弟子
不断修缮，成了方园几百里臭名昭著的淫窟。不知有多少可怜的牧羊女在此度
过了暗无天日的余生。洞壁(wall)上有些字迹。
LONG);

        set("no_get_from", 1);
        set("no_fight", "1");
        set("sleep_room", "1");

        set("exits", ([
                "out" : __DIR__"xx3",
        ]));

        set("item_desc", ([
		"wall" : "打倒星宿淫虫！星宿淫虫不得好死！\n",
        ]));
        setup();
}
