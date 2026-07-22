// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/biaoju.c

inherit ROOM;

void create()
{
        set("short", "虎威镖局");
        set("long", @LONG
这是一座建构宏伟的宅第，左右两座石坛中各竖一根两丈来高的旗杆。旗
上黄色丝线绣著一头张牙舞爪的猛虎，旗子随风招展，显得猛虎更奕奕若生。
旗首绣著「虎威镖局」四个黑字，银钩铁划，刚劲非凡。几名劲装汉子在院中
练武，但见个个腰板笔挺，显出一股英悍之气。
LONG
        );
        set("exits", ([
                "south" : __DIR__"biaoju2",
                "north" : __DIR__"westjie3",
        ]));

        set("objects", ([
                __DIR__"npc/tangzishou" : 4,
                __DIR__"npc/biaoshi" : 1,
        ]));

        set("incity",1);
	setup();
}