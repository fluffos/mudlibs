// zhulin2_config.c 随机迷宫（Virtual Object配置文件）
// seagate@pkuxkx by 2011.02.17

inherit "/newbiequest/dynroom";

mapping virtualSetting=
(["entry":([
	"file":({__DIR__"out"}),
  "virtual":0]),
	"maze":([
	"file":({__DIR__"maze2", __DIR__"maze3", __DIR__"maze4"}),
	"short":({"竹林","竹林","竹林"}),
	"desc":({"这是一个小缓坡，上面种满了密密麻麻的竹子，一片薄雾弥漫在竹林中，似乎周围杀机四伏。\n"}),
	"virtual":1]),
	"out":([
	"file":({__DIR__"cjgqian"}),
	"virtual":0])]);

int init_virtualMap()
{
	create_virtualMap(18,virtualSetting,0,"high");
//加工出地图关系以后，调用清理函数对以前的房间进行清理，防止出现地图混杂情况。
	virtualRoomDestruct(__DIR__"out");
}

void create()
{
  init_virtualMap();
}

int query_dynamic_type()
{
	return 4;
}

