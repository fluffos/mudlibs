// Room: /d/emei/dongkou.c 山洞口
// create by host dec,20 1997

inherit ROOM;

void init();

void create()
{
        set("short", "山洞口");
	set("long", @LONG
这里有一个山洞入口，绿色的青苔爬满了岩石。在你身后是一条瀑布
直泻而下拍打在岩石上发出轰轰巨响，向洞里望去只见一团漆黑，阴风阵
阵。
LONG
	);
        set("exits", ([
           "east":  __DIR__"shandong1",
	]));
	setup();
}
int valid_leave(object me,string dir)
{
    object *inv;
    int i;
    inv = all_inventory(this_player());
    for(i=sizeof(inv)-1; i>=0; i--) {
    if( inv[i]->is_character() && dir == "east")
        return notify_fail("洞口太小了，只能够容纳一个人进出。\n");
    }
 return ::valid_leave(me,dir);
}