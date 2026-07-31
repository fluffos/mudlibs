// /d/taiyuan/nroad1.c
// Room in 太原
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "多福寺");
	set("long", @LONG
多福寺在太原市西北24公里崛围山之巅.山势陡峻,松柏遍野。
为太原著名风景之一。取自“多子多福”之意。寺在山顶小峪之中
，极富古刹之风趣。寺始建于唐贞元二年(786年)。唐人李克用、
李存勖(后唐庄宗)父子曾到此佛焚香，寺况空前。宋末毁于兵火
，明洪武年间(1368-1398)重建，后又多次重修。唯寺前山巅砖塔
，仍是宋代原构。寺旁小屋，是明末清初思想家傅山读书处。

LONG
        );
set("outdoors", "/d/taiyuan");
set("valid_startroom", 1);
set("exits", ([
///                "southeast" : "/d/luoyang/huanghe_dukou2",
                "north":__DIR__"sroad7", 
	]));
       setup();
	replace_program(ROOM);
}
