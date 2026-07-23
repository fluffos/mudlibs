

inherit ROOM;


void create()
{
	set("short", "慈云寺");
	set("long", @LONG
慈云寺，濒临长江。寺门左侧卧一石刻青狮，与长江对岸的
白象街遥遥相望，素来有“青狮白象锁大江”之说。寺始建于唐代
，重修于清乾隆年间，原为观音庙。 寺内的主要建筑有大雄宝殿
、普贤殿、三圣殿、韦驮殿、藏经楼、钟鼓楼等。慈云寺所藏文
物玉佛、金刚幢、千佛衣、藏经、菩提树等并称五绝。
LONG
	);
	
	set("exits", ([
                "west" : __DIR__"eroad",
                "southeast" : __DIR__"eroad2",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
