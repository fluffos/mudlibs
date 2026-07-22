#include <mudlib.h>
#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "idleroom", "发呆幻想室" );
set_long(
   "this is a workroom\n",
   "这是宁丹的最爱的幻想空间\n\n" 
   "    你看到房间内都是软骨头，红的，黄的，绿的，甚麽颜色都有，\n"
   "    只要你慢慢寻找，可能宁丹最在这□发呆，寻找他的灵感！\n"
   "    房间的正中间，摆\著宁丹最重要的东西，咖啡，音乐，和电话，\n"
   "    宁丹每天离不开这些东西，一旦缺了一样，宁丹会变成另一个人似的\n"
   "    会觉得生命总是缺少了甚麽，桌上放了一个字条(sign)!\n"
   "    往北则是宁丹的工作室\n\n"
	);
	set("light",1);

	set( "exits", ([
		"north" : HOME"workroom"
	]) );
//     reset();
}

