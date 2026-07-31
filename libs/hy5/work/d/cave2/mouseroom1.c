 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "石室");
        set("long", @LONG
有一张很大很大的石椅，是用一整块石头虽塑成的，虽然是石头，但
比玉质更晶莹，连一丝杂色都看不到，这洞中阴寒之气砭人肌肓，但
只要坐在这石椅上，立刻觉得温暖如春。
像这样的石椅，普天之下，只怕再也找不出第二只了，但现在这石椅
却已被一剑劈成两半！
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"mouseroom2",
                ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}       
