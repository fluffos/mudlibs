// Npc : xiaojie.c  小姐
// hydra

#include <ansi.h>
inherit NPC;

int ask_me( object );

void create()
{
    set_name( "小姐", ({ "xiao jie", "xiaojie" }) );
    set( "title","张府" );
    set( "attribute", "friendly" );
    set( "gender", "女性" );
    set( "age", 18 );
    set( "long", @LONG
张家小姐琴棋书画样样精通，再加上长的国色天香，在兰州城里非常有名。
LONG
    );
    
    set( "per",35 );
    set( "int",34 );
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
    
    set( "inquiry",([
        "躲避"      :   (: ask_me :),
        "躲藏"      :   (: ask_me :),
    ]) );
        
    setup();
    carry_object( "/clone/misc/cloth" )->wear();

}

int ask_me( object ppl )
{
    object env,*ob;
    int i,time,flag=0;
    ppl = this_player();

    
    env = environment(ppl);
    if ( env->query("short") != "阁楼" )
    {
        tell_object(ppl,CYN"小姐道：这件事情还是等我回了阁楼再说吧。"
            "这里人多眼杂，别走漏了风声。\n"NOR);
         return 0;
    }
    


    

        tell_object(ppl,CYN"小姐行了个礼，道：那一切仰仗大师了。\n"
            "说罢，带了盈盈下楼而去。"NOR);
        ppl->set_temp("凉州/can_lie",1);
        call_out("hide_me",1);
        return 1;
 
}

void hide_me()
{
    destruct( this_object() );
}
