inherit ROOM;
void create()
{
        set("short", "坡地");
        set("long", @LONG
在这里似乎可以闻到烟雨江南的味道。不远处的浣花溪就和江南的
大部分东西一样，小而精致可爱。在破晓前后，天空是灰色的，云层也
是灰色的，把整个浣花溪全部溶入了这一片灰潆。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bridge3",
  "west" : __DIR__"xiaoqiao", 
"southwest" : "/d/dali/xidajie3",]));	
        set("outdoors", "chenxiang");
        set("coor/x",40);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-110);
	set("coor/z",0);
	set("coor/x",40);
	set("coor/y",-110);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
