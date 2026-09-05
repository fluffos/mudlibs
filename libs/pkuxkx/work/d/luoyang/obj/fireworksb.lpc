//小剑 zine Oct 16 2010
inherit ITEM;
#include <ansi.h>

string *pic = ({ @TEXT


           HHHH           -HHHH           
        HHH$$$HHHH      HHHH$$HHH=        
       HH$HHHHHHHHH   +HHHHHHHHHHHH       
      H$HHHHHHHHHH$H,$HHHHHHHHHHHHHH      
     HHHHH=,,,,,HHHHHHHHHH---==HHHHHH     
    =HHHH,,,,,,,,HHH$HHHH--======HHHH     
    H$HH=,,,,,====HHHHHH=========HHHHH    
    HHHH,,,,==-----H++H=========HH++HH    
   =HHH,,===-------=HH=======HHH:::+HH    
   HHHH==--------========HHHH::::::+HH=   
   $HHH-------=========HHH:::::::;;+HH=   
   HHHH----=========HHH::;+++++++++;HH=   
   HHHH--=========HHHH+++++++++++;;;HH    
    HHH======HHHHH:;++++++++++++;;;+HH    
    HH+H=======HH====,,=HHHHHH;;+;;+HH    
    HHHHH=====               =HHH;;+HH    
     HH+H=,==                 ==HH+HH     
     HHH=,..=                  ==,HHH     
      HH,,..=                  =..HH      
      =H=,,.==HHHHHHHH$HHHHH  ==..H       
     ====,=HHH++;;;;;;;;;;++HHH==.===     
     ====HH+++;;;;;;;;;;;;+HHH+HH==,=     
     =,=HHHH+++;;;;;;;;;;HHH++HHHH=,=     
     ===HHHHHH++;+;;;+HHHH++HHHHHH,=      
      =,==  HHH+++HHHH=HH+HHH= ===,=      
      ==      HHH++HHHH+HHHH      ==      
                HHH+HH+HHH                
                  HH+HHH                  
                   HHHH                   
                                                               
TEXT, });

void create()
{
        
        set_name("心型礼花", ({"xinxing lihua", "yan hua", "fireworks" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一支礼花，你可以用(dian)命令把它燃放。\n");
                set("unit", "支");
                set("value", 120000);
             }
        setup();
        call_out("dest",7200);
}

void init()
{	
	add_action("do_dian",({"dian"}));
}

int dest()
{
    tell_object(this_player(),"礼花才空气中放置太久，终于受潮，不能燃放了。\n");
    destruct(this_object());
    return 1;
}

int do_dian()
{
    string* color=({CYN,HIG,HIR,HIY,HIC});
    string str;
    object me=this_player();
    
    str = "天空中突然闪出一道绚丽的火花，一个巨大的图案逐渐\n"
          "显现：\n";
    str += color[random(sizeof(color))]+pic[random(sizeof(pic))]+NOR;
    message("marry", str, environment(me));
    if ( random(2) )
    {
        call_out( "show",2+random(3));
        return 1;
    }
    else
    {
        destruct(this_object());
        return 1;
    }
}

int show()
{
    string* color=({CYN,HIG,HIR,HIY,HIC});
    string str;
    object me=this_player();
    str = "天空中突然闪出一道绚丽的火花，一个巨大的图案逐渐\n"
          "显现：\n";
    str += color[random(sizeof(color))]+pic[random(sizeof(pic))]+NOR;
    message("marry", str, environment(me));
    if ( random(2) )
    {
        call_out( "show",2+random(3));
        return 1;
    }
    else
    {
        destruct(this_object());
        return 1;
    }
}


