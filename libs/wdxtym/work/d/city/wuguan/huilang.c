//huilang.c by river

inherit ROOM;
void create()
{
        set("short", "回廊");
        set("long", @LONG
这是一条回廊，廊顶描绘着江南秀美的风景。每两根翠绿色的柱子间相隔
也就两三尺的距离，朱红色的琉璃瓦，嫩黄色的地砖。在走廊里面，丫鬟、奴
仆们走来走去，都忙着自己的事情，不敢有一点怠慢。往东能看见一条小径通
向后花园的，西面是一条很长的走廊。 
LONG
        );
	set("no_fight",1);
        set("exits", ([
               "west" : __DIR__"zoulang7",
               "east" : __DIR__"xiaojing2",
        ]));
 
        setup();
}
