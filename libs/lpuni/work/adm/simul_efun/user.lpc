//user.c

//Tacitus @ LPUniversity
//Grouped on October 22nd, 2005

string user_data_file(string name)
{
     if(!name ||!stringp(name)) return 0;
     name = lower_case((string)name);
     return("/data/users/" + name[0..0] + "/" + name + "/" + name);
}

string user_mob_data(string name)
{
    if(!name ||!stringp(name)) return 0;
     name = lower_case((string)name);
     return("/data/users/" + name[0..0] + "/" + name + "/" + name + "_mob");
}


string user_data_directory(string priv)
{
    if(!priv ||!stringp(priv)) return 0;
    priv = lower_case((string)priv);
    return("/data/users/" + priv[0..0] + "/" + priv + "/");
}

string user_core_data_directory(string priv)
{
    if(!priv ||!stringp(priv)) return 0;
    priv = lower_case((string)priv);
    return("/data/users/" + priv[0..0] + "/" + priv + "/");
}

string user_path(string name)
{
     return ("/home/" + name[0..0] + "/" + name + "/");
}