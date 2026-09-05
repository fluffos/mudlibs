mixed f1(mixed abc, mixed value)
{
        return value;
}

mixed f2(mixed abc, mixed value)
{
        if (mapp(value)) return map_mapping(value, (: f2 :));
        return value;
}

int main(object me, string arg)
{
        mapping m1, m2;

        m1 = ([ "key": ([ "key": 1 ]) ]);
        m2 = m1;
        m2["key"]["key"] = 2;
        write(sprintf("%O %O\n", m1, m2));

        m1 = ([ "key": ([ "key": 1 ]) ]);
        m2 = f1(0, m1);
        m2["key"]["key"] = 2;
        write(sprintf("%O %O\n", m1, m2));

        m1 = ([ "key": ([ "key": 1 ]) ]);
        m2 = f2(0, m1);
        m2["key"]["key"] = 2;
        write(sprintf("%O %O\n", m1, m2));
        return 1;
}
