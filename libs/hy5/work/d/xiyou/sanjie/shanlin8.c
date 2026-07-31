// sanjie shanlin8.c

inherit ROOM;
void create()
{
        set("short", "瘴气林");
        set("long", @LONG
        
这是一片茂密的树林，长的大数有几层楼高，而且叶子茂密，
阳光都给遮蔽了，林子里面暗无天日。林子连瘴气重重，毒
蛇怪物满地爬走，好像一点都不怕人。山下有个山洞(cave)。
LONG );
	set("item_desc", ([
  	"cave" : "【藏尸地】：尸家重地，闲人免进\n",
	]));
        set("outdoors", 1);
        set("exits", ([
              "north" : __DIR__"shanlin7",
              "enter" : __DIR__"cangshilang1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
