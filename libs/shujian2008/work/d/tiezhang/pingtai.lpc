// Room: /u/zqb/tiezhang/pingtai.c

inherit ROOM;
string look_ditu();
void create()
{
	set("short", "山间平台");
	set("long", @LONG
这里是山间的一块平地。山势在这里开始分支，矗立在面前的有五座高耸
入云的山峰，行似人的五指，“铁掌山”之名由此而得。五峰虽同 处此山，但
拇指峰之雄伟，食指峰之险峻，中指峰之高耸，无名峰之奇丽，小指峰之秀美，
则各有特色，各擅胜场。在平台一侧的大石上，刻着一副地图(ditu)。
LONG
	);

	set("item_desc", ([ 
"ditu" : (: look_ditu :),
]));

	set("exits", ([ 
"westup" : __DIR__"shanlu-5",
"northeast" : __DIR__"shangu-1",
"eastup" : __DIR__"sslu-1",
"southdown" : __DIR__"shanlu-4",
"northwest" : __DIR__"hclu",
"northup" : __DIR__"shanlu-6",
]));

    set("objects", ([ 
__DIR__"npc/huiyi" : 3,
]));

	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-330);
  set("coor/y",-200);
   set("coor/z",30);
   setup();
	
}

string look_ditu()
{
    return
    "\n"
    "############################\n"
    "#          中指峰          #\n"
    "#            ||            #\n"
    "#    无名峰  ||  食指峰    #\n"
    "#         \\ || //         #\n"
    "#          \\||//          #\n"
    "# 小指峰====平台====拇指峰 #\n"
    "############################\n";
}
