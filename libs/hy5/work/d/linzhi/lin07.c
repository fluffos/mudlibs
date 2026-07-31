// Room: /d/linzhi/lin07.c

inherit ROOM;

void create()
{
	set("short", "桃花沟西口");
	set("long", @LONG
你走到桃花沟西口，再向东去就进了桃花沟。那里长满了天
然的野生桃树，每年八月时，很多人都来这里采摘桃子。据说味
道特别的好。路边一块石壁上好像刻着一些字。
LONG
	);
	set("item_desc",([
          "石壁":"
                  southup      察隅
                  east         通麦
                  west         八一镇 \n", ]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin06",
  "west" : __DIR__"lin08",
  "southup" : __DIR__"lin11",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
