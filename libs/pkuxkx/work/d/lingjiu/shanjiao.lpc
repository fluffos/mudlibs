inherit ROOM;

void create()
{
	set("short", "缥缈峰山脚");
        set("long",@LONG

向北忘去，有一座山峰，这山峰终年云封雾锁，远远望去，若有若无，因此叫作缥缈峰。
峰顶白云缭绕, 宛若仙境. 白云深处隐约可见琼楼玉宇, 那就是令江湖人物闻名丧胆的
『灵鹫宫』。听说宫中住着一些武艺高强的女侠, 而且只收女弟子为徒。
LONG
        );
        set("outdoors", "lingjiu");
	set("exits", ([
		"south" : __DIR__"shanxiaxiaolu2",
		"northup":__DIR__"ya",
        ]));
   	set("objects",([
//   	__DIR__"npc/jiuyi" : 1,
       	]));
//	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
