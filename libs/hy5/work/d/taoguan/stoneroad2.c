#include <room.h>
inherit ROOM; 
void create()
{
    seteuid(getuid());
        set("short", "青石小径");
        set("long", @LONG
绕过了後殿, 出现在眼前的是一栋木造两层高的屋子。屋子四周
的门窗都紧紧的关著, 门口上方挂著一方蓝色琉璃匾额, 上书『藏经
楼』三个金字。门旁立著一个石碑(slab)。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "southeast" : __DIR__"stoneroad",
            "north" : __DIR__"book_room1",
]));  
        set("outdoors", "taoguan");
        set("item_desc", ([
            "slab" : "石碑上写著 : \n\n"
                     "    非\n"
                     "    三  不\n"
                     "    清  得\n"
                     "    弟  进\n"
                     "    子  入\n\n"
           ]) ); 
    set("coor/x",-40);
        set("coor/y",2130);
        set("coor/z",80);
        setup(); 
    reset();
}    
