//make bye stey
#include <ansi.h>
inherit ITEM;
string *b_names = ({

  "红",
  "蓝",
  "绿",
  "青",
  "黄",
  "紫",
  "橙",
  "玛瑙", 
  "翡翠", 
  "沉玉", 
  "水晶", 
  "金沙", 
  "猫眼", 
  "钻石", 
  "神之玛瑙",
  "神之翡翠",
  "神之沉玉",
  "神之水晶",
  "神之金沙",
  "神之猫眼",
  "神之钻石",
  "旭日",
  "天空",
  "森林",
  "海洋",
  "火焰",
  "晚霞",
  "沙漠",
  "正之光",
  "慈之光",
  "地之光",
  "海之光",
  "火之光",
  "佛之光",
  "爱之光",
});

mapping names = ([

  "红":       "hong",
  "蓝":       "blue",
  "绿":       "green",
  "青":       "qing",
  "黄":       "huang",
  "紫":       "zi",
  "橙":       "cheng",
  "玛瑙":     "manao",
  "翡翠":     "feicui",
  "沉玉":     "chengyu",
  "水晶":     "shuijing",
  "金沙":     "jinsha",
  "猫眼":     "maoyan",
  "钻石":     "zuanshi",
  "神之玛瑙":  "god manao",
  "神之翡翠":  "god feicui",
  "神之沉玉":  "god chengyu",
  "神之水晶":  "god shuijing",
  "神之金沙":  "god jinsha",
  "神之猫眼":  "god maoyan",
  "神之钻石":  "god zuanshi",
  "旭日":      "sun",
  "天空":      "sky",
  "森林":      "forest",
  "海洋":      "sea",
  "火焰":      "fire",
  "晚霞":      "sunshine",
  "沙漠":      "sand",
  "正之光":    "justice light",
  "慈之光":    "mercy light",
  "地之光":    "earth light",
  "海之光":    "sea light",
  "火之光":    "fire light",
  "佛之光":    "gods light",
  "爱之光":    "love light",
]);




void setname()
{
    int i, j,k;

    string name,*kn,*id;
    k=random(1000);
 //   i=(random(sizeof(names4)/2))*2;
       if(k>995){
        i=21+random(7);
        j=i-21;
        set("is_monitored", 1);
    }else if(k>960){
        i=14+random(7);
        j=i-14;
        set("is_monitored", 1);
      }else if (k>800)
         { i=7+random(7);
         j=i-7;
         set("is_monitored", 1);
        }else
        { i=random(7);
        j=i;}
     set("b_lvl",i+1);

        
    name=b_names[i]+"宝石";
    set("baoshi",b_names[i]);
    id=({names[b_names[i]]+" baoshi","baoshi"});
    set("reward_lvl",j+1);
    if(j==0){
           set_name(BLINK+HIR+name+NOR,id); }
    if(j==1){
    set_name(BLINK+HIB+name+NOR,id); }
    if(j==2){
    set_name(BLINK+HIG+name+NOR,id); }
    if(j==3){
    set_name(BLINK+HIC+name+NOR,id); }
    if(j==4){
    set_name(BLINK+HIY+name+NOR,id); }
    if(j==5){
    set_name(BLINK+HIM+name+NOR,id); }
    if(j==6){
    set_name(BLINK+YEL+name+NOR,id); }
    if(j==7){
    set_name(BLINK+YEL+name+NOR,id); }
}
void changename(object ob,int i)
{
    int j,k;
    string name,*id;
        i=i-1;
          if(i>=28){

        j=i-28;
        ob->set("is_monitored", 1);
      }else if(i>=21){

        j=i-21;
        ob->set("is_monitored", 1);
      }else if(i>=14){

        j=i-14;
       ob->set("is_monitored", 1);
      }else if (i>=7)
         {
         j=i-7;
         ob->set("is_monitored", 1);
        }else
        {
        j=i;}
     ob->set("b_lvl",i+1);

    
    name=b_names[i]+"宝石";

    id=({names[b_names[i]]+" baoshi","baoshi"});

    ob->set("baoshi",b_names[i]);

    ob->set("reward_lvl",j+1);

    if(j==0){
    ob->set_name(BLINK+HIR+name+NOR,id); }
    if(j==1){
    ob->set_name(BLINK+HIB+name+NOR,id); }
    if(j==2){
    ob->set_name(BLINK+HIG+name+NOR,id); }
    if(j==3){
    ob->set_name(BLINK+HIC+name+NOR,id); }
    if(j==4){
    ob->set_name(BLINK+HIY+name+NOR,id); }
    if(j==5){
    ob->set_name(BLINK+HIM+name+NOR,id); }
    if(j==6){
    ob->set_name(BLINK+YEL+name+NOR,id); }
    if(j==7){
    ob->set_name(BLINK+YEL+name+NOR,id); }
}
void create(int i)
{
        setname();
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
       set("value", 2000000);
 //               set("is_monitored", 1);
                set("unit","颗");
                set("color", HIB);  //HIB
//                set("no_put",1);
                set("no_sell",1);
                set("long",HIB"一块发着闪闪发光的宝石，传说是女娲补天石的碎块,也不知道什么时候落入凡间的。\n"NOR);
        }
        setup();
}


void init()
{

    add_action("do_enchase", "enchase");
    add_action("do_enchase", "inset");
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
   i=ob->query("b_lvl");
    if(i>28) k=7;
    else if(i>21) k=5;
    else if(i > 14) k=3;
    else if(i > 7) k=2;
    else k=1;
    j=ob->query("reward_lvl");
   mats = in_obj->query("material");       //装备或武器
   inset_num = in_obj->query("inset_num");  // 嵌了几个了
   if(!inset_num) inset_num = 1;
   else inset_num = inset_num + 1;
   if(inset_num > 6) return notify_fail(in_obj->query("name")+"上已经镶嵌了太多的宝石了!\n");

   if(!in_obj->query("weapon_prop/damage"))   //防具
  {

       message_vision(CYN"$N把$n"+CYN"镶嵌到"+in_obj->query("name")+CYN"上 \n"NOR,me,ob);
       tell_room(environment(me),HIG"只见"+ob->name()+HIG"发出一团灿烂的金光,环绕在"+in_obj->query("name")+HIG"的周围 \n"NOR);
 //判断同类宝石
      if(j==1){
       in_obj->add("armor_prop/dodge",k*2+random(k*5));

       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加轻盈了！\n"NOR,me);
             }
        if(j==2){
       in_obj->add("armor_prop/spell",k*2+random(k*5));

       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加充满灵性了！\n"NOR,me);
        }
        if(j==3){
       in_obj->add("armor_prop/armor",k*2+random(k*5));

       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加坚实了！\n"NOR,me);
        }
        if(j==4){
      in_obj->add("armor_prop/dodge",k*2+random(k*5));

       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加轻盈了！\n"NOR,me);
              }
           if(j==5){

        in_obj->add("armor_prop/spell",k*2+random(k*5));

       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加充满灵性了！\n"NOR,me);
      }
         if(j==6){
       in_obj->add("armor_prop/dodge",k*2+random(k*5));

       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加轻盈了！\n"NOR,me);
        }
        if(j==7){
        in_obj->add("armor_prop/armor",k*2+random(k*5));

       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加坚实了！\n"NOR,me);
        }
     //  me->add("bellicosity",1000);
       in_obj->set_weight(in_obj->query_weight()+1000);

       in_obj->set("inset_num",inset_num);
       in_obj->set("no_sell",1);
       in_obj->add("inset_b",inset_num);  //装备b
       in_obj->set("name",HIG+in_obj->query("name")+NOR);
       if(!in_obj->query("old_long"))
         in_obj->set("old_long",in_obj->query("long"));

       if(!in_obj->query("old_ee"))
          in_obj->set("old_ee",ob->query("name"));
          else in_obj->set("old_ee",in_obj->query("old_ee")+" "+ob->query("name"));

       in_obj->set("long",in_obj->query("old_long")+"上面嵌上了"+HIW+chinese_number(inset_num)+"颗宝石:"+in_obj->query("old_ee")+"。\n"NOR);

       in_obj->save();
       destruct(ob);
       return 1;
}else{
//武器
        message_vision(CYN"$N把$n"+CYN"镶嵌到"+in_obj->query("name")+CYN"上 \n"NOR,me,ob);
       tell_room(environment(me),HIG"只见"+ob->name()+HIG"发出一团灿烂的金光,环绕在"+in_obj->query("name")+HIG"的周围 \n"NOR);

         message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加灵气活现了！\n"NOR,me);
       if(k>2) {
        in_obj->set("material","diamond");
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加坚实了！\n"NOR,me);}
       in_obj->add("weapon_prop/damage",k*2+random(k*5));
       in_obj->add("weapon_prop/intelligence",k*2+random(k*5));
       in_obj->set_weight(in_obj->query_weight()+1000);
       in_obj->set("no_sell",1);
       in_obj->set("inset_num",inset_num);
       in_obj->add("inset_b",inset_num);  //装备g
       in_obj->set("name",HIG+in_obj->query("name")+NOR);
       if(!in_obj->query("old_long"))
         in_obj->set("old_long",in_obj->query("long"));

       if(!in_obj->query("old_ee"))
          in_obj->set("old_ee",ob->query("name"));
          else in_obj->set("old_ee",in_obj->query("old_ee")+" "+ob->query("name"));

       in_obj->set("long",in_obj->query("old_long")+"上面嵌上了"+HIW+chinese_number(inset_num)+"颗宝石:"+in_obj->query("old_ee")+"。\n"NOR);
       in_obj->save();
       destruct(ob);
       return 1;
}



  return notify_fail("你镶嵌宝石失败了？\n");
}



