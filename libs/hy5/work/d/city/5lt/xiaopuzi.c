// Room: /d/changan/xiaopuzi.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "小铺子");
	set  ("long",  @LONG
这是一家小铺子。里面是当铺。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"north"  :  __DIR__"wroad1",
		"south"  :  __DIR__"dangpu2",	
	]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tangxue" : 1,
 
]));	
set("roomif","$botten#卖|买|赎|估价|查看防具|查看书籍|查看其他|查看武器:sell <物品>|buy <物品>|redeem <物品>|value <物品>|list armor|list book|list misc|list weapon$#");
set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("coor/x", -160);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
