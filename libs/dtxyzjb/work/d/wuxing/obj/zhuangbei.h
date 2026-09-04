inherit F_SAVE;
inherit F_BACKUP;
#include <ansi.h>
#include "zshxrc.lpc"
#include "zwxrc.lpc"
#define USE 0
#define LVL 1
#define VALUE 2
#define NITEM 3
#define WORD 4

void initzhuangbei(object me,object ob,string name,string long,int damage)
{ 
            int lvl=0,type=0,zsh_xrc,zw_xrc,xrc,zshrd,zwrd,xrcrandom;
            int i,j,num,real_value,need_lvl=1;
            int better_chance;
            string color,c,ch,itemtype=ob->query("type/large");
            string *rdxrc;
                     set("no_sell",1);
                     set("need_lvl",1);
                     set("no_put",1);
//                     set("no_get",1);
                     set("newitem",1);
                     if (itemtype=="weapon") ch=itemtype+"_prop/damage";
                     else ch=itemtype+"_prop/armor";
                     itemtype=itemtype+"_prop/";
                     ob->set(ch,(int)damage/2);
            if (!me->query_temp("apply/better_chance")) better_chance=0; 
                else  better_chance=me->query_temp("apply/better_chance");
            lvl=(int)me->query("wuxing/level");
            xrcrandom=random(1000);
            if(xrcrandom<2*(50+((float)lvl)/10)*(1+((float)better_chance)/1000)) xrc=4;
            else if(xrcrandom<2*(60+((float)lvl)/5)*(1+((float)better_chance)/1000)) xrc=3;
            else if(xrcrandom<2*(80+((float)lvl)/2)*(1+((float)better_chance)/1000)) xrc=2;
            else if(xrcrandom<2*(130+lvl)*(1+((float)better_chance)/1000)) xrc=1;
            else xrc=0;
//          if(xrc>me->query_temp("wuxingyao/level")/10) xrc=me->query_temp("wuxingyao/level")/10;
          if (me->query_temp("wuxingyao/level")>40 && xrc>1 && random(2)==0)
           {
                     ob->set(ch,(int)(damage*1.5));
           xrc--;
           }
            if (xrc!=0) {
            zsh_xrc=random(xrc);
            zw_xrc=xrc-zsh_xrc;
            } else {
              zsh_xrc=0;
              zw_xrc=0;
            }
            switch (xrc){
               case 0:{   color=NOR;
                          break;
                                     }
               case 1:{   color=HIB;
                          break;
                                     }
               case 2:{   color=HIR;
                          break;
                                     }
               case 3:{   color=HIC;
                          break;
                                     }
               case 4:{   color=HIY;
                          break;
                                     }
                        }
            ob->set("name",color+name+NOR);
            ob->set("long",long);
            ob->set("xrc",xrc);
            ob->set("value",2000+lvl*1000+xrc*2000);
            num=ZSH_XRC_NUM;
            for(i=1;i<=zsh_xrc;i++)
            {
                j=random(num)+1;
                c="xrc/xrc"+(string)save_variable(i);
               rdxrc=zishou_xingrongci[j];
//              do{
               while ((ob->query("type/large")==rdxrc[NITEM]) ||
                         (me->query("wuxing/level")<(int)restore_variable(rdxrc[LVL])) )
                     { j=random(num)+1;
                       rdxrc=zishou_xingrongci[j];
                     }
               ch=itemtype+rdxrc[WORD];
//                 }while(ob->query(ch))
               real_value=(int) (((int)restore_variable(rdxrc[VALUE]))/2+random((int)restore_variable(rdxrc[VALUE])))+1;
               ob->add(ch,real_value);
               if (need_lvl<(int)restore_variable(rdxrc[LVL]))
                 need_lvl=(int)restore_variable(rdxrc[LVL]);
               ch=(string)save_variable(real_value);
               ob->set(c,HIM"加  "+HIW+ch+"  "+color+rdxrc[USE]+NOR);
            }  
            num=ZW_XRC_NUM;
            for(i=1;i<=zw_xrc;i++)
            {
                j=random(num)+1;
                c="xrc/xrc"+(string)save_variable(i+zsh_xrc);
               rdxrc=ziwei_xingrongci[j];
//              do{
               while ((ob->query("type/large")==rdxrc[NITEM]) ||
                         (me->query("wuxing/level")<(int)restore_variable(rdxrc[LVL])) )
                     { j=random(num)+1;
                       rdxrc=ziwei_xingrongci[j];
                     }
               ch=itemtype+rdxrc[WORD];
//                  }while(ob->query(ch));
               real_value=(int) (((int)restore_variable(rdxrc[VALUE]))/2+random((int)restore_variable(rdxrc[VALUE])))+1;
               ob->add(ch,real_value);
               if (need_lvl<(int)restore_variable(rdxrc[LVL]))
                 need_lvl=(int)restore_variable(rdxrc[LVL]);
               ch=(string)save_variable(real_value);
               ob->set(c,HIM"加  "+HIW+ch+"  "+color+rdxrc[USE]+NOR);
            }
            ob->set("need_lvl",need_lvl);
            return;
}
string query_save_file()
{
        string id, series;
              if (!query_temp("befabao")) return 0;
        id = query("owner_id");
        series = query("type/kind");
        if( !id || !series) return 0;

        return sprintf(DATA_DIR "fabao/%c/%s-%s", id[0], id, series);
}






int disappear()
{   call_out("dis",60);
   return 1;
}
int dis()
{   object ob=this_object();
  object where = environment();
  if (!userp(where))  {
     message_vision("$n渐渐消失了。\n",where,ob);
  destruct (ob);
     }
   return 1;
}
int first(object ob)
{
    object me=this_object();
    me->set("first/player",ob->query("id"));
    me->set("first/level",ob->query("wuxing/level"));
    if(wizardp(ob)) {
      me->set("no_give",1);
      me->set("no_drop",1);
    }
    return 1;
}

void init()
{
   add_action("do_xiang","inset");
}

int do_xiang(string arg)
{
   object ob,ob1,me=this_player();
   string ch,item;
   int i,max;
   if(!arg) return notify_fail("你要镶什么？\n");
   if(sscanf(arg,"%s to %s",arg,item)!=2) return notify_fail("xiang <物品> to <物品>\n");
   if(!ob=present(arg,me)) return notify_fail("你身上没有这样东西。\n");
   if(!ob1=present(item,me)) return notify_fail("你身上没有这样东西。\n");
   if(!ob->query("can_inset")) return notify_fail("这样东西不能镶。\n");
   if (!ob1->query("socketed")) return notify_fail("不能在这样东西上镶其他物品。\n");
   if (ob1->query("socketed_num")<=ob1->query("socketed_use/number")) return notify_fail("这样东西上已经镶了太多的东西。\n");
   ob1->add("socketed_use/number",1);
   switch(ob1->query("socketed_use/number")){
     case 1:ch="socketed_use/first";
       break;
     case 2:ch="socketed_use/second";
       break;
     case 3:ch="socketed_use/third";
       break;
     case 4:ch="socketed_use/fourth";
       break;
   }
   ob1->set(ch,ob->query("name"));
   switch(ob1->query("type/large")){
     case "armor":ch=ob->query("armor");
       max=ob->query("armor_max");
       break;
     case "weapon":ch=ob->query("weapon");
       max=ob->query("weapon_max");
       break;
   }
   i=random(max)+1;
   ch=ob1->query("type/large")+"_prop/"+ch;
   ob1->add(ch,i);
   switch(ob1->query("type/large")){
     case "armor":ch="armor_prop/armor";
       break;
     case "weapon":ch="weapon_prop/damage";
        if (max>30) i=i/10;
       break;
   }
   ob1->add(ch,i);
   message_vision("$N把一个"+ob->query("name")+"镶在了"+ob1->query("name")+"上。\n",me);
   ob1->save();
   destruct(ob);
   return 1;
}
