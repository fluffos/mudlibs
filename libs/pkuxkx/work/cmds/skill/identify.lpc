//whuan，鉴定装备
//modified by Zine 加入古玩字画的鉴定
//modified by seagate 鉴定命令重构，鉴定命令和鉴定信息解耦
//   具体详见identify.h中对接口的详细定义
#include <ansi.h>
inherit F_CLEAN_UP;
#include <identify.h>

int main(object me, string arg)
{   
        object ob;
        int idf,type;
        string temp;
        
        if(!arg)
                return notify_fail("你要鉴定什么？\n");
        if(!ob=present(arg,me))
                return notify_fail("你要鉴定什么？\n");
        if( (type=ob->is_identify())==IDF_CANT ) 
                return notify_fail("这种东西还需要鉴定么？\n");;
        if( !ob->valid_identify(me) )
                return notify_fail("你无法对"+ob->name()+"进行鉴定！\n");
        
        if ( type!=IDF_SIMPLE )
        {
          ob->set_idflevel(me);
          idf=ob->get_idflevel();
        }
        else
          idf=IL_FULL;
        
        if( idf==IL_SIMPLE )
          message_vision("$N捧着$n上上下下仔仔细细的打量了一遍。\n",me,ob);
        else if( idf==IL_FULL && type==IDF_EQUIP )
       		message_vision("$N捧着$n上上下下仔仔细细的打量了一遍，又按照兵器谱的内容反复对照一番。\n",me,ob);
        else 
        	message_vision("$N捧着$n上上下下仔仔细细的打量了一遍。\n",me,ob);

        temp=ob->identify(idf, me);
        tell_object(me,temp);
        return 1;
}
