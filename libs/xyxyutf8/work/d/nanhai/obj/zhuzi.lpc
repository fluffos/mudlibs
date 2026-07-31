// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <weapon.h>
inherit STAFF;

string *names = ({
	"慈","ci","单","dan","四季","siji","硬头簧","yingtou","斑","ban",
	"楠","nan","水","shui","墨","mo","白粉","baifen","罗汉","luohan",
	"琴丝","qinsi","凤尾","fengwei","方","fang","棕","zong","斗笠","dou li",
	"十二时","shi","蒽芬","enfen","人面","renmian","桃丝","taosi",
	"金镶碧嵌","jinbi","孝顺","xiaoshun","蕲","qi","双","shuang",
	"龙公","long gong","弓","gong","柯享","kexiang","桂","gui",
	"思摩","simo","梅绿","meilv","大夫","dafu","龙须","longxu",
	"临贺","linhe","相思","xiangsi","疏节","shujie","丹青","danqing",
	"通节","tongjie","凝波","ningbo","沛","pei","扁","bian",
	"船","chuan","观音","guanyin","邛","qiong","紫","zi",
});	

void create()
{
	int i;
	string name,id;
	i = random(sizeof(names))/2*2;
	name = names[i];
	id = names[i+1];		
	set_name(name+"竹",({id+" zhu","zhu","zhuzi"}));
  	set_weight(100);
  	set("long","一根挺直的竹子，卓越不凡充满灵气。\n");
  	set("unit", "根");
	set("wield_msg", "$N「呼」地一声抽出一根$n握在手中。\n");  	
  	setup();
  	init_staff(100);
}