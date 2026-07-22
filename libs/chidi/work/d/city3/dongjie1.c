//by enter

inherit ROOM;

void create()
{
        set("short", "东大街");
        set("long", @LONG
这条街贯穿成都大街小巷，因这条街沿街都是有钱有势的酒
楼、饭馆，所以又称为“美食街”。这里店铺林立，商贾成群。
白天这里车马如龙，人声鼎沸，夜里星光伴月，灯火通明。南边
便是成都著名的商业中心：春熙路。北边有个客栈。
LONG
        );

        set("exits", ([
                "north" : __DIR__"kedian",
                "south" : __DIR__"chunxilu",
                "west" : __DIR__"guangchang",
                "east" : __DIR__"dongjie2",                
        ]));
        set("outdoors","chengdu");
      
        setup();
        replace_program(ROOM);
}

 
