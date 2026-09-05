int generate();
inherit ROOM;
#include <ansi.h>
#include "geneflower.h"
int check_flower();
void create()
{
    set("short", "树林子");
    set("long", @LONG
这里是一片树林子，鲜花遍地，非常美丽。
LONG
    );
     set("exits", ([
 	"northwest" : __DIR__"taolin",
	"northeast" : __DIR__"taolin1",
   
	  ]));
    

    setup();
    call_out("generate",1);
	call_out("check_flower",1);
}

int check_flower()
{
	object *flowers=children("/d/guiyunzhuang/obj/flower");
	int i;
	for (i=0;i<sizeof(flowers);i++)
	{
		if (time()-flowers[i]->query("gene_time")>700&&!flowers[i]->query("nian"))
		{
			message_vision("$N开始有点枯萎了，枝叶都变得蔫蔫的。\n",flowers[i]);
			flowers[i]->set("nian",1);
		}
		if (time()-flowers[i]->query("gene_time")>1400)
		{
			message_vision("$N和地上的稀泥混在一起，不复原型了。\n",flowers[i]);
			destruct(flowers[i]);
		}
	}
	remove_call_out("check_flower");
	call_out("check_flower",30);
	return 1;
}
