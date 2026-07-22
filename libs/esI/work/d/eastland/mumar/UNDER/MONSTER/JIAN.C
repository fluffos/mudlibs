#include <../under.h>
inherit MONSTER;
 
void create ()
{
        ::create();
        set_level(17);
        set_name( "Officer Jian", "校尉 江尚青" );
        add ("id", ({ "officer", "jian" }) );
        set_short( "校尉 江尚青" );
        set_long( @C_LONG
 
你面前站著一个满脸通红的高大男子，他原是牧马关骑兵先锋，因为贪杯误事而被
贬为警卫校尉。据说他和李□(lee )是从小在少林练武一起长大的拜把兄弟，虽然
这些年他因酒而损伤许多功力，却也不是盏省油的灯。据说他最爱喝的是精酿玫瑰
红(rose)。
C_LONG
        );
    set( "alignment",2000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "位" );
    set_perm_stat( "dex", 25 );
    set_perm_stat( "str", 22 );
    set_perm_stat( "int", 20 );
    set_perm_stat( "con", 20 );
    set_perm_stat( "pie", 10 );
    set ("max_hp", 500);
    set ("hit_points",500);
    set ("max_fp", 2000);
    set ("force_points",2000);
    set ("wealth", ([ "gold": 50 ]) );
    set_natural_weapon( 40, 40, 60 );
    set_natural_armor( 67, 39 );
    set ("gonfus/drunk_fist",80);
    set ("attack_skill","monk/fist/drunk_fist");
    set ("aim_difficulty", ([ "critical":25, "weakest":25, "ganglion":25,"vascular":25]));
    set ("special_defense", ([ "all":10,"none":10 ]) );
    set ("weight", 400);
    set_skill("unarmed",90);
    set_skill("unarmed-parry",90);
    set ("stun_difficulty",30);
    set("inquiry",([ "lee":"@@ask_lee",
                     "yang":"@@ask_yang",
                     "rose":"@@ask_rose",
                     "rescue":"@@ask_rescue",
                     "visit":"@@ask_visit" ]));
    equip_armor(OBJS"vest");
    equip_armor(OBJS"pants");
}
 
void die()
{   object obj,who,killer;
 
    obj=new(OBJS"mumarkey");
    obj->move(this_object());
    killer = query("last_attacker");
    if( killer ) killer->set_temp("under/killer",1);
    tell_room(environment(this_object()),
@DIE
江尚青的身躯倒下的同时，一串钥匙从他的背心里掉出....
 
DIE
,this_object());
   ::die(1);
}
 
int ask_lee()
{    tell_object(this_player(),
@ASK
 
江尚青说道: 嗯....李□....我跟他可说是从小穿同一条裤子长大的。他这个人
            除了喜欢收集一些奇怪的玩意儿外啊, 最大的毛病就是爱漂亮。上
            次他来巡查地下通道後, 就一直在哀他掉了一个扣子。
ASK
); }
 
int ask_yang()
{
if (this_player()->query_temp("under")==1)
{tell_object(this_player(),
@ASK
 
江尚青说道: 扬心是在牢里面嗯....你问这干啥啊？你是想劫狱(rescue)？
            还是要探监(visit)？
ASK
);} else tell_object(this_player(),
@ASK
 
江尚青说道: 你问这干啥......快滚......
ASK
); }
 
int ask_rose()
{
if (this_player()->query_temp("under")==1)
{tell_object(this_player(),
@ASK
 
江尚青说道: 其实我最爱喝的是帕来的叉叉圈圈......要不是他们说我
            贪杯误事....我才不喝那个没啥味道的鸟玫瑰哩......
ASK
); }
else tell_object(this_player(),
@ASK
 
江尚青说道: 你问这干啥......快滚......这儿不准逗留...
ASK
); }
 
int ask_rescue()
{   if( query_attacker() ) {
    tell_object(this_player(),
@ASK
 
江尚青说道: 哼....这年头找死的人还真不少....想劫狱？下辈子吧!!
ASK
); }
else tell_object(this_player(),
@ASK
 
江尚青说道: 劫狱....嗯....你找死!!
ASK
);
kill_ob(this_player());
}
 
int ask_visit()
{
if ( this_player()->query_temp("jian_wine") > 2)
{ tell_object(this_player(),
@ASK
 
江尚青说道: 探监啊....好吧....
江尚青用不太稳定的手拿出一串钥匙, 开了半天才把门打开把你推了进去,然後又
把门锁上了。
 
ASK
);
this_player()->move_player(UNDER"jail");
tell_object(this_player(),
@ASK
 
江尚青又在门外喊著: 别待太久....想出来时敲敲门(knock gate)就好了...
ASK
); }
else tell_object(this_player(),
@ASK
江尚青说道: 探监啊....带点礼物来吧.........嘿嘿嘿......
ASK
); }
 
int accept_item(object me,object item)
{
        string wine;
        object obj;
        int i;
 
        wine = (string) item->query("name") ;
        if ( wine !="xo" && wine !="Rose wine" ) {
        tell_object(me,
             "江尚青说道: 不要给我垃圾......\n");
        command("give "+(string)item->query("name")+
                " to "+lower_case((string)me->query("name")));
        return 1;
        }
 
        if ( wine =="Rose wine" ) {
        tell_object(me,
             "江尚青说道: 这酒一点劲都没有...不过既然给我了, 我就收著了。\n");
        return 1;
        }
 
        i = this_player()->query_temp("jian_wine");
        if ( i )
                this_player()->set_temp("jian_wine",i+1);
        else
                this_player()->set_temp("jian_wine",1);
        if (i < 2){
                command("drink xo");
                tell_room( environment(),
                "江尚青用手臂擦擦嘴满意地笑道：赞 !! 你还有吗？\n");
        }
        else {
        command("drink xo");
        tell_room( environment(),
        "江尚青醉得趴在桌上，大笑道：真过瘾 !!\n");
        set_skill( "dodge",50 );
        set_perm_stat( "str",10 );
        set_natural_armor( 47, 19 );
        set ("gonfus/drunk_fist",90);
        set_short( "校尉 江尚青[醉酒中]" );
        }
        return 1;
}
