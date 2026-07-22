//bang.h buy forsky for 帮会系统

#define		LEADER_EXP_MIN		3000000
#define		GOLD_COST			2000
#define		MEMBER_EXP_MIN		1000000
#define		FIRST_MEMBER_NUM	4

int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
                write("对不起，中文名字必须是三到十五个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("对不起，中文名字不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，名字必需是中文。\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_long(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 120) || (strlen(name) > 600 ) ) {
                write("对不起，中文描述必须是六十到三百个中文字。\n");
                return 0;
        }
        while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' ) {
                        write("对不起，中文描述不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，描述必需是中文。\n");
                        return 0;
                }
        }
        return 1;
}

int create_guild(object ob,string name,string* member)
{
	int i;
	string str;
	object *temp;
	
	str = 	"帮名："+name+"\n";
	str +=	"成员数：5\n";
	str += 	"帮主："+ob->query("name")+"("+ob->query("id")+")\n";
	for(i=0;i<4;i++)
	{
		temp[i] = find_player(member[i]);
		str += 	"创始人："+temp[i]->query("name")+"("+temp[i]->query("id")+")\n";
	}

	ob->set("guild/name",name);
	ob->set("guild/leader_id",ob->query("id"));
	ob->set("guild/leader_name",ob->query("name"));
	ob->set("guild/power_desc","最高级");
	ob->set("guild/power_level","3");
	
	for(i=0;i<4;i++)
	{
		temp[i]->set("guild/name",name);
		temp[i]->set("guild/leader_id",ob->query("id"));
		temp[i]->set("guild/leader_name",ob->query("name"));
		temp[i]->set("guild/power_desc","高级");
		temp[i]->set("guild/power_level","2");
	}
	
	return 0;
}