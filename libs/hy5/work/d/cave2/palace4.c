 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "大厅");
        set("long", @LONG
推开门，又是间花厅。厅堂的中央，有张桌子，桌子上有只天青
色的大碗，碗里是只烧得红红的鸡。四面的椅子上，坐着几个人。
这几人虽然都是男人，但看来却又和女子相似，每个人都懒洋洋地
坐在那里， 
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"bedroom2",
                "south" : __DIR__"palace3",
                "east" : __DIR__"corridor",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
