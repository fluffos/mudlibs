// /d/menpai/duanshi/npc/guard.h
inherit NPC;

string *second_name = ({
"升", "晋", "添", "增", "和", "思", "全", "德","崇","保","有","佑","万","千","百","允","元","建",
                    });

string *last_name = ({
"忠", "孝", "仁" ,"义", "信", "礼", "诚", "福","寿","禄","家","邦","吉","祥","宝","胜","文","武",
                    });

string *second_id = ({
"sheng", "jin", "tian", "zeng", "he", "si", "quan", "de", "chong", "bao", "you", "you", "wan",
"qian", "bai", "yun", "yuan", "jian", 
                    });

string *last_id = ({
"zhong", "xiao", "ren", "yi", "xin", "li", "cheng", "fu", "shou", "lu", "jia", "bang", "ji",
"xiang", "bao", "sheng", "wen", "wu",
                    });                    
                    
int refuse_killing()
{
    int i;
    object *inv, who=this_player();

    who->apply_condition("kill_dali", 150);
    inv = all_inventory( environment(this_object()) );
    for(i = 1; i < sizeof(inv); i++)
    {
        if ( !userp( inv[i] )
            && inv[i] != this_object() 
            && inv[i]->query("class")=="duanshi"
            && inv[i] != who )
            inv[i]->kill_ob(who);
    }
    return 0;
}

void win_bihua( object who )
{
    if ( environment()->query( "short" )!="小客厅") return;
    who->set_temp("finish_bihua", 1);
    who->set_temp("be_defeated", 1);
}

void lose_bihua( object who )
{
    if ( environment()->query( "short" )!="小客厅") return;
    who->set_temp("finish_bihua", 1);
    who->set_temp("be_defeated", 0);
}
#include "teach.h";