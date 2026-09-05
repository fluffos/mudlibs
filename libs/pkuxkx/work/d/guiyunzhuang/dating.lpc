// guiyunzhuang/dating 大厅
#include <ansi.h>
inherit ROOM;
string look_tu();
void create()
{
        set("short", HIC"大厅"NOR);
        set("long", "这里是归云庄的大厅，是庄主会客的地方，里面威严地站着两排卫士。
正堂前挂着一块金匾(bian)，金匾上的金字使得整个大堂奕奕生辉。墙上是
一幅八卦图(tu)。\n");
	set("valid_startroom",1);
set("item_desc",(["bian":HIY"归云庄\n"NOR,
    "tu":(:look_tu:),]));  
      set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"zoulang1",
        "east" : __DIR__"zoulang3",
	"north":__DIR__"zoulang2",
	"south":__DIR__"zoulang4",
        ]));
	set("objects",([
        CLASS_D("taohua") + "/lu-chengfeng":1,
	__DIR__"npc/shi":6,
	]));
	setup();
	
}
string look_tu()
{
    object me=this_player();
    string msg;
    if (me->query_temp("thnewbiejob/taolin/gua"))
    {
        msg="铁八卦上刻着八排小字：\n";
        msg+="乾天：东 东北 西 南\n";
        msg+="兑泽：北 西南 西北 南\n";
        msg+="离火：南 北 东南 西北\n";
        msg+="震雷：西 东南 北 北\n";
        msg+="巽风：东南 东 南 西南\n";
        msg+="坎水：东北 北 西南 西北\n";
        msg+="艮山：西南 西 西 南\n";
        msg+="坤地：西北 西北 南 东\n";
        msg+="\n";
        return msg;
    }
    return "这是一幅精致的八卦图。\n";
}