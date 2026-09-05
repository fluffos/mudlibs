//File: /d/wizard/wizard_room_zoom.c
//Use for:  zoom's workroom
//Created By zoom 2004.3.15 PM
//Modified By zoom 2004.3.16 AM
 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "密室");
        set("long",
HIW"★"HIY"常用出口。\n"
HIW"
01.暗器门 02.白驼 03.北京 04.冰火岛 05.丐帮 06.大理\n
07.钓鱼岛 08.峨嵋 09.归云庄 10.古墓 11.华山 12.风清扬\n
13.灵鹫   14.灵州 15.明教   16.慕容 17.平西 18.杀手帮\n
19.全真   20.泉州 21.日月教 22.少林 23.苏州 24.泰山\n
25.桃花岛 26.武当 27.侠客岛 28.襄阳 29.星宿\n   "NOR);
       set("exits", ([
		"aqm":"/d/anqimen/zaixiang",
		"bt":"/d/baituo/dongjie",
		"bj":"/d/beijing/changanjie",
		"bhd":"/d/bhdao/shidong",
		"gb":"/d/city/gbxiaowu",
		"dl":"/d/dali/dadian",
		"dyd":"/d/diaoyudao/zhangqian",
		"em":"/d/emei/houshan/jxan",
		"gy":"/d/guiyunzhuang/guiyunting",
		"gm":"/d/gumu/dating",
		"hs":"/d/huashan/shufang",
		"feng":"/d/huashan/feng",
		"lj":"/d/lingjiu/xiaowu",
		"lz":"/d/lingzhou/center",
		"mj":"/d/mingjiao/dadian",
		"mr":"/d/murong/yketing",
		"px":"/d/pingxiwangfu/dadao1",
		"pk":"/d/pker/guangchang",
		"qz":"/d/quanzhen/xuanzt",
		"quan":"/d/quanzhou/zhongxin",
		"ry":"/d/riyuejiao/dadian1",
		"sl":"/d/shaolin/fzlou",
		"sz":"/d/suzhou/nandajie1",
		"ts":"/d/taishan/fengchan",
		"thd":"/d/taohuadao/dating",
                "wudang":"/d/wudang2/houtang",
		"xkd":"/d/xiakedao/shishi1",
		"xy":"/d/xiangyang/xycenter",
		"xx":"/d/xingxiu/xxh2",
                "out":"/d/wizard/wizard_room_zoom",
       ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if (!wizardp(me))
        {
		return notify_fail("你往前一走，却发现有无形的力场锁着你，出不去！:(\n");
        }
return ::valid_leave(me, dir);
} 
