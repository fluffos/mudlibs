//星宿毒草,zine nov 8

#include <ansi.h>

inherit ITEM;


void create()
{
        set_name("毒草",({ "du cao"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 0);
                set("material", "grass");
                set("judge","fense");
                
                set("no_get",1);
                set("long", HIM+@LONG

                                                          
                                            .###.          
                                            -#.##          
                                            .####          
                           .#####X####/ ..   # .#          
                        #####   --.#X###### .# ##          
                      ###. /#X.    .##   .#### #           
                     ##      ##     .#.    //###           
                    ##.       #X.    /##/######.           
                   ###         X#- /####-#X.  #            
                   #./##X      ..####.   .#.  #            
                  ##   .##. -..X#/  X     :# .#            
                  #    . $##=### .  X      # ##            
                 ##       .####     #      ###             
                 ####.. ###;.#      %      -#;             
               .##,######   ##      #     /##              
                ###/ :#%    #      /#   .##@               
               .###.##.   .##     .X.  ###.                
                  #####  //#      ######                   
                     ###############:                      
LONG+NOR);           
                         
			}
        
        setup();
call_out("dest",75);
}

int dest()
{
    if (this_object())
    {
        destruct(this_object());
    }
}
void init()
{
    int i,count=0;
    object* all=all_inventory(environment());
    
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("id")=="du cao")
        {
            count=count+1;
            if (count==2)
            {
                if (all[i]!=this_object())
                {
                    destruct(all[i]);
                    count=count-1;
                }
            }
        }
    }
    
    return;
}