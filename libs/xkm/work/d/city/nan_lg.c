//write by bright
// ftb liangong

inherit ROOM;

void create()
{
        set("short","练功室");

        set("long",@LONG
这ㄦ是修练内功，或研读武学书籍之处。房内并无特别摆设,北面
是男休息室。
LONG);
                       
        set("exits",([ 
        "north" : __DIR__"ftb_nan",             
        ]));
        set("cost",0);
        setup();
}
