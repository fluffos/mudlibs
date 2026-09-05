//Create by whuan@pkuxkx
//铁掌帮
inherit ROOM;

void create()
{
        set("short", "山脚下");
        set("long", @LONG
这里便是铁掌山的山脚。抬头望去，山分五峰，且排列得就和五根手指一模一样，
中间的最高，两旁顺次矮下来。这还不奇，最奇的是每座山峰又分三截，就如手指的
指节一般。所以当地人又把此地称为“猴爪山”。
LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"road3",
  "northup" : __DIR__"shijie1",
]));
	set("objects",([
		__DIR__"npc/butou":1
	]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        "/clone/board/jiaofei_b"->foo();   
}

int valid_leave(object me, string dir)
{    
    if(userp(me) && me->query("mud_age") < 86400 && dir == "northup")
    {
        return notify_fail("渡月向你微微一笑：这位"+RANK_D->query_respect(me)+"年纪太小，还是不要上山去涉险。\n");
    }
    if(JIAOFEI_D->queryinitprogress() == 1 && dir == "northup")
    {
        return notify_fail("渡月向你微微一笑：剿匪工作尚未准备就绪，这位"+RANK_D->query_respect(me)+"请稍等。\n");
    }
    return ::valid_leave(me, dir);
}

int isstartroom()
{
    return 1;
}