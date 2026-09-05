inherit ITEM;
#include <ansi.h>

mapping score=([
        "str"           : "膂力",
        "dex"           : "身法",
        "int"           : "悟性",
        "spi"           : "灵性",
        "per"           : "容貌",
        "con"           : "根骨",
        "kar"           : "福缘",
]);
string helpmsg=(@HELP

Merry Xmas and Happy new Year!
北侠wiz祝你：

 ╭…………………………………………………╮
 ┇  ┈┈   ╭┈┈╮  ┊┈┼╮ ╭┄┄  北┇
 ┇┈┈┈┈ ┊┈┈┊┊├  ┊┊ ┊┊    大┇
 ┇  ┊┊   ╰┈┈╯  ┊┈┼┴ ┴┼┈  侠┇
 ┇┈╯╰┈ ┈┈┈┈  ╯┈╯╯ ╯╯╰  客┇
 ┇H A P P Y  N E W - Y E A R  2 0 0 8 行┇
 ╰…………………………………………………╯


同时也祝你在新年里，心想事成，事事如意。

巫师为您准备了丰厚的礼物,分为9种类型,可以随意挑选。
礼赞的使用方法是:choose 类型(1-9)，比如“choose 1”选择礼物为经验。
1       经验（可以获得30w经验）
2       声望（可以获得10w声望）
3       潜能（可以获得15w潜能）
4       金钱（可以获得2000黄金的存款）
5       等级（可以提高等级1到3级）
6       天赋（可以随机增加一项天赋3点）
7       忠诚（增加门忠2000，有很小的几率减少一次判师记录）
8       特技（有四分之一几率获得一个不会的特技）
9       内力（1000点最大内力和1000点最大精力）
HELP
     );
string pic=(@TEXT
 ╭…………………………………………………╮
 ┇  ┈┈   ╭┈┈╮  ┊┈┼╮ ╭┄┄  北┇
 ┇┈┈┈┈ ┊┈┈┊┊├  ┊┊ ┊┊    大┇
 ┇  ┊┊   ╰┈┈╯  ┊┈┼┴ ┴┼┈  侠┇
 ┇┈╯╰┈ ┈┈┈┈  ╯┈╯╯ ╯╯╰  客┇
 ┇H A P P Y  N E W - Y E A R  2 0 0 8 行┇
 ╰…………………………………………………╯
TEXT
    );

void create()
{
        set_name(HIM"新年礼赞"NOR, ({"new-year bless", "bless"}));
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIW"一片温馨的祝福,愿在这寒冬中带给您温暖的喜悦。\n"NOR);
                set("unit", "片");
        }
                set("no_sell",1);
                set("no_put",1);
                set("no_drop",1);
}
void init()
{
    add_action("choose_gift","choose");
    add_action("show_gift","confirm");
}

int choose_gift(string arg)
{
  object me;
  string str;
  int pattern,splits,points,points2;

  if(!me=this_player()) return 0;
  if(me->query("combat_exp")<100815) 
      return notify_fail("至少需要100815经验才能领礼物，赶紧去练功吧，农历新年前一直有效。\n");
  if(me->query("age")<15) 
  	  return notify_fail("至少需要16岁才能领礼物。\n");
  if(query("owner")!=me->query("id") && !wizardp(me) ) 
  	  return notify_fail(":-(,这样可不好哦，你拿的是别人的礼赞!\n");
  if(!arg) 
  	  return notify_fail(helpmsg);
  if(me->query("gift/xmas")>0) 
      return notify_fail(":->,你已经要过礼物了！\n");	
  if(sscanf(arg,"%d",pattern)!=1) 
      return notify_fail(helpmsg);
  if(pattern<1 || pattern>9 ) 
  	  return notify_fail("注意：只有九种选择!\n");

   me->set_temp("ny_pattern",pattern);
   me->set_temp("ny_choosed",1);
   write("您选择礼物设定为第"+pattern+"种选择,确定请输入confirm,您也可以重新选择.\n");
   
   return 1;
}
int show_gift()
{
  int pattern,splits,points,point,i;
  object gift,me;
  int mylvl;
  string *ss=({ 
    "corporeity","ironskin","health","energy","chainless","sociability","greedy","agile",
    "might","spirituality","athanasy","intellect","constitution","perceive","lucky"
   });
  if(!me=this_player()) return 0;
  if(!me->query_temp("ny_choosed")) return 0;
  if(!(int)pattern=me->query_temp("ny_pattern") || !(int)splits=me->query_temp("ny_splits"))
         return notify_fail("你需要重新选择.\n");
  
   me->delete_temp("ny_pattern");
   me->delete_temp("ny_choosed");


  switch(pattern)
  {
     case 1://combat_exp
     {
      me->add("combat_exp",300000);
      write("你选择了经验,你的经验增加了300000点!\n");
      break;
     }
     case 2://repute
     {
        me->add("repute",100000);
        write("你选择了声望,你的增加了100000点!\n");
        break;
     }
     case 3://pot
     {
       me->add("potential",150000);
       write("你选择了潜能,你的潜能增加了150000点!\n");
       break;
     }
     case 4://balance
     {
       if(me->query("combat_exp")<1000000) 
          return notify_fail("1M以上才可以要金钱的礼物!你可以选择其他的礼物\n");
       me->add("balance",2000*10000);
       write("你选择了金钱,你的存款增加了2000两!\n");
       break;
     }
     case 5://level
     {
     	   if (me->query("level")<50)
           me->add("level",3);
         else if (me->query("level")<60)
           me->add("level",2);
         else
           me->add("level",1);
         write("你选择了等级，你的等级提高了！\n");
         break;
     }
     case 6://attribute
     {
       i=random(sizeof(score)-1);
       me->add(keys(score)[i],3);
       write("你选择了天赋,你的"+values(score)[i]+"增加了3点!\n");
       break;
     }

     case 7://others,score,betrayer
     {
       me->add("score",2000);
       write("你的忠诚度增加了!\n");

       if(!random(5) && me->query("betrayer")>2){
       me->add("betrayer",-1);
       write("你减少了一次判师记录！\n");
       shout(HIY"【江湖传闻】"+me->query("name")+"中得大奖，减少判师记录一次。\n"NOR);
       }
       break;
     }
     case 8://specail skill
     {
       if(me->query("combat_exp")<3000000) 
       	  return notify_fail("3M以上才可以要特技的礼物!你可以选择其他的礼物\n");
       if(random(4)) 
       	{
       	  write(HIY"不好意思，你的运气非常不好，没有抽中!\n"NOR);
       	}
       else
       	{
          if(me->query("special_skill")) ss=ss-keys(me->query("special_skill"));
          i=random(sizeof(ss)-1);
          me->set("special_skill/"+ss[i],1);
          write(HIR"恭喜你!你获得了一项新的特殊技能:"+ss[i]+"\n\n"NOR);
          shout(HIY"【江湖传闻】"+me->query("name")+"中得大奖，获得了一项新的特殊技能"+ss[i]+"。\n"NOR);
        }
        break;
      }
     case 9://neili,jingli
     	{
        me->add("max_neili",1000);
        me->add("max_jingli",1000);
     		write(HIY"你的内力和精力增加了!\n"NOR);
     		break;
     	}
     }
      me->delete_temp("ny_pattern");
      me->delete_temp("ny_choosed");
      me->set("gift/xmas",1);
      me->save();
      tell_object(me,"北侠wiz祝福你：\n");
      tell_object(me,HIM+"\n"+pic+"\n"NOR);
      return 1;
}

