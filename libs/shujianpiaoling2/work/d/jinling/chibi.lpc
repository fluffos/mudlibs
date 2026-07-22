
inherit ROOM;

void create()
{
        set("short", "赤壁山");
        set("long", @LONG
赤壁古名石头关，遗留有古战场的累累痕迹。这里山势雄伟，
斜亘百丈，突入长江，激浪飞溅，高达丈余，气势磅礴。南屏山上
的拜风台，传说是诸葛亮借东风之处。凤雏庵则是赤壁之战献连环
计的庞统隐居之地。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"chibizhai",
	"southwest" : __DIR__"jiangdao6",
]));
        set("outdoors", "jinling");

        setup();
        replace_program(ROOM);
}
