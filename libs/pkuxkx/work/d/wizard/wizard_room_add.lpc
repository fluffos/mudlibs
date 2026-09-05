#include <ansi.h>
inherit ROOM;

void create()
{
        set("long",HIR"\n"
HIW"●"HIR"这里是add得个人工作室。\n"
HIW"★"HIY"下面是一些常用出口。\n"
HIW"
01.扬州		02.华山		03.全真		04.武当		05.星宿		06.大理\n
07.襄阳		08.日月教	09.归云庄	10.侠客岛	11.钓鱼岛	12.泰山\n
13.峨嵋		14.古墓		15.杀手帮	16.灵州		17.华山村	18.泉州\n
19.张三丰处	20.少林\n"NOR);
       set("valid_startroom",1);
       set("exits", ([
"01":"/d/city/guangchang",
"east":"/d/wizard/wizard_room",
		"02":"/d/huashan/houhuayuan1",
		"03":"/d/quanzhen/xuanzt",
                "04":"/d/wudang/houtang",
		"05":"/d/xingxiu/xxh2",
                "06":"/d/dali/muwu",
		"07":"/d/xiangyang/xycenter",
		"08":"/d/riyuejiao/dadian1",
		"09":"/d/guiyunzhuang/guiyunting",
		"10":"/d/xiakedao/shishi1",
		"11":"/d/diaoyudao/dazhang",
		"12":"/d/taishan/fengchan",
		"13":"/d/emei/houshan/jxan",
		"14":"/d/gumu/dating",
		"15":"/d/pker/guangchang",
		"16":"/d/lingzhou/center",
		"17":"/d/huashan/path1",
		"18":"/d/quanzhou/zhongxin",
                "19":"/d/wudang/xiaowu",
               "20":"/d/shaolin/guangchang2",
               "21":"/d/wizard/wizard_room",
               "22":"/d/selfcreate/entrance",
       ]));
        set("objects",([
   "/u/add/wishtree":1,
   ]));
    set("no_clean_up", 0);
        setup();
//  "/clone/board/pal_b"->foo();
        replace_program(ROOM);
}
