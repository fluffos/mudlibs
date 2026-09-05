// yxdh-bei.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"侠客行英雄大会"HIY"纪念碑"NOR, ({ "jinian bei", "bei"}));

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","座");
		set("long", CLR+HOME+HIC @LONG

                           ■■■■■■■■■■■■
                         ■■■■■■■■■■■■□
                       ■■■■■■■■■■■■□□   
                       ■                    ■□□     
                       ■                    ■□□         
                       ■         [31m侠[36m         ■□□    
                       ■                    ■□□             
                       ■         [31m客[36m         ■□□             
                       ■                    ■□□             
                       ■         [31m英[36m         ■□□             
                       ■                    ■□□             
                       ■         [31m雄[36m         ■□□             
                       ■                    ■□□             
                       ■         [31m大[36m         ■□□             
                       ■                    ■□□             
                       ■         [31m会[36m         ■□□             
                       ■                    ■□□             
                       ■         [33m纪[36m         ■□□             
                       ■                    ■□□             
                       ■         [33m念[36m         ■□□             
                       ■                    ■□□             
                       ■         [33m碑[36m         ■□□             
                   ◇◇■                    ■□□ ◇◇◇◇    
                ◇◇◇ ■                    ■□ ◇◇◇◇◇
              ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇    
　 　       ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇◇◇
            ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇◇
　　        ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇
[37m
    这是一座记录着一代代侠客行英雄丰功伟绩的纪念碑，虽经过若干年的风雨，
字迹却依然清晰可见。上面记载着历次北侠英雄大会的战果。背面的碑文密密麻
麻，你不禁仔细阅读起来。(read 数字)
LONG NOR);
		set("no_get", 1);
	}
	setup();
}
string* log = ({

HIR"第一次北侠英雄大会"NOR"
"CYN"丙戌年腊月二十九（2007年2月16日）晚20：30开始
"DASH_LINE+HIG"
"HIY" 小 米 组 "HIG"    状元 吉诺拉(Bugdmf)     榜眼 油条(Youtiao)      探花 德川家康(Occ)
"HIY" 大 米 组 "HIG"    状元 粉肠王(Linxaohui)  榜眼 夏夏(Dadh)         探花 大米(Pptct)
"HIY" 新 秀 组 "HIG"    状元 澄破(Shiguang)     榜眼 项少龙(Xiangshl)   探花 天王盖地虎(Tgd)
"HIY" 高手丁组 "HIG"    状元 令狐虫(Zbugbug)    榜眼 花中雪(Yynathan)   探花 赵胜(Zhaosheng)
"HIY" 高手丙组 "HIG"    状元 美美(Maymay)       榜眼 芳儿(Fanger)       探花 导演(Hanhema)
"HIY" 高手乙组 "HIG"    状元 林以寒(Tulip)      榜眼 河马史诗(Hemass)   探花 巴锲勒(Olo)
"HIY" 高手甲组 "HIG"    状元 天龙(Pptl)         榜眼 绿蚊子(Gtohly)
"HIY"绝世高手组"HIG"    状元 天龙(Pptl)
"HIY"北侠神话组"HIG"    状元 燕苍(Cpcer)
"NOR,

});

void init()
{
	add_action("do_read", "read");
}

int do_read(string arg)
{
	int times;
	if(!arg || !sscanf(arg, "%d", times))
	{
		write("你要读哪一次英雄大会的碑文？(read 数字)\n");
		return 1;
	}
	if(times < 1 || times > sizeof(log))
	{
		write("不存在这次英雄大会。\n");
		return 1;
	}
	this_player()->start_more(log[times-1]);
	return 1;
}
