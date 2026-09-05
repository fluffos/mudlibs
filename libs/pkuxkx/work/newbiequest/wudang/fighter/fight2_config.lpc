inherit "/newbiequest/dynroom";

mapping virtualSetting=
(["entry":([
	"file":({__DIR__"entry"}),
	"virtual":0]),
	"maze":([
	"file":({__DIR__"maze",__DIR__"maze2"}),
	"short":({"小树林","小树林","小树林","小树林","小树林","树丛","榕树下","密林"}),
	"desc":({"稀稀落落得长着南方常见的榕树、杨树和柳树，茂盛的茅草大概有一个人多高，\n四周似乎危机起伏，需要小心了。\n"}),
	"virtual":1]),
	"out":([
	"file":({"/d/wudang/tufeicun"}),
	"virtual":0])]);

int init_virtualMap()
{
	create_virtualMap(8,virtualSetting,0,"middle");
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

