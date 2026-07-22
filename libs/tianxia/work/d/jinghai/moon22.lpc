// Room: /d/jinghai/moon22.c

inherit ROOM;

void create()
{
	set("short", "海边茅舍");
	set("long", @LONG
这是一间用很多三寸来长的茅草搭造成的简陋的茅屋。里面
只有一张破旧的木床，一扇小窗向着港湾处敞开着。屋内打扫的
很干净，好像是有人在这里长住的样子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
 "east" : __DIR__"moon1",
]));

	setup();
}

int init()
{
        add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
         object me;
         me = this_player();

         if( !arg || arg != "didao")
         return notify_fail("什么？\n");

         if( me->query("class") != "jinghai")
         return notify_fail("什么？\n");

         if ( arg =="didao")
        {
         write("你钻入床底，突然发现了一条地道，你迅速的钻了进去！\n");
         message("vision",
         me->name() + "趁你不注意，突然钻入床底，消失不见了！\n",
                     environment(me), ({me}) );
         me->move(__DIR__"zhuque12");
         message("vision",
                  me->name() + "突然床底钻出来，拍了拍身上的灰尘，站了起来！\n",
                             environment(me), ({me}) );
          }
          return 1;

}

