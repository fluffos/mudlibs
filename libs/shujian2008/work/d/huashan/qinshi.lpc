// Room: /d/huashan/qinshi.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "寝室");
        set("long", @LONG
这里是岳不群的寝室，岳不群在江湖上人称「君子剑」，他虽为一大派掌门，
可他的卧室却布置的很简单。除了一张床，几只箱子，墙角有张化妆台，只有靠墙
一张红木书桌(desk)还显得略有气派。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"houtang",
	]));
        set ("item_desc", ([
                "desk" : 
"这是一张很结实的红木书桌，桌面上摆着几只狼毫笔，磨了一半的墨，\n"
"还有一叠未用的白纸。\n"
        ])  ) ;

	 set("objects",([
	 	__DIR__"obj/shengzi" : 1,
	 ]));

        set("no_clean_up", 0);
	 set("indoors", "华山" );

        set("coor/x",80);
  set("coor/y",-40);
   set("coor/z",80);
   setup();
}
