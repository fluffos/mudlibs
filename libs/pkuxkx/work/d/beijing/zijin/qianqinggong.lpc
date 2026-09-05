// Room: /d/beijing/zijin/qianqinggong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"乾清宫"NOR);
	set("long",
HIC"这是皇帝的寝宫，皇后在此居住，其他妃嫔可以按照皇帝的召唤
进御，后来皇帝也有时在此召见臣工，临朝听政，引见庶僚，接见外
国使臣以及读书学习披阅奏章等。
在宫门的正上方悬挂着一块大匾(bian)。临窗大坑上铺着猩红洋毯，
正面设着大红金钱蟒靠背，石青金钱蟒引枕，秋香色金钱蟒大条褥，
坑的两边设一对梅花式洋漆小几。左边几上文王鼎匙箸香盒，右边
几上汝窟美人觚----觚内插着时鲜花卉。地下面西一排四张椅上，
都搭着银红撒花椅搭，底下四副脚踏，椅的两边，也有一对高几，几
上茗碗瓶花俱香。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"yard1",
  	"north" : __DIR__"jiaotaidian",
  	"westdown" : __DIR__"maoqindian",
  	"eastdown" : __DIR__"yuchafang",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "bian" : "匾上写着「正大光明」四个大字。清朝皇帝将继承人的
名字密写两份，一份带在身边，一份封在建储匣内，放到
乾清宫「正大光明」匾的后面，皇帝死后由顾命大臣共同
打开身边密藏的一份和建储匣，会同廷臣宣布即位皇子。
",
]));

	setup();
	replace_program(ROOM);
}
