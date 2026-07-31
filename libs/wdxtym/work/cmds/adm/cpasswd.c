
#include <login.h>;

int main(object me, string arg)
{
	object ob,link_ob;
	string id,password;
	
	seteuid(ROOT_UID); // add by Yuj@SJ 1999-6-2
	if( me != this_player(1) ) return 0;
	
	if( wiz_level(me) < 4 )
		return notify_fail("只有 admin 才能这样做。\n");

	if(!arg||sscanf(arg,"%s %s",id,password)!=2)
		return notify_fail("用法： cpasswd <ID> <新密码> \n此操作容易损害玩家利益，你必须先调查清楚！\n");

	ob = LOGIN_D->find_body(id);
	if(!ob){
		ob = new(LOGIN_OB);
		ob->set("id",id);
		if( !ob->restore() ) {
			destruct(ob);
			return notify_fail("没有这个玩家。\n");
		} else {				    
			ob->set("password",crypt(password, "zj"));
			write("玩家" + ob->query("id") + "("+ob->query("name")+ ")的密码已经更改为："+password+"\n");
		     // log_file("changepw", sprintf("%s：%s(%s)把%s(%s)的密码修改为 %s\n", ctime(time()), me->query("name"), me->query("id"),
			//	 ob->query("name"), ob->query("id"), password));
			ob->save();
			destruct(ob);
			return 1;
		}
	}
	
	link_ob=ob->query_temp("link_ob");
	if(link_ob) {
		link_ob->set("password",crypt(password,"$1$ShuJian"));
		link_ob->save();
		write("玩家" + ob->query("id") + "("+ob->query("name") + ")的密码已经更改为："+password+"\n");
		//log_file("changepw", sprintf("%s：%s(%s)把%s(%s)的密码修改为 %s\n", ctime(time()), me->query("name"), me->query("id"),
		//		 ob->query("name"), ob->query("id"), password));
		return 1;
	}
	else
		return notify_fail("错误。无法进行修改。\n");
	return 1;
}


int help(object me)
{
	write(@HELP
指令格式 : cpasswd ID 新密码

这个指令可以修改玩家的密码，请谨慎使用。

HELP
    );
    return 1;
}
