 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "泥道");
        set("long", @LONG
再往上，道路愈加泥泞，已需手脚并用，洞顶上滴滴答答地往下淌水，
竟如下起了小雨，耳边隐隐有隆隆之声，如雷鸣，又如千军万马在高处奔
腾。亮光越来越强，顽强地拨开水雾。
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"exit2",
                "southup" : __DIR__"exit",
                        ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
