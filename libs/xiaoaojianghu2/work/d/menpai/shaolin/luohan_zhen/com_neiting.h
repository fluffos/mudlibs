/* com_neiting.h  the headfile of command neiting include 1,3,5,7
   write by xli
   version:1.0
   last modified:xli
   1998.10.
   for XOGroup
*/
   
#include <ansi.h>
inherit ROOM;

#define DATING __DIR__"luohan_dating"
  
void init()
{
    object me;
    me=this_player();
    add_action("do_ting","stop");
    add_action("do_sha",({"kill","sha"}));
    add_action("do_bihua",({"bihua","fight"}));
}

int welcome_visitor(object me)
{
    object here,npc1,npc2;
    object * inv=all_inventory(this_object());
    int i;
    here = environment(me);    
    if ( here != this_object() ) return 0;    

    if ( !me->query("xli_marks/闯罗汉阵") ) return 1;

    tell_object(me,HIY"\n只见你周围的罗汉拍掌向你攻来。\n\n"NOR);
    for(i=0;i<sizeof(inv);i++)
    {
        if(!userp(inv[i]) && living(inv[i]))
        {
            if(inv[i]->query("gin")>100 &&
               inv[i]->query("kee")>200 &&
               inv[i]->query("sen")>150 )
            {
                if(userp(me))
                {
                    inv[i]->bihua_ob(me);
                    me->bihua_ob(inv[i]);
                }
                
            }
            else
            {
                if(random(5)>1)
                    inv[i]->move(__DIR__"neiting"+sprintf("%d",2*random(4)+2 )); // 死门
                else
                    inv[i]->move(__DIR__"neiting"+sprintf("%d",2*random(4)+1 ));
                
            }
            
            
        }
    }

    inv=all_inventory(here); // 再判断一次

    if( environment(me) != this_object() ) return 1;

    if( ( (sizeof(inv) == 1) )   // 如果房间里只有你
        || (me->query("xli_marks/bp") == 3) ) // 或者打败过了三个罗汉而使降龙伏虎被call
    {   
        me->delete("xli_marks/bp");
        write("突然，火光急闪，明灭只间，好象有人影晃动......\n");

        if(me->query("xli_marks/defeat_huisi"))  //  打败过慧思了
        {
            if( !objectp(npc2 = find_living("hui tong")) )
                npc2 = new(__DIR__"npc/huitong");
            if ( objectp(npc2) )
            {
                npc2 ->move(here);
                write(HIY"你只见眼前人影一闪，"+GRN"伏虎罗汉"NOR+"欺身至你面前。\n"NOR);
                npc2->bihua_ob(me);
                me->bihua_ob(npc2);
                call_out("BackDating",50,me); 
                return 1;
            }
            return 1;
        }
        else
        {
            if(me->query("xli_marks/defeat_huitong"))  //  打败过慧通了
            {
                if( !objectp(npc1 = find_living("hui si")) )
                    npc1 = new(__DIR__"npc/huisi");
                if( objectp(npc1) )
                {
                    npc1 ->move(here);
                    write(HIY"你只见眼前人影一闪，"+RED"降龙罗汉"NOR+"欺身至你面前。\n"NOR);
                    npc1->bihua_ob(me);
                    me->bihua_ob(npc1);
                    call_out("BackDating",50,me);
                    return 1;
                }
                return 1;
            }
            else
            {
                if( !objectp(npc1 = find_living("hui si")) )
                    npc1 = new(__DIR__"npc/huisi");
                if( !objectp(npc2 = find_living("hui tong")) )
                    npc2 = new(__DIR__"npc/huitong");                    
                if(objectp(npc1) && objectp(npc2) )
                {
                    write("你只见眼前人影一闪，"
                    +RED"降龙"+GRN"伏虎"NOR+"两位罗汉欺身至你面前。\n");
                    npc1 ->move(here);
                    npc2 ->move(here);
                    npc1 ->bihua_ob(me);
                    npc2 ->bihua_ob(me);
                    me ->bihua_ob(npc1);
                    me ->bihua_ob(npc2);  
                    call_out("BackDating",50,me);
                    return 1;
                }
                return 1;
            }
            return 1;
        }
    }
}       

void BackDating(object me)
{
    object npc1,npc2;
    if( objectp(npc1 = present("hui si",this_object())) )
    {
        tell_object(me,"慧思长袍一挥，火光顿时暗了下来，重新燃起后，慧思已不知踪影了。\n");        
        npc1->move(DATING);
    }
    if( objectp(npc2 = present("hui tong",this_object())) )
    {
        tell_object(me,"慧通长袍一挥，火光顿时暗了下来，重新燃起后，慧通已不知踪影了。\n");
        npc2->move(DATING);
    }
}

int do_ting(string arg)
{
     write("你正在闯阵，怎么能停手呢?\n");
     return 1;
}

int do_sha(string arg)
{
     write("你与十八罗汉同属少林，怎么能同门相残呢?\n");
     return 1;
}

int do_bihua(string arg)
{
    write("你正在闯阵，如何能另行与之比划呢?\n");
    return 1;
}

int valid_leave(object me,string dir)
{
    object npc1,npc2;

    npc1 = present("hui tong",this_object());
    npc2 = present("hui si",this_object());
    
    if ( objectp(npc1) )
        npc1->move(DATING);
    if ( objectp(npc2) )    
        npc2->move(DATING);
            
    if ( userp(me)&&living(me) && me->query("xli_marks/闯罗汉阵") )
    {
        tell_object(me,YEL"你急闪身形，从罗汉们的围攻中钻了出来，也不择方向，径直奔去......\n\n"NOR);
        tell_object(me,YEL"只听见喀拉喀拉响声不断，你顿觉脚下地面似在移动，不禁大骇！\n\n"NOR);
        tell_object(me,BLU"似乎只是一瞬间，你却发现自己好象身处异地，又似还在原地。\n"NOR);
        me->move(__DIR__"neiting"+sprintf("%d",random(8)+1));
        return notify_fail("\n");
    }
    else
        return ::valid_leave(me,dir);
}
