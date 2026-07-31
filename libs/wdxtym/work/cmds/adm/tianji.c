// paym.c

#include <ansi.h>

int main(object me, string arg)
{
	string userid, file;
	int rmb;
	
if (! SECURITY_D->valid_grant(me, "(admin)") || !wizardp(me))
		return 0;

	seteuid(ROOT_UID);
	if(!arg) {
		return 0;
	} else if (sscanf(arg, "%s %d", userid, rmb) == 2) {
		file = sprintf("user_id=%s&order_id=%s-%s-%d&pay_type=%d&result_code=0&amount=%d&pay_time=%s",
											userid, userid, userid, time(), 8, rmb, 
										CHINESE_D->chinese_date(time(), 5) + "  "+CHINESE_D->chinese_date(time(), 6));
		//tell_object(find_player("luoyun"),sprintf("file==%O\n", file));
		PAYDD->do_get(file, "127.0.0.1");
	} else {
		write(INPUTTXT(HIY+ZJSIZE(22)+"你想给("+HIG+ZJSIZE(22)+(arg)+HIY+ZJSIZE(22)")充值多少元天机点？"NOR,"tianji "+arg+" $txt# ")+"\n");
		return 1;
	} 
	return 1;
}
