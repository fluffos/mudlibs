// This is a chinese-english convert module.
// By Annihilator@Eastern.Stories 10-20-93
 
#include <daemons.h>
 
string to_chinese(string english)
{
        return (string)CHINESE_D->chinese(english);
}
 
varargs int can_read_chinese(object ob)
{
/*
        if( !ob ) {
                if( this_player() ) return (int)this_player()->query("chinese");
                else return (int)previous_object()->query("chinese");
        }
 
        if( !living(ob) ) return 0;
 
        return (int)ob->query("chinese");
*/
        return 1;
}
 
string chinese_number(int i)
{
        return (string)CHINESE_D->c_number(i);
}
 
