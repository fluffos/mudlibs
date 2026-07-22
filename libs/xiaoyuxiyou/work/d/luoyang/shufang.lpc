//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "神侯府书房");
        set ("long", @LONG
这间书房是水舞寒读书所用。屋子布置的精致富丽，当中一张青
玉案，案上两只白玉瓶，瓶里插着几十枝茶花。玉瓶旁铺着几张信筏，
放着些笔墨砚石，还有个斗大的玉钵，想是用来洗笔的。

LONG);

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"shenhoufu",
                "up" : __DIR__"tianji",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuiwuhan" : 1,
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

