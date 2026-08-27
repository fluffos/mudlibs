/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : string.c
 * Author : Clode@RevivalWorld
 * Date   : 2002-09-28
 * Note   : included by Simul_Efun Object
 * Update :
 *
 *
 -----------------------------------------
 */
#include <daemon.h>
string to_string(mixed arg)
{
	return stringp(arg) ? arg : save_variable(arg);
}

string ansi_capitalize(string arg)
{
	string s, str, ansi, word, *res = allocate(0);
	int i;

	if( !arg || !stringp(arg) ) return 0;
		
	if( strsrch(arg, "-") != -1 )
		s = "-";
	else
		s = " ";

	foreach(str in explode(arg, s))
	{
		do
		{
			i = sscanf(str, "%(\e\\[[0-9;#]*[HJMmrs])%s", ansi, word);
			if( i == 2 )
				str = sprintf("%s%s", ansi, efun::capitalize(word));
			else
				str = efun::capitalize(str);
		}
		while(i == 2 && word && word[0..1] == "\e[" && str = word);
		res += ({ str });
	}
	return implode(res, s);
}

string capitalize(string arg)
{
	/*
	CHANNEL_D->channel_broadcast("sys",
		sprintf("%O capitalize redirect to ansi_capitalize.", previous_object()));*/
	return ansi_capitalize(arg);
}

string big_number_check(mixed bn)
{
	int negtive;
	
	if( !bn ) return 0;
	
	if( intp(bn) )
		return bn+"";
	else if( !stringp(bn) )
		return 0;

	if( bn[0] == '-' )
	{
		bn = bn[1..];
		negtive = 1;
	}

	bn = replace_string(bn, ",", "");

/*
	if( bn[<1] == 'k' || bn[<1] == 'K' )
		bn = bn[0..<2]+"000";
	else if( bn[<1] == 'm' || bn[<1] == 'M' )
		bn = bn[0..<2]+"000000";
	else if( bn[<1] == 'g' || bn[<1] == 'G' )
		bn = bn[0..<2]+"000000000";
*/
	while(bn[0]=='0') bn = bn[1..];

	foreach(int i in bn)
		if( i < '0' || i > '9' )
			return 0;

	if( bn == "" )
		return 0;
	else 
		return negtive ? "-"+bn : bn;
}

string multiwrap(string arg, int max_width)
{
	int i, imsg_size;
	string *imsg, *omsg = allocate(0);
	
	imsg = explode(arg, "\n");
	imsg_size = sizeof(imsg);
	
	for(i=0;i<imsg_size;i++)
	{
		if( noansi_strlen(imsg[i]) <= max_width )
			omsg += imsg[i..i];
		else
			omsg += ({ cwrap(imsg[i], max_width, 0) });
	}

	arg = implode(omsg, "\n");
	
	return arg;
}

/*
 *  check_text:  A perfect function to handle the clip-paste code
 *               room system. It could work on all MudOS version
 *               which provide the replace_string() and the
 *               save_variable() efun.
 *  features:
 *      1. Resolved \ and " problem in constant string by efun.
 *      2. Avoided to 'String too long' error from MudOS lexer.
 *      3. Protected this system from the users use " and \ to
 *         crack the system.
 *      4. Additional check too long constant string after efun.
 *
 *  Attention: It's unneeded to protect the error 'Line too long'
 *             from lexer. We suggest that you add a line length
 *             limit in the user input system, because there are
 *             not any clients can print one line string which is
 *             longer than 'yytext' size '1024'.
 *
 *                                      Passerby@Illusory.of.Time
 */
string check_text(string var)
{
        // Starting in new line to ensure that each length of line
        // is under our control.
        string newstr = "\n";

        // Keeping each of constant string length to smaller than safe size.
        // The safe string size is about 1000. In consider of the user who
        // input the unexcepted to make the result of save_variable() got
        // double length of original input, we use the half of safe size.
        // It's because any cases will not expand more than double times.
        do {
                // The variable 'newstr' stored each of new string after
                // save_variable processed. Notice that it'll use '\r'
                // instead of '\n', so we use the replace_string replace
                // back to '\n'.
                newstr += replace_string(save_variable(var[0..499]), "\r", "\n");
                // Removing the string which processed
                var = var[500..];
        } while(strlen(var));

        return newstr;
}

int is_chinese(string str)
{
	int len;

	if( !str || !str[0] )
		return 0;

	str = remove_ansi(str);
	len = strlen(str);

	if( len < 2 ) return 0;

	foreach( int a in str )
		if(  a <= ' ' || (--len%2 && (a < 160 || a > 255)) )
			return 0;
	
	return 1;
}

int is_english(string str)
{
	if( !str || !str[0] )
		return 0;

	foreach( int a in remove_ansi(str) )
		if( a != ' ' && (a < 'a' || a > 'z') && (a< 'A' || a > 'Z'))
			return 0;
			
	return 1;
}

string money(string unit, mixed money)
{
	if( !unit ) return 0;

	return "$"+unit+" "+NUMBER_D->number_symbol(money);
}