// skilld.c
// by nerd 97/5
// This is the "daemon dispatcher" that provide a link to varius skill
// daemons.

mapping skill_daemons = ([
    // Shaolin 
    "jimie-zhua"        : "shaolin",
    "longzhua-shou"     : "shaolin",
    "luohan-quan"       : "shaolin",
    "mohe-zhi"          : "shaolin",
    "nianhua-zhi"       : "shaolin",
    "sanhua-zhang"      : "shaolin",
    "weituo-zhang"      : "shaolin",
    "xumishan-zhang"    : "shaolin",
    "yintuoluo-zhua"    : "shaolin",
    
    //wuliang
    "wuliang-jian"      : "wuliang",
    "liuyun-jian"       : "wuliang",
    "haoran-zhengqi"    : "wuliang",
    "wuliang-shenfa"    : "wuliang",
    "yanxing"           : "wuliang",
    "nanshan-liushi"    : "wuliang",
    "lingxiao-shou"     : "wuliang",

    // baxian-men
    "xingyun-shenfa"    : "biaoju",
    "fengxiang-jianfa"  : "biaoju",
    "penglai-xinfa"     : "biaoju",
    "baxian-shenfa"     : "biaoju",
    "chuiliu-jianfa"    : "biaoju",
    "baxian-jian"       : "biaoju",
    "baxian-zhang"      : "biaoju",
    "chusuifeng"        : "biaoju",
    
    // kongdong
    "ny-bufa"           : "kongdong",
    "kd-xinfa"          : "kongdong",
    "wulong-quan"       : "kongdong",
    "shizi-zhan"        : "kongdong",
    "dahong-quan"       : "kongdong",
    "luofeng"           : "kongdong",
    "kongling-jian"     : "kongdong",
    "fengyun-jian"      : "kongdong",
    "qishang-quan"      : "kongdong",

]); 
    
string find_skill(string skill)
{   
    if( !undefinedp(skill_daemons[skill]) ) 
        return CLASS_D(skill_daemons[skill])+"/skill/"+skill;
    return "/system/skill/" + skill;
}   

