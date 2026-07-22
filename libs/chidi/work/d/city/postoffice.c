// Room: /d/snow/postoffice.c
inherit ROOM;
void create()
{
	set("short", "扬州驿站");
	set("long", @LONG
这里是负责扬州城官府文书和百姓的信件收发的驿站，驿站大门口上
悬著一块木牌(sign)，上面写了些字。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "奉扬州知府之命，为整顿信件收发混乱，方便我方百姓，\n"
           "所有邮件一律免费收发。（看信请ask officer about mail）\n",
]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"beimen",
	]));
	set("objects", ([
		__DIR__"npc/post_officer": 1
	]) );
	setup();
}
int valid_leave(object me, string dir)
{
	object mbox;
	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "你将信箱交回驿站。\n");
		destruct(mbox);
	}
	return 1;
}
