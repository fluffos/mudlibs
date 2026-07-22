#include <../under.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(9);
        set_name( "wounded soldier", "伤兵" );
        add ("id", ({ "soldier", }) );
        set_short( "伤兵" );
        set_long( @C_LONG
你眼前是一个受了重伤的工兵，全身包著绷带，只有眼睛和嘴露在外面。不过在这
个没有战事的时候，你实在想不到他怎麽能弄到这麽严重的伤(hurt)。
C_LONG
        );
    set( "gender", "male" );
    set( "max_hp",120);
    set( "hit_points",10);
    set( "race", "human" );
    set( "unit", "个" );
    set( "weight", 400);
    set( "chat_chance", 5 );
    set( "chat_output", ({ "伤兵微微地移动身躯，同时低声地呻吟著：痛～\n" }) );
    set( "inquiry",([ "hurt":"@@ask_hurt",
                      "sand":"@@ask_sand" ]));
}
 
int ask_hurt()
{    tell_object(this_player(),
@ASK
 
伤兵微弱地对你说道: 唉....我也不知道是怎麽回事，当我拿著我的圆锹在工作
                    时，不知是什麽力量拉著我的圆锹把我扯入沙(sand)中..
                    当我醒来时，就躺在这里了。当时除了我外，只有工兵头
                    在场，我除了知道是工兵头救我外，真的什麽都不知道。
ASK
);
}
 
int ask_sand()
{    tell_object(this_player(),
@ASK
 
伤兵似乎受到了极大的惊吓，口吐白□，喃喃自语著: 我不知道...我不知道...
ASK
);
}
