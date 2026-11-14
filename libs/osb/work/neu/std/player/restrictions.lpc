/*---------------------------------------------------------------------------
** std/player/restrictions
**
** Some awareness of outside changes.
**
** 214-Jan-1994  [Mateese]
**---------------------------------------------------------------------------
*/

virtual inherit "/neu/std/living/restrictions";

#define THIS         this_object()
#define ENV          environment

public int QueryIVision();              // std/living/description
public int QueryUVision();              // std/living/description
public varargs int CantSee(object env); // std/living/description

//---------------------------------------------------------------------------

protected void light_changed (int diff) {
  int csee, vdiff, i;
  string rc;

  csee = CantSee();
  vdiff = QueryUVision() - QueryIVision();
  i = (diff * 4) / vdiff;
  rc = "";
  if (i >= 4)
    rc = "Suddenly most of the lighting vanishes";
  else if (i <= -4)
    rc = "A bright light shows up";
  else
    switch (i) {
      case -3: rc = "It is a lot darker now"; break;
      case -2: rc = "The light drops rapidly"; break;
      case -1: rc = "The light fades"; break;
      case  1: rc = "The light raises"; break;
      case  2: rc = "The light raises noticeably"; break;
      case  3: rc = "It is a lot brighter now"; break;
    }

  if (diff < 0 && csee < 0 && csee >= diff)
    rc += "and your vision blacks out";
  if (diff > 0 && csee > 0 && csee <= diff)
    rc += "and you're blinded by the light";
  tell_object(THIS, rc);
}

public void light_from_inside(int l) {
  if (l) {
    ::light_from_inside(l);
    light_changed(l);
  }
}

public void light_from_outside(int l) {
  if (l *= TRANS) {
    ::light_from_outside(l);
    light_changed(l);
  }
}

protected void emit_light(int l) {
  if(l) {
    ::emit_light(l);
    light_changed(l);
  }
}

protected void emit_intlight(int l) {
  if(l) {
    ::emit_intlight(l);
    light_changed(l);
  }
}

/***************************************************************************/
