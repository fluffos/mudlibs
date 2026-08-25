//
// hzk2asc.c
// 
// 凰帝(emperor)
// 2003/5/6 create.

#include <ansi.h>

inherit M_ACCESS;

#define HZ_DIR   "/wiz/emperor/"
#define HZ       HZ_DIR"HZK16"
#define HZS      HZ_DIR"HZK24S"
#define HZF      HZ_DIR"HZK24F"
#define HZK      HZ_DIR"HZK24K"
#define HZH      HZ_DIR"HZK24H"
#define HZX      HZ_DIR"SHZK16"

string *ran_str = ({"@","#","&","$",});
string * ran_color = ({HIR,HIC,HIG,HIY,HIB,HIM,WHT,HIW,//YEL,CYN,RED,BLU,MAG,
BRED,BGRN,BYEL,BBLU,BMAG,BCYN,BWHT,});

void create()
{
    set_privilege(1);
}

int getbit(int byte, int n){
	return ((byte>>n)&1);
}

mixed hzk2asc16(string s, string hzk, int size){
	int i;
	buffer *b;
	b = allocate(6);
	i = sizeof(s);
	if(i>12) return sprintf("%s====== BUG ======\n", s);
	for(int j=0;j<i;j++){
		if((s[j]&0x80)&&(s[j+1]&0x80)){
			int rec;
			rec = ((s[j]-0xa1)*94+s[j+1]-0xa1)*size;
			if(wizardp(this_user())) printf("qu = %O. wei=%O.\n rec = %O.\n", s[j]-0xa1, s[j+1]-0xa1, rec);
			b[j/2] = read_buffer(hzk,rec, size);
			j+=1;
		}
		else return sprintf("%s====== BUG ======\n", s);
	}
	return b;
}

mixed hzk2asc24(string s, string hzk, int size){
	int i;
	buffer *b;
	b = allocate(6);
	i = sizeof(s);
	if(i>12) return sprintf("%s====== BUG ======\n", s);
	for(int j=0;j<i;j++){
		if((s[j]&0x80)&&(s[j+1]&0x80)){
			int rec,qu,wei;
			qu = s[j]-0xa0;
			wei = s[j+1]-0xa0;
//			if(qu<16) rec = ((qu-1)*94+wei-1)*size;
//			else 
			rec = ((qu-16)*94+wei-1)*size;
			b[j/2] = read_buffer(hzk,rec, size);
			j+=1;
		}
		else return sprintf("%s====== BUG ======\n", s);
	}
	return b;
}

string hzk2asc(string s, string hzk){
	mixed b;
	int j, size, dz, k, l;
	string str, str1, str2, *col;

	str1 = ran_str[random(sizeof(ran_str))];
	str2 = ran_str[random(sizeof( ran_str-({str1}) ))];
//	color = ran_color[random(sizeof( ran_color ))];

	switch(hzk){
	case "S": 
		str = HZS;
		size = 72;
		dz = 24;
		break;
	case "F": 
		str = HZF;
		size = 72;
		dz = 24;
		break;
	case "K": 
		str = HZK;
		size = 72;
		dz = 24;
		break;
	case "H": 
		str = HZH;
		size = 72;
		dz = 24;
		break;
	case "X": 
		str = HZX;
		size = 32;
		dz = 16;
		break;
	default :
		size = 32;
		dz = 16;
		str =HZ;
		break;
	}
	if(dz==24) b = hzk2asc24(s, str, size);
	else b = hzk2asc16(s, str, size);
//	printf("buff=\n%O\n",b);
	if(!arrayp(b)) return b;
	b-=({0});
	j = sizeof(b);
	col =allocate(j);
	l = j;
	while(l--){
//		int x;
		col[l] = ran_color[random(sizeof( ran_color-col ))];
	}
	str = HIC"\n╭"+repeat_string("─",dz*j/2)+"╮\n";
	if(random(20)>18) k=1;
	else k=0;
	
	if(dz==24){
		int x, y, i;
		for(x=0;x<dz;x++){
			str += "│"NOR;
//printf("buffer_size=%O\n",j);
			for(i=0;i<j;i++){
				for(y=0;y<dz;y++){
//printf("y=%O\n",y);
					if((0x80>>x%8)&b[i][y*3+x/8]) str += str1;
//					if(getbit(b[i][y*3],x%8)) str +=str1;
					else str += " ";
				}
			}
			
			str += HIC"│\n";
		}
		
	}
	else
	for(int a1=0;a1<dz;a1++){   //lines
		str += "│"NOR;
		for(int i=0;i<j;i++){   //words
			for(int a2=0;a2<(dz/8);a2++){ //bytes
				for(int a3=0;a3<8;a3++){  // 
/*
					if(dz==24){
						if(getbit(b[i][(24-a2-1)*(dz/8)+a1],7-a3)) str += str1;
						else str += " ";
					}
					else 
*/
					if(getbit(b[i][a1*(dz/8)+a2],7-a3)) 
						switch(k){
						case 0:
							str += (col[i]+str1+NOR);
							break;
						case 2:
							str += str1;//"*";
							break;
						case 1:
							str += HIC"#";
							break;
						default :
							break;
						}
					else 
						switch(k){
						case 0:
							str += ran_str[random(sizeof( ran_str-({str1}) ))];
//							str += str2;
							break;
						case 2:
							str += str2;//"*";
							break;
						case 1:
							str += " ";
							break;
						default :
							break;
						}
				}
			}
		}
		str += HIC"│\n";
	}
	str += "╰"+repeat_string("─",dz*j/2)+"╯\n"NOR;
	if(wizardp(this_user())) printf("max len = %d.\nlocation=%s\n", sizeof(str), s);
	return str;
}

		
