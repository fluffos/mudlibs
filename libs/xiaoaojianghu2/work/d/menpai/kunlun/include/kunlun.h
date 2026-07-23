// kunlun.h
// Ffox 98-9-7 14:02
#include <ansi.h>

//判断是否昆仑派的弟子
int kl_dizi(object me )
{
    if( me->query("family/family_name") == "昆仑派" ) return 1;
    else return 0;
}
//设置昆仑派特有的标记
mixed kl_mark(string opt, object sb, string name, mixed num, int sign)
{
      switch( opt ) {
        case "set" : 
            if (sign==1) return (sb->set("ffox/"+name,num) );
            else return(sb->set_temp("ffox/"+name,num) );
        case "delete" :
            if (sign==1) return( sb->delete("ffox/"+name));
            else return( sb->delete_temp("ffox/"+name));
        case "query" : 
            if (sign==1) return( sb->query("ffox/"+name));
            else return( sb->query_temp("ffox/"+name));
        case "add" :
            if( sign==1) return( sb->add("ffox/"+name,num) );
            else return (sb->add_temp("ffox/"+name,num) );
        default :
            return 0;
        }
}