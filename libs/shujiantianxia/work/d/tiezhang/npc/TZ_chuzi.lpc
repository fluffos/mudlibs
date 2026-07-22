//Write by Yanyang@SJ  2001.2.20
//TZ_chuzi.c
inherit NPC;
#include <ansi.h>
string ask_food();

void create()
{
       set_name("厨子", ({ "chu zi", "chuzi", }) );
       set("gender", "男性" );
       set("age", 46);
       set("long", "他是铁掌帮高薪聘来的厨子，长得肥头大耳，白白胖胖。\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");

       set("inquiry", ([
             "食物" : (: ask_food :),
             "food" : (: ask_food :),
       ]) );

       setup();
       carry_object(ARMOR_D("cloth"))->wear(); 
}

string ask_food()
{                    
        object me,food;
        mapping fam;
        me=this_player();

        if (mapp(fam = me->query("family")) && fam["family_name"] != "铁掌帮" ) return "这位" + RANK_D->query_respect(me) + "肚子饿了吗？可惜铁掌帮的伙食暂时不用来招待外客！";

        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "这位" + RANK_D->query_respect(me) + "都打着饱嗝了！怎么还要？";
        if ( present("mi fan", this_player()))
                return "这位" + RANK_D->query_respect(me) + "身上不是还有嘛，先吃了再说吧！";
        if ( present("ruzhu", this_player()))
                return "这位" + RANK_D->query_respect(me) + "身上不是还有嘛，先吃了再说吧！";
        if ( present("hongshao niurou", this_player()))
                return "这位" + RANK_D->query_respect(me) + "身上不是还有嘛，先吃了再说吧！";
        if ( present("mi fan",  environment(me)) )
                return "那不是有吗？先吃了再说，别浪费了！";              
        if ( present("ruzhu",  environment(me)) )
                return "那不是有吗？先吃了再说，别浪费了！";              
        if ( present("hongshao niurou",  environment(me)) )
                return "那不是有吗？先吃了再说，别浪费了！";              
        food = new ("/d/tiezhang/obj/fan");
        food->move(environment()); 
        food = new ("/d/tiezhang/obj/ruzhu");
        food->move(environment());
        food = new ("/d/tiezhang/obj/hsnr");
        food->move(environment());
        say("厨子将饭菜端出来放在了桌子上。\n");
        return "看样子是饿坏了吧！来，来，多吃点！";
}


