//newmap Zine Nov 11 2010
#include <ansi.h>
inherit ITEM;

void create()
{
  int n;
  string* ownername=({"胡一刀","萧峰","韩员外"});
  string* taskid=({1,2,6});
  n=random(sizeof(ownername));
  set_name( WHT+ownername[n]+"的家信"NOR , ({"letter","xin","jia xin"}));
  set_weight(500);
    set("letterback",taskid[n]);
    set("unit", "张");
    set("value", 0);
    set("long","这是一张"+ownername[n]+"的家信，如果送回去也许好人会有好报。\n");
    set("no_store", 1);
    set("no_sell", 1);
    set("no_pawn",1);
    set("no_put",1);
    set("is_map",1);
    set("correct",0);
  
  setup();
  call_out("dest",900);
}

int dest()
{
    object ob=this_object();
    if (ob)
    {
        destruct(ob);
    }
    return 1;
}

