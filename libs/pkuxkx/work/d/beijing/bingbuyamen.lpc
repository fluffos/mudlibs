
// Room: /d/beijing/bingbuyamen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"兵部府衙大门"NOR);
	set("long",
CYN"这里是当今朝廷的兵部衙门。左右两边是肃立的官兵，正前方
是一个很大的厅堂。兵部尚书高高地坐在里面太师椅上查阅通文，
一群文秘跑来跑去，有时还抱着一些名册。墙上有一个告示(gaoshi).\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"guloudajie_w",
        "south" : __DIR__"bingbuyamen2",
	]));

	set("objects", ([
	    "/d/beijing/npc/shiwei":4,
	]));

  	set("item_desc", ([
	"gaoshi" : "米尚书亲临处理投军，升迁，退役等事宜。\n",
	]));


	setup();

}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if( dir !="south" || me->query("class") == "officer")
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "shi wei" )
            return notify_fail("侍卫伸手拦住你朗声说道：里面没什么好看的，马上离开这里....！\n");
    }            
    return ::valid_leave(me, dir);
}
