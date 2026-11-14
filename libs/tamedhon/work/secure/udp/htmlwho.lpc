/* SilberLand MUDlib
 *
 * /secure/udp/htmlwho.c -- WWW who handling
 *
 * $Date: 1997/03/16 00:09:47 $
 * $Revision: 1.1 $
 * $Log: htmlwho.c,v $
 * Revision 1.1  1997/03/16 00:09:47  Woody
 * prepared for revision control
 *
 */

#include <udp.h>

#define TD(x) if (find_player("debugger")) tell_object(find_player("debugger"),x)

string adjust(string str,int wid)
{
  int w2;

  w2=wid/2;
  wid=wid-w2;
  return extract("                                                          ",0,wid-1)+str+
    extract("                                                         ",0,w2-1);
}

udp_htmlwho(data)
{
  int i,num;
  mixed mdata;
  mixed wholiste,tmp,tmp2;
 
  mdata="/obj/werliste"->QueryWhoListe(0,0,1);
  num=sizeof(mdata);
  for (i=num-1;i>=0;i--)
  {
    tmp=mdata[i][0]->name();
    if (tmp&&sizeof(tmp))
    {
      tmp2=efun::explode(mdata[i][1],tmp);
      if (sizeof(tmp2)>1)
      {
        tmp2[0]="<A HREF=\"/htbin/mudwww?finger?"+getuid(mdata[i][0])+"\"><b>";
        tmp2[1]="</b></A>"+tmp2[1];
        mdata[i][1]=implode(tmp2,tmp);
      }
      mdata[i]=" <LI> "+mdata[i][1];
    }
  }
  wholiste=implode(mdata,"\n");
  INETD->send_udp(data[NAME], ([
				REQUEST: REPLY,
				RECIPIENT: data[SENDER],
				ID: data[ID],
				DATA: wholiste
				]) );
}
