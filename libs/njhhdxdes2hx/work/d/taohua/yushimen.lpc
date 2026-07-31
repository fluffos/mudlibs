// Room: /d/new_taohua/yushimen.c

inherit ROOM;

void create()
{
	set("short", "寝室大门");
	set("long", @LONG
这里是寝室大门，往北是男寝室，往南是女寝室。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north" : __DIR__"nanqinshi",
  "south": __DIR__"nvqinshi",
  "west" : __DIR__"houting",
]));
	

	setup();

}
int valid_leave(object me, string dir)
{

        if (me->query("gender")=="男性" && dir=="south")
              return notify_fail("男弟子不能入女寝室。\n");
        if (me->query("gender")=="女性" && dir=="north")
              return notify_fail("女弟子到男寝室干什么?\n");
        
          return ::valid_leave(me, dir);
}
