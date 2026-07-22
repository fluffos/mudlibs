#define NO_FEE

varargs mixed add(string prop, mixed data, object who)
{
    return who->add(prop, data);
}

varargs mixed addn(string prop, mixed data, object who)
{
    return who->addn(prop, data);
}

varargs mixed query(string prop, object who)
{
    return who->query(prop);
}

varargs mixed set(string prop, mixed data, object who)
{
    return who->set(prop, data);
}

varargs int delete(string prop, object who)
{
    return who->delete(prop);
}

varargs mixed add_temp(string prop, mixed data, object who)
{
    return who->add_temp(prop, data);
}

varargs mixed addn_temp(string prop, mixed data, object who)
{
    return who->addn_temp(prop, data);
}

varargs mixed query_temp(string prop, object who)
{
    return who->query_temp(prop);
}

varargs mixed set_temp(string prop, mixed data, object who)
{
    return who->set_temp(prop, data);
}

varargs int delete_temp(string prop, object who)
{
    return who->delete_temp(prop);
}

