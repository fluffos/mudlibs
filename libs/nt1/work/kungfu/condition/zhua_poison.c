#include <ansi.h> 
#include <condition.h> 

inherit F_CLEAN_UP; 
inherit POISON; 

string name() { return "zhua_poison"; } 

string chinese_name() { return "凝血神抓毒"; } 

string update_msg_others() 
{
       return HIW "$N" HIW "忽然打了一个哆嗦,脸上露出痛苦而诡异的笑容。\n" NOR; 
}

string update_msg_self() 
{
        return HIW "忽然一丝热流自体内升起，缓缓的浸入你四肢百骸，原来你中的凝血神抓毒发作了！\n" NOR; 
}
