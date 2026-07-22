
//power.h for power.c
#include <ansi.h>
mapping wide=([
"changan":"长安","luoyang":"洛阳","xiangyang":"襄阳",
"chengdu":"成都","baling":"巴陵","hefei":"合肥",
"jiujiang":"九江","yangzhou":"扬州","hangzhou":"杭州",
"xingyang":"荥阳","liyang":"黎阳","xucheng":"许城",
"pengliang":"彭梁","leshou":"乐寿","yuyang":"鱼阳",
"shanhaiguan":"山海关","taiyuan":"太原","mayi":"马邑",
"dingxiang":"定襄","saiwai":"塞外","suiye":"碎叶",
"tuyuhun":"土谷浑","gaoli":"高丽",]);

string check_wide(string w)
{
  if(!wide[w]) return "无此";
  return wide[w];
}

string get_power(int power)
{
   switch(power)
   {
    case 2: return "次级";break;
    case 3: return "中上级";break;
    case 4: return "中级";break;
    case 5: return "中下级";break;
    case 6: return "下级";break;
    case 7: return "下下级";break;
    case 8: return "最低级";break;
    default: return "没有任何级别";break;
   }
}

string get_leader(object ob)
{
  switch(ob->query("shili/leader"))
  {
    case "lifa_b": return HIW"李阀阀主"NOR;break;
    case "songjia_b": return HIW"宋家堡堡主"NOR;break;
    case "duzun_b": return HIW"独尊堡堡主"NOR;break;
    case "feima_b": return HIW"飞马牧场场主"NOR;break;
    case "dajiang_b": return HIW"大江联盟主"NOR;break;
    case "haisha_b": return HIW"海杀帮帮主"NOR;break;
    default: return HIR"神秘的帮主"NOR;
   }
}

string strleft(string msg,int blank)
{
while(strlen(msg)<blank)
	msg = msg+" ";

return msg;	
		
}

string str2left(string msg,int blank)
{
if(strlen(msg)%2!=0)
	msg = msg+" ";
while(strlen(msg)<blank)
	msg = msg+"━";

return msg;	
		
}