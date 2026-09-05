//shizhe4.c  负责教学的使者
//by zoom
//2003.3.31

#include "shizhe.h"

void greeting(object me)
{
	command("tell "+me->query("id")+" 
    欢迎！欢迎！我是负责功夫指令的使者，我将教你如何使用功夫指令。

    打斗前先要决定自己使用什么武功，即激发，指令：enable|jiafa <武功名>。
例如：enable force zixia-shengong,就是激发紫霞神功为当前的内功，注意，
重新激发内功时，内力小点，就是当前值变为零。内功有所长进之后要打坐来提
高自己的内力，命令是dazuo num，或者dz，可以看具体的help， 小心打坐时走
火入魔。内力高了之后，就可以在战斗时加力(enforce|jiali <num>)， 加力的
多少取决于内功的等级。同时内功还有补充精，气，疗伤等作用，help kungfu-force。

    然后如果是用兵器上的功夫的话，就需要使用相应的兵器，这就要用到wield
和unwield指令。wield 兵器名使用该兵器，unwield则放弃使用。两只手都可以拿
武器，战斗的时候使用的招式以右手武器为准。空手功夫要备才能在打架的时候使
用，命令是:prepare|bei [<特殊技能名称>|none]，前提是这种功夫已经激发。
");
	command("tell "+me->query("id")+" 
    学会了特殊的功夫之后，一般都有特殊攻击效果(perform)，达到一定要求后
(级别或谜题)就可以用perform xx的命令来使用特殊攻击，大多数都要求在和敌人
战斗中才可以使用，也有少数可以直接使用，但是被人发现，可能会主动杀你。

    你也可以穿上一些护具来保护自己，如你现在身上的布衣就是护具。穿某种
护具用wear 护具名，remove则取下该护具。你也可以用wear all穿上你所有的
所有护具，remove all则取下所有护具。

    此外，还可以设置一些参数，例如set wimpy xx，设置逃跑系数等。");
}