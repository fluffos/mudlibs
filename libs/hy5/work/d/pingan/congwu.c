//congwu
  

inherit ROOM;

void create()
{
	set("short","龙门镖局");
	set("long", @LONG
这儿是平安城第一号镖局，正对面是一人多高的香案，双旁坐
着众位镖头。亭中央的虎头椅上正是龙门镖局的总镖头都大锦。亭
外竖着块招牌(pai)，不知写些什么。
LONG
	);

       set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("exits", ([
		"west" : __DIR__"nan3",
		 
	]));

        set("item_desc", ([
	"pai":
"		    告示
－－－－－－－－－－－－－－－－－－－－－－
本镖局提供各种等级的镖师为你提供安全保证。
根据招慕的镖师武功及数量，本镖局收取不同
的费用。
指令：先买令牌.然后遇危险里用huwei.

镖师名         说     明         费     用
－－－－－－－－－－－－－－－－－－－－－－
qinglong       青龙镖师          五十两黄金
baihu          白虎镖师          四十两黄金
lvbao          绿豹镖师          二十两黄金
chilang        赤狼镖师          十两黄金
jinshe         金蛇镖师          一两黄金
－－－－－－－－－－－－－－－－－－－－－－
－－－－－－－－－－－－－－－－－－－－－－
                        龙门镖局总镖头都大锦\n"
	]));

	set("objects",([
		__DIR__"npc/dudajin":1,
	]));

       set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	setup();
	replace_program(ROOM);
}

