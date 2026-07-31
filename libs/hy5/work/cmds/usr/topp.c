#include <ansi.h>
int main()
{
	string info,name,id,file,infoa,infob;
		info = read_file("/data/npc/champion.o");
infoa = read_file("/data/npc/menpai.o");
infob = read_file("/data/npc/menpai1.o");
	printf(HIY"\n\n    ΩΩ= "HIM" 海洋各派知名人士列表"HIY"  =ΩΩ\n"HIW"----------------------------------------------\n"NOR);
printf(HIM"	〖江湖浩劫〗"+RED" %s"+HIC"▲对战▲"NOR+RED" %s\n"NOR,infoa,infob);
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIC"	正派盟主        "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIC"	正派盟主        "+HIB" 空缺\n"NOR);
	info = read_file("/data/npc/champion1.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIR"	邪派盟主        "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIR"	邪派盟主        "+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_wy.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIB"	五岳剑派盟主    "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIB"	五岳剑派盟主    "+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_sl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	少林寺掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	少林寺掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_gm.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	古墓派掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	古墓派掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_gb.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	丐帮掌门大弟子  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"   	丐帮掌门大弟子  "+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_hs.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	华山派掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	华山派掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_yl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	云龙门掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	云龙门掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_lj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	灵鹫宫掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	灵鹫宫掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_xx.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	星宿派掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	星宿派掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_wd.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	武当派掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	武当派掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_em.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	峨眉派掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	峨眉派掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_xs.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	雪山寺掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	雪山寺掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_dl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	大理段家大弟子  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	大理段家大弟子  "+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_bt.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	白驼山掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	白驼山掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_mj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	明教掌门大弟子  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	明教掌门大弟子  "+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_qz.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	全真派掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	全真派掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_ry.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	日月教掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	日月教掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_mr.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	慕容世家大弟子  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	慕容世家大弟子  "+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_slj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	神龙教掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	神龙教掌门大弟子"+HIB" 空缺\n"NOR);
info = read_file("/data/npc/champion_th.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	桃花岛掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	桃花岛掌门大弟子"+HIB" 空缺\n"NOR);
	info = read_file("/data/npc/champion_tz.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	铁掌帮掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	铁掌帮掌门大弟子"+HIB" 空缺\n"NOR);
	info = read_file("/data/npc/champion_xy.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	逍遥派掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	逍遥派掌门大弟子"+HIB" 空缺\n"NOR);
	info = read_file("/data/npc/champion_kl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	昆仑派掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	昆仑派掌门大弟子"+HIB" 空缺\n"NOR);
	info = read_file("/data/npc/champion_wdj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	五毒教掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	五毒教掌门大弟子"+HIB" 空缺\n"NOR);
	info = read_file("/data/npc/champion_lx.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	凌霄城掌门大弟子"+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	凌霄城掌门大弟子"+HIB" 空缺\n"NOR);
	info = read_file("/data/npc/champion_tm.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	唐门掌门副门主  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	唐门掌门副门主  "+HIB" 空缺\n"NOR);
	info = read_file("/data/npc/champion_feitian.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	飞天御剑流宗主  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	飞天御剑流宗主  "+HIB" 空缺\n"NOR);


	info = read_file("/data/npc/champion_nsl.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	南少林派副主持  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	南少林派副主持  "+HIB" 空缺\n"NOR);


	info = read_file("/data/npc/champion_hua.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	红花会副总舵主  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	红花会副总舵主  "+HIB" 空缺\n"NOR);


	info = read_file("/data/npc/champion_ss.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	嵩 山 派副掌门  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	嵩 山 派副掌门  "+HIB" 空缺\n"NOR);


	info = read_file("/data/npc/champion_ts.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	泰 山 派副掌门  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	泰 山 派副掌门  "+HIB" 空缺\n"NOR);
		
	info = read_file("/data/npc/champion_qc.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	青 城 派副掌门  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	青 城 派副掌门  "+HIB" 空缺\n"NOR);		

	info = read_file("/data/npc/champion_henshan.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	衡 山 派副掌门  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	衡 山 派副掌门  "+HIB" 空缺\n"NOR);		
		

	info = read_file("/data/npc/champion_hengshan.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	恒 山 派副掌门  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	恒 山 派副掌门  "+HIB" 空缺\n"NOR);				

	info = read_file("/data/npc/champion_hj.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	关外胡家副总管  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	关外胡家副总管  "+HIB" 空缺\n"NOR);			
		

	info = read_file("/data/npc/champion_mz.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	梅  庄  副庄主  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	梅  庄  副庄主  "+HIB" 空缺\n"NOR);					

info = read_file("/data/npc/champion_jh.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	靖海派  副门主  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	靖海派  副门主  "+HIB" 空缺\n"NOR);					


info = read_file("/data/npc/champion_hn.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	白云庵  副庵主  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	白云庵  副庵主  "+HIB" 空缺\n"NOR);					

info = read_file("/data/npc/champion_kd.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	崆峒派  副掌门  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	崆峒派  副掌门  "+HIB" 空缺\n"NOR);			
		
info = read_file("/data/npc/champion_xkd.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	侠客岛  副岛主  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	侠客岛  副岛主  "+HIB" 空缺\n"NOR);					


info = read_file("/data/npc/champion_yd.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
	printf(HIG"	落雁庄  副庄主  "+HIB" %s\n"NOR,name+"("+id+")");
	}else printf(HIG"	落雁庄  副庄主  "+HIB" 空缺\n"NOR);					


	printf(HIW"------------------------------"HIM" ☆ 海洋V ☆ "HIW"---\n"NOR);

return 1;
}
int help(object me)
{  
write(@HELP
指令格式: topp让你察看海洋中各大武林人士。
HELP
   );   
return 1;
}