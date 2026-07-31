
// Room: /u/cloud/dragonhill/sroad.c

inherit ROOM;

void create()
{
        set("short", "黄土路");
        set("long",
"这里是雪亭镇通往绮云镇的必经之路。南面就是绮云镇，北面通往卧龙岗。早先官府想在此\n"
"修条大路连接两镇，无奈地势所限，加上卧龙岗上常有强人出没，只得做罢。虽说是土路，\n"
"可过往的人很多，路面已被踩得很平了。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"shillfoot",
  "southeast" : __DIR__"entrance"
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}
