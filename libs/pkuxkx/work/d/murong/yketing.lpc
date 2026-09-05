//yketing.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "客厅");
    set("long", @LONG
大厅中陈设简朴, 无什摆设, 正堂上挂着许多人物字画, 都是容氏祖先
的遗迹, 用来表示对先人的尊敬。西面通向慕容家的书房。里面是内室
了。
LONG
    );

    set("exits", ([
		"west" : __DIR__"yshufang",
		"north" : __DIR__"yneishi",
		"south" : __DIR__"yyuan3",
    ]));

	set("objects", ([
                 CLASS_D("murong/deng") : 1,
		]));
    
 set("valid_startroom",1);
    setup();
   "/clone/board/murong_b"->foo();

}
