// realuser.c
// 注册实名用户

inherit F_CLEAN_UP;

#include <ansi.h>
#include <specialskill.h>

int confirm(string option,string id,object me)
{
    object newuser,newuser_loginob;
    object ob;

	  ob = me->query_temp("link_ob");
    if(!ob) return 0;
	  while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

    if(option != "yes") 
    {
        write("好吧，请仔细考虑。\n");
    }
    else
    {
        newuser = find_player(id);
        if(!objectp(newuser))
        {
            write("没有这个用户或者他/她未上线。\n");
        }
        else
        {
            newuser_loginob = newuser->query_temp("link_ob");
	          while( newuser_loginob && newuser_loginob->is_character() ) 
	            newuser_loginob = newuser_loginob->query_temp("link_ob");
	          
            if(newuser_loginob->query("realuser_verified"))
            {
                write(id+"已经是实名用户了。\n");         
            }
            else
            {

				if (me->query("realuser_tran"))
            {
                write("你本身就是转移来的实名，不能再次下传。\n");         
            }
			else
				{
					me->add("combat_exp",-me->query("combat_exp")/5);
					if(me->query("combat_exp") < 2000)
					{
						me->set("combat_exp", 2000);
					}
					me->add("int",-2);
					me->add("str",-2);
					me->add("dex",-2);
					me->add("con",-2);
					me->add("kar",-2);
					me->add("per",-2);
					me->add("spi",-2);

					me->save();

					ob->delete("realuser_verified");
					ob->save();
					
					newuser_loginob->set("realuser_tran",1);
					newuser_loginob->set("realuser_verified",time());
					newuser_loginob->save();

					write("你已经成功的把身份转移给了"+id+"\n");
					tell_object(newuser,me->name()+"已经把实名验证的身份转移给了你。\n");
					log_file("/user/realuser", sprintf("%s %s(%s)将实名用户转移给了%s(%s)。\n", ctime(time()), me->query("name"), me->query("id"), newuser->query("name"), newuser->query("id") ) );
				}
            }
        }
    }
    return 1;
}

int main(object me, string arg)
{
	object ob;
  object newuser,newuser_loginob;
	string line;
	int no;
	string* words;
	string id,code="";
	string skill,skill_cn;

	int count = 0;
	if( me != this_player(1) ) return 0;

	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
	
	if(!arg) return notify_fail("指令格式：realuser 验证码 或 realuser id\n");
	if(ob->query("realuser_verified")) 
  {
        newuser = find_player(arg);
		if (!me->query("realuser_tr_enable"))
			{
			 return notify_fail("未经巫师允许，不能转移实名。如果确实需要转移，可以向巫师申请转移资格。\n");
			}
        if(!newuser)
        {
            return notify_fail("你已经是实名用户了！如果你想将实名验证的身份转移到其他ID，请使用realuser id。\n");
        }

        if(newuser == me)
        {
            return notify_fail("转给自己？\n");
        }
        
        newuser_loginob = newuser->query_temp("link_ob");
        if(newuser_loginob->query("realuser_verified"))
        {
            write(arg+"已经是实名用户了。\n");
            return 1;
        }

        if(time() - ob->query("realuser_verified") < 86400 * 30)
        {
            write("您完成实名验证不到30天，不能转移验证身份给别的玩家。\n");
            return 1;
        }
        write("转移实名验证身份需要消耗本ID 20%的经验，且先天属性各降低两点。转移后，新ID在不能再做转移。\n。");
        write("确定要将实名验证身份转移给:"+arg+"请输入：yes\n");
        input_to((:confirm:),0,arg,me);
        return 1;
  }
	no=1;
	while(1)
	{
		line = read_file("/data/realuser/verifycodes",no,1);
		if(sizeof(line) == 0)
		{
			break;
		}
		words = explode(line,":");
		if(sizeof(words) != 2) 
		{
			no++;
			continue;
		}
		if(strcmp(words[0],me->query("id")) == 0)
		{
			id = words[0];
			code = words[1];
			break;
		}
		no++;
	}
	if(sizeof(code) == 0)
	{
		write("你的注册申请可能还未批准。\n");
		return 1;
	}
	code = replace_string(code,"\n","");
	if(strcmp(code,arg) == 0)
	{
		write(HIY"恭喜！你的实名验证成功了！从现在开始，你是北大侠客行MUD的实名用户！\n"NOR);
		seteuid(getuid());
		ob->set("realuser_verified",time());
		ob->save();
		log_file("/user/realuser", sprintf("%s %s(%s)注册为实名用户。\n", ctime(time()), me->query("name"), me->query("id")) );
	}
	else
	{
		write("嗯？验证码不对啊。\n");
	}
	
	return 1;
}


int help(object me)
{
	write(@HELP
指令格式 : realuser 验证码
 
输入你收到的验证码，就可以注册为实名用户。验证码的格式像这样：TPJK-VMGO-PHRW-KSHZ-UGUO
全部是大写。

也可以用这个指令将实名验证的身份转移到其他ID：
realuser id
HELP
    );
    return 1;
}
 
