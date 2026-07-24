"/d/kaifeng/",
"/d/kaifeng/",
"/d/kaifeng/",
"/d/westway/",
"/d/changan/",
"/d/meishan/",
"/d/gao/",
"/d/xueshan/",
"/d/moon/",
"/d/jjf/",
"/d/qujing/biqiu/",
"/d/qujing/wuji/",
"/d/qujing/wuzhuang/",
"/d/qujing/chechi/",
"/d/qujing/nuerguo/",
"/d/qujing/qinfa/",
"/d/qujing/jisaiguo/",
fangcun
hell
hyd
jjf
shushan
wudidong
wzg
xueshan
dragon
moon
pansi
putuo
gumu
sanjie

string family_action(string family)
{
    if (family && !undefinedp(performs[family]))
        return performs[family][random(sizeof(performs[family]))];
}
