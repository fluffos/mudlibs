// This is a room made by wsl.
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "太白堂");
    set("long", @LONG
闻名遐迩的“诗仙”李白在长安的住所,走进太白堂,“此夜曲中闻折柳，
何人不起故园情”。诗仙的乡情乡恋和乡愁，也那么铭心刻骨。两重檐顶
使太白堂内的一切处于浓重的阴影下，但是两扇大门洞开，前后投进的光
亮。走上太白堂的石阶时，你总感到李白不是坐着，而正潇潇洒洒的诗画
江山。
LONG
    );
    set("exits", ([
         //"south" :__DIR__"ca6",
         "northeast" :__DIR__"ca7",
    ]));
    //create_door("south", "后门", "north", DOOR_CLOSED);
    setup();
    replace_program(ROOM);
}
