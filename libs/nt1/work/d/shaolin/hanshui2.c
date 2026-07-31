// Room: /d/shaolin/hanshui2.c
// Date: YZC 96/01/19


#include <ansi.h> 
#include <room.h> 

inherit RIVER; 

void create()
{
	set("short", "汉水北岸");
	set("long", @LONG
汉水北岸也是相当热闹，自北岸渡口往北，一条笔直的官道直通南阳。
此地民风淳朴，路旁夹柳成阴，酒厮林立，且都有一面大大的「酒」旗迎
风飘扬，蔚为壮观。也有不少小贩沿路叫买，语多难辨，却也令人盛情难
却。
LONG );

    set("exits", ([
	"north" : __DIR__"nanyang",
    ]));
        set("arrive_room", "/d/shaolin/hanshui1"); 

    set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
    ]));

        set("resource/fish", ({ "/clone/fish/liyu", 
                                "/clone/fish/jiyu", 
                                "/clone/fish/qingyu", 
                                "/clone/fish/caoyu", })); 
    set("outdoors", "shaolin");
    set("no_clean_up", 0);
    setup();
    replace_program(RIVER); 
}
