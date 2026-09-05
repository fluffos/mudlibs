#pragma save_binary
#include "/include/ansi.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir,poem;
        mixed *file;
        string *msg;
        int i;
        object poet;
        seteuid(getuid());

	    if(me->query("sen")<50)
            return notify_fail("你冥思苦想，脑子一片混乱。没有想出一言半语\n");
        dir="/d/poem/";
        file = get_dir(dir, -1);
	    if(!arg||arg)
	    {
	        if( !sizeof(file) )
	            tell_object(me,"开启文件错误。\n");
	        i=sizeof(file);
	        poem=read_file(dir+file[random(i)][0]);
	        while(sizeof(poem)>=8000)//显示支持的最大的字节数。
	            poem=read_file(dir+file[random(i)][0]);
	        poem=replace_string(poem,"：","："HIG);
	        poem=replace_string(poem,"\n","\n"HIC);
            
            poet=present("poet",environment(me));//诗人
            if(poet)
            {
                me->receive_damage("sen", 50);
                me->set_explore("south#16");
			    msg=({
        	    "$N愤愤不平的说,就你大诗人会吟诗作对么?"+RANK_D->query_self_rude(me)+"也来一首!\n",
			    "$N高兴的说"+RANK_D->query_self_close(me,me->query("age"))+"也来附庸风雅一番.\n",
        	    "$N突然诗情大发,立刻摇头晃脑,口中念念有词...............\n",
        	    "大诗人吟诗完毕,瞟了$N一眼,似乎颇为得意,$N勃然大怒,"+RANK_D->query_self_rude(me)+"也来一首\n",
        	    "$N握着大诗人的手,激动说道:总算找到知音了.$N说:"+RANK_D->query_self_close(me,me->query("age"))+"也风雅一番.\n",
        	     });
			     message_vision(msg[random(sizeof(msg))],me);
            }
             message_vision(HIC"$N摇头晃脑,念诗一首:\n"NOR,me);
	         message_vision(HIY+poem+NOR,me);
	    	//write(UNFR ESC+poem);
		//write(BIGTOP ESC+poem);
	    	//for(i=0;i<10;i++)
	    	//write(DBL ESC+"\n");
	    	//write(SINGW ESC"\n");
	    	//write(poem);
	    	//write(HOME ESC);
	    	//write(FRBOT ESC);
	    	//write(TOPOINT(5,5));
	    	//HOME ESC;
	    	//FRTOP ESC;
	    	//return 1;
	    	//
			//write(HOME ESC);
	    	//write(TOPOINT(0,0));
/*	    	write(FRELINE);
	    	for(i=0;i<30;i++)
	    		{
	    			//TORIGHT(40);
	    		
	    			write(random(5)+"@@"+random(5)+"@@"+random(5)+"@@"+random(5)+"@@"+random(5)+random(5)+random(5)+random(5));
	    			FRELINE;
	    			//TOBOT(1);
	    			//TORIGHT(40);
	    	    	write("\n");	
	    		
	    		}
	    	
	    	
	    	//write(TOPOINT(6,6));
	    	//write(NOR);
	    	write(TOBOT(50));
	    	HOME ESC;
	    	//write(TOPOINT(40,1));
	    	//write(REST ESC+poem);
	    	//this_object()->main(me);
	    	//"/cmds/std/look"->main(me);
	    	call_out("do_call",1,me);
	*/
	}
	
	return 1;
}
/*

int do_call(object me)
{
	//write(CLR_LINE);
	//write(CLR ESC);
	//TOPOINT(0,6);
	//FRTOP ESC;
	//write("asdasdasdasdasdasdasdasdasdasd");
	remove_call_out("call_out");
	this_object()->main(me);	
	return 1;
}

*/
