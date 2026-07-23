inherit ROOM;
#include <ansi.h>
inherit F_BACKUP;

int random_look()
{
string msg;
object me = this_player();
switch( random(5) )
        {
        case 1 :
                msg = HBBLU HIW+@LONG

        ∴°★．☆° ．★·°∴°★．° ．·。∴°              
        ☆ ．·°∴° ☆．．·°∴°．☆°★°∴°              
        °∴ 那怕星际无垠 ☆° ．·★°∴°．°°               
        ∴°．°★ ．·°∴°．°∴°．★☆° ．·              
        °．☆° ．★·我也要追到你 °．°°．★                
        ．·°∴★°．°∴°．☆° ．·°∴°．°               
        ．·°∴°★．°．∴·°°并永远爱你∴☆°              

LONG+NOR;
                msg = replace_string(msg,"∴",NOR HBBLU BLINK HIR"∴"NOR HBBLU HIW);
                msg = replace_string(msg,"°",NOR HBBLU BLINK WHT"°"NOR HBBLU HIW);
                msg = replace_string(msg,"★",NOR HBBLU BLINK HIY"★"NOR HBBLU HIW);
                msg = replace_string(msg,"。",NOR HBBLU BLINK HIG"。"NOR HBBLU HIW);
                msg = replace_string(msg,"．",NOR HBBLU BLINK HIB"．"NOR HBBLU HIW);
                break;
        case 2 :
                msg = BYEL BLK+@LONG

           .,,,,,,,,,,.                         
         ,;;;;;;;;;;;;;;,                       
       ,;;;;;;;;;;;)));;(((,,;;;,,_             
      ,;;;;;;;;;;'      |)))))))))))\\          
      ;;;;;;/ )''    - /,)))((((((((((\         
      ;;;;' \        ~|\  ))))))))))))))        
      /     /         |   ((((((((((((((        
    /'      \      _/~'    ')|()))))))))        
  /'         `\   />     o_/)))((((((((         
/          /' `~~(____ /  ()))))))))))          
|     ---,   \        \     ((((((((((          
          `\   \~-_____|      ))))))))          
            `\  |      |_.---.  \               

LONG+NOR;
                msg = replace_string(msg,"o",NOR BYEL BLINK HIY"o"NOR BYEL BLK);
                break;
        default :       
                msg = BBLU HIY+@LONG

::.--.-.::                                              
:( (    ):::::  东边日出西边雨                          
(_,  \ ) ,_)::  道是无晴却有情       |                  
:::-'--`--:::::::: ~~|     ,       \ _ /                
::::::::::::::::::: ,|`-._/|   -==  (_)  ==-            
::::::::^^::::::::.' |   /||\      /   \                
::::::^^::::::::.'   | ./ ||`\       |                  
:::::::::::::::/ `-. |/._ ||  \                         
::::::::::::::|      ||   ||   \                        
 ~~=~_~^~ =~ \~~~~~~~'~~~~'~~~~/~~`` ~=~^~              
~^^~~-=~^~ ^ `--------------'~^~=~^~_~^=~^~             

LONG+NOR;
                msg = replace_string(msg,"东边日出西边雨",NOR BBLU HIR"东边日出西边雨"NOR BBLU HIY);
                msg = replace_string(msg,"道是无晴却有情",NOR BBLU HIR"道是无晴却有情"NOR BBLU HIY);
                break;
        }
tell_object(me,msg);
return 1;
}

void create ()
{
set ("short", HIW"兔子"NOR YEL"窝"NOR);
set ("long",YEL"\n
深山深处的兔子窝，地下四通八达，不愧"NOR WHT"狡兔三窟"NOR YEL"的称号。
洞口长满了绿油油的"NOR HIG"青草"NOR YEL"，茁壮的向上生长着，显示着其
无比强烈的生命。人类与之比起，又算得了什么？\n
微风抚过，"NOR HIG"绿草"NOR YEL"们随风摆动，享受着它们短暂生命中难得
平静的谢意。
一缕"NOR HIC"阳光"NOR YEL"(light)透过"NOR HIG"青草"NOR YEL"射进洞中，映出斑影婆娑。\n\n
"NOR);
set("exits", ([ 
      "up" : "/d/wiz/wizroom",
        "kz" : "/d/city/kezhan",
        "wuxia" : "/c/playroom/wuxia",
]));
set("objects",([
 "/d/city/npc/vikee"  : 1,
"/d/wiz/obj/gift" : 1,
]));
set("item_desc",([
        "light" : (: random_look :),
]));


set("outdoors", "changan");
set("chat_room",1);
set("no_time",1);
set("mai_corpse_able",1);
set("freeze", 1); 
set("if_bed",1);
set("sleep_room",1);
set("no_upgrade_age",1);
set("valid_startroom", 1);
set("hs_world",1);
set("no_clean_up",1);
setup();
call_other("/d/snowtu/obj/bbs_snowtu", "???");
}

int do_test()
{
mapping temp = ([
      "MUDLIB" : "SanJie",
      "ENCODING" : "GB",
      "PORTUDP" : "6670",
      "USERS" : "45",
      "TCP" : "all",
      "HTTP" : "建设中...",
      "TIME" : "Tue Feb  7 23:07:09 2006",
      "ADM_EMAIL" : "snowtu@163.com",
      "PORT" : "6666",
      "ALIAS" : "SanJie",
      "HOST" : "dns",
      "NAME" : "SanJie",
      "HOSTADDRESS" : "221.215.46.34",
      "VERSION" : "天上人间 V3.0",
      "DRIVER" : "MudOS v22pre11",
      "MUDNAME" : "三界神话",
      "MUD_WEB" : "www.yangshuo.net/bbs",

]);
("/adm/daemons/network/dns_master.c")->set_mud_info("SanJie",temp);
temp = ("/adm/daemons/network/dns_master.c")->query_muds();
set("mudlist",temp);
return 1;
}

int do_set(string arg)
{
if ( !wizardp(this_player()) )  return 0;
if ( !arg || ( arg!="string" && arg!="int" ) ) return 0;
write(NOR HIY BLK"\n\t\t\t修改模式设置为"+arg+"\n"NOR);
set("edit_type",arg);
return 1;
}
void init()
{
add_action("do_xiugai","xiugai");
add_action("do_set","set");
add_action("do_kill","kill");
add_action("do_test","test");
add_action("do_clr","clr");
}

int do_xiugai(string arg)
{
string id,data;
string type;
object who,me = this_player();
mixed temp;
if ( !wizardp(me) )  return 0;
type = query("edit_type");
if ( !type || !stringp(type) || (type!="int" && type!="string") )
         return notify_fail("先set一下吧。\n");
if ( type=="string" )
       {
       if ( sscanf(arg,"%s %s %s",id,data,temp)!=3 )
              return notify_fail("格式 xiugai <id> <data> <数据> \n"); 
       temp = SDS_D->color_msg(temp);
       }
else   {
       if ( sscanf(arg,"%s %s %d",id,data,temp)!=3 )
              return notify_fail("格式 xiugai <id> <data> <数据> \n"); 
       }
who = find_player(id);
if ( !who )   return notify_fail("没有这个人。\n");
who->set(data,temp);
if ( data=="cloth_name" )  {
   object cloth = present("sheng yi",who);
   if ( cloth )  { cloth->set("name",temp+NOR HIC"座"HIY"黄金圣衣"NOR);cloth->save(); }
   }
write(who->query("id")+"的"+data+"修改为"+temp+"\n");
who->save();
return 1;
}

int do_kill(string arg)
{
object me = this_player();
object who;
if ( !arg || !wizardp(me) )  return 0;
who = present(arg,this_object());
if ( !who )  return 0;
who->kill_ob(me);
me->kill_ob(who);
return 1;
}

int do_clr()
{
object *us = users();
int i;
object cc;
for(i=0;i<sizeof(us);i++)
      {
      cc = present("card",us[i]);
      if ( cc )  destruct(cc);
      }
return 1;
}

void valid_move(object who)
{
if ( who->query("env/no_move") )
      {
      who->move(this_object());
      }
}
