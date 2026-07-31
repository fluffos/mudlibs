// Room: /city/wumiao.c
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "ÎäÃí");
    set("long", @LONG
ÕâÀïÊÇÔÀÍõÃíµÄÕıµî£¬ÄÚÓĞÔÀ·ÉÏñ£¬ÏñÉÏ·½Ğü¹ÒÔÀ·ÉÊÖÊé¡°»¹ÎÒºÓÉ½¡±µÄ
ºáØÒ¡£µîÁ½²à±ÚÉÏÇ¶×Å¡°¾¡ÖÒ±¨¹ú¡±ËÄ¸ö´ó×Ö¡£ÎäÈËµ½´Ë£¬¶¼·ÅÏÂÎäÆ÷£¬±Ï¹§
±Ï¾´µØÉÏÏãÀñ°İ¡£ÅÔ±ßËÆºõÓĞÒ»µÀ²àÃÅ¡£

                           [1;31mÔÀÍõÃí[2;37;0m

LONG
    );
    set("no_fight", "1");
    set("no_steal", "1");
    set("no_sleep_room", "1");
        set("valid_startroom","1");
    set("objects", ([
        __DIR__"obj/box" : 1,
                __DIR__"npc/bigeye" : 1,
          "/d/daniel/saveme" : 1,
    ]));
    set("exits", ([
        "east" : __DIR__"beidajie2",
        "northwest": "/d/wizard/guest_room",
       "north":"/d/city/shijian",
     "south":"/d/zjb/shengjiroom",
    ]));
        create_door("northwest", "ÖñÃÅ", "southeast", DOOR_CLOSED);
        setup();
      "/clone/board/wiz2_b"->foo();
}
void init()
{
    if (!wizardp(this_user()))
add_action("discmds",({"duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","xi","hit","perform","prcatice","scribe","surrender","get"}));
}
int discmds()
{
    tell_object(this_player(),"´óµ¨£¡ÔÚÉñÏñÃæÇ°Ò²¸ÒºúÀ´£¿£¡\n");
    return 1;
}
