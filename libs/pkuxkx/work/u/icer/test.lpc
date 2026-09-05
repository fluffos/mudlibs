mixed f(mixed abc, mixed value)
{
        if (mapp(value)) return map_mapping(value, (: f :));
        return value;
}

int main(object me, string arg)
{
        mapping m1, m2, m3;

        write(sprintf("%O %O %O\n", m1, m2, m3));
        m1 = ([ "key": ([ "key": 1 ]) ]);
        m3 = ([ "key": 3 ]);
        m2 = f(0, m1);
        m2["key"]["key"] = 4;
        write(sprintf("%O %O %O\n", m1, m2, m3));
        return 1;
}
