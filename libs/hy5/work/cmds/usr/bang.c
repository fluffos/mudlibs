#include <ansi.h>
#define SCORE_COST 5000
#define GOLD_COST 2000
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
	object gold;
	string e_name,c_name,title,mid,mname;	
	string *dir;
	int i;
	seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s %s",e_name, c_name, title) != 3)
        return notify_fail("指令格式：　bang xuelianjiao 雪莲教 教主\n");
        if((int)me->query("score") < SCORE_COST)
        return notify_fail("你的江湖阅历不够"+chinese_number(SCORE_COST)+
        "点。\n");
	 if((int)me->query("combat_exp") < 15000000)
        return notify_fail("你的经验不够"+chinese_number(15000000)+
        "点。\n");
        gold = present("gold_money",me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < GOLD_COST)
        return notify_fail("你身上没有"+chinese_number(GOLD_COST)+"两金子。\n");	
	if(!check_legal_name(c_name) || !check_legal_name(title))
	return 1;
	c_name += "　";
	e_name += "_";
	dir = get_dir(DATA_DIR+"guild/");
	for(i=0; i<sizeof(dir); i++) 
	if(dir[i] == e_name || dir[i] == c_name)
	return notify_fail("你想创立的帮派中文或英文名字已经被别人占用了！\n");	

	if(c_name=="少林派" || c_name=="武当派" || c_name=="峨嵋派"|| c_name=="华山派"
	|| c_name=="灵鹫宫"|| c_name=="桃花岛"|| c_name=="星宿派"|| c_name=="白驼山派"
	|| c_name=="神龙教"|| c_name=="云龙门"|| c_name=="明教"|| c_name=="丐帮"
	|| c_name=="全真教"|| c_name=="大理段家"|| c_name=="逍遥派"|| c_name=="铁掌帮"
	|| c_name=="姑苏慕容"|| c_name=="日月神教"|| c_name=="昆仑派"|| c_name=="雪山寺"
	|| c_name=="关外胡家"|| c_name=="唐门"|| c_name=="飞天御剑流"|| c_name=="昆仑派"
	|| c_name=="南少林派"|| c_name=="五毒教"|| c_name=="铁掌帮"|| c_name=="凌霄城"
	|| c_name=="红花会"|| c_name=="嵩山派"|| c_name=="泰山派"|| c_name=="青城派"
	|| c_name=="恒山派"|| c_name=="衡山派"|| c_name=="梅庄"|| c_name=="日月神教")
	return notify_fail("你想创立的帮派中文或英文名字已经被别人占用了！\n");	

	if(
	!BR_D->touch_file(DATA_DIR+"guild/"+e_name) ||
	!BR_D->touch_file(DATA_DIR+"guild/"+c_name))
	return notify_fail("游戏系统出现问题！请通知管理人员！\n");
        mid=me->query("family/master_id");
	mname=me->query("family/master_name");
	me->delete("family");
	me->create_family(c_name,1,title);
	me->set("class",e_name);
        me->set("family/master_id",mid);
        me->set("family/master_name",mname);
	me->add("score",-SCORE_COST);
	gold->add_amount(-GOLD_COST);
	me->set("title",c_name+title);
 	message("system",
	HIM"\n☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ \n\n\n"HIC 
			"\t\t    『  "+c_name+"』"+"在江湖中成立了！\n"HIM"
	    \n☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ \n"NOR,
			users() );
    return 1;
}
 
int help(object me)
{
    write(@HELP
让你在海洋中成立自己的帮派！

指令格式: 
bang xuelianjiao 雪莲教 教主
经验要求 15M
此指令让你创立一个新的帮，派，或教。 
并封你为雪莲教教主。

又例：

bang bluedress 青衣楼 总管
创立青衣楼并封你为青衣楼总管。
HELP
    );
	return 1;
}
 
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

