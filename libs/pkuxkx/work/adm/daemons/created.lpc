//////////////////////////////////////////
//	created.c by cobra
//////////////////////////////////////////
#include <ansi.h>
#include <create.h>

string *query_menpai()
{
	string *menpai=({}),file;
	int nIndex,nSize;
	if(file=read_file(MENPAI_LIST))
	{
		menpai = explode(file,"\n");
		nSize  = sizeof(menpai);
		for(nIndex=0;nIndex<nSize;nIndex++)
		{
			menpai[nIndex]=use_color(menpai[nIndex]);
		}
	}
	return menpai;
}

string use_color(string arg)
{
	int nLength,nPosition;
	if(!arg)
		return "";
	else
	{
		arg=replace_string(arg,"$NOR$",NOR);
		arg=replace_string(arg,"$HIR$",HIR);
		arg=replace_string(arg,"$HIW$",HIW);
		arg=replace_string(arg,"$HIG$",HIG);
		arg=replace_string(arg,"$HIC$",HIC);
		arg=replace_string(arg,"$HIB$",HIB);
		arg=replace_string(arg,"$HIY$",HIY);
		arg=replace_string(arg,"$HIM$",HIM);
		arg=replace_string(arg,"$RED$",RED);
		arg=replace_string(arg,"$BLK$",BLK);
		arg=replace_string(arg,"$BNK$",BNK);
		arg=replace_string(arg,"$BLU$",BLU);
		arg=replace_string(arg,"$MAG$",MAG);
		arg=replace_string(arg,"$WHT$",WHT);
		arg=replace_string(arg,"$CYN$",CYN);
		arg=replace_string(arg,"$GRN$",GRN);
		arg=replace_string(arg,"$YEL$",YEL);
		nLength=strwidth(arg);
		nPosition=strsrch(arg,NOR,-1);
		if(nPosition<nLength-17)
			arg+= NOR;
	}
	return arg;
}
string remove_color(string arg)
{
	if(!arg) 
		return "";
	else
	{
		arg=replace_string(arg,"$NOR$","");
		arg=replace_string(arg,"$HIR$","");
		arg=replace_string(arg,"$HIW$","");
		arg=replace_string(arg,"$HIG$","");
		arg=replace_string(arg,"$HIC$","");
		arg=replace_string(arg,"$HIB$","");
		arg=replace_string(arg,"$HIY$","");
		arg=replace_string(arg,"$HIM$","");

		arg=replace_string(arg,"$RED$","");
		arg=replace_string(arg,"$BLK$","");
		arg=replace_string(arg,"$BNK$","");
		arg=replace_string(arg,"$BLU$","");
		arg=replace_string(arg,"$MAG$","");
		arg=replace_string(arg,"$WHT$","");
		arg=replace_string(arg,"$CYN$","");
		arg=replace_string(arg,"$GRN$","");
		arg=replace_string(arg,"$YEL$","");

		arg=replace_string(arg,NOR,"");
		arg=replace_string(arg,HIR,"");
		arg=replace_string(arg,HIW,"");
		arg=replace_string(arg,HIG,"");
		arg=replace_string(arg,HIC,"");
		arg=replace_string(arg,HIB,"");
		arg=replace_string(arg,HIY,"");
		arg=replace_string(arg,HIM,"");

		arg=replace_string(arg,RED,"");
		arg=replace_string(arg,BLK,"");
		arg=replace_string(arg,BNK,"");
		arg=replace_string(arg,BLU,"");
		arg=replace_string(arg,MAG,"");
		arg=replace_string(arg,WHT,"");
		arg=replace_string(arg,CYN,"");
		arg=replace_string(arg,GRN,"");
		arg=replace_string(arg,YEL,"");
	}
	return arg;
}
string return_string(string arg)
{
	if(!arg) 
		return "";
	else
	{
		arg=replace_string(arg,NOR,"$NOR$");
		arg=replace_string(arg,HIR,"$HIR$");
		arg=replace_string(arg,HIW,"$HIW$");
		arg=replace_string(arg,HIG,"$HIG$");
		arg=replace_string(arg,HIC,"$HIC$");
		arg=replace_string(arg,HIB,"$HIB$");
		arg=replace_string(arg,HIY,"$HIY$");
		arg=replace_string(arg,HIM,"$HIM$");

		arg=replace_string(arg,RED,"$RED$");
		arg=replace_string(arg,BLK,"$BLK$");
		arg=replace_string(arg,BNK,"$BNK$");
		arg=replace_string(arg,BLU,"$BLU$");
		arg=replace_string(arg,MAG,"$MAG$");
		arg=replace_string(arg,WHT,"$WHT$");
		arg=replace_string(arg,CYN,"$CYN$");
		arg=replace_string(arg,GRN,"$GRN$");
		arg=replace_string(arg,YEL,"$YEL$");
	}
	return arg;
}
int add_menpai(string Name)
{
	string *menpais=({}),menpai;
	int nIndex,nSize;
	menpais=query_menpai();
	nSize = sizeof(menpais);
	for(nIndex=0;nIndex<nSize;nIndex++)
	{
		menpai=remove_color(menpais[nIndex]);
		if(menpai==remove_color(Name) )
			return 0;
	}
	menpai=implode(menpais,"\n");
	menpai+="\n"+Name;
	write_file(MENPAI_LIST,menpai,1);
	return 1;
}
int remove_menpai(string Name)
{
	string *menpais=({}),menpai;
	int nIndex,nSize,nSuccess;
	menpais=query_menpai();
	menpai="";
	nSize = sizeof(menpais);
	for(nIndex=0;nIndex<nSize;nIndex++)
	{
		if(remove_color(menpais[nIndex])==remove_color(Name) )
		{
			nSuccess=1;
			continue;
		}
		menpai+=menpais[nIndex]+"\n";
	}
	menpai=menpai[0..sizeof(menpai)-2];
	if(nSuccess==1)
		write_file(MENPAI_LIST,menpai,1);
	return nSuccess;
}
int is_exist_menpai(string Name)
{
	int nSize,nIndex,nSuccess;
	string *menpais=({}),menpai;
	menpais=query_menpai();
	nSize = sizeof(menpais);
	nSuccess=0;
	for(nIndex=0;nIndex<nSize;nIndex++)
	{
		if(remove_color(menpais[nIndex])==remove_color(Name) )
		{
			nSuccess=1;
			continue;
		}
	}
	return nSuccess;
}
int is_legal_English(string arg)
{
	string sTemp;
	int nLegal,nSize,nIndex;
	sTemp=remove_color(arg);
	nLegal = 1;
	nSize = sizeof(sTemp);
	for(nIndex=0;nIndex<nSize;nIndex++)
	{
		if((sTemp[nIndex]>='A'&&sTemp[nIndex]<='Z')||(sTemp[nIndex]>='a'&&sTemp[nIndex]<='z')||sTemp[nIndex]==' ')
			continue;
		else
		{
			nLegal=0;
			break;
		}
	}
	return nLegal;
}
int is_legal_Chinese(string arg)
{
	string sTemp;
	int nLegal,nSize,nIndex;
	sTemp=remove_color(arg);
	nLegal = is_chinese(sTemp);
	return nLegal;
}
