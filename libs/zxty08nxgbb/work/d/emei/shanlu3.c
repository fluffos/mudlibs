// shanlu3.c 山路3
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
走出了茂密的树林，道路豁然开朗。一条大道直通到一座大山山脚。远
远望去隐约看望见不远处有一座寺庙。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "south": __DIR__"shanmen",
                "east": __DIR__"shanlu2",
                
      	]));
	setup();
}

