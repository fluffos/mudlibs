// Created by zhx,2009.8.29

#include <ansi.h>

void setshort()
{
    this_object()->set("short", CYN"山路"NOR);
}

void setlong()
{
    this_object()->set("long", CYN @LONG
这里是岛上的山路。
    这里终年云雾缭绕，不见日月。如果你不是这的居民，
很难分出东西南北，更可怕的是，这里不时有野兽和倭寇
出没。这些畜牲，可不管你是干啥的，一律格杀。
LONG NOR);
   this_object()->set("no_die", 1);
}


void setobject()
{
    
    this_object()->set("objects", ([
    __DIR__"npc/wokou" : random(3),
              ]));
}
