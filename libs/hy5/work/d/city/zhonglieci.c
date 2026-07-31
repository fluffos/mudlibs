// /d/city/zhonglieci.c  忠烈祠
//modified by sega 1/10/99
//修改a_time为120,并添加newjob的一些信息,以防一些人一直flood
//修改a_time为300，一些老玩家建议我们延长这个时间。
//修改了2次保镖间隔为5分钟
#include <ansi.h>
inherit ROOM;
// 下列地址所在房间必须有outdoors 

void create()
{
	set("short", "忠烈祠");
	set("long", @LONG
这里扬州忠烈祠，是大清鹿鼎公韦小宝奉清圣祖康熙圣谕所筑，供
奉的却是大明尽忠报国、忠君爱民的扬州督师史阁部史可法。堂上牌匾
是康熙御笔“敕建扬州忠烈祠”。匾下史公神像历久年深，像上的颜色
已经斑驳脱离了。四周的地上积了一些尘土，看来象是已经有些时候没
有人来过的痕迹。像前摆放着一张红木高脚供桌，桌上高处，放着一个
神龛(kan)。
LONG    );
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"north" : __DIR__"zizheng",
	]));

	set("count",1);
	set("item_desc", ([
		"kan" :  HIG"
与周遭一比较，你发现这个神龛一尘不染，干净得奇怪，好象常有人打开似的。\n
"NOR
	]));
	set("coor/x", -30);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}

