// 妓院老板 /d/city/chuzhou/npc/whorehouseboss.c
// by lala, 1997-12-17

#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "薛巧莲", ({ "xue xiaolian", "xue", "boss", }) );
    set( "title", MAG"弄玉坊"YEL"老板"NOR );
    set( "gender", "女性" );
    set( "age", 38 );
    set( "long", @LONG
这个女人打扮得花枝招展，但是还是能看出有些老了。她是这家妓院的老板。据
说她这儿的姑娘原本有不少都是良家女孩子，被拐卖到这里来的。
LONG
    );
    set( "attitude", "friendly" );
    set( "talk_msg",({
    }));
    set("qi",400);
    set("max_qi",400);
    set("eff_kee",400);
    set("sen",400);
    set("max_sen",400);
    set("eff_sen",400);
    set("max_force", 600);
    set("force",     600);
    set("force_factor", 20);
    set("combat_exp", 500000);
    set("social_exp", 500000);
    set("positive_score", 200);
    set("negative_score", 3000);

 
    setup();
      
    carry_object( "/clone/misc/cloth")->wear();
}          



