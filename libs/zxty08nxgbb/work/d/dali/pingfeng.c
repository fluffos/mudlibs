inherit ROOM;
void create()
{
        set("short", "翠玉屏风");
        set("long", @LONG
翠玉屏风上狂劲草书：
物华交泰，斗柄回寅。草芽遍地绿，柳眼满堤青。一岭桃花红锦婉，半溪烟水碧罗
明。几多风雨，无限心情。日晒花心艳，燕衔苔蕊轻。山色王维画浓淡，鸟声季子舌纵
横。芳菲铺绣无人赏，蝶舞蜂歌却有情。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"mingyu",
  "south" : __DIR__"garden",
]));

        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/beggar" : 1,
]));

        setup();
}
