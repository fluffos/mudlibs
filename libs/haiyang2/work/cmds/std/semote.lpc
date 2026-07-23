// semote.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int checksemote(object me,string arg);
int femote(object me,string arg);
int show(object me,string str,string arg,int count); 
int flag = 1;

int main(object me, string arg)
{
        string *e, out="";
        int i,j = 0;
	if( (int)me->query("jing") < 50 )
		return notify_fail("你的精神无法集中。\n");
	if( !wizardp(me) )
		me->receive_damage("jing", 50);

        if (!arg)
        {
                e = sort_array(EMOTE_D->query_all_emote(), 1);

                for(i=0; i<sizeof(e); i++)
                {
                        out += sprintf("%-13s%s", e[i], (j++%6==5)?"\n": "");
                }
                me->start_more(out + "\n");
                return 1;
        }
        else
                return checksemote(me,arg);
}

int checksemote(object me, string arg)
{
        mapping emote;
        string str,*e;
        int i,count;
        count = 0;        
        emote = EMOTE_D->query_emote(arg);
        e = sort_array(EMOTE_D->query_all_emote(), 1);
        str="";
	if( (int)me->query("jing") < 50 )
		return notify_fail("你的精神无法集中。\n");
	if( !wizardp(me) )
		me->receive_damage("jing", 50);

        if ( !arg )
        {
                for(i=0; i<sizeof(e); i++)
                {
                        str += sprintf("%s%s\n%s\n","Emote名称：",e[i],EMOTE_D->query_emote(e[i])["others_target"] );
                }
        }
        else
        {
                for(i=0; i<sizeof(e); i++)
                {
                        if ( arg==e[i] )
                        {
                                str=sprintf("%s%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n","Emote名称：",e[i],
                                emote["myself"], emote["others"], emote["myself_self"],
                                emote["others_self"], emote["myself_target"], emote["target"],
                                emote["others_target"] );
                                count ++;
                                break;
                        }
                        if (arg==e[i][0..sizeof(arg)-1])
                        {
                                str += sprintf("%s%s\n%s%s\n","Emote名称：",e[i],"内容：",EMOTE_D->query_emote(e[i])["others_target"] );
                                count ++;
                        }
                }
        } 
        if (str=="")
                return femote(me,arg);
        else
        {
                flag = 1;
                return show(me,str,arg,count);
        }
}

int femote(object me,string arg)
{
        mapping emote;
        string *e, *loop;
        string str="", msg;
        int i,count,k;
        count = 0;
	if( (int)me->query("jing") < 50 )
		return notify_fail("你的精神无法集中。\n");
	if( !wizardp(me) )
		me->receive_damage("jing", 50);

        loop = ({ "others_target", "others_self", "others" });

        e = sort_array( EMOTE_D->query_all_emote(), 1);

        for(i=0; i<sizeof(e); i++)
        {
                emote = EMOTE_D->query_emote(e[i]);
                for( int j=0; j<sizeof(loop); j++ )
                {
                        msg = emote[ loop[j] ];
                        if( msg && strsrch(msg, arg) != -1 )
                        {
                                str += sprintf("Emote 名: %s\n动作: %s\n", e[i], msg);
                                k ++;
                        }
                }
                if( k )
                        count ++;
                k = 0;
        }

        if(  str == "" )
                return notify_fail(MUD_NAME" 中无符合查询条件["+ arg +"]的 Emote.\n");
        else
        {
                flag = 0;
                return show(me,str,arg,count);
        }
}

int show(object me,string str,string arg,int count)
{
	if( (int)me->query("jing") < 50 )
		return notify_fail("你的精神无法集中。\n");
	if( !wizardp(me) )
		me->receive_damage("jing", 50);

        str =
    		"\n参数" + arg + "的查询结果："
                "\n---------------------------------------------------------------\n"
                + str;
        str = replace_string(str, "$n", "(对方)");
        str = replace_string(str, "$N", me->name(1));
        str = replace_string(str, "$P", "你");
        str = replace_string(str, "$p", "(他/她)");
        str = replace_string(str, "$S", RANK_D->query_self(me));
        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
        str = replace_string(str, "$R", "(对方的粗鲁称呼");
        str = replace_string(str, "$r", "(对方的粗鲁称呼)");
        str = replace_string(str, "$C", "(自己的呢称)");
        str = replace_string(str, "$c", "(对方的呢称)");

        str += "---------------------------------------------------------------\n";
        flag?str += sprintf("在%s中，以[%s]开头的 Emote 共有 %d 个。\n",MUD_NAME, arg, count ):str += sprintf("在%s中，含有[%s]的 emote 共有 %d 个。\n",MUD_NAME, arg, count );
        me->start_more(str);
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : semote [中英文]

这个指令不加参数时可以列出目前所能使用的Emote，
加上参数后，可以搜索以参数为开头或含有该参数的Emote。

HELP
    );
    return 1;
}

