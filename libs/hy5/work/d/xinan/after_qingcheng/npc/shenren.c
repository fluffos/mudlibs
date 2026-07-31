
//Writen by lnwm on 97/07/09

//shenren.c

//玉壁月华明剑法
//无量剑派最杰出的弟子，见到后山玉壁上的玉壁月华明的剑法
//不能自拔，追逍遥子而去，（逍遥子追立秋水）一直追到四川。
//逍遥子感他虔诚，指点了他两招，他遂隐居在此，痴等逍遥子。

//有洁癖

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("白衣老人", ({ "baiyi laoren","laoren","ren" }) );
    set("gender", "男性" );
    set("age", 40);
    set("title","");
	set("long",
"一位神秘人物。\n"
	    );
    setup();
}




