// verify.c
// Modified by snowman@SJ 16/03/2000
// Refered by kittt 7/3/2000@WEBSITE http://Mudder2000.yeah.net

#include <ansi.h>

inherit F_CLEAN_UP;
           // 描述阵列，和skills.c差不多
string *skill_level_desc = ({
        BLU "不堪一击" NOR,BLU "毫不足虑" NOR,BLU "不足挂齿" NOR,BLU "初学乍练" NOR,BLU "勉勉强强" NOR,
        HIB "初窥门径" NOR,HIB "初出茅庐" NOR,HIB "略知一二" NOR,HIB "普普通通" NOR,HIB "平平淡淡" NOR,
        CYN "平淡无奇" NOR,CYN "粗通皮毛" NOR,CYN "半生不熟" NOR,CYN "马马虎虎" NOR,CYN "略有小成" NOR,
        HIC "已有小成" NOR,HIC "鹤立鸡群" NOR,HIC "驾轻就熟" NOR,HIC "青出于蓝" NOR,HIC "融会贯通" NOR,
        GRN "心领神会" NOR,GRN "炉火纯青" NOR,GRN "了然于胸" NOR,GRN "略有大成" NOR,GRN "已有大成" NOR,
        YEL "豁然贯通" NOR,YEL "出类拔萃" NOR,YEL "无可匹敌" NOR,YEL "技冠群雄" NOR,YEL "神乎其技" NOR,
        HIY "出神入化" NOR,HIY "非同凡响" NOR,HIY "傲视群雄" NOR,HIY "登峰造极" NOR,HIY "无与伦比" NOR,
        RED "所向披靡" NOR,RED "一代宗师" NOR,RED "精深奥妙" NOR,RED "神功盖世" NOR,RED "举世无双" NOR,
        WHT "惊世骇俗" NOR,WHT "撼天动地" NOR,WHT "震古铄今" NOR,WHT "超凡入圣" NOR,WHT "威镇寰宇" NOR,
        HIW "空前绝后" NOR,HIW "天人合一" NOR,MAG "深藏不露" NOR,HIM "深不可测" NOR,HIR "返璞归真" NOR
});
           
string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,BLU "初窥门径" NOR,HIB "略知一二" NOR,HIB "半生不熟" NOR,
        CYN "马马虎虎" NOR,CYN "已有小成" NOR,HIC "融会贯通" NOR,HIC "心领神会" NOR,
        GRN "了然於胸" NOR,GRN "已有大成" NOR,YEL "非同凡响" NOR,YEL "举世无双" NOR,
        HIY "震古铄今" NOR,RED "无与伦比" NOR,WHT "超凡入圣" NOR,HIW "空前绝后" NOR,
});

// 武功种类的mapping
mapping valid_type = ([
"unarmed":      "拳脚",
"claw":         "爪功","cuff":         "拳功",
"finger":       "指功","strike":       "掌功",
"hand":         "手功","leg":          "腿功",
"sword":        "剑法","blade":        "刀法",  
"dagger":       "匕法","brush":        "笔法",          
"spear":        "枪法","hook":         "钩法",          
"stick":        "棒法","staff":        "杖法",          
"club" :        "棍法","throwing":     "暗器",          
"whip":         "鞭法","axe":          "斧法",
"hammer":       "锤法","force":        "内功",  
"dodge":        "轻功","parry":        "招架",  
]);

string skill_level(string, int);
string skill_enables(object sk);

int sort_skill(string file)  // 判断是否为可行的文件。
{
        int i;
        if ( !sscanf(file, "%*s.c") )  return 0;
        i = strlen(file); 
        while(i--){
                if( file[i] == '.' ) continue;
                if( file[i] < 'a' || file[i] > 'z' ) // 带数字显然就不行了。
                        return 0;
        }

        return 1;
}

int main(object me, string arg)
{
        mapping lrn;
        string exert, str, *file;
        object sk;
        int i, j = 0;

        seteuid(getuid());

        if(!arg) return notify_fail("指令格式 : verify [武功名称].[?|特殊技能]\n");
        
        sscanf(arg, "%s.%s", arg, str);
                
        if(!me->query_skill(arg, 1)) // 自己都不会当然不能查咯。
                return notify_fail("你要查对什么技能？\n");
        
        if(file_size(SKILL_D(arg)+".c") < 1)  // 文件不存在
                return notify_fail("错误！你要查对技能文件已经消失，请通知巫师。\n");
        
        if( stringp(str) ){
                // 格式 verify xxx.? 是查询此skill的帮助。
                // verify xxx.yyy 是查询 yyy 的帮助。
                // help还得自己写，麻烦麻烦！！不要也罢。--- by kittt
                if( str == "?" ){
                        notify_fail("对不起，「"+to_chinese(arg)+"」目前还没有详细的帮助说明。\n");
                        return SKILL_D(arg)->help(me);
                } // 以下是判断是否存在pfm,exert的说明，也是得自己写。slogan snowman
                else if( stringp(exert = SKILL_D(arg)->exert_function_file("")) && file_size(exert + str +".c") > 0){
                        notify_fail("对不起，"+to_chinese(arg)+"内功方面的「"+str+"」功能没有详细的说明。\n");
                        return (exert + str)->help(me);
                }
                else if( stringp(exert = SKILL_D(arg)->perform_action_file("")) && file_size(exert + str +".c") > 0){
                        notify_fail("对不起，"+to_chinese(arg)+"外功方面的「"+str+"」功能没有详细的说明。\n");
                        return (exert + str)->help(me);
                }
                return notify_fail("对不起，"+to_chinese(arg)+"没有「"+str+"」这项功能。\n");
        }
        
        lrn = me->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        str = sprintf("\n┌%-24s─────────────────────┐\n", HIW"【"+to_chinese(arg)+"功能表】"NOR);
        // 前面的一些skill状态输出，简单就不用说了吧。
        str = replace_string(str, "  ", "─");
        str += sprintf("│"HIY"等级"NOR"：  %s %3d/%6d\t      "HIY"类别"NOR"：  %-15s%9s  \n",skill_level(SKILL_D(arg)->type(), 
                        me->query_skill(arg, 1)), me->query_skill(arg, 1), 
                        (int)lrn[arg], SKILL_D(arg)->type(), "│");     

        // 如果不是功夫就不用看pfm什么的啦。
        if(SKILL_D(arg)->type() != "martial"  
        || member_array(arg, keys(valid_type))!=-1) 
                return notify_fail(str+"└─────────────────────────────────┘\n");
                
        str += "│\t\t\t\t\t\t\t\t    │\n";
        sk = load_object(SKILL_D(arg));

        // 输出该skill可以激发的基本技能。

        exert = skill_enables(sk);  //function在后面
        if(exert != ""){
                str += exert; // 如果存在就输出。
                i++;
        }

        // 输出有效的exert。    
        if( stringp(exert = SKILL_D(arg)->exert_function_file("")) ){  // skill文件tail不是常有的么
                file = get_dir(exert); // 用它来找出可用的路径。
                if( sizeof(file) > 0){   // 在其中将可用的exert列出来。 
                        file  = filter_array(file, (: sort_skill :) );  // sort_skill就是最前面那个function.
                        j = sizeof(file);
                }
        }
        
        if(j && j > 0){ // 输出结果了。snowman爱画框框啊。
                if( i )
                        str = str + "├─────────────────────────────────┤\n";
                str += "│"HIY"内功方面(exert + )"NOR"：\t\t\t\t\t\t    ";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "│\n│\t";  // 一行四个
                        str += sprintf("%-14s ",YEL+replace_string(file[i], ".c", "")+NOR);  // 当然输出要把文件名的.c去掉。
                        if ( i > j-2 ){
                                switch(i%4){ // 没有四个就要填空空喽。
                                        case 0: str +="\t\t\t\t\t            "; break;
                                        case 1: str +="\t\t\t            "; break;
                                        case 2: str +="\t\t    "; break;
                                        default: break;
                                }
                        }
                }
                str += "│\n";
                j = 0;
        }
        // pfm和exert差不了多少。
        if( stringp(exert = SKILL_D(arg)->perform_action_file(""))){
                file = get_dir(exert);
                if( sizeof(file) > 0){
                        file  = filter_array(file, (: sort_skill :) );
                        j = sizeof(file);
                }
        }
        
        if(j && j > 0){
                if( i )
                        str = str + "├─────────────────────────────────┤\n";
                str += "│"HIY"外功方面(perform + )"NOR"：\t\t\t\t\t    ";
                for(i=0; i < j; i++){
                        if (i % 4 == 0) str += "│\n│\t";
                        str += sprintf("%-14s ",WHT+replace_string(file[i], ".c", "")+NOR);
                        if ( i > j-2 ){
                                switch(i%4){
                                        case 0: str +="\t\t\t\t\t            "; break;
                                        case 1: str +="\t\t\t            "; break;
                                        case 2: str +="\t\t    "; break;
                                        default: break;
                                }
                        }
                }
                str += "│\n";
        }
        str += "└─────────────────────────────────┘\n";
        write(str);  // 大工告成。
        return 1;
}

string skill_enables(object sk) // 也是前面用到的function用以判断所能激发的基本计能。
{
        int i, j;
        string str, *skills;
        skills = keys(valid_type); 
        
        for(i=0; i < sizeof(skills); i++) { // 分解出有效的基本skill
                if (sk->valid_enable(skills[i])) continue; 
                skills[i] = 0;  // 如果是能被激发的基本skill就保留，不行的就改为0。
        }
        
        skills -= ({ 0 }); // 去掉上面code得到的0
        // 输出。
        j = sizeof(skills);  
        if( !j || j < 1)  
                return "";
        str = "│"HIY"特殊技能"NOR"：\t\t\t\t\t\t\t    ";
                
        for(i=0; i < j; i++) {
                if (i % 4 == 0) str += "│\n│\t";  
                str += sprintf("%-14s ", HIC+valid_type[skills[i]]+"("+skills[i]+")"NOR); 
                if ( i > j-2 ){  
                        switch(i%4){
                                case 0: str +="\t\t\t\t\t            "; break;
                                case 1: str +="\t\t\t            "; break;
                                case 2: str +="\t\t    "; break;
                                default: break;
                        }
                }
        }
        str += "│\n";
        return str;
}

string skill_level(string type, int level) //输出技能的描述。
{
        int grade;
        
        switch(type) {
                case "knowledge":
                        grade = level / 20;
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        grade = level / 8;
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write("\n指令格式 : verify [武功名称].[绝招名称 | ?]\n");
        write(@HELP
这个指令可以让你查询此项技能的功能和数据。

特殊技能表示可以 enable 的技能，如：
        (轻功、招架、棍法、杖法) 表示：此武功可以用作轻功，招架，棍法，杖法等。

内功方面显示可运用(exert)的内功。

外功方面显示可使用(perform)的外功，绝招等。

如果内功或外功的绝招有帮助介绍，可用 verify skill.pfm 的形式来查看。
如：    verify taiji-quan.dongjing  查看动静决
        verify yinyun-ziqi.yinyun   查看氤氲内聚
        verify taiji-quan.?         查看太极拳

        
HELP);

    return 1;
}

