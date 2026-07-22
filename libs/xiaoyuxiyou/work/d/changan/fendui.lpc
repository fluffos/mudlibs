// Room: /d/changan/fendui.c
inherit ROOM;
int block_cmd(string);

void create()
{
  set ("short", "荒坟堆");
  set ("long", @LONG

这里是长安城南的一片荒地，周围密密麻麻地堆了好几十个坟头。
有些坟前还有些祭祀，烧纸的痕迹。四处荒凉，很少有人走动，偶
而有几只寻食的野狗跑过。
LONG);
  set("mai_corpse_able", 1);
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"broadway1",
]));
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
    if (verb == "cast") return 1;
    if (verb == "perform") return 1;
    if (verb == "burn") return 1;
    if (verb == "kill") return 1;
    if (verb == "teamkill") return 1;
    if (verb == "ji") return 1;
    return 0;
}

