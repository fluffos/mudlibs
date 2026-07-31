// Room: /d/tianshui/business.c

inherit ROOM;

void create()
{
        set("short", "天水城商栈");
        set("long", @LONG
这里就是著名的天水商栈，天水买卖商品的集散地，也是富
商大贾云集之所，由天水商会控制。在天水大宗商品的买卖都要
通过这里进行。门口挂着一块木牌(sign)。
LONG
        );



	set("exits",([
	"east" : __DIR__"sroad2",
]));

    
 
        setup();
}

