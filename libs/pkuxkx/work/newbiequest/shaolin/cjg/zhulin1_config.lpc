// zhulin1_config.c 矩阵迷宫（Virtual Object配置文件）
// seagate@pkuxkx by 2011.02.16

inherit "/newbiequest/dynroom";

mapping virtualSetting=
(["entry":([
	"file":__DIR__"entry"]),
	"maze":([
	"file":({__DIR__"maze"}),
	"short":({"竹林"}),
	"desc":({"这是一个小缓坡，上面种满了密密麻麻的竹子，一片薄雾弥漫在竹林中，似乎周围杀机四伏。\n"}),
	"virtual":1]),
	"out":([
	"file":__DIR__"out"])]);

int init_virtualMap()
{
	create_StandardVirtualMap(10, 9, virtualSetting);
//加工出地图关系以后，调用清理函数对以前的房间进行清理，防止出现地图混杂情况。
	virtualRoomDestruct(__DIR__"entry");
}

void create()
{
  init_virtualMap();
}

int query_dynamic_type()
{
	return 4;
}