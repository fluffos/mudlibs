// Room: /u/cuer/emei/sheku.c

inherit ROOM;

void create()
{
	set("short", "蛇窟");
	set("long", @LONG
这里就是蛇窟了，四周一片黑暗，但你突然间看见周
围都是毒蛇发光的眼睛，好恐怖啊。毒蛇都向你游来，嘶
嘶的声音令人感到肉麻。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shkrkou",
  "north" : __DIR__"shkjtou",
]));
	set("no_clean_up", 0);
        set("no_task", 1);

	setup(); 
}
	
                      
int valid_leave(object me, string dir)
{
        if (objectp(present("snake", environment(me))) && 
                dir == "north" )
                return notify_fail("毒蛇档住了你的去路！\n");
        return ::valid_leave(me, dir);
}
