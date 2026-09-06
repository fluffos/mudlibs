// *********************************************************************
// Ultravision talent
//
// [Softbyte] 12mar1998    Creation
//
// *********************************************************************

#include <attributes.h>

int GetAmount(int value)
{
  int i;

  if (value<333)    // low talent
  {
    i=20;
  }
  else if (value<667) // medium talent
  {
    i=40;
  }
  else             // high talent
  {
    i=80;
  }
  return i;
}

// Set this talent (this file) of the lving (me)  to the value 'value'
void SetTalent(object me,int value,mixed extra)
{
  int i;

  if (!me) return ;
  i=GetAmount(value);
  // reduce ivision attr
  me->ModifyAttr(A_UVISION,i);
}

// Will be called if living (me) got removed or the talent got removed
void RemoveTalent(object me,int value,mixed extra)
{
  int i;

  if (!me) return ;
  i=GetAmount(value);
  me->ModifyAttr(A_UVISION,-i);
}
