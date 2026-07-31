// Room: /d/linzhi/lin05.c

inherit ROOM;

void create()
{
	set("short", "桃花沟东口");
	set("long", @LONG
你走到桃花沟东口，再向西去就进了桃花沟。那里长满了天
然的野生桃树，每年八月时，很多人都来这里采摘桃子。据说味
道特别的好。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lin04",
  "west" : __DIR__"lin06",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
