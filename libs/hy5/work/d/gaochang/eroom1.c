
inherit ROOM;




void create()
{
	set("short", "东大殿");
	set("long", @LONG
每一间房中大都供有佛像。偶然在壁上见到几个汉文，
写的是「高昌国国王」，「文泰」，「大唐贞观十三年」等等字样。有一座
殿堂中供的都是汉人塑像，匾上写的是「大成至圣先师孔子位」，左右各有数
十人，写著「颜回」、「子路」、「子贡」、「子夏」、「子张」等名字。
LONG
	);

	set("exits", ([	
		"north" : __DIR__"eroom2",
		"west"  : __DIR__"dadian",
//	]));

//	set("objects",([
//		CLASS_D("shaolin") + "/cheng-guan" : 1,
	]));
	setup();
	replace_program(ROOM);
}



