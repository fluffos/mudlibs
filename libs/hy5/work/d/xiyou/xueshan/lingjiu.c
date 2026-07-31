#include <ansi.h>
inherit ROOM;

string *fo=({
HIW"阿弥陀佛"NOR,
HIC"无量寿佛"NOR,
WHT"金刚不坏佛"NOR,
WHT"宝光佛"NOR,
WHT"龙尊王佛"NOR,
HIC"精进善佛"NOR,
HIC"宝月光佛"NOR,
HIC"现无愚佛"NOR,
HIM"婆留那佛"NOR,
HIM"那罗延佛"NOR,
HIM"功德华佛"NOR,
HIY"才功德佛"NOR,
HIY"善游步佛"NOR,
HIY"旃檀光佛"NOR,
HIG"摩尼幢佛"NOR,
HIG"慧炬照佛"NOR,
HIG"海德光明佛"NOR,
HIR"大慈光佛"NOR,
HIR"慈力王佛"NOR,
HIR"贤善首佛"NOR,
HIB"广主严佛"NOR,
HIB"金华光佛"NOR,
HIB"才光明佛"NOR,
WHT"智慧胜佛"NOR,
WHT"世静光佛"NOR,
CYN"日月光佛"NOR,
CYN"日月珠光佛"NOR,
MAG"慧幢胜王佛"NOR,
MAG"妙音声佛"NOR,
YEL"常光幢佛"NOR,
YEL"观世灯佛"NOR,
GRN"法胜王佛"NOR,
GRN"须弥光佛"NOR,
RED"大慧力王佛"NOR,
RED"金海光佛"NOR,
BLU"大通光佛"NOR,
BLU"才光佛"NOR
});

string *msg=({
"我闻佛音声，世所未曾有，所言真实者，应当修供养。",
"仰惟佛世尊，普为世间出，亦应垂哀愍，必令我得见。",
"即生此念时，佛于空中现，普放净光明，显示无比身。",
"胜鬘及眷属，头面接足礼，咸以清净心，叹佛实功德。",
"如来妙色身，世间无与等，无比不思议，是故今敬礼。",
"如来色无尽，智慧亦复然，一切法常住，是故我归依。",
"降伏心过恶，及与身四种，已到难伏地，是故礼法王。",
"知一切尔焰，智慧身自在，摄持一切法，是故今敬礼。",
"敬礼过称量，敬礼无譬类，敬礼无边法，敬礼难思议。",
"哀愍覆护我，令法种增长，此世及后生，愿佛常摄受。",
"我久安立汝，前世已开觉，今复摄受汝，未来生亦然。",
"我已作功德，现在及余世，如是众善本，惟愿见摄受。"
});


void create ()
{
        set ("short", HIW"灵鹫洞"NOR);
        set ("long", HIW @LONG

整个山洞都是白雪堆积而成，周围除了白色还是白色，你来到这里，
心里感到前所未有的清净，不愧为佛家修炼的无上宝境，据说当年如
来佛祖就是在这里修炼成丈六金身的。
LONG
HIW);
        set("exits",
        ([
                "down" : __DIR__"no4-enter",
        ]));
       set("objects", ([ /* sizeof() == 2 */ 
           "/d/xiyou/xueshan/npc/jianan" : 1, 
        ])); 

   set("no_fight", 1);
   set("no_magic", 1);

    setup();
}

