// chengyaojia.c 程瑶迦

#include <ansi.h>
inherit NPC;
#include "/u/tod/mi.h"

string ask_cancel(object me);

void create()
{
        set_name("程瑶迦", ({"cheng yaojia", "cheng", "yaojia"}));
        set("title",HIW "归云庄少奶奶" NOR);
        set("gender", "女性");
        set("age", 19);
        set("long", 
        "这是名十八九岁左右的锦衣少妇，服饰华丽，神情很是腼腆。\n"

        );

        set("attitude", "friendly");

        set("str", 20);
        set("int", 23);
        set("con", 20);
        set("dex", 25);
        set("per", 30);

        set("qi", 1300);
        set("max_qi", 1300);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 2300);
        set("max_neili", 2300);
        set("jingli", 1500);
        set("max_jingli", 1500);
        set("jiali", 100);

        set("combat_exp", 300000);      

        set("inquiry", ([
                 "miyu" : (: ask_cancel :),
                "谜语" : (: ask_cancel :),
        ]) );

string ask_cancel(object me)
{
        me = this_player();
                 mi(me);

                return "快猜，快呀！";
 }

