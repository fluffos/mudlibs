//jinling  yuhuatai.c
inherit ROOM;

void create()
{
        set("short", "雨花台");
        set("long", @LONG
相传梁武帝时，高僧云光法师在此讲经，感动佛祖，天上落花如雨，后
人即称为雨花台。雨花台孙吴时称石子岗，因这里盛产 色彩斑斓的玛瑙石，
故又称聚宝山、玛瑙岗。只见这里遍地皆是彩色的石头,不愧雨花之名。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"jiangdao1",
           "south" : __DIR__"beijie1",

]));
        set("objects", ([
		__DIR__"npc/obj/stone" : 4,
               __DIR__"npc/wangqier" : 1,

			]) );

//        set("no_clean_up", 0);
//       set("no_death_penalty",1);

        setup();
        replace_program(ROOM);
}
