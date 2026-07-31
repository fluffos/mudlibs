//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "小青锋");
        set ("long", @LONG
此铺的大老板乃是洛阳金刀王家的武术教头聂青锋，大掌柜则是
小教头小青锋。十八般外门兵器，这里应有尽有。四周的墙上还陈列
着大唐天朝上赫赫有名的人物赖以成名的奇门兵器。
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"dingde1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/qingfeng" : 1,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


