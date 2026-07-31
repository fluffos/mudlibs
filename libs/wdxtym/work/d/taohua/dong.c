#include <ansi.h>
inherit ROOM;
 
int do_pick(string arg) ;

void create()
{
	set("short", "山洞");
	set("long",@LONG
你正处在一个小山洞中。这里光线很暗，只能隐隐约约看出地上有
一堆干草。你突然闻到一股难闻的气味，显然是有人长期住在这里却不
打扫的缘故，可是现在没有一个人在这里。
LONG);   
	set("item_desc", ([
	"xia" : @TEXT
你仔细看了一下石匣，发现里面似乎放着一本书，似乎可以试着拿出来(pick book)。
TEXT ]) );
	set("exits", ([
	    "out"  : __DIR__"road5",
	]));
	setup();
}
