/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : 
 * Author : Clode@RevivalWorld
 * Date   : 2001-07-11
 * Note   : ansi package。
 * Update :
 *  o 2000-00-00  

 -----------------------------------------
 */

#ifdef LATTICE
#include "/lpc_incl.h"
#else
#include "../lpc_incl.h"
#endif

nosave char *code[]  = {"$NOR$","$BLK$","$RED$","$GRN$","$YEL$","$BLU$","$MAG$","$CYN$","$WHT$",
"$HIR$","$HIG$","$HIY$","$HIB$","$HIM$","$HIC$","$HIW$",
"$HBBLK$","$HBRED$","$HBGRN$","$HBYEL$","$HBBLU$","$HBMAG$","$HBCYN$","$HBWHT$",
"$BBLK$","$BRED$","$BGRN$","$BYEL$","$BBLU$","$BMAG$","$BCYN$","$BWHT$",
"$BOLD$","$BLINK$","$HIREV$"};

nosave char *color[] = {"[m","[30m","[31m","[32m","[33m","[34m","[35m","[36m","[1;30m",
"[1;31m","[1;32m","[1;33m","[1;34m","[1;35m","[1;36m","[1;37m",
"[40;1m","[41;1m","[42;1m","[43;1m","[44;1m","[45;1m","[46;1m","[47;1m",
"[40m","[41m","[42m","[43m","[44m","[45m","[46m","[47m",
"[1m","[5m","[1;7m"};

/* 
	Written by Clode@Revival World 2001/7/10 05:31下午 
	濾除不必要之控制碼, 與轉換常用之色碼
*/
#ifdef F_ANSI
void
f_ansi PROT((void)) {
	int i, j;
	int clen, csize, slen;
	unsigned char *str, *ret;
	unsigned char *tmp;

	slen = SVALUE_STRLEN(sp);
	str = sp->u.string;
	ret = tmp = new_string(slen+512, "f_ansi");

	csize = sizeof(code)/4;
	
	while( *str ) {
		clen = 0;
		if( *str < '\x20' && *str != '\n' ) {
			if( *str == '\x1B' && str[1] == '[' ) {
				i=2;
				while( isdigit(str[i]) || str[i]==';' ) i++;
				if( *(str+i) != 'm' ) {
					str++; continue;
				}
			}
			else {	
				str++; continue;
			}
		}
		
		if( *str == '$' )
			for(i=0,j=0;i<csize;i++) {
				while( str[j] && str[j] == *(code[i]+j) ) j++;
				
				if( --j && str[j] == '$' ) {
					str += j+1;
					clen = strlen(color[i]);
					
					for(j=0;j<clen;j++) *ret++ = *(color[i]+j);
					break;
				}
			}
		
		if( !clen ) *ret++ = *str++;
	}
	*ret = '\0';
	
	str = new_string(strlen(tmp), "f_ansi");
	strcpy(str, tmp);
	
	FREE_MSTR(tmp);
	free_string_svalue(sp);
	put_malloced_string(str);
}
#endif

/* Written by Clode@RW on 2001/7/11 04:23下午 */
#ifdef F_REMOVE_ANSI
void
f_remove_ansi PROT((void)) {
	int i;
	char *str, *ret, *rethead;
	
	str = sp->u.string;
	
	ret = rethead = new_string(SVALUE_STRLEN(sp)+1, "f_remove_ansi");
	
	while(*str) 
	{
		if( *str == '\x1B' && str[1] && str[1] == '[' ) 
		{
			i=2;
			while( isdigit(str[i]) || str[i]==';' ) i++;
			if( str[i] == 'm' ) {
					str += i+1;
					continue;
			}
		}
		*ret++ = *str++;
	}

	*ret = '\0';
	
	str = new_string(strlen(rethead), "f_remove_ansi");
	strcpy(str, rethead);
	
	FREE_MSTR(rethead);
	free_string_svalue(sp);
	put_malloced_string(str);
}
#endif

/* Written by Clode@RW on 2001/7/11 04:24下午 */
#ifdef F_NOANSI_STRLEN
void
f_noansi_strlen PROT((void)) {
	int i, len;
	unsigned char *str;
	
	str = sp->u.string;
	len = 0;
	while(*str) 
	{
		if( *str == '\x1B' && str[1] && str[1] == '[' ) 
		{
			i=2;
			while( isdigit(str[i]) || str[i]==';' ) i++;
			if( str[i] == 'm' ) {
				str += i+1;
				continue;
			}
		}
		len++; str++;
	}
	
	pop_stack();
	push_number(len);
}
#endif


#define CLEAR_ANSI		1
#define HAVE_SAME_LEAD_ELEM 	2
#define NEW_ELEM		4
#define NEED_CLEAN		8
#define ALREADY_HAVE		16

#define ANSI_CAP	4
// 2002/2/16 12:24下午 by Clode
nosave int combine_ansi P4(char **, ret, char *, str, char **, ansi_table, int *, flag) {
	
	int i=0, j;
	
	while(str[i]=='\x1B')
	{
		/* 若接下來並無字元, 或字元不是 [, 則離開 combine_ansi */
		if( !str[++i] || str[i] != '[' ) break;
		
		i++;
		
		/* 凡是 ; 或 [ 或 0 一律略過 */
		while(str[i] && (str[i] == ';' || str[i] == '[' || str[i] =='0')) i++;
		
		/* 若第一個字元就是 m 的話, 則清空 ansi_table */
		if( str[i] == 'm' )
		{
			/* 清空ansi_table */
			for(j=0;j<ANSI_CAP;j++)
				*ansi_table[j] = *(ansi_table[j]+1) = 0;
			
			while(str[++i] && (str[i] == ' ' || str[i] == '\n'))
				*((*ret)++) = str[i];
			
			*flag |= CLEAR_ANSI;
			continue;
		}
		
		/* 對一個 ansi 內容進行 loop */
		while(str[i])
		{
			while(str[i] && str[i] == ';') i++;
			
			if( isdigit(str[i]) )
			{
				if( str[i] == '0' )
				{
					/* 清空ansi_table */
					for(j=0;j<ANSI_CAP;j++)
						*ansi_table[j] = *(ansi_table[j]+1) = 0;
				}
				
				else for(j=0;j<ANSI_CAP;j++)
				{
					/* 檢查是否已有相同 ansi_elem */
					
					if( *ansi_table[j] )
					{
						if( str[i] == *ansi_table[j] )
						{
							if( str[i+1] )
							{
								if( isdigit(str[i+1]) && *(ansi_table[j]+1) )
								{
									if( *(ansi_table[j]+1) == str[i+1] )
									{
										i++;
										break;
									}
									else
									{
										*(ansi_table[j]+1) = str[++i];
										break;
									}
									
								}
								else if( !isdigit(str[i+1]) && !*(ansi_table[j]+1) ) break;
								else continue;
							}
							else return i;
						}
						else continue;
					}
					else
					{
						*ansi_table[j] = str[i];
						
						if( str[i+1] && isdigit(str[i+1]) )
							*(ansi_table[j]+1) = str[++i];
						
						break;
					}
				}
			}
			else if( str[i] == 'm' )
			{
				while(str[++i] && (str[i] == ' ' || str[i] == '\n')) 			
					*((*ret)++) = str[i];

				if( str[i] == '\x1B' )
					break;
				else 
					return i;
			}
			else
			{
				for(j=0;j<ANSI_CAP;j++)
					*ansi_table[j] = *(ansi_table[j]+1) = 0;
				
				*((*ret)++) = '\x1B';
				return 1;
			}
			
			i++;
		}/* while */
			
	}/* while */
	
	return i;
}
// 2002/2/16 12:24下午 by Clode
nosave char *rally_ansi P1(char *, str) {
	int i, j, k, flag;
	char *ansi_table[ANSI_CAP], *last_table[ANSI_CAP], *new_table[ANSI_CAP];
	unsigned char *ret, *rethead;
	
	ret = rethead = new_string(strlen(str)+1, "f_kill_repeat_ansi ret");
	
	for(j=0;j<ANSI_CAP;j++)
	{
		 new_table[j] = DMALLOC(2, TAG_STRING, "rally_ansi");
		last_table[j] = DMALLOC(2, TAG_STRING, "rally_ansi");
		ansi_table[j] = DMALLOC(2, TAG_STRING, "rally_ansi");
		*new_table[j] = *(new_table[j]+1) = *last_table[j] = *(last_table[j]+1) = *ansi_table[j] = *(ansi_table[j]+1) = 0;
	}
	
	while(*str)
	{
		if( *str != '\x1B' )
		{
			*ret++ = *str++;
			continue;
		}
		else
		{
			k = flag = 0;
			
			for(j=0;j<ANSI_CAP;j++)
				*new_table[j] = *(new_table[j]+1) = *ansi_table[j] = *(ansi_table[j]+1) = 0;
			
			str += combine_ansi((char **)&ret, str, ansi_table, &flag);
			
			if( flag & CLEAR_ANSI )
			{
				for(i=0;i<ANSI_CAP;i++)
				{
					if( !*last_table[i] ) break;
					
					for(j=0;j<ANSI_CAP;j++)
					{
						if( !*ansi_table[j] ) break;
						
						if( *last_table[i] == *ansi_table[j] )
						{
							flag |= HAVE_SAME_LEAD_ELEM;
							if( *(last_table[i]+1) != *(ansi_table[j]+1) )
							{
								*new_table[k] = *last_table[i] = *ansi_table[j];
								*(new_table[k++]+1) = *(last_table[i]+1) = *(ansi_table[j]+1);
							}
							break;
						}
					}
					
					if( !(flag & HAVE_SAME_LEAD_ELEM) )
						flag |= NEED_CLEAN;
					else flag ^= HAVE_SAME_LEAD_ELEM;
				}
				if( flag & NEED_CLEAN )
				{
					flag ^= NEED_CLEAN;
					
					*ret++ ='\x1B';
					*ret++ ='[';
					*ret++ ='m';
					
					for(i=0;i<ANSI_CAP;i++)
					{
						if( *ansi_table[i] )
						{
							*new_table[i] = *last_table[i] = *ansi_table[i];
							*(new_table[i]+1) = *(last_table[i]+1) = *(ansi_table[i]+1);
						}
						else
							*new_table[i] = *(new_table[i]+1) = *last_table[i] = *(last_table[i]+1) = 0;
					}
				}
				else
				{
					for(i=0;i<ANSI_CAP;i++)
					{
						if( !*ansi_table[i] ) break;
					
						for(j=0;j<ANSI_CAP;j++)
						{
							if( !*last_table[j] ) break;
							
							if( *ansi_table[i] == *last_table[j] )
								flag |= ALREADY_HAVE;
						}
						
						if( flag & ALREADY_HAVE )
							flag ^= ALREADY_HAVE;
						else for(j=0;j<ANSI_CAP;j++)
						{
								if( *last_table[j] ) continue;
								
								*new_table[k] = *last_table[j] = *ansi_table[i];
								*(new_table[k++]+1) = *(last_table[j]+1) = *(ansi_table[i]+1);
								break;
						}
					}
				}
			}
			else
			{
				k=0;
				for(i=0;i<ANSI_CAP;i++)
				{
					if( !*ansi_table[i] ) break;
					
					flag |= NEW_ELEM;
					
					for(j=0;j<ANSI_CAP;j++)
					{
						if( !*last_table[j] ) break;
						
						if( *ansi_table[i] == *last_table[j] )
						{
							flag ^= NEW_ELEM;
							
							if( *(ansi_table[i]+1) != *(last_table[j]+1) )
							{
								*new_table[k] = *ansi_table[i];
								*(new_table[k++]+1) = *(last_table[j]+1) = *(ansi_table[i]+1);
							}
							break;
						}
					}
					
					if( flag & NEW_ELEM )
					{
						flag ^= NEW_ELEM;
						
						for(j=0;j<ANSI_CAP;j++)
						{
							if( *last_table[j] ) continue;
							
							*new_table[k] = *last_table[j] = *ansi_table[i];
							*(new_table[k++]+1) = *(last_table[j]+1) = *(ansi_table[i]+1);
							break;
						}
					}
				}
			}
			
			if( *new_table[0] )
			{
				*ret++ = '\x1B';
				*ret++ = '[';
				for(j=0;j<ANSI_CAP;j++)
				{
					if( !*new_table[j] ) break;
					
					*ret++ = *new_table[j];
					
					if( *(new_table[j]+1) ) 
						*ret++ = *(new_table[j]+1);
					
					*ret++ = ';';
				}
				*(ret-1) = 'm';
			}
		}
	}
	
	*ret = '\0';
	
	for(j=0;j<ANSI_CAP;j++)
	{
		FREE(last_table[j]);
		FREE(new_table[j]);
		FREE(ansi_table[j]);
	}
		
	return rethead;
}	

// 2002/2/16 12:24下午 by Clode	
#ifdef F_KILL_REPEAT_ANSI
void
f_kill_repeat_ansi PROT((void)) {
	unsigned char *str, *tmp;

	tmp = rally_ansi(sp->u.string);
	
	str = new_string(strlen(tmp), "f_kill_repeat_ansi");
	strcpy(str, tmp);
	
	FREE_MSTR(tmp);
	free_string_svalue(sp);
  	put_malloced_string(str);		
}
#endif

#ifdef F_ANSI_PART
void
f_ansi_part PROT((void)) {
	int i, j;
	char *str, *ret, *rethead;
	
	str = sp->u.string;
	
	ret = rethead = new_string(SVALUE_STRLEN(sp)+1, "f_ansi_part");
	
	while(*str) 
	{
		if( *str == '\x1B' && str[1] && str[1] == '[' ) 
		{
			i = 2;
			while( isdigit(str[i]) || str[i]==';' ) i++;

			if( str[i] == 'm' )
			{
				if( i == 2 )
				{
					str++; continue;
				}
				i++;
				while(i--)
				{
					if( str[i] == '0' && !isdigit(str[i-1]) ) continue;
					*ret++ = *str++;
				}
			}
		}
		else str++;
	}

	*ret = '\0';
	
	str = new_string(strlen(rethead), "f_remove_ansi");
	strcpy(str, rethead);
	
	FREE_MSTR(rethead);
	free_string_svalue(sp);
	put_malloced_string(str);
}
#endif


#ifdef F_REMOVE_BG_ANSI
void
f_remove_bg_ansi PROT((void)) {
	int i, j;
	char *str, *ret, *rethead;
	
	str = sp->u.string;
	
	ret = rethead = new_string(SVALUE_STRLEN(sp)+1, "f_remove_bg_ansi");
	
	while(*str) 
	{
		if( *str == '\x1B' && str[1] && str[1] == '[' ) 
		{
			*ret++ = *str++;
			*ret++ = *str++;
			
			while(*str)
			{
				if( *str == 'm' )
				{
					*ret++ = *str++;
					break;
				}
				
				if( *str == ';' )
				{
					*ret++ = *str++;
					continue;
				}
				
				if( isdigit(*str) )
				{
					if( *str == '4' )
					{
						str++;
						if( *str && isdigit(*str) )
							str++;
					}
					else 
					{
						*ret++ = *str++;
						if( *str && isdigit(*str) )
							*ret++ = *str++;
					}
				}
				else *ret++ = *str++;
			}	
		}
		else *ret++ = *str++;
	}

	*ret = '\0';
	
	str = new_string(strlen(rethead), "f_remove_gb_ansi");
	strcpy(str, rethead);
	
	FREE_MSTR(rethead);
	free_string_svalue(sp);
	put_malloced_string(str);
}
#endif
