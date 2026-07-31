// /d/hmy/baizhang.c

inherit ROOM;

void create()
{
        set("short", "百丈泉");
	set("long", @LONG
崖瀑下有一道百余丈长的清泉，说来也怪，东面玉屏瀑上水色流动，弹花
飞溅，而这百丈泉却又是平滑如镜，丝毫没有半点涟漪。
LONG
        );
	set("resource/water", 1);
        set("no_sleep_room",1);

        set("exits", ([ 
	  "eastup" : __DIR__"yupingpu",
	  "south" : __DIR__"qiangu",
]));
        set("objects", ([
                __DIR__"npc/youke": 1,
]));

        set("outdoors", "黑木崖");

        setup();
}
 
