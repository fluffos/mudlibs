// poemgirl.c

inherit BHNPC;

#include <ansi.h>

int send_back(object me);

void create()
{
          set_name(HIW"ÏÉ¹Ã"NOR, ({ "xian gu", "gu",}) );
         set("gender", "Å®ÐÔ" );
        set("age", 152);

        set("combat_exp", 2000000);
        set("attitude", "friendly");
        set_skill("literate", 300);
        set_skill("dodge", 140);
        setup();
     this_player()->carry_object("/clone/misc/cloth")->wear();

}

