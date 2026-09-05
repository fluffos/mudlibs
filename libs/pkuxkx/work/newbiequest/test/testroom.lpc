inherit "/newbiequest/dynroom";

mapping virtualSetting=
(["entry":([
	"file":({__DIR__"entry"}),
	"short":({"迷宫入口"}),
	"desc":({"前面有一片迷雾，请小心！\n"}),
	"virtual":1]),
	"maze":([
	"file":({__DIR__"maze"}),
	"short":({"迷宫"}),
	"desc":({"四周一片迷雾。\n"}),
	"virtual":1]),
	"out":([
	"file":({__DIR__"entry"}),
	"short":({"迷宫出口"}),
	"desc":({"后面有一片迷雾，请小心！\n"}),
	"virtual":1])]);

int init_virtualMap()
{
	object ob;
	create_virtualMap(20,virtualSetting,0);
	create_virtualMap(20,virtualSetting,1);
	create_virtualMap(20,virtualSetting,2);
	create_virtualMap(20,virtualSetting,3);
	create_virtualMap(20,virtualSetting,4);
	create_virtualMap(20,virtualSetting,5);
//加工出地图关系以后，调用清理函数对以前的房间进行清理，防止出现地图混杂情况。
	virtualRoomDestruct();
//	debug_virtualMap(1);
}

void create()
{
  init_virtualMap();
}

int query_dynamic_type()
{
	return 4;
}

