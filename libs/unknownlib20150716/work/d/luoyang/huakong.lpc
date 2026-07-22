//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "花空烟水流");
        set ("long", @LONG
屋子很大，这么大的屋子，只有一个窗户，很小的窗户，离地很
高。窗户是关着的，看不到外面的景色。门也很小，肩稍宽的人，就
只能侧身而入。墙上漆着白色的漆，漆得很厚，仿佛不愿人看出这墙
是石壁，是土，还是铜铁所筑。角落里有两张床，木床。床上的被褥
很干净，却很简朴。

LONG);

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"congming2",
                "up" : __DIR__"jinyi",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/difenghou" : 1,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
  	set("no_fight", 1);
  	set("no_magic", 1);
        setup();
}
void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    if (verb == "bid") return 1;
    return 0;
}

