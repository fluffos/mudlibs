// hp cmds
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;
        int opp_damage,me_damage,me_round,opp_round;
        string output;
        
        seteuid(getuid(me));
 
        if(!arg) return notify_fail("你要評估誰的強度﹖\n");
                ob = present(arg, environment(me));
        if(!ob) return notify_fail("這裡沒有你要評估的對象。\n");
        if(!me->visible(ob)) return notify_fail("這裡沒有你要評估的對象。\n");
	if(!living(ob)) return notify_fail("這個東西看起來沒什麼威脅性。\n");
	if(ob==me) return notify_fail("你自己的狀態你自己最清楚吧。\n");
	if(me->query("mp")<5 ) return notify_fail("你精神不佳, 無法正確判斷對手的強度。\n");
	opp_damage=ob->query_damage();
	opp_damage = opp_damage/2 + random(opp_damage/2);
	opp_damage -= (int)(me->query_armor()*3+random(me->query_armor()*2))/5;
	me_damage=me->query_damage();
	me_damage = me_damage/2 + random(me_damage/2);
	me_damage -= (int)(ob->query_armor()*3+random(ob->query_armor()*2))/5;
	if(me_damage<1) me_damage=1;
	if(opp_damage<1) opp_damage=1; 
	me_round = me->query("hp")/opp_damage;
	opp_round = ob->query("hp")/me_damage;
	
	output="在你仔細的評估了"+ob->name()+"的強度之後發現:\n\n  ";

	if( me_round < 5 ) output+=HIW+"對付"+ob->name()+"?!..就憑你?..我看是你活的不耐煩了!\n"+NOR; 
	else
	{
		output+=ob->name();
	
		if(me_round< 3) output+=HIR"有非常恐怖的戰鬥力。\n"+NOR;
		else  if(me_round< 5) output+=HIM"有強大的戰鬥力。\n"+NOR;
		else  if(me_round<11) output+="有頗強的戰鬥力。\n"; 
		else  if(me_round<20) output+="戰鬥力不弱。\n";
		else  if(me_round<35) output+="的戰鬥力不強。\n";
		else output+="的攻擊力並不足以威脅你。\n";
		
		if( opp_round < 3) output+=HIG"  現在的你應該可以在瞬間取勝。\n"NOR;
		else  if(opp_round< 5) output+=HIG"  現在的你應該可以輕鬆獲勝。\n"NOR;
		else  if(opp_round<11) output+="  雖然你有相當的勝算，但最好不要輕敵。\n"; 
		else  if(opp_round<20) output+="  你可能\要花一番功\夫才能\打的贏。\n";
		else  if(opp_round<35) output+="  要有萬全的準備才能取勝。\n";
		else output+="  這將會是一場持久戰。\n";
	}
	write(output);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : consider <對象名稱>

這個指令可以讓你(妳)或評估指定對象(含怪物)的強度。

see also : score
HELP
    );
    return 1;
}

