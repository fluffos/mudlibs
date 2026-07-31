 // Silencer@FY workgroup  恶人窟
inherit ROOM;
void create()
{
        set("short", "石洞");
        set("long", @LONG
一入洞，别有一番景象，洞壁上几根儿臂粗的牛油巨烛把四周照得亮堂堂，地
上由碎石铺成，砌成了一个狰狞的人像，青面獠牙，左手持叉，右手执鞭。洞内有
一股潮湿的霉臭之味，似是一条多年不用的隧道。没有回头的路，不知道前方等待
着你的是什么。
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
        set("valid_startroom",1);
        setup();
} 
void init()
{
        this_player()->set("startroom", base_name(this_object()));
}     
