//房间
#include <ansi.h>
#include <login.h>
inherit CHAT_ROOM;

void create()
{
        set("short","$HIM$【凝～儿～居】$NOR$");
        set("long", @LONG
 $CYN$                           .,odd$$$$$i,?bouc,.
                         .ue$$?TCD$GICP$$$bc"$$$$$bc
                     ,,uod$?ld$$$$$$$$$bi2$$$,????$$b
                 .,e$$$$$Pb$$??P?P?$$$$$$$$("4$6F`"$bU, !> >
                .d$$$$R??i2Ue$$$$R??%x"?,ced$$bec,'$$P".)!-
                d$?$$$$$$$$$$$',ced$$$$$$$$$$$$$i hd$$$$o
               `)d$?lb$$$$$$"ucd$$$$$$$$$$$$$$$$$$$$,`bd$$$$$c
                d"u$$$$$$P"u$$$$$$$$$$$$$$$$$$$$$$$X> $$$$$$$$$
               Jd$$$$$F,r,$$$$$$$$$$$$$$P5IC7PF"',,ud:?$$$$$$$$>
               $$$$$F,d"x$$$$$$$$$$$?53bd$$R"ud$$$$$$$."t?T$$$$$
               $$$$"d$"d$$$$$$$$$$$$$$$$$$".d$$$$$$$$$$bc "$$$$
               $$'$$ d$$$$$$$$$?$CG$ecr n9$???$$$$$$???$ X$?F
               ?$,$'J$$$$$$$+cQ??$??TP ",ub8??hJ$$$z$$$h;$VF
                $$$$$ $$$$$$?$$cIR$$zP":!t$"``"``$$$"`-`'`XF"
                 $h<$$$$$b.""??'  <!!!8$o,;";u$$$c?%-;; :
                  `$$h?$$$$$$>)d$L9k !X$$$$$$$$$$$$$$$$$F
                     ?$h"?$$$$$i`?$`?k'$$$$$$$$$$??XX$$$F
                      `??.??$L?? R ?.Xd$$$$$$$$$bu$$$$F
                         ?$$$$$?F xX$$X?$$$$$F"""""9$"
                          $6X(? dUJ$bu`?R$$$$$euud$'
                           $$$?n !.$$$??$$$$$P   $
                            ??$ :Xkd$$$$$32D  `"" 
                            
$HIW$相片的旁边放着一张美丽的卡片【$HIC$zi$HIW$】。旁边的音响正在播放着andy的歌曲【$HIY$music$HIW$】
音响上面放着一张纸【$HIR$zhi$HIW$】$NOR$
LONG
);

        set("item_desc",([
                "zi": HIW"
$HIC$ARE YOU ALLRIGHT. I MISS YOU TONIGHT $HIW$真心无奈 多心都为了爱 我坐在这傻傻的发呆
我仍依赖 你纯纯的$HIR$爱$HIW$ 我心还在 爱你的人还在 苦苦等 想哭哭不出来 $HIC$无心伤害$HIW$ 你应该
明白 爱太多空隙 受伤容易 互信互爱才是唯一 对你的付出都放在心里 我始终这样珍惜
我怎么会忘记 $HIY$FEEL SO SORRY,BABY I'M SO SORRY I NEVER MEANT, I NEVER MEANT TO
HURT U $HIC$无心伤害$HIW$ 你应该明白 $HIC$FEEL SO LONELY,BABY I'M SO LONELY DO U KNOW,I NEED 
U TO COME BACK ARE U ALLRIGHT $HIY$请快点回来$HIW$(I MISS U TONIGHT) 真心仍在 与你永不分
开 $HIY$这一生只愿和你相爱$HIW$ 与你同在 只为你等待 $HIM$爱是纯真$HIW$ 爱是无恨 不在乎怎么会痛苦万
分 $HIM$我真的太笨$HIW$ 不懂心疼 $HIY$BABY PLEASE COME BACK OH YA~ 
\n"NOR,

"music":"$HIW$短短一生太多的变化 难得又慢慢步进了平凡忘掉了多不想失去 却终于失去他
偏偏空虚心里多记挂 风吹不息又似真却似假 前路$HIR$我$HIW$可不惜一切再编织一个家
现在不想 想呀 一世不想烦 有谁人谁人令我不再惊怕 $HIC$遇上你$HIW$ 你知道吗 $HIR$我不
能一息间将你等于他$HIW$ 是你在旁牵起了变化 $HIC$心枯也不禁说出这段情话 $HIY$是爱你 
你相信吗$HIW$ $HIM$我竟然经得起心痛的伤疤 $HIW$在那最后一刹 $HIR$你不经意间永远已替代他$NOR$\n",

"zhi":"$HIW$夜里难以入睡，用什麽可以麻醉，情绪太多怎堪面对，不是不要你陪
有些事$HIR$你$HIW$无法体会，卸下了防备，$HIM$孤独跟随$HIW$，我想要一个自己的空间
能够好好想想我们之间的明天，如果爱情不如我们想像的$HIM$甜美$HIW$，那麽
所有的罪让我来背$HIC$我的心太乱$HIW$，要一些空白，你若是明白，让我暂时
的离开我的心太乱，不敢再贪更多爱，想哭的我，却怎麽哭也哭不出
来我的心太乱，要一些空白，$HIC$老天在不在，$HIY$忘了为我来安排我的心太
乱，$HIR$害怕爱情的背叛$HIW$，想哭的我像是一个迷路小孩，“$HIC$迷路的小孩$HIW$”$NOR$\n"
]));
        set("exits", ([
                "out"  : "/u/bmw/chatroom",
                "down" : "/d/center/chat_room",
        ]));
        
        setup();
}