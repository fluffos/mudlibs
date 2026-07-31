inherit ROOM;
void create()
{
	set("short", "扬州驿站");
	set("long", @LONG
这里是负责扬州城官府文书和百姓的信件收发的驿站，驿站大门口上
悬著一块木牌(sign)，上面写了些字。

       向杜宽要任务为  squest。


LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
	    "sign" : "奉扬州知府之命，为整顿信件收发混乱，方便我方百姓，\n"
	    "所有邮件一律免费收发。（看信请ask officer about mail）\n",
]));
	set("exits", ([ /* sizeof() == 1 */
	       
		"west" : "/d/city/beimen",
	]));
	set("objects", ([
		__DIR__"npc/post_officer": 1
	]) );
	set("no_fight",1);
	setup();
}

