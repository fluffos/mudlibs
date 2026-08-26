/* $Id: un_article_indefinite.c,v 1.1 1994/02/12 11:16:41 vax Exp $
 * This efun removes indefinite articles: a, an.
 * $Log: un_article_indefinite.c,v $
 * Revision 1.1  1994/02/12  11:16:41  vax
 * Initial revision
 *
 */

string un_article_indefinite(string str)
{
    if (sscanf(str,"a %s",str) == 1) return str;
    sscanf(str,"an %s",str);
    return str;
}
