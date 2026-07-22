//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "龙腾武馆");
        set ("long", @LONG
你现在正站在一个巨大武馆的教练场中，地上铺着黄色的细砂，一群
二十来岁的年轻人正在这里努力地操练着, 还有一个中年汉子在不停
的喊着号子，让人振奋。

LONG);

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"qianyuan2",
                "west" : __DIR__"wuguan2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/dizi" : 2,
		__DIR__"npc/jiaotou" : 1,                
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


