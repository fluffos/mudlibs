// by mayue

inherit ROOM;

void create()
{
	set("short", "江边小路");
	set("long", @LONG
这里是桃花江边的一条泥土小路，一旁就是清澈的江水。夹岸
连绵不断的桃花灿若云霞，暗香袭人，引来许多蜜蜂在花树间飞舞。
前面有一个木牌(pai)立在路中央,由于风吹日晒，字迹已经模糊了。
西边通向昆明。
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"southeast" : __DIR__"xiaolu",
		"southeast" : __DIR__"taohua",
//		"west" : __DIR__"wumiao",
		"west" : "/d/kunming/qingshilu",
		"northwest" : __DIR__"xiao2",
	]));
        set("objects", ([
                "/clone/misc/dache": 1,
	]));
   set("item_desc",([
    "pai":"         前方桃花峪......,.....瘴气.....危险。本村之人....闯入。\n
                                                村长  苗三斤 \n",
]));
   

	setup();
	replace_program(ROOM);
}

