// /d/hmy/wulao.c 五老峰
inherit ROOM;

void create()
{
	set("short", "五老峰");
	set("long", @LONG
此处有五坐石峰紧紧相靠，石峰自上而下有数百年的草藤随风飘洒，就象
年逾古稀的五位老朋友在叙旧一般。这里远离人烟，动物渐多，眼前就有一对
猴群(houqun)跳上跳下。
LONG
    );
        set("exits",([
            "west" : __DIR__"lianhua",
            "east" : __DIR__"ziyun",
            "north" : __DIR__"yiping",
            "south" : __DIR__"rusheng",
        ]));
        set("objects", ([
                __DIR__"npc/houzi": 2,
                __DIR__"npc/xiaohou": 2,

	]));
	set("outdoors", "黑木崖");	
	set("item_desc", ([
        	"houqun" : "这群猴子自跳自闹，一会跳下峰壁，一会又窜上峰顶。\n",
	]));
	setup();
}
