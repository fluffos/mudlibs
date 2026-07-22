// shanpo.c
// 山坡 

inherit ROOM;
void create()
{
	set("short", "山坡");
	set("long",@long
眼前豁然一亮，原来是九老洞外的一个小山坡。山坡上杂草丛生，风很大，
刮得树枝乱摇。一棵古树下放着几个骷髅，上面都插了五个手指洞，看起来阴
森森的。
long);
	set("exits",([
		"enter" : __DIR__"jiulaodong1",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		CLASS_D("emei") + "/zhou-zhiruo" : 1,
		__DIR__"obj/kuloutou" : 1+random(2),
	]));
	setup();
}
