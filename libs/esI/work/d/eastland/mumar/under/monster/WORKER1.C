#include <../under.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(12);
        set_name( "worker master", "工兵头" );
        add ("id", ({ "master","worker" }) );
        set_short( "工兵头" );
        set_long( @C_LONG
你眼前是一个身体健壮的工兵头子，他正带领著这儿的工兵施工中。
C_LONG
        );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
    set ("weight", 400);
    wield_weapon(OBJS"pick");
    set( "inquiry",([ "sand":"@@ask_sand",
                      "goldeater":"@@ask_goldeater",
                      "yang":"@@ask_yang" ]));
}
 
int ask_sand()
{    tell_object(this_player(),
@ASK
 
工兵头神色诡异地对你说: 那块沙地有些怪异，那天我和一个工兵值班施工，就当
                        他圆锹插入沙中的那一刹那，我看到一道黑气从土中窜
                        出，把坑道内的光线都遮蔽了，只听到一声惨叫。等到
                        一切都结束後，只看到他受了重伤埋在沙里，同时坑道
                        内所有的工具的金属部份都不翼而飞......我当时也吓
                        坏了，扛起他就往外跑。後来将军就下令改换施工方向
                        了。
工兵头说道：我想那可能真的是只食金兽(goldeater)...现在想起来我还怕...。
ASK
);
}
 
int ask_goldeater()
{    tell_object(this_player(),
@ASK
 
工兵头对你说道: 其实我也不知道什麽食金兽、食银兽的，我也是从我们参军
　　　　　　　　扬大人(yang)口中听到这个名词的......怪吓人的......。
ASK
);
}
 
int ask_yang()
{    tell_object(this_player(),
@ASK
 
工兵头对你说道: 扬大人前天因为逾假(vacation)归营，被关警闭罗......。
 
你心想: 连军官都关，这里的军纪还真严格。
ASK
);
this_player()->set_temp("under",1);
}
