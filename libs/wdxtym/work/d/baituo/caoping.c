// caoping.c
inherit ROOM;
void create()
{
	set("short","²ÝÆº");
	set("long",
	     "ÕâÀïÊÇÒ»¿é·¼²ÝÆº£¬ÂÌ²ÝÒðÒð£¬ºûµûÂþÎè£¬ÈÃÈË¸Ðµ½ã«Òâ¡£\n"
	     "²»¹ýÅ¼¶ûÒ²»áÅöµ½²Ë»¨Éß¡£\n"
	);
	set("exits", ([
		"west" : __DIR__"shijie",
	]));

	set("objects" , ([
	     "/clone/beast/caihuashe" : random(2),
	]));

	set("resource/snake", ({ "/clone/beast/jinshe",
				 "/clone/beast/dushe", }));

	set("outdoors", "baituo");
	setup();
}
