#include <../under.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(10);
        set_name( "Staffer Yang", "参军 扬心" );
        add ("id", ({ "staffer", "yang" }) );
        set_short( "参军 扬心" );
        set_long( @C_LONG
 
你面前是一个身材矮小的囚犯，不过看来是一张书生般秀气的脸。据说参军是牧马
关的次席军师，只是想不到如此的军官也会在这里警闭。他现在正闭目沉思，似乎
对你的来临毫不理会。
C_LONG
        );
    set( "alignment",2000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "位" );
    set_perm_stat( "dex", 25 );
    set_perm_stat( "int", 30 );
    set_perm_stat( "con", 20 );
    set_perm_stat( "pie", 10 );
    set_natural_weapon( 20, 20, 30 );
    set_natural_armor( 30, 30 );
    set ("aim_difficulty", ([ "critical":25, "weakest":25, "ganglion":25,"vascular":25]));
    set ("special_defense", ([ "all":20,"none":20 ]) );
    set ("weight", 400);
    set_skill("dodge",50);
    set("inquiry",([ "goldeater":"@@ask_goldeater",
                     "vacation":"@@ask_vacation" ]));
}
 
int ask_goldeater()
{
if ( this_player()->query_temp("under") >=1 ) {
tell_object(this_player(),
@ASK
 
扬心说道: 这食金兽也只是我依工兵头所说而下的推断。不过，我小时听说
　　　　　食金兽是只圣兽。现在北蛮对牧马关虎视眈眈，食金兽出现在牧
          马关也许是件好事。不过为了预防万一，我还是准备了一些必要
          的法器放在我房里，以免那食金兽再伤人。
ASK );
this_player()->set_temp("under",2);
}
else tell_object(this_player(),
@ASK
 
扬心连头都不抬起来，理都不理你。
ASK);
}
int ask_vacation()
{
if ( this_player()->query_temp("under") >=1 ) {
tell_object(this_player(),
@ASK
 
扬心说道: 唉......那天要不是我在城门口被一个奇怪的道士拦住，也不会弄到
          逾假归营，不过关在这倒也清闲，可以让我多多思考。
ASK );
}
else tell_object(this_player(),
@ASK
 
扬心连头都不抬起来，理都不理你。
ASK
); }
