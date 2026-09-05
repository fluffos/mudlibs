#include <ansi.h>
#include <command.h>
#pragma save_binary
#define HZK "/d/luoyang/npc/etc/Hzk"
#define ASC "/d/luoyang/npc/etc/Asc"

#define DEFAULT_FILL "#"
#define DEFAULT_FCOLOR ""
#define DEFAULT_BG " "
#define DEFAULT_BGCOLOR ""
#define AUTO_SIZE 20


string Display(string str, int size, string fill, string bg, string fcolor, string bgcolor);
string Display(string str, int size, string fill, string bg, string fcolor, string bgcolor)
{
        int offset;
        int *mask = ({0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1});
        string *flch =({"!","@","#","$","%","&","*","+","A","B","C",
        "D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R",
        "S","T","U","V","W","X","Y","Z",});//填充字符
        int scale;
        int r,z,leafy;
        string char;
        string *out;
        
        if(!size)
#ifdef AUTO_SIZE
                size = AUTO_SIZE;
#else
                error("TEXT to PIC need size.\n");
#endif
        out = allocate(16);
        out = map_array(out, (: $1 = "" :));
        size *= 2;

        if(!fill) fill = DEFAULT_FILL;
        if(!fcolor) fcolor = DEFAULT_FCOLOR;
        if(!bg) bg = DEFAULT_BG;
        if(sizeof(fill) != sizeof(bg)) {
                fill = DEFAULT_FILL;
                bg = DEFAULT_BG;
        }
        if(!bgcolor) bgcolor = DEFAULT_BGCOLOR;

                          size = 24;
        for(int k = 0; k < sizeof(str); k++) {
                                leafy = random(5);
                                r = random(10);
                                z = random(3);
                                if(z == 1)
                                size = 24;
                                else if(z == 2)
                                size = 32;
                                else size = 28;                               
                                //下面开始定义填充字符和背景
                                 fill= flch[random(sizeof(flch))];
                                 fill= fill+NOR;
                                 switch (random(5))
                                 {
                                 	case 0:
                                 		fill=HIR + fill;
                                 		break;
                                 	case 1:
                                 		fill=HIY + fill;
                                 		break;	
                                 	case 2:
                                 		fill=HIC + fill;
                                 		break;
                                 	case 3:
                                 		fill=HIB + fill;
                                 		break;
                                 	default:
                                 		fill=HIM + fill;
                                 		break;
                                 	}
                                 if(random(4))  bg = flch[random(sizeof(flch))];
                                 else  bg = " ";

                                                if(mask[0] & str[k]) {
                        offset  = size*( (atoi(sprintf("%d", str[k]))-0xA1)*94 + atoi(sprintf("%d", str[k+1])) - 0xA1 );
                        char = read_bytes(HZK + (size/2), offset, size);
                        k++;
                        scale = 2;
                } else {
                        offset = str[k] * (size/2);
                        char = read_bytes(ASC + (size/2), offset, (size/2));
                        scale = 1;
                }

                if(!sizeof(char)) error("TEXT to PIC can't read bytes from character lib\n");

                for(int i = 0; i < sizeof(char); i++) {
                        for(int j = 0; j < 8; j++) {
                                if(mask[j] & char[i]) 
                                        out[i/scale] += fcolor + fill;
                                else 
                                        out[i/scale] += bgcolor + bg;
                        }
                }

                 for(int i = 0; i < sizeof(out); i++) {
                 if(!leafy) {
                    out[i] = replace_string(out[i], fcolor + fill, fill );
                    }
                      }
                            }
        size = random(5);
        return implode(out, "\n") + NOR;
}
