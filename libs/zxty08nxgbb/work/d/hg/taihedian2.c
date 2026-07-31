// Room: /u/cass/hg/taihedian2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "太和殿露台广场");
	set("long", @LONG
露台上东设日晷，象征授时；西设嘉量，是全国标准量器。殿前有广场，
中间是用巨石铺就的御道，左右是磨砖对缝的海墁地砖，东西各有仪仗墩石，
御道两旁放置铜制品级山。举行典礼时，大臣们根据身份跪于品级山旁。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"taihedian",
]));

	setup();
	replace_program(ROOM);
}
