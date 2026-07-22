inherit ROOM;

void create()
{
        set("short", "赌场");
        set("long", @LONG
这里是一个骨骰房，房间不大，挤满了急于翻本的人，屋子中间的桌子边
上站着一位四十多岁的人，正在那里吆五喝六，一看就是一个赌场高手，被老
板请来做庄家。墙上挂着一块牌子(paizi)。
LONG
        );

        set("item_desc", ([
                "paizi" : "
ya tc <数量> <coin|silver|gold> 押头彩(两数顺序及点数均正确)       一赔三十五
ya dc <数量> <coin|silver|gold> 押大彩(两数点数正确)               一赔十七\n"
//	"ya sd <数量> <coin|silver|gold> 押双对(两数相同且均为偶数)         一赔十一\n"
"ya kp <数量> <coin|silver|gold> 押空盘(两数不同且均为偶数)         一赔五
ya qx <数量> <coin|silver|gold> 押七星(两数之和为七)               一赔五
ya dd <数量> <coin|silver|gold> 押单对(两数均为奇数)               一赔三
ya sx <数量> <coin|silver|gold> 押散星(两数之和为三、五、九、十一) 一赔二
每盘按从上到下的顺序只出现一种点型(头彩和大彩可同时出现)，其他情况都算庄家赢。
\n",
        ]));
        set("no_fight",1);
        set("sleep_room",1);
        set("no_sleep_room",1);
        set("exits", ([
                "north" : __DIR__"duchang",
        ]));
        set("objects", ([
                  __DIR__"npc/zhuangjia" : 1,
        ]));
        set("coor/x",90);
  set("coor/y",-30);
   set("coor/z",0);
   set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && me->query("balance")<100)
        tell_object(me,"穷鬼，没钱?!下次不要来！\n");
        return ::valid_leave(me, dir);
}
