#pragma save_binary
// Room: /d/green/fort2.c

inherit ROOM;

void create()
{
	set("coor",({320,4860,25}));
	set("short", "野羊山寨");
	set("long",
"这是野羊山的山寨，有三三两两腰挂钢刀的人在走来走去。左边\n"
"是山寨的武器库又边是山寨的粮草库，北方是密密的帐篷。\n"
);
	set("exits", ([ /* sizeof() == 2 */
    "west": __DIR__"wstorage",
  "south" : __DIR__"fort1",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/toumu4" : 1,
  __DIR__"npc/blader" : 1,
]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "west"
&& (objectp(present("lou luo", environment(me)))
          ||objectp(present("toumu", environment(me))))) 
     return                    notify_fail("喽罗喊道：想进去，没那么容易!\n");
        return ::valid_leave(me, dir);
}

