#include <ansi.h>
string cipher_name(object me,string name)
{
	string msg="\n",word,color,bg_color;
	int no=random(3),color_no,bg_color_no,*color_nos=({0,1,2,3,4}),line_no=0,col_no=0,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,line=6+random(6),col=6+random(6),total;
	mapping *colors=({(["bg":HBWHT,"colors":({HIR,HIB,HIG,MAG,HIC})]),
					  (["bg":HBCYN,"colors":({HIR,HIB,HIG,MAG,HIW})]),
					  (["bg":HBGRN,"colors":({HIR,HIB,HIC,MAG,HIW})]),});
	total=line*col;
	x1=random(line);
	y1=random(col);
	x2=random(line);
	y2=random(col);
	x3=random(line);
	y3=random(col);
	x4=random(line);
	y4=random(col);
	x5=random(line);
	y5=random(col);
	if (strwidth(name)>5) name=name[0..4];
	switch (strwidth(name))
	{
		case 4:
		while (x1==x2&&y1==y2)
		{x2=random(line);y2=random(col);}
		break;
		case 6:
		while (x1==x2&&y1==y2)
		{x2=random(line);y2=random(col);}
		while ((x3==x2&&y3==y2)||(x3==x1&&y3==y1))
		{x3=random(line);y3=random(col);}
		break;
		case 8:
		while (x1==x2&&y1==y2)
		{x2=random(line);y2=random(col);}
		while ((x3==x2&&y3==y2)||(x3==x1&&y3==y1))
		{x3=random(line);y3=random(col);}
		while ((x4==x3&&y4==y3)||(x4==x2&&y4==y2)||(x4==x1&&y4==y1))
		{x4=random(line);y4=random(col);}
		break;
		case 10:
		while (x1==x2&&y1==y2)
		{x2=random(line);y2=random(col);}
		while ((x3==x2&&y3==y2)||(x3==x1&&y3==y1))
		{x3=random(line);y3=random(col);}
		while ((x4==x3&&y4==y3)||(x4==x2&&y4==y2)||(x4==x1&&y4==y1))
		{x4=random(line);y4=random(col);}
		while ((x5==x4&&y5==y4)||(x5==x3&&y5==y3)||(x5==x2&&y5==y2)||(x5==x1&&y5==y1))
		{x5=random(line);y5=random(col);}
		break;
	}
	color_no=random(5);
	color_nos-=({color_no});
	bg_color_no=color_nos[random(sizeof(color_nos))];
	color=colors[no]["bg"]+colors[no]["colors"][color_no];
	bg_color=colors[no]["bg"]+colors[no]["colors"][bg_color_no];
	for (int i=0;i<total;i++)
	{
		if (line_no==x1&&col_no==y1)
		msg+=color+name[0..0]+NOR;
		else if (line_no==x2&&col_no==y2)
		msg+=color+name[1..1]+NOR;
		else if (strwidth(name)>4&&line_no==x3&&col_no==y3)
		msg+=color+name[2..2]+NOR;
		else if (strwidth(name)>6&&line_no==x4&&col_no==y4)
		msg+=color+name[3..4]+NOR;
		else if (strwidth(name)>8&&line_no==x5&&col_no==y5)
		msg+=color+name[4..4]+NOR;
		else
		{
			word=ANTIROBOT_D->generaterandomcode()[0..1];
			msg+=bg_color+word+NOR;
		}
		col_no+=1;
		if ((i+1)%col==0&&i!=0)
		{
			msg+="\n";
			line_no+=1;
			col_no=0;
		}
	}
	return msg+"\n\n";
}
