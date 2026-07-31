// /d/jinghai/moon5.c

inherit ROOM;

void create()
{
        set("short", "明月水寨寨门");
        set("long", @LONG
高大的圆木整齐的排列成两丈多高的寨墙。两扇大木门敞开
着，两侧站立着守门的兵卒，气氛严肃。围墙上树立着无数的旗
杆，上面写着[靖海明月寨]几个大字。又有几副三角旗上书 [明
月水寨总寨]。
LONG
        );

        set("exits", ([
                "south"           : __DIR__"moon6",
                "north"            : __DIR__"moon4",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["north" : __DIR__"moon4"]) );
        set( "close_look",@LONG
这里是明月水寨寨门。现在是天色以晚，寨门已经关上了。
静悄悄的只有几个守卫的水勇们还警惕的站在这里。
LONG
);
        set( "gate_name","明月水寨寨门" );
*/

        set("objects",([
        __DIR__"npc/yong1" : 2,
        __DIR__"npc/duizhang" : 1,
]));

        set("outdoors","jinghai");
        setup();
}
