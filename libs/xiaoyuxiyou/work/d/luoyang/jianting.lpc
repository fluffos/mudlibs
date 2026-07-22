//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "风刀霜剑亭");
        set ("long", @LONG
大唐朝的各位英雄和官府的将军士兵们都认为祭剑是取得胜利的
必要条件之一。每逢武者出行或者将军出征，大家都会到这儿来祭一
次兵刃，以求好运。
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"chengyun1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jijian" : 1,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


