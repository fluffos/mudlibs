// bloc.c	聯盟指令	Shengsan@DS
inherit F_CLEAN_UP;
#include <bloc.h>
#include <ansi.h>


//int help();

int main(object me, string arg)
{
	string bloc_cmds;
	int i,cmds_type;
	if( me != this_player(1) ) return 0;
	if( !wizardp(me) ) return 0;
//	me->set("BLOC/eBlocName","gigi");
//	me->set("BLOC/CMDS/cmds",({BLOC_CMDS_CREAT,BLOC_CMDS_ADDMEMBER,BLOC_CMDS_SHOW}));
	if(!arg) return 0;

	if( sscanf(arg, "%s %s", bloc_cmds, arg)==2 )
	{
		write("兩個字串啦\n");
		cmds_type=BLOC_D->search_bloc_cmds(bloc_cmds);
	}
	else
	{
		write("一個字串啦\n");
		cmds_type=BLOC_D->search_bloc_cmds(arg);
		bloc_cmds = arg;
		arg = "";
	}
	write("= "+cmds_type+" =\n");
	if(cmds_type==-1)
		return 0;
	i=BLOC_D->check_cmds_authority(me,cmds_type);
	write("== "+i+" ==\n");
	if(i==0)
		return 0;
	i = BLOC_D->process_bloc_cmds(cmds_type,me,arg);
	write("=== "+i+" ===\n");
	return 1;
}