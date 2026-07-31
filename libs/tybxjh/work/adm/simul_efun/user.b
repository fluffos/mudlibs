object *users()
{
       return filter_array(children(USER_OB), (: userp :));
}
mapping zjbdbase(mapping vic)
{
mapping zjb = vic;
return zjb;
}
