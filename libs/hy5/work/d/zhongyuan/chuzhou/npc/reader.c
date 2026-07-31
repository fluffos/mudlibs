// 楚州买书的顾客 /d/city/chuzhou/npc/reader.c
// by lala, 1997-12-13

inherit NPC;

void create()
{
    set_name( "书生", ({ "shu sheng", "reader" }) );
    set( "gender", "男性" );
    set( "age", 25 );
    set( "long", "这是个年轻的书生，经常到七瑞书屋来读书，就是不买。\n" );        

    set("combat_exp",6000);
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);

    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}

int query_answer()
{
    command( "say “啊呀，这个么，因为来的比较急，还没有准备好说什么呢，等两天再说！”" );
    return 1;
}    

