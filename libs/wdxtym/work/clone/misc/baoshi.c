#include <ansi.h>
inherit ITEM;
string *b_names = ({

  "细碎的红",
  "细碎的蓝",
  "细碎的绿",
  "细碎的青",
  "细碎的黄",
  "细碎的紫",
  "细碎的橙",
  "粗糙的红",
  "粗糙的蓝",
  "粗糙的绿", 
  "粗糙的青", 
  "粗糙的黄", 
  "粗糙的紫", 
  "粗糙的橙",  
  "标准的红",
  "标准的蓝",
  "标准的绿",
  "标准的青",
  "标准的黄",
  "标准的紫",
  "标准的橙",
  "精致的红",
  "精致的蓝",
  "精致的绿",
  "精致的青",
  "精致的黄",
  "精致的紫",
  "精致的橙",
  "完美的红",
  "完美的蓝",
  "完美的绿",
  "完美的青",
  "完美的黄",
  "完美的紫",
  "完美的橙",
});

mapping names = ([
  "细碎的红":       "broken red",
  "细碎的蓝":       "broken blue",
  "细碎的绿":       "broken green",
  "细碎的青":       "broken cyan",
  "细碎的黄":       "broken yellow",
  "细碎的紫":       "broken purple",
  "细碎的橙":       "broken orange",
  "粗糙的红":       "crude red",
  "粗糙的蓝":       "crude blue",
  "粗糙的绿":       "crude green",
  "粗糙的青":       "crude cyan",
  "粗糙的黄":       "crude yellow",
  "粗糙的紫":       "crude purple",
  "粗糙的橙":       "crude orange",
  "标准的红":       "standard red",
  "标准的蓝":       "standard blue",
  "标准的绿":       "standard green",
  "标准的青":       "standard cyan",
  "标准的黄":       "standard yellow",
  "标准的紫":       "standard purple",
  "标准的橙":       "standard orange",
  "精致的红":       "delicate red",
  "精致的蓝":       "delicate blue",
  "精致的绿":       "delicate green",
  "精致的青":       "delicate cyan",
  "精致的黄":       "delicate yellow",
  "精致的紫":       "delicate purple",
  "精致的橙":       "delicate orange",
  "完美的红":       "perfect red",
  "完美的蓝":       "perfect blue",
  "完美的绿":       "perfect green",
  "完美的青":       "perfect cyan",
  "完美的黄":       "perfect yellow",
  "完美的紫":       "perfect purple",
  "完美的橙":       "perfect orange",
]);

void setname()
{


    int i, j,k;

    string name,*kn,*id;

if (query("reward_lvl")>0) {
i=(query("b_lvl")-1)*7+query("reward_lvl")-1;
j=query("reward_lvl")-1;
}

if ( query("reward_lvl")<1){
k=random(1000);
       if(k>995){
        i=21+random(7);
        j=i-21;
        set("is_monitored", 1);
      }
else if(k>960){
        i=14+random(7);
        j=i-14;
        set("is_monitored", 1);
      }
else if(k>800){
        i=7+random(7);
        j=i-7;
        set("is_monitored", 1);
      }
else { i=random(7);
         j=i;}
}

     set("b_lvl",i/7+1);

        
    name=b_names[i]+"宝石";
    set("baoshi",b_names[i]);
    id=({names[b_names[i]]+" baoshi","baoshi"});
    set("reward_lvl",j+1);
    if(j==0){
    set_name(HIR+name+NOR,id); }
    if(j==1){
    set_name(HIB+name+NOR,id); }
    if(j==2){
    set_name(HIG+name+NOR,id); }
    if(j==3){
    set_name(HIC+name+NOR,id); }
    if(j==4){
    set_name(HIY+name+NOR,id); }
    if(j==5){
    set_name(HIM+name+NOR,id); }
    if(j==6){
    set_name(YEL+name+NOR,id); }
    if(j==7){
    set_name(YEL+name+NOR,id); }
}


void changename(object ob,int i)
{
    int j,k;
    string name,*id;
        i=i-1;

if(i>=28){
        j=i-28;
        ob->set("is_monitored", 1);
      }
else if(i>=21){
        j=i-21;
        ob->set("is_monitored", 1);
      }
else if(i>=14){
        j=i-14;
       ob->set("is_monitored", 1);
      }
else if (i>=7){
        j=i-7;
        ob->set("is_monitored", 1);
      }
else {  j=i;}

     ob->set("b_lvl",i/7+1);

    
    name=b_names[i]+"宝石";

    id=({names[b_names[i]]+" baoshi","baoshi"});

    ob->set("baoshi",b_names[i]);

    ob->set("reward_lvl",j+1);
    if(j==0){
    ob->set_name(HIR+name+NOR,id); }
    if(j==1){
    ob->set_name(HIB+name+NOR,id); }
    if(j==2){
    ob->set_name(HIG+name+NOR,id); }
    if(j==3){
    ob->set_name(HIC+name+NOR,id); }
    if(j==4){
    ob->set_name(HIY+name+NOR,id); }
    if(j==5){
    ob->set_name(HIM+name+NOR,id); }
    if(j==6){
    ob->set_name(YEL+name+NOR,id); }
    if(j==7){
    ob->set_name(YEL+name+NOR,id); }
}


void create(int i)
{
	setname();
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 2000000);
		set("unit","颗");
		set("color", HIM);  //HIB
		set("no_sell",1);
		set("long",HIM"一块发着闪闪发光的宝石，传说是女娲补天石的碎块,也不知道什么时候落入凡间的。\n"NOR);
	}
	setup();
}


void init()
{
    add_action("do_enchase", "enchase");
    add_action("do_enchase", "inset");
    add_action("do_combine", "combine");
}


int do_enchase(string arg)
{
   object in_obj;
   string item,str,mats;
   int rd,inset_num ,i,j,k;
   object me = this_player();
   object ob = this_object();

   if(!arg) return notify_fail("你要干什么？\n");



   if(sscanf(arg, "%s", item)!=1) return notify_fail("你要把宝石镶嵌到什么上？\n");


   if(!objectp(in_obj = present(item, me))) return notify_fail("你身上没有这样东西。\n");

   if( in_obj->query("equipped") )
      return notify_fail("你必须放下这样东西才能镶嵌宝石。\n");
//added by wuyou,lest one player inset baoshi in another player
   if( in_obj->is_character() )
      return notify_fail("你难道疯了，怎么能把宝石镶嵌到人身上？\n");
//   if( in_obj->query("no_zm")||in_obj->query_unique())
//      return notify_fail("这件装备不能镶嵌宝石。\n");
   i=ob->query("b_lvl")*7;
    if(i>28) k=15;
    else if(i>21) k=10;
    else if(i > 14) k=6;
    else if(i > 7) k=3;
    else k=1;
   j=ob->query("reward_lvl");
   mats = in_obj->query("material");       //装备或武器
   inset_num = in_obj->query("inset_num");  // 嵌了几个了
   if(!inset_num) inset_num = 1;
   else inset_num = inset_num + 1;
   if(inset_num > 5) return notify_fail(in_obj->query("name")+"上已经镶嵌了太多的宝石了!\n");

   if(!in_obj->query("weapon_prop/damage"))   //防具
  {     message_vision(CYN"$N把$n"+CYN"镶嵌到"+in_obj->query("name")+CYN"上 \n"NOR,me,ob);
       tell_room(environment(me),HIG"只见"+ob->name()+HIG"发出一团灿烂的金光,环绕在"+in_obj->query("name")+HIG"的周围 \n"NOR);
 //判断同类宝石
       if(j==1){
       in_obj->add("armor_prop/armor",k*2);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加坚实了！\n"NOR,me);
        }
       if(j==2){
       in_obj->add("armor_prop/strength",k);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加有力了！\n"NOR,me);
        }
       if(j==3){
       in_obj->add("armor_prop/qi",k*10);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加坚实了！\n"NOR,me);
        }
       if(j==4){
       in_obj->add("armor_prop/dexerity",k);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加轻盈了！\n"NOR,me);
         }
       if(j==5){
       in_obj->add("armor_prop/dodge",k*2);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎充满了灵性！\n"NOR,me);
        }
       if(j==6){
       in_obj->add("armor_prop/intelligence",k);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加轻盈了！\n"NOR,me);
        }
       if(j==7){
       in_obj->add("armor_prop/constitution",k);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加坚实了！\n"NOR,me);
        }

     //  me->add("bellicosity",1000);
       in_obj->set_weight(in_obj->query_weight()+500);
       in_obj->set("inset_num",inset_num);
       in_obj->set("no_sell",1);
       in_obj->add("inset_b",inset_num);  //装备b
       in_obj->set("name",HIG+in_obj->query("name")+NOR);

       if(!in_obj->query("old_long"))
         in_obj->set("old_long",in_obj->query("long"));

       if(!in_obj->query("old_ee"))
          in_obj->set("old_ee",ob->query("name"));

     else in_obj->set("old_ee",in_obj->query("old_ee")+" "+ob->query("name"));

       in_obj->set("long",in_obj->query("old_long")+"上面镶嵌了"+HIW+chinese_number(inset_num)+"颗宝石："+in_obj->query("old_ee")+"。\n"NOR);

       in_obj->save();
       destruct(ob);
       return 1;
}

else{
//武器
        message_vision(CYN"$N把$n"+CYN"镶嵌到"+in_obj->query("name")+CYN"上 \n"NOR,me,ob);
       tell_room(environment(me),HIG"只见"+ob->name()+HIG"发出一团灿烂的金光,环绕在"+in_obj->query("name")+HIG"的周围 \n"NOR);

       if(j==1){
       in_obj->add("weapon_prop/damage",k*2);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更有威力了！\n"NOR,me);
        }
       if(j==2){
       in_obj->add("weapon_prop/strength",k);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更有威力了！\n"NOR,me);
        }
       if(j==3){
       in_obj->add("weapon_prop/qi",k*10);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加坚实了！\n"NOR,me);
        }
       if(j==4){
       in_obj->add("weapon_prop/dexerity",k);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加轻盈了！\n"NOR,me);
         }
       if(j==5){
       in_obj->add("weapon_prop/dodge",k*2);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加轻盈了！\n"NOR,me);
        }
       if(j==6){
       in_obj->add("weapon_prop/intelligence",k);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎充满了灵性！\n"NOR,me);
        }
       if(j==7){
       in_obj->add("weapon_prop/constitution",k);
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加坚实了！\n"NOR,me);
        }

       if(k>20) {
       in_obj->set("material","diamond");
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加坚实了！\n"NOR,me);}


       in_obj->set_weight(in_obj->query_weight()+500);
       in_obj->set("no_sell",1);
       in_obj->set("inset_num",inset_num);
       in_obj->add("inset_b",inset_num);  //装备g
       in_obj->set("name",HIG+in_obj->query("name")+NOR);

       if(!in_obj->query("old_long"))
         in_obj->set("old_long",in_obj->query("long"));

       if(!in_obj->query("old_ee"))
          in_obj->set("old_ee",ob->query("name"));

     else in_obj->set("old_ee",in_obj->query("old_ee")+" "+ob->query("name"));

       in_obj->set("long",in_obj->query("old_long")+"上面镶嵌了"+HIW+chinese_number(inset_num)+"颗宝石："+in_obj->query("old_ee")+"。\n"NOR);
       in_obj->save();
       destruct(ob);
       return 1;
}

  return notify_fail("你镶嵌宝石失败了？\n");
}




int do_combine(string arg)
{

   int i,j;
    string name,*kn,*id;

   object me = this_player();
   object ob = this_object();
object ob2,ob3;

i=ob->query("b_lvl");
j=ob->query("reward_lvl")-1;

	if (!arg || arg == "")
		return notify_fail("你想合并什么宝石？\n");
	if (arg != ob->query("id")) return 0;
	if (ob->query("b_lvl") == 5)
		return notify_fail("这个宝石已经是最高等级了！\n");
	if (me->query("max_neili") < 500 || me->query("neili") < 800)
		return notify_fail("以你现在的内力修为，还无法运功合并宝石！\n");

//	ob = present(ob->query("id"), me);
	if ( !objectp(ob2= present(ob->query("id")+" 2", me)) )
		return notify_fail("你必须用三块"+ob->query("name")+"来合并。\n");
	if ( !objectp(ob3= present(ob->query("id")+" 3", me)) )
		return notify_fail("你必须用三块"+ob->query("name")+"来合并。\n");

if (random(100)>24){
				message_vision(HIM"$N把三块"+ob->query("name")+HIM"合在一起，暗运内力熔炼，但见"+ob->query("name")+HIM"表面异彩流动......\n"HIG"渐渐地$N收回了内力，"+ob->query("name")+HIG"似乎变得更加完美了！\n"NOR, me);
				me->add("max_neili", -10);
				me->add("neili", -500);
				me->start_busy(1);
	destruct(ob2);
	destruct(ob3);
	                  ob->set("b_lvl",i+1);

i=i*7+j;
    name=b_names[i]+"宝石";
    set("baoshi",b_names[i]);
    id=({names[b_names[i]]+" baoshi","baoshi"});

j=ob->query("reward_lvl")-1;

    if(j==0){
    set_name(HIR+name+NOR,id); }
    if(j==1){
    set_name(HIB+name+NOR,id); }
    if(j==2){
    set_name(HIG+name+NOR,id); }
    if(j==3){
    set_name(HIC+name+NOR,id); }
    if(j==4){
    set_name(HIY+name+NOR,id); }
    if(j==5){
    set_name(HIM+name+NOR,id); }
    if(j==6){
    set_name(YEL+name+NOR,id); }
    if(j==7){
    set_name(YEL+name+NOR,id); }

				return 1;
			
		}

	else {				message_vision(HIM"$N把三块"+ob->query("name")+HIM"合在一起，暗运内力熔炼，但见"+ob->query("name")+HIM"表面异彩流动......\n"HIW"只听“咔”的一声脆响，$N手中的"+ob->query("name")+HIW"变得粉碎！\n"NOR, me);

	destruct(ob2);
	destruct(ob3);
	destruct(ob);
			return 1;
   }
}

int query_autoload() { return 1; }
