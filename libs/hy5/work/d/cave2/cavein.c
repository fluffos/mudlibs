 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "石洞");
        set("long", @LONG
一入洞，竟是别有一番景象，洞壁上几根儿臂似的牛油巨烛把四周照的亮堂
堂的，地上由碎石铺成，最令人惊讶的是，这碎石竟然还砌成了一个狰狞的人像，
青面獠牙，左手持叉，右手执鞭。洞底凹凸不平，有一股潮湿的霉臭之味，似是
一条多年不用的隧道。
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao1",  
        ]));
        set("objects", ([ 
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        this_player()->set("startroom", base_name(this_object()));
}
