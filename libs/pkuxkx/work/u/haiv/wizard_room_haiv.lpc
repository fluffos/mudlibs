// Room: /d/wizard/wizard_room_haiv.c

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", HIW"实验室"NOR);
	set("long", @LONG
这里就是千里草巫师的实验室，各种实验器具一应具全，实验台上
一尘不染，进实验室前要全身消毒，穿上无菌白大褂，带上无菌手套，
欢迎各位巫师来游玩，实验台上有个厚厚的实验记录簿(board)。
LONG );

	set("exits", ([ 
        "whuan" :"/d/wizard/wizard_room_whuan" ,
  	"out" :"/d/wizard/wizard_room" ,
        "pal" :"/d/wizard/wizard_room_pal" ,
        "hz" :"/d/hangzhou/zhongxin" ,
  	"city":"/d/city/guangchang",
  	]));

	set("valid_startroom", 1);
	set("no_clean_up", 0);
	setup();
  "/clone/board/haiv_b"->foo();

}

void  init  ()
{
    add_action  ("do_addexp","addexp");
    add_action  ("do_addpot","addpot");
    add_action  ("do_addneili","addneili");
    add_action  ("do_addjingli","addjingli");
    add_action  ("do_addskill","addskill");
    add_action  ("do_addscore","addscore");
    add_action  ("do_addrobot","addrobot");
    add_action  ("do_addfeizei","addfeizei");
    add_action  ("do_addmudage","addmudage");
    add_action  ("do_addnuoyi","addnuoyi");
    add_action  ("do_addrepute","addrepute");
    add_action  ("do_addmoney","addmoney");
    add_action  ("do_addhydtimes","addhydtimes");

}

int  do_addexp  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，经验！ \n");       
    me->add("combat_exp",1000000);
    
    return 1;
}

int  do_addpot  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，潜能！ \n");       
    me->add("potential",1000000);
    
    return 1;
}

int  do_addneili  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，内力！ \n");       
    me->add("max_neili",100);
    
    return 1;
}

int  do_addjingli  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，精力！ \n");       
    me->add("max_jingli",100);
    
    return 1;
}

int  do_addskill  ()
{
    object me; 
    mapping skills;
    me = this_player();
    skills=me->query_skills();
        if(mapp(skills))
        {
        	string *skname;
                skname=keys(skills);
                for(int i=0;i<sizeof(skills);i++)
				{
                        skills[skname[i]]++;
				tell_object(me,HIC"你的［"+to_chinese(skname[i])+"］进步了!\n"NOR);
				}
        }
		tell_object(me,HIW"你觉得个方面的武功都有所进步！\n"NOR);   
       
    return 1;
}

int  do_addscore  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，门忠！ \n");       
    me->add("score",1000);
    
    return 1;
}

int  do_addrobot  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，机器人！ \n");       
    me->set("antirobot/deactivity",-1000);
    
    return 1;

}

int  do_addfeizei  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，飞贼！ \n");       
    me->set("chaoting/catch_feizei",210);
    
    return 1;

}

int  do_addmudage  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，年龄！ \n");       
    me->add("mud_age",86400);
    
    return 1;
}

int  do_addnuoyi  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，挪移！ \n");       
    me->set_skill("qiankun-danuoyi",830);
    
    return 1;
}

int  do_addrepute  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，声望！ \n");       
    me->add("repute",100000);
    
    return 1;
}

int  do_addmoney  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，金钱！ \n");       
    me->add("balance",10000000);
    
    return 1;
}

int  do_addhydtimes  ()
{
    object me; 
    me = this_player();    
    write("你高喊一声，来吧，hyd！ \n");       
    me->add("yidao/times",500);
    
    return 1;
}