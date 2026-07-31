// huayuan.c

inherit ROOM;

void create()
{
  set ("short", "后花园");
  set ("long", @LONG
后花园中花草甚多，在院子的正中央种着一棵樱花树，每当樱花盛开的时候
片片樱花如雪一样落下刹是好看。花园的墙显得有点矮，弥彦常从这里偷跑
出去玩。
LONG);
set("item_desc",(["qiang":
"一堵矮墙，墙边的草已经被猜的面目全非了．．．\n"
]));
  set("outdoors", "feitian");
set("exits", ([ /* sizeof() == 4 */
"southwest" : __DIR__"chufang",
"northwest" : __DIR__"lianwuchang",
]));
	set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
}

