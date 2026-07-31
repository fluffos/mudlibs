// 神农帮的ＮＰＣ标准文件  /d/menpai/shennong/npc/ShennongNpc.c
// by lala, 1998-01-21

#include <ansi.h>
inherit NPC;

void Greeting( object ppl );

void setup()
{
    mapping my = this_object()->query_entire_dbase();
                                                                                                     
    if( !my["title"]          ) set("title", BLU"神农帮帮众"NOR);
    if( !my["gender"]         ) set("gender",            "男性");
    if( !my["age"]            ) set("age",     18 + random(50) );
    if( !my["attitude"]       ) set("attitude",     "peaceful" );
                                
    if( !my["max_force"]      ) set("max_force",            100);
    if( !my["force"]          ) set("force",                100);
    if( !my["force_factor"]   ) set("force_factor",           5);
    if( !my["max_kee"]        ) set("max_kee",              225);
    if( !my["max_sen"]        ) set("max_sen",              225);
    if( !my["kee"]            ) set("kee",                  225);
    if( !my["sen"]            ) set("sen",                  225);
                                    
    if( !my["combat_exp"]     ) set("combat_exp",         10000);
    if( !my["social_exp"]     ) set("social_exp",         15000);
    if( !my["negative_score"] ) set("negative_score",       800);

    if( !my["inquiry"]        )
        set("inquiry",  ([
            "here"      :   "这不就是无量山嘛，那帮无量剑的家伙就住在这儿。",
            "rumors"    :   "上次本帮到无量山采药，和无量派的家伙动了手。",    
            "神农帮"    :   "本帮就是神农帮，在大理赫赫有名！",
            "无量派"    :   "就是住这儿的那帮家伙，上次那个什么容子矩杀了我们好几个弟兄！",
            "无量山"    :   "这不就是无量山嘛，那帮无量剑的家伙就住在这儿。",
            "剑湖宫"    :   "是无量派的家伙住的地方，这次咱们要平了他们，占了这剑湖宫。",
            "司空玄"    :   "那是本帮的帮主，你怎么敢随便提他老人家的名字！",
            "灵鹫宫"    :   "……你怎么知道的？……快不要提起。",
            "通天草"    :   "据说这长在无量山里的草熬汤可以缓解生死符的发作。",
            "容子矩"    :   "无量派的家伙数他最狠，上次杀了我们好几个弟兄呢！",
            "生死符"    :   "……这，这是灵鹫宫的一种暗器，帮主身上就中了几颗。",
        ]) );

    if( !my["talk_msg"]       )
        set("talk_msg", ({
            "“我们神农帮以采药、贩药为生，所以这药理上一定要下功夫。”",
            "“本来呢，我们和他们无量派虽然没有什么交情，但是原也没有梁子。”",
            "“无量派的家伙真是可恶，我们要到他们后山采药，他们居然敢不让！”",
            "“哼，他们这后山又不是金銮殿、御花园，外人凭什么来不得？”",
            "“我们神农帮和无量派动了两次手，吃了不小的亏，死伤了好几个弟兄！”",
            "“那个叫做容子矩的小子最是可恶，杀了我们两个好弟兄！～～”",
            "“这一次如果不把无量派杀个鸡犬不留，咱们便人人抹脖子吧。”",
            "“缥缈峰灵鹫宫这次派来的符圣使带来天山童姥的命令，说要平了无量派。”",
            "“其实灵鹫宫是要弄清楚「无量玉璧」的秘密，可要弄清这秘密就必须占了剑湖宫。”",
        }) );  
    if( !my["family"]         )
        set("family",   ([
            "family_name"   :   "神农帮",
            "master_name"   :   "司空玄",
            "master_id"     :   "sikong xuan",
            "generation"    :   2,
            "title"         :   "弟子",
        ]) );
    ::setup();
}




void init()
{
	object me=this_player();
      remove_call_out( "greeting" );
       call_out( "greeting", 1, me );
}

void greeting( object me )
{

    if ( !me 
        || environment( me ) != environment() )
        return;

            if( me->query("family/family_name") == "无量剑派东宗" 
    ||  me->query("family/family_name") == "无量剑派西宗" )    
    {
    message_vision( "$N对着$n桀桀怪笑：“你们这些无量派的狗东西，还想跑吗？ ”\n",
        this_object(), me );
    this_object()->kill_ob(me);
    me->fight_ob(this_object());
   }
}


void attempt_apprentice( object ppl )
{
    command( "say “呵呵，本帮只有帮主本人可以收徒，你还是去拜帮主他老人家吧！”" );
    return;
}

            