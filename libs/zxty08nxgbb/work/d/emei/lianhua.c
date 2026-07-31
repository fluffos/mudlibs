// /d/emei/lianhua.c 峨嵋派 莲花峰
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "莲花峰");
	set("long", @LONG
这里是峨嵋的中峰，莲花峰。莲花峰地势略为平缓，不似其它山峰般
险峻，西边有所小小的庙宇，那就是万行庵了。再往上就是峨嵋的最高顶，
东北面稀稀落落有十几间房子，是峨嵋派的地方，闲杂游客最好别往那里
去。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ 
                "northdown":__DIR__"shijie2",
                "southup": __DIR__"shijie3",
                "west" : __DIR__"wanxingan",
		]));
	set("objects", ([ 
	]));

	setup();
}
