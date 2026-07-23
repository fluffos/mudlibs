// 等同 /cmds/skill/study.c  用于参修典籍。
// Ffox 98-4-16 14:09


#include <ansi.h>
#include <skill.h>

int get_gain(object me, object ob, mapping book)
{
    string type;
    int bonus;

    type = SKILL_D( book[ "name" ] )->query_xiuwei_type();
    
    if ( type && (int)me->query_xiuwei_by_type(type) < book["xiuwei_required"] )
    {
        write("你拿着" + ob->name() +"仔细端详，却发现很难理解上面所讲的一切。\n");
        return 1;
    }
    if ( (int)me->query_lingwu( "literate" ) < book[ "literate_required" ] )
    {
        write("你拿着" + ob->name() +"仔细研读了一下，却发现上面的文字过于艰深，也许你需要\n"
            "多学些读书识字方面的知识了。\n");
        return 1;
    }
    if ( ob->invalid_study( me ) )
        return 1;
    if ( !me->query_jibie( book[ "name" ] ) )
        me->set_jibie( book["name"], 0 );
    
    // 书分成两类一类是涨jibei和exp
    // 这类相当于 课外书，丰富知识的
    // 另一类是涨jibie和xiuwei的
    // 这类就是课本了，用于学写的，象师傅。

    if ( book[ "bonus_jilei" ] )
    {
        if ( !book[ "max_lingwu" ] 
            || me->query_lingwu( book[ "name" ] ) > book[ "max_lingwu" ] )
        {
            write ( "这本书的一切都都已尽被你须知，你已经无法从中学到新东西了。\n" );
            return 1;
        }
        if ( !me->query_jibie( book[ "name" ] ) )
        {
            write( "这本书只能从中领悟到熟练度。你还不会这门技能。\n" );
            return 1;
        }
        bonus = book[ "bonus_jilei" ];
        if ( bonus <= 0 )
            me->improve_jilei(book["name"], (int)me->query_lingwu( "literate" ) / 3 + 1 );
        else 
            me->improve_jilei(book["name"], bonus);
        if ( book["bonus_social_exp"] &&
            (int)me->query("social_exp") < book["max_social_exp"] )    
        {
            bonus = book["bonus_social_exp"];
            me->add("social_exp", bonus);
        }
        if ( book["combat_exp"] &&
            (int)me->query("combat_exp") < book["max_combat_exp"] )
        {
            bonus = book["bonus_combat_exp"];
            me->add("combat_exp", bonus);
        }
    }
    else 
    {
        if ( me->query_jibie( book[ "name" ] ) 
            && me->query_lingwu_ratio( book[ "name" ] ) < 90 )
        {
            write( "功夫需要多加练习，才能真正掌握。\n" );
            return 1;
        }
        else
        {
            if ( me->query_jibie( book[ "name" ] ) >=  book[ "max_jibie" ] )
            {
                write ( "这本书的一切都都已尽被你须知，你已经无法从中学到新东西了。\n" );
                return 1;
            }
            if ( bonus = book[ "bonus_jibie" ] > 0 )
                me->improvve_jibie( book[ "name" ], bonus );
            else if ( bonus <= 0 )
            {
                if (me->query("age")<15) // to avoid selecting gifts
                    me->improve_jibie( book[ "name" ], random(15) );
                else
                    me->improve_jibie( book[ "name" ], 
                        random( (int)me->query("int")/10 + random(2) ) );
                    // 这样的random没有用，因为多读若干次总有一次是最大值: "int"-1 + 1

                if ( book["bonus_xiuwei"] && 
                    (int)me->query_xiuwei_by_type( type ) < book[ "max_xiuwei" ] )
                {
                    bonus = book["bonus_xiuwei"];
                    me->improve_xiuwei( type, bonus );
                }
            }
        }
    }                
    write(YEL"你研读有关" + to_chinese(book["name"]) + "的技巧，从中悟出了一些心得。\n"NOR);
    return 1;
}

