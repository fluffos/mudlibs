//Cracked by Roath
// seaboat1.c  海船
// by ALN@XKX

inherit SHIP;

void create()
{
        string argg;
        int num;
  
        set("short", "海船");
        set("long", (: long_desc :));
        set("invalid_startroom", 1);

        set("cost", 5);

        setup();

        if( sscanf(__FILE__, "%s%d", argg, num) == 2 )
        set("exits", ([
                "down" : __DIR__"cabin" + num,
        ]));
}
