// SilberLand MUDlib
//
// std/thing/material.c -- material handling for standard objects
//
// $Date: 2009/08/04 21:00:00 $                      
/* $Revision: 2.6 $       
 * $Log: material.c,v $
 *
 * Revision 2.6  2009/08/04 21:00:00  Rommy
 * Setzen von fehlerhaften Mappings abfangen
 *
 * Revision 2.5  2001/02/10 12:07:26  Samtpfote
 * prepared for revision control
 *
 * Revision 2.5  1997/09/25 15:11:38  Woody
 * Neues System (Mappings statt Arrays) von Rochus@MG
 *
 * Revision 2.4  1997/04/16 15:51:07  Feyaria
 * MAT_FUR
 *
 * Revision 2.3  1997/04/01 11:32:02  Feyaria
 * MAT_BONE
 *
 * Revision 2.2  1997/03/21 10:12:32  Feyaria
 * nochmals Typo, argl :(
 *
 * Revision 2.1  1997/03/21 10:05:41  Feyaria
 * Typo in pflanzlicher und tiericher Baisis
 *
 * Revision 2.0  1997/03/13 02:27:49  Woody
 * prepared for revision control
 *
 * Revision 1.14  1997/02/22  14:00:00  Woody
 * neues Material
 * Revision 1.13  1996/10/20  03:00:00  Woody
 * neues Material
 * Revision 1.12  1996/05/17  18:30:00  Woody
 * neue Materialien
 * Revision 1.11  1996/05/11  18:30:00  Woody
 * neue Materialien
 * Revision 1.1   1996/04/21  12:15:00  Woody
 * neue Materialien
 * Revision 1.0   1996/02/27  03:15:00  Mupfel
 * MatToString, MatList
 */                            

#pragma strong_types

#define NEED_PROTOTYPES 1

#include <thing/properties.h>
#include <thing/language.h>
#include <thing/material.h>
#include <defines.h>
//#include <std_headers.h>

// Nur zur Kompatibilitaet - sollte nicht weiter verwendet werden!
string MatToString(string mat, int casus)
{
  if (member(({WER, WESSEN, WEM, WEN}), casus)==-1)
    casus = WER;
  return
    call_other(MATERIALDB, "MaterialName", mat, casus) ||
    ({"unbekanntes Material", "unbekannten Materiales",
      "unbekanntem Material", "unbekanntes Material"})[casus];
}

// Nur zur Kompatibilitaet - sollte nicht weiter verwendet werden!
string MatList(int casus)
{
  return call_other(MATERIALDB,"ConvMaterialList",
                    QueryProp(P_MATERIAL),casus);
}

// Material-Behandlung:
mapping _set_material(mixed mat) {
  int i,sz;
  mapping mats;

  if (mappingp(mat)) {
    if (get_type_info(mat,1)!=1)
      mats=0; // error
    else
      mats=mat;
  } else {
    mats=([]);
    if (stringp(mat))
      mats=([mat:100]);
    else if (pointerp(mat) && sz=sizeof(mat))
      for (i=sz-1;i>=0;i--)
        mats[mat[i]]=100/sz;
    else
      mats=([MAT_MISC:100]);
  }
  return Set(P_MATERIAL,mats);
}

mapping _query_material() {
  mixed res;

  if (!mappingp(res=Query(P_MATERIAL)))
    return ([MAT_MISC:100]);
  return res;
}

int QueryMaterial(string mat) {
  mapping mats;

  if (!mappingp(mats=QueryProp(P_MATERIAL)))
    return 0;
  return mats[mat];
}

int QueryMaterialGroup(string matgroup) {
  return call_other(MATERIALDB,"MaterialGroup",
                    QueryProp(P_MATERIAL),matgroup);
}

string MaterialList(int casus, mixed idinf) {
  return call_other(MATERIALDB,"ConvMaterialList",
                    QueryProp(P_MATERIAL),casus,idinf);
}

