/* Do not remove the headers from this file! see /USAGE for more info. */

int max_mAh;
int mAh_capacity;

int rechargable = 0;

int is_power_source()
{
    return 1;
}

void set_rechargable(int r)
{
    rechargable = r;
}

int use_charge(int ma)
{
    mAh_capacity -= ma;
    if (mAh_capacity > 0)
        return 1;
    return 0;
}

int query_rechargable()
{
    return rechargable;
}

void set_max_mah(int c)
{
    max_mAh = c;
}

int query_max_mah()
{
    return max_mAh;
}

void set_mah(int c)
{
    mAh_capacity = CLAMP(c, 0, max_mAh);
}

void set_random_mah()
{
    set_mah((max_mAh / 4) + random(max_mAh));
}

int query_mah()
{
    return mAh_capacity;
}
