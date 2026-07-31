//Cracked by Roath
// more.c

#include <ansi.h>

void more(string cmd, string *text, int line,int y)
{
	int i,j,k;
	if(y){
	switch(cmd){
		case "":
		case "n":
			write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
			for(i=line + 23,k=line+1; line<sizeof(text) && line<i; line++)
				write(CYN+(string)(k++)+NOR+"   "+text[line] + "\n");
			if( line>=sizeof(text) ) return;
			break;
		case "b":
			write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
			line = line - 46;
			if(line<-22) return;
			for(i=line + 23,k=line+1; line < i;line++)
				write(CYN+(string)(k++)+NOR+"   "+text[line]+"\n");
			break;
		case "q":
			return;
		default:
			write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
        }
        printf("== 未完继续 " HIY "%d%%" NOR " == (n 或 <ENTER> 继续下一页，q 离开，b 前一页)",
                (line*100/sizeof(text)) );
        input_to("more", text, line,1);
        }
        else {
        switch(cmd) {
                case "":
                case "n":
	                write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
                        for(i=line + 23; line<sizeof(text) && line<i; line++)
                                write(text[line] + "\n");
                        if( line>=sizeof(text) ) return;
                        break;
	        case " ":
        	case "b":
        		write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
        		line = line - 46;
        		if(line<-22) return;
        		for(i=line + 23; line < i;line++)
                		write(text[line]+"\n");
        		break;
                case "q":
                        return;
		default:
			write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
        }
        printf("== 未完继续 " HIY "%d%%" NOR " == (n 或 <ENTER> 继续下一页，q 离开，b 前一页)",
                (line*100/sizeof(text)) );
        input_to("more", text, line);
        }
}

void start_more(string msg,int y)
{
        more("", explode(msg, "\n"), 0,y);
}


