// miss 追寻物品

#include <ansi.h>

inherit F_CLEAN_UP;
string *anjian=({

//"在线玩家:who",
"魔窟副本:flygo moku",
"幻境副本:flygo huanjing",

//"草人试炼:flygo caoren",
});
mapping where=([
//"qiandao":"/d/city/wumiao",
//"daizi":"/d/wizard/guest_room",
//"room":"/data/hell/4/guangchang",
//"lunjian" : "/d/lunjian/enter",
//"turen" : "/d/pk/entry",
//"qianchi" : "/d/fuben/qianchipu/qianchipu",
]);
int main(object me, string str)
{
	if(environment(me)->query("no_magic", 1))
		return notify_fail("这里无法使用这个功能。\n");
	
 if(!str)
 {
string bynb,msg,bynb1;
msg=ZJOBLONG"萌新功能键，请选择\n"ZJOBACTS2+ZJMENUF(4,4,8,30);
  foreach (bynb in anjian)
 msg+= bynb+ZJSEP;
 msg+="草人副本:flygo caoren\n";
 //msg+= bynb1+ZJSEP;

 tell_object(me,msg);
 return 1;
 }

	if (me->is_ghost())
		return notify_fail("你还是等还了阳再说吧。\n");
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中。\n");

    {	//副本
    	object room;
    	
        if (str == "moku")
        {
        	if(!objectp(room = new("/d/fuben_moku/moku")))
        	{
        		write("副本开启失败。\n");
        		return 1;
        	}
        	if(!room->start_fuben_moku(this_player()))
        		destruct(room);
        	return 1;
        }
        if (str == "caoren")
        {
        	if(!objectp(room = new("/d/fuben_caoren/shilianchang")))
        	{
        		write("副本开启失败。\n");
        		return 1;
        	}
        	if(!room->start_fuben_caoren(this_player()))
        		destruct(room);
        	return 1;
        }
        
        if (str == "huanjing")
        {
            "/d/fuben_huanjing/huanjing"->start_fuben(me);
            return 1;
        }
    }

 if (stringp(where[str]))
 me->move(where[str]);
return 1;	
}

int help(object me)
{
write(@HELP
指令格式 :
老魔牛逼！
HELP
    );
    return 1;
}
