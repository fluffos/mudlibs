#include <ansi.h>
#ifndef __JOB_INFO_H__
#define __JOB_INFO_H__

string *outer_gate_name = ({HIY"永安门"NOR, HIY"左安门"NOR, HIY"右安门"NOR, HIY"广安门"NOR,
         HIY"广渠门"NOR, HIY"西便门"NOR, HIY"东便门"NOR, HIY"阜成门"NOR,
         HIY"朝阳门"NOR, HIY"西直门"NOR, HIY"东直门"NOR, HIY"安定门"NOR,
	 HIY"德胜门"NOR,});


string *inner_gate_name = ({HIY"正阳门"NOR, HIY"宣武门"NOR, HIY"地安门"NOR, HIY"北海西门"NOR,
		HIY"崇文门"NOR, HIY"景山"NOR });

mapping info_beauty = ([
"白衣少女": 10 + random(40),
"门卫": 10 + random(40),
"陪练童子": 10 + random(40),
"老材": 10 + random(40),
"流氓": 10 + random(40),
"流氓头": 10 + random(40),
"家丁": 10 + random(40),
"镖头": 10 + random(40),
//"老顾": 10 + random(40),
"老仆": 10 + random(40),
"地痞": 10 + random(40),
"小流氓": 10 + random(40),
"李铁嘴": 10 + random(40),
"翠花": 10 + random(40),
"王小二": 10 + random(40),
HIW"厚土旗众"NOR: 10 + random(40),
BLU"洪水旗众"NOR: 10 + random(40),
YEL"锐金旗众"NOR: 10 + random(40),
YEL"巨木旗众"NOR: 10 + random(40),
YEL"烈火旗众"NOR: 10 + random(40),
"小妾": 10 + random(40),
"萍水逢": 10 + random(40),
"婆子": 10 + random(40),
"日月教众": 10 + random(40),
"鲍大楚": 10 + random(40),
"小喽罗": 10 + random(40),
"土匪": 10 + random(40),
"小土匪": 10 + random(40),
"星宿派号手": 10 + random(40),
"星宿派鼓手": 10 + random(40),
"星宿派钹手": 10 + random(40),//31

"舞蛇人": 50 + random(100),
"教头": 50 + random(100),
"管家": 50 + random(100),
"小青": 50 + random(100),
"王五": 50 + random(100),
"海公公": 50 + random(100),
"丁坚": 50 + random(100),
"崔员外": 50 + random(100),
"倭寇": 50 + random(100),
HIC"东瀛武士"NOR: 50 + random(100),
"东瀛浪人": 50 + random(100),
"公子哥": 50 + random(100),
"剑客": 50 + random(100),
"刀客": 50 + random(100),
"李四": 50 + random(100),
"庄丁": 50 + random(100),
"阿善": 50 + random(100),
"辛然": 50 + random(100),
"颜垣": 50 + random(100),
"闻苍松": 50 + random(100),
"庄铮": 50 + random(100),
"唐洋": 50 + random(100),
"亲兵": 50 + random(100),
"吴应雄": 50 + random(100),
"浪人头目": 50 + random(100),
"童百熊": 50 + random(100),
"农夫": 50 + random(100),
"土匪头": 50 + random(100),
"打手": 50 + random(100),
"黑老板": 50 + random(100),
"阿紫": 50 + random(100),
"出尘子": 50 + random(100),
"采花子": 50 + random(100),
"巴依": 50 + random(100),
"霍都": 50 + random(100),
RED"土匪头"NOR: 50 + random(100),
BLK"土匪"NOR: 50 + random(100),//68

"欧阳克": 80 + random(150),
"丹青生": 80 + random(150),
"秃笔翁": 80 + random(150),
"黑白子": 80 + random(150),
"田伯光": 80 + random(150),
"梅超风": 80 + random(150),
"陈玄风": 80 + random(150),
"韦一笑": 80 + random(150),
"黛绮丝": 80 + random(150),
"殷天正": 80 + random(150),
"亲兵头": 80 + random(150),
"浪回头": 80 + random(150),
"包打听": 80 + random(150),
"李莫愁": 80 + random(150),
"曲洋": 80 + random(150),
"上官云": 80 + random(150),
"张三": 80 + random(150),
"天狼子": 80 + random(150),
"狮吼子": 80 + random(150),
"摘星子": 80 + random(150),
RED"土匪"NOR: 80 + random(150),//89

HIR"秦桧"NOR: 120 + random(220),
"黄钟公": 120 + random(220),
"秦伟邦": 120 + random(220),
"护院武师": 120 + random(220),
"向问天": 120 + random(220),
"丁春秋": 120 + random(220),//95
]);
string query_beauty(int num)
{
        int i;
        string *beautys = keys(info_beauty);
        i = sizeof(info_beauty);
        command("say " + i);
        for (i = sizeof(beautys); i > 0; i--)
        command("say " + beautys[i - 1] + i);
        return beautys[random(num)];
}
#endif
