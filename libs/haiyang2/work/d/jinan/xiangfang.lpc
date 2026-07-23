 inherit ROOM;
void create()
{
        set("short", "西厢房");
        set("long", @LONG
这里是衙门中衙役捕头们日常划拳行酒的厢房，房中几个大通铺可供差役
们休息，几张红木桌子摊满了喝空的酒袋酒坛，残羹冷炙．杯盘狼籍，一股浓
烈的酒气四处弥漫．平日里知府衙门的江师爷也喜欢在这里喝酒闲聊．常常是
不醉不归，众衙役把他抬回家里也成了每日例行的公事．;
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"govern",
]));
        set("objects", ([
        __DIR__"npc/jiang" : 1,
        __DIR__"npc/yayi4" : 2,
                        ]) ); 
    set("coor/x",20);
        set("coor/y",1880);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
