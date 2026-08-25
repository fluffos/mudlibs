//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef _vehicle_statistics_c
#define _vehicle_statistics_c

#include "/lib/services/materials/materials.h"

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getMaterialVehicleBonus(string material)
{
    mapping result = ([]);

    if (stringp(material) && member(materials, material) &&
        member(materials[material], "vehicle"))
    {
        result = materials[material]["vehicle"] + ([]);
    }
    return result;
}

#endif
