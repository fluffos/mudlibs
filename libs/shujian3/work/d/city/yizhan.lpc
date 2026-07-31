// Room: /d/city/yizhan.c

inherit ROOM;

void create()
{
        set("short", "驿站");
        set("long", @LONG
这是扬州驿站，负责传送和京城里的往来公文。每天快马三匹，早午晚各
传递书信三次。不管你的书信要寄到哪里，只要放到这里，一天之内绝对可以
送到，北边是一家新开的花店，据说里面的老板非常漂亮。
LONG
        );
        set("exits", ([
                "west" : __DIR__"beidajie3",
                "north" : __DIR__"huadian",
        ]));

/*
        set("objects", ([
                __DIR__"npc/youtanzhi" : 1,
        ]));

*/
        set("coor/x",130);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",130);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",130);
  set("coor/y",0);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
        object mbox;

        if (in_input(me)) return 0;
        if( mbox = me->query_temp("mbox_ob") ) {
          tell_object(me, "你将信箱还给了游坦之。\n");
                destruct(mbox);
        }
           return ::valid_leave(me, dir);
}

