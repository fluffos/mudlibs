// 空地.c
// 空地
inherit ROOM;
void create()
{
	set("short","林间空地");
	set("long",@long
这里是林间的一块空地，一走进这里就可以闻到一股浓浓的雄黄味扑鼻而
来。在空地上有两三间竹屋，屋子的墙壁、屋顶均由碗口大小的粗竹所编，看
来甚是坚定。屋后有道山溪垂山而下。
long);
	set("exits",([
	    "north" : __DIR__"treen2",
           "south" : __DIR__"trees2",
           "northup" : __DIR__"sanroad1",
           "enter" : __DIR__"lgxroom",
]));

	set("outdoors", "神龙岛");
        set("coor/x",490);
  set("coor/y",410);
   set("coor/z",0);
   setup();
       call_other( "/clone/board/sld_b", "???" );
}
	    	
