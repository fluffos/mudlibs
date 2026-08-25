// color.c by fire on Dec 30 1997 
// modified on April 1999
#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>
#define p_sep "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓"
inherit CHINESE_DA;
inherit CMD;
nosave protected mixed * bkc=({ BBLK,BRED,BGRN,BYEL,BBLU,BMAG,BCYN,BWHT});
nosave protected mixed * fkc= ({ BLK,RED,GRN,ORG,BLU,MAG,CYN,WHT,
			 HIR,HIG,HIY,HIB,HIM,HIC,HIW});
private string line="     BBLK  BRED  BGRN  BYEL  BBLU  BMAG  BCYN  BWHT";
private string *row=({ "BLK","RED","GRN","ORG","BLU","MAG","CYN","WHT",
			 "HIR","HIG","HIY","HIB","HIM","HIC","HIW"});

	
void main()
{
	int i,j;
	string p_color;
	printf("《三国演义》颜色测试：\n");
	
	printf("%s\n",p_sep);
	printf("%s\n",line);
	for(j=0;j<sizeof(fkc);++j) {
		write(row[j]+" ");
		for(i=0;i<sizeof(bkc);++i) {
			write(bkc[i]+fkc[j]+"★■◎"+NOR); 
		}
		write("\n");
	}
	printf("%s\n",p_sep);
	return;
}
