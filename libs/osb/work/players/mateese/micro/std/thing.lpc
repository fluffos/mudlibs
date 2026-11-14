/*---------------------------------------------------------------------------
** std/thing.c
**
** A simple thing to clone or inherit.
**
** TODO: Implement combat functions for things so they can be destroyed
**       using weapons/other things.
** TODO: Implement details for things.
**
** 10-Sep-1993 [Mateese]
**---------------------------------------------------------------------------
*/

virtual inherit "/std/object";
virtual inherit "/std/thing/moving";
virtual inherit "/std/thing/physical";

//---------------------------------------------------------------------------
public int clean_up (int ref)

{
  return "moving"::clean_up(ref);
}

//---------------------------------------------------------------------------
public int prevent_shadow (object shadow)

{
  return file_name(THIS) == "/std/thing";
}

/***************************************************************************/
