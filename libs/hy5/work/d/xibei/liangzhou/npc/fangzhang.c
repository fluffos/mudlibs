// Npc : fangzhang.c
// hydra

#include <ansi.h>
inherit NPC;

void create()
{
    seteuid(getuid());
    set_name( "妙庆", ({ "fang zhang", "monk" }) );
    set("title","大云寺方丈");
    set( "attribute", "friendly" );
    set( "gender", "男性" );
    set( "age", 50 );
    set( "long", @LONG
这位是大云寺的方丈，正一付愁眉苦脸的样子。
LONG
    );
    
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
    


        
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}

void init()
{
    object me;
    me = this_player();
    call_out( "greeting",3,me );
    add_action( "do_nod","nod");
}

void greeting( object me )
{
    if( random(3)==0 )
    {
        if(!me->query_temp("凉州/wait_nod"))
        {
            if ( environment(me) != environment() )  return;
            tell_object( me,CYN"老方丈见你到来，悄悄地跟你说道：“这位大师，能否帮贫僧一个忙？”\n"NOR);
            tell_object( me,CYN"如果愿意的话，就点个头。\n"NOR);
            me -> set_temp("凉州/wait_nod",1);
        }
    }
    else
    {
        if( userp(me) )
            command( "say 阿弥陀佛。。。。");
    }
}
    
int do_nod( string arg )
{
    object me;
    string msg;
    me = this_player();
    if(!me->query_temp("凉州/wait_nod") || me->query_temp("凉州/have_noded") ) return 0;
    if( arg ) return 0;
    msg = "老方丈“哎。。。”了一一声，叹了一口气，道：前几天不知道从什么地方来了几个\n";
    msg += "恶人，来到了凉州，凭借着有一点手脚，在凉州城里胡作非为，欺负百姓。。。\n";
    msg += "前天，又看上了隔壁张家的小姐，说要今晚。。。哎。。。\n";
    msg += "张家老施主知我会一点功夫，想让我去帮忙把他们赶走，可是。。。哎。。。贫僧曾\n";
    msg += "跟他们交过手，实在不是他们的对手。\n";
    msg += "我看大师身怀绝艺，是否愿意帮贫僧这个忙，解救凉州百姓于水火，贫僧这相有礼了。\n";
    msg += "你跟张府的人说是“我妙庆方丈介绍来的”，他们会相信你的。\n";
    tell_object( me,msg );
    me -> set_temp("凉州/have_noded",1);
    return 0;
}
