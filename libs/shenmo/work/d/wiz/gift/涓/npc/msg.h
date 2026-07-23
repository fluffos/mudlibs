/*********************************
**      中秋礼物·祝贺语                **
**              msg.h           **
*********************************/

#include <ansi.h>

string random_msg()
{
string w_name,w_id,*str,msg,name,id,arg1,arg2;
mapping wiz_msg = ([
        "乱"            :       "run",
        "开心汤姆"      :       "tom",
        "风琴"          :       "yhq",
]);
switch(random(4))
        {
        case 0:
                msg = @LONG
┏━┓         \ /         ┏━┓  %s(%s)
┃中┃      恭祝发财       ┃乐┃  祝
┗━┛| ┏━┓ / \ ┏━┓ |┗━┛  %s(%s)
     -o-┃秋┃     ┃快┃-o-       %s
  +   | ┗━┛  *  ┗━┛ |  +     %s
LONG;
                break;
        case 1:
                msg = @LONG
　.╭╮︵☆╭╮.`╔═══╦═══╦═══╗ .`.`
　.〔　o　o　〕╭中╮ `╭秋╮ `╭快╮  ╭乐╮.
　.〔ミ О ミ〕.╲╱.`. ╲╱.`. ╲╱    ╲╱ .`.
　〔︵灬　灬︵〕%s(%s)祝%s(%s)%s%s
LONG;
                break;
        case 2:
                msg = @LONG
  ▇▇▇▇ .  %s(%s)祝%s(%s)
◢▇▇▇▇◣
▇中秋快乐▇      %s
◥▇▇▇▇◤      %s
  ▇▇▇▇ .
   | | |
LONG;
                break;
        default:
                msg = @LONG
╔♂╗┏┯┓┏┯┓┏┯┓┏┯┓╔♀╗
┃★┃┠中┨┠秋┨┠快┨┠乐┨┃☆┃
┃☆┃┗┷┛┗┷┛┗┷┛┗┷┛┃★┃
╚♂╝↘*≡年≡年≡如≡意≡*↙╚♀╝
%s(%s)祝%s(%s)%s%s
LONG;
        }
str = keys(wiz_msg);
w_name = str[random(sizeof(str))];
w_id = wiz_msg[w_name];
name = this_player()->query("name");
id = this_player()->query("id");
str = @@STR
身体健康
吉祥顺心
前途似锦
一帆风顺
万事如意
中秋快乐
岁岁平安
STR;
arg1 = str[random(sizeof(str))];
do      {
        arg2 = str[random(sizeof(str))];
}while(arg1==arg2);

msg = HIM"\n"+msg+NOR"\n";
msg = sprintf(msg,HIY+w_name+NOR+HIM,HIY+capitalize(w_id)+NOR+HIM,HIG+name+NOR+HIM,HIG+capitalize(id)+NOR+HIM,HIC+arg1+NOR+HIM,HIC+arg2+NOR+HIM);
msg = replace_string(msg,"中",NOR+BLINK+WHT"中"NOR HIM);
msg = replace_string(msg,"秋",NOR+BLINK+WHT"秋"NOR HIM);
msg = replace_string(msg,"快",NOR+BLINK+WHT"快"NOR HIM);
msg = replace_string(msg,"乐",NOR+BLINK+WHT"乐"NOR HIM);
msg = replace_string(msg,"☆",NOR+BLINK+HIR"☆"NOR HIM);
msg = replace_string(msg,"★",NOR+BLINK+RED"★"NOR HIM);
msg = replace_string(msg,".",NOR+BLINK+MAG"."NOR HIM);

return msg;
}
