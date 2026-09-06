/*
 * /basic/object/dimensions.c - weight and size
 *
 * Copyright (c) 1994 The Stickmud Project,
 * All rights reserved.
 * 
 */

/*
 * Size, centimetres: X, Y, Z = width, height, depth
 *
 */
// Last modifications by Doomdark 10-mar-95.

int weight, *size;

#define SIZECHECK2 if (!size || !pointerp(size)) size = ({ 0, 0, 0 })
#define SIZECHECK1 if (!size || !pointerp(size)) return 0

/* Stupid weight units :-( */
public void
set_weight(int x)
{
    weight = x;
}

public int
query_weight_kg()
{
    int kg = 0;

    switch (weight)
    {
    case 0: kg = 0;
    case 1: kg = 1;
    case 2: kg = 1;
    case 3: kg = 4;
    case 4: kg = 8;
    case 5: kg = 10;
    default: kg = (weight * 2);
    }

    return kg;
}

public int
query_weight()
{
    return weight;
}

public int query_width()  { SIZECHECK1; return size[0]; }
public int query_height() { SIZECHECK1; return size[1]; }
public int query_depth()  { SIZECHECK1; return size[2]; }
public int *query_size()  { SIZECHECK1; return size; }

public status
set_size(mixed x)
{
    /* Default: height */
    if (intp(x))
    {
	SIZECHECK2;
	size[1] = x;
	return 1;
    }

    if (!pointerp(x)) return 0;
    if (sizeof(x) != 3) return 0;

    size = x;

    return 1;
}

public status set_width(int x)  { SIZECHECK2; size[0] = x; return 1;}
public status set_height(int x) { SIZECHECK2; size[1] = x; return 1;}
public status set_depth(int x)  { SIZECHECK2; size[2] = x; return 1;}
