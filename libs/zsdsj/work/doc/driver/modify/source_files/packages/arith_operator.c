/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : arith_operator.c
 * Author : Clode@RevivalWorld
 * Date   : 2002-01-01
 * Note   : arith_operator package。
 * Update :
 *  o 2000-00-00  

 -----------------------------------------
 */
#ifdef LATTICE
#include "/lpc_incl.h"
#else
#include "../lpc_incl.h"
#endif

nosave char *remove_leading_zero P1(char *, num) {
	
	int i=0, j=-1, len;
	char *ret;
	
	len = strlen(num);
	
	while(num[++j]==48);
	
	if( j == len ) j--;

	ret = DMALLOC(len-j+1, TAG_STRING, "remove_leading_zero");
	for(i=j;i<len;i++)
		ret[i-j] = num[i];
		
	ret[len-j] = '\0';
	
	return ret;
}

nosave void itoa P1(svalue_t *, sp) {

	int i, j, k, negative=0;
	char *tmp;
	
	if( sp->type == T_REAL )
	{
            	sp->type = T_NUMBER;
            	sp->u.number = (int) sp->u.real;
        }
        
        if( sp->type == T_NUMBER )
        {
        	i=0;
        	j = k = sp->u.number;
        	
        	if( j < 0 )
        	{
        		j = k = -j;
        		negative = 1;
        	}
        	
        	while(++i && (j=j/10));
        	
        	sp->u.string = tmp = DMALLOC(i+1+negative, TAG_STRING, "itoa");
		
        	tmp[i+negative]='\0';
		
        	do
        	{
            		tmp[--i+negative] = (k%10)+48;
        	}
        	while((k=k/10));
        
        	sp->type = T_STRING;
        	
        	if( negative ) tmp[0] = 45;
	}
}

/* 數值比較運算子函式 ">" "<" ">=" "<=" "==" */
/*
	< 	:	1
	>	:	2
	=	:	4
*/
/* n1, n2 : 正整數 */
nosave int compare_value P5(int, negative1, char *, n1, int, negative2, char *, n2, char *, operator) {
	
	int i=0, j, n1_len, n2_len, flag=0;
	
	while(operator[i])
		switch(operator[i++])
		{
			case 60 : flag |= 1; break;
			case 62 : flag |= 2; break;
			case 61 : flag |= 4; break;
			default : break;
		}
	
	if( !flag ) return 0;
	if( flag == 7 ) return 1;

	if( negative1 && !negative2 )
	{
		if( flag == 4 ) return 0;
		if( 1 & flag ) return 1;
		if( 2 & flag ) return 0;
	}
	
	if( !negative1 && negative2 )
	{
		if( flag == 4 ) return 0;
		if( 1 & flag ) return 0;
		if( 2 & flag ) return 1;
	}
		
	n1_len = strlen(n1);
	n2_len = strlen(n2);
	
	if( !negative1 && !negative2 )
	{
		if( n1_len < n2_len )
		{
			if( flag == 4 ) return 0;
			if( 1 & flag ) return 1;
			if( 2 & flag ) return 0;
		}
	
		if( n1_len > n2_len )
		{
			if( flag == 4 ) return 0;
			if( 1 & flag ) return 0;
			if( 2 & flag ) return 1;
		} 
	
		for(i=0;i<n1_len;i++)
		{
			if( (n1[i]-48) - (n2[i]-48) == 0 ) continue;
		
			if( (n1[i]-48) - (n2[i]-48) > 0 )
			{
				if( flag == 4 ) return 0;
				if( 1 & flag ) return 0;
				if( 2 & flag ) return 1;
			}
			else
			{
				if( flag == 4 ) return 0;
				if( 1 & flag ) return 1;
				if( 2 & flag ) return 0;
			}
		}
	}
	else
	{
		if( n1_len < n2_len )
		{
			if( flag == 4 ) return 0;
			if( 1 & flag ) return 0;
			if( 2 & flag ) return 1;
		}
	
		if( n1_len > n2_len )
		{
			if( flag == 4 ) return 0;
			if( 1 & flag ) return 1;
			if( 2 & flag ) return 0;
		} 
	
		for(i=0;i<n1_len;i++)
		{
			if( (n1[i]-48) - (n2[i]-48) == 0 ) continue;
		
			if( (n1[i]-48) - (n2[i]-48) > 0 )
			{
				if( flag == 4 ) return 0;
				if( 1 & flag ) return 1;
				if( 2 & flag ) return 0;
			}
			else
			{
				if( flag == 4 ) return 0;
				if( 1 & flag ) return 0;
				if( 2 & flag ) return 1;
			}
		}
	}
	if( 4 & flag ) return 1;
	return 0;
}
	
/* 加法處理函式 */
/* n1, n2 : 正整數 */
nosave char *addition P2(char *, n1, char *, n2) {

	int i, j, k, carry=0;
	int n1_len, n2_len, ans_len;
	char *ans, *ret;

	n1_len = strlen(n1);
	n2_len = strlen(n2);

	ans_len = (n1_len > n2_len ? n1_len : n2_len) + 1;

	ans = DMALLOC(ans_len+1, TAG_STRING, "addition");

   	for(i=n1_len-1,j=n2_len-1,k=ans_len-1;i>=0 && j>=0;i--,j--,k--)
   	{
      		ans[k]=(n1[i]+n2[j]-96+carry)%10 + 48;
      		carry=(n1[i]+n2[j]-96+carry >= 10);
   	}
   	
   	if(i>=0)
      		for(;i>=0;i--,k--)
      		{
 			ans[k]=(n1[i]-48+carry)%10 + 48;
 			carry=(n1[i]-48+carry >= 10);
      		}
   	else
      		for(;j>=0;j--,k--)
      		{
 			ans[k]=(n2[j]-48+carry)%10 + 48;
 			carry=(n2[j]-48+carry >= 10);
      		}

	ans[ans_len] = '\0';
   	if( carry > 0 )
   	{
   		ans[0]=carry+48;
   		ret = ans;
   	}
   	else
   	{
   		ans[0] = 48;
		ret = remove_leading_zero(ans);
   		FREE(ans);
   	}

	return ret;
}

/* 減法處理函式 */
/* n1 : 大正整數, n2 : 小正整數 */
nosave char *subtraction P2(char *, n1, char *, n2) {
	
	int i, j, k, carry=0;
	int n1_len, n2_len, ans_len;
	char *ans, *ret;

	n1_len = strlen(n1);
	n2_len = strlen(n2);
	
	ans_len = (n1_len > n2_len ? n1_len : n2_len);
	
	ans = DMALLOC(ans_len+1, TAG_STRING, "subtraction");
	
	for(i=n1_len-1,j=n2_len-1,k=ans_len-1;i>=0 && j>=0;i--,j--,k--)
   	{
   		ans[k] = (n1[i]-48) - (n2[j]-48) + carry + ((n1[i]+carry)<n2[j]?10:0) + 48;
   		carry = -(n1[i]+carry < n2[j]);
   	}
   	
   	if(i>=0)
      		for(;i>=0;i--,k--)
      		{
      			ans[k] = n1[i] + carry + ((n1[i]-48+carry)<0?10:0);
 			carry = -((n1[i]-48+carry) < 0);
      		}
   	
   	ans[ans_len] = '\0';
   	ret = remove_leading_zero(ans);

   	FREE(ans);
   	return ret;
}

/* 乘法處理函式 */
/* n1, n2 : 正整數 */
nosave char *multiplication P2(char *, n1, char *, n2) {

	int i, j, k, carry=0;
	int n1_len, n2_len, ans_len;
	char *ans, *ret;
	
   	n1_len = strlen(n1);
   	n2_len = strlen(n2);
   	
	ans_len = n1_len+n2_len;
	
   	ans = DMALLOC(ans_len+2, TAG_STRING, "multiplication");
   	for(i=0;i<=ans_len;i++)
      		ans[i]=0;
   
   	for(i=n1_len-1;i>=0;i--)
   	{
      		carry=0;
      		for(j=n2_len-1;j>=0;j--)
      		{
	 		ans[i+j+1] = ans[i+j+1]+(n1[i]-48)*(n2[j]-48)+carry;
	 		carry=ans[i+j+1]/10;
	 		ans[i+j+1] %= 10;
	 		//ans[i+j+1] += 48;
      		}
      		ans[i+j+1] += carry;
   	}

	ans[ans_len] = '\0';
	while(ans_len--)
		ans[ans_len]+=48;
		
   	if( carry > 0 )
   	{
   		ans[0]=carry+48;
   		ret = ans;
   	}
   	else
   	{
   		ans[0] = 48;
		ret = remove_leading_zero(ans);
   		FREE(ans);
   	}
	return ret;
}

/* 除法處理函式 */
/* n1 : 大正整數(被除數), n2 : 小正整數(除數) */
nosave char *division P2(char *, n1, char *, n2) {
	
	int i, j, k=0, carry=0;
	int n1_len, n2_len, ans_len, tmp_len;
	char *ret, *tmp, *str;
	
   	n1_len = strlen(n1);
   	n2_len = strlen(n2);
   	
   	if( !n2[0] || n2[0] == 48 ) error("(division) 除數為 0");
   	
   	tmp = DMALLOC(n2_len+1, TAG_STRING, "division 1");
   	ret = DMALLOC(n1_len+1, TAG_STRING, "division 2");
   	
   	for(i=0;i<n1_len;i++, carry=0)
   	{
   		if( !i ) 
   		{
   			for(j=0;j<n2_len;j++) 
   				tmp[j] = n1[j];
   			tmp[n2_len] = '\0';
   			i = j-1;
   		}
   		else
   		{
   			tmp_len = strlen(tmp);
			str = DMALLOC(tmp_len+2, TAG_STRING, "division 3");
   			strcpy(str, tmp);
   			str[tmp_len] = n1[i];
   			str[tmp_len+1] = '\0';
   			FREE(tmp);
   			tmp = remove_leading_zero(str);
   			FREE(str);
   		}

   		while( compare_value(0, tmp, 0, n2, ">=") )
   		{
   			str = subtraction(tmp, n2);
   			FREE(tmp);
   			tmp = DMALLOC(strlen(str)+1, TAG_STRING, "division 4");
   			strcpy(tmp, str);
   			FREE(str);
   			carry++;
   		}
   		ret[k++] = carry+48;
   	}
   	
   	ret[k] = '\0';
	FREE(tmp);
	tmp = remove_leading_zero(ret);
	FREE(ret);
   	return tmp;
}

#ifdef F_COUNT
void f_count() {
	
	int i, negative=0, negative1=0, negative2=0;
	char *n1, *n2, *operator, *tmp, *ans;
	
	itoa(sp);
	itoa((sp-2));
	
	operator = (sp-1)->u.string;
	
	if( (sp-2)->u.string[0] == 45 )
	{
		negative1 = 1;
		tmp = DMALLOC(strlen((sp-2)->u.string), TAG_STRING, "count");
		(sp-2)->u.string++;
		strcpy(tmp, (sp-2)->u.string);
		(sp-2)->u.string--;
	}
	else
	{
		tmp = DMALLOC(strlen((sp-2)->u.string)+1, TAG_STRING, "count");
		strcpy(tmp, (sp-2)->u.string);
	}
	
	n1 = remove_leading_zero(tmp);
	FREE(tmp);
	
	if( sp->u.string[0] == 45 )
	{
		negative2 = 1;
		tmp = DMALLOC(strlen(sp->u.string), TAG_STRING, "count");
		sp->u.string++;
		strcpy(tmp, sp->u.string);
		sp->u.string--;
	}
	else
	{
		tmp = DMALLOC(strlen(sp->u.string)+1, TAG_STRING, "count");
		strcpy(tmp, sp->u.string);
	}
	
	n2 = remove_leading_zero(tmp);
	FREE(tmp);
	
	switch(strlen(operator))
	{
		case 1:
		{
			switch(operator[0])
			{
				case '+':
					if( negative1 )
					{
						if( negative2 )
						{
							negative = 1;
							tmp = addition(n1, n2);
						}
						else
						{
							if( compare_value(0,n1, 0,n2, ">") )
							{
								negative = 1;
								tmp = subtraction(n1, n2);
							}
							else
								tmp = subtraction(n2, n1);
						}
					}
					else
					{
						if( negative2 )
						{
							if( compare_value(0,n2, 0,n1, ">") )
							{
								negative = 1;
								tmp = subtraction(n2, n1);
							}
							else
								tmp = subtraction(n1, n2);
						}
						else
							tmp = addition(n1, n2);
					}
					break;
					
					
				case '-':
					if( negative1 )
					{
						if( negative2 )
						{
							if( compare_value(0,n1, 0,n2, ">") )
							{
								negative = 1;
								tmp = subtraction(n1, n2);
							}
							else
								tmp = subtraction(n2, n1);
						}
						else
						{
							negative = 1;
							tmp = addition(n1, n2);
						}
					}
					else
					{
						if( negative2 )
							tmp = addition(n1, n2);
						else
						{
							if( compare_value(0,n1, 0,n2, ">=") )
								tmp = subtraction(n1, n2);
							else
							{
								negative = 1;
								tmp = subtraction(n2, n1);
							}
						}
					}
					break;
					
					
				case '*':
					if( ((negative1 && !negative2) || (negative2 && !negative1)) && !compare_value(0,n1, 0,"0", "==") && !compare_value(0,n2, 0,"0", "=="))
						negative = 1;
						
					tmp = multiplication(n1,n2);
					break;
				case '/':
					if( ((negative1 && !negative2) || (negative2 && !negative1)) && !compare_value(0,n1, 0,"0", "==") && !compare_value(0,n2, 0,"0", "==") )
						negative = 1;
					
					tmp = division(n1,n2);
					break;
				default:				
					i = compare_value(negative1, n1, negative2, n2, operator);
					free_string_svalue(sp--);
					free_string_svalue(sp--);
					free_string_svalue(sp);
					FREE(n1);
					FREE(n2);
					put_number(i);
					return;
			}
			
			ans = new_string(strlen(tmp)+negative, "f_count");
			if( negative && tmp[0] != 48 )
			{
				ans[0] = 45;
				*ans++;
				strcpy(ans, tmp);
				*ans--;
			}
			else
				strcpy(ans, tmp);
			
			FREE(tmp);
			free_string_svalue(sp--);
			free_string_svalue(sp--);
			free_string_svalue(sp);
			FREE(n1);
			FREE(n2);
			put_malloced_string(ans);
			return;
		}
		
		case 2:
		{
			i = compare_value(negative1, n1, negative2, n2, operator);
			free_string_svalue(sp--);
			free_string_svalue(sp--);
			free_string_svalue(sp);
			FREE(n1);
			FREE(n2);
			put_number(i);
			return;
		}

		default: error("運算子錯誤 : +, -, *, /, >, >=, <, <=, =="); break;
	}
}
#endif
	