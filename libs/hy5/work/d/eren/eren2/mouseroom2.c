 inherit ROOM;
void create()
{
        set("short", "主室");
        set("long", @LONG
穿过石室，是一条长长的走廊。两侧的洞壁上绘有人像，仔细看去，
是两个貌美的轻纱女子或在奏乐，或在起舞。大理石的地面倒映出人影，
此处的主人定是身缠万贯。唯一奇怪的是，偶尔还会有几只黑鼠大摇大
摆地从身边穿过，并不怕人。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"smallroom1",
                "west" : __DIR__"smallroom2",
                "north" : __DIR__"mouseroom3",
                "southwest" : __DIR__"mouseroom1",
                ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
