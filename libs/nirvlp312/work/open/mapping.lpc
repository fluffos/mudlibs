/*
 * Some funs for manipulating mappings--like m_values which for some reason
 * DR doesn't have.
 * 
 * Bastian 07/26/95
 */

#pragma strict_types
#pragma save_types

/*
 * Function: m_indices
 * Purpose : Return an array with the keys of mapping map.
 */
mixed *
m_indices ( mapping map ) {
    return keys(map);
}

/*
 * Function: m_values
 * Purpose : Return an array of the contents of mapping map.
 */
mixed *
m_values ( mapping map ) {
    mixed *values, *indices;
    int i, size;

    values = ({ });
    indices = keys(map);
    for ( i = 0, size = sizeof(indices); i < size; i++ )
        values += map[indices[i]];
    return values + ({ });
}
    
/*
 * Function: make_mapping
 * Purpose : Take two arrays of keys and values and return a mapping made from
 *           them.
 */
mapping 
make_mapping ( mixed *indices, mixed *values ) {
    int i, size;
    mapping map;

    map = ([ ]);
    for ( i = 0, size = sizeof(indices); i < size; i++ )
        map += ([ indices[i] : values[i] ]);
    return map + ([ ]);
}

/*
 * Function: deconstruct_mapping
 * Purpose : Takes the contents of map and places them in the array pointer
 *           provided. The fun also returns the new array.
 */
mixed *
deconstruct_mapping ( mapping map ) {
    int i, size;
    mixed *indices, *savemap;

    savemap = ({ });
    indices = keys(map);
    for ( i = 0, size = sizeof(indices); i < size; i++ )
        savemap += ({ indices[i], map[indices[i]] });
    return savemap;
}

/*
 * Function: reconstruct_mapping
 * Purpose : Restore a mapping that was deconstructed with deconstruct_mapping.
 *           The array used to save the mapping will be zeroed upon
 *           completion.
 */
mapping
reconstruct_mapping ( mixed *savemap ) {
    int i, size;
    mapping map;
    
    map = ([ ]);
    for ( i = 0, size = sizeof(savemap); i < size; i++ )
        map += ([ savemap[i] : savemap[++i] ]);
    savemap[0..size - 1] = ({ });
    return map;
}
