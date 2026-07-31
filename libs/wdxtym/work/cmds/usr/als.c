// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
	    object obj,ob,obj1,obj2,obj3,obj4;
	mapping alias;
        int count,mengxin,i;
        string a,b;
	string verb, replace, *vrbs,str;

		me = this_player();
        if (! arg) 
		
        return notify_fail(INPUTTXT(ZJSIZE(18)MAG BBLK"请选择你要连续10次的快捷指令"NOR,"als $txt#")+"\n");
		
	switch (arg) {
	  case "1" :
			str = ZJOBLONG+ZJSIZE(29)+WHT"注意：锻造仅有50%的成功率，请谨慎操作，三级之前失败只会扣除一个锻造材料，之后失败只会扣除部分材料！"+NOR+ZJBR+sprintf(HIR"你目前的武器锻造等级为：" NOR + HIY " %d级"NOR, me->query("weapon/dj"))+ZJBR+sprintf(HIR"你目前的神兵锻造等级为：" NOR + HIY " %d级"NOR"\n", me->query("shenbing/dj"))+"\n"+ZJOBACTS2+ZJMENUF(1,1,10,29);
			str += "点击输入你要执行十连的指令，例如：aa:als"+ZJSEP;
			write(str+"\n");
		return 1;

		break;
	  case "aa" :
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));	
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));
	write(ZJFORCECMD("aa"));	

		break;
	  case "bb" :
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));	
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));
	write(ZJFORCECMD("bb"));	

	  case "cc" :
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));	
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));
	write(ZJFORCECMD("cc"));	
	  case "dd" :
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));	
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));
	write(ZJFORCECMD("dd"));		
	  case "ee" :
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));	
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));
	write(ZJFORCECMD("ee"));	
	  case "ff" :
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));	
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));
	write(ZJFORCECMD("ff"));	
	  case "gg" :
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));	
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));
	write(ZJFORCECMD("gg"));	
	  case "hh" :
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));	
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));
	write(ZJFORCECMD("hh"));	
	  case "ii" :
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));	
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));
	write(ZJFORCECMD("ii"));	
	  case "jj" :
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));	
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));
	write(ZJFORCECMD("jj"));	
	  case "kk" :
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));	
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));
	write(ZJFORCECMD("kk"));	
	  case "ll" :
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));	
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));
	write(ZJFORCECMD("ll"));	
	  case "mm" :
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));	
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));
	write(ZJFORCECMD("mm"));	
	break;

	  default :
		message_vision(HIC "出现错误，请联系巫师。\n" NOR,me);
	}		
              sscanf(arg, "%s ", a);


        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家红包。
HELP
        );
        return 1;
}
