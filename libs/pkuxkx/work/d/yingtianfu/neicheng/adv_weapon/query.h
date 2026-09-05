#include <ansi.h>

#define HEADER MAG" ━━━━━━━━━━━━━━━━━━━━━━━━━━ \n"NOR
#define LINE   MAG" ━━━━━━━━━━━━━━━━━━━━━━━━━━ \n"NOR

string getdegree(int lv,object me)
{
    string *degrees=({"无","☆","★","★☆","★★","★★☆","★★★","★★★☆","★★★★","★★★★☆","★★★★★","★★★★★☆","★★★★★★"});
	int *lvs=({0,1,2,3,4,5,6,7,8,9,10,11,12});
    return degrees[member_array(lv,lvs)];
}

int do_queryweapon()
{
    object me=this_player();
    string msg,info,degree;
	string *adv_weapon_name=({"剑意","刀芒","鞭影","霸斧","枪魂","怒锤","流戟","器灵","匕魔","横杖"});
	string *adv_weapon=({"sword","blade","whip","axe","spear","hammer","halberd","throwing","dagger","staff"});
	string *color=({WHT,HIW,YEL,HIY,HIG,BLU,HIC,CYN,HIR,RED});
    int lv;
    msg="\n\n";
    msg+=HEADER;
    info=HIW"              ☆☆高级兵器技能☆☆\n"NOR;
    msg+=info;
    msg+=LINE;
    msg+="\n";
	for (int i=0;i<sizeof(adv_weapon);i++)
	{
		lv=(int)me->query("adv_weapon/class/"+adv_weapon[i]+"/lv");
		degree=getdegree(lv,me);
		info=color[i]+"  ◆"+adv_weapon_name[i]+"◆  "+sprintf("%-14s",degree);
		if (i%2==0)
		info+="  ";
		else
		info+="\n";
		msg+=info;
	}
    msg+=LINE;
    tell_object(me,msg);
    return 1;
}