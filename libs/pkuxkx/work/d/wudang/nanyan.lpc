// nanyan.c 南岩峰
// by Marz 

inherit ROOM;

void create()
{
	set("short", "南岩峰");
	set("long", 
"这是一条宽大坚实的石阶路，不时地有进香客和游人从你\n"
"的身边走过。抬头北望，雄伟的两仪殿顶浮现在香烟袅绕之中，\n"
"巍峨壮观；东边一条石阶通往山下，隐约可见远处山林蔼蔼，\n"
"赏心悦目。\n"
	);
	set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"wuya",
		"northup" : __DIR__"liangyi",
	]));
	setup();
	replace_program(ROOM);
}

