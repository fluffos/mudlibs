inherit F_CLEAN_UP;
int check_legal_name(string name);
int check_legal_long(string name);
void enter_desc(object me,object gold,string s_title, string dir, string text);
#define SCORE_COST 2000
#define GOLD_COST  1000
#define MIN_EXP 5000000
int main(object me, string arg)
{
        int flag;
        string stitle;
    string banghui;
        string ltitle;
        string dir;
        object env;
        object gold;
object lp;
        seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s",dir,stitle) != 2)
       return notify_fail("指令格式：　zao5 north 恨天阁大门 \n");
//       if(me->query("family/privs") != -1) 
        if(! (banghui=me->query("banghui")))
        return notify_fail("你没有这种权力。\n");
        if((int)me->query("score") < SCORE_COST)
        return notify_fail("你的江湖阅历不够"+chinese_number(SCORE_COST)+
        "点。\n");
        if((int)me->query("combat_exp") < MIN_EXP)
        return notify_fail("你的实战经验不够"+chinese_number(MIN_EXP)+
        "点。\n");
        gold = present("gold_money",me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < GOLD_COST)
        return notify_fail("你身上没有"+chinese_number(GOLD_COST)+"两金子。\n");
        lp=new("/clone/misc/lingpai");
        lp->create(banghui);
        if(lp->query("no_use")) {
                destruct(lp);
                return notify_fail("你的帮会文件有问题，请与巫师联系。\n");
        }
        if(lp->query("bangzhu_id")!=me->query("id"))    {
                destruct(lp);
                return notify_fail("只有帮主才能使用本指令。\n");
        }

        destruct(lp);
       if((int)me->query("created_men") > 0)
        return notify_fail("你不可再建房了！\n");
        env = environment(me);
       if(!env->query("owner") && (string)env->query("owner") != "public" 
        && (string)env->query("owner") != (string) me->query("id"))
        return notify_fail("你不可在这建房！\n");
        if((string)env->query("type") == "zheng" && me->query("shen") < 0)
        return notify_fail("你一个邪魔外道想在这里造房子？找死啊！\n");
        if((string)env->query("type") == "xie" && me->query("shen") > 0)
        return notify_fail("你一个正派人士想在这里造房子？找死啊！\n");

        if(check_legal_name(stitle))
         me->edit( (: enter_desc , me,gold, stitle, dir :) );
        return 1;
        
}
void enter_desc(object me,object gold, string s_title,string dir,string text)
{
string *direc= ({"north", "south", "east", "west",
"enter","out", "up", "down"});
        int i;
        int okey=0;
        int record = 6;
        object env;
        if(!check_legal_long(text)) return;
        for (i = 0; i < sizeof(direc); i++)
        if(direc[i] == dir) {okey=1; break;}
        if(okey)        
        {
        env = environment(me);
        if(env->query("exits/"+dir))
                {
                tell_object(me,"这个方向已经有房屋了！\n");
                return;
                }
// I think by now, we should checked all conditions,
// deduct the cost and go build it!
                gold->add_amount(-GOLD_COST);
                me->add("score",-SCORE_COST);
                BR_D->buildroom(me,s_title,text,dir,record);
        }
        else
        {
        tell_object(me,"你要往哪个方向建？\n");
        return;
        }
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("对不起，中文名字必须是一到二十个中文字。\n");
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
        }
        return 1;
}

int help (object me)
{
        write(@HELP
指令格式: zao5 <讯息>
给自己的帮派造房子。

HELP
        );
        return 1;
}

