// Updated by stefan on 10 Jan 1997
#include <daemons.h>

nosave protected mapping prep_info = ([ 
        "in"    : "%s里面",
        "from"  : "从%s",
        "on"    : "%s上",
        "under" : "%s下面",
        "behind": "%s后面",
        "beside": "%s的旁边",
        "to"    : "%s",
        "with"  : "和%s一起", 
        "at"    : "对%s", 
        "off"   : "%s下", 
        "out"   : "%s外面", 
        "down"  : "%s下方", 
        "up"    : "%s上方", 
        "around": "%s周围", 
        "over"  : "%s上面",
        "into"  : "%s内", 
        "about" : "关于%s",
       ]); 
                

string prep_calc(string prep, string name) {
        if (member_array(prep, keys(prep_info))==-1) return prep + name;
        else return sprintf(prep_info[prep], name);
        	
}

string chinese_number(int i)
{
        return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
        return CHINESE_D->chinese(str);
}

int is_chinese(string str)
{
        // Same GBK byte-range bug as valid_chinese_id() in secure/user/
        // login.c (AGENTS.md 8.1): str[0] is a Unicode codepoint here, not
        // a raw GBK lead byte, and strlen() counts characters not bytes.
        if (strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <= 0x9fff) return 1;
        return 0;
}

string gender_self(string sex)
{
        switch(sex) {
                case "女性": return "你";       break;
                default: return "你";
        }
}

string gender_pronoun(string sex)
{
        switch(sex) {
                case "男性":    return "他";    break;
                case "女性":    return "她";    break;
                case "雄性":
                case "雌性":    return "它";    break;
                default: return "它";
        }
}
