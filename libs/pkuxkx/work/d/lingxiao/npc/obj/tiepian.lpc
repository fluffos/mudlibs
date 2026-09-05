// File         : tiepian.c
// Created By   : iszt@pkuxkx, 2006-09-19

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIB"铁片"NOR, ({"tie pian", "pian"}));
        set_weight(180);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", HIB"黑黝黝的一块铁片，似乎便是江湖中盛传已久的「玄铁令」。\n"NOR);
                set("unit", "片");
                set("value", 100);
                set("no_get", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_steal", 1);
                set("no_pawn", 1);
                set("no_sell", 1);
                set("no_store", 1);
                set("owner", "iszt");             
        }
        setup();
}

void init()
{
        call_out("own", 1, this_player());
}

void own(object ob)
{
        if (ob->query("id") != query("owner"))
                destruct(this_object());
}
