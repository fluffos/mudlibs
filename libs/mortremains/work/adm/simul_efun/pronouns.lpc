// mudlib: Basis
// date:   1992/09/25
// author: Truilkan

/*
  $Locker:  $

  $Source: /usr/local/mud/libs/basis/adm/obj/simul_efun/RCS/pronouns.c,v $
  $Revision: 1.3 $
  $Author: garnett $
  $Date: 92/10/04 06:53:07 $
  $State: Exp $

  $Log:	pronouns.c,v $
 * Revision 1.3  92/10/04  06:53:07  garnett
 * added ppossessive
 * 
 * Revision 1.2  92/09/27  22:25:31  garnett
 * fixed objective case for male (to be him and not his)
 * 
 * Revision 1.1  92/09/25  07:51:46  garnett
 * Initial revision
 * 
*/
 
//  Watcher added the possibility of passing an object argument rather
//  than the string form (06/28/93)
 

string possessive(mixed gender) {
	string ret;

	if(objectp(gender))  
		gender = (string)gender->query("gender");
 
	switch (gender) {
		case "male" :
			ret = "his";
			break;
		case "female" :
			ret = "her";
			break;
		case "neuter" :
			ret = "its";
			break;
		case "neutral" :
		default :
			ret = "hir";
			break;
	}
	return ret;
}

string ppossessive(mixed gender) {
	string ret;

	if(objectp(gender))
		gender = (string)gender->query("gender");
 
	switch (gender) {
		case "male" :
			ret = "his";
			break;
		case "female" :
			ret = "hers";
			break;
		case "neuter" :
			ret = "its";
			break;
		case "neutral" :
		default :
			ret = "hirs";
			break;
	}
	return ret;
}

string subjective(mixed gender) {
	string ret;
 
	if(objectp(gender))
		gender = (string)gender->query("gender");

	switch (gender) {
		case "male" :
			ret = "he";
			break;
		case "female" :
			ret = "she";
			break;
		case "neuter" :
			ret = "it";
			break;
		case "neutral" :
		default :
			ret = "sie";
			break;
	}
	return ret;
}

string objective(mixed gender) {
	string ret;
 
	if(objectp(gender)) 
		gender = (string)gender->query("gender");

	switch (gender) {
		case "male" :
			ret = "him";
			break;
		case "female" :
			ret = "her";
			break;
		case "neuter" :
			ret = "it";
			break;
		case "neutral" :
		default :
			ret = "hir";
			break;
	}
	return ret;
}
 
