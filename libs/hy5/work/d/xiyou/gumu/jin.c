// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short", "剑冢");
 set("long", @LONG
传说这里是远古的战场，地上插着许多刀剑，据说这些刀剑
背负着主人的怨恨和凄凉，到处是死人的骸骨，一种阴魂不
散的感觉......
LONG
 );
 set("exits", ([
  "south" : __DIR__"huo",
  "north" : __DIR__"tu",
  "east" : __DIR__"shui",
  "west" : __DIR__"mu",
]));

 set("coor/x",10);
 set("coor/y",-620);
 set("coor/z",-20);
 setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(10) + 1, ob);
 add_action("do_chop","chop");
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
 {
 tell_object(this_object(), HIW "\n\n一柄锈剑突然飞起，冲着你就刺了过来！！\n\n" NOR);
 COMBAT_D->report_status(ob,1);
 ob->receive_wound("kee", random(20)+10);
 if( environment(ob) == this_object())
 call_out("blowing",random(10)+1, ob);
 }
 else
 return 1;
}
void reset()
{
 ::reset();
        remove_call_out("blowing");
        delete("exits/east");
}
int valid_leave(object me, string dir)
{
        remove_call_out("blowing");
 return 1;
}



