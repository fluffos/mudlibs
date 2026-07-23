// /d/taiyuan/nroad1.c
// Room in 太原
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "纯阳宫");
	set("long", @LONG
纯阳宫始建于宋代末年，原是为供奉道教“神仙”吕洞宾而修建的，所以又叫吕祖
庙，明清时增修扩建而成现在的规模。纯阳宫是一座集庙宇、园林风格为一体的
五进院落，院内亭台楼阁样样皆有。门前有四柱三楼木牌坊，其造型、色彩均独
具特色，惹人注目。吕祖殿是纯阳宫的主殿，位于院落中央，面阔三间，方方正
正，是宫内最壮观的建筑。殿后的那座院落建筑格局颇为独特，据说是按八卦的
方位而建，具有鲜明的道教建筑特色，也是整个纯阳宫的精华所在。 
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "west":__DIR__"sroad1", 
                "southeast":__DIR__"sroad3", 
                
	]));
       setup();
	replace_program(ROOM);
}
