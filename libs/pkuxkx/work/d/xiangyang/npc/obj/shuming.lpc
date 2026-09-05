#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( HIC "『襄阳城导游』" NOR, ({ "luyou tu", "tu" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
                set("long",
"\n                 『襄阳城导游』\n\n" +
"襄阳城中主要的秘密有：
    1: 拿雕雏: ask 村姑 about 白雕
                 注：(1)要赶在村姑死前杀掉土匪头 . \n" +
"                     (2)dodge > 80.
    2: 取马: ask 马夫 about 借马---ask 郭芙 about 小红马---ask 郭芙 about 白雕
       ----give diaochu to 郭芙---到马房取马\n" +
"    3：拿<射雕英雄传>:
            南门(ask 守将 about 投军)------郭靖家中（ask 女拥 about 郭大侠）----
            帅府(ask 郭靖 about 报国)----北门(give ling to jiang)-----ride 马---\n" +
"           蒙古营门（answer 送信)------kill 蒙哥,get 兵符-----give 兵符 to 郭靖
                 注：(1) 没有马是过不了草原的。
                     (2) 襄阳城中只要对任意一个守军或者守将下kill,就会到处被砍。\n" +
"    4: 拿掌法秘籍：
            绸缎庄(buy 布料)---ask 张大哥 about 小兰---give 布料 to 张大哥---
          give 布料to 小兰 \n" +
"    5: 九转熊胆丸：
            ask 猎户 about 医生-----ask 程灵素 about 救人-----带领程灵素到猎户家中看病
        打晕麝鹿，得到麝香，-----打死老虎，得到虎骨，-----打死黑熊得到熊胆------采到灵芝\n" +
"        -----在白雕雪峰第二层(zuan dong)得到玄冰-----give to 程灵素
            注意：(1):麝鹿不能杀死，否则麝香会毁掉，而且过一段时间麝鹿会消失。
                 (2):杀黑熊之前玩家被晕掉，get all from ,所以没有武器.黑熊过一段时间也会消失。\n" +
"                 (3):通向灵芝和黑熊的路是随机的。
 宝物的功效：
      1:  《射雕英雄传》parry ,force 到180级，耗精30。
      2:  《掌法秘籍》 strike 到 60级，耗精 20\n" +
"      3:  九转熊胆丸： 如果吃掉，正神的降1000，负神的加1000，内力+10,精力加15；
                       如果给猎户，道德加5000。\n" +
    RED"以上有不妥之处，烦劳各位给予指正和修改，不胜感激。



                                  chenchen 98.4.25\n"NOR
             );
        set("value",10000);
		set("material", "paper");
	}
	setup();
}
