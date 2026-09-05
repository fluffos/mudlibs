// milin1.c 密林
// seagate@pkuxkx 路径动态更新

inherit "/newbiequest/dynroom";
void refresh_Map();

void create()
{
	set("short", "密林");
	set("long", 
"林中阴森森的，除了几声鸟叫外再没有其他的声音，四周\n"
"都是参天大树，遮天蔽日。脚下是厚厚的落叶，看不出有什么\n"
"人迹，显得格外怕人。\n"
	);
	set("exits", ([
		"south"  : "/d/wudang/houmen",
		"north"  : __DIR__"milin2",
		"west"   : __DIR__"milin1",
		"east"   : __DIR__"milin1",
	]));
  set("outdoors", "wudang");
	set("dynroom/static_exits", ({"south"}));  //如果存在固定方向则配置此属性
	set("dynroom/type",1);                     //1为动态房间，0为固定房间
	set("no_clean_up",1);
	
  refresh_Map();
	setup();
}

void init()
{
	refresh_Map();
}

void reset()
{
	::reset();
	set("no_clean_up",1);
}

void refresh_Map()
{
  if(!query("refreshtime")||(time()-query("refreshtime"))/3600>=24) {
		::init_dynMap(__DIR__, this_object());
		set("refreshtime",time());
	}
}

string get_random_exits(string *exitArray)
{
	string *initExits=({"east","south","north","west","northwest","northeast","southwest","southeast"});
	string *effExits;
	effExits=initExits-exitArray;
	return effExits[random(sizeof(effExits))];
}

string query_dynamic_function()
{
	return "get_random_exits";
}

string query_dynamic_dir()
{
	return __DIR__;
}
