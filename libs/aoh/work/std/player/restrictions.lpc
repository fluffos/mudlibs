/*---------------------------------------------------------------------------
** std/player/restrictions
**
** Some awareness of outside changes.
**
** 214-Jan-1994  [Mateese]
**---------------------------------------------------------------------------
*/

inherit "/std/living/restrictions";

#define THIS         this_object()
#define ENV          environment


public int QueryIVision();              // std/living/description
public int QueryUVision();              // std/living/description
public varargs int CantSee(object env); // std/living/description
protected void announce_light_change();

#define TRANS	  QueryTransparency() / 1000

//---------------------------------------------------------------------------

nosave int lightdiff; // Accumulated light differences

//---------------------------------------------------------------------------

protected void announce_light_change() {
  int csee, vdiff, i, diff;
  string rc;

  while(remove_call_out(#'announce_light_change) >= 0) ; /*'*/

  if (!lightdiff)
    return;

  diff = lightdiff; lightdiff = 0;

  csee = CantSee();
  vdiff = QueryUVision() - QueryIVision();
  i = (diff * 4) / (vdiff || 1);
  rc = "";
  if (i <= -4)
    rc = "Suddenly most of the lighting vanishes";
  else if (i > 4)
    rc = "A bright light shows up";
  else
    switch (i) {
      case -3: rc = "It is a lot darker now"; break;
      case -2: rc = "The light drops rapidly"; break;
      case -1: rc = "The light fades"; break;
      case  1: rc = "The light brightens"; break;
      case  2: rc = "The light brightens noticeably"; break;
      case  3: rc = "It is a lot brighter now"; break;
    }

  if (i && diff < 0 && csee < 0 && csee >= diff)
    rc += " and your vision blacks out";
  if (i && diff > 0 && csee > 0 && csee <= diff)
    rc += " and you're blinded by the light";
  if (rc != "")
    tell_object(THIS, rc+".\n");
}

protected void light_changed (int diff) {
  lightdiff += diff;
  if (-1 == find_call_out(#'announce_light_change)) /*'*/
    call_out(#'announce_light_change, 0); /*'*/
}

public void light_from_inside(int l) {
  if (l) {
    ::light_from_inside(l);
    lightdiff += l;
    if (-1 == find_call_out(#'announce_light_change)) /*'*/
      call_out(#'announce_light_change, 0); /*'*/
  }
}

public void light_from_outside(int l) {
  if (l *= TRANS) {
    ::light_from_outside(l);
    lightdiff += l;
    if (-1 == find_call_out(#'announce_light_change)) /*'*/
      call_out(#'announce_light_change, 0); /*'*/
  }
}

public void emit_light(int l) {
  if(l) {
    ::emit_light(l);
    lightdiff += l;
    if (-1 == find_call_out(#'announce_light_change)) /*'*/
      call_out(#'announce_light_change, 0); /*'*/
  }
}

public void emit_intlight(int l) {
  if(l) {
    ::emit_intlight(l);
    lightdiff += l;
    if (-1 == find_call_out(#'announce_light_change)) /*'*/
      call_out(#'announce_light_change, 0); /*'*/
  }
}

/***************************************************************************/
