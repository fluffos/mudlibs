
// Room: /d/snow/postoffice.c

inherit ROOM;

void create()
{
    
	set("coor",({-20,4850,10}));
	set("short", "官府驿站");
	set("long",
"这里是负责宁远城官府文书跟军令往来的驿站，但是因为出了宁远城往西北就是通往西域的\n"
"一片无人居住的大沙漠，所以驿站来往的人就少了，驿站的官员索性就开始接一些百姓的信\n"
"件，一方面打发时间，一方面也有点事做以免被上级裁撤。\n"
);

	set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"nroad2",
                "west" : __DIR__"yamen_square"
	]));
	set("outdoors", "ny");
	set("objects", ([
        __DIR__"npc/post_officer" : 1,   
	"/clone/misc/dache" : 1 
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

    return 1;
	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "你将信箱交回驿站。\n");
		destruct(mbox);
	}
	return 1;
}
