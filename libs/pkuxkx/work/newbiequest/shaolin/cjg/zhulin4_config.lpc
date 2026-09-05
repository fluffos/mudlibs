// zhulin2_config.c 随机迷宫（Virtual Object配置文件）
// seagate@pkuxkx by 2011.02.17

inherit "/newbiequest/dynroom";

mapping virtualSetting=
(["entry":([
	"file":({__DIR__"out_s"}),
  "virtual":0]),
	"maze":([
	"file":({__DIR__"maze2_s", __DIR__"maze3_s", __DIR__"maze4_s"}),
	"short":({"竹林","竹林","竹林","竹林小径","竹林缓坡","竹林小路","竹林空地"}),
	"desc":({"这是一个小缓坡，上面种满了密密麻麻的竹子，一片薄雾弥漫在竹林中，似乎周围杀机四伏。\n"}),
	"virtual":1]),
	"out":([
	"file":({__DIR__"cjgqian_s"}),
	"virtual":0])]);

int init_virtualMap()
{
	create_virtualMap(12,virtualSetting,0,"middle");
//	debug_virtualMap(1);
//加工出地图关系以后，调用清理函数对以前的房间进行清理，防止出现地图混杂情况。
	virtualRoomDestruct(__DIR__"out_s");
}

void create()
{
  init_virtualMap();
}

int query_dynamic_type()
{
	return 4;
}

