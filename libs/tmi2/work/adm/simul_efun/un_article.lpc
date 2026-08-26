/* $Id: un_article.c,v 1.1 1994/02/12 11:20:10 vax Exp $
 * This efun removes articles: a, an, the.
 * $Log: un_article.c,v $
 * Revision 1.1  1994/02/12  11:20:10  vax
 * Initial revision
 *
 */

string un_article(string str)
{
    if (sscanf(str,"the %s",str) == 1) return str;
    return un_article_indefinite(str);
}
