inherit ROOM;
#include <ansi.h>

string *strs = ({
        " 混沌初分盘古先，太极两仪四象悬， \n",
        " 子天丑地人寅出，避除兽患有巢贤。 \n",
        " 燧人取火免鲜食，伏羲画卦阴阳前， \n",
        " 神农治世尝百草，轩辕礼乐婚姻联。 \n",
        " 少昊五帝民物阜，禹王治水洪波蠲,  \n",
        " 承平享国至四百，桀王无道乾坤颠。 \n",
        " 周室开基立帝图，分茅列土报功殊.  \n",
     });
     
void create()
{
	set ("short", "大唐书院");
  	set ("long", @LONG

这个地方就是大唐的书院了，很多新手的读书写字都是这里   
强化(dushu)的,远远看到个牌子,上书：大 唐 书 院
LONG);

  	set("exits", ([
		"west" : __DIR__"guozijian",
	]));
  	set("objects", ([ 
		__DIR__"npc/wuji" : 1,
		__DIR__"npc/xiucai4" : 1,
	]));
  	setup();
}

void init()
{
	add_action("do_dushu", "dushu");
}

int do_dushu()
{ 
	object who=this_player();
	if( !query("jiangjing") )
		return 0;     
	if(who->query("kee")<20||who->query("gin")<20) 
		return notify_fail("读书这么用功?还是先去休息休息吧!\n");
	if( who->query("class")!="scholar" )
		return notify_fail("贺知章对你摇摇手说:暂时不收没有拜师的弟子.\n");
     	if(who->is_busy())
        	return notify_fail("你正忙着呢。\n");
	tell_object( who,"你低眉垂目，口中微颂："+strs[random( sizeof(strs) )] );
     	who->start_busy(5);
     	who->improve_skill(   "literate",random(  (int)( who->query("spi")+who->query("int"))));
     	if( who->query("haoran-zhengqi",2)>100 )
     		who->improve_skill("haoran-zhengqi",random(  (int)( who->query("spi")+who->query("int"))));
     	if( who->query("haoran-jian",2)>100 )
     		who->improve_skill("haoran-jian",random(  (int)( who->query("spi")+who->query("int"))));
     	who->receive_damage("kee",20);
       	who->receive_damage("sen",20);
     	tell_object(who,"你觉得自己的又了解了些世界的发展历程！\n");
     	return 1;
}