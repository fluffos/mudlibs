// SilberLand MUDlib
//
// std/npc/put_and_get.c -- Put/Get Handling von NPCs
//
// $Date: 1997/04/15 10:33:14 $
/* $Revision: 3.2 $
 * $Log: put_and_get.c,v $
 * Revision 3.2  1997/04/15 10:33:14  Feyaria
 * buob auf obj ausgebessert
 *
 * Revision 3.1  1997/04/12 20:02:58  Feyaria
 * REJECT_DESTRUCT eingefuehrt
 *
 * Revision 3.0  1997/03/13 01:26:43  Woody
 * prepared for revision control
 *
 * 1996/11/24  Woody  @WER, @WESSEN, ... eingebaut, Units anders handlen
 * 1996/11/03  Woody  Units beruecksichtigt
 */

inherit "std/living/put_and_get";
#include <moving.h>
#include <properties.h>

void give_notify(object obj )
{
  mixed* msg;
  string str;
  int ga;

  if( pointerp(msg=QueryProp( P_REJECT ) ) )
  {
    /*
    if (obj->IsUnit() && ((msg[0]==REJECT_GIVE) || (msg[0]==REJECT_DROP))) {
      obj->AddAmount(-(ga=obj->QueryProp(P_GIVEN_AMOUNT)));
      obj=clone_object(explode(object_name(obj), "#")[0]);
      obj->SetProp (P_AMOUNT, ga);
      obj->move(this_object(), M_NOCHECK | M_FORCE_SPLIT);
    }
    */
    if (obj->IsUnit())
      obj->Set("u_req", obj->QueryProp(P_GIVEN_AMOUNT));

    str=msg[1];
    if (strstr(str,"@WER",0))
      str=implode(efun::explode(str,"@WER"),obj->name(WER,1));
    if (strstr(str,"@WESSEN",0))
      str=implode(efun::explode(str,"@WESSEN"),obj->name(WESSEN,1));
    if (strstr(str,"@WEM",0))
      str=implode(efun::explode(str,"@WEM"),obj->name(WEM,1));
    if (strstr(str,"@WEN",0))
      str=implode(efun::explode(str,"@WEN"),obj->name(WEN,1));
    say( str );
    switch( msg[0] )
    {
      case REJECT_GIVE:
        give_obj( obj, this_player() );
        break;
      case REJECT_DROP:
        drop_obj( obj );
        break;
      case REJECT_DESTRUCT:
        obj->remove();
        break;
      case REJECT_KEEP:
        /* keep it */
        break;
    }
  }
}
