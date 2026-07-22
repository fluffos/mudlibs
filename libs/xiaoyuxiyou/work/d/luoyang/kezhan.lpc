//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "星月客店");
        set ("long", @LONG
这是一家靠十字路口的客栈，店铺很有点规模了，生意也不错，许多过往
的人都喜欢选择这里落脚，因为这里的店主也是一个江湖中人，所以很少有人
会来此闹事，小二忙前忙后的招呼客人，店主也满脸笑容的陪着说好话。让人
有一种归家的感觉。
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"qianyuan1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
               __DIR__"npc/xiaoer" : 1,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


