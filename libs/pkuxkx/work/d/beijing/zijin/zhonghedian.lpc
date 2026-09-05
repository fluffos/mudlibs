#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"中和殿"NOR);
	set("long",
HIC"这里又称华盖殿，中极殿，是正方形殿。皇帝在太和殿举办大典
前，一般在此准备。另外，每十年一次的进呈玉碟（皇帝的家谱）
仪式也在此进行。大殿呈方形，单檐黄琉璃瓦四角攒尖，鎏金宝顶
。内檐绘着金龙吉祥彩画和团龙图案。殿内也设有宝座，旁边还摆
着金鼎、熏炉。\n"NOR
	);

	set("exits", ([
		"north" : __DIR__"baohedian",
		"south" : __DIR__"taihedian",
        	"west"  : __DIR__"xiaodao1",
        	"east"  : __DIR__"xiaodao2",
	]));

	setup();
	replace_program(ROOM);
}
