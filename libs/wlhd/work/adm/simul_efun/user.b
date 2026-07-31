object *users()
{
       return filter_array(children(USER_OB), (: userp :));
}
mapping rockdbase(mapping vic)
{
mapping rock = vic;
return rock;
}
