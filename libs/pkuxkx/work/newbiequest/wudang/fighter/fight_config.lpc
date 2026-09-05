inherit "/newbiequest/dynroom";

mapping virtualSetting=
(["entry":([
	"file":({"/d/wudang/xiaolu"}),
	"virtual":0]),
	"maze":([
	"file":({__DIR__"maze",__DIR__"maze2"}),
	"short":({"小树林","小树林","小树林","小树林","小树林","树丛","榕树下","密林"}),
	"desc":({"稀稀落落得长着南方常见的榕树、杨树和柳树，茂盛的茅草大概有一个人多高，\n四周似乎危机起伏，需要小心了。\n"}),
	"virtual":1]),
	"out":([
	"file":({__DIR__"entry"}),
	"virtual":0])]);

int init_virtualMap()
{
	object ob;

	create_virtualMap(12,virtualSetting,0,"low");
//加工出地图关系以后，调用清理函数对以前的房间进行清理，防止出现地图混杂情况。
	virtualRoomDestruct("/d/wudang/xiaolu");
}

void create()
{
  init_virtualMap();
}

int query_dynamic_type()
{
	return 4;
}

