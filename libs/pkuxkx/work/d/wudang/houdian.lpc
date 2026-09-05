// houdian.c 后殿
// by llin 

inherit ROOM;

void create()
{
	set("short", "后殿");
	set("long", 
"后殿内脏兮兮的，墙角满布蜘蛛网，神像，供桌(zhuo)上\n"
"积着厚厚的一层灰尘，仿佛很久没有人来过了，但供桌边的青\n"
"石地板上却留着几个手印，显得格外醒目。\n"
	);                          	
	set("exits", ([
		"south" : __DIR__"liangyi",
	]));
	set("item_desc" ,([
		"zhuo" : "这是一张又旧又破的供桌，上面满是灰尘；桌下面黑乎乎的不知有什么东西。\n",
	]));
	setup();
	replace_program(ROOM);
}

