// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW+"华筝的内帐"+NOR);
	set("long", @LONG
这里是华筝住所的内帐。
LONG
	);

	set("exits", ([
        "out" : __DIR__"hua_bao",
	]));
	set("objects", ([
        	__DIR__"npc/shinv" : 1,
	]));
	set("no_robber",1);
	set("sleep_room", "1");
	setup();
    call_out("gene_huazheng",1);
}

int gene_huazheng()
{
    object hua;
    object *ob=livings();
    int i,flag=0;
    for (i=0;i<sizeof(ob);i++)
    {
        if (ob[i]->query("is_huazheng")&&ob[i]->query("is_for_shediao_quest"))
        {
            flag=1;
        }
    }
    if (flag==0)
    {
            hua=new(__DIR__"npc/huazheng");
            hua->move(this_object());
    }
    remove_call_out("gene_huazheng");
    call_out("gene_huazheng",1800);
    return 1;
}

