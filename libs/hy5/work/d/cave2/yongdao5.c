 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "白石道");
        set("long", @LONG
石道两旁，都砌着白玉般晶莹光滑的石块，顶上隐隐有灯光透出却瞧不
见灯是嵌在那里的。这石道的地上，竟留着一行脚印，每隔叁尺，就有一个，
就算是用尺量着昼上去的，也没有如此规律整齐。这甬道中地上铺的石头，
也和两壁一样，平滑坚实，就算是用刀来刻，也十分不容易。但这人的脚印
竟比刀刻的还清楚。
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"yongdao7",
                "westup" : __DIR__"yongdao4",
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
