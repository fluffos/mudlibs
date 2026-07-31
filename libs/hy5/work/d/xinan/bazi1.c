#include <room.h>
inherit ROOM;


void create()
{
        set("short", "坝子");
        set("long", @LONG
这里是群山环抱的一块土地，当地人称其为“坝子”，就是山间平地，谷地
的意思。大部分老百姓都聚居在一块块分散的“坝子”上。这里土地肥沃，水源
充分，地势平坦适宜耕种。南面又是一座座高山，山上林草丛生。东边有一个小
村子。北面隐隐可望见点苍山顶的皑皑白雪。
LONG
        );
        set("exits", ([
                "southup"     : __DIR__"shangu1",
                "northeast"  : __DIR__"taihe_cun",
        ]));
        set("outdoors","xinan");
	set("objects", ([
		__DIR__"npc/chashang" : 2,
		]) );
        setup();
}
