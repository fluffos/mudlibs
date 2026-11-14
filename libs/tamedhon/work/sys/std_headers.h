// SilberLand MUDlib
//
// sys/std_headers.h -- standard headers(?)
//
// $Date: 1997/03/31 13:41:09 $
/* $Revision: 1.1 $
 * $Log: std_headers.h,v $
 * Revision 1.1  1997/03/31 13:41:09  Woody
 * prepared for revision control
 *
 */

#ifndef __STD_HEADERS_H__
#define __STD_HEADERS_H__

//LANGUAGE
void SetArticle( int fl );
int QueryAFlag();
varargs string QueryArticle( int casus, int dem, int force );
varargs int SuggestArticle( string myname );
varargs string QueryPossPronoun( int what, int casus, int number );
string QueryPronoun( int casus );
varargs string QueryDu(int casus,int gender,int zahl);
string QueryGenderString();
varargs string DeclAdj( string adj, int casus, int demon );

#endif
