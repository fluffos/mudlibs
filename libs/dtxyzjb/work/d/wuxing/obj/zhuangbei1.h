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
            int lvl=0,type=0,zsh_xrc,zw_xrc,xrc,zshrd,zwrd;
            int i,j,num,real_value,need_lvl;
            int better_chance;
            string color,c,ch,itemtype=ob->query("type/large");
            string *rdxrc;
                     set("no_sell",1);
                     set("need_lvl",1);
                     set("no_put",1);
//                     set("no_get",1);
                     set("newitem",1);
            if (!me->query_temp("apply/better_chance")) better_chance=0; 
                else  better_chance=me->query_temp("apply/better_chance");
            lvl=(int) (me->query("wuxingyao/kill_level")+me->query("wuxing/level"))/2;
            zshrd=random(100);
            zwrd=random(100);
            if(zshrd<10*(1+lvl/100)*(1+better_chance/200)) {zsh_xrc=2;} 
              else if(zshrd<20*(1+lvl/100)*(1+better_chance/200)) {zsh_xrc=1;}
              else {zsh_xrc=0;}
            if(zwrd<10*(1+lvl/100)*(1+better_chance/200)) {zw_xrc=2;} 
              else if(zwrd<20*(1+lvl/100)*(1+better_chance/200)) {zw_xrc=1;}
              else {zw_xrc=0;}
            xrc=zsh_xrc+zw_xrc;
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
                     if (itemtype=="weapon") ch=itemtype+"_prop/damage";
                     else ch=itemtype+"_prop/armor";
                     itemtype=itemtype+"_prop/";
            ob->set(ch,damage);
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
