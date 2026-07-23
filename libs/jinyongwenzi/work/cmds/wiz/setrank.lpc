// rank.c
// by snowman@SJ 11/03/2000

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	
        if( !arg ) {
                write(RANK_D->query_rank(me)+me->short(1)+"\n");
                return 1;
        }
        
        if( strlen(arg) > 30 )
                return notify_fail("你的头衔太长了，想一个短一点的、响亮一点的。\n");

	if( sscanf(arg, "%s %s", arg, str)!=2 )
		return notify_fail("你要设置头衔的哪一项？(rank, color, level, self_rude, self, rude, respect)\n");
		
	switch(arg){
		case "rank": 
		case "color":
		case "self_rude":
		case "self":
		case "rude":
		case "respect":
			me->set("rank_info/"+arg, str); break;
			
		case "level": if(intp(atoi(str)) )
				me->set("rank_info/level", atoi(str)); 
				break;
		default: return notify_fail("你要设置头衔的哪一项？(rank, color, level, self_rude, self, rude, respect)\n");
	}

        write("你将头衔的 "+arg+" 项，设置为："+str+"。\n");
        write(RANK_D->query_rank(me)+me->short(1)+"\n");
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : rank <项目> <字串>
 
这个指令可以让你为自己设定一个头衔的等级，颜色等。
HELP
        );
        return 1;
}
