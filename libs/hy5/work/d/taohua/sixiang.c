// Room: /u/jpei/thd/sixiang.c

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "四象");
	set("long", @LONG
这里是四象层，你一走下来，往上的铁梯就被撤掉了。所谓四象，系指阴
阳变化的四态，亦即太阴、少阳、太阳、少阴，是阴阳互相转化的形式。阴极
中的阴就是太阴，而阴中带阳就是少阳，同样的也有太阳和少阴。四象进一步
演化即是四象生八卦，以方位倒转八卦论，太阳之阳为乾，居正南，太阴之阴
为坤，于正北；少阴之阳为离，居东方，少阳之阴为坎，在西方。四象又对应
五灵中的四兽，而此室居中央，表示五灵中的人统领其余四灵兽。以方位入五
行，此中土之形，尚黄，有一道铁梯直通下方的中央戊己土。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"taiyin",
		"south" : __DIR__"taiyang",
		"west" : __DIR__"shaoyang",
		"east" : __DIR__"shaoyin",
		"down" : __DIR__"tu",
	]) );

	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

int do_save()
{
	write("这里不准存盘！\n");
	return 1;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}

