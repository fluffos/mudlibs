// Room: /u/cass/hg/donghuamen.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "东华门");
	set("long", @LONG
门楼上建有4层高的阁楼，上两层为八角形，下两层为四方形，每层
的屋脊、雀替都饰有精致的禽兽泥塑和人物雕刻。
LONG
);

	setup();
	replace_program(ROOM);
}
